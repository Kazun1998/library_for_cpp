#pragma once

#include"../Algebra/modint.hpp"
#include"Numeric_Theory_Translation.hpp"

template<typename mint>
vector<mint> Partitions_P(int N) {
    Numeric_Theory_Translation<mint> calc;

    vector<mint> f(N + 1);
    f[0] = 1;

    for (int k = 1; k * (3 * k - 1) <= 2 * N; k++) {
        mint m = ((k & 1) == 0) ? 1 : -1;

        int d1 = k * (3 * k - 1) / 2, d2 = k * (3 * k + 1) / 2;
        f[d1] += m;
        if (d2 <= N) { f[d2] += m; }
    }

    return calc.inverse(f);
}
