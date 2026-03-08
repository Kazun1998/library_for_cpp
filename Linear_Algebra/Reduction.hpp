#pragma once

#include"Field_Matrix.hpp"

template<typename F>
Field_Matrix<F> Row_Reduce(const Field_Matrix<F> &A) {
    if (A.row == 0) { return Field_Matrix(A); }

    vector<vector<F>> X(A.mat);
    for (int i = 0, j = 0; i < A.row && j < A.col; j++) {
        if(X[i][j] == 0) {
            int p = i + 1;
            for (; p < A.row; p++) {
                if (X[p][j] == 0) { continue; }

                swap(X[p], X[i]);
                break;
            }

            if (p == A.row) { continue; }
        }

        F u = X[i][j], u_inv = u.inverse();
        for (int q = 0; q < A.col; q++) { X[i][q] *= u_inv; }

        for (int p = 0; p < A.row; p++) {
            if (p == i) { continue; }

            F v = X[p][j];
            for (int q = 0; q < A.col; q++) { X[p][q] -= v * X[i][q]; }
        }

        i++;
    }

    return Field_Matrix<F>(X);
}
