#pragma once

#include "../template/template.hpp"
#include "Modulo.hpp"

namespace modulo {
    vector<ll> Garner(const vector<Modulo> &X) {
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
                left += safe_mod(m_product * s[j], m[i]);
                m_product = safe_mod(m_product * m[j], m[i]);
            }

            auto [right, _1, _2] = Extended_Euclid<ll>(m_product, m[i]);
            s[i] = safe_mod((a[i] - left) * right, m[i]);
        }

        return s;
    }

    ll First_Garner(const vector<Modulo> &X, const ll R) {
        int n = X.size();
        auto s = Garner(X);

        ll res = 0;
        for (int i = n - 1; i >=0 ; --i) {
            res = safe_mod(X[i].n * res + s[i], R);
        }

        return res;
    }
}
