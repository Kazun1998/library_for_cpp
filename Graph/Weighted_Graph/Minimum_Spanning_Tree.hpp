#pragma once

#include"../Graph/Graph.hpp"

namespace weighted_graph {
    template<typename W>
    struct Minimum_Spanning_Tree {
        vector<graph::Edge<W>> edges;
        W weight;
    };
}
