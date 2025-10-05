#pragma once

#include"../template/template.hpp"
#include"../Algebra/modint.hpp"
#include"Fast_Power_Series.hpp"
#include"Exp.hpp"

template<typename mint>
vector<mint> Bell_Number(int N) {
    vector<mint> fact(N + 1), fact_inv(N + 1);
    fact[0] = 1;
    for (int x = 1; x <= N; x++) { fact[x] = x * fact[x - 1]; }

    fact_inv[N] = fact[N].inverse();
    for (int x = N - 1; x >= 0; x--) { fact_inv[x] = (x + 1) * fact_inv[x + 1]; }

    vector<mint> f(fact_inv); f[0] = 0;
    Fast_Power_Series<mint> G = Exp(Fast_Power_Series(f, N + 1));

    vector<mint> g = G.poly;
    for (int k = 1; k <= N; k++) { g[k] *= fact[k]; }
    return g;
}
