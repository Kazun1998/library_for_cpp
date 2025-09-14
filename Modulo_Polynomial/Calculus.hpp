#pragma once

#include"Fast_Power_Series.hpp"

// A の形式的微分を求める
template<const ll Mod>
Fast_Polynominal_Series<Mod> Differential(const Fast_Polynominal_Series<Mod> &A) {
    vector<modint<Mod>> b(A.precision);
    for (int k = 1; k < A.precision; k++) { b[k - 1] = k * A[k]; }
    return Fast_Polynominal_Series<Mod>(b, A.precision);
}

// A の不定積分を求める. ただし, 定数項は C (default 0) を使う.
template<const ll Mod>
Fast_Polynominal_Series<Mod> Integrate(const Fast_Polynominal_Series<Mod> &A, modint<Mod> C = 0) {
    using mint = modint<Mod>;
    if (A.is_zero()) { return Fast_Polynominal_Series<Mod>({0}, A.precision); }

    vector<mint> inv(A.precision + 1);
    inv[1] = mint(1);
    for (int k = 2; k <= A.precision; k++) {
        ll q, r;
        tie (q, r) = divmod(Mod, k);
        inv[k] = -q * inv[r];
    }

    vector<mint> b(A.precision + 1);
    b[0] = C;
    for (int k = 0; k < A.precision; k++) { b[k + 1] = inv[k + 1] * A[k]; }
    return Fast_Polynominal_Series<Mod>(b, A.precision);
}