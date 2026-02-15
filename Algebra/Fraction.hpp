#pragma once

#include <concepts>
#include <numeric>

template<std::integral T>
class Fraction {
    public:
    // num: 分子, den: 分母
    T num, den;

    constexpr Fraction(T num = 0): num(num), den(1) {}
    constexpr Fraction(T num, T den): num(num), den(den) { normalize(); }

    constexpr void normalize() {
        if (den < 0) { num = -num; den = -den; }
        T g = std::gcd(num, den);
        num /= g;
        den /= g;
    }

    constexpr Fraction operator-() const { return Fraction(-num, den); }

    constexpr Fraction& operator+=(const Fraction &rhs) {
        T g = std::gcd(den, rhs.den);
        num = num * (rhs.den / g) + rhs.num * (den / g);
        den = den / g * rhs.den;
        normalize();
        return *this;
    }

    constexpr Fraction& operator-=(const Fraction &rhs) {
        T g = std::gcd(den, rhs.den);
        num = num * (rhs.den / g) - rhs.num * (den / g);
        den = den / g * rhs.den;
        normalize();
        return *this;
    }

    constexpr Fraction& operator*=(const Fraction &rhs) {
        T g1 = std::gcd(num, rhs.den);
        T g2 = std::gcd(den, rhs.num);
        num = (num / g1) * (rhs.num / g2);
        den = (den / g2) * (rhs.den / g1);
        normalize();
        return *this;
    }

    constexpr Fraction& operator/=(const Fraction &rhs) {
        T g1 = std::gcd(num, rhs.num);
        T g2 = std::gcd(den, rhs.den);
        num = (num / g1) * (rhs.den / g2);
        den = (den / g2) * (rhs.num / g1);
        normalize();
        return *this;
    }

    friend constexpr Fraction operator+(const Fraction &lhs, const Fraction &rhs) { return Fraction(lhs) += rhs; }
    friend constexpr Fraction operator-(const Fraction &lhs, const Fraction &rhs) { return Fraction(lhs) -= rhs; }
    friend constexpr Fraction operator*(const Fraction &lhs, const Fraction &rhs) { return Fraction(lhs) *= rhs; }
    friend constexpr Fraction operator/(const Fraction &lhs, const Fraction &rhs) { return Fraction(lhs) /= rhs; }

    friend constexpr bool operator==(const Fraction &lhs, const Fraction &rhs) { return lhs.num == rhs.num && lhs.den == rhs.den; }
    friend constexpr bool operator!=(const Fraction &lhs, const Fraction &rhs) { return !(lhs == rhs); }
    friend constexpr bool operator<(const Fraction &lhs, const Fraction &rhs) { return lhs.num * rhs.den < rhs.num * lhs.den; }
    friend constexpr bool operator>(const Fraction &lhs, const Fraction &rhs) { return rhs < lhs; }
    friend constexpr bool operator<=(const Fraction &lhs, const Fraction &rhs) { return !(rhs < lhs); }
    friend constexpr bool operator>=(const Fraction &lhs, const Fraction &rhs) { return !(lhs < rhs); }

    constexpr Fraction inv() const { return Fraction(den, num); }

    constexpr double to_double() const { return (double)num / den; }

    friend std::istream &operator>>(std::istream &is, Fraction &f) { T n, d; is >> n >> d; f = Fraction(n, d); return is; }
    friend std::ostream &operator<<(std::ostream &os, const Fraction &f) { return os << f.num << " " << f.den; }
};

template<std::integral T>
constexpr Fraction<T> abs(const Fraction<T> &f) {
    return Fraction<T>(f.num < 0 ? -f.num : f.num, f.den);
}

template<std::integral T>
constexpr Fraction<T> pow(const Fraction<T> &f, long long n) {
    if (n < 0) return pow(f.inv(), -n);
    Fraction<T> res(1), e(f);
    while (n > 0) {
        if (n & 1) res *= e;
        e *= e;
        n >>= 1;
    }
    return res;
}
