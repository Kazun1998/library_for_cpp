#pragma once

#include "../template/template.hpp"
#include "Find_Linear_Recurrence.hpp"

template<typename F>
F Determinant_of_Sparse_Matrix(const int N, const vector<tuple<int, int, F>> &elements) {
    auto random_vector = [&N]() -> vector<F> {
        static mt19937 engine(chrono::steady_clock::now().time_since_epoch().count());
        vector<F> res(N);
        for (int i = 0; i < N; ++i) res[i] = F(engine());

        return res;
    };

    // 非ゼロのランダムな要素で対角行列を作成
    auto random_diagonal_matrix = [&N]() -> pair<vector<F>, F> {
        static mt19937 engine(chrono::steady_clock::now().time_since_epoch().count());
        vector<F> D(N);

        F det_D = 1;
        for (int i = 0; i < N; ++i) {
            do { D[i] = F(engine()); } while (D[i] == F(0));
            det_D *= D[i];
        }

        return { D, det_D };
    };
    


    auto inner = [&N](const vector<F> &u, const vector<F> &v) -> F {
        F y = 0;
        for (int i = 0; i < N; ++i) y += u[i] * v[i];
        return y;
    };

    vector<F> u = random_vector();
    vector<F> v = random_vector();
    auto [D, det_D] = random_diagonal_matrix();

    vector<F> y(2 * N);

    y[0] = inner(u, v);
    for (int k = 1; k < 2 * N; ++k) {
        vector<F> w(N, 0);
        for (auto [i, j, a]: elements) {
            w[i] += a * v[j];
        }
        for (int i = 0; i < N; ++i) w[i] *= D[i]; // D を適用

        v = std::move(w);
        y[k] = inner(u, v);
    }

    vector<F> c = Find_Linear_Recurrence(y);

    // ランダム化しても次数が N 未満なら行列式は 0
    unless(c.size() == N) return F(0);

    F det_DA = is_odd(N) ? c[N - 1] : -c[N - 1];
    return det_DA / det_D;
}
