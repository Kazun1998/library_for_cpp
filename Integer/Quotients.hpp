#pragma once

#include"../template/template.hpp"

vector<tuple<ll, ll, ll>> Quotients(ll N) {
    auto quotients = vector<tuple<ll, ll, ll>>();

    ll l = 1;
    while (l <= N) {
        ll q = N / l;
        ll r = div_ceil(N, q + 1);
        quotients.emplace_back(q, l, r);
    }

    return quotients;
}
