#pragma once

#include "../template/template.hpp"

template<typename F>
vector<F> Enumerate_Geometrics(const F a, const F r, const int n) {
    vector<F> res(n + 1);
    res[0] = a;
    for (int k = 1; k <= n; ++k) res[k] = r * res[k - 1];

    return res;
}
template<typename F>
vector<F> Enumerate_Geometrics(const F r, const int n) {
    return Enumerate_Geometrics(F(1), r, n);
}
