#pragma once

#include "../template/template.hpp"
#include "../Integer/Prime.hpp"
#include "Modulo.hpp"

namespace modulo {
    vector<ll> Garner_Base(const vector<Modulo> &X) {
        int n = X.size();
        vector<ll> a(n), m(n);
        for (int i = 0; i < n; ++i) {
            a[i] = X[i].a, m[i] = X[i].n;
        }
        vector<ll> s(n);

        for (int i = 0; i < n; ++i) {
            ll m_product = 1;
            ll left = 0;
            for (int j = 0; j < i; ++j) {
                left = safe_mod(left + safe_mod(m_product * s[j], m[i]), m[i]);
                m_product = safe_mod(m_product * m[j], m[i]);
            }

            auto [right, _1, _2] = Extended_Euclid<ll>(m_product, m[i]);
            s[i] = safe_mod((a[i] - left) * right, m[i]);
        }

        return s;
    }

    optional<ll> First_Garner(vector<Modulo> X, const ll R, bool positive = false) {
        int n = X.size();

        map<ll, pair<int, int>> champions;
        prime::Pseudo_Prime_Generator generator;

        for (int i = 0; i < n; ++i) {
            for (auto [p, e]: prime::prime_factorization(X[i].n)) {

                if (champions.count(p) == 0) {
                    champions[p] = {i, e};
                    continue;
                }

                auto [j, f] = champions[p];

                ll q = intpow(p, min<int>(e, f));

                unless (X[i].a % q == X[j].a % q) return nullopt;

                if (e >= f) {
                    X[j].degenerate(X[j].n / q);
                    champions[p] = {i, e};
                }
                else {
                    X[i].degenerate(X[i].n / q);
                }
            }
        }

        auto s = Garner_Base(X);

        if (positive && ranges::count(s, 0) == n) {
            ll res = 1;
            for (const auto &x: X) {
                res = safe_mod(res * x.n, R);
            }

            return res;
        }

        ll res = 0;
        for (int i = n - 1; i >=0 ; --i) {
            res = safe_mod(X[i].n * res + s[i], R);
        }

        return res;
    }
}
