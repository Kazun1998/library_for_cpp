#pragma once

#include"Exp.hpp"

// A の M 乗を求める.
template<const ll Mod>
Fast_Polynominal_Series<Mod> pow(Fast_Polynominal_Series<Mod> &A, ll M) {
    using mint = modint<Mod>;
    using FPS = Fast_Polynominal_Series<Mod>;

    // M = 0 のときは, A^0 = 1 が確定
    if (M == 0) { return Fast_Polynominal_Series<Mod>({1}, A.precision); }

    int ord = A.order();

    // A = 0 のときは, M != 0 より, A^M = 0 が確定
    if (ord == -1) { return Fast_Polynominal_Series<Mod>(A.precision); }

    // ord(A^M) = M ord(A) である. M ord(A) > n ならば, A^M = 0 (mod X^n) になる.
    if (ord > A.precision / M) { return Fast_Polynominal_Series<Mod>(A.precision); }

    mint content = A[ord];
    mint content_inv = content.inverse();
    mint content_m = pow(content, M);

    M %= Mod;

    vector<mint> b(A.precision - ord);
    for (int d = ord; d < A.precision; d++) { b[d - ord] = A[d] * content_inv; }
    FPS B(b);
    FPS C = Exp(M * Log(B));

    vector<mint> g(ord * M, 0);
    g.insert(g.end(), C.poly.begin(), C.poly.end());
    g.resize(A.precision);

    Fast_Polynominal_Series<Mod> G(g);
    G *= content_m;

    return G;
}
