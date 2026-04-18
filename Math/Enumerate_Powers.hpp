#pragma once

#include "../template/template.hpp"
#include "../Integer/Smallest_Prime_Factor.hpp"

/**
 * @brief 0^k, 1^k, ..., n^k の列挙
 * @details 最小素因数 (SPF) を用いて、0 から n までの整数の k 乗を O(n + \pi(n) \log k) で計算する.
 * @tparam F 値の型 (modint など)
 * @param n 最大値
 * @param k 指数
 * @return vector<F> 長さ n + 1 の配列.res[i] = i^k.
 */
template<typename F>
vector<F> Enumerate_Powers(const int n, const ll k) {
    vector<F> powers(n + 1);
    powers[0] = (k == 0) ? F(1) : F(0);

    // この後, n >= 1 を仮定している部分があるため, n = 0 を例外処理
    if (n == 0) return powers;

    powers[1] = F(1);
    auto spf = prime::Smallest_Prime_Factor(n);

    for (int x = 2; x <= n; ++x) {
        int p = spf.smallest_prime_factor(x);
        if (p == x) {
            // x が素数のときはそのまま計算
            powers[x] = pow(F(x), k);
        } else {
            // x が合成数のとき, x の 2 以上 x 未満の約数の 1 つを d とすると,
            // x = d * (x / d) より, x^k = d^k * (x / d)^k である.
            // ここでは, d = p (最小素因数) としている.
            powers[x] = powers[p] * powers[x / p];
        }
    }
    return powers;
}
