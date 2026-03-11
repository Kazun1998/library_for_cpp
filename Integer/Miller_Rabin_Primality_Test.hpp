#pragma once

#include "../template/template.hpp"
#include "Prime.hpp"
#include "Odd_Montgomery_Multiplication.hpp"

bool Miller_Rabin_Primality_Test(uint64_t n) {
    if (n <= 1) return false;
    if (n % 2 == 0) return n == 2; 

    int s; uint64_t d;
    tie (s, d) = prime::exponents(n - 1, 2);

    Odd_Montgomery_Multiplication calculator(n);
    auto challenge = [&n, &s, &d, &calculator](uint64_t m) -> bool {
        m %= n;
        if (m == 0) return true;

        auto y = calculator.modpow(m, d);
        if (y == 1 || y == n - 1) return true;

        rep(s) {
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