---
title: (等比) x (単項式) の級数
documentation_of: //Summation/Sum_of_Exponential_Times_Polynomial_Limit.hpp
---

## Outline

$\displaystyle \sum_{k=0}^\infty r^k k^d$ を求める.

## Theory

$\| r \| < 1$ とする.

[(等比) x (単項式) の総和](Sum_of_Exponential_Times_Polynomial.hpp) において, 定数 $C$ と $d$ 次多項式 $f$ を使って $s_n = C + r^N f(n)$ と表せること, そして, $C$ が求められるところまでは同じ.

ここで, $\| r \| < 1$ であり, $f$ は多項式なので,

$$ \lim_{n \to \infty} \left(C + r^N f(n) \right) = C $$

である.

よって,

$$ \sum_{n=0}^\infty r^n n^d = C $$

になる.

## Contents

```cpp
template<typename F>
F Sum_of_Exponential_Times_Polynomial(const F r, const int d, const ll n)
```

* $\displaystyle \sum_{k=0}^n r^k k^d$ を求める.
* **計算量**: $O(d)$ 時間.

```cpp
template<typename F>
F Sum_of_Exponential_Times_Polynomial(const F r, const int d, const ll p, const ll q)
```

* $\displaystyle \sum_{k=p}^q r^k k^d$ を求める.
* **計算量**: $O(d)$ 時間.

## History 

|日付|内容|
|:---:|:---:|
|2026/04/19| Sum_of_Exponential_Times_Polynomial 実装 |
