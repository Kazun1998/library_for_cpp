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

        private:
        int m, n;
        vector<vector<pair<int, Weight>>> edges;
    };
}