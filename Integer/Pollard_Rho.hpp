#pragma once

#include "../template/template.hpp"
#include "Prime.hpp"
#include "Odd_Montgomery_Multiplication.hpp"
#include "Miller_Rabin_Primality_Test.hpp"

uint64_t Find_Prime_Factor_by_Pollard_Rho(uint64_t n) {
    if (n == 1) return 1;
    if (n % 2 == 0) return 2;

    uint64_t m = 1 << (bit_length(m) / 8 + 1);
    Odd_Montgomery_Multiplication calc(n);

    for (uint64_t c = 1; c < 99; ++c) {
        auto f = [&calc, &n, &c](const uint64_t x) -> uint64_t {
            uint64_t y = calc.mod_mul(x, x);
            uint64_t z = y + c;
            return z < n ? z : z - n;
        };
        
        uint64_t x = 0, y = 0;
        uint64_t g = 1;
        while (g == 1) {
            x = f(x);
            y = f(f(y));

            uint64_t diff = x < y ? y - x : x - y;
            g = gcd(diff, n);
        }

        if (g == n) continue;
        if (Miller_Rabin_Primality_Test(g)) return g;
        if (Miller_Rabin_Primality_Test(n / g)) return n / g;

        return Find_Prime_Factor_by_Pollard_Rho(n);
    }

    return n;
}

vector<pair<uint64_t, ll>> Prime_Factorization_by_Pollard_Rho(uint64_t n) {
    vector<pair<uint64_t, ll>> factors;
    while (n > 1) {
        uint64_t p = Find_Prime_Factor_by_Pollard_Rho(n);
        auto [e, m] = prime::exponents(n, p);

        factors.emplace_back(p, e);
        n = m;
    }

    return factors;
}