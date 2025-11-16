#pragma once

#include"../template/template.hpp"

template<typename K, typename V>
class Adelson_Velsky_and_Landis_Tree {
    class Node {
        public:
        K key;
        V value;
        Node *left, *right;
        int height, size;

        Node(K key, V value): key(key), value(value), left(nullptr), right(nullptr), height(1), size(1) {}

        int set_height() {
            int left_hight = (left == nullptr) ? 0 : left->height;
            int right_hight = (right == nullptr) ? 0 : right->height;

            return height = 1 + std::max(left_hight, right_hight);
        }

        int set_size() {
            int left_size = (left == nullptr) ? 0 : left->size;
            int right_size = (right == nullptr) ? 0 : right->size;

            return size = 1 + left_size + right_size;
        }

        int get_height() { return height; }

        int get_bias() {
            int left_hight = (left == nullptr) ? 0 : left->height;
            int right_hight = (right == nullptr) ? 0 : right->height;
            return left_hight - right_hight;
        }
    };

    private:
    Node* insert_inner(Node *node, K &key, V &value) {
        if (node == nullptr) { return new Node(key, value); }

        if (key == node->key) {
            node->value = value;
            return node;
        }

        if (key < node->key) {
            node->left = insert_inner(node->left, key, value);
        } else {
            node->right = insert_inner(node->right, key, value);
        }

        node->set_height();
        node->set_size();

        int bias = node->get_bias();

        // Case I: Left Left
        if (bias > 1 && key < node->left->key) {
            return right_rotation(node);
        }

        // Case II: Right Right
        if (bias < -1 && key > node->right->key) {
            return left_rotation(node);
        }

        // Case III: Left Right
        if (bias > 1 && key > node->left->key) {
            node->left = left_rotation(node->left);
            return right_rotation(node);
        }

        // Case IV: Right Left
        if (bias < -1 && key < node->right->key) {
            node->right = right_rotation(node->right);
            return left_rotation(node);
        }

        return node;
    }

    Node* delete_inner(Node *node, K &key) {
        if (node == nullptr) { return node; }
        else if (key < node->key) {
            node->left = delete_inner(node->left, key);
        } else if (key > node->key) {
            node->right = delete_inner(node->right, key);
        } else {
            if (node->left == nullptr) {
                Node *tmp = node->right;
                delete node;
                return tmp;
            } else if (node->right == nullptr) {
                Node *tmp = node->left;
                delete node;
                return tmp;
            }

            Node *tmp = node->right;
            while (tmp->left != nullptr) {
                tmp = tmp->left;
            }

            node->key = tmp->key;
            node->value = tmp->value;
            node->right = delete_inner(node->right, tmp->key);
        }

        if (node == nullptr) { return node; }

        node->set_height();
        node->set_size();

        int bias = node->get_bias();

        // Case I: Left Left
        if (bias > 1 && node->left->get_bias() >= 0) {
            return right_rotation(node);
        }

        // Case II: Right Right
        if (bias < -1 && node->right->get_bias() <= 0) {
            return left_rotation(node);
        }

        // Case III: Left Right
        if (bias > 1 && node->left->get_bias() < 0) {
            node->left = left_rotation(node->left);
            return right_rotation(node);
        }

        // Case IV: Right Left
        if (bias < -1 && node->right->get_bias() > 0) {
            node->right = right_rotation(node->right);
            return left_rotation(node);
        }

        return node;
    }

    Node* left_rotation(Node* x) {
        Node *y = x->right;
        Node *z = y->left;

        y->left = x;
        x->right = z;

        x->set_height();
        y->set_height();

        x->set_size();
        y->set_size();

        return y;
    }

    Node* right_rotation(Node *x) {
        Node *y = x->left;
        Node *z = y->right;

        y->right = x;
        x->left = z;

        x->set_height();
        y->set_height();

        x->set_size();
        y->set_size();

        return y;
    }

    Node* next_inner(const K &key, bool equal) const {
        Node *successor = nullptr;
        Node *node = root;

        while (node != nullptr) {
            bool condition = equal ? (key <= node->key) : (key < node->key);

            if (condition) {
                successor = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }

        return successor;
    }

    Node* previous_inner(const K &key, bool equal) const {
        Node *predecessor = nullptr;
        Node *node = root;

        while (node != nullptr) {
            bool condition = equal ? (key >= node->key) : (key > node->key);

            if (condition) {
                predecessor = node;
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return predecessor;
    }

    Node* find_inner(const K &key) {
        Node *node = root;

        while (node != nullptr) {
            if (key == node->key) { return node; }

            node = (key < node->key) ? node->left : node->right;
        }

        return nullptr;
    }

    const Node* find_inner(const K &key) const {
        const Node *node = root;

        while (node != nullptr) {
            if (key == node->key) { return node; }
            node = (key < node->key) ? node->left : node->right;
        }

        return nullptr;
    }

    void clear(Node* node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    public:
    Node *root;
    Adelson_Velsky_and_Landis_Tree(): root(nullptr) {}
    ~Adelson_Velsky_and_Landis_Tree() { clear(root); }

    inline int size() const { return root == nullptr ? 0 : root->size; }

    inline void insert(K key) { insert(key, V()); }

    inline void insert(K key, V value) {
        root = insert_inner(root, key, value);
    }

    inline void discard(K key) { root = delete_inner(root, key); }

    K next(const K &key, bool equal = true) const {
        Node *successor = next_inner(key, equal);

        if (successor == nullptr) { throw std::out_of_range(""); }

        return successor->key;
    }

    K next(const K &key, const K &default_value, bool equal = true) const {
        Node *successor = next_inner(key, equal);

        return (successor != nullptr) ? successor->key : default_value;
    }

    K previous(const K &key, bool equal = true) const {
        Node *predecessor = previous_inner(key, equal);

        if (predecessor == nullptr) { throw std::out_of_range(""); }

        return predecessor->key;
    }

    K previous(const K &key, const K &default_value, bool equal = true) const {
        Node *predecessor = previous_inner(key, equal);

        return (predecessor != nullptr) ? predecessor->key : default_value;
    }

    V& operator[](const K &key) {
        insert(key);
        return find_inner(key)->value;
    }

    inline V* find(const K &key) {
        Node *node = find_inner(key);
        return (node == nullptr) ? nullptr : &(node->value);
    }

    inline const V* find(const K &key) const {
        const Node *node = find_inner(key);
        return (node == nullptr) ? nullptr : &(node->value);
    }

    K& kth_key(int k) {
        if (k < 0) { k += size(); }

        unless(0 <= k && k < size()) { throw out_of_range(""); }

        Node *node = root;
        while (true) {
            int t = (node->left == nullptr) ? 0 : node->left->size;

            if (k == t) { return node->key; }
            else if (k < t) { node = node->left; }
            else {
                k -= t + 1;
                node = node->right;
            }
        }
    }

    int less_count_inner(Node *node, const K &key, bool equal) const {
        if (node == nullptr) { return 0; }

        bool cond = equal ? (key < node->key) : (key <= node->key);

        if (cond) { return less_count_inner(node->left, key, equal); }

        int left_size = (node->left == nullptr) ? 0 : node->left->size;
        return 1 + left_size + less_count_inner(node->right, key, equal);
    }

    int less_count(const K &key, bool equal = false) const {
        return less_count_inner(root, key, equal);
    }
};
