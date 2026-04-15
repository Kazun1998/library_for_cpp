#pragma once

#include "../template/template.hpp"
#include "../template/enumerable.hpp"

template<typename F>
F Lagrange_Interpolation_Point(const vector<F> &x, const vector<F> &y, F X) {
    assert(x.size() == y.size());
    int n = (int)x.size();

    // 分子の累積積を前計算 O(N)
    vector<F> pre(n + 1, F(1)), suf(n + 1, F(1));
    for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] * (X - x[i]);
    for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] * (X - x[i]);

    F Y = F(0);
    for (int i = 0; i < n; ++i) {
        // 分母の積を計算
        F den = F(1);
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            den *= (x[i] - x[j]);
        }

        Y += y[i] * pre[i] * suf[i + 1] / den;
    }

    return Y;
}

template<typename F>
F Lagrange_Interpolation_Point(const vector<pair<F, F>> &points, F X) {
    auto x = enumerable::collect(points, [](const auto &p) { return p.first; });
    auto y = enumerable::collect(points, [](const auto &p) { return p.second; });
    return Lagrange_Interpolation_Point(x, y, X);
}
