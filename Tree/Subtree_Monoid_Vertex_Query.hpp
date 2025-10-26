#pragma once

#include"../template/template.hpp"
#include"Tree.hpp"
#include"../Segment_Tree/Segment_Tree.hpp"

template<typename M>
class Subtree_Monoid_Vertex_Query {
    private:
    Tree T;
    unique_ptr<Segment_Tree<M>> S;

    public:
    Subtree_Monoid_Vertex_Query(Tree &tree, const vector<M> &data, const function<M(M, M)> op, const M unit): T(tree) {
        T.calculate_euler_tour_vertex();

        // NEXT: 遅延セグメント木に対応 + Segment Tree のベクトルのサイズを下げる.

        int n = T.order();
        vector<M> first(2 * n);
        for (int v = T.offset(); v < T.vector_size(); v++) {
            first[T.in_time[v]] = data[v];
        }

        S = make_unique<Segment_Tree<M>>(first, op, unit);
    }

    /*
    @brief 頂点 `v` を `x` に変更する.
    @param v 頂点
    @param x 変更後の `M` の頂点 `v` における値
    */
    void update(const int &v, const M &x) {
        S->update(T.in_time[v], x);
    }

    /*
    @brief 頂点 `v` を根とする部分木に関する総積を求める.
    @param v 部分木の頂点
    @returns 頂点 `v` を根とする部分木に関する総積
    */
    M query(const int &v) {
        return S->product(T.in_time[v], T.out_time[v]);
    }
};