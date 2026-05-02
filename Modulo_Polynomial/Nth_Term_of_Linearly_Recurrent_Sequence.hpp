#pragma once

#include"../Algebra/modint.hpp"
#include"Fast_Power_Series.hpp"
#include"Fraction_Coefficient.hpp"

/**
 * @brief 線形回帰数列の生成関数の分子 $P$ と分母 $Q$ を求める
 * @details 
 * $a_i = c_0 a_{i-1} + c_1 a_{i-2} + \dots + c_{d-1} a_{i-d}$ で定義される数列の母関数を $A(x) = \sum a_i x^i = P(x)/Q(x)$ とする。
 * このとき、$Q(x) = 1 - c_0 x - c_1 x^2 - \dots - c_{d-1} x^d$、
 * $P(x) = A(x)Q(x) \pmod{x^d}$ となる。
 * 
 * @tparam mint 体の要素の型
 * @param a 初項のリスト [a_0, a_1, ..., a_{d-1}]
 * @param c 漸化式の係数 [c_0, c_1, ..., c_{d-1}]
 * @return pair<Fast_Power_Series<mint>, Fast_Power_Series<mint>> {分子 P, 分母 Q}
 */
template<typename mint>
pair<Fast_Power_Series<mint>, Fast_Power_Series<mint>> Generating_Function_of_Linearly_Recurrent_Sequence(const vector<mint> &a, const vector<mint> &c) {
    using FPS = Fast_Power_Series<mint>;

    int d = a.size();
    FPS A(a, d + 1);

    vector<mint> q(d + 1);
    q[0] = 1;
    for (int i = 0; i < d; i++) q[i + 1] = -c[i];
    FPS Q(q, d + 1);

    FPS P = A * Q;
    P.resize(d);

    return {P, Q};
}

/**
 * @brief 線形回帰数列の第 n 項を求める
 * @details 
 * $a_i = c_0 a_{i-1} + c_1 a_{i-2} + \dots + c_{d-1} a_{i-d}$ で定義される線形回帰数列の第 $n$ 項を計算する。
 * 内部で Bostan-Mori 法 (Fraction_Coefficient) を使用している。
 * 
 * @tparam mint 体の要素の型 (modint等)
 * @param a 初項のリスト [a_0, a_1, ..., a_{d-1}] (d は数列の次数)
 * @param c 漸化式の係数 [c_0, c_1, ..., c_{d-1}]
 * @param n 求めたい項のインデックス (0-indexed)
 * @param offset インデックスに対するオフセット。実際の計算では n - offset 番目の項を返す。
 * @return mint 第 n 項の値
 * @note 計算量: O(d log d log n)
 */
template<typename mint>
mint Nth_Term_of_Linearly_Recurrent_Sequence(const vector<mint> &a, const vector<mint> &c, ll n, ll offset = 0) {
    using FPS = Fast_Power_Series<mint>;

    ll d = a.size();
    n -= offset;

    if (n < 0) { return 0; }
    if (n < d) { return a[n]; }

    FPS A(a, d + 1);
    vector<mint> q(d + 1);
    for (int i = 0; i < d + 1; i++) { q[i] = i ? -c[i - 1] : 1; }
    auto [P, Q] = Linearly_Recurrent_Sequence_Generating_Function(a, c);

    FPS Q(q, d + 1);
    FPS P = A * Q;
    P.poly[d] = 0;

    return Fraction_Coefficient(P, Q, n);
}
