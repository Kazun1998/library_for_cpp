---
title: 分割数 (P)
documentation_of: //Modulo_Polynomial/Partition_P.hpp
---

## Outline

$n = 0, 1, 2, \dots, N$ に対する分割数 $p_n$ を求める.

## Definition

以下を満たす正の整数列 $(a_i)$ を, $n$ の分割という.

* $(a_i)$ は広義単調増加である.
* 総和が $n$ である.

また, $n$ の分割の数を $n$ の分割数という.

## Theory

$p = (p_n)$ の母関数を $P$ とする.

各 $k$ について, $k$ を何個使うかを考えることにより, 分割に $k$ を使う部分を表す形式的ベキ級数は

$$ \sum_{m=0}^\infty \left(X^k \right)^m = \dfrac{1}{1-X^k} $$

である.

これを全ての正の整数について考えると, $P$ そのものになる. つまり,

$$ P(X) = \prod_{k=1}^\infty \dfrac{1}{1-X^k} = \dfrac{1}{\prod_{k=1}^\infty (1-X^k) }$$

となる.

ここで, 分母について, 五角数定理

$$ \prod_{k=1}^\infty (1-X^k) = \sum_{k=-\infty}^\infty (-1)^k X^{\frac{k(3k-1)}{2}}$$

を用いることによって, 分母の多項式を $O(\sqrt{N})$ 時間で構築できる.

よって, $P$ はこの多項式の逆元を求めるパートがボトルネックとして, $O(N \log N)$ 時間で求められる.

## Contents

```cpp
vector<mint> Partitions_P(int N)
```

* $n = 0, 1, 2, \dots, N$ における分割数 $p_N$ を求める.
* **計算量** : $O(N \log N)$ 時間
