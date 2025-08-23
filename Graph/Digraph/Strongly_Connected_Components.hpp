#include"Digraph.hpp"

namespace Digraph {
    class Strongly_Connected_Components {
        public:
        vector<vector<int>> components;
        vector<int> group;

        private:
        vector<int> order;
        vector<bool> used;

        public:
        Strongly_Connected_Components(const Digraph &D) {
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
        void dfs1(const Digraph &D, int v) {
            used[v] = true;
            for (auto arc_id: D.successors(v)) {
                auto arc = D.get_arc(arc_id);
                int w = arc.target;

                unless(used[w]) { dfs1(D, w); }
            }

            order.emplace_back(v);
        }

        void dfs2(const Digraph &D, int v) {
            components[group[v] = components.size() - 1].emplace_back(v);

            for (auto arc_id: D.predecessors(v)) {
                auto arc = D.get_arc(arc_id);
                int w = arc.source;
                if (group[w] == -1) { dfs2(D, w); }
            }
        }
    };
}
