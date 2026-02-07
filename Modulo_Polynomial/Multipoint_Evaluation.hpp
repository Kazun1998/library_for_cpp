#pragma once

#include "Fast_Power_Series.hpp"

template<typename mint>
vector<mint> Multipoint_Evaluation(Fast_Power_Series<mint> P, const vector<mint> &Xs) {
    int m = Xs.size();
    if (m == 0) { return {}; }

    using FPS = Fast_Power_Series<mint>;

    // Subproduct Tree の構築
    // インデックス k=1 が根。
    int tree_size = 1; while (tree_size < m) { tree_size *= 2; }
    vector<FPS> g(2 * tree_size);

    auto build = [&](auto self, int l, int r, int k) -> void {
        if (r - l == 1) {
            g[k] = FPS({-Xs[l], 1});
            return;
        }
        int mid = (l + r) / 2;
        self(self, l, mid, 2 * k);
        self(self, mid, r, 2 * k + 1);
        int len = g[2 * k].size() + g[2 * k + 1].size() - 1;
        g[2 * k].precision = len;
        g[2 * k + 1].precision = len;
        g[k] = g[2 * k] * g[2 * k + 1];
    };

    build(build, 0, m, 1);

    vector<mint> Ys(m);

    auto solve = [&](auto self, int l, int r, int k, const FPS &Q) -> void {
        if (r - l == 1) {
            if (Q.size() > 0) { Ys[l] = Q[0]; }
            else { Ys[l] = 0; }
            return;
        }
        
        int mid = (l + r) / 2;
        FPS Q_l = Q % g[2 * k];
        self(self, l, mid, 2 * k, Q_l);
        
        FPS Q_r = Q % g[2 * k + 1];
        self(self, mid, r, 2 * k + 1, Q_r);
    };

    FPS Q = P % g[1];
    solve(solve, 0, m, 1, Q);

    return Ys;
}
