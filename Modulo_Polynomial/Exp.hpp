#pragma once

#include"Fast_Power_Series.hpp"
#include"Log.hpp"

template<const ll Mod>
Fast_Polynominal_Series<Mod> Exp(const Fast_Polynominal_Series<Mod> &A) {
    assert(A[0].is_zero());

    int n = A.precision;

    Fast_Polynominal_Series<Mod> G({1}, 1), one({1}, n);
    for (; G.precision < n;) {
        G.precision *= 2;
        G = G * (one - Log(G) + A);
    }

    return G;
}
