---
title: 分数式の係数
documentation_of: //Modulo_Polynomial/Fraction_Coefficient.hpp
---

## Outline

多項式 $P, Q$ に対して, $\left[X^N \right] \dfrac{P}{Q}$ を高速に求める.

## Theory

Bostan-Mori 法を利用する.

$\left[X^0 \right] Q \neq 0$ とする.

分子と分母の両方に $Q(-X)$ を掛けると, 分母が偶多項式 $Q(X)Q(-X)$ となる.

よって, 多項式 $V$ が存在して, $V(X^2) = Q(X)Q(-X)$ と表せる.

分子の多項式 $P(X)Q(-X)$ は偶成分 $S_0(X)$ と奇成分 $S_1(X)$ によって,
$$ P(X) Q(-X) = S_0(X^2) + X S_1(X^2)$$
と表せる.

$$ \dfrac{P}{Q} = \dfrac{P(X)Q(-X)}{Q(X)Q(-X)} = \dfrac{S_0(X^2) + X S_1(X^2)}{V(X^2)} = \dfrac{S_0(X^2)}{V(X^2)} + X \dfrac{S_1(X^2)}{V(X^2)} $$
となる. このとき,

$$ T_0(X) := \dfrac{S_0(X^2)}{V(X^2)}, \quad T_1(X) := \dfrac{S_1(X^2)}{V(X^2)}$$

は共に偶多項式である.

$$ \dfrac{P}{Q} = T_0(X^2) + X T_1(X^2) $$

となる.

* $N$ が偶数のとき

$$
\begin{align*}
    \left[X^N \right] \dfrac{P}{Q}
    &= \left[X^N \right] \left(T_0(X^2) + X T_1(X^2) \right) \\
    &= \left[X^N \right] T_0(X^2) \\
    &= \left[X^{N/2} \right] T_0(X) \\
    &= \left[X^{N/2} \right] \dfrac{S_0}{V} \\
\end{align*}
$$

* $N$ が奇数のとき

$$
\begin{align*}
    \left[X^N \right] \dfrac{P}{Q}
    &= \left[X^N \right] \left(T_0(X^2) + X T_1(X^2) \right) \\
    &= \left[X^N \right] XT_1(X^2) \\
    &= \left[X^{N-1} \right] T_1(X^2) \\
    &= \left[X^{(N-1)/2} \right] \dfrac{S_1}{V} \\
\end{align*}
$$

これにより, $N$ が約 $1/2$ に落とした同様の問題に帰着された.

また, ベースケースとして,

$$ \left[X^0 \right] \dfrac{P}{Q} = \dfrac{\left[X^0 \right]P}{\left[X^0 \right] Q} $$

として $N = 0$ のときを求めることができる.

$P, Q$ が高々 $d$ 次として, 形式的冪級数の除算に $O(d \log d)$ 時間かかり, これを $O(\log N)$ 回繰り返す.

よって, $\left[X^N \right] \dfrac{P}{Q}$ は $O(d \log d \log N)$ 時間で求めることができる.

## Contents

```cpp
template<const ll Mod>
modint<Mod> Fraction_Coefficient(const Fast_Polynominal_Series<Mod> &P, const Fast_Polynominal_Series<Mod> &Q, ll N)
```

* $\left[ X^N \right] \dfrac{P}{Q}$ を求める.
* **計算量** : $P, Q$ が高々 $d$ 次式として, $O(d \log d \log N)$ 時間

