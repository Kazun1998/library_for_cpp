#pragma once

#include"../../template/template.hpp"

namespace digraph {
    struct Arc {
        int id, source, target;

        Arc() = default;
        Arc(int id, int source, int target): id(id), source(source), target(target) {}
    };

    class Digraph {
        private:
        int arc_id_offset;
        vector<vector<Arc*>> adjacent_out, adjacent_in;
        vector<Arc> arcs;

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
         * @brief 辺数を取得する
         * @return int 辺数
         */
        inline int size() const { return int(arcs.size()) - arc_id_offset; }

        /**
         * @brief 頂点 u から頂点 v への弧を追加する
         * @param u 始点
         * @param v 終点
         * @return Arc* 追加された弧へのポインタ
         */
        Arc* add_arc(int u, int v) {
            int id = int(arcs.size());

            Arc* arc_ptr = new Arc(id, u, v);
            arcs.emplace_back(*arc_ptr);
            
            adjacent_out[u].emplace_back(arc_ptr);
            adjacent_in[v].emplace_back(arc_ptr);

            return arc_ptr;
        }

        /**
         * @brief 頂点 u から出る弧のリストを取得する
         * @param u 頂点
         * @return const vector<Arc*>& 弧のリスト
         */
        inline const vector<Arc*>& successors(int u) const { return adjacent_out[u]; }

        /**
         * @brief 頂点 u に入る弧のリストを取得する
         * @param u 頂点
         * @return const vector<Arc*>& 弧のリスト
         */
        inline const vector<Arc*>& predecessors(int u) const { return adjacent_in[u]; }

        /**
         * @brief 指定された ID の弧を取得する
         * @param id 弧 ID
         * @return const Arc 弧
         */
        inline const Arc get_arc(int id) const { return arcs[id]; }
        inline Arc get_arc(int id) { return arcs[id]; }

        /**
         * @brief 頂点 v の出次数を取得する
         * @param v 頂点
         * @return int 出次数
         */
        inline int out_degree(const int v) const { return adjacent_out[v].size(); }

        /**
         * @brief 頂点 v の入次数を取得する
         * @param v 頂点
         * @return int 入次数
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
                for (const auto *arc : adjacent_out[u]) {
                    const int v = arc->target;
                    if (visited[v]) continue;

                    visited[v] = true;
                    reachable.emplace_back(v);
                }
            }

            return reachable;
        }

        /**
         * @brief 指定された頂点から到達可能な頂点のリストを取得する
         * @param source 始点
         * @return vector<int> 到達可能な頂点のリスト
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
                for (const auto *arc : adjacent_in[u]) {
                    const int v = arc->source;
                    if (visited[v]) continue;

                    visited[v] = true;
                    reachable.emplace_back(v);
                }
            }

            return reachable;
        }

        /**
         * @brief 指定された頂点へ到達可能な頂点のリストを取得する
         * @param target 終点
         * @return vector<int> 到達可能な頂点のリスト
         */
        vector<int> backward_reachable(const int target) const { return backward_reachable(vector<int>{target}); }
    };
}
