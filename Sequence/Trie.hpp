#pragma one

#include"../template/template.hpp"

template<typename T>
class Trie {
    struct Node {
        T item;
        unordered_map<T, Node*> next;
        size_t terminal_count, prefix_count;

        Node(): Node(T()) {}
        Node(const T &item): item(item), terminal_count(0), prefix_count(0) {}

        constexpr bool contains(const T &x) const { return next.find(x) != next.end(); }
    };

    Node *root;

    public:
    Trie() { root = new Node(); }

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
    constexpr void insert(const vector<T> &vec) { insert(vec, root); }

    // count

    /// @brief Trie 木に登録されている vec の数を求める. ただし, 検索の開始位置は node から.
    /// @param vec 
    /// @param node 
    size_t count(const vector<T> &vec, Node *node) {
        Node *final_node = get(vec, node);
        return final_node != nullptr ? final_node->terminal_count : 0;
    }

    constexpr size_t count(const vector<T> &vec) { return count(vec, root); }

    // count_prefixing
    size_t count_prefixing(const vector<T> &vec, Node *node, bool equal = true) {
        Node *final_node = get(vec, node);
        if (final_node == nullptr) { return 0; }

        return equal ? node->prefix_count : node->prefix_count - node->terminal_count;
    }

    constexpr size_t count_prefixing(const vector<T> &vec, bool equal = true) { return count_prefixing(vec, root, equal); }

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

    constexpr size_t count_prefixed(const vector<T> &vec, bool equal = true) { return count_prefixed(vec, root, equal); }

    // contains
    constexpr bool contains(const vector<T> &vec, Node *node) { return count(vec, node) > 0; }
    constexpr bool contains(const vector<T> &vec) { return contains(vec, root); }

    // search
    constexpr bool search(const vector<T> &vec, Node *node) { return contains(vec, node); }
    constexpr bool search(const vector<T> &vec) { return search(vec, root); }

    // search_prefixing
    constexpr bool search_prefixing(const vector<T> &vec, Node *node) { return count_prefixing(vec, node) > 0; }
    constexpr bool search_prefixing(const vector<T> &vec) { return search_prefixing(vec, root); }

    // search_prefixed
    constexpr bool search_prefixed(const vector<T> &vec, Node *node) { return count_prefixed(vec, node) > 0; }
    constexpr bool search_prefixed(const vector<T> &vec) { return search_prefixed(vec, root); }

    constexpr Node* get_root() { return root; }
    Node* get(const vector<T> &vec, Node *node) {
        for (T x: vec) {
            if (!node->contains(x)) { return nullptr; }

            node = node->next[x];
        }

        return node;
    }

    constexpr Node* get(const vector<T> &vec) { return get(vec, root); }

    // size
    constexpr const size_t size() const { return root->prefix_count; }

    // for string
    constexpr void insert(const string &str, Node *node) { insert(vector<char>(str.begin(), str.end()), node); }
    constexpr void insert(const string &str) { insert(str, root); }

    constexpr size_t count(const string &str, Node *node) { return count(vector<char>(str.begin(), str.end()), node); }
    constexpr size_t count(const string &str) { return count(str, root); }

    constexpr size_t count_prefixing(const string &str, Node *node) { return count_prefixing(vector<char>(str.begin(), str.end()), node); }
    constexpr size_t count_prefixing(const string &str) { return count_prefixing(str, root); }

    constexpr size_t count_prefixed(const string &str, Node *node) { return count_prefixed(vector<char>(str.begin(), str.end()), node); }
    constexpr size_t count_prefixed(const string &str) { return count_prefixed(str, root); }

    constexpr bool contains(const string &str, Node *node) { return contains(vector<char>(str.begin(), str.end()), node); }
    constexpr bool contains(const string &str) { return contains(str, root); }

    constexpr bool search(const string &str, Node *node) { return search(vector<char>(str.begin(), str.end()), node); }
    constexpr bool search(const string &str) { return search(str, root); }

    constexpr bool search_prefixing(const string &str, Node *node) { return search_prefixing(vector<char>(str.begin(), str.end()), node); }
    constexpr bool search_prefixing(const string &str) { return search_prefixing(str, root); }

    constexpr bool search_prefixed(const string &str, Node *node) { return search_prefixed(vector<char>(str.begin(), str.end()), node); }
    constexpr bool search_prefixed(const string &str) { return search_prefixed(str, root); }

    constexpr Node* get(const string &str, Node *node) { return get(vector<char>(str.begin(), str.end())); }
    constexpr Node* get(const string &str) { return get(str, root); }
};
