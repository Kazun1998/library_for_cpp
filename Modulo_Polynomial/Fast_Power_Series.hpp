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
        this->resize(this->precision);
        this->reduce();
        return *this;
    }

    friend Fast_Power_Series operator*(const Fast_Power_Series &lhs, const Fast_Power_Series &rhs) { return Fast_Power_Series(lhs) *= rhs; }

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
        this->resize(this->precision);
        this->reduce();
        return *this;
    }

    friend Fast_Power_Series operator/(const Fast_Power_Series &lhs, const Fast_Power_Series &rhs) { return Fast_Power_Series(lhs) /= rhs; }

    // 多項式としての除算
    Fast_Power_Series div(Fast_Power_Series &B) {
        this->reduce(); B.reduce();

        int n = this->poly.size(), m = B.poly.size();

        if (n < m) { return Fast_Power_Series({0}); }

        vector<mint> a_rev(this->poly), b_rev(B.poly);
        reverse(a_rev.begin(), a_rev.end());
        reverse(b_rev.begin(), b_rev.end());

        vector<mint> c = calculator.convolution(a_rev, calculator.inverse(b_rev, n));
        c.resize(n - m + 1);
        reverse(c.begin(), c.end());
        return Fast_Power_Series(c, n);
    }

    Fast_Power_Series& operator%=(Fast_Power_Series &B) {
        Fast_Power_Series Q = this->div(B);
        this->poly = ((*this) - B * Q).poly;
        return *this;
    }

    friend Fast_Power_Series operator%(Fast_Power_Series &lhs, Fast_Power_Series &rhs) { return Fast_Power_Series(lhs) %= rhs; }
};

template<typename mint>
Numeric_Theory_Translation<mint> Fast_Power_Series<mint>::calculator = Numeric_Theory_Translation<mint>();

template<typename mint>
pair<Fast_Power_Series<mint>, Fast_Power_Series<mint>> divmod(Fast_Power_Series<mint> &A, Fast_Power_Series<mint> &B) {
    Fast_Power_Series Q = A.div(B);
    Fast_Power_Series R = A - B * Q;
    return {Q, R};
}
