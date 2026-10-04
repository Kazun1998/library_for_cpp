#pragma once

#include"Graph.hpp"

namespace graph {
    /// @brief Lowlink (橋・関節点の検出). DFS は再帰を用いないため, 深いグラフでもスタックオーバーフローしない.
    class Lowlink {
        public:
        vector<bool> bridge, articulation;
        vector<int> ord, low;

        template<typename W>
        Lowlink(const Graph<W> &G) {
            int N = G.order(), M = G.size();
            ord.assign(N, -1);
            low.assign(N, -1);

            bridge.assign(M + G.edge_id_offset, false);
            articulation.assign(N, false);

            vector<int> parent(N, -1), parent_edge_id(N, -1), children_number(N, 0);

            int k = 0;
            // (頂点, 次に見る辺の位置)
            vector<pair<int, int>> stack;

            auto visit = [&](int v) -> void {
                ord[v] = low[v] = k++;
                stack.emplace_back(v, 0);
            };

            for (int s = 0; s < N; s++) {
                if (ord[s] != -1) { continue; }

                visit(s);
                while (!stack.empty()) {
                    int v = stack.back().first;
                    const auto &edges = G.incidence(v);

                    // v の辺を見終わった: 親に結果を伝える
                    if (stack.back().second == int(edges.size())) {
                        stack.pop_back();

                        int p = parent[v];
                        if (p == -1) {
                            if (children_number[v] >= 2) { articulation[v] = true; }
                            continue;
                        }

                        low[p] = min(low[p], low[v]);
                        if (parent[p] != -1 && ord[p] <= low[v]) { articulation[p] = true; }
                        if (ord[p] < low[v]) { bridge[parent_edge_id[v]] = true; }
                        continue;
                    }

                    const auto &edge = edges[stack.back().second++];
                    int target = edge.target;
                    if (ord[target] != -1) {
                        // 親へ来た辺そのものだけを無視する (親への多重辺は後退辺として扱う)
                        if (edge.id != parent_edge_id[v]) { low[v] = min(low[v], ord[target]); }
                        continue;
                    }

                    children_number[v]++;
                    parent[target] = v;
                    parent_edge_id[target] = edge.id;
                    visit(target);
                }
            }
        }
    };
}
