#pragma once

#include"../../template/template.hpp"
#include"Minimum_Spanning_Tree.hpp"

namespace weighted_graph {
    template<typename W>
    Minimum_Spanning_Tree<W> Prim(const graph::Graph<W> &G) {
        using Edge = graph::Edge<W>;
        if (G.order() == 0) { return { vector<Edge>(), W(0) }; }

        vector<bool> seen(G.order(), false);

        // (重み, 辺 ID, 到達先)
        using Item = tuple<W, int, int>;
        priority_queue<Item, vector<Item>, greater<Item>> Q;
        auto push_incidences = [&](int v) {
            for (const auto &edge: G.incidence(v)) {
                if (!seen[edge.target]) { Q.emplace(G.get_edge(edge.id).weight, edge.id, edge.target); }
            }
        };

        seen[0] = true;
        push_incidences(0);

        vector<Edge> tree_edges;
        W tree_weight = 0;

        while (!Q.empty()) {
            auto [w, id, t] = Q.top(); Q.pop();
            if (seen[t]) { continue; }

            seen[t] = true;
            tree_weight += w;
            tree_edges.emplace_back(G.get_edge(id));

            push_incidences(t);
        }

        return { tree_edges, tree_weight };
    }
}
