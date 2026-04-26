#pragma once

#include "../template/template.hpp"
#include "Find_Linear_Recurrence.hpp"

/**
 * @brief 疎行列の行列式を計算する (Wiedemann法) 
 * @tparam F 体の要素の型 (modint等)
 * @param N 行列のサイズ
 * @param elements 行列の非ゼロ要素 (row, col, value) のリスト
 * @return F 行列式の結果。行列が非正則である可能性が高い場合は 0 を返す
 * @note 計算量: 非零要素の数を K として, O(N * (K + N))
 */
template<typename F>
F Determinant_of_Sparse_Matrix(const int N, const vector<tuple<int, int, F>> &elements) {
    // ランダムなベクトルを生成する
    auto random_vector = [&N]() -> vector<F> {
        static mt19937 engine(chrono::steady_clock::now().time_since_epoch().count());
        vector<F> res(N);
        for (int i = 0; i < N; ++i) res[i] = F(engine());

        return res;
    };

    // 各成分が非ゼロであるランダムな対角行列 D とその行列式 det(D) を生成する
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
    

    // ベクトルの内積を計算する
    auto inner = [&N](const vector<F> &u, const vector<F> &v) -> F {
        F y = 0;
        for (int i = 0; i < N; ++i) y += u[i] * v[i];
        return y;
    };

    vector<F> u = random_vector();
    vector<F> v = random_vector();
    auto [D, det_D] = random_diagonal_matrix();

    vector<F> y(2 * N);

    // 数列 y_k = u^T (DA)^k v を生成 (k = 0 ... 2N-1)
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

    // Berlekamp-Massey 法により最短線形漸化式を求める
    vector<F> c = Find_Linear_Recurrence(y);

    // 最小多項式の次数が N 未満であれば、行列は特異（行列式 0）とみなす
    unless(c.size() == N) return F(0);

    // 最小多項式の定数項から det(DA) を導出
    F det_DA = is_odd(N) ? c[N - 1] : -c[N - 1];
    return det_DA / det_D;
}
