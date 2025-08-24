#pragma once

#include"../template/template.hpp"

// N 以下の約数を列挙
vector<ll> Divisors(ll N) {
    vector<ll> divisors;
    for (int x = 1; x * x <= N; x++){
        unless(N % x == 0) { continue; }

        divisors.emplace_back(x);
        if (N / x != x) { divisors.emplace_back(N / x); }
    }

    sort(all(divisors));

    return divisors;
}
