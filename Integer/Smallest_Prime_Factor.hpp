#pragma once

#include"../template/template.hpp"

namespace prime {
    class Smallest_Prime_Factor {
        private:
        vector<ll> spf; // smallest prime factor

        public:
        Smallest_Prime_Factor(int N): spf(N + 1, 1) {
            if (N <= 1) return;

            for (int x = 2; x <= N; x += 2) spf[x] = 2;
            for (int x = 3; x <= N; x += 6) spf[x] = 3;

            vector<int> primes{2, 3};
            bool parity = 0;
            for (int x = 5; x <= N; x += parity ? 4 : 2, parity ^= true) {
                if (spf[x] == 1) {
                    spf[x] = x;
                    primes.emplace_back(x);
                }

                for (int p: primes) {
                    unless (x <= N / p) break;

                    spf[x * p] = p;
                    if (p == spf[x]) break;
                }
            }
        }

        constexpr inline int smallest_prime_factor(int x) const { return spf[x]; }

        vector<pair<long long, long long>> prime_factorization(int n) {
            if (n == 0)  { return vector<pair<long long, long long>>{ make_pair(0, 1) }; }

            vector<pair<long long, long long>> factors;
            if (n < 0) {
                factors.emplace_back(-1, 1);
                n = -n;
            }

            while (n > 1) {
                int p = spf[n];
                int e = 0;
                while (spf[n] == p) {
                    e ++;
                    n /= p;
                }

                factors.emplace_back(p, e);
            }

            return factors;
        }
    };
}
