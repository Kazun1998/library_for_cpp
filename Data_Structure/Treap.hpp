#pragma once

#include"../template/template.hpp"

template<typename T>
class Treap {
    struct Node {
        T key;
        int priority;
        Node *left = nullptr, *right = nullptr;
        Node(T key, int priority) : key(key), priority(priority) {}
    };

    Node *root = nullptr;
    std::mt19937 mt;

    public:
    Treap(): mt(std::random_device{}()) {}

    static Node* merge(Node* first, Node* second) {
        if (!first || !second) return first ? first : second;

        if (first->priority > second->priority) {
            first->right = merge(first->right, second);
            return first;
        } else {
            second->left = merge(first, second->left);
            return second;
        }
    }

    static void split(Node* tree, T key, Node*& less, Node*& more) {
        if (!tree) { less = more = nullptr; return; }

        if (tree->key < key) {
            split(tree->right, key, tree->right, more);
            less = tree;
        } else {
            split(tree->left, key, less, tree->left);
            more = tree;
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
