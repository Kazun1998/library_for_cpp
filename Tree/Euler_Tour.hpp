#pragma once

#include "../template/template.hpp"
#include "Tree.hpp"

class Euler_Tour {
    private:
    const Tree &T;

    bool has_euler_tour_vertex = false, has_euler_tour_edge = false;

    public:
    vector<int> in_time, out_time;
    vector<int> euler_tour_vertex;
    vector<tuple<int, int, int>> euler_tour_edge;

    Euler_Tour(const Tree &T): T(T) {
        assert(T.is_locked());
    }

    // Euler Tour (頂点) に関する計算を行う.
    void calculate_euler_tour_vertex() {
        if (has_euler_tour_vertex) { return; }

        euler_tour_vertex.clear();
        in_time.assign(T.vector_size(), -1);
        out_time.assign(T.vector_size(), -1);

        auto dfs = [&](auto self, int x) -> void {
            in_time[x] = (int)euler_tour_vertex.size();
            euler_tour_vertex.emplace_back(x);

            for (int y: T.get_children(x)) {
                self(self, y);
            }

            out_time[x] = (int)euler_tour_vertex.size() - 1;
            unless(T.is_root(x)) { euler_tour_vertex.emplace_back(T.get_parent(x)); }
        };

        dfs(dfs, T.get_root());

        has_euler_tour_vertex = true;
    }

    // Euler Tour (辺) に関する計算を行う.
    void calculate_euler_tour_edge() {
        if (has_euler_tour_edge) { return; }

        calculate_euler_tour_vertex();
        euler_tour_edge.clear();

        for (int t = 0; t < 2 * (T.order() - 1); t++) {
            int x = euler_tour_vertex[t], y = euler_tour_vertex[t + 1];
            int k = (x == T.get_parent(y)) ? 1 : -1;
            euler_tour_edge.emplace_back(make_tuple(x, y, k));
        }

        has_euler_tour_edge = true;
    }

    // 頂点 x の部分木が, オイラーツアー列上で対応する区間 [in_time[x], out_time[x]] を返す.
    pair<int, int> subtree_range(const int &x) {
        calculate_euler_tour_vertex();
        return make_pair(in_time[x], out_time[x]);
    }

    // x は y の祖先 (自分自身も含む) か?
    bool is_ancestor(const int &x, const int &y) {
        calculate_euler_tour_vertex();
        return in_time[x] <= in_time[y] && out_time[y] <= out_time[x];
    }
};
