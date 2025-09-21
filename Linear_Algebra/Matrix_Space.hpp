#pragma once

#include"Field_Vector_Space.hpp"
#include"Field_Matrix.hpp"

// A の行ベクトルからなる列を生成する.
template<typename F>
vector<Field_Vector<F>> Row_Vectors(const Field_Matrix<F> &A) {
    vector<Field_Vector<F>> row_vectors(A.row, Field_Vector<F>(A.col));
    for (int i = 0; i < A.row; i++) { row_vectors[i] = Field_Vector(A.mat[i]); }

    return row_vectors;
}

// A の列ベクトルからなる列を生成する.
template<typename F>
vector<Field_Vector<F>> Column_Vectors(const Field_Matrix<F> &A) {
    vector<vector<F>> tmp(A.col, vector<F>(A.row));
    for (int i = 0; i < A.row; i++) {
        for (int j = 0; j < A.col; j++) {
            tmp[j][i] = A.mat[i][j];
        }
    }

    vector<Field_Vector<F>> column_vectors(A.col, Field_Vector<F>(A.row));
    for (int j = 0; j < A.col; j++) { column_vectors[j] = Field_Vector(tmp[j]); }
    return column_vectors;
}
