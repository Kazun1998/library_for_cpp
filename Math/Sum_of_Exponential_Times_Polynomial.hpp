#pragma once

#include "../template/template.hpp"
#include "../Counting/Combination_Calculator.hpp"
#include "Enumerate_Geometrics.hpp"
#include "Enumerate_Powers.hpp"

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
