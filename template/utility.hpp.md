---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
    path: verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
    title: verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Floor_Linear_Sum.test.cpp
    title: verify/yosupo_library_checker/number_theory/Floor_Linear_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Min_of_Mod_of_Linear.test.cpp
    title: verify/yosupo_library_checker/number_theory/Min_of_Mod_of_Linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/utility.hpp\"\n\nusing ll = long long;\n\n// a\
    \ \u2190 max(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\u308C\
    \u305F\u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T, typename U>\n\
    inline bool chmax(T &a, const U b){\n    return (a < b ? a = b, 1: 0);\n}\n\n\
    // a \u2190 min(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\
    \u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T, typename\
    \ U>\ninline bool chmin(T &a, const U b){\n    return (a > b ? a = b, 1: 0);\n\
    }\n"
  code: "#pragma once\n\nusing ll = long long;\n\n// a \u2190 max(a, b) \u3092\u5B9F\
    \u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\u308C\u305F\u3089, \u8FD4\u308A\
    \u5024\u304C true.\ntemplate<typename T, typename U>\ninline bool chmax(T &a,\
    \ const U b){\n    return (a < b ? a = b, 1: 0);\n}\n\n// a \u2190 min(a, b) \u3092\
    \u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\u308C\u305F\u3089, \u8FD4\
    \u308A\u5024\u304C true.\ntemplate<typename T, typename U>\ninline bool chmin(T\
    \ &a, const U b){\n    return (a > b ? a = b, 1: 0);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template/utility.hpp
  requiredBy:
  - Math/Floor_Linear_Sum.hpp
  - Integer/Quotients.hpp
  - template/template.hpp
  timestamp: '2025-08-17 13:03:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/number_theory/Min_of_Mod_of_Linear.test.cpp
  - verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
  - verify/yosupo_library_checker/number_theory/Floor_Linear_Sum.test.cpp
documentation_of: template/utility.hpp
layout: document
redirect_from:
- /library/template/utility.hpp
- /library/template/utility.hpp.html
title: template/utility.hpp
---
