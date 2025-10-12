---
title: Floor Linear Sum
documentation_of: //Math/Floor_Linear_Sum.hpp
---

## Outline

$\displaystyle \sum_{k=0}^{N-1} \left \lfloor \dfrac{A k + B}{M} \right \rfloor$ を高速に求める.

## Theory

$\displaystyle T(A, B, M, N) := \sum_{k=0}^{N-1} \left \lfloor \dfrac{A k + B}{M} \right \rfloor$ とする.

### Section I

$A, B$ について, 以下が成り立つ.

$$\begin{align*}
T(A \pm M, B, M, N)
&= \sum_{k=0}^{N-1} \left \lfloor \dfrac{(A \pm M) k + B}{M} \right \rfloor \\
&= \sum_{k=0}^{N-1} \left \lfloor \dfrac{A k + B}{M} \pm k \right \rfloor \\
&= \sum_{k=0}^{N-1} \left(\left \lfloor \dfrac{A k + B}{M} \right \rfloor \pm k \right) \\
&= \sum_{k=0}^{N-1} \left \lfloor \dfrac{A k + B}{M} \right \rfloor \pm \sum_{k=0}^{N-1} k \\
&= T(A, B, M, N) \pm \dfrac{N(N-1)}{2} \\
\end{align*}$$

$$\begin{align*}
T(A, B \pm M, M, N)
&= \sum_{k=0}^{N-1} \left \lfloor \dfrac{A k + (B \pm M)}{M} \right \rfloor \\
&= \sum_{k=0}^{N-1} \left \lfloor \dfrac{A k + B}{M} \pm 1 \right \rfloor \\
&= \sum_{k=0}^{N-1} \left(\left \lfloor \dfrac{A k + B}{M} \right \rfloor \pm 1 \right) \\
&= \sum_{k=0}^{N-1} \left \lfloor \dfrac{A k + B}{M} \right \rfloor \pm \sum_{k=0}^{N-1} 1 \\
&= T(A, B, M, N) \pm N \\
\end{align*}$$

よって, $0 \leq A \lt M, 0 \leq B \lt M$ の範囲のみを考えれば良い.

### Section II

$\displaystyle f(k) := \left \lfloor \dfrac{Ak+B}{M} \right \rfloor$ とおく.

$\displaystyle r := \left \lfloor \dfrac{AN+B}{M} \right \rfloor$ とする. $y = 0, 1, \dots, r$ に対して, $f(k) = y$ となる $k~(0 \leq k \lt N)$ の個数を $c_y$ とおく.
