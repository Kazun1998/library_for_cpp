#pragma once

// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Modulo_Polynomial/Modulo_Polynomial.hpp

#include"../template/template.hpp"
#include"../Algebra/modint.hpp"

/// @brief 剰余環を係数とする多項式 (精度付き) の基底クラス. 保持・線形演算・添字・入出力を担う.
/// @tparam mint 係数の型
/// @tparam Derived CRTP の派生クラス. 演算の戻り値の型になる. 積・除算は Derived 側で定義する.
template<typename mint, typename Derived>
class Modulo_Polynomial {
    public:
    int precision = 0;

    public:
    vector<mint> poly;
    Modulo_Polynomial(vector<mint> _poly, int precision): precision(precision) {
        if ((int) _poly.size() > precision) { _poly.resize(precision); }
        poly = _poly;
    }

    Modulo_Polynomial() = default;
    Modulo_Polynomial(vector<mint> poly) : Modulo_Polynomial(poly, poly.size()) {}
    Modulo_Polynomial(int precision) : Modulo_Polynomial({}, precision) {}

    private:
    Derived& self() { return static_cast<Derived&>(*this); }
    const Derived& self() const { return static_cast<const Derived&>(*this); }

    // 演算子の定義
    public:
    // マイナス元
    Derived operator-() const {
        Derived res(self());
        for (auto &a : res.poly) { a = -a; }
        return res;
    }

    // 加法 (精度は小さい方に合わせる)
    Derived& operator+=(const Derived &P) {
        poly.resize(max(poly.size(), P.poly.size()));
        for (int i = 0; i < (int) P.poly.size(); i++) { poly[i] += P.poly[i]; }
        precision = min(precision, P.precision);
        weak_resize();
        reduce();
        return self();
    }

    Derived& operator+=(const mint &a) {
        if (poly.empty()) { resize(1); }
        unless (poly.empty()) { poly[0] += a; }
        reduce();
        return self();
    }

    friend Derived operator+(const Derived &lhs, const Derived &rhs) { return Derived(lhs) += rhs; }
    Derived operator+(const mint &a) const { return Derived(self()) += a; }

    // 減法 (精度は小さい方に合わせる)
    Derived& operator-=(const Derived &P) {
        poly.resize(max(poly.size(), P.poly.size()));
        for (int i = 0; i < (int) P.poly.size(); i++) { poly[i] -= P.poly[i]; }
        precision = min(precision, P.precision);
        weak_resize();
        reduce();
        return self();
    }

    Derived& operator-=(const mint &a) {
        if (poly.empty()) { resize(1); }
        unless (poly.empty()) { poly[0] -= a; }
        reduce();
        return self();
    }

    friend Derived operator-(const Derived &lhs, const Derived &rhs) { return Derived(lhs) -= rhs; }
    Derived operator-(const mint &a) const { return Derived(self()) -= a; }

    // スカラー倍
    Derived& operator*=(const mint &a) {
        for (int i = 0; i < size(); i++) { poly[i] *= a; }
        reduce();
        return self();
    }

    Derived operator*(const mint &a) const { return Derived(self()) *= a; }
    friend Derived operator*(const mint &a, const Derived &P) { return Derived(P) *= a; }

    // スカラー除算
    Derived& operator/=(const mint &a) {
        mint a_inv = a.inverse();
        for (int i = 0; i < size(); i++) { poly[i] *= a_inv; }
        return self();
    }

    Derived operator/(const mint &a) const { return Derived(self()) /= a; }

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

    /// @brief poly のサイズが size より大きい場合のみ, size に切り詰める.
    /// @param size 指定するサイズ. -1 の場合は precision を使用する.
    void weak_resize(int size = -1) {
        if (size == -1) { size = this->precision; }

        if (size >= this->poly.size()) return;

        resize(size);
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
