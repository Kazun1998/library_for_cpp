#pragma once

#include "../template/template.hpp"

template<typename FUNC>
vector<int> Monotone_Minima(const int n, const int m, const FUNC eval) {
    vector<int> res(n);

    auto solve = [&](auto self, int u, int d, int l, int r) -> void {
        if (u >= d) return;

        int mid = (u + d) / 2;
        int best_j = l;
        for (int j = l + 1; j < r; ++j) {
            if (eval(mid, j) < eval(mid, best_j)) {
                best_j = j;
            }
        }
        res[mid] = best_j;

        self(self, u, mid, l, best_j + 1);
        self(self, mid + 1, d, best_j, r);
    };

    solve(solve, 0, n, 0, m);
    return res;
}