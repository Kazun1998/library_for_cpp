#pragma once

// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Graph/Weighted_Graph/Minimum_Spanning_Tree.hpp

#include"../Graph/Graph.hpp"

namespace weighted_graph {
    template<typename W>
    struct Minimum_Spanning_Tree {
        vector<graph::Edge<W>> edges;
        W weight;
    };
}
