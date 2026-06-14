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

    public:
    Treap(): mt(std::random_device{}()) {}

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

        if (mid) delete mid;

        root = merge(less, more);
    }
};
