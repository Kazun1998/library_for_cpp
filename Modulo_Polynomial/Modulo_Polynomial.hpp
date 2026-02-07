#pragma once

#include"../template/template.hpp"
#include"../Algebra/modint.hpp"

template<typename mint>
class Modulo_Polynomial {
    public:
    int precision = 0;

    public:
    vector<mint> poly;
    Modulo_Polynomial(vector<mint> _poly, int precision): precision(precision) {
        if (_poly.size() > precision) { _poly.resize(precision); }
        poly = _poly;
    }

    Modulo_Polynomial() = default;
    Modulo_Polynomial(vector<mint> poly) : Modulo_Polynomial(poly, poly.size()) {}
    Modulo_Polynomial(int precision) : Modulo_Polynomial({}, precision) {}

    // 演算子の定義
    public:
    // マイナス元
    Modulo_Polynomial operator-() const {
        Modulo_Polynomial res(*this);
        for (auto &a : res.poly) { a = -a; }
        return res;
    }

    // 加法
    Modulo_Polynomial& operator+=(const Modulo_Polynomial &P){
        if (size() < P.size()) { resize(P.size()); }

        for (int i = 0; i < (int) P.poly.size(); i++) { poly[i] += P[i]; }
        reduce();

        return *this;
    }

    Modulo_Polynomial& operator+=(const mint &a){
        if (poly.empty()) { resize(1); }
        poly[0] += a;
        reduce();

        return *this;
    }

    friend Modulo_Polynomial operator+(const Modulo_Polynomial &lhs, const Modulo_Polynomial &rhs) { return Modulo_Polynomial(lhs) += rhs; }
    Modulo_Polynomial operator+(const mint &a) const { return Modulo_Polynomial(*this) += a; }

    // 減法
    Modulo_Polynomial& operator-=(const Modulo_Polynomial &P){
        if (size() < P.size()) { resize(P.size()); }

        for (int i = 0; i < (int) P.poly.size(); i++) { poly[i] -= P[i]; }
        reduce();

        return *this;
    }

    Modulo_Polynomial& operator-=(const mint &a){
        if (poly.empty()) { resize(1); }
        poly[0] -= a;
        reduce();

        return *this;
    }

    friend Modulo_Polynomial operator-(const Modulo_Polynomial &lhs, const Modulo_Polynomial &rhs) { return Modulo_Polynomial(lhs) -= rhs; }
    Modulo_Polynomial operator-(const mint &a) const { return Modulo_Polynomial(*this) -= a; }

    // スカラー倍
    Modulo_Polynomial& operator*=(const mint &a){
        for (int i = 0; i < size(); i++) { poly[i] *= a; }
        reduce();
        return *this;
    }

    Modulo_Polynomial operator*(const mint &a) const {return Modulo_Polynomial(*this) *= a;}

    friend Modulo_Polynomial operator*(const mint &a, const Modulo_Polynomial &P) {
        Modulo_Polynomial res(P);
        res *= a;
        return res;
    }

    // 積
    Modulo_Polynomial& operator*=(const Modulo_Polynomial &P) {
        int r = min({(int) (poly.size() + P.poly.size()) - 1, precision, P.precision});
        vector<mint> A(r);
        for (int i = 0; i < size(); i++) {
            for (int j = 0; j < P.size(); j++) {
                if (i + j < r) { A[i + j] += poly[i] * P.poly[j]; }
            }
        }

        poly = A;
        precision = min(precision, P.precision);
        return *this;
    }

    friend Modulo_Polynomial operator*(const Modulo_Polynomial &lhs, const Modulo_Polynomial &rhs) { return Modulo_Polynomial(lhs) *= rhs; }

    // スカラー除算
    Modulo_Polynomial& operator/=(const mint &a) {
        mint a_inv = a.inverse();
        for (int i = 0; i < size(); i++) { poly[i] *= a_inv; }
        return *this;
    }

    Modulo_Polynomial operator/(const mint &a) const { return Modulo_Polynomial(*this) /= a; }

    // index
    mint operator[] (int k) const { return (k < poly.size()) ? poly[k] : 0; }

    // istream
    friend istream &operator>>(istream &is, Modulo_Polynomial &P) {
        P.poly.resize(P.precision);
        for (int i = 0; i < (int)P.precision; i++) { is >> P.poly[i]; }
        return (is);
    }

    // ostream
    friend ostream &operator<<(ostream &os, const Modulo_Polynomial &P){
        for (int i = 0; i < (int)P.poly.size(); i++){
            os << (i ? " " : "") << P[i];
        }
        return os;
    }

    // poly で保持しているベクトルの長さを size にする.
    // size = -1 のときは, size = precision に変換される.
    void resize(int size = -1) {
        if (size == -1) { size = this -> precision; }
        size = min(size, this -> precision);
        poly.resize(size);
    }

    void update_precision(int precision) {
        this->precision = precision;
        if (poly.size() > precision) { poly.resize(precision); }
    }

    bool is_zero() const {
        for (auto &a: poly) { unless(a.is_zero()) {return false;} }
        return true;
    }

    // 高次に連なる 0 を削除する
    void reduce() {
        while (!poly.empty() && poly.back().is_zero()) { poly.pop_back(); }
    }

    // 保持している多項式の乗法の項の長さを求める
    int size() const { return poly.size(); }

    // 次数を求める (ゼロ多項式の時は -1)
    int degree() const {
        for (int d = size() - 1; d >= 0; d--) {
            unless(poly[d].is_zero()) { return d; }
        }
        return -1;
    }

    // 位数 (係数が非ゼロである次数の最小値)
    int order() const {
        for (int d = 0; d < size(); d++) {
            unless(poly[d].is_zero()) { return d; }
        }
        return -1;
    }
};
