#pragma once

#include "../template/template.hpp"
#include "../template/concepts.hpp"

template<typename T> requires totally_ordered<T>
class Ordered_Trie {
    struct Node {
        T item;
        map<T, Node*> next;
        size_t terminal_count, prefix_count;
        bool is_root;

        Node(): Node(T()) {}
        Node(const T &item, const bool is_root = false): item(item), terminal_count(0), prefix_count(0), is_root(is_root) {}

        bool contains(const T &x) const { return next.find(x) != next.end(); }

        inline Node* dig(const T x) { return contains(x) ? next[x] : nullptr; }
    };

    public:
    Node *root;

    Ordered_Trie() {
        root = new Node(T(), true);
    }

    // insert

    /// @brief Trie 木に vec を挿入する. ただし, 挿入の開始位置は node から.
    /// @param vec
    /// @param node
    void insert(const vector<T> &vec, Node *node) {
        node->prefix_count++;
        for (T x: vec) {
            if (!node->contains(x)) {
                node->next[x] = new Node(x);
            }

            node = node->next[x];
            node->prefix_count++;
        }

        node->terminal_count++;
    }

    /// @brief Trie 木に vec を挿入する.
    /// @param vec
    void insert(const vector<T> &vec) { insert(vec, root); }

    // erase

    /// @brief Trie 木から vec を削除する. ただし, 削除の開始位置は node から. 登録されていなければ何もせず false を返す.
    /// @param vec
    /// @param node
    bool erase(const vector<T> &vec, Node *node) {
        if (count(vec, node) == 0) { return false; }

        vector<Node*> path = {node};
        for (const T &x: vec) {
            node = node->next[x];
            path.emplace_back(node);
        }

        node->terminal_count--;
        for (Node *node: path) { node->prefix_count--; }

        for (size_t i = path.size() - 1; i >= 1; i--) {
            Node *cur = path[i];
            Node *par = path[i - 1];
            if (cur->prefix_count > 0) { break; }

            par->next.erase(cur->item);
            delete cur;
        }

        return true;
    }

    /// @brief Trie 木から vec を削除する. 登録されていなければ何もせず false を返す.
    /// @param vec
    bool erase(const vector<T> &vec) { return erase(vec, root); }

    // discard

    /// @brief Trie 木に登録されている vec をすべて削除する. ただし, 削除の開始位置は node から.
    /// @param vec
    /// @param node
    /// @return 削除した個数.
    size_t discard(const vector<T> &vec, Node *node) {
        Node *final_node = get(vec, node);
        if (final_node == nullptr || final_node->terminal_count == 0) { return 0; }

        const size_t cnt = final_node->terminal_count;

        vector<Node*> path = {node};
        for (const T &x: vec) {
            node = node->next[x];
            path.emplace_back(node);
        }

        node->terminal_count = 0;
        for (Node *n: path) { n->prefix_count -= cnt; }

        for (size_t i = path.size() - 1; i >= 1; i--) {
            Node *cur = path[i];
            Node *par = path[i - 1];
            if (cur->prefix_count > 0) { break; }

            par->next.erase(cur->item);
            delete cur;
        }

        return cnt;
    }

    /// @brief Trie 木に登録されている vec をすべて削除する.
    /// @param vec
    /// @return 削除した個数.
    size_t discard(const vector<T> &vec) { return discard(vec, root); }

    // count

    /// @brief Trie 木に登録されている vec の数を求める. ただし, 検索の開始位置は node から.
    /// @param vec
    /// @param node
    size_t count(const vector<T> &vec, Node *node) {
        Node *final_node = get(vec, node);
        return final_node != nullptr ? final_node->terminal_count : 0;
    }

    size_t count(const vector<T> &vec) { return count(vec, root); }

    // count_prefixing
    size_t count_prefixing(const vector<T> &vec, Node *node, bool equal = true) {
        Node *final_node = get(vec, node);
        if (final_node == nullptr) { return 0; }

        return equal ? node->prefix_count : node->prefix_count - node->terminal_count;
    }

    size_t count_prefixing(const vector<T> &vec, bool equal = true) { return count_prefixing(vec, root, equal); }

    // count_prefixed
    size_t count_prefixed(const vector<T> &vec, Node *node, bool equal = true) {
        size_t res = node->terminal_count;
        for (T x: vec) {
            if(!node->contains(x)) { return res; }

            node = node->next[x];
            res += node->terminal_count;
        }

        return equal ? res : res - node->terminal_count;
    }

