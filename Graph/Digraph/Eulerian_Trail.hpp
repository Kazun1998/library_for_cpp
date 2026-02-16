#pragma once

#include "Digraph.hpp"
#include "Path.hpp"

namespace digraph {
    optional<Path> Eulerian_Trail(const Digraph &D) {
        int n = D.order();
        int m = D.size();
        int start = -1, goal = -1;

        // 必要条件の判定
        for (int v = 0; v < n; ++v) {
            int r = D.out_degree(v) - D.in_degree(v);
            if (abs<int>(r) >= 2) return nullopt;

            if (r == 1) {
                if (start != -1) return nullopt;

                start = v;
            } else if (r == -1) {
                goal = v;
            }
        }

        // start, goal の決定
        if (start == -1) {
            for (int v = 0; v < n; ++v) {
                if (D.out_degree(v) > 0) {
                    start = goal = v;
                    break;
                }
            }

            if (start == -1) start = goal = 0;
        }

        vector<int> iter(n, 0);
        vector<Arc> path;
        auto dfs = [&](auto self, const int v) -> void {
            const auto &arcs = D.successors(v);
            while (iter[v] < arcs.size()) {
                const Arc* arc = arcs[iter[v]++];
                self(self, arc->target);
                path.emplace_back(*arc);
            }
        };

        dfs(dfs, start);

        // 十分性のチェック
        if (path.size() < m) return nullopt;

        reverse(path.begin(), path.end());
        return Path(start, path);
    }
}
