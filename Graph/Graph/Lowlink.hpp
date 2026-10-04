#pragma once

#include"Graph.hpp"

namespace graph {
    class Lowlink {
        private:
        vector<bool> used;

        public:
        vector<bool> bridge, articulation;
        vector<int> ord, low;

        template<typename W>
        Lowlink(const Graph<W> &G) {
            int N = G.order(), M = G.size();
            used.assign(N, false);
            ord.assign(N, -1);
            low.assign(N, -1);

            bridge.assign(M + G.edge_id_offset, false);
            articulation.assign(N, false);

            int k = 0;
            for (int i = 0; i < N; i++) {
                unless(used[i]) { k = dfs(G, i, k, -1, -1); }
            }
        }

        private:
        template<typename W>
        int dfs(const Graph<W> &G, int v, int k, int parent, int parent_edge_id) {
            used[v] = true;
            ord[v] = k++;
            low[v] = ord[v];

            bool is_articulation = false;
            int children_number = 0;

            for (auto edge: G.incidence(v)) {
                int target = edge.target;
                if (used[target]) {
                    // 親へ来た辺そのものだけを無視する (親への多重辺は後退辺として扱う)
                    unless (edge.id == parent_edge_id) {
                        low[v] = min(low[v], ord[target]);
                    }
                    continue;
                }

                children_number++;
                k = dfs(G, target, k, v, edge.id);
                low[v] = min(low[v], low[target]);

                if (parent != -1 && ord[v] <= low[target]) { is_articulation = true; }
                if (ord[v] < low[target]) { bridge[edge.id] = true; }
            }

            if (parent == -1 && children_number >= 2) { is_articulation = true; }
            if (is_articulation) { articulation[v] = true; }

            return k;
        }
    };
}
