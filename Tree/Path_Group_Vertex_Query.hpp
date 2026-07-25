#pragma once

#include "../template/template.hpp"
#include "Tree.hpp"
#include "Lowest_Common_Ancestor.hpp"
#include "../Segment_Tree/Segment_Tree.hpp"

template<typename G>
class Path_Group_Vertex_Query {
    private:
    Tree T;
    Lowest_Common_Ancestor LCA;
    function<G(G, G)> op;
    G unit;
    function<G(G)> neg;

    unique_ptr<Segment_Tree<G>> Sf; // 根方向 -> 葉方向の順に演算する.
    unique_ptr<Segment_Tree<G>> Sb; // 葉方向 -> 根方向の順に演算する.

    // 根から頂点 `x` までのパス上の総積を, 根側から `x` 側の順に求める.
    G to_root(const int &x) const { return Sf->product(0, T.in_time[x]); }

    // 頂点 `x` から根までのパス上の総積を, `x` 側から根側の順に求める.
    G from_root(const int &x) const { return Sb->product(0, T.in_time[x]); }

    public:
    /// @brief コンストラクタ. 頂点集合に群 `G` の値を割り当て, パスクエリの準備を行う.
    /// @param tree 対象となる Tree オブジェクト. 事前に seal() (is_locked() == true) されている必要がある.
    /// @param data 各頂点 `v` における初期値 `data[v]`.
    /// @param op `G` 上の演算.
    /// @param unit `G` の単位元.
    /// @param neg `G` における逆元を求める関数.
    Path_Group_Vertex_Query(Tree &tree, const vector<G> &data, const function<G(G, G)> op, const G unit, const function<G(G)> neg):
        T(tree), LCA(T), op(op), unit(unit), neg(neg) {
        T.calculate_euler_tour_vertex();

        vector<G> tour(T.euler_tour_vertex.size(), unit);
        for (int v = T.offset(); v < T.vector_size(); v++) {
            tour[T.in_time[v]] = data[v];
            unless(T.is_root(v)) { tour[T.out_time[v] + 1] = neg(data[v]); }
        }

        function<G(G, G)> rev_op = [op](const G &x, const G &y) -> G { return op(y, x); };

        Sf = make_unique<Segment_Tree<G>>(tour, op, unit);
        Sb = make_unique<Segment_Tree<G>>(tour, rev_op, unit);
    }

    /// @brief 頂点 `v` における値を `x` に変更する.
    /// @param v 頂点
    /// @param x 変更後の `G` の頂点 `v` における値
    void update(const int &v, const G &x) {
        Sf->update(T.in_time[v], x);
        Sb->update(T.in_time[v], x);

        unless(T.is_root(v)) {
            Sf->update(T.out_time[v] + 1, neg(x));
            Sb->update(T.out_time[v] + 1, neg(x));
        }
    }

    /// @brief 頂点 `u` から頂点 `v` へのパス上に関する総積を求める.
    /// @param u パスの始点
    /// @param v パスの終点
    /// @return 頂点 `u` から頂点 `v` へのパス (両端含む) 上にある値達を, `u` 側から `v` 側の順に演算した総積
    G query(const int &u, const int &v) const {
        int w = LCA.lowest_common_ancestor(u, v);

        G U = from_root(u);
        unless(T.is_root(w)) { U = op(U, neg(from_root(T.get_parent(w)))); }

        G D = op(neg(to_root(w)), to_root(v));

        return op(U, D);
    }
};
