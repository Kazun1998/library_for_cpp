#pragma once

#include"../Algebra/modint.hpp"
#include"Fast_Power_Series.hpp"
#include"Fraction_Coefficient.hpp"

template<const ll Mod>
modint<Mod> Nth_Term_of_Linearly_Recurrent_Sequence(const vector<modint<Mod>> &a, const vector<modint<Mod>> &c, ll n, ll offset = 0) {
    using FPS = Fast_Polynominal_Series<Mod>;

    ll d = a.size();
    n -= offset;

    if (n < 0) { return 0; }
    if (n < d) { return a[n]; }

    FPS A(a, d + 1);
    vector<modint<Mod>> q(d + 1);
    for (int i = 0; i < d + 1; i++) { q[i] = i ? -c[i - 1] : 1; }

    FPS Q(q, d + 1);
    FPS P = A * Q;
    P.poly[d] = 0;

    return Fraction_Coefficient(P, Q, n);
}
