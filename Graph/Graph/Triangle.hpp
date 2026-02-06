#pragma once

#include"Graph.hpp"

namespace graph {
    vector<tuple<int, int, int>> Triangle(const Graph &G) {
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

        vector<bool> used(N, false);
        vector<tuple<int, int, int>> triangles;
        for (int u = 0; u < N; u++) {
            for (int w: A[u]) { used[w] = true; }

            for (int v: A[u]) {
                for (int w: A[v]) {
                    if (used[w]) triangles.emplace_back(u, v, w);
                }
            }

            for (int w: A[u]) { used[w] = false; }
        }

        return triangles;
    }
}
