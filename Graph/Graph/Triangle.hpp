#pragma once

#include"Graph.hpp"

namespace graph {
    template<typename X>
    X Triangle(const Graph &G, const function<X(int, int, int)> &calc, const function<X(X, X)> &merge, const X unit) {
        int N = G.order();
        vector<vector<int>> A(N);

        for (int u = 0; u < N; u++) {
            for (auto edge: G.incidence(u)) {
                int v = edge->target;
                if (G.degree(u) > G.degree(v) || (G.degree(u) == G.degree(v) && u > v)) {
                    A[u].emplace_back(v);
                }
            }
        }

        X res(unit);
        vector<bool> used(N, false);

        for (int u = 0; u < N; u++) {
            for (int w: A[u]) { used[w] = true; }

            for (int v: A[u]) {
                for (int w: A[v]) {
                    if (used[w]) { res = merge(res, calc(u, v, w)); }
                }
            }

            for (int w: A[u]) { used[w] = false; }
        }

        return res;
    }
}
