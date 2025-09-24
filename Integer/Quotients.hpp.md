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
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/utility.hpp
    title: template/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
    title: verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Integer/Quotients.hpp\"\n\n#line 2 \"template/template.hpp\"\
    \n\nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cctype>\n#include <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n\
    #include <climits>\n#include <cmath>\n#include <complex>\n#include <cstdarg>\n\
    #include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n\
    #include <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include\
    \ <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <vector>\n\n// utility\n#line\
    \ 2 \"template/utility.hpp\"\n\nusing ll = long long;\n\n// a \u2190 max(a, b)\
    \ \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\u308C\u305F\u3089\
    , \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T, typename U>\ninline bool\
    \ chmax(T &a, const U b){\n    return (a < b ? a = b, 1: 0);\n}\n\n// a \u2190\
    \ min(a, b) \u3092\u5B9F\u884C\u3059\u308B. a \u304C\u66F4\u65B0\u3055\u308C\u305F\
    \u3089, \u8FD4\u308A\u5024\u304C true.\ntemplate<typename T, typename U>\ninline\
    \ bool chmin(T &a, const U b){\n    return (a > b ? a = b, 1: 0);\n}\n#line 59\
    \ \"template/template.hpp\"\n\n// math\n#line 2 \"template/math.hpp\"\n\n// \u9664\
    \u7B97\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// floor(x / y) \u3092\u6C42\u3081\
    \u308B.\ntemplate<typename T, typename U>\nT div_floor(T x, U y){ return (x >\
    \ 0 ? x / y: (x - y + 1) / y); }\n\n// ceil(x / y) \u3092\u6C42\u3081\u308B.\n\
    template<typename T, typename U>\nT div_ceil(T x, U y){ return (x > 0 ? (x + y\
    \ - 1) / y: x / y) ;}\n\n// x \u3092 y \u3067\u5272\u3063\u305F\u4F59\u308A\u3092\
    \u6C42\u3081\u308B.\ntemplate<typename T, typename U>\nT mod(T x, U y){\n    T\
    \ q = div_floor(x, y);\n    return x - q * y ;\n}\n\n// x \u3092 y \u3067\u5272\
    \u3063\u305F\u5546\u3068\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename\
    \ T, typename U>\npair<T, T> divmod(T x, U y){\n    T q = div_floor(x, y);\n \
    \   return {q, x - q * y};\n}\n\n// \u56DB\u6368\u4E94\u5165\u3092\u6C42\u3081\
    \u308B.\ntemplate<typename T, typename U>\nT round(T x, U y){\n    T q, r;\n \
    \   tie (q, r) = divmod(x, y);\n    return (r >= div_ceil(y, 2)) ? q + 1 : q;\n\
    }\n\n// \u6307\u6570\u306B\u95A2\u3059\u308B\u95A2\u6570\n\n// x \u306E y \u4E57\
    \u3092\u6C42\u3081\u308B.\nll intpow(ll x, ll y){\n    ll a = 1;\n    while (y){\n\
    \        if (y & 1) { a *= x; }\n        x *= x;\n        y >>= 1;\n    }\n  \
    \  return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\u5272\u3063\u305F\u4F59\
    \u308A\u3092\u6C42\u3081\u308B.\nll modpow(ll x, ll y, ll z){\n    ll a = 1;\n\
    \    while (y){\n        if (y & 1) { (a *= x) %= z; }\n        (x *= x) %= z;\n\
    \        y >>= 1;\n    }\n    return a;\n}\n\n// x \u306E y \u4E57\u3092 z \u3067\
    \u5272\u3063\u305F\u4F59\u308A\u3092\u6C42\u3081\u308B.\ntemplate<typename T,\
    \ typename U>\nT modpow(T x, U y, T z) {\n    T a = 1;\n    while (y) {\n    \
    \    if (y & 1) { (a *= x) %= z; }\n\n        (x *= x) %= z;\n        y >>= 1;\n\
    \    }\n\n    return a;\n}\n\n// vector \u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\
    \u6C42\u3081\u308B.\nll sum(vector<ll> &X){\n    ll y = 0;\n    for (auto &&x:\
    \ X) { y+=x; }\n    return y;\n}\n\n// vector \u306E\u8981\u7D20\u306E\u7DCF\u548C\
    \u3092\u6C42\u3081\u308B.\ntemplate<typename T>\nT sum(vector<T> &X){\n    T y\
    \ = T(0);\n    for (auto &&x: X) { y += x; }\n    return y;\n}\n\n// a x + b y\
    \ = gcd(a, b) \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44 (a, b) \u306B\u5BFE\
    \u3057\u3066, (x, y, gcd(a, b)) \u3092\u6C42\u3081\u308B.\ntuple<ll, ll, ll> Extended_Euclid(ll\
    \ a, ll b) {\n    ll s = 1, t = 0, u = 0, v = 1;\n    while (b) {\n        ll\
    \ q;\n        tie(q, a, b) = make_tuple(div_floor(a, b), b, mod(a, b));\n    \
    \    tie(s, t) = make_pair(t, s - q * t);\n        tie(u, v) = make_pair(v, u\
    \ - q * v);\n    }\n\n    return make_tuple(s, u, a);\n}\n\n// floor(sqrt(N))\
    \ \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\u304D\u306F, 0 \u3068\u3059\u308B\
    ).\nll isqrt(const ll &N) { \n    if (N <= 0) { return 0; }\n\n    ll x = sqrt(N);\n\
    \    while ((x + 1) * (x + 1) <= N) { x++; }\n    while (x * x > N) { x--; }\n\
    \n    return x;\n}\n\n// floor(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\
    \u3068\u304D\u306F, 0 \u3068\u3059\u308B).\nll floor_sqrt(const ll &N) { return\
    \ isqrt(N); }\n\n// ceil(sqrt(N)) \u3092\u6C42\u3081\u308B (N < 0 \u306E\u3068\
    \u304D\u306F, 0 \u3068\u3059\u308B).\nll ceil_sqrt(const ll &N) {\n    ll x =\
    \ isqrt(N);\n    return x * x == N ? x : x + 1;\n}\n#line 62 \"template/template.hpp\"\
    \n\n// inout\n#line 1 \"template/inout.hpp\"\n// \u5165\u51FA\u529B\ntemplate<class...\
    \ T>\nvoid input(T&... a){ (cin >> ... >> a); }\n\nvoid print(){ cout << \"\\\
    n\"; }\n\ntemplate<class T, class... Ts>\nvoid print(const T& a, const Ts&...\
    \ b){\n    cout << a;\n    (cout << ... << (cout << \" \", b));\n    cout << \"\
    \\n\";\n}\n\ntemplate<typename T, typename U>\nistream &operator>>(istream &is,\
    \ pair<T, U> &P){\n    is >> P.first >> P.second;\n    return is;\n}\n\ntemplate<typename\
    \ T, typename U>\nostream &operator<<(ostream &os, const pair<T, U> &P){\n   \
    \ os << P.first << \" \" << P.second;\n    return os;\n}\n\ntemplate<typename\
    \ T>\nvector<T> vector_input(int N, int index){\n    vector<T> X(N+index);\n \
    \   for (int i=index; i<index+N; i++) cin >> X[i];\n    return X;\n}\n\ntemplate<typename\
    \ T>\nistream &operator>>(istream &is, vector<T> &X){\n    for (auto &x: X) {\
    \ is >> x; }\n    return is;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const vector<T> &X){\n    int s = (int)X.size();\n    for (int i = 0; i\
    \ < s; i++) { os << (i ? \" \" : \"\") << X[i]; }\n    return os;\n}\n\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os, const unordered_set<T> &S){\n    int i\
    \ = 0;\n    for (T a: S) {os << (i ? \" \": \"\") << a; i++;}\n    return os;\n\
    }\n\ntemplate<typename T>\nostream &operator<<(ostream &os, const set<T> &S){\n\
    \    int i = 0;\n    for (T a: S) { os << (i ? \" \": \"\") << a; i++; }\n   \
    \ return os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream &os, const\
    \ unordered_multiset<T> &S){\n    int i = 0;\n    for (T a: S) { os << (i ? \"\
    \ \": \"\") << a; i++; }\n    return os;\n}\n\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os, const multiset<T> &S){\n    int i = 0;\n    for (T a: S) { os << (i ? \"\
    \ \": \"\") << a; i++; }\n    return os;\n}\n#line 65 \"template/template.hpp\"\
    \n\n// macro\n#line 2 \"template/macro.hpp\"\n\n// \u30DE\u30AF\u30ED\u306E\u5B9A\
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
    \ foreach4, foreach3, foreach2, foreach1)(__VA_ARGS__)\n#line 4 \"Integer/Quotients.hpp\"\
    \n\nvector<tuple<ll, ll, ll>> Quotients(ll N) {\n    auto quotients = vector<tuple<ll,\
    \ ll, ll>>();\n\n    ll l = 1;\n    while (l <= N) {\n        ll q = N / l;\n\
    \        ll r = N / q;\n        quotients.emplace_back(q, l, r);\n        l =\
    \ r + 1;\n    }\n\n    return quotients;\n}\n"
  code: "#pragma once\n\n#include\"../template/template.hpp\"\n\nvector<tuple<ll,\
    \ ll, ll>> Quotients(ll N) {\n    auto quotients = vector<tuple<ll, ll, ll>>();\n\
    \n    ll l = 1;\n    while (l <= N) {\n        ll q = N / l;\n        ll r = N\
    \ / q;\n        quotients.emplace_back(q, l, r);\n        l = r + 1;\n    }\n\n\
    \    return quotients;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  isVerificationFile: false
  path: Integer/Quotients.hpp
  requiredBy: []
  timestamp: '2025-09-23 12:48:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/number_theory/Enumerate_Quotients.test.cpp
