#pragma once

#include"Fast_Power_Series.hpp"
#include"Taylor_Shift.hpp"

/// @brief 第 I 種スターリング数 (Stirling numbers of the first kind) を計算する
/// @tparam mint
/// @param N 
/// @param sign 符号の有無. false の場合は符号なし (上昇階乗冪の係数), true の場合は符号あり (下降階乗冪の係数)
/// @return 長さ N + 1 の vector. i 番目の要素は S_1(N, i)
/// @note 計算量 O(N log N)
template<typename mint>
vector<mint> Stirling_1st(int N, bool sign = false) {
    using FPS = Fast_Power_Series<mint>;
    if (N == 0) { return {1}; }

    auto g = [](auto self, int n) -> FPS {
        if (n == 0) { return FPS({1}); }
        if (n == 1) { return FPS({0, 1}); }

        if (n % 2 == 1) {
            FPS P = self(self, n - 1);
            return P.mul_poly(FPS({mint(n - 1), 1}));
        }

        FPS P = self(self, n / 2);
        FPS Q = Taylor_Shift(P, n / 2);
        return P.mul_poly(Q);
    };
    
    auto c = g(g, N).poly;

    unless(sign) { return c; }

    for (int k = 0; k <= N; k++) {
        unless (k % 2 == N % 2) { c[k] *= -1; }
    }

    return c;
}