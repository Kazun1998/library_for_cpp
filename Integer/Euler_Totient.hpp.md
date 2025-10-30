---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Integer/Prime.hpp
    title: Integer/Prime.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Modulo/Order.hpp
    title: "\u5270\u4F59\u985E\u306E\u6307\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/ntl/1D.test.cpp
    title: verify/aizu_online_judge/ntl/1D.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/Modulo_Order.test.cpp
    title: verify/yukicoder/Modulo_Order.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Integer/Euler_Totient.hpp\"\n\n#line 2 \"Integer/Prime.hpp\"\
    \n\nnamespace prime {\n  class Pseudo_Prime_Generator {\n    private:\n    long\
    \ long prime = 1, step = 0;\n\n    public:\n    long long get() {\n      if (step)\
    \ {\n        prime += step;\n        step = 6 - step;\n      }\n      else if\
    \ (prime == 1) { prime = 2; }\n      else if (prime == 2) { prime = 3; }\n   \
    \   else if (prime == 3) { prime = 5, step = 2; }\n\n      return prime;\n   \
    \ }\n  };\n\n  // n \u306F\u7D20\u6570?\n  bool is_prime(long long n) {\n    if\
    \ (n <= 3) { return n >= 2; }\n    else if (n == 5) { return true; }\n    else\
    \ if ((n % 2 == 0) || (n % 3 == 0) || (n % 5 == 0)) { return false; }\n\n    Pseudo_Prime_Generator\
    \ generator;\n    for (long long p = generator.get(); p * p <= n; p = generator.get())\
    \ {\n      if (n % p == 0) { return false; }\n    }\n\n    return true;\n  }\n\
    \n  pair<long long, long long> exponents(long long n, long long p) {\n    long\
    \ long e = 0;\n    while (n % p == 0) { e++, n /= p; }\n    return {e, n};\n \
    \ }\n\n  // \u7D20\u56E0\u6570\u5206\u89E3\n  vector<pair<long long, long long>>\
    \ prime_factorization (long long n) {\n    if (n == 0) { return { make_pair(0,\
    \ 0) }; } \n\n    vector<pair<long long, long long>> factors;\n    if (n < 0)\
    \ {\n      factors.emplace_back(make_pair(-1, 1));\n      n = abs(n);\n    }\n\
    \n    Pseudo_Prime_Generator generator;\n    for (long long p =generator.get();\
    \ p * p <= n; p = generator.get()) {\n      long long e;\n      tie(e, n) = exponents(n,\
    \ p); \n      if (e) { factors.emplace_back(make_pair(p, e)); }\n    }\n\n   \
    \ if (n > 1) { factors.emplace_back(make_pair(n, 1)); }\n  \n    return factors;\n\
    \  }\n\n  // n \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u30EA\u30B9\u30C8\u3092\u4F5C\
    \u6210\u3059\u308B.\n  vector<long long> prime_list(long long n) {\n    if (n\
    \ == 0 || n == 1) { return {}; }\n    else if (n == 2) { return {2}; }\n\n   \
    \ if (n % 2 == 0) { n--; }\n\n    long long m = (n + 1) / 2;\n\n    // prime_flag[k]\
    \ := (2k+1) \u306F\u7D20\u6570\u304B?\n    vector<bool> prime_flag(m, true);\n\
    \    prime_flag[0] = false;\n\n    // 9 \u4EE5\u4E0A\u306E 3 \u306E\u500D\u6570\
    \u3092\u6D88\u3059.\n    for (long long x = 4; x < m; x += 3) { prime_flag[x]\
    \ = false; }\n\n    auto generator = Pseudo_Prime_Generator();\n    for (auto\
    \ p = generator.get(); p * p <= n; p = generator.get()) {\n      if (p <= 3) {\
    \ continue; }\n\n      if (!prime_flag[(p - 1) / 2]) { continue; }\n\n      for\
    \ (auto j = (p * p - 1) / 2; j < m; j += p) { prime_flag[j] = false; }\n    }\n\
    \n    vector<long long> primes{2};\n\n    for (long long k = 0; k < m; k++) {\n\
    \      if (prime_flag[k]) { primes.emplace_back(2 * k + 1); }\n    }\n\n    return\
    \ primes;\n  }\n}\n#line 4 \"Integer/Euler_Totient.hpp\"\n\nlong long Euler_Totient(long\
    \ long N, bool mode = true) {\n    if (N == 1) { return mode ? 1 : 0; }\n\n  \
    \  long long phi = 1;\n    for (auto &&[p, e]: prime::prime_factorization(N))\
    \ {\n        phi *= p - 1;\n        for (int k = 0; k < e - 1; k++) { phi *= p;\
    \ }\n    }\n\n    return phi;\n}\n"
  code: "#pragma once\n\n#include\"Prime.hpp\"\n\nlong long Euler_Totient(long long\
    \ N, bool mode = true) {\n    if (N == 1) { return mode ? 1 : 0; }\n\n    long\
    \ long phi = 1;\n    for (auto &&[p, e]: prime::prime_factorization(N)) {\n  \
    \      phi *= p - 1;\n        for (int k = 0; k < e - 1; k++) { phi *= p; }\n\
    \    }\n\n    return phi;\n}\n"
  dependsOn:
  - Integer/Prime.hpp
  isVerificationFile: false
  path: Integer/Euler_Totient.hpp
  requiredBy:
  - Modulo/Order.hpp
  timestamp: '2025-10-30 23:38:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu_online_judge/ntl/1D.test.cpp
  - verify/yukicoder/Modulo_Order.test.cpp
