#pragma once

#include"../template/template.hpp"
#include"Prime.hpp"
#include"Miller_Rabin_Primality_Test.hpp"

ll Find_Factor_Rho(ll N) {
    if (N == 1) { return 1; }

    ll m = 1 << (bit_length(N) / 8 + 1);
    for (ll c = 1; c < 100; c++) {
        auto f = [&c, &N](ll x) { return (x * x + c) % N; };

        ll y = 2, r = 1, g = 1;
        __int128_t q = 1;
        while (g == 1) {
            ll x = y;
            rep(r) { y = f(y); }

            ll k = 0;
            while (k < r && g == 1) {
                for (ll j = 1; j <= min(m, r - k); j++){
                    y = f(y);
                    q = q * abs(x - y) % N;
                }

                g = gcd(q % N, N);
                k += m;
            }

            r <<= 1;
        }

        if (g == N) { continue; }

        if (Miller_Rabin_Primality_Test(g)) { return g; }
        if (Miller_Rabin_Primality_Test(N / g)) { return N / g; }
    }

    return N;
}

// ポラード・ローアルゴリズムによる素因数分解
vector<pair<long long, long long>> Pollard_Rho_Prime_Factorization(ll N) {
    vector<pair<long long, long long>> factors;

    // N < 2^20 のときは, O(sqrt(N)) 時間の素因数分解で行う.
    if (N < pow(2LL, 20)) { return Prime::prime_factorization(N); }

    // Section I: 101 以下の素数を最初に処理する.
    Prime::Pseudo_Prime_Generator generator;
    for (int p = generator.get(); p <= 101; p = generator.get()) {
        ll e;
        tie (e, N) = Prime::exponents(N, p);
        if (e > 0) { factors.emplace_back(p, e); }
    }

    // Section II: Find_Factor_Rho によって, 残りの素因数を見つける.
    while (N > 1) {
        if (Miller_Rabin_Primality_Test(N)) {
            factors.emplace_back(N, 1);
            N = 1;
        } else {
            ll p = Find_Factor_Rho(N);
            ll e;
            tie (e, N) = Prime::exponents(N, p);
            factors.emplace_back(p, e);
        }
    }

    sort(all(factors));

    return factors;
}