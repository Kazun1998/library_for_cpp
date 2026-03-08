#pragma once

#include "../template/template.hpp"
#include "Prime.hpp"
#include "Odd_Montgomery_Multiplication.hpp"

// N が素数かどうかを判定する.
bool Miller_Rabin_Primality_Test(ll N, int trial = 30) {
    if (N == 2) { return true; }
    if (N == 1 || N % 2 == 0) { return false; }

    ll q; int k;
    tie (k, q) = prime::exponents(N - 1, 2);

    random_device device;
    mt19937_64 gen(device());
    uniform_int_distribution<ll> distribute(2, N - 1);
    Odd_Montgomery_Multiplication calculator(N);

    auto challenge = [&]() -> bool {
        ll m = distribute(gen);
        auto y = calculator.modpow(m, q);

        if (y == 1) { return true; }

        rep(k) {
            if (y == N - 1) { return true; }

            y = calculator.mod_mul(y, y);
        }

        return false;
    };

    rep(trial) { unless(challenge()) { return false; } }

    return true;
}