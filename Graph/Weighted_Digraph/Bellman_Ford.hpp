#pragma once

#include "../Digraph/Digraph.hpp"
#include "../Digraph/Path.hpp"

namespace weighted_digraph::bellman_ford {
    /// @brief 始点からの最短路の結果
    template<typename W>
    struct Result {
        int start;

        /// @brief reachable[v]: 始点から v に到達可能か.
        vector<bool> reachable;

        /// @brief unbounded[v]: 始点から v への最短路長が -∞ か (始点から到達可能な負閉路を経由して v に到達できるか).
        vector<bool> unbounded;

        /// @brief dist[v]: 始点から v への最短路長. reachable[v] かつ !unbounded[v] のときのみ意味を持つ.
        vector<W> dist;

        /// @brief parent_arc_ids[v]: 始点から v への最短路における v に入る弧の ID. 始点と, 意味を持たない頂点では -1.
        vector<int> parent_arc_ids;

        /// @brief 始点から到達可能な負閉路が存在するか.
        bool has_negative_cycle() const {
            return find(unbounded.begin(), unbounded.end(), true) != unbounded.end();
        }

        /// @brief 始点から goal への最短路長が (-∞ ではない) 有限値として存在するか.
        bool is_finite(int goal) const { return reachable[goal] && !unbounded[goal]; }

        /// @brief 始点から goal への最短路を復元する.
        /// @return 最短路. goal に到達できない, または最短路長が -∞ のときは nullopt.
        optional<digraph::Path<W>> restore(const digraph::Digraph<W> &D, int goal) const {
            if (!is_finite(goal)) { return nullopt; }

            vector<digraph::Arc<W>> arcs;
            for (int v = goal; v != start; ) {
                const auto &arc = D.get_arc(parent_arc_ids[v]);
                arcs.emplace_back(arc);
                v = arc.source;
            }

            reverse(arcs.begin(), arcs.end());
            return digraph::Path<W>(start, arcs);
        }
    };

    /// @brief Bellman-Ford 法により, 始点から全頂点への最短路を求める. 負の重みの弧を許す.
    /// @details 計算量は O(NM). 始点から到達可能な負閉路がある場合は, その負閉路から到達できる頂点が unbounded になる.
    /// @param D 重み付き有向グラフ
    /// @param start 始点
    template<typename W>
    Result<W> Bellman_Ford(const digraph::Digraph<W> &D, int start) {
        int n = D.order();

        Result<W> result;
        result.start = start;
        result.reachable.assign(n, false);
        result.unbounded.assign(n, false);
        result.dist.assign(n, W());
        result.parent_arc_ids.assign(n, -1);

        auto &reachable = result.reachable;
        auto &dist = result.dist;
        auto &parent = result.parent_arc_ids;

        reachable[start] = true;

        // 全ての弧を 1 回緩和する. 更新された頂点を updated に追加する.
        vector<int> updated;
        auto relax_all = [&]() -> void {
            updated.clear();
            for (int u = 0; u < n; ++u) {
                if (!reachable[u]) { continue; }

                for (int arc_id: D.successors(u)) {
                    const auto &arc = D.get_arc(arc_id);
                    int v = arc.target;
                    W d = dist[u] + arc.weight;
                    unless (!reachable[v] || d < dist[v]) { continue; }

                    reachable[v] = true;
                    dist[v] = d;
                    parent[v] = arc_id;
                    updated.emplace_back(v);
                }
            }
        };

        // 負閉路がなければ, n - 1 回の緩和で収束する.
        for (int i = 0; i < n - 1; ++i) {
            relax_all();
            if (updated.empty()) { return result; }
        }

        // n 回目の緩和でも更新される頂点は, 負閉路上か, 負閉路から到達できる頂点である.
        relax_all();
        if (updated.empty()) { return result; }

        // それらから到達できる頂点は全て, 最短路長が -∞ である.
        auto &unbounded = result.unbounded;
        vector<int> queue;
        for (int v: updated) {
            if (unbounded[v]) { continue; }

            unbounded[v] = true;
            queue.emplace_back(v);
        }

        for (int head = 0; head < int(queue.size()); ++head) {
            for (int id: D.successors(queue[head])) {
                int w = D.get_arc(id).target;
                if (unbounded[w]) { continue; }

                unbounded[w] = true;
                queue.emplace_back(w);
            }
        }

        return result;
    }
}
