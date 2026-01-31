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

    int add_arc_multiple(const vector<int> sources, const vector<int> targets) {
        const int x = add_vertex();

        for (const int s: sources) add_arc(s, x);
        for (const int t: targets) add_arc(x, t);

        return x;
    }

    int add_vertex() {
        arcs.emplace_back(vector<int>{});

        return arcs.size() - 1;
    }

    optional<vector<int>> sort() const {
        const int n = arcs.size();
        vector<bool> marked(n, false), use(n, false);
        vector<int> order;

        auto visit = [&](auto func, const int x) -> bool {
            if (use[x]) return false;
            if (marked[x]) return true;

            use[x] = true;
            for (const int &y : arcs[x]) {
                if (!func(func, y)) return false;
            }

            marked[x] = true;
            order.push_back(x);
            use[x] = false;
            return true;
        };

        for (int x = 0; x < n; ++x) {
            if (!visit(visit, x)) return nullopt;
        }

        reverse(order.begin(), order.end());
        return order;
    }

    bool is_DAG() const { return sort() != nullopt; }
};