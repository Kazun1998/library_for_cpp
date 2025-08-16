---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Modulo/Discrete_Log.hpp
    title: Modulo/Discrete_Log.hpp
  - icon: ':heavy_check_mark:'
    path: Modulo/Modulo.hpp
    title: Modulo/Modulo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"verify/yosupo_library_checker/number_theory/Discrete_Log.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\
    \n#include<bits/stdc++.h>\n\nusing namespace std;\n\n#line 2 \"Modulo/Modulo.hpp\"\
    \n\nnamespace Modulo {\n    class DifferentModulus : public exception {\n    \
    \  public: // public\u306B\u6307\u5B9A\n      const char* what() const noexcept\
    \ override { return \"\u7570\u306A\u308B\u6CD5\u540C\u58EB\u306E\u56DB\u5247\u6F14\
    \u7B97\u3067\u3059\"; }\n    };\n\n    struct Modulo {\n        long long a, n;\n\
    \n        public:\n        // \u521D\u671F\u5316\n        Modulo(): a(0), n(1)\
    \ {}\n        Modulo(long long a, long long n): a((a % n + n) % n), n(n) {}\n\n\
    \        // \u30DE\u30A4\u30CA\u30B9\u5143\n        Modulo operator-() const {\
    \ return Modulo(-a, n); }\n\n        // \u52A0\u6CD5\n        Modulo& operator+=(const\
    \ Modulo &y) {\n            if (n != y.n) { throw DifferentModulus(); }\n    \n\
    \            if ((a += y.a) >= n) a -= n;\n            return *this;\n       \
    \ }\n\n        Modulo& operator+=(const long long &y) { return (*this) += Modulo(y,\
    \ n); }\n\n        friend Modulo operator+(const Modulo &x, const Modulo &y) {\
    \ return Modulo(x) += y ; }\n        friend Modulo operator+(const Modulo &x,\
    \ const long long &a) { return x + Modulo(a, x.n); }\n        friend Modulo operator+(const\
    \ long long &a, const Modulo &x) { return Modulo(a, x.n) + x; }\n\n        //\
    \ \u6E1B\u6CD5\n        Modulo& operator-=(const Modulo &y) {\n            if\
    \ (n != y.n) { throw DifferentModulus(); }\n            if ((a += (n - y.a)) >=\
    \ n) a -= n;\n            return *this;\n        }\n\n        Modulo& operator-=(const\
    \ long long &y) { return (*this) -= Modulo(y, n); }\n\n        friend Modulo operator-(const\
    \ Modulo &x, const Modulo &y) { return Modulo(x) -= y; }\n        friend Modulo\
    \ operator-(const Modulo &x, const long long &a) { return x - Modulo(a, x.n);\
    \ }\n        friend Modulo operator-(const long long &a, const Modulo &x) { return\
    \ Modulo(a, x.n) - x; }\n\n        // \u4E57\u6CD5\n        Modulo& operator*=(const\
    \ Modulo &y) {\n            if (n != y.n) { throw DifferentModulus(); }\n    \
    \        (a *= y.a) %= n;\n            return *this;\n        }\n\n        Modulo&\
    \ operator*=(const long long &y){return (*this) *= Modulo(y, n); }\n\n       \
    \ friend Modulo operator*(const Modulo &x, const Modulo &y) { return Modulo(x)\
    \ *= y; }\n        friend Modulo operator*(const Modulo &x, const long long &a)\
    \ { return x * Modulo(a,x.n); }\n        friend Modulo operator*(const long long\
    \ &a, const Modulo &x) { return Modulo(a, x.n) * x; }\n\n        // \u9664\u6CD5\
    \n        Modulo& operator/=(const Modulo &y){\n            if (n != y.n) { throw\
    \ DifferentModulus(); }\n            return (*this) *= y.inverse();\n        }\n\
    \n        Modulo& operator/=(const long long &y) {return (*this ) /= Modulo(y,\
    \ n); }\n\n        friend Modulo operator/(const Modulo &x, const Modulo &y) {\
    \ return Modulo(x) /= y; }\n        friend Modulo operator/(const Modulo &x, const\
    \ long long &a) { return x / Modulo(a, x.n); }\n        friend Modulo operator/(const\
    \ long long &a, const Modulo &x) { return Modulo(a, x.n) / x; }\n\n        //\
    \ \u9000\u5316\n        Modulo& degenerate(const int m){\n            a %= m;\
    \ n = m;\n            return *this;\n        }\n\n        // \u30E2\u30B8\u30E5\
    \u30E9\u30FC\u9006\u5143\n        bool invertible() const {\n            long\
    \ long x = a, y = n;\n            while (y) { swap(x = x % y, y); }\n        \
    \    return x == 1;\n        }\n\n        Modulo inverse() const{\n          \
    \  long long s = 1, t = 0;\n            long long x = a, y = n;\n            while\
    \ (y){\n                auto q = x / y;\n                swap(x -= q * y, y);\n\
    \                swap(s -= q * t, t);\n            }\n\n            return Modulo(s,\
    \ n);\n        }\n\n        // \u6BD4\u8F03\n        friend bool operator==(const\
    \ Modulo &x, const Modulo &y) { return x.a==y.a; }\n        friend bool operator==(const\
    \ Modulo &x, const long long &a) { return (x.a - a) % x.n == 0; }\n        friend\
    \ bool operator==(const long long &a, const Modulo &x) { return (a - x.a) % x.n\
    \ == 0; }\n\n        friend bool operator!=(const Modulo &x, const Modulo &y)\
    \ { return x.a != y.a; }\n        friend bool operator!=(const Modulo &x, const\
    \ long long &a) { return (x.a - a)% x.n != 0; }\n        friend bool operator!=(const\
    \ long long &a, const Modulo &x) { return (a - x.a)% x.n != 0; }\n\n        //\
    \ \u5165\u529B\n        friend istream &operator>>(istream &is, Modulo &x) {\n\
    \            long long b, m;\n            is >> b >> m;\n            x = Modulo(b,\
    \ m);\n            return (is);\n        }\n\n        // \u51FA\u529B\n      \
    \  friend ostream &operator<<(ostream &os, const Modulo &x) { return os << x.a\
    \ << \" (mod \" << x.n << \")\"; }\n    };\n\n    Modulo pow(Modulo x, long long\
    \ n) {\n        if (n < 0) { return pow(x, -n).inverse(); }\n\n        auto res\
    \ = Modulo(1, x.n);\n        for (; n; n >>= 1) {\n            if (n & 1) { res\
    \ *= x; }\n            x *= x;\n        }\n\n        return res;\n    }\n}\n#line\
    \ 2 \"Modulo/Discrete_Log.hpp\"\n\nnamespace Modulo {\n    long long Discrete_Log\
    \ (Modulo &X, Modulo &Y, long long not_exist = -1) {\n        assert(X.n == Y.n);\n\
    \n        long long m = 0;\n        for (; m * m < X.n; m++) {}\n\n        auto\
    \ y = Modulo(Y);\n        unordered_set<long long> st;\n        for (int i = 0;\
    \ i < m; i++) {\n            y *= X;\n            st.insert(y.a);\n        }\n\
    \n        auto step = pow(X, m);\n        auto head = Modulo(1, X.n);\n      \
    \  int count = 0;\n\n        for (int k = 1; k <= m; k++) {\n            auto\
    \ tail = head;\n            head *= step;\n            if (!st.count(head.a))\
    \ { continue; }\n\n            auto body = tail;\n            for (long long n\
    \ = (k - 1) * m; n < k * m; n++) {\n                if (body == Y) { return n;\
    \ }\n\n                body *= X;\n            }\n\n            count++;\n\n \
    \           if (count == 2) { return not_exist; }\n        }\n\n        return\
    \ not_exist;\n    }\n}\n#line 8 \"verify/yosupo_library_checker/number_theory/Discrete_Log.test.cpp\"\
    \n\nint main() {\n  int T; cin >> T;\n  for (int t = 1; t <= T; t++) {\n    int\
    \ X, Y, M; cin >> X >> Y >> M;\n    auto A = Modulo::Modulo(X, M), B = Modulo::Modulo(Y,\
    \ M);\n\n    cout << Modulo::Discrete_Log(A, B) << endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include<bits/stdc++.h>\n\nusing namespace std;\n\n#include\"../../../Modulo/Discrete_Log.hpp\"\
    \n\nint main() {\n  int T; cin >> T;\n  for (int t = 1; t <= T; t++) {\n    int\
    \ X, Y, M; cin >> X >> Y >> M;\n    auto A = Modulo::Modulo(X, M), B = Modulo::Modulo(Y,\
    \ M);\n\n    cout << Modulo::Discrete_Log(A, B) << endl;\n  }\n}\n"
  dependsOn:
  - Modulo/Discrete_Log.hpp
  - Modulo/Modulo.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/number_theory/Discrete_Log.test.cpp
  requiredBy: []
  timestamp: '2025-08-17 00:06:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/number_theory/Discrete_Log.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/number_theory/Discrete_Log.test.cpp
- /verify/verify/yosupo_library_checker/number_theory/Discrete_Log.test.cpp.html
title: verify/yosupo_library_checker/number_theory/Discrete_Log.test.cpp
---
