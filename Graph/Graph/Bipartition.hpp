#pragma once

#include "../../template/template.hpp"
#include "Graph.hpp"

namespace graph {
    optional<vector<pair<vector<int>, vector<int>>>> Biparte(const Graph &G) {
        int n = G.order();
        vector<int> colors(n, -1);

        vector<pair<vector<int>, vector<int>>> groups;
        for (int x = 0; x < n; ++x) {
            if (colors[x] != -1) continue;

            vector<int> stack{x};
            vector<int> white{x}, black;

            colors[x] = 0;
            while (!stack.empty()) {
                int v = stack.back(); stack.pop_back();

                for (auto edge: G.incidence(v)) {
                int u = edge->target;
                if (colors[u] != -1) {
                    if (colors[u] ^ 1 != colors[v]) return nullopt;
                    continue;
                }

                colors[u] = colors[v] ^ 1;
                (colors[u] == 0 ? white : black).emplace_back(u);
                stack.emplace_back(u);
                }
            }

            groups.emplace_back(white, black);
        }

        return groups;
    }
}