documentation_of: Integer/Quotients.hpp
layout: document
title: "\u5546\u306E\u5217\u6319 (Quotients)"
---

## Outline

正の整数 $N$ に対して, 関数 $f: \mathbb{N} \to \mathbb{N}$ を

  $$ f(x) := \left \lfloor \dfrac{N}{x} \right \rfloor $$

で定義する.

  $$ E_N := \left\{ f(x) ~\middle|~ 1 \leq x \leq N \right\}$$

と, 各 $y \in E_N$ に対して, $f(x) = y$ を満たす $x$ の範囲を合計で $O(\sqrt{N})$ 時間で求める.

## Theory

### 主となる定理の証明
以下の定理が成り立つ.
> $ \\# E_N = O(\sqrt{N})$

#### 証明

  $$ E_N = \left\{ f(x) ~\middle|~ 1 \leq x \leq \sqrt{N} \right\} \cup \left\{ f(x) ~\middle|~ \sqrt{N} \leq x \leq N \right\}$$

と分割できる.

  $$ L_N := \left\{ f(x) ~\middle|~ 1 \leq x \leq \sqrt{N} \right\}, \quad R_N := \left\{ f(x) ~\middle|~ \sqrt{N} \leq x \leq N \right\} $$

とする.

##### $L_N$ について

