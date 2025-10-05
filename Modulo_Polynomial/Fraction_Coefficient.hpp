#pragma once

#include"../Algebra/modint.hpp"
#include"Fast_Power_Series.hpp"

template<typename mint>
mint Fraction_Coefficient(const Fast_Power_Series<mint> &P, const Fast_Power_Series<mint> &Q, ll N) {
    vector<mint> p(P.poly), q(Q.poly);
    int m = 1 << ceil_log2(q.size());

    Numeric_Theory_Translation<mint> calc;

    p.resize(2 * m);
    q.resize(2 * m);

    while (N > 0) {
        vector<mint> r(2 * m);
        for (int i = 0; i < 2 * m; i++) { r[i] = (i % 2 == 0) ? q[i] : -q[i]; }

        calc.ntt(p), calc.ntt(q), calc.ntt(r);
        for (int i = 0; i < 2 * m; i++) { p[i] *= r[i]; q[i] *= r[i]; }

        calc.inverse_ntt(p); calc.inverse_ntt(q);

        if (N % 2 == 0) {
            for (int i = 0; i < m; i++) { p[i] = p[2 * i]; }
        } else {
            for (int i = 0; i < m; i++) { p[i] = p[2 * i + 1]; }
        }

        for (int i = 0; i < m; i++) { q[i] = q[2 * i]; }

        for (int i = m; i < 2 * m; i++) { p[i] = q[i] = 0; }

        N /= 2;
    }

    return p[0] / q[0];
}
