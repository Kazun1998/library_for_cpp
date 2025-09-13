#pragma once

#include"../template/template.hpp"

vector<tuple<ll, ll, ll>> Quotients(ll N) {
    auto quotients = vector<tuple<ll, ll, ll>>();

    ll l = 1;
    while (l <= N) {
        ll q = N / l;
        ll r = N / q;
        quotients.emplace_back(q, l, r);
        l = r + 1;
    }

    return quotients;
}
