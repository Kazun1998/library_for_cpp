#pragma once

#include "Matrix_Vectors.hpp"
#include "Field_Vector_Space.hpp"
#include "Reduction.hpp"

/**
 * @brief 行列 A の行空間 (Row Space) を求める
 * @tparam F 体の型
 * @param A 行列
 * @return Field_Vector_Space<F> 行空間
 */
template<typename F>
Field_Vector_Space<F> Row_Space(const Field_Matrix<F> &A) {
    return Field_Vector_Space<F>(A.col, Row_Vectors(A));
}

/**
 * @brief 行列 A の列空間 (Column Space / Image) を求める
 * @tparam F 体の型
 * @param A 行列
 * @return Field_Vector_Space<F> 列空間
 */
template<typename F>
Field_Vector_Space<F> Column_Space(const Field_Matrix<F> &A) {
    return Field_Vector_Space<F>(A.row, Column_Vectors(A));
}

/**
 * @brief 線形方程式 Ax = b を解く
 * @tparam F 体の型
 * @param A 行列
 * @param b ベクトル
 * @return std::optional<std::pair<Field_Vector<F>, Field_Vector_Space<F>>>  {特殊解, 解空間（核）}. 解が存在しない場合は nullopt
 */
template<typename F>
optional<pair<Field_Vector<F>, Field_Vector_Space<F>>> Solve_Linear_System(const Field_Matrix<F> &A, const Field_Vector<F> &b) {
    using Matrix = Field_Matrix<F>;
    using Vector = Field_Vector<F>;

    assert(A.row == b.dimension());

    // A は m 行 n 列
    int m = A.row, n = A.col;

    // 拡大係数行列 M = [A | b] を構築
    Matrix M(m, n + 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) M[i][j] = A[i][j];
        M[i][n] = b[i];
    }

    // M の行基本変形 M_reduce を得る
    Matrix M_reduce = Row_Reduce(M);

    // ピボットの列と自由変数の列を特定
    vector<int> pivots;
    vector<int> free_vars;
    int r = 0;
    for (int j = 0; j < n; j++) {
        if (r < m && M_reduce[r][j] != 0) {
            pivots.emplace_back(j);
            r++;
        } else {
            free_vars.push_back(j);
        }
    }

    // 解が存在するか（矛盾がないか）のチェック
    for (int i = r; i < m; i++) { unless (M_reduce[i][n] == 0) return nullopt; }

    // 特殊解 x0 を求める.
    Vector x0(n);
    for (int i = 0; i < r; i++) { x0[pivots[i]] = M_reduce[i][n]; }

    // Ker A の基底を求める.
    vector<Vector> ker_basis(n - r, Vector(n));
    for (int i = 0; i < free_vars.size(); ++i) ker_basis[i][free_vars[i]] = 1;

    for (int i = 0; i < ker_basis.size(); ++i) {
        for (int j = 0; j < r; ++j) {
            ker_basis[i][pivots[j]] = -M_reduce[j][free_vars[i]];
        }
    }


    return make_pair(x0, Field_Vector_Space<F>(n, ker_basis));
}
