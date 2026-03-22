#pragma once

#include "../template/template.hpp"
#include "Prime.hpp"
#include "Odd_Montgomery_Multiplication.hpp"
#include "Miller_Rabin_Primality_Test.hpp"

uint64_t Find_Prime_Factor_by_Pollard_Rho(uint64_t n) {
    if (n == 1) return 1;
    if (n % 2 == 0) return 2;
    if (Miller_Rabin_Primality_Test(n)) return n;

    Odd_Montgomery_Multiplication calc(n);

    for (uint64_t c = 1; c < 99; ++c) {
        uint64_t mc = calc.form(c);
        auto f = [&](uint64_t x) -> uint64_t {
            uint64_t y = calc.multiply(x, x);
            uint64_t z = y + mc;
            if (z >= n) z -= n;
            return z;
        };
        
        // form で変換した後の整数で gcd を取っているが,
        // n が奇数で, form ではOdd_Montgomery_Multiplication の取り方的に n と互いに素な2^64 をかけて n で割っているため,
        // gcd は不変である.

        uint64_t x = calc.form(0), y = calc.form(0);
        uint64_t g = 1;
        uint64_t q = calc.form(1);
        uint64_t m = 500;

        while (g == 1) {
            uint64_t xs = x, ys = y;
            for (int i = 0; i < m; ++i) {
                x = f(x);
                y = f(f(y));
                uint64_t diff = x < y ? y - x : x - y;
                q = calc.multiply(q, diff);
            }
            g = gcd(q, n);
            if (g == 1) continue;
            if (g == n) {
                g = 1;
                x = xs; y = ys;
                while (g == 1) {
                    x = f(x);
                    y = f(f(y));
                    uint64_t diff = x < y ? y - x : x - y;
                    g = gcd(diff, n);
                }
                if (g == n) break;
            }

            if (Miller_Rabin_Primality_Test(g)) return g;
            if (Miller_Rabin_Primality_Test(n / g)) return n / g;
            return Find_Prime_Factor_by_Pollard_Rho(g);
        }
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