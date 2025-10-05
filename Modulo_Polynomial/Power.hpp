#pragma once

#include"Exp.hpp"

// A の M 乗を求める.
template<typename mint>
Fast_Power_Series<mint> pow(Fast_Power_Series<mint> &A, ll M) {
    using FPS = Fast_Power_Series<mint>;

    // M = 0 のときは, A^0 = 1 が確定
    if (M == 0) { return Fast_Power_Series<mint>({1}, A.precision); }

    int ord = A.order();

    // A = 0 のときは, M != 0 より, A^M = 0 が確定
    if (ord == -1) { return Fast_Power_Series<mint>(A.precision); }

    // ord(A^M) = M ord(A) である. M ord(A) > n ならば, A^M = 0 (mod X^n) になる.
    if (ord > A.precision / M) { return Fast_Power_Series<mint>(A.precision); }

    mint content = A[ord];
    mint content_inv = content.inverse();
    mint content_m = pow(content, M);

    M %= mint::Mod;

    vector<mint> b(A.precision - ord);
    for (int d = ord; d < A.precision; d++) { b[d - ord] = A[d] * content_inv; }
    FPS B(b);
    FPS C = Exp(M * Log(B));

    vector<mint> g(ord * M, 0);
    g.insert(g.end(), C.poly.begin(), C.poly.end());
    g.resize(A.precision);

    Fast_Power_Series<mint> G(g);
    G *= content_m;

    return G;
}
