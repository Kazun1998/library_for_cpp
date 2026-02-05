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
    using V = int;

    vector<X> data(T.vector_size());

    for (V v: T.bottom_up()) {
        M tmp = unit;
        for (V w: T.get_children(v)) {
            tmp = merge(tmp, f(data[w], v, w));
        }
        data[v] = g(tmp, v);
    }

    return data;
}
