---
title: 線形漸化式の第 $N$ 項
documentation_of: //Modulo_Polynomial/Nth_Term_of_Linearly_Recurrent_Sequence.hpp
---

## Outline

線形漸化式の第 $N$ 項を高速に求める.

## Theory

$c_0, c_1, \dots, c_{d-1} \in \mathbb{F}_p$ とする. $\mathbb{F}_p$ 上の列 $a = (a_n)$ は $(d+1)$ 項間線形漸化式

$$ a_n = \sum_{k=0}^{d-1} c_k a_{n-(k+1)} \quad (n \geq d) \quad (*) $$

を満たしているとする.

形式的冪級数 $A$ を $a$ の母関数とする.

このとき, $(*)$ の両辺に $X^n$ を掛け, $n \geq d$ の範囲を足し合わせることにより,

$$ \sum_{n=d}^\infty a_n X^n = \sum_{n=d}^\infty \sum_{k=0}^{d-1} c_k a_{n-(k+1)} X^n $$

を得る.

左辺について,

$$ \sum_{n=d}^\infty a_n X^n = A - \sum_{n=0}^{d-1} a_n X^{n-1} $$

となる.

右辺について,

$$\begin{align*}
    \sum_{n=d}^\infty \sum_{k=0}^{d-1} c_k a_{n-(k+1)} X^n
    &= \sum_{k=0}^{d-1} \sum_{n=d}^\infty c_k a_{n-(k+1)} X^n \\
    &= \sum_{k=0}^{d-1} c_k X^{k+1} \sum_{n=d}^\infty a_{n-(k+1)} X^{n-(k+1)} \\
    &= \sum_{k=0}^{d-1} c_k X^{k+1} \left(A - \sum_{m=0}^{d-k-2} a_m X^m \right) \\
    &= \sum_{k=1}^d c_{k-1} X^k \left(A - \sum_{m=0}^{d-k-1} a_m X^m \right) \\
\end{align*}$$

となるため, 整理すると,

$$ \left(1 - \sum_{k=1}^d c_{k-1} X^k \right) A = - \sum_{k=1}^d \sum_{m=0}^{d-k-1} c_{k-1} a_m X^{k+m} \quad (**) $$

多項式 $Q$ を

  $$ Q := 1 - \sum_{k=1}^d c_{k-1} X^k $$

とおくと, $QA$ は (**) より, $d$ 次未満の多項式である.

$P := QA$ とおくと,

  $$ A = \dfrac{P}{Q} $$

の関係式が成り立つ.

よって,

  $$ a_N = \left[X^N \right] A = \left[X^N \right] \dfrac{P}{Q} $$

である.

$P, Q$ は高々 $d$ 次の多項式であるので, [分数式の $N$ 次の係数を求める](Fraction_Coefficient.hpp) アルゴリズムにより, $a_N$ を $O(d \log d \log N)$ 時間で求めることができる.

## Contents
```cpp
modint<Mod> Nth_Term_of_Linearly_Recurrent_Sequence(const vector<modint<Mod>> &a, const vector<modint<Mod>> &c, ll n, ll offset = 0)
```

* 以下の $(d+1)$ 項間線形漸化式 (*) を満たす列 $a = (a_n)$ の第 $N$ 項 $a_N$ を求める.

$$ a_n = \sum_{k=0}^{d-1} c_k a_{n-(k+1)} \quad (n \geq d) \quad (*) $$

* **計算量** : $O(d \log d \log N)$ 時間

