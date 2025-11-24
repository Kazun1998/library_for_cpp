#pragma once

#include"Weighted_Graph.hpp"

namespace weighted_graph {
    template<typename W>
    struct Minimum_Spanning_Tree {
        vector<Weighted_Edge<W>*> edges;
        W weight;
    };
}
