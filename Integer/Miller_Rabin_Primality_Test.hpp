#pragma once

#include "../template/template.hpp"
#include "Prime.hpp"
#include "Odd_Montgomery_Multiplication.hpp"

// N が素数かどうかを判定する.
// 決定的ミラーラビン法. N (>= 0) が 2^64 未満のときに動作する.
bool Miller_Rabin_Primality_Test(uint64_t n) {
    if (n <= 1) { return false; }
    if (n == 2) { return true; }
    if (n % 2 == 0) { return false; }
    if (n % 3 == 0) { return n == 3; }
    if (n % 5 == 0) { return n == 5; }

    int s; uint64_t d;
    tie (s, d) = prime::exponents(n - 1, 2);

    Odd_Montgomery_Multiplication calculator(n);
    auto challenge = [&n, &s, &d, &calculator](uint64_t m) -> bool {
        m %= n;
        if (m == 0) return true;

        auto y = calculator.modpow(m, d);
        if (y == 1 || y == n - 1) return true;

        for (int i = 1; i < s; ++i) {
            y = calculator.mod_mul(y, y);
            if (y == n - 1) return true;
        }

        return false;
    };

    for (const uint64_t m : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        unless(challenge(m)) return false;
    }

    return true;
}