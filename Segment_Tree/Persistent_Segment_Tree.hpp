#pragma once

#include "../template/template.hpp"

template<typename M>
class Persistent_Segment_Tree {
    private:
    struct Node {
        M x;
        Node *left_child, *right_child;

        Node(M x) : x(x), left_child(nullptr), right_child(nullptr) {}
        Node(M x, Node* left, Node* right) : x(x), left_child(left), right_child(right) {}
    };

    int n;
    const function<M(M, M)> op;
    const M unit;
    vector<Node*> roots;
    vector<Node*> nodes_pool;
    int version;

    Node* new_node(M x, Node* l = nullptr, Node* r = nullptr) {
        Node* res = new Node(x, l, r);
        nodes_pool.push_back(res);
        return res;
    }

    Node* build(const int l, const int r, const vector<M> &data) {
        if (l >= r) return nullptr;
        // 1 要素区間を表す頂点 → 葉
        if (r - l == 1) return new_node(data[l]);

        // そうでない場合, 2 要素以上の区間なので, 左と右に分割できる.
        int m = (l + r) / 2;

        Node* left = build(l, m, data);
        Node* right = build(m, r, data);

        return new_node(op(left->x, right->x), left, right);
    }

    void build_up(const vector<M> &data) {
        if (n > 0) roots.emplace_back(build(0, n, data));
        else roots.emplace_back(nullptr);
    }

    Node* _update(const Node* node, const int l, const int r, const int k, const M x) {
        // 葉に到達した場合, 新しい値を保持するノードを作成して返す.
        if (r - l == 1) return new_node(x);

        int m = (l + r) / 2;
        Node *left = node->left_child, *right = node->right_child;

        // 更新対象のインデックスに応じて, 左または右の子を再帰的に新しく作成する
        if (k < m) left = _update(left, l, m, k, x);
        else right = _update(right, m, r, k, x);

        // 新しく作成した子（片方）と, 既存のもう片方の子を組み合わせて,現在の高さのノードを新しく作成する
        return new_node(op(left->x, right->x), left, right);
    }

    // 半開区間 [l, r) を計算する. 現在見ているノードは半開区間 [a, b) を表す.
    M _product(const Node* node, const int l, const int r, const int a, const int b) const {
        // [l, r) と [a, b) が互いに素ならば, 単位元を返す.
        if (b <= l || r <= a) return unit;

        // [a, b) が [l, r) に含まれているならば, ノードの値をそのまま返す.
        if (l <= a && b <= r) return node->x;

        int m = (a + b) / 2;

        M vl = _product(node->left_child, l, r, a, m);
        M vr = _product(node->right_child, l, r, m, b);

        return op(vl, vr);
    }

    M _get(const Node* node, const int l, const int r, const int k) const {
        if (r - l == 1) return node->x;
        int m = (l + r) / 2;
        if (k < m) return _get(node->left_child, l, m, k);
        else return _get(node->right_child, m, r, k);
    }

    Node* _copy(const Node* node_curr, const Node* node_src, const int l, const int r, const int a, const int b) {
        if (b <= l || r <= a) return const_cast<Node*>(node_curr);
        if (l <= a && b <= r) return const_cast<Node*>(node_src);

        int m = (a + b) / 2;
        Node *left = _copy(node_curr->left_child, node_src->left_child, l, r, a, m);
        Node *right = _copy(node_curr->right_child, node_src->right_child, l, r, m, b);

        return new_node(op(left->x, right->x), left, right);
    }

    public:
    Persistent_Segment_Tree(const vector<M> &data, const function<M(M, M)> op, const M unit): n(data.size()), op(op), unit(unit), version(0) {
        build_up(data);
    }

    Persistent_Segment_Tree(const int n, const function<M(M, M)> op, const M unit): n(n), op(op), unit(unit), version(0) {
        build_up(vector<M>(n, unit));
    }

    ~Persistent_Segment_Tree() {
        for (Node* node : nodes_pool) delete node;
    }

    // バージョン t をコピーして新しいバージョンを作成し, そのインデックスを返す. 
    // t が -1 の場合は最新のバージョンをコピーする.
    int increment(int t = -1) {
        if (t == -1) t = version;
        assert(t <= version);
        roots.emplace_back(roots[t]);
        return ++version;
    }

    // バージョン t をベースに第 k 要素を x に更新した新しい状態を作成する.
    // 現在の最新バージョンを上書きする.
    int update(const int t, const int k, const M x) {
        assert(t <= version);
        assert(0 <= k && k < n);

        Node* new_root = _update(roots[t], 0, n, k, x);
        roots[version] = new_root;
        return version;
    }

    int update(const int k, const M x) { return update(version, k, x); }

    int copy(const int t, const int l, const int r) {
        assert(t <= version);
        if (n == 0 || l > r) return version;
        assert(0 <= l && r < n);

        roots[version] = _copy(roots[version], roots[t], l, r + 1, 0, n);
        return version;
    }

    M product(const int t, const int l, const int r) const {
        assert(t <= version);
        if (l > r || n == 0) return unit;
        return _product(roots[t], l, r + 1, 0, n);
    }

    M product(const int l, const int r) const {
        return product(version, l, r);
    }

    M get(const int t, const int k) const {
        assert(t <= version);
        if (n == 0) return unit;
        assert(0 <= k && k < n);

        return _get(roots[t], 0, n, k);
    }

    M get(const int k) const { return get(version, k); }

    M operator[](const int k) const { return get(version, k); }

    int current_version() const { return version; }
};
