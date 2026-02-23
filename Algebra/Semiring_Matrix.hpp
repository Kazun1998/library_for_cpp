#pragma once

#include "../template/template.hpp"

template<class Semiring, auto ADD, auto zero, auto MUL, auto one>
class Semiring_Matrix {
    public:
    int row, col;

    Semiring_Matrix() : row(0), col(0) {}
    Semiring_Matrix(int n, int m) : row(n), col(m), mat(n, vector<Semiring>(m, zero)) {}
    Semiring_Matrix(const vector<vector<Semiring>>& mat) : row(mat.size()), col(mat.size() ? mat[0].size() : 0), mat(mat) {}

    inline const vector<Semiring>& operator[](int i) const { return mat[i]; }
    inline vector<Semiring>& operator[](int i) { return mat[i]; }

    static Semiring_Matrix identity(int n) {
        Semiring_Matrix res(n, n);
        for (int i = 0; i < n; ++i) res[i][i] = one;
        return res;
    }

    Semiring_Matrix& operator+=(const Semiring_Matrix& b) {
        assert(row == b.row && col == b.col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                mat[i][j] = ADD(mat[i][j], b[i][j]);
            }
        }
        return *this;
    }

    friend Semiring_Matrix operator+(const Semiring_Matrix& a, const Semiring_Matrix& b) { return Semiring_Matrix(a) += b; }

    friend Semiring_Matrix operator*(const Semiring_Matrix& a, const Semiring_Matrix& b) {
        assert(a.col == b.row);
        Semiring_Matrix res(a.row, b.col);
        for (int i = 0; i < a.row; ++i) {
            for (int k = 0; k < a.col; ++k) {
                for (int j = 0; j < b.col; ++j) {
                    res[i][j] = ADD(res[i][j], MUL(a[i][k], b[k][j]));
                }
            }
        }
        return res;
    }

    Semiring_Matrix& operator*=(const Semiring_Matrix& b) { return *this = *this * b; }

    Semiring_Matrix transpose() const {
        Semiring_Matrix res(col, row);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                res[j][i] = mat[i][j];
            }
        }
        return res;
    }

    friend ostream& operator<<(ostream& os, const Semiring_Matrix& m) {
        for (int i = 0; i < m.row; ++i) {
            for (int j = 0; j < m.col; ++j) {
                os << m[i][j] << (j == m.col - 1 ? "" : " ");
            }
            if (i != m.row - 1) os << "\n";
        }
        return os;
    }

    private:
    vector<vector<Semiring>> mat;
};
