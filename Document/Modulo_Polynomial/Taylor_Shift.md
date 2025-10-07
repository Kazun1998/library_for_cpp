---
title: Taylor Shift
documentation_of: //Modulo_Polynomial/Taylor_Shift.hpp
---

## Outline

多項式 $P(X)$ と $c \in F$ に対して, $Q(X) = P(X + c)$ を満たす多項式 $Q$ を求める.

## Theory

$P$ が $d$ 次の多項式であるとして,

$$ P(X) = \sum_{n=0}^d a_n X^n $$

とする.

このとき,

$$\begin{align*}
    P(X + a)
    &= \sum_{n=0}^d a_n (X + c)^n \\
    &= \sum_{n=0}^d a_n \left(\sum_{m=0}^n \dbinom{n}{m} X^m c^{n-m} \right) \\
    &= \sum_{n=0}^d a_n \sum_{m=0}^n \dbinom{n}{m} X^m c^{n-m} \\
    &= \sum_{n=0}^d a_n \sum_{m=0}^n \dfrac{n!}{m!(n-m)!} X^m c^{n-m} \\
    &= \sum_{n=0}^d \sum_{m=0}^n (a_n n!) \cdot \dfrac{c^{n-m}}{(n-m)!} \cdot \dfrac{X^m}{m!} \\
    &= \sum_{m=0}^d \left(\sum_{n=m}^d (a_n n!) \cdot \dfrac{c^{n-m}}{(n-m)!} \right) \dfrac{X^m}{m!} \\
    &= \sum_{m=0}^d \left(\sum_{n=0}^{d-m} (a_{n+m} (n+m)!) \cdot \dfrac{c^n}{n!} \right) \dfrac{X^m}{m!} \\
\end{align*}$$

ここで, $d$ 次多項式 $U, V$ を

$$ U := \sum_{n=0}^d a_n n! X^n, \quad V := \sum_{n=0}^d \dfrac{c^{d-n}}{(d-n)!} X^n $$

とおくと,

$$\begin{align*}
    \sum_{n=0}^{d-m} (a_{n+m} (n+m)!) \cdot \dfrac{c^n}{n!}
    &= \sum_{n=0}^{d-m} \left(\left[X^{n+m} \right] U \right) \left( \left[X^{d-n} \right] V \right) \\
    &= \left[X^{m+d} \right] (UV)
\end{align*}$$

である.

従って,

$$ P(X + a) = \sum_{m=0}^d \left[X^{d+m} \right] (UV) \dfrac{X^m}{m!} $$

である. $U, V$ は $d$ 次多項式であるため, $UV$ は $O(d \log d)$ 時間で求められる. これに伴い, $P(X+a)$ も $O(d \log d)$ 時間で求められる.

### Contents 

```cpp
Fast_Power_Series<mint> Taylor_Shift(const Fast_Power_Series<mint> &P, const mint &a)
```

* 多項式 $P$ に対して, $P(X+a)$ を求める.
* **計算量** : $P$ の次数を $d$ として, $O(d \log d)$ 時間.
