#pragma once

#include "../../template/template.hpp"
#include "../Common.hpp"

namespace digraph {
    using graph_common::Empty;

    /**
     * @brief 弧
     * @tparam W 重みの型 (重みなしの場合は Empty)
     */
    template<typename W = Empty>
    struct Arc {
        int id, source, target;
        [[no_unique_address]] W weight;

        Arc(): id(-1), source(-1), target(-1), weight() {}
        Arc(int id, int source, int target, W weight): id(id), source(source), target(target), weight(weight) {}
    };

    /**
     * @brief 有向 Graph
     * @tparam W 重みの型 (重みなしの場合は Empty)
     * @note 弧は値で保持する. add_arc を呼ぶと get_arc で得た参照は無効になる可能性がある.
     */
    template<typename W = Empty>
    class Digraph {
        public:
        using Arc_Type = Arc<W>;

        private:
        int arc_id_offset;
        vector<vector<int>> adjacent_out, adjacent_in;
        vector<Arc_Type> arcs;

        public:
        /**
         * @brief コンストラクタ
         * @param n 頂点数
         * @param arc_id_offset 弧 ID のオフセット
         */
        Digraph(int n, int arc_id_offset = 0): arc_id_offset(arc_id_offset) {
            adjacent_out.assign(n, {});
            adjacent_in.assign(n, {});
            arcs.resize(arc_id_offset);
        }

        /**
         * @brief 頂点数を取得する
         * @return int 頂点数
         */
        inline int order() const { return int(adjacent_in.size()); }

        /**
         * @brief 弧数を取得する
         * @return int 弧数
         */
        inline int size() const { return int(arcs.size()) - arc_id_offset; }

        /**
         * @brief 頂点 u から頂点 v への弧を追加する (重みなし用)
         * @return int 追加された弧の ID
         */
        int add_arc(int u, int v) requires same_as<W, Empty> { return add_arc(u, v, Empty()); }

        /**
         * @brief 頂点 u から頂点 v への重み w の弧を追加する
         * @return int 追加された弧の ID
         */
        int add_arc(int u, int v, W w) {
            int id = int(arcs.size());

            arcs.emplace_back(id, u, v, w);
            adjacent_out[u].emplace_back(id);
            adjacent_in[v].emplace_back(id);

            return id;
        }

        /**
         * @brief 頂点 u から出る弧の ID のリストを取得する
         */
        inline const vector<int>& successors(int u) const { return adjacent_out[u]; }

        /**
         * @brief 頂点 u に入る弧の ID のリストを取得する
         */
        inline const vector<int>& predecessors(int u) const { return adjacent_in[u]; }

        /**
         * @brief 弧 ID が id である弧を取得する
         */
        inline const Arc_Type& get_arc(int id) const { return arcs[id]; }
        inline Arc_Type& get_arc(int id) { return arcs[id]; }

        /**
         * @brief 頂点 v の出次数を取得する
         */
        inline int out_degree(const int v) const { return adjacent_out[v].size(); }

        /**
         * @brief 頂点 v の入次数を取得する
         */
        inline int in_degree(const int v) const { return adjacent_in[v].size(); }

        /**
         * @brief 指定された頂点集合から到達可能な頂点のリストを取得する
         * @param sources 始点の集合
         * @return vector<int> 到達可能な頂点のリスト
         */
        vector<int> forward_reachable(const vector<int> &sources) const {
            const int n = order();
            vector<bool> visited(n, false);
            vector<int> reachable;

            for (const int s : sources) {
                if (s < 0 || s >= n || visited[s]) continue;
                visited[s] = true;
                reachable.emplace_back(s);
            }

            for (int head = 0; head < reachable.size(); ++head) {
                const int u = reachable[head];
                for (const int id : adjacent_out[u]) {
                    const int v = arcs[id].target;
                    if (visited[v]) continue;

                    visited[v] = true;
                    reachable.emplace_back(v);
                }
            }

            return reachable;
        }

        /**
         * @brief 指定された頂点から到達可能な頂点のリストを取得する
         */
        vector<int> forward_reachable(const int source) const { return forward_reachable(vector<int>{source}); }

        /**
         * @brief 指定された頂点集合へ到達可能な頂点のリストを取得する
         * @param targets 終点の集合
         * @return vector<int> 到達可能な頂点のリスト
         */
        vector<int> backward_reachable(const vector<int> &targets) const {
            const int n = order();
            vector<bool> visited(n, false);
            vector<int> reachable;

            for (const int t : targets) {
                if (t < 0 || t >= n || visited[t]) continue;
                visited[t] = true;
                reachable.emplace_back(t);
            }

            for (int head = 0; head < reachable.size(); ++head) {
                const int u = reachable[head];
                for (const int id : adjacent_in[u]) {
                    const int v = arcs[id].source;
                    if (visited[v]) continue;

                    visited[v] = true;
                    reachable.emplace_back(v);
                }
            }

            return reachable;
        }

        /**
         * @brief 指定された頂点へ到達可能な頂点のリストを取得する
         */
        vector<int> backward_reachable(const int target) const { return backward_reachable(vector<int>{target}); }
    };
}
