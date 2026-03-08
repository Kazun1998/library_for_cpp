#pragma once

#include "../template/template.hpp"
#include "Prime.hpp"
#include "Odd_Montgomery_Multiplication.hpp"

// N が素数かどうかを判定する.
// 決定的ミラーラビン法. N (>= 0) が 2^64 未満のときに動作する.
bool Miller_Rabin_Primality_Test(ll N) {
    if (N <= 1) { return false; }
    if (N == 2) { return true; }
    if (N % 2 == 0) { return false; }

    ll q; int k;
    tie (k, q) = prime::exponents(N - 1, 2);

    // N < 2^64 の範囲では, 以下の 12 個の基底で十分.
    // 参考文献: J. Sorenson and J. Webster, "Strong Pseudoprimes to Twelve Prime Bases", 
    // Mathematics of Computation 86(304): 985-1003, 2017.
    // https://arxiv.org/abs/1509.00864
    const vector<ll> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    Odd_Montgomery_Multiplication calculator(N);

    for (ll m : bases) {
        if (N <= m) { break; }

        auto y = calculator.modpow(m, q);

        if (y == 1 || y == N - 1) { continue; }

        bool is_composite = true;
        for (int i = 1; i < k; ++i) {
            y = calculator.mod_mul(y, y);
            if (y == N - 1) {
                is_composite = false;
                break;
            }
        }

        if (is_composite) { return false; }
    }

    return true;
}