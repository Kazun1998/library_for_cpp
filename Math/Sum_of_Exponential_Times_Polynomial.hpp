#pragma once

#include "../template/template.hpp"
#include "../Counting/Combination_Calculator.hpp"
#include "../Math/Lagrange_Interpolation.hpp"
#include "Enumerate_Geometrics.hpp"
#include "Enumerate_Powers.hpp"

template<typename F>
F Sum_of_Exponential_Times_Polynomial(const F r, const int d, const ll n) {
    // n < 0 のときは, 自明に sum = 0;
    if (n < 0) return 0;
    // r = 0 のときは, sum = 0^d になる (n >= 0 は保証されている)
    if (r == F(0)) return d == 0 ? 1 : 0;

    vector<F> S(d + 2);
    vector<F> r_powers = Enumerate_Geometrics<F>(r, d + 2);
    {
        vector<F> powers = Enumerate_Powers<F>(d + 2, d);
        if (r == F(1)) {
            // r = 1のときは, sum = 0^d + 1^d + 2^d + ... + n^d になる.
            S[0] = powers[0];
            for (int k = 1; k <= d + 1; ++k) S[k] = S[k - 1] + powers[k];
            return Lagrange_Interpolation_Point_Arithmetic(S, F(n));
        }
        S[0] = powers[0] * r_powers[0];
        for (int k = 1; k <= d + 1; ++k) S[k] = S[k - 1] + powers[k] * r_powers[k];
    } // ここで powers が解放される

    F C;
    {
        Combination_Calculator<F> calc(d + 2);
        F P_1 = 0;
        for (int k = 0; k <= d + 1; ++k) {
            F term = calc.nCr(d + 1, k) * r_powers[k] * S[d + 1 - k];
            if (is_odd(k)) P_1 -= term; else P_1 += term;
        }
        C = P_1 / pow(1 - r, d + 1);
    } // ここで最初の calc が解放され、メモリが空く

    // S を T に書き換え (T_k = (S_k - C) / r^k)
    for (int k = 0; k <= d + 1; ++k) {
        S[k] = (S[k] - C) / r_powers[k];
    }
    vector<F>().swap(r_powers); // r_powers を完全に解放

    F T_n = Lagrange_Interpolation_Point_Arithmetic(S, F(n));
    return C + pow(r, n) * T_n;
}

template<typename F>
F Sum_of_Exponential_Times_Polynomial_Limit(const F r, const int d) {
    assert(r != F(1));

    vector<F> S(d + 2);
    Combination_Calculator<F> calc(d + 2);
    vector<F> powers = Enumerate_Powers<F>(d + 2, d);
    vector<F> r_powers = Enumerate_Geometrics<F>(r, d + 2);
    S[0] = powers[0] * r_powers[0];
    for (int k = 1; k <= d + 1; ++k) S[k] = S[k - 1] + powers[k] * r_powers[k];

    // a_n := r^n n^d として, a_n の母関数を A(x) とする.
    // このとき, A の母関数はある d 次多項式 P を使って, A(x) = P(x) / (1-rx)^(d+1) と書ける.
    // すると, (a_n) の累積和に当たる数列の母関数 S(x) は S(x) = P(x) / ((1-x)(1-rx)^(d+1)) となる.
    // よって, 部分分数分解によって, 定数 C と d 次多項式 Q によって, S(x) = C / (1-x) + Q(x) / (1-rx)^(d+1) と書ける.
    // このとき, 求めるべきは C である.
    // C = P(1) / (1-r)^(d+1) であり, P(1) は数列 S_n と (1-rx)^{d+1} の係数を畳み込むことで抽出できる.
    // 具体的には, P(1) = \sum_{k=0}^{d+1} S_{d+1-k} * [x^k](1-rx)^{d+1} である.

    F P_1 = 0; // 多項式 P(x) の x=1 における値
    for (int k = 0; k <= d + 1; ++k) {
        F term = calc.nCr(d + 1, k) * r_powers[k] * S[d + 1 - k]; // |[x^k](1-rx)^{d+1}| * S_{d+1-k}
        is_even(k) ? P_1 += term : P_1 -= term;
    }

    return P_1 / pow(1 - r, d + 1);
}
