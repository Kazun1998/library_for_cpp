#pragma once

#include "../Digraph/Digraph.hpp"
#include "../Digraph/Path.hpp"

namespace weighted_digraph::warshall_floyd {
    template<typename W> struct Result;
    template<typename W> Result<W> Warshall_Floyd(const digraph::Digraph<W> &D);

    /// @brief 全点対最短路の結果
    template<typename W>
    struct Result {
        /// @brief parent_arc_ids[u][v]: u から v への最短路における v に入る弧の ID. u = v や, 意味を持たないときは -1.
        vector<vector<int>> parent_arc_ids;

        /// @brief 負閉路が存在するか.
        bool has_negative_cycle() const {
            for (int v = 0; v < int(dist.size()); ++v) {
                if (dist[v][v] < W()) { return true; }
            }
            return false;
        }

        /// @brief u から v に到達可能か.
        bool is_reachable(int u, int v) const { return reachable[u][v]; }

        /// @brief u から v への最短路長が -∞ か.
        bool is_unbounded(int u, int v) const { return unbounded[u][v]; }

        /// @brief u から v への最短路長が (-∞ ではない) 有限値として存在するか.
        bool is_finite(int u, int v) const { return is_reachable(u, v) && !is_unbounded(u, v); }

        /// @brief u から v への最短路長. is_finite(u, v) のときのみ意味を持つ.
        W distance(int u, int v) const { return dist[u][v]; }

        /// @brief start から goal への最短路を復元する.
        /// @return 最短路. goal に到達できない, または最短路長が -∞ のときは nullopt.
        optional<digraph::Path<W>> restore(const digraph::Digraph<W> &D, int start, int goal) const {
            if (!is_finite(start, goal)) { return nullopt; }

            vector<digraph::Arc<W>> arcs;
            for (int v = goal; v != start; ) {
                const auto &arc = D.get_arc(parent_arc_ids[start][v]);
                arcs.emplace_back(arc);
                v = arc.source;
            }

            reverse(arcs.begin(), arcs.end());
            return digraph::Path<W>(start, arcs);
        }

        private:
        friend Result<W> Warshall_Floyd<W>(const digraph::Digraph<W> &D);

        /// @brief reachable[u][v]: u から v に到達可能か.
        vector<vector<bool>> reachable;

        /// @brief unbounded[u][v]: u から v への最短路長が -∞ か (u から v への途中で負閉路を経由できるか).
        vector<vector<bool>> unbounded;

        /// @brief dist[u][v]: u から v への最短路長. is_finite(u, v) のときのみ意味を持つ.
        vector<vector<W>> dist;
    };

    /// @brief Warshall-Floyd 法により, 全頂点対の最短路を求める. 負の重みの弧を許す.
    /// @details 計算量は O(N^3). 負閉路があっても計算を続け, 最短路長が -∞ の組は unbounded になる.
    /// @param D 重み付き有向グラフ
    template<typename W>
    Result<W> Warshall_Floyd(const digraph::Digraph<W> &D) {
        int n = D.order();

        Result<W> result;
        result.reachable.assign(n, vector<bool>(n, false));
        result.unbounded.assign(n, vector<bool>(n, false));
        result.dist.assign(n, vector<W>(n, W()));
        result.parent_arc_ids.assign(n, vector<int>(n, -1));

        auto &reachable = result.reachable;
        auto &unbounded = result.unbounded;
        auto &dist = result.dist;
        auto &parent = result.parent_arc_ids;

        for (int v = 0; v < n; ++v) { reachable[v][v] = true; }

        for (int u = 0; u < n; ++u) {
            for (int arc_id: D.successors(u)) {
                const auto &arc = D.get_arc(arc_id);
                int v = arc.target;
                unless (!reachable[u][v] || arc.weight < dist[u][v]) { continue; }

                reachable[u][v] = true;
                dist[u][v] = arc.weight;
                parent[u][v] = arc_id;
            }
        }

        for (int k = 0; k < n; ++k) {
            // k が負閉路上にあるとき, k を経由する組の距離は発散するので更新しない (到達可能性のみ更新する).
            bool update_dist = !(dist[k][k] < W());

            for (int u = 0; u < n; ++u) {
                if (!reachable[u][k]) { continue; }

                for (int v = 0; v < n; ++v) {
                    if (!reachable[k][v]) { continue; }

                    if (!update_dist) {
                        reachable[u][v] = true;
                        continue;
                    }

                    W d = dist[u][k] + dist[k][v];
                    unless (!reachable[u][v] || d < dist[u][v]) { continue; }

                    reachable[u][v] = true;
                    dist[u][v] = d;
                    parent[u][v] = parent[k][v];
                }
            }
        }

        // 負閉路上の頂点 k を経由できる組 (u, v) は, 最短路長が -∞ である.
        for (int k = 0; k < n; ++k) {
            if (!(dist[k][k] < W())) { continue; }

            for (int u = 0; u < n; ++u) {
                if (!reachable[u][k]) { continue; }

                for (int v = 0; v < n; ++v) {
                    if (reachable[k][v]) { unbounded[u][v] = true; }
                }
            }
        }

        return result;
    }
}
