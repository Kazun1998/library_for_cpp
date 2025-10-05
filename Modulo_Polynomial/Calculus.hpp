#pragma once

#include"Fast_Power_Series.hpp"

// A の形式的微分を求める
template<typename mint>
Fast_Power_Series<mint> Differential(const Fast_Power_Series<mint> &A) {
    vector<mint> b(A.precision);
    for (int k = 1; k < A.precision; k++) { b[k - 1] = k * A[k]; }
    return Fast_Power_Series<mint>(b, A.precision);
}

// A の不定積分を求める. ただし, 定数項は C (default 0) を使う.
template<typename mint>
Fast_Power_Series<mint> Integrate(const Fast_Power_Series<mint> &A, const mint C = 0) {
    if (A.is_zero()) { return Fast_Power_Series<mint>({0}, A.precision); }

    vector<mint> inv(A.precision + 1);
    inv[1] = mint(1);
    for (int k = 2; k <= A.precision; k++) {
        ll q, r;
        tie (q, r) = divmod(mint::Mod, k);
        inv[k] = -q * inv[r];
    }

    vector<mint> b(A.precision + 1);
    b[0] = C;
    for (int k = 0; k < A.precision; k++) { b[k + 1] = inv[k + 1] * A[k]; }
    return Fast_Power_Series<mint>(b, A.precision);
}