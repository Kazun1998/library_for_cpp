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

        vector<Weight> matching_each_size() {
            return matching_vertex_duplicate_each_size(vector<int>(m, 1), vector<int>(n, 1));
        }

        tuple<Weight, vector<int>, vector<int>> matching() {
            auto [weight, X_pre, Y_pre] = matching_vertex_duplicate(vector<int>(m, 1), vector<int>(n, 1));

            vector<int> X(m, -1), Y(n, -1);
            for (int a = 0; a < m; ++a) {
                if (!X_pre[a].empty()) X[a] = X_pre[a][0];
            }

            for (int b = 0; b < n; ++b) {
                if (!Y_pre[b].empty()) Y[b] = Y_pre[b][0];
            }

            return { weight, X, Y };
        }

        vector<Weight> matching_vertex_duplicate_each_size(const vector<int> &k, const vector<int> &l) {
            auto [F, source, target] = prepare_min_cost_flow(k, l);
            return F.slope(source, target);
        }

        tuple<Weight, vector<vector<int>>, vector<vector<int>>> matching_vertex_duplicate(const vector<int> &k, const vector<int> &l) {
            auto [F, source, target] = prepare_min_cost_flow(k, l);

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

        tuple<Max_Gain_Flow<int, Weight>, int, int> prepare_min_cost_flow(const vector<int> &k, const vector<int> &l) {
            Max_Gain_Flow<int, Weight> F(m + n + 2);
            int source = m + n, target = m + n + 1;

            int flow = min(sum(k), sum(l));

            for (int a = 0; a < m; ++a) F.add_arc(source, a, k[a], 0);

            for (int b = 0; b < n; ++b) F.add_arc(b + m, target, l[b], 0);

            for (int a = 0; a < m; ++a) {
                for (auto [b, w]: edges[a]) {
                    F.add_arc(a, b + m, 1, w);
                }
            }

            return { move(F), source, target };
        }
    };
}