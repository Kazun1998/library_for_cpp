#pragma once

#include"Modulo_Polynomial.hpp"
#include"Numeric_Theory_Translation.hpp"

template<const ll Mod>
class Fast_Polynominal_Series : public Modulo_Polynomial<Mod> {
    private:
    using mint = modint<Mod>;

    protected:
    static Numeric_Theory_Translation<Mod> calculator;

    public:
    Fast_Polynominal_Series(vector<mint> _poly, int _precision) : Modulo_Polynomial<Mod>(_poly, _precision) {}

    Fast_Polynominal_Series() = default;
    Fast_Polynominal_Series(vector<mint> _poly) : Fast_Polynominal_Series(_poly, _poly.size()) {}
    Fast_Polynominal_Series(int _precision) : Fast_Polynominal_Series({}, _precision) {}

    // 加算
    Fast_Polynominal_Series& operator+=(const Fast_Polynominal_Series &B) {
        this->poly.resize(max(this->poly.size(), B.poly.size()));
        for (int i = 0; i < B.poly.size(); i++) {
            this->poly[i] += B.poly[i];
        }
        this->precision = min(this->precision, B.precision);
        this->reduce();
        return *this;
    }

    friend Fast_Polynominal_Series<Mod> operator+(const Fast_Polynominal_Series<Mod> &lhs, const Fast_Polynominal_Series<Mod> &rhs) {
        return Fast_Polynominal_Series<Mod>(lhs) += rhs; 
    }

    // 減算
    Fast_Polynominal_Series& operator-=(const Fast_Polynominal_Series &B) {
        this->poly.resize(max(this->poly.size(), B.poly.size()));
        for (int i = 0; i < B.poly.size(); i++) {
            this->poly[i] -= B.poly[i];
        }
        this->precision = min(this->precision, B.precision);
        this->reduce();
        return *this;
    }

    friend Fast_Polynominal_Series<Mod> operator-(const Fast_Polynominal_Series<Mod> &lhs, const Fast_Polynominal_Series<Mod> &rhs) {
        return Fast_Polynominal_Series<Mod>(lhs) -= rhs; 
    }

    // 積
    Fast_Polynominal_Series& operator*=(const Fast_Polynominal_Series &P) {
        auto tmp = calculator.convolution(this->poly, P.poly);

        this->poly = tmp;
        this->precision = min(this->precision, P.precision);
        this->resize(this->precision);
        this->reduce();
        return *this;
    }

    friend Fast_Polynominal_Series operator*(const Fast_Polynominal_Series &lhs, const Fast_Polynominal_Series &rhs) { return Fast_Polynominal_Series(lhs) *= rhs; }

    // (mod X^d) における逆元を求める
    // d = -1 のときは, d = precision になる.
    Fast_Polynominal_Series inverse(int d = -1) {
        vector<mint> p = calculator.inverse(this->poly, (d == -1) ? this->precision : min(d, this->precision));
        return {p, this->precision};
    }

    // 除算
    Fast_Polynominal_Series& operator/=(const Fast_Polynominal_Series &P) {
        vector<mint> inv = calculator.inverse(P.poly, P.precision);
        this->poly = calculator.convolution(this->poly, inv);
        this->precision = min(this->precision, P.precision);
        this->resize(this->precision);
        this->reduce();
        return *this;
    }

    friend Fast_Polynominal_Series operator/(const Fast_Polynominal_Series &lhs, const Fast_Polynominal_Series &rhs) { return Fast_Polynominal_Series(lhs) /= rhs; }

    // 多項式としての除算
    Fast_Polynominal_Series div(Fast_Polynominal_Series &B) {
        this->reduce(); B.reduce();

        int n = this->poly.size(), m = B.poly.size();

        if (n < m) { return Fast_Polynominal_Series({0}); }

        vector<mint> a_rev(this->poly), b_rev(B.poly);
        reverse(a_rev.begin(), a_rev.end());
        reverse(b_rev.begin(), b_rev.end());

        vector<mint> c = calculator.convolution(a_rev, calculator.inverse(b_rev, n));
        c.resize(n - m + 1);
        reverse(c.begin(), c.end());
        return Fast_Polynominal_Series(c, n);
    }

    Fast_Polynominal_Series& operator%=(Fast_Polynominal_Series &B) {
        Fast_Polynominal_Series Q = this->div(B);
        this->poly = ((*this) - B * Q).poly;
        return *this;
    }

    friend Fast_Polynominal_Series operator%(Fast_Polynominal_Series &lhs, Fast_Polynominal_Series &rhs) { return Fast_Polynominal_Series(lhs) %= rhs; }
};

template<const ll Mod>
Numeric_Theory_Translation<Mod> Fast_Polynominal_Series<Mod>::calculator = Numeric_Theory_Translation<Mod>();

template<const ll Mod>
pair<Fast_Polynominal_Series<Mod>, Fast_Polynominal_Series<Mod>> divmod(Fast_Polynominal_Series<Mod> &A, Fast_Polynominal_Series<Mod> &B) {
    Fast_Polynominal_Series Q = A.div(B);
    Fast_Polynominal_Series R = A - B * Q;
    return {Q, R};
}
