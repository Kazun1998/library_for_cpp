#pragma once

#include "../Graph/Graph.hpp"

// 互換用: 重み付き無向 Graph は graph::Graph<W> に統合された.
namespace weighted_graph {
    template<typename W>
    using Weighted_Edge = graph::Edge<W>;

    template<typename W>
    using Weighted_Graph = graph::Graph<W>;
}
