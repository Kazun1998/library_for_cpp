---
title: Log
documentation_of: //Modulo_Polynomial/Log.hpp
---

## Outline

形式的ベキ級数 $P$ に対して, $\log P$ を求める.

## Define

$[X^0] P = 1$ である形式的ベキ級数 $P$ に対して, $P$ の対数 $\log P$ を

$$ \log P := -\sum_{n=1}^\infty \dfrac{(1-P)^n}{n} $$

で定義する.

## Theory

対数に関する微分について, 以下の式が従う.

$$\begin{align*}
    (\log P)'
    &= \left(- \sum_{n=1}^\infty \dfrac{(1-P)^n}{n} \right)' \\
    &= P' \sum_{n=1}^\infty (1-P)^n \\
    &= \dfrac{P'}{1-(1-P)} \\
    &= \dfrac{P'}{P}
\end{align*}$$

つまり, $(\log P)' = \dfrac{P'}{P}$ であるので,

$$ \log P = \int \dfrac{P'}{P}~dX $$

となる.

この式を利用すると, $\log P$ は $P$ の微分と除算で求められるため, $N$ 次まで求めるとすると, 計算量は $O(N \log N)$ 時間になる.

## Contents

```cpp
Fast_Power_Series<mint> Log(const Fast_Power_Series<mint> &A)
```

* $\log A$ を求める.
* **制約** : $[X^0] A = 1$.
* **計算量** : $N$ 次まで求めるとして, $O(N \log N)$ 時間.
