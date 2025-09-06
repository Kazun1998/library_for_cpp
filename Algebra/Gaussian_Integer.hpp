#pragma once

#include"../template/template.hpp"

template<typename R>
class Gaussian_Integer {
    public:
    R re, im;

    constexpr Gaussian_Integer(R re, R im): re(re), im(im) {}
    constexpr Gaussian_Integer(R re): re(re), im(0) {}

    // マイナス元
    Gaussian_Integer operator-() const { return Gaussian_Integer(-re, -im); }

    // 加法
    Gaussian_Integer& operator+=(const Gaussian_Integer &b){
        re += b.re;
        im += b.im;
        return *this;
    }

    friend Gaussian_Integer operator+(const Gaussian_Integer &x, const Gaussian_Integer &y) { return Gaussian_Integer(x) += y; }

    // 減法
    Gaussian_Integer& operator-=(const Gaussian_Integer &b){
        re -= b.re;
        im -= b.im;
        return *this;
    }

    friend Gaussian_Integer operator-(const Gaussian_Integer &x, const Gaussian_Integer &y) { return Gaussian_Integer(x) -= y; }

    // 乗法
    Gaussian_Integer& operator*=(const Gaussian_Integer &b){
        tie (re, im) = make_pair(re * b.re - im * b.im, re * b.im + im * b.re);
        return *this;
    }

    friend Gaussian_Integer operator*(const Gaussian_Integer &x, const Gaussian_Integer &y) { return Gaussian_Integer(x) *= y; }

    // 除法
    Gaussian_Integer& operator/=(const Gaussian_Integer &b){
        R n = b.norm();
        R x = round(re * b.re + im * b.im, n);
        R y = round(im * b.re - re * b.im, n);
        re = x;
        im = y;
        return *this;
    }

    friend Gaussian_Integer operator/(const Gaussian_Integer &x, const Gaussian_Integer &y) { return Gaussian_Integer(x) /= y; }

    // 剰余
    Gaussian_Integer& operator%=(const Gaussian_Integer &b){
        Gaussian_Integer a(re, im);
        auto q = a / b;
        auto r = a - b * q;
        re = r.re;
        im = r.im;
        return *this;
    }

    friend Gaussian_Integer operator%(const Gaussian_Integer &x, const Gaussian_Integer &y) { return Gaussian_Integer(x) %= y; }

    // 共役
    Gaussian_Integer conjugate() const { return Gaussian_Integer(re, -im); }

    // ノルム
    R norm() const { return re * re + im * im; }

    // 入力
    friend istream &operator>>(istream &is, Gaussian_Integer &a) {
        is >> a.re >> a.im;
        return is;
    }

    // 出力
    friend ostream &operator<<(ostream &os, const Gaussian_Integer &x) { return os << x.re << "+" << x.im << "i"; }

    // ゼロ?
    bool is_zero() const { return re == 0 && im == 0; }
};

template<typename R>
Gaussian_Integer<R> gcd(Gaussian_Integer<R> alpha, Gaussian_Integer<R> beta) {
    while(!beta.is_zero()) {
        tie(alpha, beta) = make_pair(beta, alpha % beta);
    }

    return alpha;
}