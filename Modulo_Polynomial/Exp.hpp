#pragma once

#include"Fast_Power_Series.hpp"
#include"Log.hpp"

template<typename mint>
Fast_Power_Series<mint> Exp(const Fast_Power_Series<mint> &A) {
    assert(A[0].is_zero());

    int n = A.precision;

    Fast_Power_Series<mint> G({1}, 1), one({1}, n);
    for (; G.precision < n;) {
        G.precision *= 2;
        G = G * (one - Log(G) + A);
    }

    return G;
}
