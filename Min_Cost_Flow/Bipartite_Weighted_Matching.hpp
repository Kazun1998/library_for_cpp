#pragma once

#include "Min_Cost_Flow.hpp"

namespace min_cost_flow {
    template<class Weight>
    class Bipartite_Weighted_Matching {
        public:
        Bipartite_Weighted_Matching(int m, int n): m(m), n(n) {}

        private:
        int m, n;
    };
}