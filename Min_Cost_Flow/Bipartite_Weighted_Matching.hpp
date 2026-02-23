#pragma once

#include "Min_Cost_Flow.hpp"

namespace min_cost_flow {
    template<class Weight>
    class Bipartite_Weighted_Matching {
        public:
        Bipartite_Weighted_Matching(int m, int n): m(m), n(n), edges(m, vector<pair<int, Weight>>{}) {}

        void add_edge(int a, int b, Weight w) {
            edges[a].emplace_back(b, w);
        }

        tuple<Weight, vector<vector<int>>, vector<vector<int>>> matching_vertex_duplicate(const vector<int> &k, const vector<int> &l) {
            Max_Gain_Flow<int, Weight> F(m + n + 2);
            int source = m + n, target = m + n + 1;

            int flow = min(sum(k), sum(l));
            F.add_arc(source, target, flow, 0);

            for (int a = 0; a < m; ++a) F.add_arc(source, a, k[a], 0);

            for (int b = 0; b < n; ++b) F.add_arc(b + m, target, l[b], 0);

            for (int a = 0; a < m; ++a) {
                for (auto [b, w]: edges[a]) {
                    F.add_arc(a, b + m, 1, w);
                }
            }

            Weight gain = F.slope(source, target, -1).back();

            vector<vector<int>> X(m), Y(n);

            for (int j = 0; j < F.size(); ++j) {
                Arc<int, Weight> *arc = F.get_arc(j);
                if (arc->source == source || arc->target == target) continue;
                if (arc->is_flowable()) continue;

                int a = arc->source, b = arc->target - m;
                X[a].emplace_back(b);
                Y[b].emplace_back(a);
            }

            return { gain, X, Y };
        }

        private:
        int m, n;
        vector<vector<pair<int, Weight>>> edges;
    };
}