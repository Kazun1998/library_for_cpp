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

    int n;
    const function<M(M, M)> op;
    const M unit;
    vector<Node*> roots;
    int version;

    Node* build(const int l, const int r, const vector<M> &data) {
        // 1 要素区間を表す頂点 → 葉
        if (r - l == 1) return new Node(data[l], l, r);

        // そうでない場合, 2 要素以上の区間なので, 左と右に分割できる.
        int m = (l + r) / 2;

        Node* left = build(l, m, data);
        Node* right = build(m, r, data);

        return new Node(op(left->x, right->x), l, r, left, right);
    }

    void build_up(const vector<M> &data) {
        roots.emplace_back(build(0, n, data));
    }

    public:
    Persistent_Segment_Tree(const vector<M> &data, const function<M(M, M)> op, const M unit): n(data.size()), op(op), unit(unit), version(0) {
        build_up(data);
    }

    Persistent_Segment_Tree(const int n, const function<M(M, M)> op, const M unit): n(n), op(op), unit(unit), version(0) {
        build_up(vector<M>(n, unit));
    }
};
