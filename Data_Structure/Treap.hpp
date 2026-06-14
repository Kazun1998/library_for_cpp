#pragma once

#include"../template/template.hpp"

template<typename T>
class Treap {
    struct Node {
        T key;
        int priority;
        int size;
        Node *left = nullptr, *right = nullptr;
        Node(T key, int priority) : key(key), priority(priority), size(1) {}
    };

    Node *root = nullptr;
    std::mt19937 mt;

    static int get_size(Node* node) { return node ? node->size : 0; }

    static Node* update(Node* node) {
        if (node) node->size = 1 + get_size(node->left) + get_size(node->right);
        return node;
    }

    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    const Node* next_inner(const T &key, bool equal) const {
        const Node *res = nullptr;
        const Node *cur = root;
        while (cur) {
            bool condition = equal ? (key <= cur->key) : (key < cur->key);
            if (condition) {
                res = cur;
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return res;
    }

    const Node* previous_inner(const T &key, bool equal) const {
        const Node *res = nullptr;
        const Node *cur = root;
        while (cur) {
            bool condition = equal ? (key >= cur->key) : (key > cur->key);
            if (condition) {
                res = cur;
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return res;
    }

    public:
    Treap(): mt(std::random_device{}()) {}

    Treap(std::initializer_list<T> init_list) : Treap() {
        for (const auto& x : init_list) insert(x);
    }

    template<class Iterator>
    Treap(Iterator first, Iterator last) : Treap() {
        for (auto it = first; it != last; ++it) insert(*it);
    }

    template<class Container>
    Treap(const Container& container) : Treap() {
        for (const auto& x : container) insert(x);
    }

    ~Treap() { clear(root); }

    int size() const { return get_size(root); }

    static Node* merge(Node* first, Node* second) {
        if (!first || !second) return first ? first : second;

        if (first->priority > second->priority) {
            first->right = merge(first->right, second);
            return update(first);
        } else {
            second->left = merge(first, second->left);
            return update(second);
        }
    }

    static void split(Node* tree, T key, Node*& less, Node*& more) {
        if (!tree) { less = more = nullptr; return; }

        if (tree->key < key) {
            split(tree->right, key, tree->right, more);
            less = update(tree);
        } else {
            split(tree->left, key, less, tree->left);
            more = update(tree);
        }
    }

    void insert(T key) {
        Node *less, *more;
        split(root, key, less, more);
        root = merge(merge(less, new Node(key, mt())), more);
    }

    void erase(T key) {
        Node *less, *mid, *more;
        split(root, key, less, mid);
        split(mid, key + 1, mid, more);

        clear(mid);

        root = merge(less, more);
    }

    /// @brief Treap を空にする.
    void clear() { clear(root); root = nullptr; }

    /// @brief キーが含まれているか判定する.
    bool contains(const T &key) const {
        Node* cur = root;
        while (cur) {
            if (cur->key == key) return true;
            cur = (key < cur->key) ? cur->left : cur->right;
        }
        return false;
    }

    /// @brief key より大きい（または以上）キーのうち最小のものを求める.
    T next(const T &key, bool equal = true) const {
        const Node *res = next_inner(key, equal);
        if (!res) throw std::out_of_range("Treap::next : Successor not found.");
        return res->key;
    }

    /// @brief key より大きい（または以上）キーのうち最小のものを求める. 存在しない場合は default_value を返す.
    T next(const T &key, const T &default_value, bool equal = true) const {
        const Node *res = next_inner(key, equal);
        return res ? res->key : default_value;
    }

    /// @brief key 未満（または以下）のキーのうち最大のものを求める.
    T previous(const T &key, bool equal = true) const {
        const Node *res = previous_inner(key, equal);
        if (!res) throw std::out_of_range("Treap::previous : Predecessor not found.");
        return res->key;
    }

    /// @brief key 未満（または以下）のキーのうち最大のものを求める. 存在しない場合は default_value を返す.
    T previous(const T &key, const T &default_value, bool equal = true) const {
        const Node *res = previous_inner(key, equal);
        return res ? res->key : default_value;
    }

    /// @brief key 未満の要素の数を求める.
    int less_count(const T &key, bool equal = false) const {
        Node* cur = root;
        int res = 0;
        while (cur) {
            bool condition = equal ? (cur->key <= key) : (cur->key < key);
            if (condition) {
                res += get_size(cur->left) + 1;
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return res;
    }

    /// @brief key より大きい要素の数を求める.
    int more_count(const T &key, bool equal = false) const {
        return size() - less_count(key, !equal);
    }

    /// @brief 昇順で k 番目 (0-indexed) のキーを取得する.
    /// @param k インデックス (負の値の場合は後ろから数える)
    T kth_element(int k) const {
        if (k < 0) k += size();
        if (k < 0 || k >= size()) throw std::out_of_range("Treap::kth_element : Index out of range.");

        Node* node = root;
        loop {
            int left_size = get_size(node->left);
            if (k < left_size) {
                node = node->left;
            } else if (k == left_size) {
                break;
            } else {
                k -= left_size + 1;
                node = node->right;
            }
        }
        return node->key;
    }
};
