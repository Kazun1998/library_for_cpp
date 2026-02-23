#pragma once

#include "../template/template.hpp"

template<class Semiring, auto ADD, auto zero, auto MUL, auto one>
class Semiring_Matrix {
    public:
    int row, col;

    Semiring_Matrix(int n, int m): row(n), col(m) {}

    private:
    vector<vector<Semiring>> mat;
};

