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
    const M identity;
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
        if (b <= l || r <= a) return identity;
        
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
    /// @brief コンストラクタ. 配列 data で初期化する.
    /// @param data 初期データ
    /// @param op 二項演算子
    /// @param identity 単位元
    Persistent_Segment_Tree(const vector<M> &data, const function<M(M, M)> op, const M identity): n(data.size()), op(op), identity(identity), version(0) {
        build_up(data);
    }

    /// @brief コンストラクタ. サイズ n, 全要素 identity で初期化する.
    /// @param n 配列サイズ
    /// @param op 二項演算子
    /// @param identity 単位元
    Persistent_Segment_Tree(const int n, const function<M(M, M)> op, const M identity): n(n), op(op), identity(identity), version(0) {
        build_up(vector<M>(n, identity));
    }

    ~Persistent_Segment_Tree() {
        for (Node* node : nodes_pool) delete node;
    }

    /// @brief バージョン t をコピーして新しいバージョンを作成し, そのインデックスを返す.
    /// @param t ベースとするバージョン (デフォルトは最新バージョン)
    /// @return 新しいバージョン番号
    int increment(int t = -1) {
        if (t == -1) t = version;
        assert(t <= version);
        roots.emplace_back(roots[t]);
        return ++version;
    }

    /// @brief バージョン s をベースに第 k 要素を x に更新した状態を作成し, バージョン t に代入する.
    /// @param s 元のバージョン
    /// @param t 保存先のバージョン
    /// @param k 更新するインデックス (0-indexed)
    /// @param x 更新後の値
    /// @return バージョン t
    int update(const int s, const int t, const int k, const M x) {
        assert(s <= version);
        assert(t <= version);
        assert(0 <= k && k < n);

        roots[t] = _update(roots[s], 0, n, k, x);
        return t;
    }

    /// @brief バージョン t をベースに第 k 要素を x に更新した新しい状態を作成する. 現在の最新バージョンを上書きする.
    /// @param t ベースとするバージョン
    /// @param k 更新するインデックス (0-indexed)
    /// @param x 更新後の値
    /// @return 最新バージョン番号
    int update(const int t, const int k, const M x) { return update(t, version, k, x); }

    /// @brief 最新バージョンをベースに第 k 要素を x に更新した新しい状態を作成し、最新バージョンを上書きする.
    /// @param k 更新するインデックス (0-indexed)
    /// @param x 更新後の値
    /// @return 最新バージョン番号
    int update(const int k, const M x) { return update(version, k, x); }

    /// @brief バージョン t をその場で更新（上書き）する (update(t, t, k, x) のシノニム).
    /// @param t 更新対象のバージョン
    /// @param k インデックス
    /// @param x 値
    /// @return バージョン番号 t
    int amend(const int t, const int k, const M x) { return update(t, t, k, x); }

    /// @brief バージョン s の [l, r] の範囲をバージョン t にコピー（マージ）する.
    /// @param s コピー元のバージョン
    /// @param t コピー先のバージョン
    /// @param l 左端 (閉区間)
    /// @param r 右端 (閉区間)
    /// @return バージョン t
    int copy(const int s, const int t, const int l, const int r) {
        assert(s <= version);
        assert(t <= version);
        if (n == 0 || l > r) return t;
        assert(0 <= l && r < n);

        roots[t] = _copy(roots[t], roots[s], l, r + 1, 0, n);
        return t;
    }

    /// @brief バージョン t の [l, r] の範囲を最新バージョンにコピーする.
    /// @param t コピー元のバージョン
    /// @param l 左端 (閉区間)
    /// @param r 右端 (閉区間)
    /// @return 最新バージョン番号
    int copy(const int t, const int l, const int r) { return copy(t, version, l, r); }

    /// @brief バージョン s の内容をバージョン t にそのままコピーする.
    /// @param s コピー元のバージョン
    /// @param t コピー先のバージョン
    /// @return バージョン t
    int clone(const int s, const int t) {
        assert(s <= version);
        assert(t <= version);
        roots[t] = roots[s];
        return t;
    }

    /// @brief バージョン t の内容を現在の最新バージョンにそのままコピーする.
    /// @param t コピー元のバージョン
    /// @return 最新バージョン番号
    int clone(const int t) { return clone(t, version); }

    /// @brief バージョン t における [l, r] の範囲の総積を求める.
    /// @param t 取得対象のバージョン
    /// @param l 左端 (閉区間)
    /// @param r 右端 (閉区間)
    /// @return 区間の総積
    M product(const int t, const int l, const int r) const {
        assert(t <= version);
        if (l > r || n == 0) return identity;
        return _product(roots[t], l, r + 1, 0, n);
    }

    /// @brief 最新バージョンにおける [l, r] の範囲の総積を求める.
    /// @param l 左端 (閉区間)
    /// @param r 右端 (閉区間)
    /// @return 区間の総積
    M product(const int l, const int r) const {
        return product(version, l, r);
    }

    /// @brief バージョン t における全区間の総積を求める.
    /// @param t 取得対象のバージョン
    /// @return 全区間の総積
    M all_product(const int t) const { return product(t, 0, n - 1); }

    /// @brief 最新バージョンにおける全区間の総積を求める.
    /// @return 全区間の総積
    M all_product() const { return all_product(version); }

    /// @brief バージョン t における第 k 要素の値を取得する.
    /// @param t 取得対象のバージョン
    /// @param k インデックス (0-indexed)
    /// @return 要素の値
    M get(const int t, const int k) const {
        assert(t <= version);
        if (n == 0) return identity;
        assert(0 <= k && k < n);

        return _get(roots[t], 0, n, k);
    }

    /// @brief 最新バージョンにおける第 k 要素の値を取得する.
    /// @param k インデックス (0-indexed)
    /// @return 要素の値
    M get(const int k) const { return get(version, k); }

    /// @brief 最新バージョンにおける第 k 要素の値を取得する.
    M operator[](const int k) const { return get(version, k); }

    /// @brief 現在の最新バージョン番号を取得する.
    int current_version() const { return version; }
};
