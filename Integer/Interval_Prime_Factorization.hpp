#pragma once

#include "../template/template.hpp"
#include "Prime.hpp"

vector<vector<pair<ll, int>>> Interval_Prime_Factorization(ll l, ll r) {
    const ll offset = l;
    const int size = r - l + 1;

    vector<vector<pair<ll, int>>> factors(size);
    vector<ll> remain(size);
    iota(remain.begin(), remain.end(), l);

    if (l == 0) {
        factors[0].emplace_back(0, 1);
        l = 1;
    }

    for (ll p: prime::prime_list(isqrt(r))) {
        for (ll x = (l + p - 1) / p * p; x <= r; x += p) {
            int e = 0;
            while (remain[x - offset] % p == 0) {
                remain[x - offset] /= p;
                e++;
            }
            factors[x - offset].emplace_back(p, e);
        }
    }

    for (ll x = l; x <= r; ++x) {
        unless (remain[x - offset] == 1) {
            factors[x - offset].emplace_back(remain[x - offset], 1);
        }
    }

    return factors;
}