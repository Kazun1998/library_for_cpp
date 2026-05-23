#pragma once

#include "../template/template.hpp"
#include "Prime.hpp"

/**
 * @brief 区間 [l, r] 内のすべての整数の素因数分解を計算する.
 * @param l 区間の下限 (0 <= l)
 * @param r 区間の上限 (l <= r)
 * @return vector<vector<pair<ll, int>>> 素因数分解結果のリスト.
 *         戻り値の i 番目の要素は, 値 (l + i) の素因数分解 (素因数, 指数) のリスト.
 */
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