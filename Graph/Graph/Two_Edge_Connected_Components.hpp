#pragma once

#include"Lowlink.hpp"

namespace graph {
    class Two_Edge_Connected_Components {
        public:
        vector<vector<int>> components;
        vector<int> component_ids;

        Two_Edge_Connected_Components(const Graph &G) {
            calculate(G);
        }

        private:
        vector<bool> bridges;
        void calculate(const Graph &G) {
            bridges = Lowlink(G).bridge;

            components.clear();
            component_ids.assign(G.order(), -1);

            for (int x = 0; x < G.order(); x++) {
                unless(component_ids[x] == -1) { continue; }
                dfs(G, x);
            }
        }

        void dfs(const Graph &G, int start) {
            int component_id = components.size();

            components.emplace_back();
            component_ids[start] = component_id;

            stack<int> st;
            st.emplace(start);
            components[component_id].emplace_back(start);

            while(!st.empty()) {
                int x = st.top(); st.pop();
                for (auto [edge_id, y]: G.incidence(x)) {
                    if (bridges[edge_id]) { continue; }
                    unless (component_ids[y] == -1) { continue; }

                    component_ids[y] = component_id;
                    components[component_id].emplace_back(y);
                    st.emplace(y);
                }
            }
        }
    };
}
