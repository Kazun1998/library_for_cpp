#pragma once

#include"../../template/template.hpp"
#include"../Graph/Graph.hpp"
#include"Minimum_Spanning_Tree.hpp"
#include"../../Union_Find/Union_Find.hpp"

namespace weighted_graph {
    template<typename W>
    Minimum_Spanning_Tree<W> Kruskal(const graph::Graph<W> &G) {
        using Edge = graph::Edge<W>;

        Union_Find U(G.order());
        vector<Edge> edges;
        for (int id = G.edge_id_offset; id < G.edge_id_offset + G.size(); ++id) {
            edges.emplace_back(G.get_edge(id));
        }

        vector<Edge> tree_edges;
        W tree_weight = 0;

        sort(edges.begin(), edges.end(), [](const Edge &e, const Edge &f) { return e.weight < f.weight; } );

        for (const auto &edge: edges) {
            if (!U.unite(edge.source, edge.target)) { continue; }

            tree_edges.emplace_back(edge);
            tree_weight += edge.weight;
        }

        return Minimum_Spanning_Tree<W> { tree_edges, tree_weight };
    }
}
