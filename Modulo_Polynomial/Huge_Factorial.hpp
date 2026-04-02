#pragma once

#include "../Algebra/modint.hpp"
#include "Multipoint_Evaluation.hpp"

/// @brief 階乗 N! mod P を計算する
/// @tparam mint
/// @param N
/// @return N! mod P
/// @note N >= P のときは 0 を返す.
/// @note 計算量 O(√N (log N)^2)
template<typename mint>
mint Huge_Factorial(const ll N) {
    if (N == 0) return 1;
    if (N >= mint::mod()) return 0;

    int N_sqrt = isqrt(N);

    vector<vector<mint>> A_seg(N_sqrt);
    for (int i = 1; i <= N_sqrt; ++i) {
        A_seg[i - 1] = { i, 1 };
    }

    vector<mint> points(N_sqrt);
    for (int j = 0; j < N_sqrt; ++j) { points[j] = mint(j) * mint(N_sqrt); }

    using FPS = Fast_Power_Series<mint>;
    auto calculator = Numeric_Theory_Translation<mint>();

    vector<mint> B = Multipoint_Evaluation<mint>(
        FPS(calculator.multiple_convolution(A_seg)),
        points
    );

    mint res = 1;
    for (int j = 0; j < N_sqrt; ++j) res *= B[j];

    for (ll k = N_sqrt * N_sqrt + 1; k <= N; ++k) res *= k;

    return res;
}
