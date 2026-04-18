#pragma once

#include "../template/template.hpp"
#include "../Counting/Combination_Calculator.hpp"
#include "../Math/Lagrange_Interpolation.hpp"
#include "Enumerate_Geometrics.hpp"
#include "Enumerate_Powers.hpp"

template<typename F>
F Sum_of_Exponential_Times_Polynomial(const F r, const int d, const ll n) {
    // n < 0 のときは, 自明に sum = 0;
    if (n < 0) return 0;
    // r = 0 のときは, sum = 0^d になる (n >= 0 は保証されている)
    if (r == F(0)) return d == 0 ? 1 : 0;

    vector<F> S(d + 2);
    {
        vector<F> powers = Enumerate_Powers<F>(d + 2, d);
        if (r == F(1)) {
            // r = 1のときは, sum = 0^d + 1^d + 2^d + ... + n^d になる.
            S[0] = powers[0];
            for (int k = 1; k <= d + 1; ++k) S[k] = S[k - 1] + powers[k];
            vector<F>().swap(powers);
            return Lagrange_Interpolation_Point_Arithmetic(S, F(n));
        }
        F r_pow = 1;
        S[0] = powers[0]; // r^0 * 0^d
        for (int k = 1; k <= d + 1; ++k) {
            r_pow *= r;
            S[k] = S[k - 1] + powers[k] * r_pow;
        }
        vector<F>().swap(powers);
    }

    F C;
    {
        F P_1 = 0;
        F comb = 1; // nCr(d+1, k)
        F r_pow = 1; // r^k
        for (int k = 0; k <= d + 1; ++k) {
            F term = comb * r_pow * S[d + 1 - k];
            if (is_odd(k)) P_1 -= term; else P_1 += term;
            if (k < d + 1) {
                comb *= F(d + 1 - k);
                comb /= F(k + 1);
                r_pow *= r;
            }
        }
        C = P_1 / pow(1 - r, d + 1);
    }

    // S を T に書き換え (T_k = (S_k - C) / r^k)
    F inv_r = F(1) / r;
    F inv_r_pow = 1;
    for (int k = 0; k <= d + 1; ++k) {
        S[k] = (S[k] - C) * inv_r_pow;
        inv_r_pow *= inv_r;
    }

    F T_n = Lagrange_Interpolation_Point_Arithmetic(S, F(n));
    return C + pow(r, n) * T_n;
}

template<typename F>
F Sum_of_Exponential_Times_Polynomial_Limit(const F r, const int d) {
    assert(r != F(1));

    vector<F> S(d + 2);
    {
        vector<F> powers = Enumerate_Powers<F>(d + 2, d);
        F r_pow = 1;
        S[0] = powers[0];
        for (int k = 1; k <= d + 1; ++k) {
            r_pow *= r;
            S[k] = S[k - 1] + powers[k] * r_pow;
        }
        vector<F>().swap(powers);
    }

    F P_1 = 0; // 多項式 P(x) の x=1 における値
    {
        F comb = 1;
        F r_pow = 1;
        for (int k = 0; k <= d + 1; ++k) {
            F term = comb * r_pow * S[d + 1 - k];
            is_even(k) ? P_1 += term : P_1 -= term;
            if (k < d + 1) {
                comb *= F(d + 1 - k);
                comb /= F(k + 1);
                r_pow *= r;
            }
        }
    }

    return P_1 / pow(1 - r, d + 1);
}
