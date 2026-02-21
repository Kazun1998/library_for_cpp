#pragma once

#include "Tree.hpp"

template<typename X>
vector<X> Tree_DP_from_Root(Tree &T, function<X(X, int, int)> f, const X alpha) {
    vector<X> data(T.vector_size());

    data[T.get_root()] = alpha;

    auto dfs = [&](auto self, int x) -> void {
        for (int y: T.get_children(x)) {
            data[y] = f(data[x], x, y);
            self(self, y);
        }
    };

    dfs(dfs, T.get_root());
    return data;
}

template<typename X, typename M>
vector<X> Tree_DP_from_Leaf(Tree &T, function<M(X, int, int)> f, function<X(M, int)> g, function<M(M, M)> merge, const M unit) {
    vector<X> data(T.vector_size());

    auto dfs = [&](auto self, int v) -> void {
        M children_product = unit;
        for (int w: T.get_children(v)) {
            self(self, w);
            children_product = merge(children_product, f(data[w], v, w));
        }
        data[v] = g(children_product, v);
    };

    dfs(dfs, T.get_root());
    return data;
}
