---
title: Euler's Totient 関数
documentation_of: //Integer/Euler_Totient.hpp
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