#pragma once

#include"../../template/template.hpp"

namespace graph {
    struct Edge {
        int id, source, target;
        Edge *rev;

        Edge() = default;
        Edge(int id, int source, int target): id(id), source(source), target(target), rev(nullptr) {}
    };

    class Graph {
        private:
        vector<vector<Edge*>> incidences;
        vector<Edge> edges, rev_edges;
        vector<int> deg;

        public:
        int edge_id_offset;

        public:
        Graph(int n, int edge_id_offset = 0): edge_id_offset(edge_id_offset), deg(n, 0) {
            incidences.assign(n, {});
            edges.resize(edge_id_offset, Edge());
        }
        
        inline int order() const { return int(incidences.size()); }

        inline int size() const { return int(edges.size()) - edge_id_offset; }

        // 頂点 u から頂点 v への辺を追加する.
        int add_edge(int u, int v) {
            int id = int(edges.size());

            Edge* edge = new Edge(id, u, v);
            Edge* rev_edge = new Edge(id, v, u);

            edge->rev = rev_edge;
            rev_edge->rev = edge;

            incidences[u].emplace_back(edge);
            incidences[v].emplace_back(rev_edge);
            edges.emplace_back(*edge);

            deg[u]++;
            deg[v]++;

            return id;
        }

        vector<Edge*> incidence (int u) const { return incidences[u]; }

        // 辺 ID が id であり, source が u である辺を取得する.
        inline const Edge& get_edge(int id) const { return edges[id]; }

        // 辺 ID が id であり, source が u である辺を取得する.
        inline Edge& get_edge(int id) { return edges[id]; }

        /// @brief 頂点 v の次数を求める
        inline int degree(const int v) const { return deg[v]; }
    };
}
