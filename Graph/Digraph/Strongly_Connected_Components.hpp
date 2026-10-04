#pragma once

#include"Digraph.hpp"

namespace digraph {
    /// @brief 強連結成分分解 (Kosaraju 法). DFS は再帰を用いないため, 深いグラフでもスタックオーバーフローしない.
    class Strongly_Connected_Components {
        public:
        vector<vector<int>> components;
        vector<int> group;

        public:
        template<typename W>
        Strongly_Connected_Components(const Digraph<W> &D) {
            int n = D.order();

            // 帰りがけ順を求める
            vector<int> order;
            order.reserve(n);
            vector<bool> used(n, false);
            for (int s = 0; s < n; s++) {
                unless(used[s]) { dfs1(D, s, used, order); }
            }

            reverse(all(order));
            group.assign(n, -1);

            for (int v: order) {
                unless(group[v] == -1) { continue; }

                components.emplace_back(vector<int>());
                dfs2(D, v);
            }
        }

        private:
        template<typename W>
        void dfs1(const Digraph<W> &D, int start, vector<bool> &used, vector<int> &order) {
            // (頂点, 次に見る弧の位置)
            vector<pair<int, int>> stack;

            used[start] = true;
            stack.emplace_back(start, 0);

            while (!stack.empty()) {
                auto &[v, index] = stack.back();
                const auto &arcs = D.successors(v);

                if (index == int(arcs.size())) {
                    order.emplace_back(v);
                    stack.pop_back();
                    continue;
                }

                int w = D.get_arc(arcs[index++]).target;
                if (used[w]) { continue; }

                used[w] = true;
                stack.emplace_back(w, 0);
            }
        }

        template<typename W>
        void dfs2(const Digraph<W> &D, int start) {
            int component_id = int(components.size()) - 1;

            vector<pair<int, int>> stack;

            components[group[start] = component_id].emplace_back(start);
            stack.emplace_back(start, 0);

            while (!stack.empty()) {
                auto &[v, index] = stack.back();
                const auto &arcs = D.predecessors(v);

                if (index == int(arcs.size())) {
                    stack.pop_back();
                    continue;
                }

                int w = D.get_arc(arcs[index++]).source;
                if (group[w] != -1) { continue; }

                components[group[w] = component_id].emplace_back(w);
                stack.emplace_back(w, 0);
            }
        }
    };
}
