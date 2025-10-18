---
title: Bell 数
documentation_of: //Modulo_Polynomial/Bell_Number.hpp
---

## Outline

$n = 0, 1, 2, \dots, N$ における Bell 数 $B_n$ を高速に求める.

## Theory

$\{1, 2, \dots, n\}$ の分割の数を $n$ 番目の Bell 数 $B_n$ として定義された数列 $(B_n)_{n \geq 0}$ を Bell 数という.

Bell 数について, 以下が成り立つ.

$$ \sum_{n=0}^\infty B_n X^n = \exp(\exp(X) - 1)$$

## Contents

```cpp
vector<modint<Mod>> Bell_Number(int N)
```

* $n = 0, 1, 2, \dots, N$ における Bell 数の第 $n$ 項 $B_n$ を $\textrm{Mod}$ で割った余りを求める.
