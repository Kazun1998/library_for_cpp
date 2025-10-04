#pragma once

#include"../template/template.hpp"
#include"../Algebra/modint.hpp"
#include"Fast_Power_Series.hpp"
#include"Exp.hpp"

template<typename mint>
vector<mint> Bernoulli_Number(int N) {
    vector<mint> fact(N + 2), fact_inv(N + 2);
    fact[0] = 1;
    for (int x = 1; x <= N + 1; x++) { fact[x] = x * fact[x - 1]; }
    fact_inv[N + 1] = fact[N + 1].inverse();
    for (int x = N; x >= 0; x--) { fact_inv[x] = (x + 1) * fact_inv[x + 1]; }

    vector<mint> g(N + 1);
    for (int d = 0; d < N + 1; d++) { g[d] = fact_inv[d + 1]; }

    Fast_Power_Series<mint> G(g, N + 1), P = Fast_Power_Series<mint>({1}, N + 1) / G;
    vector<mint> Bernoulli(N + 1);
    for (int k = 0; k <= N; k++) { Bernoulli[k] = fact[k] * P.poly[k]; }

    return Bernoulli;
}
