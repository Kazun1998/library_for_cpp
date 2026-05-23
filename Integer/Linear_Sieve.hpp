#pragma once

#include "../template/template.hpp"

vector<int> Linear_Sieve(const int n) {
    vector<int> lpf(n + 1, 0), primes;

    lpf[1] = 1;
    for (int i = 2; i <= n; ++i) {
        // lpf[i] がこの時点で未確定ならば, i は素数である.
        if (lpf[i] == 0) {
            lpf[i] = i;
            primes.emplace_back(i);
        }

        // p <= lpf[i] である素数 p について, lpf[i * p] = p である.
        for (int p: primes) {
            unless(p * i <= n && p <= lpf[i]) break;

            lpf[p * i] = p;
        }
    }

    return lpf;
}
