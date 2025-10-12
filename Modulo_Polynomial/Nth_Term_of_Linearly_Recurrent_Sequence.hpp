#pragma once

#include"../Algebra/modint.hpp"
#include"Fast_Power_Series.hpp"
#include"Fraction_Coefficient.hpp"

template<typename mint>
mint Nth_Term_of_Linearly_Recurrent_Sequence(const vector<mint> &a, const vector<mint> &c, ll n, ll offset = 0) {
    using FPS = Fast_Power_Series<mint>;

    ll d = a.size();
    n -= offset;

    if (n < 0) { return 0; }
    if (n < d) { return a[n]; }

    FPS A(a, d + 1);
    vector<mint> q(d + 1);
    for (int i = 0; i < d + 1; i++) { q[i] = i ? -c[i - 1] : 1; }

    FPS Q(q, d + 1);
    FPS P = A * Q;
    P.poly[d] = 0;

    return Fraction_Coefficient(P, Q, n);
}
