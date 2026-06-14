#pragma once

#include"../template/template.hpp"

template<typename T>
class Additive_Treap {
    struct Node {
        T key;
        int priority;
        int size;
        T weight;
        Node *left = nullptr, *right = nullptr;
        Node(T key, int priority) : key(key), priority(priority), size(1), weight(key) {}
    };

    Node *root = nullptr;
    std::mt19937 mt;

    static int get_size(Node* node) { return node ? node->size : 0; }
    static T get_weight(Node* node) { return node ? node->weight : T(0); }

    static Node* update(Node* node) {
        if (!node) return node;

        node->size = 1 + get_size(node->left) + get_size(node->right);
        node->weight = node->key + get_weight(node->left) + get_weight(node->right);
        return node;
    }

    static void split_upper(Node* tree, T key, Node*& less_eq, Node*& more) {
        if (!tree) { less_eq = more = nullptr; return; }
        if (!(key < tree->key)) { // tree->key <= key
            split_upper(tree->right, key, tree->right, more);
            less_eq = update(tree);
        } else {
            split_upper(tree->left, key, less_eq, tree->left);
            more = update(tree);
        }
    }

    static Node* erase_one(Node* node, const T key, bool& deleted) {
        if (!node) return nullptr;
        if (node->key == key) {
            deleted = true;
            Node* res = merge(node->left, node->right);
            node->left = node->right = nullptr;
            delete node;
            return res;
        }
        if (key < node->key) node->left = erase_one(node->left, key, deleted);
        else node->right = erase_one(node->right, key, deleted);
        return update(node);
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
    Additive_Treap(): mt(std::random_device{}()) {}

    Additive_Treap(std::initializer_list<T> init_list) : Additive_Treap() {
        for (const auto& x : init_list) insert(x);
    }

    template<class Iterator>
    Additive_Treap(Iterator first, Iterator last) : Additive_Treap() {
        for (auto it = first; it != last; ++it) insert(*it);
    }

    template<class Container>
    Additive_Treap(const Container& container) : Additive_Treap() {
        for (const auto& x : container) insert(x);
    }

    ~Additive_Treap() { clear(root); }

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
        Node *less, *more;
        split(root, key, less, more);
        root = merge(merge(less, new Node(key, mt())), more);
        return true;
    }

    /// @brief key を 1 つ削除する.
    bool erase(const T key) {
        bool deleted = false;
        root = erase_one(root, key, deleted);
        return deleted;
    }

    /// @brief key をすべて削除する.
    int discard(const T key) {
        Node *less, *mid_more, *mid, *more;
        split(root, key, less, mid_more);
        split_upper(mid_more, key, mid, more);
        int res = get_size(mid);
        clear(mid);
        root = merge(less, more);
        return res;
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

    /// @brief x 未満 (または以下) の要素の個数と総和を求める.
    pair<int, T> query(const T x, bool equal = false) const {
        Node* cur = root;
        int count = 0;
        T sum = T(0);
        while (cur) {
            bool condition = equal ? (cur->key <= x) : (cur->key < x);
            if (condition) {
                count += get_size(cur->left) + 1;
                sum += get_weight(cur->left) + cur->key;
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return {count, sum};
    }

    /// @brief l 以上 r 未満の元の個数と総和を求める.
    pair<int, T> query_range(const T l, const T r, bool l_equal = true, bool r_equal = false) const {
        if (l > r || (l == r && (!l_equal || !r_equal))) return {0, T(0)};
        auto upper = query(r, r_equal);
        auto lower = query(l, !l_equal);
        return {std::max(0, upper.first - lower.first), upper.second - lower.second};
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

    /// @brief キーの個数を求める.
    int count(const T key) const {
        auto [cnt_less, sum_less] = query(key, false);
        auto [cnt_less_eq, sum_less_eq] = query(key, true);
        return cnt_less_eq - cnt_less;
    }

    /// @brief x 未満の元の個数を求める.
    int count_less(const T x, bool equal = false) const {
        return query(x, equal).first;
    }

    /// @brief x 未満（または以下）の元の総和を求める.
    T sum_less(const T x, bool equal = false) const {
        return query(x, equal).second;
    }

    /// @brief x より大きい（または以上）の元の総和を求める.
    T sum_more(const T x, bool equal = false) const {
        return sum_all() - sum_less(x, !equal);
    }

    /// @brief l 以上 r 未満の元の総和を求める.
    T sum_range(const T l, const T r, bool l_equal = true, bool r_equal = false) const {
        if (l > r || (l == r && (!l_equal || !r_equal))) return T(0);
        T upper = sum_less(r, r_equal);
        T lower = sum_less(l, !l_equal);
        return upper - lower;
    }

    /// @brief 全ての元の総和を求める.
    T sum_all() const { return get_weight(root); }

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

    /// @brief 先頭 k 個の要素の総和を求める.
    T sum_first(int k) const {
        if (k <= 0) return T(0);
        if (k >= (int)size()) return sum_all();
        Node* cur = root;
        T res = T(0);
        while (cur) {
            int left_size = get_size(cur->left);
            if (k <= left_size) {
                cur = cur->left;
            } else {
                res += get_weight(cur->left) + cur->key;
                k -= left_size + 1;
                if (k <= 0) break;
                cur = cur->right;
            }
        }
        return res;
    }

    /// @brief 末尾 k 個の要素の総和を求める.
    T sum_last(int k) const {
        return sum_all() - sum_first(size() - k);
    }

    /// @brief 下位 k 個の要素の総和を求める (sum_first のエイリアス).
    T worst_sum(int k) const { return sum_first(k); }

    /// @brief 上位 k 個の要素の総和を求める (sum_last のエイリアス).
    T best_sum(int k) const { return sum_last(k); }

    /// @brief 累積和が target 以上となる最初の要素のインデックスを返す.
    /// @note 全ての要素が非負であることを前提とする.
    int bisect_by_sum(T target) const {
        if (target <= T(0)) return 0;
        if (target > sum_all()) return size();
        Node* cur = root;
        int idx = 0;
        while (cur) {
            T left_w = get_weight(cur->left);
            if (target <= left_w) {
                cur = cur->left;
            } else if (target <= left_w + cur->key) {
                return idx + get_size(cur->left);
            } else {
                target -= (left_w + cur->key);
                idx += get_size(cur->left) + 1;
                cur = cur->right;
            }
        }
        return size();
    }

    /// @brief k 番目 (0-indexed) のキーを取得する.
    T kth(int k) const {
        if (k < 0) k += size();
        if (k < 0 || k >= (int)size()) throw std::out_of_range("Additive_Treap::kth : Index out of range.");

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