    size_t count_prefixed(const vector<T> &vec, bool equal = true) { return count_prefixed(vec, root, equal); }

    // contains
    bool contains(const vector<T> &vec, Node *node) { return count(vec, node) > 0; }
    bool contains(const vector<T> &vec) { return contains(vec, root); }

    // search
    bool search(const vector<T> &vec, Node *node) { return contains(vec, node); }
    bool search(const vector<T> &vec) { return search(vec, root); }

    // search_prefixing
    bool search_prefixing(const vector<T> &vec, Node *node) { return count_prefixing(vec, node) > 0; }
    bool search_prefixing(const vector<T> &vec) { return search_prefixing(vec, root); }

    // search_prefixed
    bool search_prefixed(const vector<T> &vec, Node *node) { return count_prefixed(vec, node) > 0; }
    bool search_prefixed(const vector<T> &vec) { return search_prefixed(vec, root); }

    Node* get_root() { return root; }
    Node* get(const vector<T> &vec, Node *node) {
        for (T x: vec) {
            node = node->dig(x);
            if (node == nullptr) { break; }
        }

        return node;
    }

    Node* get(const vector<T> &vec) { return get(vec, root); }

    // size
    size_t size() const { return root->prefix_count; }

    // order statistics

    /// @brief 辞書順で node 以下 k 番目 (0-indexed) に小さい列を求める. ただし, node からの相対順位で数える.
    /// @param k
    /// @param node
    vector<T> find_by_order(size_t k, Node *node) {
        assert(k < node->prefix_count);

        vector<T> res;
        while (true) {
            if (k < node->terminal_count) { return res; }
            k -= node->terminal_count;

            for (const auto &[x, child]: node->next) {
                if (k < child->prefix_count) {
                    res.emplace_back(x);
                    node = child;
                    goto next_node;
                }

                k -= child->prefix_count;
            }

            assert(false);
            next_node:;
        }
    }

    /// @brief 辞書順で k 番目 (0-indexed) に小さい列を求める.
    /// @param k
    vector<T> find_by_order(size_t k) { return find_by_order(k, root); }

    /// @brief vec より真に辞書順で小さい列の個数を求める. ただし, 検索の開始位置は node から.
    /// @param vec
    /// @param node
    size_t order_of_key(const vector<T> &vec, Node *node) {
        size_t res = 0;
        for (const T &x: vec) {
            res += node->terminal_count;

            for (auto it = node->next.begin(); it != node->next.end() && it->first < x; ++it) {
                res += it->second->prefix_count;
            }

            if (!node->contains(x)) { return res; }
            node = node->next[x];
        }

        return res;
    }

    /// @brief vec より真に辞書順で小さい列の個数を求める.
    /// @param vec
    size_t order_of_key(const vector<T> &vec) { return order_of_key(vec, root); }

    /// @brief vec より辞書順で小さい列の個数を求める. ただし, 検索の開始位置は node から.
    /// @param vec
    /// @param node
    /// @param equal true のとき vec 自身と等しい列も個数に含める.
    size_t count_less(const vector<T> &vec, Node *node, bool equal = false) {
        return order_of_key(vec, node) + (equal ? count(vec, node) : 0);
    }

    /// @brief vec より辞書順で小さい列の個数を求める.
    /// @param vec
    /// @param equal true のとき vec 自身と等しい列も個数に含める.
    size_t count_less(const vector<T> &vec, bool equal = false) { return count_less(vec, root, equal); }

    /// @brief vec より辞書順で大きい列の個数を求める. ただし, 検索の開始位置は node から.
    /// @param vec
    /// @param node
    /// @param equal true のとき vec 自身と等しい列も個数に含める.
    size_t count_more(const vector<T> &vec, Node *node, bool equal = false) {
        return node->prefix_count - order_of_key(vec, node) - (equal ? 0 : count(vec, node));
    }

    /// @brief vec より辞書順で大きい列の個数を求める.
    /// @param vec
    /// @param equal true のとき vec 自身と等しい列も個数に含める.
    size_t count_more(const vector<T> &vec, bool equal = false) { return count_more(vec, root, equal); }

