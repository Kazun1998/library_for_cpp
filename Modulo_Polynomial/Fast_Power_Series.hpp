#pragma once

#include"Modulo_Polynomial.hpp"
#include"Numeric_Theory_Translation.hpp"

template<const ll Mod>
class Fast_Polynominal_Series : public Modulo_Polynomial<Mod> {
    private:
    using mint = modint<Mod>;

    protected:
    static auto calculator =  Numeric_Theory_Translation<Mod>();

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
};
