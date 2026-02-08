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
    if (N == 0) { return {1}; }

    Numeric_Theory_Translation<mint> ntt;

    auto g = [&](auto self, int n) -> vector<mint> {
        if (n == 0) { return {1}; }
        if (n == 1) { return {0, 1}; }

        if (n % 2 == 1) {
            vector<mint> P = self(self, n - 1);
            vector<mint> Q = {mint(n - 1), 1};
            return ntt.convolution(P, Q);
        }

        vector<mint> P = self(self, n / 2);
        Fast_Power_Series<mint> P_fps(P);
        Fast_Power_Series<mint> Q_fps = Taylor_Shift(P_fps, mint(n / 2));
        return ntt.convolution(P, Q_fps.poly);
    };
    
    auto c = g(g, N);

    unless(sign) { return c; }

    for (int k = 0; k <= N; k++) {
        unless (k % 2 == N % 2) { c[k] *= -1; }
    }

    return c;
}