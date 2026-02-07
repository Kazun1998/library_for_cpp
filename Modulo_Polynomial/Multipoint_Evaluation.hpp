#pragma once

#include "Fast_Power_Series.hpp"

template<typename mint>
vector<mint> Multipoint_Evaluation(Fast_Power_Series<mint> P, const vector<mint> &Xs) {
    int m = Xs.size();
    int size = 1 << ceil_log2(m);

    using FPS = Fast_Power_Series<mint>;

    vector<FPS> g(2 * size);
    for (int i = 0; i < size; ++i) {
        g[i + size] = (i < m) ? FPS({-Xs[i], 1}, m + 1) : FPS({1}, m + 1);
    }

    for (int i = size - 1; i >= 0; --i) {
        g[i] = g[2 * i] * g[2 * i + 1];
    }

    for (int i = 1; i < 2 * size; ++i) {
        g[i] = (i == 1 ? P : g[i >> 1]) % g[i];
    }

    vector<mint> Ys(m);
    for (int i = 0; i < m; ++i) Ys[i] = g[i + size][0];

    return Ys;
}
