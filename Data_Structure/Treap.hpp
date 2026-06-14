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

    size_t size() const { return get_size(root); }

    bool empty() const { return size() == 0; }

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

    bool insert(const T key) {
        if (contains(key)) return false;
        Node *less, *more;
        split(root, key, less, more);
        root = merge(merge(less, new Node(key, mt())), more);
        return true;
    }

    bool erase(const T key) {
        if (!contains(key)) return false;
        Node *less, *mid, *more;
        split(root, key, less, mid);
        split(mid, key + 1, mid, more);
        clear(mid);
        root = merge(less, more);
        return true;
    }

    /// @brief Treap を空にする.
    void clear() { clear(root); root = nullptr; }

    /// @brief キーが含まれているか判定する.
    bool contains(const T key) const {
        Node* cur = root;
        while (cur) {
            if (cur->key == key) return true;
            cur = (key < cur->key) ? cur->left : cur->right;
        }
        return false;
    }

    /// @brief x より大きい（または以上）キーのうち最小のものを求める.
    std::optional<T> next(const T x, bool equal = false) const {
        const Node *res = next_inner(x, equal);
        return res ? std::make_optional(res->key) : std::nullopt;
    }

    /// @brief x 未満（または以下）のキーのうち最大のものを求める.
    std::optional<T> previous(const T x, bool equal = false) const {
        const Node *res = previous_inner(x, equal);
        return res ? std::make_optional(res->key) : std::nullopt;
    }

    /// @brief x 未満の元の個数を求める.
    int count_less(const T x, bool equal = false) const {
        Node* cur = root;
        int res = 0;
        while (cur) {
            bool condition = equal ? (cur->key <= x) : (cur->key < x);
            if (condition) {
                res += get_size(cur->left) + 1;
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return res;
    }

    /// @brief x より大きい元の個数を求める.
    int count_more(const T x, bool equal = false) const {
        return size() - count_less(x, !equal);
    }

    /// @brief l 以上 r 未満の元の数を求める.
    int count_range(const T l, const T r, bool l_equal = true, bool r_equal = false) const {
        if (l > r || (l == r && (!l_equal || !r_equal))) return 0;
        int upper = count_less(r, r_equal);
        int lower = count_less(l, !l_equal);
        return std::max(0, upper - lower);
    }

    /// @brief k 番目 (0-indexed) のキーを取得する.
    T kth(int k) const {
        if (k < 0) k += size();
        if (k < 0 || k >= (int)size()) throw std::out_of_range("Treap::kth : Index out of range.");

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

    std::optional<T> safe_kth(int k) const {
        if (k < 0) k += size();
        if (k < 0 || k >= (int)size()) return std::nullopt;
        return kth(k);
    }

    T operator[](int k) { return kth(k); }
    T operator[](int k) const { return kth(k); }

    T kth_min(int k) const { return kth(k); }
    T kth_max(int k) const { return kth(-(k + 1)); }

    T min() const { return kth(0); }
    T max() const { return kth(-1); }
};
