#pragma once

#include "../template/template.hpp"
#include "Prime.hpp"

vector<bool> Interval_Sieve_of_Eratosthenes(const ll l, const ll r) {
    const ll offset = l;
    const int size = r - l + 1;
    vector<bool> is_prime(size, true);

    // 0 と 1 の例外
    if (l <= 0 && 0 <= r) is_prime[0 - offset] = false;
    if (l <= 1 && 1 <= r) is_prime[1 - offset] = false;

    for (ll p: prime::prime_list(isqrt(r))) {
        for (ll x = max<ll>((l + p - 1) / p * p, p * p); x <= r; x += p) {
            is_prime[x - offset] = false;
        }
    }

    return is_prime;
}
