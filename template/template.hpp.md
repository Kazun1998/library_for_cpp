---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/math.hpp
    title: template/math.hpp
  - icon: ':heavy_check_mark:'
    path: template/utility.hpp
    title: template/utility.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Algebra/Gaussian_Integer.hpp
    title: Algebra/Gaussian_Integer.hpp
  - icon: ':heavy_check_mark:'
    path: Integer/Divisors.hpp
    title: Integer/Divisors.hpp
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
  bundledCode: "#line 2 \"template/template.hpp\"\n\nusing namespace std;\n\n// intrinstic\n\
    #include <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <streambuf>\n#include\
    \ <string>\n#include <tuple>\n#include <type_traits>\n#include <typeinfo>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include <vector>\n\
    \n// utility\n#line 2 \"template/utility.hpp\"\n\nusing ll = long long;\n\n//\
    \ a \u2190 max(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\
    \u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T, typename\
    \ U>\ninline bool chmax(T &a, const U b){\n    return (a < b ? a = b, 1: 0);\n\
    }\n\n// a \u2190 min(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\
    \u3055\u308C\u305F\u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T,\
    \ typename U>\ninline bool chmin(T &a, const U b){\n    return (a > b ? a = b,\
    \ 1: 0);\n}\n#line 59 \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\
    \n\n// \u9664\u7B97\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// floor(x / y) \u3092\
    \u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT div_floor(T x, U y){\
    \ return (x > 0 ? x / y: (x - y + 1) / y); }\n\n// ceil(x / y) \u3092\u6C42\u3081\
    \u308B.\ntemplate<typename T, typename U>\nT div_ceil(T x, U y){ return (x > 0\
    \ ? (x + y - 1) / y: x / y) ;}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u4F59\
    \u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT mod(T x,\
    \ U y){\n    T q = div_floor(x, y);\n    return x - q * y ;\n}\n\n// x \u3092\
    \ y \u3067\u5272\u3063\u305F\u5546\u3068\u4F59\u308A\u3092\u6C42\u3081\u308B.\n\
    template<typename T, typename U>\npair<T, T> divmod(T x, U y){\n    T q = div_floor(x,\
    \ y);\n    return {q, x - q * y};\n}\n\n// \u56DB\u6368\u4E94\u5165\u3092\u6C42\
    \u3081\u308B.\ntemplate<typename T, typename U>\nT round(T x, U y){\n    T q,\
    \ r;\n    tie (q, r) = divmod(x, y);\n    return (r >= div_ceil(y, 2)) ? q + 1\
    \ : q;\n}\n\n// \u6307\u6570\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// x \u306E\
    \ y \u4E57\u3092\u6C42\u3081\u308B.\nll intpow(ll x, ll y){\n    ll a = 1;\n \
    \   while (y){\n        if (y & 1) { a *= x; }\n        x *= x;\n        y >>=\
    \ 1;\n    }\n    return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\u5272\u3063\
    \u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\nll modpow(ll x, ll y, ll z){\n  \
    \  ll a = 1;\n    while (y){\n        if (y & 1) { (a *= x) %= z; }\n        (x\
    \ *= x) %= z;\n        y >>= 1;\n    }\n    return a;\n}\n\n// vector \u306E\u8981\
    \u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B.\nll sum(vector<ll> &X){\n  \
    \  ll y = 0;\n    for (auto &&x: X) { y+=x; }\n    return y;\n}\n\n// vector \u306E\
    \u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B.\ntemplate<typename T>\n\
    T sum(vector<T> &X){\n    T y = T(0);\n    for (auto &&x: X) { y += x; }\n   \
    \ return y;\n}\n#line 62 \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\
    \n// \u5165\u51FA\u529B\ntemplate<class... T>\nvoid input(T&... a){ (cin >> ...\
    \ >> a); }\n\nvoid print(){ cout << \"\\n\"; }\n\ntemplate<class T, class... Ts>\n\
    void print(const T& a, const Ts&... b){\n    cout << a;\n    (cout << ... << (cout\
    \ << \" \", b));\n    cout << \"\\n\";\n}\n\ntemplate<typename T, typename U>\n\
    istream &operator>>(istream &is, pair<T, U> &P){\n    is >> P.first >> P.second;\n\
    \    return is;\n}\n\ntemplate<typename T, typename U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &P){\n    os << P.first << \" \" << P.second;\n    return\
    \ os;\n}\n\ntemplate<typename T>\nvector<T> vector_input(int N, int index){\n\
    \    vector<T> X(N+index);\n    for (int i=index; i<index+N; i++) cin >> X[i];\n\
    \    return X;\n}\n\ntemplate<typename T>\nistream &operator>>(istream &is, vector<T>\
    \ &X){\n    for (auto &x: X) { is >> x; }\n    return is;\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &X){\n    int s = (int)X.size();\n\
    \    for (int i = 0; i < s; i++) { os << (i ? \" \" : \"\") << X[i]; }\n    return\
    \ os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream &os, const unordered_set<T>\
    \ &S){\n    int i = 0;\n    for (T a: S) {os << (i ? \" \": \"\") << a; i++;}\n\
    \    return os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream &os, const\
    \ set<T> &S){\n    int i = 0;\n    for (T a: S) { os << (i ? \" \": \"\") << a;\
    \ i++; }\n    return os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const unordered_multiset<T> &S){\n    int i = 0;\n    for (T a: S) { os\
    \ << (i ? \" \": \"\") << a; i++; }\n    return os;\n}\n\ntemplate<typename T>\n\
    ostream &operator<<(ostream &os, const multiset<T> &S){\n    int i = 0;\n    for\
    \ (T a: S) { os << (i ? \" \": \"\") << a; i++; }\n    return os;\n}\n#line 65\
    \ \"template/template.hpp\"\n\n// macro\n#line 2 \"template/macro.hpp\"\n\n//\
    \ \u30DE\u30AF\u30ED\u306E\u5B9A\u7FA9\n#define all(x) x.begin(), x.end()\n#define\
    \ len(x) ll(x.size())\n#define elif else if\n#define unless(cond) if (!(cond))\n\
    \n// \u30AA\u30FC\u30D0\u30FC\u30ED\u30FC\u30C9\u30DE\u30AF\u30ED\n#define overload2(_1,\
    \ _2, name, ...) name\n#define overload3(_1, _2, _3, name, ...) name\n#define\
    \ overload4(_1, _2, _3, _4, name, ...) name\n#define overload5(_1, _2, _3, _4,\
    \ _5, name, ...) name\n\n// \u7E70\u308A\u8FD4\u3057\u7CFB\n#define rep1(n) for\
    \ (ll i = 0; i < n; i++)\n#define rep2(i, n) for (ll i = 0; i < n; i++)\n#define\
    \ rep3(i, a, b) for (ll i = a; i < b; i++)\n#define rep4(i, a, b, c) for (ll i\
    \ = a; i < b; i += c)\n#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2,\
    \ rep1)(__VA_ARGS__)\n\n#define foreach1(x, a) for (auto &&x: a)\n#define foreach2(x,\
    \ y, a) for (auto &&[x, y]: a)\n#define foreach3(x, y, z, a) for (auto &&[x, y,\
    \ z]: a)\n#define foreach4(x, y, z, w, a) for (auto &&[x, y, z, w]: a)\n#define\
    \ foreach(...) overload5(__VA_ARGS__, foreach4, foreach3, foreach2, foreach1)(__VA_ARGS__)\n\
    #line 68 \"template/template.hpp\"\n"
  code: '#pragma once


    using namespace std;


    // intrinstic

    #include <immintrin.h>


    #include <algorithm>

    #include <array>

    #include <bitset>

    #include <cassert>

    #include <cctype>

    #include <cfenv>

    #include <cfloat>

    #include <chrono>

    #include <cinttypes>

    #include <climits>

    #include <cmath>

    #include <complex>

    #include <cstdarg>

    #include <cstddef>

    #include <cstdint>

    #include <cstdio>

    #include <cstdlib>

    #include <cstring>

    #include <deque>

    #include <fstream>

    #include <functional>

    #include <initializer_list>

    #include <iomanip>

    #include <ios>

    #include <iostream>

    #include <istream>

    #include <iterator>

    #include <limits>

    #include <list>

    #include <map>

    #include <memory>

    #include <new>

    #include <numeric>

    #include <ostream>

    #include <queue>

    #include <random>

    #include <set>

    #include <sstream>

    #include <stack>

    #include <streambuf>

    #include <string>

    #include <tuple>

    #include <type_traits>

    #include <typeinfo>

    #include <unordered_map>

    #include <unordered_set>

    #include <utility>

    #include <vector>


    // utility

    #include"utility.hpp"


    // math

    #include"math.hpp"


    // inout

    #include"inout.hpp"


    // macro

    #include"macro.hpp"

    '
  dependsOn:
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  isVerificationFile: false
  path: template/template.hpp
  requiredBy:
  - Tree/Tree.hpp
  - Modulo/Modulo.hpp
  - Modulo/Discrete_Log.hpp
  - Modulo/Order.hpp
  - Algebra/Gaussian_Integer.hpp
  - Integer/Divisors.hpp
  - Integer/Quotients.hpp
  - Math/Floor_Linear_Sum.hpp
  - Math/Two_SAT.hpp
  timestamp: '2025-08-23 11:25:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.test.cpp
  - verify/yosupo_library_checker/tree/Lowest_Common_Ancestor.test.cpp
  - verify/yosupo_library_checker/number_theory/Min_of_Mod_of_Linear.test.cpp
  - verify/yosupo_library_checker/number_theory/Floor_Linear_Sum.test.cpp
  - verify/yosupo_library_checker/number_theory/Gaussian_Integers.test.cpp
  - verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
  - verify/yosupo_library_checker/number_theory/Discrete_Log.test.cpp
  - verify/yosupo_library_checker/other/two_sat.test.cpp
  - verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
  - verify/yukicoder/Modulo_Order.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
