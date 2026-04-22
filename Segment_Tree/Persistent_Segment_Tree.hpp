#pragma once

#include "../template/template.hpp"

template<typename M>
class Persistent_Segment_Tree {
    private:
    struct Node {
        M x;
        int l, r;
        Node *left_child, *right_child;

        Node(M x, int l, int r) : x(x), l(l), r(r), left_child(nullptr), right_child(nullptr) {}
        Node(M x, int l, int r, Node* left, Node* right) : x(x), l(l), r(r), left_child(left), right_child(right) {}
    };
};
