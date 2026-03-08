#pragma once

#include"../Algebra/modint.hpp"
#include"Numeric_Theory_Translation.hpp"

template<typename mint>
vector<mint> Stirling_2nd(int N) {
    Numeric_Theory_Translation<mint> calc;

    vector<mint> fact(N + 1), fact_inv(N + 1);

    fact[0] = 1;
    for (int k = 1; k <= N; k++) { fact[k] = k * fact[k - 1]; }

    fact_inv[N] = fact[N].inverse();
    for (int k = N - 1; k >= 0; k--) { fact_inv[k] = (k + 1) * fact_inv[k + 1]; }

    vector<mint> a(N + 1), b(N + 1);
    for (int i = 0; i <= N; i++) { a[i] = pow(mint(i), N) * fact_inv[i]; }
    for (int j = 0; j <= N; j++) { b[j] = (j % 2 == 0) ? fact_inv[j] : -fact_inv[j]; }

    vector<mint> c = calc.convolution(a, b);
    c.erase(c.begin() + N + 1, c.end());
    return c;
}
