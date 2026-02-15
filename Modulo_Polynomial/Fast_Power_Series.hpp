#pragma once

#include"Modulo_Polynomial.hpp"
#include"Numeric_Theory_Translation.hpp"

template<typename mint>
class Fast_Power_Series : public Modulo_Polynomial<mint> {
    protected:
    static Numeric_Theory_Translation<mint> calculator;

    public:
    Fast_Power_Series(vector<mint> _poly, int _precision) : Modulo_Polynomial<mint>(_poly, _precision) {}

    Fast_Power_Series() = default;
    Fast_Power_Series(vector<mint> _poly) : Fast_Power_Series(_poly, _poly.size()) {}
    Fast_Power_Series(int _precision) : Fast_Power_Series({}, _precision) {}

    // 加算
    Fast_Power_Series& operator+=(const Fast_Power_Series &B) {
        this->poly.resize(max(this->poly.size(), B.poly.size()));
        for (int i = 0; i < B.poly.size(); i++) {
            this->poly[i] += B.poly[i];
        }
        this->precision = min(this->precision, B.precision);
        this->weak_resize();
        this->reduce();
        return *this;
    }

    friend Fast_Power_Series<mint> operator+(const Fast_Power_Series<mint> &lhs, const Fast_Power_Series<mint> &rhs) {
        return Fast_Power_Series<mint>(lhs) += rhs; 
    }

    // 減算
    Fast_Power_Series& operator-=(const Fast_Power_Series &B) {
        this->poly.resize(max(this->poly.size(), B.poly.size()));
        for (int i = 0; i < B.poly.size(); i++) {
            this->poly[i] -= B.poly[i];
        }
        this->precision = min(this->precision, B.precision);
        this->weak_resize();
        this->reduce();
        return *this;
    }

    friend Fast_Power_Series<mint> operator-(const Fast_Power_Series<mint> &lhs, const Fast_Power_Series<mint> &rhs) {
        return Fast_Power_Series<mint>(lhs) -= rhs; 
    }

    // スカラー倍
    Fast_Power_Series& operator*=(const mint &a){
        for (int i = 0; i < this->size(); i++) { this->poly[i] *= a; }
        this->reduce();
        return *this;
    }

    Fast_Power_Series operator*(const mint &a) const {return Fast_Power_Series(*this) *= a; }

    friend Fast_Power_Series operator*(const mint &a, const Fast_Power_Series &P) { return Fast_Power_Series(P) *= a; }

    friend Fast_Power_Series operator*(const ll &a, const Fast_Power_Series &P) { return mint(a) * P; }

    // 積
    Fast_Power_Series& operator*=(const Fast_Power_Series &P) {
        auto tmp = calculator.convolution(this->poly, P.poly);

        this->poly = tmp;
        this->precision = min(this->precision, P.precision);

        this->weak_resize();
        this->reduce();
        return *this;
    }

    friend Fast_Power_Series operator*(const Fast_Power_Series &lhs, const Fast_Power_Series &rhs) { return Fast_Power_Series(lhs) *= rhs; }

    // 多項式としての積. 精度は結果の次数に合わせて自動拡張される.
    Fast_Power_Series mul_poly(const Fast_Power_Series &P) const {
        auto tmp = calculator.convolution(this->poly, P.poly);
        return Fast_Power_Series(tmp, tmp.size());
    }

    // (mod X^d) における逆元を求める
    // d = -1 のときは, d = precision になる.
    Fast_Power_Series inverse(int d = -1) {
        vector<mint> p = calculator.inverse(this->poly, (d == -1) ? this->precision : min(d, this->precision));
        return {p, this->precision};
    }

    // 除算
    Fast_Power_Series& operator/=(const Fast_Power_Series &P) {
        vector<mint> inv = calculator.inverse(P.poly, P.precision);
        this->poly = calculator.convolution(this->poly, inv);
        this->precision = min(this->precision, P.precision);
        this->weak_resize();
        this->reduce();
        return *this;
    }

    friend Fast_Power_Series operator/(const Fast_Power_Series &lhs, const Fast_Power_Series &rhs) { return Fast_Power_Series(lhs) /= rhs; }

    // 多項式としての除算
    Fast_Power_Series div(const Fast_Power_Series &B) {
        this->reduce(); // B.reduce(); const なので変更しない

        int n = this->poly.size(), m = B.poly.size();

        if (n < m) { return Fast_Power_Series({0}); }

        vector<mint> a_rev(this->poly), b_rev(B.poly);
        reverse(a_rev.begin(), a_rev.end());
        reverse(b_rev.begin(), b_rev.end());

        int k = n - m + 1;
        if (a_rev.size() > k) { a_rev.resize(k); }
        if (b_rev.size() > k) { b_rev.resize(k); }
        vector<mint> c = calculator.convolution(a_rev, calculator.inverse(b_rev, k));
        c.resize(k);
        reverse(c.begin(), c.end());
        return Fast_Power_Series(c, n);
    }

    Fast_Power_Series& operator%=(const Fast_Power_Series &B) {
        Fast_Power_Series Q = this->div(B);
        vector<mint> product = calculator.convolution(B.poly, Q.poly);
        if (this->poly.size() < product.size()) { this->poly.resize(product.size()); }
        for (int i = 0; i < product.size(); i++) { this->poly[i] -= product[i]; }
        this->reduce();
        return *this;
    }

    friend Fast_Power_Series operator%(const Fast_Power_Series &lhs, const Fast_Power_Series &rhs) { return Fast_Power_Series(lhs) %= rhs; }

    pair<Fast_Power_Series, Fast_Power_Series> divmod(const Fast_Power_Series &B) {
        Fast_Power_Series Q = this->div(B);
        vector<mint> product = calculator.convolution(B.poly, Q.poly);

        Fast_Power_Series R(*this);
        if (R.poly.size() < product.size()) { R.poly.resize(product.size()); }
        for (int i = 0; i < product.size(); i++) { R.poly[i] -= product[i]; }
        R.reduce();
        return {Q, R};
    }
};

template<typename mint>
Numeric_Theory_Translation<mint> Fast_Power_Series<mint>::calculator = Numeric_Theory_Translation<mint>();

template<typename mint>
pair<Fast_Power_Series<mint>, Fast_Power_Series<mint>> divmod(Fast_Power_Series<mint> &A, const Fast_Power_Series<mint> &B) {
    return A.divmod(B);
}
