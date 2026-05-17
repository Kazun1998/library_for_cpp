#pragma once

#include "../template/template.hpp"
#include "../Counting/Combination_Calculator.hpp"
#include "../Math/Enumerate_Geometrics.hpp"
#include "../Math/Enumerate_Powers.hpp"

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
