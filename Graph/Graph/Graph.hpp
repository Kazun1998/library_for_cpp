#pragma once

#include"../../template/template.hpp"

namespace graph {
    struct Edge {
        int id, u, v;

        Edge() = default;
        Edge(int id, int u, int v): id(id), u(u), v(v) {}
    };

    class Graph {
        private:
        int edge_id_offset;
        vector<vector<pair<int, int>>> incidences; // { edge_id, neighbor_vertex }
        vector<Edge> edges;

        public:
        Graph(int n, int edge_id_offset = 0): edge_id_offset(edge_id_offset) {
            incidences.assign(n, {});
            edges.resize(edge_id_offset, Edge());
        }
        
        inline int order() const { return int(incidences.size()); }

        inline int size() const { return int(edges.size()) - edge_id_offset; }

        // 頂点 u から頂点 v への辺を追加する.
        int add_edge(int u, int v) {
            int id = int(edges.size());

            incidences[u].emplace_back(id, v);
            incidences[v].emplace_back(id, u);
            edges.emplace_back(Edge(id, u, v));

            return id;
        }

        // 頂点 u に接続する辺 ID と隣接頂点 v のペア { ID, v } のリストを取得
        inline const vector<pair<int, int>>& incidence (int u) const { return incidences[u]; }

        // 辺 ID が id であり, source が u である辺を取得する.
        inline const Edge& get_edge(int id) const { return edges[id]; }

        // 辺 ID が id であり, source が u である辺を取得する.
        inline Edge& get_edge(int id) { return edges[id]; }
    };
}
