#pragma once

namespace weighted_graph {
    template<typename W>
    struct Weighted_Edge {
        int id, source, target;
        W weight;
        Weighted_Edge *rev;

        Weighted_Edge() = default;
        Weighted_Edge (int id, int source, int target, W weight): id(id), source(source), target(target), weight(weight) {}

        void set_reversal() {
            Weighted_Edge rev_edge = Weighted_Edge(id, target, source, weight);
            rev = &rev_edge;
            rev_edge.rev = this;
        }
    };
    
    template<typename W>
    class Weighted_Graph {
        using Edge = Weighted_Edge<W>;

        private:
        int edge_id_offset;
        vector<vector<Edge>> incidences;
        vector<Edge> edges;

        public:
        Weighted_Graph(int n, int edge_id_offset = 0): edge_id_offset(edge_id_offset), incidences(n), edges(edge_id_offset) {}
    
        inline int order() const { return int(incidences.size()); }

        inline int size() const { return int(edges.size()) - edge_id_offset; }

        // 頂点 u から頂点 v への重み w の弧を追加する.
        int add_edge(int u, int v, W w){
            int id = int(edges.size());

            Edge edge = Edge(id, u, v, w);
            edge.set_reversal();

            incidences[u].emplace_back(edge);
            incidences[v].emplace_back(*edge.rev);

            edges.emplace_back(edge);

            return id;
        }

        inline const vector<Edge>& incidence (int u) const { return incidences[u]; }

        /// @brief 辺 ID が id である辺を取得する.
        /// @param id
        inline const Edge& get_edge(int id) const { return edges[id]; }

        /// @brief 辺 ID が id である辺を取得する.
        /// @param id
        inline Edge& get_edge(int id) { return edges[id]; }
    };
}
