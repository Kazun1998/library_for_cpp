#pragma once

#include"../template/template.hpp"

template<typename T>
class Binary_Trie {
    struct Binary_Trie_Node {
        int terminal = 0, subtree_size = 0;
        Binary_Trie_Node *zero_child = nullptr, *one_child = nullptr;

        Binary_Trie_Node() = default;
    };

    int bit_size;
    bool allow_multiple;
    T _lazy_xor = 0, max_value;
    Binary_Trie_Node *root;

    Binary_Trie_Node* find_node(T x) {
        Binary_Trie_Node *node = root;
        for (int k = bit_size - 1; k >= 0; k--) {
            node = get_bit(x, k) ? node->one_child : node->zero_child;
            if (node == nullptr) { break; }
        }

        return node;
    }

    public:
    Binary_Trie() = default;

    Binary_Trie(const int bit_size, bool allow_multiple = false):
        bit_size(bit_size), allow_multiple(allow_multiple), max_value(T(1) << bit_size) {
            root = new Binary_Trie_Node();
        }

    inline T lazy_xor() const { return _lazy_xor; }
    inline void act_xor(T x) { _lazy_xor ^= x; }

    // 要素の追加

    /// @brief x を挿入する.
    /// @param x 挿入する値
    /// @return Trie 木に変化があれば true, なければ false.
    bool insert(T x) {
        Binary_Trie_Node *node = root;
        vector<Binary_Trie_Node*> path(bit_size + 1);
        path[0] = root;

        x ^= lazy_xor();

        for (int k = 0; k < bit_size; k++) {
            bool bit = get_bit(x, bit_size - (k + 1));
            Binary_Trie_Node **child_ptr = bit ? &node->one_child : &node->zero_child;

            if (*child_ptr == nullptr) {
                *child_ptr = new Binary_Trie_Node();
            }

            node = *child_ptr;
            path[k + 1] = node;
        }

        if (node->terminal > 0 && !allow_multiple) { return false; }
        
        node->terminal++;
        for (auto node: path) {
            node->subtree_size++;
        }

        return true;
    }

    // 要素の削除

    /// @brief `x` が存在する場合に `x` を 1 個削除する.
    /// @param x 削除する要素
    /// @return Trie 木に変化があれば true, なければ false.
    bool discard(T x) {
        unless(0 <= x && x < max_value) { return 0; }

        Binary_Trie_Node *node = root;

        vector<Binary_Trie_Node*> path(bit_size + 1);
        path[0] = root;

        x ^= lazy_xor();

        for (int d = 0; d < bit_size; d++) {
            bool bit = get_bit(x, bit_size - (d + 1));

            Binary_Trie_Node **child_ptr = bit ? &node->one_child : &node->zero_child;

            if (*child_ptr == nullptr) { return false; }

            node = *child_ptr;
            path[d + 1] = node;
        }

        if (!node->terminal) { return false; }

        node->terminal--;
        for (auto node: path) { node->subtree_size--; }

        return true;
    }

    /// @brief `x` を高々 `k` 回削除する.
    /// @param x 削除する要素
    /// @param k 削除する個数 (k = -1 とすると, 無限回になる)
    /// @return `x` を削除した回数
    int erase(T x, int k = -1) {
        unless(0 <= x && x < max_value) { return 0; }
    
        Binary_Trie_Node *node = root;

        vector<Binary_Trie_Node*> path(bit_size + 1);
        path[0] = root;

        x ^= lazy_xor();

        for (int d = 0; d < bit_size; d++) {
            bool bit = get_bit(x, bit_size - (d + 1));

            Binary_Trie_Node **child_ptr = bit ? &node->one_child : &node->zero_child;

            if (*child_ptr == nullptr) { return false; }

            node = *child_ptr;
            path[d + 1] = node;
        }

        if ((k == -1) || node->terminal < k) { 
            k = node->terminal;
        }

        node->terminal -= k;
        for (auto node: path) { node->subtree_size -= k; }

        return k;
    }

    /// @brief Binary Trie 木に保存されている要素数を求める.
    inline int64_t size() const { return root->subtree_size; }

    inline explicit operator bool() const { return size() > 0; }

    /// @brief Binary Trie 木に保存されている x の数を求める.
    /// @param x 検索値
    int count(T x) {
        unless (0 <= x && x < max_value) { return 0; }

        x ^= lazy_xor();

        Binary_Trie_Node* node = find_node(x);
        return node != nullptr ? node->subtree_size : 0;
    }

