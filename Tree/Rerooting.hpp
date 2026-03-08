#pragma once

#include"../template/template.hpp"
#include"Tree_DP.hpp"

template<typename X, typename M>
class Rerooting_DP {
    public:
    vector<X> lower, upper, result;

    public:
    Rerooting_DP(Tree &T, function<M(X, int, int)> f, function<X(M, int)> g, function<X(M, int)> h, function<M(M, M)> merge, const M unit) {
        using V = int;

        // T の頂点 v を根とする部分木に関する値
        lower = Tree_DP_from_Leaf(T, f, g, merge, unit);
        upper.resize(T.vector_size());

        for (V v: T.top_down()) {
            const auto &children_v = T.get_children(v);
    
            vector<M> left{unit}, right{unit};
            for (V c: children_v) {
                left.emplace_back(merge(left.back(), f(lower[c], v, c)));
            }

            for (auto it = children_v.rbegin(); it != children_v.rend(); ++it) {
                V c = *it;
                right.emplace_back(merge(right.back(), f(lower[c], v, c)));
            }

            reverse(right.begin(), right.end());
            for (int i = 0; i < children_v.size(); i++) {
                V c = children_v[i];
                M a = merge(left[i], right[i + 1]);
                M b = T.is_root(v) ? a : merge(a, f(upper[v], v, T.get_parent(v)));

                upper[c] = g(b, v);
            }
        }

        result.resize(T.vector_size());
        for (V v: T.top_down()) {
            M a = T.is_root(v) ? unit : f(upper[v], v, T.get_parent(v));
            for (V c: T.get_children(v)) {
                a = merge(a, f(lower[c], v, c));
            }

            result[v] = h(a, v);
        }
    }

    Rerooting_DP(Tree &T, function<M(X, int, int)> f, function<X(M, int)> g, function<M(M, M)> merge, const M unit):
        Rerooting_DP(T, f, g, g, merge, unit) {}
};
