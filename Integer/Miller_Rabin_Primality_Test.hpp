#pragma once

#include"../template/template.hpp"
#include"Prime.hpp"

// N が素数かどうかを判定する.
bool Miller_Rabin_Primality_Test(ll N, int trial = 30) {
    if (N == 2) { return true; }
    if (N == 1 || N % 2 == 0) { return false; }

    ll q; int k;
    tie (k, q) = Prime::exponents(N - 1, 2);

    random_device device;
    mt19937_64 gen(device());
    uniform_int_distribution<ll> distribute(2, N - 1);

    auto challenge = [&]() -> bool {
        __int128_t m = distribute(gen);
        auto y = modpow(m, q, (__int128_t)N);

        if (y == 1) { return true; }

        bool flag = true;
        rep(k) {
            if ((y + 1) % N == 0) { return true; }

            y *= y; y %= N;
        }

        return false;
    };

    rep(trial) { unless(challenge()) { return false; } }

    return true;
}