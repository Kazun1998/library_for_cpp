#pragma once

#include"../template/template.hpp"

template<typename F>
class Field_Vector {
    private:
    vector<F> vec;

    public:
    Field_Vector(const vector<F> &_vec): vec(_vec) {};
    Field_Vector(const int n): vec(vector<F>(n, F(0))) {};

    // 次元を求める.
    inline int dimension () const { return vec.size(); }

    // 要素
    inline const F &operator[](int i) const { return vec[i]; }
    inline F &operator[](int i) { return vec[i]; }

    // 比較
    bool operator==(const Field_Vector &w) const {
        if (dimension () != w.dimension ()){ return false; }

        for (int i = 0; i < dimension (); i++) {
            unless((*this)[i] == w[i]) { return false;}
        }
        return true;
    }

    bool operator!=(const Field_Vector &w) const { return !((*this) == w); }

    // マイナス元
    Field_Vector operator-() const {
        Field_Vector v(dimension ());
        for (int i = 0; i < dimension (); i++){
            v[i] = -(*this)[i];
        }
        return v;
    }

    // 加法
    Field_Vector& operator+=(const Field_Vector &w) {
        assert (dimension () == w.dimension ());
        for (int i = 0; i < dimension (); i++){ (*this)[i] += w[i]; }
        return *this;
    }

    Field_Vector operator+(const Field_Vector &w) const { return Field_Vector(*this) += w; }

    // 減法
    Field_Vector& operator-=(const Field_Vector &w) {
        assert (dimension () == w.dimension ());
        for (int i = 0; i < dimension (); i++){ (*this)[i] -= w[i]; }
        return *this;
    }

    Field_Vector operator-(const Field_Vector &w) const { return Field_Vector(*this) -= w; }

    // スカラー倍
    Field_Vector& operator*=(const F a) {
        for (int i = 0; i < dimension (); i++){ (*this)[i] *= a; }
        return *this;
    }

    Field_Vector operator*(const F &a) const { return Field_Vector(*this) *= a; }

    Field_Vector& operator/=(const F a) {
        F a_inv = a.inverse();
        for (int i = 0; i < dimension (); i++){ (*this)[i] *= a_inv; }
        return *this;
    }

    Field_Vector operator/(const F &a) const { return Field_Vector(*this) /= a; }

    // zero?
    bool is_zero() const {
        for (int i = 0; i < dimension (); i++) {
            unless((*this)[i] == 0) { return false; }
        }
        return true;
    }

    // 入力
    friend istream &operator>>(istream &is, Field_Vector &v) {
        for (int i = 0; i < v.dimension (); i++) { is >> v[i]; }
        return is;
    }

    // 出力
    friend ostream &operator<<(ostream &os, const Field_Vector &v) {
        for (int i = 0; i < v.dimension (); i++) {
            os << (i ? " ": "") << v[i];
        }
        return os;
    }

    // 内積
    F inner(const Field_Vector<F> &w) const {
        F res = 0;
        for (int i = 0; i < dimension (); i++) { res += (*this)[i] * w[i]; }
        return res;
    }
};

template<typename F>
Field_Vector<F> operator* (const F &a, const Field_Vector<F> &v) { return v * a; }
