---
title: (等比) x (単項式) の総和
documentation_of: //Summation/Sum_of_Exponential_Times_Polynomial.hpp
---

## Outline

$\displaystyle \sum_{k=0}^N r^k k^d$ を求める.

## Theory

$F$ を体とする.

---
$r = 0$ のとき, 求めるべきは

$$ r^n n^d = \begin{cases} 1 & (n = 0, d = 0) \\ 0 & (\textrm{otherwise}) \end{cases} $$

であるため,

$$ \sum_{k=0}^N 0^n k^d = \begin{cases} 1 & (d = 0) \\ 0 & (d > 0) \end{cases} $$

になる.

---
$r = 1$ のとき, 求めるべきは

$$ \sum_{k=0}^N k^d $$

である. これは, [Faulhaber の公式](https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A1%E3%82%A6%E3%83%AB%E3%83%8F%E3%83%BC%E3%83%90%E3%83%BC%E3%81%AE%E5%85%AC%E5%BC%8F) によって, ある $(d+1)$ 次多項式 $P(x)$ が存在して,

$$ \sum_{k=0}^n k^d = P(n) $$

が任意の $n$ で成立する.

よって, $P(0), P(1), \dots, P(d)$ から Lagrange 補間を使うことにより, $P(N)$ を求めることができる.

---

これ以降, $r \neq 0, 1$ とする.

$a_n := r^n n^d$ とする. このとき, $(a_n)$ の母関数 $A$ はある $d$ 次以下の多項式 $Q$ を用いて,

$$ A(x) = \dfrac{Q(x)}{(1-rx)^{d+1}} $$

と表せる. 故に, $(a_n)$ の累積和を $(s_n)$ としたとき, $(s_n)$ の母関数 $S$ は

$$ S(x) = \dfrac{Q(x)}{(1-x) (1-rx)^{d+1}} $$

になる. よって, 部分分数分解を行うことで, ある定数 $C \in F$ と $d$ 次以下の多項式 $P(x)$ を用いて,

$$ S(x) = \dfrac{C}{1-x} + \dfrac{P(x)}{(1-rx)^{d+1}} \quad \cdots (1) $$

と表せる. 故に, ある $d$ 次の多項式 $f$ を使って,

$$ s_n = C + r^n f(n) \quad \cdots (2) $$

となることがわかる.

(1) 式について, 両辺に $(1-rx)^{d+1}$ を掛けることによって,

$$ (1-rx)^{d+1} S(x) = \dfrac{(1-rx)^{d+1}}{1-x} \cdot C + Q(x) $$

である. ここで, $Q$ は $d$ 次の多項式であるため, $(d+1)$ 次の係数が消える. よって, $C$ に関する方程式を作ることができる.

つまり,

$$ \left[x^{d+1} \right] \left((1-rx)^{d+1} S(x) \right) = C \cdot \left[x^{d+1} \right] \dfrac{(1-rx)^{d+1}}{1-x} $$

である.

ここで, 左辺と右辺について,

$$
\begin{align*}
    \left[x^{d+1} \right] \left((1-rx)^{d+1} S(x) \right)
    &= \sum_{k=0}^{d+1} \left(\left[x^k \right] (1-rx)^{d+1} \right) \left(\left[x^{d+1-k} \right] S(x) \right) \\
     &= \sum_{k=0}^{d+1} \dbinom{d+1}{k} (-r)^k s_{d+1-k}
\end{align*}
$$

$$
\begin{align*}
    \left[x^{d+1} \right] \dfrac{(1-rx)^{d+1}}{1-x}
    &= \sum_{k=0}^{d+1} \left[x^k \right] (1-rx)^{d+1} \\
    &= \left. (1-rx)^{d+1} \right|_{x=1}\\
    &= (1-r)^{d+1}
\end{align*}
$$

であるため,

$$ C = \dfrac{1}{(1-r)^{d+1}} \sum_{k=0}^{d+1} \dbinom{d+1}{k} (-r)^k s_{d+1-k} $$

になる.

(2) 式を変形させると,

$$ f(n) = \dfrac{s_n - C}{r^n}$$

である. 右辺は $C$ が確定したことによって全てが計算可能になる.

よって, $f$ は $d$ 次の多項式であるため, $f(0), f(1), \dots, f(d)$ を求めてから Lagrange 補間を使うことにより, $f(N)$ を求めることができる.

これによって,

$$ s_N = C + r^N f(N) $$

によって, $s_N$ を求めることができる.

---

$r$ がどのような場合であったとしても, Lagrange 補間から一点の値を求めているが, 標本点が $0, 1, 2, \dots, d$ と等差数列であるため, 一点の値は $O(d)$ 時間で求められる.

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
