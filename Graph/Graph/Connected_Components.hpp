#pragma once

#include"Graph.hpp"

namespace graph {
    class Connected_Components {
        public:
        vector<vector<int>> components;
        vector<int> component_ids;

        Connected_Components(const Graph &G) {
            components.clear();
            component_ids.assign(G.order(), -1);

            for (int x = 0; x < G.order(); x++) {
                unless(component_ids[x] == -1) { continue; }
                dfs(G, x);
            }
        };

        private:
        void dfs(const Graph &G, int start) {
            int component_id = components.size();

            components.emplace_back();
            component_ids[start] = component_id;

            stack<int> st;
            st.emplace(start);
            components[component_id].emplace_back(start);

            while(!st.empty()) {
                int x = st.top(); st.pop();
                for (auto edge: G.incidence(x)) {
                    int y = edge->target;
                    unless (component_ids[y] == -1) { continue; }

                    component_ids[y] = component_id;
                    components[component_id].emplace_back(y);
                    st.emplace(y);
                }
            }
        }
    };

    bool is_Connected(const Graph &G) {
        auto connected_components = Connected_Components(G);
        return connected_components.components.size() == 1;
    }
}
