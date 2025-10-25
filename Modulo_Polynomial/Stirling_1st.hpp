#pragma once

#include"Fast_Power_Series.hpp"
#include"Taylor_Shift.hpp"

template<typename mint>
vector<mint> Stirling_1st(int N, bool sign = false) {
    using FPS = Fast_Power_Series<mint>;

    auto g = [&N](auto self, int n) -> FPS {
        if (n == 0) { return FPS({1}, N + 1); }
        if (n == 1) { return FPS({0, 1}, N + 1); }

        if (n % 2 == 1) { return self(self, n - 1) * FPS({n - 1, 1}, N + 1); }

        FPS P = self(self, n / 2);
        return P * Taylor_Shift(P, n / 2);
    };
    
    auto c = g(g, N).poly;

    unless(sign) { return c; }

    for (int k = 0; k <= N; k++) {
        unless (safe_mod(k, 2) == safe_mod(N, 2)) { c[k] *= -1; }
    }

    return c;
}