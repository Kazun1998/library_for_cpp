#pragma once

#include "../template/template.hpp"
#include "Extended_Algebra.hpp"

template<class Semiring, auto ADD, auto zero, auto MUL, auto one>
class Semiring_Matrix {
    public:
    int row, col;

    Semiring_Matrix() : row(0), col(0) {}
    Semiring_Matrix(int n): Semiring_Matrix(n, n) {}
    Semiring_Matrix(int n, int m) : row(n), col(m), mat(n, vector<Semiring>(m, zero)) {}
    Semiring_Matrix(const vector<vector<Semiring>>& mat) : row(mat.size()), col(mat.size() ? mat[0].size() : 0), mat(mat) {}

    inline const vector<Semiring>& operator[](int i) const { return mat[i]; }
    inline vector<Semiring>& operator[](int i) { return mat[i]; }

    inline const Semiring& operator[](int i, int j) const { return mat[i][j]; }
    inline Semiring& operator[](int i, int j) { return mat[i][j]; }

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

template<class Semiring, auto ADD, auto zero, auto MUL, auto one>
Semiring_Matrix<Semiring, ADD, zero, MUL, one> power(Semiring_Matrix<Semiring, ADD, zero, MUL, one> A, int64_t n) {
    assert(A.row == A.col);
    assert(n >= 0);

    auto res = Semiring_Matrix<Semiring, ADD, zero, MUL, one>::identity(A.row);

    while (n > 0) {
        if (n & 1) res *= A;
        A *= A;
        n >>= 1;
    }
    return res;
}

namespace semiring_ops {
    template<class T> T op_max(T a, T b) { return a > b ? a : b; }
    template<class T> T op_min(T a, T b) { return a < b ? a : b; }
    template<class T> T op_add(T a, T b) { return a + b; }
}

template<class T>
using Max_Min_Matrix = Semiring_Matrix<Extended_Algebra<T>, semiring_ops::op_max<Extended_Algebra<T>>, -Extended_Algebra<T>::inf, semiring_ops::op_min<Extended_Algebra<T>>, Extended_Algebra<T>::inf>;

template<class T>
using Tropical_Min_Matrix = Semiring_Matrix<Extended_Algebra<T>, semiring_ops::op_min<Extended_Algebra<T>>, Extended_Algebra<T>::inf, semiring_ops::op_add<Extended_Algebra<T>>, Extended_Algebra<T>(0)>;

template<class T>
using Tropical_Max_Matrix = Semiring_Matrix<Extended_Algebra<T>, semiring_ops::op_max<Extended_Algebra<T>>, -Extended_Algebra<T>::inf, semiring_ops::op_add<Extended_Algebra<T>>, Extended_Algebra<T>(0)>;
