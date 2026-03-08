#pragma once

#include"Field_Matrix.hpp"
#include"Reduction.hpp"

template<typename F>
int Rank(const Field_Matrix<F> &A) {
    Field_Matrix<F> B = Row_Reduce(A);

    int rank = 0;
    for (int i = 0; i < A.row; i++) {
        for (int j = 0; j < A.col; j++) {
            unless(B.mat[i][j] == 0) { rank++; break; }
        }
    }
    return rank;
}
