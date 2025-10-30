---
title: 微積分
documentation_of: //Modulo_Polynomial/Calculus.hpp
---

## Outline

形式的ベキ級数 $P$ に対する形式的微分と形式的積分を求める.

## Define

$\displaystyle P := \sum_{n=0}^\infty a_n X^n $ を形式的ベキ級数とする.

$P$ の形式的微分 $P'$ を

$$ P' := \sum_{n=1}^\infty n a_n X^{n-1} $$

で定義する.

また, 定数 $C$ に関する形式的積分を

$$ \int P~dX := \sum_{n=0}^\infty \dfrac{a_n}{n+1} X^{n+1} + C $$

で定義する.

## Theory

形式的微分と形式的積分は線形性が成り立つ.

また, 形式的ベキ級数 $P$ に対して, 以下の式が成り立つ. ただし, $C_0$

* $\displaystyle \left(\int P~dX \right)' = P$.
* ある $C_0$ が存在して, $\displaystyle \int P'~dX = P + C_0 $.

## Contents

### Differential

```cpp
template<typename mint>
Fast_Power_Series<mint> Differential(const Fast_Power_Series<mint> &A)
```

* $A$ の形式的微分 $A'$ を求める.
* **計算量** : $N$ 次まで求めるとして, $O(N)$ 時間.

### Integrate

```cpp
template<typename mint>
Fast_Power_Series<mint> Integrate(const Fast_Power_Series<mint> &A, const mint C = 0)
```

* $A$ の $C$ に関する形式的積分を求める.
* **計算量** : $N$ 次まで求めるとして, $O(N)$ 時間.
