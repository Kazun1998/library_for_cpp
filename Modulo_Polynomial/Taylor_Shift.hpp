#pragma once

#include"Fast_Power_Series.hpp"

template<typename mint>
Fast_Power_Series<mint> Taylor_Shift(const Fast_Power_Series<mint> &P, const mint &a) {
    int n = P.precision;
    vector<mint> fact(n), fact_inv(n);
    fact[0] = 1;
    for (int k = 1; k < n; k++) { fact[k] = k * fact[k - 1]; }

    fact_inv[n - 1] = fact[n - 1].inverse();
    for (int k = n - 2; k >= 0; k--) { fact_inv[k] = (k + 1) * fact_inv[k + 1]; }

    vector<mint> f(n), g(n);
    for (int i = 0; i < n; i++) { f[i] = P[i] * fact[i]; }
    mint a_pow = 1;
    for (int i = 0; i < n; i++) {
        g[i] = a_pow * fact_inv[i];
        a_pow *= a;
    }

    reverse(g.begin(), g.end());

    auto calculator = Numeric_Theory_Translation<mint>();

    vector<mint> h = calculator.convolution(f, g);
    h.erase(h.begin(), h.begin() + n - 1);

    for (int k = 0; k < n; k++) { h[k] *= fact_inv[k]; }

    return Fast_Power_Series<mint>(h, P.precision);
}
