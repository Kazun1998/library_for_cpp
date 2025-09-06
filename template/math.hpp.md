---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Algebra/Gaussian_Integer.hpp
    title: Algebra/Gaussian_Integer.hpp
  - icon: ':heavy_check_mark:'
    path: Integer/Divisors.hpp
    title: Integer/Divisors.hpp
  - icon: ':heavy_check_mark:'
    path: Integer/Miller_Rabin_Primality.hpp
    title: Integer/Miller_Rabin_Primality.hpp
  - icon: ':heavy_check_mark:'
    path: Integer/Quotients.hpp
    title: Integer/Quotients.hpp
  - icon: ':heavy_check_mark:'
    path: Math/Floor_Linear_Sum.hpp
    title: Math/Floor_Linear_Sum.hpp
  - icon: ':heavy_check_mark:'
    path: Math/Two_SAT.hpp
    title: Math/Two_SAT.hpp
  - icon: ':heavy_check_mark:'
    path: Modulo/Discrete_Log.hpp
    title: Modulo/Discrete_Log.hpp
  - icon: ':heavy_check_mark:'
    path: Modulo/Modulo.hpp
    title: Modulo/Modulo.hpp
  - icon: ':heavy_check_mark:'
    path: Modulo/Order.hpp
    title: Modulo/Order.hpp
  - icon: ':heavy_check_mark:'
    path: Tree/Tree.hpp
    title: Tree/Tree.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.test.cpp
    title: verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
    title: verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Discrete_Log.test.cpp
    title: verify/yosupo_library_checker/number_theory/Discrete_Log.test.cpp
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
    path: verify/yosupo_library_checker/number_theory/Miller_Rabin_Primality_Test.test.cpp
    title: verify/yosupo_library_checker/number_theory/Miller_Rabin_Primality_Test.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Min_of_Mod_of_Linear.test.cpp
    title: verify/yosupo_library_checker/number_theory/Min_of_Mod_of_Linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/other/two_sat.test.cpp
    title: verify/yosupo_library_checker/other/two_sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/tree/Lowest_Common_Ancestor.test.cpp
    title: verify/yosupo_library_checker/tree/Lowest_Common_Ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/Modulo_Order.test.cpp
    title: verify/yukicoder/Modulo_Order.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/math.hpp\"\n\n// \u9664\u7B97\u306B\u95A2\u3059\
    \u308B\u95A2\u6570\n\n// floor(x / y) \u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\nT div_floor(T x, U y){ return (x > 0 ? x / y: (x - y + 1) /\
    \ y); }\n\n// ceil(x / y) \u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename\
    \ U>\nT div_ceil(T x, U y){ return (x > 0 ? (x + y - 1) / y: x / y) ;}\n\n// x\
    \ \u3092 y \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\nT mod(T x, U y){\n    T q = div_floor(x, y);\n    return x -\
    \ q * y ;\n}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u5546\u3068\u4F59\u308A\
    \u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename U>\npair<T, T> divmod(T\
    \ x, U y){\n    T q = div_floor(x, y);\n    return {q, x - q * y};\n}\n\n// \u56DB\
    \u6368\u4E94\u5165\u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename U>\n\
    T round(T x, U y){\n    T q, r;\n    tie (q, r) = divmod(x, y);\n    return (r\
    \ >= div_ceil(y, 2)) ? q + 1 : q;\n}\n\n// \u6307\u6570\u306B\u95A2\u3059\u308B\
    \u95A2\u6570\n\n// x \u306E y \u4E57\u3092\u6C42\u3081\u308B.\nll intpow(ll x,\
    \ ll y){\n    ll a = 1;\n    while (y){\n        if (y & 1) { a *= x; }\n    \
    \    x *= x;\n        y >>= 1;\n    }\n    return a;\n}\n\n// x \u306E y \u4E57\
    \u3092 z \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\nll modpow(ll\
    \ x, ll y, ll z){\n    ll a = 1;\n    while (y){\n        if (y & 1) { (a *= x)\
    \ %= z; }\n        (x *= x) %= z;\n        y >>= 1;\n    }\n    return a;\n}\n\
    \n// x \u306E y \u4E57\u3092 z \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\
    \u3081\u308B.\ntemplate<typename T, typename U>\nT modpow(T x, U y, T z) {\n \
    \   T a = 1;\n    while (y) {\n        if (y & 1) { (a *= x) %= z; }\n\n     \
    \   (x *= x) %= z;\n        y >>= 1;\n    }\n\n    return a;\n}\n\n// vector \u306E\
    \u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B.\nll sum(vector<ll> &X){\n\
    \    ll y = 0;\n    for (auto &&x: X) { y+=x; }\n    return y;\n}\n\n// vector\
    \ \u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T>\nT sum(vector<T> &X){\n    T y = T(0);\n    for (auto &&x: X) { y += x; }\n\
    \    return y;\n}\n"
  code: "#pragma once\n\n// \u9664\u7B97\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n//\
    \ floor(x / y) \u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT\
    \ div_floor(T x, U y){ return (x > 0 ? x / y: (x - y + 1) / y); }\n\n// ceil(x\
    \ / y) \u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT div_ceil(T\
    \ x, U y){ return (x > 0 ? (x + y - 1) / y: x / y) ;}\n\n// x \u3092 y \u3067\u5272\
    \u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename\
    \ U>\nT mod(T x, U y){\n    T q = div_floor(x, y);\n    return x - q * y ;\n}\n\
    \n// x \u3092 y \u3067\u5272\u3063\u305F\u5546\u3068\u4F59\u308A\u3092\u6C42\u3081\
    \u308B.\ntemplate<typename T, typename U>\npair<T, T> divmod(T x, U y){\n    T\
    \ q = div_floor(x, y);\n    return {q, x - q * y};\n}\n\n// \u56DB\u6368\u4E94\
    \u5165\u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT round(T x,\
    \ U y){\n    T q, r;\n    tie (q, r) = divmod(x, y);\n    return (r >= div_ceil(y,\
    \ 2)) ? q + 1 : q;\n}\n\n// \u6307\u6570\u306B\u95A2\u3059\u308B\u95A2\u6570\n\
    \n// x \u306E y \u4E57\u3092\u6C42\u3081\u308B.\nll intpow(ll x, ll y){\n    ll\
    \ a = 1;\n    while (y){\n        if (y & 1) { a *= x; }\n        x *= x;\n  \
    \      y >>= 1;\n    }\n    return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\
    \u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\nll modpow(ll x, ll y,\
    \ ll z){\n    ll a = 1;\n    while (y){\n        if (y & 1) { (a *= x) %= z; }\n\
    \        (x *= x) %= z;\n        y >>= 1;\n    }\n    return a;\n}\n\n// x \u306E\
    \ y \u4E57\u3092 z \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B\
    .\ntemplate<typename T, typename U>\nT modpow(T x, U y, T z) {\n    T a = 1;\n\
    \    while (y) {\n        if (y & 1) { (a *= x) %= z; }\n\n        (x *= x) %=\
    \ z;\n        y >>= 1;\n    }\n\n    return a;\n}\n\n// vector \u306E\u8981\u7D20\
    \u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B.\nll sum(vector<ll> &X){\n    ll y\
    \ = 0;\n    for (auto &&x: X) { y+=x; }\n    return y;\n}\n\n// vector \u306E\u8981\
    \u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B.\ntemplate<typename T>\nT sum(vector<T>\
    \ &X){\n    T y = T(0);\n    for (auto &&x: X) { y += x; }\n    return y;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: template/math.hpp
  requiredBy:
  - Tree/Tree.hpp
  - template/template.hpp
  - Modulo/Modulo.hpp
  - Modulo/Discrete_Log.hpp
  - Modulo/Order.hpp
  - Algebra/Gaussian_Integer.hpp
  - Integer/Divisors.hpp
  - Integer/Quotients.hpp
  - Integer/Miller_Rabin_Primality.hpp
  - Math/Floor_Linear_Sum.hpp
  - Math/Two_SAT.hpp
  timestamp: '2025-09-06 23:10:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.test.cpp
  - verify/yosupo_library_checker/tree/Lowest_Common_Ancestor.test.cpp
  - verify/yosupo_library_checker/number_theory/Min_of_Mod_of_Linear.test.cpp
  - verify/yosupo_library_checker/number_theory/Floor_Linear_Sum.test.cpp
  - verify/yosupo_library_checker/number_theory/Miller_Rabin_Primality_Test.test.cpp
  - verify/yosupo_library_checker/number_theory/Gaussian_Integers.test.cpp
  - verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
  - verify/yosupo_library_checker/number_theory/Discrete_Log.test.cpp
  - verify/yosupo_library_checker/other/two_sat.test.cpp
  - verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
  - verify/yukicoder/Modulo_Order.test.cpp
documentation_of: template/math.hpp
layout: document
redirect_from:
- /library/template/math.hpp
- /library/template/math.hpp.html
title: template/math.hpp
---