    /// @brief 登録されている列の中で辞書順最小の列を求める.
    optional<vector<T>> min() {
        if (root->prefix_count == 0) { return nullopt; }

        Node *node = root;
        vector<T> res;
        while (node->terminal_count == 0) {
            auto it = node->next.begin();
            res.emplace_back(it->first);
            node = it->second;
        }

        return res;
    }

    /// @brief 登録されている列の中で辞書順最大の列を求める.
    optional<vector<T>> max() {
        if (root->prefix_count == 0) { return nullopt; }

        Node *node = root;
        vector<T> res;
        while (!node->next.empty()) {
            auto it = node->next.rbegin();
            res.emplace_back(it->first);
            node = it->second;
        }

        return res;
    }

    /// @brief 登録されている列の中で vec より辞書順で大きい最小の列 (successor) を求める.
    /// @param vec
    /// @param equal true のとき vec 自身も候補に含める (vec 以上で最小の列を求める).
    optional<vector<T>> next(const vector<T> &vec, bool equal = false) {
        size_t idx = order_of_key(vec) + (equal ? 0 : count(vec));
        if (idx >= size()) { return nullopt; }

        return find_by_order(idx);
    }

    /// @brief 登録されている列の中で vec より辞書順で小さい最大の列 (predecessor) を求める.
    /// @param vec
    /// @param equal true のとき vec 自身も候補に含める (vec 以下で最大の列を求める).
    optional<vector<T>> prev(const vector<T> &vec, bool equal = false) {
        size_t idx = order_of_key(vec) + (equal ? count(vec) : 0);
        if (idx == 0) { return nullopt; }

        return find_by_order(idx - 1);
    }

    // for string
    void insert(const string &str, Node *node) { insert(vector<char>(str.begin(), str.end()), node); }
    void insert(const string &str) { insert(str, root); }

    bool erase(const string &str, Node *node) { return erase(vector<char>(str.begin(), str.end()), node); }
    bool erase(const string &str) { return erase(str, root); }

    size_t discard(const string &str, Node *node) { return discard(vector<char>(str.begin(), str.end()), node); }
    size_t discard(const string &str) { return discard(str, root); }

    size_t count(const string &str, Node *node) { return count(vector<char>(str.begin(), str.end()), node); }
    size_t count(const string &str) { return count(str, root); }

    size_t count_prefixing(const string &str, Node *node) { return count_prefixing(vector<char>(str.begin(), str.end()), node); }
    size_t count_prefixing(const string &str) { return count_prefixing(str, root); }

    size_t count_prefixed(const string &str, Node *node) { return count_prefixed(vector<char>(str.begin(), str.end()), node); }
    size_t count_prefixed(const string &str) { return count_prefixed(str, root); }

    bool contains(const string &str, Node *node) { return contains(vector<char>(str.begin(), str.end()), node); }
    bool contains(const string &str) { return contains(str, root); }

    bool search(const string &str, Node *node) { return search(vector<char>(str.begin(), str.end()), node); }
    bool search(const string &str) { return search(str, root); }

    bool search_prefixing(const string &str, Node *node) { return search_prefixing(vector<char>(str.begin(), str.end()), node); }
    bool search_prefixing(const string &str) { return search_prefixing(str, root); }

    bool search_prefixed(const string &str, Node *node) { return search_prefixed(vector<char>(str.begin(), str.end()), node); }
    bool search_prefixed(const string &str) { return search_prefixed(str, root); }

    Node* get(const string &str, Node *node) { return get(vector<char>(str.begin(), str.end()), node); }
    Node* get(const string &str) { return get(str, root); }

    size_t order_of_key(const string &str, Node *node) { return order_of_key(vector<char>(str.begin(), str.end()), node); }
    size_t order_of_key(const string &str) { return order_of_key(str, root); }

    size_t count_less(const string &str, Node *node, bool equal = false) { return count_less(vector<char>(str.begin(), str.end()), node, equal); }
    size_t count_less(const string &str, bool equal = false) { return count_less(str, root, equal); }

    size_t count_more(const string &str, Node *node, bool equal = false) { return count_more(vector<char>(str.begin(), str.end()), node, equal); }
    size_t count_more(const string &str, bool equal = false) { return count_more(str, root, equal); }

    optional<vector<char>> next(const string &str, bool equal = false) { return next(vector<char>(str.begin(), str.end()), equal); }
    optional<vector<char>> prev(const string &str, bool equal = false) { return prev(vector<char>(str.begin(), str.end()), equal); }
};
