---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/original/Fraction.test.cpp
    title: verify/original/Fraction.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Algebra/Fraction.hpp\"\n\n#include <concepts>\n#include\
    \ <numeric>\n\ntemplate<std::integral T>\nclass Fraction {\n    public:\n    //\
    \ num: \u5206\u5B50, den: \u5206\u6BCD\n    T num, den;\n\n    constexpr Fraction(T\
    \ num = 0): num(num), den(1) {}\n    constexpr Fraction(T num, T den): num(num),\
    \ den(den) { normalize(); }\n\n    constexpr void normalize() {\n        if (den\
    \ < 0) { num = -num; den = -den; }\n        T g = std::gcd(num, den);\n      \
    \  num /= g;\n        den /= g;\n    }\n\n    constexpr Fraction operator-() const\
    \ { return Fraction(-num, den); }\n\n    constexpr Fraction& operator+=(const\
    \ Fraction &rhs) {\n        T g = std::gcd(den, rhs.den);\n        num = num *\
    \ (rhs.den / g) + rhs.num * (den / g);\n        den = den / g * rhs.den;\n   \
    \     normalize();\n        return *this;\n    }\n\n    constexpr Fraction& operator-=(const\
    \ Fraction &rhs) {\n        T g = std::gcd(den, rhs.den);\n        num = num *\
    \ (rhs.den / g) - rhs.num * (den / g);\n        den = den / g * rhs.den;\n   \
    \     normalize();\n        return *this;\n    }\n\n    constexpr Fraction& operator*=(const\
    \ Fraction &rhs) {\n        T g1 = std::gcd(num, rhs.den);\n        T g2 = std::gcd(den,\
    \ rhs.num);\n        num = (num / g1) * (rhs.num / g2);\n        den = (den /\
    \ g2) * (rhs.den / g1);\n        normalize();\n        return *this;\n    }\n\n\
    \    constexpr Fraction& operator/=(const Fraction &rhs) {\n        T g1 = std::gcd(num,\
    \ rhs.num);\n        T g2 = std::gcd(den, rhs.den);\n        num = (num / g1)\
    \ * (rhs.den / g2);\n        den = (den / g2) * (rhs.num / g1);\n        normalize();\n\
    \        return *this;\n    }\n\n    friend constexpr Fraction operator+(const\
    \ Fraction &lhs, const Fraction &rhs) { return Fraction(lhs) += rhs; }\n    friend\
    \ constexpr Fraction operator-(const Fraction &lhs, const Fraction &rhs) { return\
    \ Fraction(lhs) -= rhs; }\n    friend constexpr Fraction operator*(const Fraction\
    \ &lhs, const Fraction &rhs) { return Fraction(lhs) *= rhs; }\n    friend constexpr\
    \ Fraction operator/(const Fraction &lhs, const Fraction &rhs) { return Fraction(lhs)\
    \ /= rhs; }\n\n    friend constexpr bool operator==(const Fraction &lhs, const\
    \ Fraction &rhs) { return lhs.num == rhs.num && lhs.den == rhs.den; }\n    friend\
    \ constexpr bool operator!=(const Fraction &lhs, const Fraction &rhs) { return\
    \ !(lhs == rhs); }\n    friend constexpr bool operator<(const Fraction &lhs, const\
    \ Fraction &rhs) { return lhs.num * rhs.den < rhs.num * lhs.den; }\n    friend\
    \ constexpr bool operator>(const Fraction &lhs, const Fraction &rhs) { return\
    \ rhs < lhs; }\n    friend constexpr bool operator<=(const Fraction &lhs, const\
    \ Fraction &rhs) { return !(rhs < lhs); }\n    friend constexpr bool operator>=(const\
    \ Fraction &lhs, const Fraction &rhs) { return !(lhs < rhs); }\n\n    constexpr\
    \ Fraction inv() const { return Fraction(den, num); }\n\n    constexpr double\
    \ to_double() const { return (double)num / den; }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, Fraction &f) { T n, d; is >> n >> d; f = Fraction(n, d); return is; }\n\
    \    friend std::ostream &operator<<(std::ostream &os, const Fraction &f) { return\
    \ os << f.num << \" \" << f.den; }\n};\n\ntemplate<std::integral T>\nconstexpr\
    \ Fraction<T> abs(const Fraction<T> &f) {\n    return Fraction<T>(f.num < 0 ?\
    \ -f.num : f.num, f.den);\n}\n\ntemplate<std::integral T>\nconstexpr Fraction<T>\
    \ pow(const Fraction<T> &f, long long n) {\n    if (n < 0) return pow(f.inv(),\
    \ -n);\n    Fraction<T> res(1), e(f);\n    while (n > 0) {\n        if (n & 1)\
    \ res *= e;\n        e *= e;\n        n >>= 1;\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n#include <concepts>\n#include <numeric>\n\ntemplate<std::integral\
    \ T>\nclass Fraction {\n    public:\n    // num: \u5206\u5B50, den: \u5206\u6BCD\
    \n    T num, den;\n\n    constexpr Fraction(T num = 0): num(num), den(1) {}\n\
    \    constexpr Fraction(T num, T den): num(num), den(den) { normalize(); }\n\n\
    \    constexpr void normalize() {\n        if (den < 0) { num = -num; den = -den;\
    \ }\n        T g = std::gcd(num, den);\n        num /= g;\n        den /= g;\n\
    \    }\n\n    constexpr Fraction operator-() const { return Fraction(-num, den);\
    \ }\n\n    constexpr Fraction& operator+=(const Fraction &rhs) {\n        T g\
    \ = std::gcd(den, rhs.den);\n        num = num * (rhs.den / g) + rhs.num * (den\
    \ / g);\n        den = den / g * rhs.den;\n        normalize();\n        return\
    \ *this;\n    }\n\n    constexpr Fraction& operator-=(const Fraction &rhs) {\n\
    \        T g = std::gcd(den, rhs.den);\n        num = num * (rhs.den / g) - rhs.num\
    \ * (den / g);\n        den = den / g * rhs.den;\n        normalize();\n     \
    \   return *this;\n    }\n\n    constexpr Fraction& operator*=(const Fraction\
    \ &rhs) {\n        T g1 = std::gcd(num, rhs.den);\n        T g2 = std::gcd(den,\
    \ rhs.num);\n        num = (num / g1) * (rhs.num / g2);\n        den = (den /\
    \ g2) * (rhs.den / g1);\n        normalize();\n        return *this;\n    }\n\n\
    \    constexpr Fraction& operator/=(const Fraction &rhs) {\n        T g1 = std::gcd(num,\
    \ rhs.num);\n        T g2 = std::gcd(den, rhs.den);\n        num = (num / g1)\
    \ * (rhs.den / g2);\n        den = (den / g2) * (rhs.num / g1);\n        normalize();\n\
    \        return *this;\n    }\n\n    friend constexpr Fraction operator+(const\
    \ Fraction &lhs, const Fraction &rhs) { return Fraction(lhs) += rhs; }\n    friend\
    \ constexpr Fraction operator-(const Fraction &lhs, const Fraction &rhs) { return\
    \ Fraction(lhs) -= rhs; }\n    friend constexpr Fraction operator*(const Fraction\
    \ &lhs, const Fraction &rhs) { return Fraction(lhs) *= rhs; }\n    friend constexpr\
    \ Fraction operator/(const Fraction &lhs, const Fraction &rhs) { return Fraction(lhs)\
    \ /= rhs; }\n\n    friend constexpr bool operator==(const Fraction &lhs, const\
    \ Fraction &rhs) { return lhs.num == rhs.num && lhs.den == rhs.den; }\n    friend\
    \ constexpr bool operator!=(const Fraction &lhs, const Fraction &rhs) { return\
    \ !(lhs == rhs); }\n    friend constexpr bool operator<(const Fraction &lhs, const\
    \ Fraction &rhs) { return lhs.num * rhs.den < rhs.num * lhs.den; }\n    friend\
    \ constexpr bool operator>(const Fraction &lhs, const Fraction &rhs) { return\
    \ rhs < lhs; }\n    friend constexpr bool operator<=(const Fraction &lhs, const\
    \ Fraction &rhs) { return !(rhs < lhs); }\n    friend constexpr bool operator>=(const\
    \ Fraction &lhs, const Fraction &rhs) { return !(lhs < rhs); }\n\n    constexpr\
    \ Fraction inv() const { return Fraction(den, num); }\n\n    constexpr double\
    \ to_double() const { return (double)num / den; }\n\n    friend std::istream &operator>>(std::istream\
    \ &is, Fraction &f) { T n, d; is >> n >> d; f = Fraction(n, d); return is; }\n\
    \    friend std::ostream &operator<<(std::ostream &os, const Fraction &f) { return\
    \ os << f.num << \" \" << f.den; }\n};\n\ntemplate<std::integral T>\nconstexpr\
    \ Fraction<T> abs(const Fraction<T> &f) {\n    return Fraction<T>(f.num < 0 ?\
    \ -f.num : f.num, f.den);\n}\n\ntemplate<std::integral T>\nconstexpr Fraction<T>\
    \ pow(const Fraction<T> &f, long long n) {\n    if (n < 0) return pow(f.inv(),\
    \ -n);\n    Fraction<T> res(1), e(f);\n    while (n > 0) {\n        if (n & 1)\
    \ res *= e;\n        e *= e;\n        n >>= 1;\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Algebra/Fraction.hpp
  requiredBy: []
  timestamp: '2026-02-15 15:30:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/original/Fraction.test.cpp
documentation_of: Algebra/Fraction.hpp
layout: document
redirect_from:
- /library/Algebra/Fraction.hpp
- /library/Algebra/Fraction.hpp.html
title: Algebra/Fraction.hpp
---