    /// @brief Binary Trie 木に保存されている `x` 未満の要素の数を求める.
    /// @param x 閾値
    /// @param equal `true` にすると, 「`x` 未満」が「`x` 以下」になる.
    int less_count(T x, bool equal = false) {
        if (equal) { return less_count(x + 1, false); }

        if (x < 0) { return 0; }
        if (x >= (T(1) << bit_size)) { return root->subtree_size;}

        int res = 0;
        Binary_Trie_Node *node = root;

        x ^= lazy_xor();

        for (int k = bit_size - 1; k >= 0; k--) {
            Binary_Trie_Node *left = node->zero_child, *right = node->one_child;
            if (get_bit(lazy_xor(), k)) {
                swap(left, right);
            }

            if (get_bit(x, k)) {
                if (left != nullptr) {
                    res += left->subtree_size;
                } else if (right != nullptr) {
                    return res;
                }

                node = right;
            } else {
                if (left == nullptr) {
                    return res;
                }

                node = left;
            }
        }

        return res;
    }

    /// @brief Binary Trie 木に保存されている `x` より大きい要素の数を求める.
    /// @param x 閾値
    /// @param equal `true` にすると, 「`x` より大きい」が「`x` 以上」になる.
    inline int more_count(T x, bool equal = false) const { return size() - less_count(x, !equal); }

    /// @brief Binary Trie 木に保存されている `x` 未満で最大の要素を求める.
    /// @param x 閾値
    /// @param equal `true` にすると, 「`x` 未満」が「`x` 以下」になる.
    T low_value(T x, bool equal = false) {
        if (equal) { x++; }

        int alpha = less_count(x, false);

        if (alpha == 0) { throw out_of_range("No value found that is less than the limit " + to_string(x) + "."); }

        return kth(alpha - 1);
    }

    /// @brief Binary Trie 木に保存されている `x` 未満で最大の要素を求める.
    /// @param x 閾値
    /// @param default_value `x` 未満の要素が存在しない場合の返り値
    /// @param equal `true` にすると, 「`x` 未満」が「`x` 以下」になる.
    T low_value(T x, T default_value, bool equal = false) const {
        if (equal) { x++; }

        int alpha = less_count(x, false);

        return alpha > 0 ? kth(alpha - 1) : default_value;
    }

    /// @brief Binary Trie 木に保存されている `x` より大きい要素のうち最小の要素を求める.
    /// @param x 閾値
    /// @param equal `true` にすると, 「`x` より大きい」が「`x` 以上」になる.
    T high_value(T x, bool equal = false) {
        if (equal) { x--; }

        int beta = more_count(x, false);

        if (beta == 0) { throw out_of_range("No value found that is more than the limit " + to_string(x) + "."); }

        return kth(-beta);
    }

    /// @brief Binary Trie 木に保存されている `x` より大きい要素のうち最小の要素を求める.
    /// @param x 閾値
    /// @param default_value `x` より大きい要素が存在しない場合の返り値
    /// @param equal `true` にすると, 「`x` より大きい」が「`x` 以上」になる.
    T high_value(T x, T default_value, bool equal = false) const {
        if (equal) { x--; }

        int beta = more_count(x, false);

        return beta > 0 ? kth(-beta) : default_value;
    }

    /// @brief Binary Trie 木にて `x` が存在するかどうかを判定する.
    /// @param x 
    inline bool contains(T x) { return count(x) > 0; }

    T operator[](int k) const {
        if (k < 0) { k += size(); }

        unless(0 <= k && k < size()) { throw out_of_range("Out of Range"); }

        T value = 0;
        Binary_Trie_Node *node = root;
        for (int d = bit_size - 1; d >= 0; d--) {
            Binary_Trie_Node *left = node->zero_child, *right = node->one_child;

            if (get_bit(lazy_xor(), d)) { swap(left, right); }

            if (left == nullptr) {
                node = right;
                value |= T(1) << d;
            } else if (left->subtree_size <= k) {
                k -= left->subtree_size;
                node = right;
                value |= T(1) << d;
            } else {
                node = left;
            }
        }

        return value;
    }

    inline T kth(int k) const { return (*this)[k]; }

    /// @brief 最小値を取得する.
    inline T get_min() const { return kth(0); }


    /// @brief 最大値を取得する.
    inline T get_max() const { return kth(-1); }
};