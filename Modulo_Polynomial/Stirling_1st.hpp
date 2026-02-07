#pragma once

#include"Fast_Power_Series.hpp"
#include"Taylor_Shift.hpp"

template<typename mint>
vector<mint> Stirling_1st(int N, bool sign = false) {
    using FPS = Fast_Power_Series<mint>;
    if (N == 0) { return {1}; }

    auto g = [](auto self, int n) -> FPS {
        if (n == 0) { return FPS({1}, 1); }
        if (n == 1) { return FPS({0, 1}, 2); }

        if (n % 2 == 1) {
            FPS P = self(self, n - 1);
            P.update_precision(n + 1);
            return P * FPS({n - 1, 1}, n + 1);
        }

        FPS P = self(self, n / 2);
        FPS Q = Taylor_Shift(P, n / 2);
        P.update_precision(n + 1);
        Q.update_precision(n + 1);
        return P * Q;
    };
    
    auto c = g(g, N).poly;

    unless(sign) { return c; }

    for (int k = 0; k <= N; k++) {
        unless (k % 2 == N % 2) { c[k] *= -1; }
    }

    return c;
}