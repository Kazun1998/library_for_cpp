---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Algebra/Gaussian_Integer.hpp
    title: Algebra/Gaussian_Integer.hpp
  - icon: ':warning:'
    path: Integer/Divisors.hpp
    title: Integer/Divisors.hpp
  - icon: ':heavy_check_mark:'
    path: Integer/Quotients.hpp
    title: Integer/Quotients.hpp
  - icon: ':heavy_check_mark:'
    path: Math/Floor_Linear_Sum.hpp
    title: Math/Floor_Linear_Sum.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
    title: verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
    title: verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Floor_Linear_Sum.test.cpp
    title: verify/yosupo_library_checker/number_theory/Floor_Linear_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Gaussian_Integers.test.cpp
    title: verify/yosupo_library_checker/number_theory/Gaussian_Integers.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Min_of_Mod_of_Linear.test.cpp
    title: verify/yosupo_library_checker/number_theory/Min_of_Mod_of_Linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/macro.hpp\"\n\n// \u30DE\u30AF\u30ED\u306E\u5B9A\
    \u7FA9\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n#define unless(cond) if (!(cond))\n\n// \u30AA\u30FC\u30D0\u30FC\
    \u30ED\u30FC\u30C9\u30DE\u30AF\u30ED\n#define overload2(_1, _2, name, ...) name\n\
    #define overload3(_1, _2, _3, name, ...) name\n#define overload4(_1, _2, _3, _4,\
    \ name, ...) name\n#define overload5(_1, _2, _3, _4, _5, name, ...) name\n\n//\
    \ \u7E70\u308A\u8FD4\u3057\u7CFB\n#define rep1(n) for (ll i = 0; i < n; i++)\n\
    #define rep2(i, n) for (ll i = 0; i < n; i++)\n#define rep3(i, a, b) for (ll i\
    \ = a; i < b; i++)\n#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)\n#define\
    \ rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\n#define\
    \ foreach1(x, a) for (auto &&x: a)\n#define foreach2(x, y, a) for (auto &&[x,\
    \ y]: a)\n#define foreach3(x, y, z, a) for (auto &&[x, y, z]: a)\n#define foreach4(x,\
    \ y, z, w, a) for (auto &&[x, y, z, w]: a)\n#define foreach(...) overload5(__VA_ARGS__,\
    \ foreach4, foreach3, foreach2, foreach1)(__VA_ARGS__)\n"
  code: "#pragma once\n\n// \u30DE\u30AF\u30ED\u306E\u5B9A\u7FA9\n#define all(x) x.begin(),\
    \ x.end()\n#define len(x) ll(x.size())\n#define elif else if\n#define unless(cond)\
    \ if (!(cond))\n\n// \u30AA\u30FC\u30D0\u30FC\u30ED\u30FC\u30C9\u30DE\u30AF\u30ED\
    \n#define overload2(_1, _2, name, ...) name\n#define overload3(_1, _2, _3, name,\
    \ ...) name\n#define overload4(_1, _2, _3, _4, name, ...) name\n#define overload5(_1,\
    \ _2, _3, _4, _5, name, ...) name\n\n// \u7E70\u308A\u8FD4\u3057\u7CFB\n#define\
    \ rep1(n) for (ll i = 0; i < n; i++)\n#define rep2(i, n) for (ll i = 0; i < n;\
    \ i++)\n#define rep3(i, a, b) for (ll i = a; i < b; i++)\n#define rep4(i, a, b,\
    \ c) for (ll i = a; i < b; i += c)\n#define rep(...) overload4(__VA_ARGS__, rep4,\
    \ rep3, rep2, rep1)(__VA_ARGS__)\n\n#define foreach1(x, a) for (auto &&x: a)\n\
    #define foreach2(x, y, a) for (auto &&[x, y]: a)\n#define foreach3(x, y, z, a)\
    \ for (auto &&[x, y, z]: a)\n#define foreach4(x, y, z, w, a) for (auto &&[x, y,\
    \ z, w]: a)\n#define foreach(...) overload5(__VA_ARGS__, foreach4, foreach3, foreach2,\
    \ foreach1)(__VA_ARGS__)\n"
  dependsOn: []
  isVerificationFile: false
  path: template/macro.hpp
  requiredBy:
  - Algebra/Gaussian_Integer.hpp
  - Math/Floor_Linear_Sum.hpp
  - Integer/Divisors.hpp
  - Integer/Quotients.hpp
  - template/template.hpp
  timestamp: '2025-08-17 13:03:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
  - verify/yosupo_library_checker/number_theory/Gaussian_Integers.test.cpp
  - verify/yosupo_library_checker/number_theory/Min_of_Mod_of_Linear.test.cpp
  - verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
  - verify/yosupo_library_checker/number_theory/Floor_Linear_Sum.test.cpp
documentation_of: template/macro.hpp
layout: document
redirect_from:
- /library/template/macro.hpp
- /library/template/macro.hpp.html
title: template/macro.hpp
---
