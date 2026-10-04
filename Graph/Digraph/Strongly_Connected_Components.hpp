#pragma once

#include"Digraph.hpp"

namespace digraph {
    class Strongly_Connected_Components {
        public:
        vector<vector<int>> components;
        vector<int> group;

        private:
        vector<int> order;
        vector<bool> used;

        public:
        template<typename W>
        Strongly_Connected_Components(const Digraph<W> &D) {
            int n = D.order();

            used.assign(n, false);

            for (int i = 0; i < n; i++) {
                unless(used[i]) { dfs1(D, i); }
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
        void dfs1(const Digraph<W> &D, int v) {
            used[v] = true;
            for (int id: D.successors(v)) {
                int w = D.get_arc(id).target;

                unless(used[w]) { dfs1(D, w); }
            }

            order.emplace_back(v);
        }

        template<typename W>
        void dfs2(const Digraph<W> &D, int v) {
            components[group[v] = components.size() - 1].emplace_back(v);

            for (int id: D.predecessors(v)) {
                int w = D.get_arc(id).source;
                if (group[w] == -1) { dfs2(D, w); }
            }
        }
    };
}
