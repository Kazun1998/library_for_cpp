#pragma once

#include "../template/template.hpp"

class Topological_Sort {
    vector<vector<int>> arcs;
    bool self_loop;
    bool _is_DAG;

    public:
    Topological_Sort(int n, bool self_loop = false): arcs(n), self_loop(self_loop), _is_DAG(false) {}

    void add_arc(const int source, const int target) {
        if (source == target && !self_loop) return;

        arcs[source].emplace_back(target);
    }

    int add_vertex() {
        arcs.emplace_back(vector<int>{});

        return arcs.size() - 1;
    }

    optional<vector<int>> sort() {
        const int n = arcs.size();
        vector<int> in_deg(n, 0);

        for (int x = 0; x < n; ++x) {
            for (const int y : arcs[x]) {
                in_deg[y]++;
            }
        }

        vector<int> stack;
        for (int x = 0; x < n; ++x) {
            if (in_deg[x] == 0) stack.emplace_back(x);
        }

        vector<int> order;
        while (!stack.empty()) {
            int x = stack.back();
            stack.pop_back();
            order.emplace_back(x);

            for (const int y: arcs[x]) {
                in_deg[y]--;
                if (in_deg[y] == 0) stack.emplace_back(y);
            }
        }

        if (order.size() == n) {
            _is_DAG = true;
            return order;
        } else {
            _is_DAG = false;
            return nullopt;
        }

    }

    bool is_DAG() const { return _is_DAG; }
};