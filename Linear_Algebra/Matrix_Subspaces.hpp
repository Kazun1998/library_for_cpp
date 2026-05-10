#pragma once

#include "Matrix_Vectors.hpp"

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