documentation_of: Integer/Euler_Totient.hpp
layout: document
title: "Euler's Totient \u95A2\u6570"
---

## Outline

正の整数 $N$ に対して, Euler の Totient 関数 $\varphi$ の $N$ における値 $\varphi(N)$ を求める.

## Theory

正の整数 $N$ に対して, $N$ と互いに素な $1$ 以上 $N$ 以下の整数の個数 $\varphi(N)$ を与える関数を Euler の Totient 関数という.

Euler の Totient 関数 に対して, 以下の性質が成り立つ.

* 素数 $p$ と非負整数 $k$ に対して, $\varphi(p^k) = p^k - p^{k-1} = p^{k-1} (p-1)$.
* 互いに素な正の整数 $m, n$ に対して, $\varphi(mn) = \varphi(m) \varphi(n)$.

$N$ の素因数分解を

$$ N = p_1^{e_1} \cdot p_2^{e_2} \cdot \dots p_r^{e_r} $$

とする ($p_1, \dots, p_r$ は素数, $e_1, \dots, e_r$ は正の整数).

すると,

$$\begin{align*}
    \varphi(N)
    &= \prod_{i=1}^r p_i^{e_i - 1} (p_i - 1) \\
    &= N \prod_{i=1}^r \dfrac{p_i - 1}{p_i}
\end{align*}$$

となる.

$N$ の素因数分解は試し割りを用いると, $O(\sqrt{N})$ 時間, 高速な方法で $O(N^{1/4})$ 時間で求められるので, $\varphi(N)$ もこれらと同程度の時間で求められる.

## $\varphi$ の性質

$\varphi$ について, 以下が成り立つ.

* $N \geq 2$ に対して, $\mathbb{Z}/N \mathbb{Z}$ における可逆元の個数は $\varphi(N)$ 個である.
* $d$ を $N$ の約数とする. $\gcd(N,x) = \frac{N}{d}$ となる $N$ 未満の非負整数の数は $\varphi(d)$ 個である. このことから, $\displaystyle \sum_{d \mid N} \varphi(d) = N$ が成り立つ.

## Contents

```cpp
long long Euler_Totient(long long N, bool mode = true)
```

* 正の整数 $N$ に対して, $\varphi(N)$ を求める.
* **引数**
  * `mode`: `false` にした場合, 求めるものが 「$N$ と互いに素な $1$ 以上 $N$ **未満**の整数の個数」になる.
    * $N \geq 2$ の場合は $\varphi(N)$ と等しくなる.
    * $N = 1$ の場合の返り値が $1$ から $0$ になる.
* **計算量** : $O\left(\sqrt{N} \right)$ 時間.