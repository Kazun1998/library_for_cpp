#pragma once

#include"../Algebra/modint.hpp"
#include"Fast_Power_Series.hpp"
#include"Exp.hpp"

// A の (連続とは限らない) 部分列のうち, 和が k=0,1,...,K になる組み合わせの総数を Mod で割った余りを求める.
template<const ll Mod>
vector<modint<Mod>> Subset_Sum(vector<int> A, int K) {
    using mint = modint<Mod>;

    vector<ll> chi(K + 1);
    for (ll a: A) {
        if (a <= K) { chi[a] += 1; }
    }

    vector<mint> inv(K + 1); inv[1] = 1;
    for (int x = 2; x <= K; x++) {
        auto [q, r] = divmod(Mod, x);
        inv[x] = -q * inv[r];
    }

    vector<mint> f(K + 1);
    for (int x = 1; x <= K; x++) {
        if (chi[x] == 0) { continue; }

        for (int k = 1, c = 1; k * x <= K; k++) {
            f[k * x] += c * inv[k] * chi[x];
            c *= -1;
        }
    }

    auto g = Exp(Fast_Polynominal_Series<Mod>(f)).poly;
    g.resize(K + 1);
    return g;
}
