#pragma once

#include"../../template/template.hpp"
#include"Weighted_Graph.hpp"
#include"Minimum_Spanning_Tree.hpp"
#include"../../Union_Find/Union_Find.hpp"

namespace weighted_graph {
    template<typename W>
    Minimum_Spanning_Tree<W> Kruskal(const Weighted_Graph<W> &G) {
        using Edge = Weighted_Edge<W>;

        Union_Find U(G.order());
        vector<Edge> edges(G.size());
        for (int j = 0; j < G.size(); j++) {
            edges[j] = G.get_edge(j);
        }

        vector<Edge> tree_edges;
        W tree_weight = 0;

        sort(edges.begin(), edges.end(), [](const Weighted_Edge<W> &e, const Weighted_Edge<W> &f) { return e.weight < f.weight; } );
        for (Weighted_Edge<W> edge: edges) {
            if (!U.unite(edge.source, edge.target)) { continue; }

            tree_edges.emplace_back(edge);
            tree_weight += edge.weight;
        }

        return Minimum_Spanning_Tree<W> { tree_edges, tree_weight };
    }
}