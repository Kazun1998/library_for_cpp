#pragma once

// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Algebra/Gaussian_Integer.hpp

#include"../template/template.hpp"

template<typename R>
class Gaussian_Integer {
    public:
    R re, im;

    constexpr Gaussian_Integer(R re, R im): re(re), im(im) {}
    constexpr Gaussian_Integer(R re): re(re), im(0) {}

    // マイナス元
    constexpr Gaussian_Integer operator-() const { return Gaussian_Integer(-re, -im); }

    // 加法
    constexpr Gaussian_Integer& operator+=(const Gaussian_Integer &b){
        re += b.re;
        im += b.im;
        return *this;
    }

    friend constexpr Gaussian_Integer operator+(const Gaussian_Integer &x, const Gaussian_Integer &y) { return Gaussian_Integer(x) += y; }

    // 減法
    constexpr Gaussian_Integer& operator-=(const Gaussian_Integer &b){
        re -= b.re;
        im -= b.im;
        return *this;
    }

    friend constexpr Gaussian_Integer operator-(const Gaussian_Integer &x, const Gaussian_Integer &y) { return Gaussian_Integer(x) -= y; }

    // 乗法
    constexpr Gaussian_Integer& operator*=(const Gaussian_Integer &b){
        tie (re, im) = make_pair(re * b.re - im * b.im, re * b.im + im * b.re);
        return *this;
    }

    friend constexpr Gaussian_Integer operator*(const Gaussian_Integer &x, const Gaussian_Integer &y) { return Gaussian_Integer(x) *= y; }

    // 除法
    Gaussian_Integer& operator/=(const Gaussian_Integer &b){
        if (b.is_zero()) { throw invalid_argument("Gaussian_Integer: division by zero"); }

        const R n = b.norm();
        const R x = round(re * b.re + im * b.im, n);
        const R y = round(im * b.re - re * b.im, n);
        re = x;
        im = y;
        return *this;
    }

    friend Gaussian_Integer operator/(const Gaussian_Integer &x, const Gaussian_Integer &y) { return Gaussian_Integer(x) /= y; }

    // 剰余
    Gaussian_Integer& operator%=(const Gaussian_Integer &b){
        const Gaussian_Integer a(re, im);
        const Gaussian_Integer q = a / b;
        const Gaussian_Integer r = a - b * q;
        re = r.re;
        im = r.im;
        return *this;
    }

    friend Gaussian_Integer operator%(const Gaussian_Integer &x, const Gaussian_Integer &y) { return Gaussian_Integer(x) %= y; }

    // 比較
    friend constexpr bool operator==(const Gaussian_Integer &x, const Gaussian_Integer &y) { return x.re == y.re && x.im == y.im; }

    // 共役
    constexpr Gaussian_Integer conjugate() const { return Gaussian_Integer(re, -im); }

    // ノルム
    constexpr R norm() const { return re * re + im * im; }

    // 入力
    friend istream &operator>>(istream &is, Gaussian_Integer &a) {
        is >> a.re >> a.im;
        return is;
    }

    // 出力
    friend ostream &operator<<(ostream &os, const Gaussian_Integer &x) { return os << x.re << " " << x.im; }

    // ゼロ?
    constexpr bool is_zero() const { return re == 0 && im == 0; }
};

template<typename R>
Gaussian_Integer<R> gcd(Gaussian_Integer<R> alpha, Gaussian_Integer<R> beta) {
    until(beta.is_zero()) {
        tie(alpha, beta) = make_pair(beta, alpha % beta);
    }

    return alpha;
}
