#pragma once

#include "../template/template.hpp"
#include "Prime.hpp"
#include "Odd_Montgomery_Multiplication.hpp"

/// @brief ミラー・ラビン素数判定法により、与えられた整数が素数かどうかを判定する。
/// @param n 判定対象の整数 (n <= 2^64 - 1)
/// @return n が素数であれば true、そうでなければ false を返す。
/// @note 2^64 未満の整数に対しては決定的な判定を行う。
/// @see https://miller-rabin.appspot.com/
bool Miller_Rabin_Primality_Test(uint64_t n) {
    if (n <= 1) return false;
    if (n % 2 == 0) return n == 2; 

    int s; uint64_t d;
    tie (s, d) = prime::exponents(n - 1, 2);

    Odd_Montgomery_Multiplication calculator(n);
    auto challenge = [&n, &s, &d, &calculator](uint64_t a) -> bool {
        a %= n;
        if (a == 0) return true;

        auto y = calculator.modpow(a, d);
        if (y == 1 || y == n - 1) return true;

        rep(s) {
            y = calculator.mod_mul(y, y);
            if (y == n - 1) return true;
        }

        return false;
    };

    for (const uint64_t a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        unless(challenge(a)) return false;
    }

    return true;
}