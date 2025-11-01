#pragma once

#include"../Algebra/modint.hpp"
#include"../Counting/Combination_Calculator.hpp"
#include"Fast_Power_Series.hpp"
#include"Exp.hpp"

template<typename mint>
vector<mint> Partition_Q(int N) {
    Combination_Calculator<mint> calc(N + 1);

    vector<mint> p(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = i, k = 1, c = 1; j <= N; j += i, k++, c *= -1) {
            p[j] += c * calc.inv(k);
        }
    }

    Fast_Power_Series<mint> P(p);

    return Exp(P).poly;
}
