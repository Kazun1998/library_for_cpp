---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.test.cpp
    title: verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/linear_algebra/Determinant.test.cpp
    title: verify/yosupo_library_checker/linear_algebra/Determinant.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/linear_algebra/Inverse.test.cpp
    title: verify/yosupo_library_checker/linear_algebra/Inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/linear_algebra/Matrix_Product.test.cpp
    title: verify/yosupo_library_checker/linear_algebra/Matrix_Product.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/linear_algebra/Power_Matrix.test.cpp
    title: verify/yosupo_library_checker/linear_algebra/Power_Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/linear_algebra/Rank.test.cpp
    title: verify/yosupo_library_checker/linear_algebra/Rank.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Algebra/modint.hpp\"\n\ntemplate<int mod>\nclass modint{\n\
    \    public:\n    int64_t x;\n\n    public:\n    // \u521D\u671F\u5316\n    constexpr\
    \ modint(): x(0) {}\n    constexpr modint(int64_t a): x((a % mod + mod) % mod)\
    \ {}\n\n    // \u30DE\u30A4\u30CA\u30B9\u5143\n    modint operator-() const {\
    \ return modint(-x); }\n\n    // \u52A0\u6CD5\n    modint& operator+=(const modint\
    \ &b){\n        if ((x += b.x) >= mod) x -= mod;\n        return *this;\n    }\n\
    \n    friend modint operator+(const modint &x, const modint &y) { return modint(x)\
    \ += y; }\n\n    // \u6E1B\u6CD5\n    modint& operator-=(const modint &b){\n \
    \       if ((x += mod - b.x) >= mod) x -= mod;\n        return *this;\n    }\n\
    \n    friend modint operator-(const modint &x, const modint &y) { return modint(x)\
    \ -= y; }\n\n    // \u4E57\u6CD5\n    modint& operator*=(const modint &b){\n \
    \       (x *= b.x) %= mod;\n        return *this;\n    }\n\n    friend modint\
    \ operator*(const modint &x, const modint &y) { return modint(x) *= y; }\n\n \
    \   // \u9664\u6CD5\n    modint& operator/=(const modint &b){ return (*this) *=\
    \ b.inverse(); }\n\n    friend modint operator/(const modint &x, const modint\
    \ &y) { return modint(x) /= y; }\n\n    modint inverse() const {\n        int64_t\
    \ s = 1, t = 0;\n        int64_t a = x, b = mod;\n\n        while (b > 0) {\n\
    \            int64_t q = a / b;\n\n            a -= q * b; swap(a, b);\n     \
    \       s -= q * t; swap(s, t);\n        }\n\n        assert (a == 1);\n\n   \
    \     return modint(s);\n    }\n\n    // \u6BD4\u8F03\n    friend bool operator==(const\
    \ modint &a, const modint &b) { return (a.x == b.x); }\n    friend bool operator!=(const\
    \ modint &a, const modint &b) { return (a.x != b.x); }\n\n    // \u5165\u529B\n\
    \    friend istream &operator>>(istream &is, modint &a) {\n        is >> a.x;\n\
    \        a.x = (a.x % mod + mod) % mod;\n        return is;\n    }\n\n    // \u51FA\
    \u529B\n    friend ostream &operator<<(ostream &os, const modint &a) { return\
    \ os << a.x; }\n};\n\ntemplate<int Mod>\nmodint<Mod> pow(modint<Mod> x, long long\
    \ n) {\n    if (n < 0) { return pow(x, -n).inverse(); }\n\n    auto res = modint<Mod>(1);\n\
    \    for (; n; n >>= 1) {\n        if (n & 1) { res *= x; }\n        x *= x;\n\
    \    }\n\n    return res;\n}\n"
  code: "#pragma once\n\ntemplate<int mod>\nclass modint{\n    public:\n    int64_t\
    \ x;\n\n    public:\n    // \u521D\u671F\u5316\n    constexpr modint(): x(0) {}\n\
    \    constexpr modint(int64_t a): x((a % mod + mod) % mod) {}\n\n    // \u30DE\
    \u30A4\u30CA\u30B9\u5143\n    modint operator-() const { return modint(-x); }\n\
    \n    // \u52A0\u6CD5\n    modint& operator+=(const modint &b){\n        if ((x\
    \ += b.x) >= mod) x -= mod;\n        return *this;\n    }\n\n    friend modint\
    \ operator+(const modint &x, const modint &y) { return modint(x) += y; }\n\n \
    \   // \u6E1B\u6CD5\n    modint& operator-=(const modint &b){\n        if ((x\
    \ += mod - b.x) >= mod) x -= mod;\n        return *this;\n    }\n\n    friend\
    \ modint operator-(const modint &x, const modint &y) { return modint(x) -= y;\
    \ }\n\n    // \u4E57\u6CD5\n    modint& operator*=(const modint &b){\n       \
    \ (x *= b.x) %= mod;\n        return *this;\n    }\n\n    friend modint operator*(const\
    \ modint &x, const modint &y) { return modint(x) *= y; }\n\n    // \u9664\u6CD5\
    \n    modint& operator/=(const modint &b){ return (*this) *= b.inverse(); }\n\n\
    \    friend modint operator/(const modint &x, const modint &y) { return modint(x)\
    \ /= y; }\n\n    modint inverse() const {\n        int64_t s = 1, t = 0;\n   \
    \     int64_t a = x, b = mod;\n\n        while (b > 0) {\n            int64_t\
    \ q = a / b;\n\n            a -= q * b; swap(a, b);\n            s -= q * t; swap(s,\
    \ t);\n        }\n\n        assert (a == 1);\n\n        return modint(s);\n  \
    \  }\n\n    // \u6BD4\u8F03\n    friend bool operator==(const modint &a, const\
    \ modint &b) { return (a.x == b.x); }\n    friend bool operator!=(const modint\
    \ &a, const modint &b) { return (a.x != b.x); }\n\n    // \u5165\u529B\n    friend\
    \ istream &operator>>(istream &is, modint &a) {\n        is >> a.x;\n        a.x\
    \ = (a.x % mod + mod) % mod;\n        return is;\n    }\n\n    // \u51FA\u529B\
    \n    friend ostream &operator<<(ostream &os, const modint &a) { return os <<\
    \ a.x; }\n};\n\ntemplate<int Mod>\nmodint<Mod> pow(modint<Mod> x, long long n)\
    \ {\n    if (n < 0) { return pow(x, -n).inverse(); }\n\n    auto res = modint<Mod>(1);\n\
    \    for (; n; n >>= 1) {\n        if (n & 1) { res *= x; }\n        x *= x;\n\
    \    }\n\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Algebra/modint.hpp
  requiredBy: []
  timestamp: '2025-09-24 00:56:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.test.cpp
  - verify/yosupo_library_checker/linear_algebra/Power_Matrix.test.cpp
  - verify/yosupo_library_checker/linear_algebra/Determinant.test.cpp
  - verify/yosupo_library_checker/linear_algebra/Matrix_Product.test.cpp
  - verify/yosupo_library_checker/linear_algebra/Rank.test.cpp
  - verify/yosupo_library_checker/linear_algebra/Inverse.test.cpp
documentation_of: Algebra/modint.hpp
layout: document
redirect_from:
- /library/Algebra/modint.hpp
- /library/Algebra/modint.hpp.html
title: Algebra/modint.hpp
---
