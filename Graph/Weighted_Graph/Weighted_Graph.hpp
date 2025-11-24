#pragma once

namespace weighted_graph {
    template<typename W>
    struct Weighted_Edge {
        int id, source, target;
        W weight;
        Weighted_Edge *rev;

        Weighted_Edge() = default;
        Weighted_Edge (int id, int source, int target, W weight): id(id), source(source), target(target), weight(weight) {}
    };
    
    template<typename W>
    class Weighted_Graph {
        using Edge = Weighted_Edge<W>;

        private:
        int edge_id_offset;
        vector<vector<Edge*>> incidences;
        vector<Edge*> edges, rev_edges;

        public:
        Weighted_Graph(int n, int edge_id_offset = 0): edge_id_offset(edge_id_offset), incidences(n), edges(edge_id_offset), rev_edges(edge_id_offset) {}

        ~Weighted_Graph() {
            for (Edge* edge: edges) {
                if (edge != nullptr) { delete edge; }
            }

            for (Edge* rev_edge: rev_edges) {
                if (rev_edge != nullptr) { delete rev_edge; }
            }
        }

        inline int order() const { return int(incidences.size()); }

        inline int size() const { return int(edges.size()) - edge_id_offset; }

        // 頂点 u から頂点 v への重み w の弧を追加する.
        int add_edge(int u, int v, W w){
            int id = int(edges.size());

            Edge* edge = new Edge(id, u, v, w);
            Edge* rev_edge = new Edge(id, v, u, w);

            edge->rev = rev_edge;
            rev_edge->rev = edge;

            incidences[u].emplace_back(edge);
            incidences[v].emplace_back(rev_edge);

            edges.emplace_back(edge);
            rev_edges.emplace_back(rev_edge);

            return id;
        }

        inline const vector<Edge*>& incidence (int u) const { return incidences[u]; }

        /// @brief 辺 ID が id である辺を取得する.
        /// @param id
        inline const Edge* get_edge(int id) const { return edges[id]; }

        /// @brief 辺 ID が id である辺を取得する.
        /// @param id
        inline Edge* get_edge(int id) { return edges[id]; }
    };
}
