#pragma once

#include"../../template/template.hpp"
#include"Minimum_Spanning_Tree.hpp"

namespace weighted_graph {
    template<typename W>
    Minimum_Spanning_Tree<W> Prim(const Weighted_Graph<W> &G) {
        using Edge = Weighted_Edge<W>;
        if (G.order() == 0) { return { vector<Edge*>(), W(0) }; }

        auto compare = [](Edge *e, Edge *f) {
            return e->weight > f->weight;
        };

        priority_queue<Edge*, vector<Edge*>, decltype(compare)> Q(compare);
        for (auto edge: G.incidence(0)) {
            Q.push(edge);
        }

        vector<Edge*> tree_edges;
        W tree_weight = 0;

        vector<bool> seen(G.order(), false);
        seen[0] = true;

        while (!Q.empty()) {
            Edge *e = Q.top(); Q.pop();

            int t = e->target;
            W w = e->weight;

            if (seen[t]) { continue; }

            seen[t] = true;
            tree_weight += w;
            tree_edges.emplace_back(e);

            for (Edge* f: G.incidence(t)) {
                if (!seen[f->target]) { Q.push(f); }
            }
        }

        return { tree_edges, tree_weight };
    }
}