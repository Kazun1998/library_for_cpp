#pragma once

#include "Tree.hpp"

template<typename X>
vector<X> Tree_DP_from_Root(Tree &T, function<X(X, int, int)> f, const X alpha) {
    vector<X> data(T.vector_size());

    data[T.get_root()] = alpha;

    for (int x: T.top_down()) {
        for (int y: T.get_children(x)) {
            data[y] = f(data[x], x, y);
        }
    }

    return data;
}
