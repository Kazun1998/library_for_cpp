#pragma once

#include "../template/template.hpp"
#include "Tree.hpp"

class Lowest_Common_Ancestor {
    private:
    const Tree &T;
    int N_bit;
    vector<vector<int>> upper_list;

    public:
    Lowest_Common_Ancestor(const Tree &tree) : T(tree) {
        assert(T.is_locked());
        int N = T.order();
        int offset = T.offset();

        N_bit = 0;
        while ((1 << N_bit) <= N) { N_bit++; }

        upper_list.assign(N_bit, vector<int>(N + offset, -1));

        for (int i = offset; i < N + offset; i++) {
            if (T.is_root(i)) {
                upper_list[0][i] = i;
            } else {
                upper_list[0][i] = T.get_parent(i);
            }
        }

        for (int k = 1; k < N_bit; k++) {
            for (int i = offset; i < N + offset; i++) {
                upper_list[k][i] = upper_list[k - 1][upper_list[k - 1][i]];
            }
        }
    }

    // 頂点 x から見て k 代前の頂点を求める.
    int upper(int x, int k, bool over = true) const {
        if (T.vertex_depth(x) < k) { return over ? T.get_root() : -1; }

        for (int b = 0; k; k >>= 1, b++) {
            if (k & 1) { x = upper_list[b][x]; }
        }

        return x;
    }

    // 頂点 x と頂点 y の最小共通先祖を求める.
    int lowest_common_ancestor(int x, int y) const {
        if (T.vertex_depth(x) > T.vertex_depth(y)) { swap(x, y); }
        y = upper(y, T.vertex_depth(y) - T.vertex_depth(x));

        if (T.is_root(x) || x == y) { return x; }

        for (int k = N_bit - 1; k >= 0; k--) {
            int px = upper_list[k][x], py = upper_list[k][y];
            if (px != py) { x = px, y = py; }
        }

        return T.is_root(x) ? T.get_root() : T.get_parent(x);
    }

    // 2 頂点 x, y 間の距離を求める.
    int distance(int x, int y) const {
        return T.vertex_depth(x) + T.vertex_depth(y) - 2 * T.vertex_depth(lowest_common_ancestor(x, y));
    }

    // 頂点 u から頂点 v へ向かうパスにおいて k 番目 (0-indexed) に通る頂点を求める.
    int jump(int u, int v, int k, int over = -1) const {
        if (k == 0) { return u; }

        int w = lowest_common_ancestor(u, v);
        int dist_uw = T.vertex_depth(u) - T.vertex_depth(w);
        int dist_wv = T.vertex_depth(v) - T.vertex_depth(w);
        int dist_uv = dist_uw + dist_wv;

        if (dist_uv < k) { return over; }
        return (k <= dist_uw) ? upper(u, k) : upper(v, dist_uv - k);
    }
};