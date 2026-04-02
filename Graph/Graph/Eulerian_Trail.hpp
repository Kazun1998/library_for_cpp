#pragma once

#include "Graph.hpp"
#include "Path.hpp"

namespace graph {
    optional<Path> Eulerian_Trail(const Graph &G) {
        int n = G.order();
        int m = G.size();
        int start = -1, goal = -1;

        // 必要条件の判定
        for (int v = 0; v < n; ++v) {
            if (G.degree(v) % 2 == 1) {
                if (start == -1) start = v;
                else if (goal == -1) goal = v;
                else return nullopt;
            }
        }

        // start, goal の決定
        if (start == -1) {
            for (int v = 0; v < n; ++v) {
                if (G.degree(v) > 0) {
                    start = goal = v;
                    break;
                }
            }

            if (start == -1) start = goal = 0;
        }

        vector<int> iter(n, 0);
        vector<bool> saw_edge_ids(m + G.edge_id_offset, false);
        vector<Edge> path;

        auto dfs = [&](auto self, const int v) -> void {
            const auto &edges = G.incidence(v);
            while (iter[v] < edges.size()) {
                const Edge* edge = edges[iter[v]++];
                if (saw_edge_ids[edge->id]) { continue; }
                saw_edge_ids[edge->id] = true;
                self(self, edge->target);
                path.emplace_back(*edge);
            }
        };

        dfs(dfs, start);

        // 十分性のチェック
        if (path.size() < m) return nullopt;

        reverse(path.begin(), path.end());
        return Path(start, path);
    }
}