$x$ が走る範囲は $1 \leq x \leq \sqrt{N}$ であるため, $\\# L_N \leq \sqrt{N}$ である.

##### $R_N$ について

$x \geq \sqrt{N}$ に対して, $\dfrac{N}{x} \leq \sqrt{N}$ である. よって, $f(x) \leq \sqrt{N}$ である. 故に, $\\# R_N \leq \sqrt{N}$ である.

以上から,

  $$ \# E_N = \# (L_N \cup R_N) \leq \# L_N + \# R_N \leq 2 \sqrt{N}$$

であるので, $\\# E_N = O(\sqrt{N})$ となる.

### アルゴリズムの構築

$f$ は広義単調減少であるため, 以下のアルゴリズムによって, 商の可能性を降順に全て列挙できる.

* $l \gets 1$ とする.
* 以下のループを $l \leq N$ である限り繰り返す.
    * $q \gets f(l)$ とする.
    * $x \in \mathbb{N}$ に対して, $f(x) = q \iff l \leq x \leq f(q)$ である. そのため, $f(x) = q$ となる範囲は $l \leq x \leq f(q)$ となる.
    * $l \gets f(q) + 1$ とする.

## Contents

```cpp
vector<tuple<ll, ll, ll>> Quotients(ll N)
```

* $E_N$ の要素 $q$ と $f(x) = q$ を満たす $q$ の範囲を $q$ の降順に出力する.
* **返り値**
  * $(q, l, r)$ の形. 各要素 (`tuple<ll, ll, ll>`) は以下を意味する.
    * $q \in E_N$ である.
    * $f(x) = q$ である範囲が $l \leq x \leq r$ となることを意味する.
* **計算量** : $O(\sqrt{N})$ 時間