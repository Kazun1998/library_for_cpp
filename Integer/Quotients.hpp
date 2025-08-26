#pragma once

#include"../template/template.hpp"

vector<tuple<ll, ll, ll>> Quotients(ll N) {
    auto quotients = vector<tuple<ll, ll, ll>>();

    ll k = 1;
    for(; k * k <= N; k++) { quotients.emplace_back(make_tuple(N / k, k, k)); }

    for (ll t = k; t > 0; t--) {
        ll l = N / (t + 1) + 1, r = N / t;
        if (l <= r && get<1>(quotients.back()) < l) {
            quotients.emplace_back(make_tuple(t, l, r));
        }
    }

    return quotients;
}
