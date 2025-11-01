#pragma once

#include"../template/template.hpp"
#include"Prime.hpp"
#include"Quotients.hpp"

namespace prime {
    /// @brief `N` 以下の素数の数を求める.
    /// @param N 
    /// @return `N` 以下の素数の数
    ll Prime_Pi(const ll &N) {
        if (N <= 0) { return 0; }

        vector<ll> quotients;
        for (auto &[q, l, r]: Quotients(N)) {
            quotients.emplace_back(q);
        }

        unordered_map<ll, ll> S;
        for (ll q: quotients) { S[q] = q - 1; }

        ll N_sqrt = isqrt(N);
        for (ll x = 2; x <= N_sqrt; x++) {
            if (S[x] <= S[x - 1]) { continue; }

            for (ll n: quotients) {
                if (n < x * x) { break; }

                S[n] -= S[n / x] - S[x - 1];
            }
        }

        return S[N];
    }
};
