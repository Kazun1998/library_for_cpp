#pragma once

#include "../../template/template.hpp"
#include "../Common.hpp"

namespace graph {
    using graph_common::Empty;

    /**
     * @brief 無向辺
     * @tparam W 重みの型 (重みなしの場合は Empty)
     */
    template<typename W = Empty>
    struct Edge {
        int id, source, target;
        [[no_unique_address]] W weight;

        Edge(): id(-1), source(-1), target(-1), weight() {}
        Edge(int id, int source, int target, W weight): id(id), source(source), target(target), weight(weight) {}
    };

    /**
     * @brief 向きを付けた辺. 頂点 source から target へ辺 id をたどることを表す.
     * @note 重みは get_edge(id).weight で取得する.
     */
    struct Oriented_Edge {
        int id, source, target;

        Oriented_Edge(int id, int source, int target): id(id), source(source), target(target) {}
    };

    /**
     * @brief 無向 Graph
     * @tparam W 重みの型 (重みなしの場合は Empty)
     * @note 辺は値で保持する. add_edge を呼ぶと get_edge で得た参照は無効になる可能性がある.
     */
    template<typename W = Empty>
    class Graph {
        public:
        using Edge_Type = Edge<W>;

        private:
        vector<vector<Oriented_Edge>> incidences;
        vector<Edge_Type> edges;

        public:
        int edge_id_offset;

        /**
         * @brief コンストラクタ
         * @param n 位数 (頂点数)
         * @param edge_id_offset 辺 ID のオフセット
         */
        Graph(int n, int edge_id_offset = 0): incidences(n), edges(edge_id_offset), edge_id_offset(edge_id_offset) {}

        /// @brief このグラフの位数 (頂点数) を求める.
        inline int order() const { return int(incidences.size()); }

        /// @brief このグラフのサイズ (辺数) を求める.
        inline int size() const { return int(edges.size()) - edge_id_offset; }

        /// @brief 辺 uv を加える (重みなし用).
        /// @return 追加した辺の ID
        int add_edge(int u, int v) requires same_as<W, Empty> { return add_edge(u, v, Empty()); }

        /// @brief 重み w の辺 uv を加える.
        /// @return 追加した辺の ID
        int add_edge(int u, int v, W w) {
            int id = int(edges.size());

            edges.emplace_back(id, u, v, w);
            incidences[u].emplace_back(id, u, v);
            incidences[v].emplace_back(id, v, u);

            return id;
        }

        /// @brief 頂点 u に接続する辺を, u から出る向きで取得する. 自己ループは 2 回現れる.
        inline const vector<Oriented_Edge>& incidence(int u) const { return incidences[u]; }

        /// @brief 辺 ID が id である辺を取得する.
        inline const Edge_Type& get_edge(int id) const { return edges[id]; }
        inline Edge_Type& get_edge(int id) { return edges[id]; }

        /// @brief 頂点 v の次数を求める
        inline int degree(const int v) const { return int(incidences[v].size()); }

        vector<vector<int>> adjacency_matrix() const {
            vector<vector<int>> matrix(order(), vector<int>(order(), 0));
            for (int j = edge_id_offset; j < edge_id_offset + size(); ++j) {
                const Edge_Type &edge = edges[j];
                matrix[edge.source][edge.target]++;
                matrix[edge.target][edge.source]++;
            }

            return matrix;
        }

        vector<vector<int>> degree_matrix() const {
            vector<vector<int>> matrix(order(), vector<int>(order(), 0));
            for (int i = 0; i < order(); ++i) matrix[i][i] = degree(i);
            return matrix;
        }

        vector<vector<int>> laplacian_matrix() const {
            const vector<vector<int>> D = degree_matrix(), A = adjacency_matrix();
            vector<vector<int>> L(order(), vector<int>(order()));
            for (int i = 0; i < order(); ++i) {
                for (int j = 0; j < order(); ++j) {
                    L[i][j] = D[i][j] - A[i][j];
                }
            }

            return L;
        }
    };
}
