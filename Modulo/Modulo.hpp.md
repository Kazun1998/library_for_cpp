---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Modulo/Discrete_Log.hpp
    title: Modulo/Discrete_Log.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Modulo/Modulo.hpp\"\n\nnamespace Modulo {\n    class DifferentModulus\
    \ : public exception {\n      public: // public\u306B\u6307\u5B9A\n      const\
    \ char* what() const noexcept override { return \"\u7570\u306A\u308B\u6CD5\u540C\
    \u58EB\u306E\u56DB\u5247\u6F14\u7B97\u3067\u3059\"; }\n    };\n\n    struct Modulo\
    \ {\n        long long a, n;\n\n        public:\n        // \u521D\u671F\u5316\
    \n        Modulo(): a(0), n(1) {}\n        Modulo(long long a, long long n): a((a\
    \ % n + n) % n), n(n) {}\n\n        // \u30DE\u30A4\u30CA\u30B9\u5143\n      \
    \  Modulo operator-() const { return Modulo(-a, n); }\n\n        // \u52A0\u6CD5\
    \n        Modulo& operator+=(const Modulo &y) {\n            if (n != y.n) { throw\
    \ DifferentModulus(); }\n    \n            if ((a += y.a) >= n) a -= n;\n    \
    \        return *this;\n        }\n\n        Modulo& operator+=(const long long\
    \ &y) { return (*this) += Modulo(y, n); }\n\n        friend Modulo operator+(const\
    \ Modulo &x, const Modulo &y) { return Modulo(x) += y ; }\n        friend Modulo\
    \ operator+(const Modulo &x, const long long &a) { return x + Modulo(a, x.n);\
    \ }\n        friend Modulo operator+(const long long &a, const Modulo &x) { return\
    \ Modulo(a, x.n) + x; }\n\n        // \u6E1B\u6CD5\n        Modulo& operator-=(const\
    \ Modulo &y) {\n            if (n != y.n) { throw DifferentModulus(); }\n    \
    \        if ((a += (n - y.a)) >= n) a -= n;\n            return *this;\n     \
    \   }\n\n        Modulo& operator-=(const long long &y) { return (*this) -= Modulo(y,\
    \ n); }\n\n        friend Modulo operator-(const Modulo &x, const Modulo &y) {\
    \ return Modulo(x) -= y; }\n        friend Modulo operator-(const Modulo &x, const\
    \ long long &a) { return x - Modulo(a, x.n); }\n        friend Modulo operator-(const\
    \ long long &a, const Modulo &x) { return Modulo(a, x.n) - x; }\n\n        //\
    \ \u4E57\u6CD5\n        Modulo& operator*=(const Modulo &y) {\n            if\
    \ (n != y.n) { throw DifferentModulus(); }\n            (a *= y.a) %= n;\n   \
    \         return *this;\n        }\n\n        Modulo& operator*=(const long long\
    \ &y){return (*this) *= Modulo(y, n); }\n\n        friend Modulo operator*(const\
    \ Modulo &x, const Modulo &y) { return Modulo(x) *= y; }\n        friend Modulo\
    \ operator*(const Modulo &x, const long long &a) { return x * Modulo(a,x.n); }\n\
    \        friend Modulo operator*(const long long &a, const Modulo &x) { return\
    \ Modulo(a, x.n) * x; }\n\n        // \u9664\u6CD5\n        Modulo& operator/=(const\
    \ Modulo &y){\n            if (n != y.n) { throw DifferentModulus(); }\n     \
    \       return (*this) *= y.inverse();\n        }\n\n        Modulo& operator/=(const\
    \ long long &y) {return (*this ) /= Modulo(y, n); }\n\n        friend Modulo operator/(const\
    \ Modulo &x, const Modulo &y) { return Modulo(x) /= y; }\n        friend Modulo\
    \ operator/(const Modulo &x, const long long &a) { return x / Modulo(a, x.n);\
    \ }\n        friend Modulo operator/(const long long &a, const Modulo &x) { return\
    \ Modulo(a, x.n) / x; }\n\n        // \u9000\u5316\n        Modulo& degenerate(const\
    \ int m){\n            a %= m; n = m;\n            return *this;\n        }\n\n\
    \        // \u30E2\u30B8\u30E5\u30E9\u30FC\u9006\u5143\n        bool invertible()\
    \ const {\n            long long x = a, y = n;\n            while (y) { swap(x\
    \ = x % y, y); }\n            return x == 1;\n        }\n\n        Modulo inverse()\
    \ const{\n            long long s = 1, t = 0;\n            long long x = a, y\
    \ = n;\n            while (y){\n                auto q = x / y;\n            \
    \    swap(x -= q * y, y);\n                swap(s -= q * t, t);\n            }\n\
    \n            return Modulo(s, n);\n        }\n\n        // \u6BD4\u8F03\n   \
    \     friend bool operator==(const Modulo &x, const Modulo &y) { return x.a==y.a;\
    \ }\n        friend bool operator==(const Modulo &x, const long long &a) { return\
    \ (x.a - a) % x.n == 0; }\n        friend bool operator==(const long long &a,\
    \ const Modulo &x) { return (a - x.a) % x.n == 0; }\n\n        friend bool operator!=(const\
    \ Modulo &x, const Modulo &y) { return x.a != y.a; }\n        friend bool operator!=(const\
    \ Modulo &x, const long long &a) { return (x.a - a)% x.n != 0; }\n        friend\
    \ bool operator!=(const long long &a, const Modulo &x) { return (a - x.a)% x.n\
    \ != 0; }\n\n        // \u5165\u529B\n        friend istream &operator>>(istream\
    \ &is, Modulo &x) {\n            long long b, m;\n            is >> b >> m;\n\
    \            x = Modulo(b, m);\n            return (is);\n        }\n\n      \
    \  // \u51FA\u529B\n        friend ostream &operator<<(ostream &os, const Modulo\
    \ &x) { return os << x.a << \" (mod \" << x.n << \")\"; }\n    };\n\n    Modulo\
    \ pow(Modulo x, long long n) {\n        if (n < 0) { return pow(x, -n).inverse();\
    \ }\n\n        auto res = Modulo(1, x.n);\n        for (; n; n >>= 1) {\n    \
    \        if (n & 1) { res *= x; }\n            x *= x;\n        }\n\n        return\
    \ res;\n    }\n}\n"
  code: "#pragma once\n\nnamespace Modulo {\n    class DifferentModulus : public exception\
    \ {\n      public: // public\u306B\u6307\u5B9A\n      const char* what() const\
    \ noexcept override { return \"\u7570\u306A\u308B\u6CD5\u540C\u58EB\u306E\u56DB\
    \u5247\u6F14\u7B97\u3067\u3059\"; }\n    };\n\n    struct Modulo {\n        long\
    \ long a, n;\n\n        public:\n        // \u521D\u671F\u5316\n        Modulo():\
    \ a(0), n(1) {}\n        Modulo(long long a, long long n): a((a % n + n) % n),\
    \ n(n) {}\n\n        // \u30DE\u30A4\u30CA\u30B9\u5143\n        Modulo operator-()\
    \ const { return Modulo(-a, n); }\n\n        // \u52A0\u6CD5\n        Modulo&\
    \ operator+=(const Modulo &y) {\n            if (n != y.n) { throw DifferentModulus();\
    \ }\n    \n            if ((a += y.a) >= n) a -= n;\n            return *this;\n\
    \        }\n\n        Modulo& operator+=(const long long &y) { return (*this)\
    \ += Modulo(y, n); }\n\n        friend Modulo operator+(const Modulo &x, const\
    \ Modulo &y) { return Modulo(x) += y ; }\n        friend Modulo operator+(const\
    \ Modulo &x, const long long &a) { return x + Modulo(a, x.n); }\n        friend\
    \ Modulo operator+(const long long &a, const Modulo &x) { return Modulo(a, x.n)\
    \ + x; }\n\n        // \u6E1B\u6CD5\n        Modulo& operator-=(const Modulo &y)\
    \ {\n            if (n != y.n) { throw DifferentModulus(); }\n            if ((a\
    \ += (n - y.a)) >= n) a -= n;\n            return *this;\n        }\n\n      \
    \  Modulo& operator-=(const long long &y) { return (*this) -= Modulo(y, n); }\n\
    \n        friend Modulo operator-(const Modulo &x, const Modulo &y) { return Modulo(x)\
    \ -= y; }\n        friend Modulo operator-(const Modulo &x, const long long &a)\
    \ { return x - Modulo(a, x.n); }\n        friend Modulo operator-(const long long\
    \ &a, const Modulo &x) { return Modulo(a, x.n) - x; }\n\n        // \u4E57\u6CD5\
    \n        Modulo& operator*=(const Modulo &y) {\n            if (n != y.n) { throw\
    \ DifferentModulus(); }\n            (a *= y.a) %= n;\n            return *this;\n\
    \        }\n\n        Modulo& operator*=(const long long &y){return (*this) *=\
    \ Modulo(y, n); }\n\n        friend Modulo operator*(const Modulo &x, const Modulo\
    \ &y) { return Modulo(x) *= y; }\n        friend Modulo operator*(const Modulo\
    \ &x, const long long &a) { return x * Modulo(a,x.n); }\n        friend Modulo\
    \ operator*(const long long &a, const Modulo &x) { return Modulo(a, x.n) * x;\
    \ }\n\n        // \u9664\u6CD5\n        Modulo& operator/=(const Modulo &y){\n\
    \            if (n != y.n) { throw DifferentModulus(); }\n            return (*this)\
    \ *= y.inverse();\n        }\n\n        Modulo& operator/=(const long long &y)\
    \ {return (*this ) /= Modulo(y, n); }\n\n        friend Modulo operator/(const\
    \ Modulo &x, const Modulo &y) { return Modulo(x) /= y; }\n        friend Modulo\
    \ operator/(const Modulo &x, const long long &a) { return x / Modulo(a, x.n);\
    \ }\n        friend Modulo operator/(const long long &a, const Modulo &x) { return\
    \ Modulo(a, x.n) / x; }\n\n        // \u9000\u5316\n        Modulo& degenerate(const\
    \ int m){\n            a %= m; n = m;\n            return *this;\n        }\n\n\
    \        // \u30E2\u30B8\u30E5\u30E9\u30FC\u9006\u5143\n        bool invertible()\
    \ const {\n            long long x = a, y = n;\n            while (y) { swap(x\
    \ = x % y, y); }\n            return x == 1;\n        }\n\n        Modulo inverse()\
    \ const{\n            long long s = 1, t = 0;\n            long long x = a, y\
    \ = n;\n            while (y){\n                auto q = x / y;\n            \
    \    swap(x -= q * y, y);\n                swap(s -= q * t, t);\n            }\n\
    \n            return Modulo(s, n);\n        }\n\n        // \u6BD4\u8F03\n   \
    \     friend bool operator==(const Modulo &x, const Modulo &y) { return x.a==y.a;\
    \ }\n        friend bool operator==(const Modulo &x, const long long &a) { return\
    \ (x.a - a) % x.n == 0; }\n        friend bool operator==(const long long &a,\
    \ const Modulo &x) { return (a - x.a) % x.n == 0; }\n\n        friend bool operator!=(const\
    \ Modulo &x, const Modulo &y) { return x.a != y.a; }\n        friend bool operator!=(const\
    \ Modulo &x, const long long &a) { return (x.a - a)% x.n != 0; }\n        friend\
    \ bool operator!=(const long long &a, const Modulo &x) { return (a - x.a)% x.n\
    \ != 0; }\n\n        // \u5165\u529B\n        friend istream &operator>>(istream\
    \ &is, Modulo &x) {\n            long long b, m;\n            is >> b >> m;\n\
    \            x = Modulo(b, m);\n            return (is);\n        }\n\n      \
    \  // \u51FA\u529B\n        friend ostream &operator<<(ostream &os, const Modulo\
    \ &x) { return os << x.a << \" (mod \" << x.n << \")\"; }\n    };\n\n    Modulo\
    \ pow(Modulo x, long long n) {\n        if (n < 0) { return pow(x, -n).inverse();\
    \ }\n\n        auto res = Modulo(1, x.n);\n        for (; n; n >>= 1) {\n    \
    \        if (n & 1) { res *= x; }\n            x *= x;\n        }\n\n        return\
    \ res;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Modulo/Modulo.hpp
  requiredBy:
  - Modulo/Discrete_Log.hpp
  timestamp: '2025-08-16 19:50:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Modulo/Modulo.hpp
layout: document
redirect_from:
- /library/Modulo/Modulo.hpp
- /library/Modulo/Modulo.hpp.html
title: Modulo/Modulo.hpp
---
