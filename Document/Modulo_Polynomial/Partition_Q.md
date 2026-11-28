---
title: 分割数 (Q)
documentation_of: //Modulo_Polynomial/Partition_Q.hpp
---

## Outline

$n = 0, 1, 2, \dots, N$ それぞれに対して, $n$ を相異なる正の整数で分割する方法 (順序違いは同一視) の数 $q_n$ を求める.

## Definition

以下を満たす正の整数列 $(a_i)$ の数を $q_n$ とする.

* $(a_i)$ は狭義単調増加である.
* 総和が $n$ である.

## Theory

これは [Subset Sum (多項式)](Subset_sum.hpp) における $A = (1, 2, \dots, N)$ の場合である特殊パターンである.

## Contents

```cpp
template<typename mint>
vector<mint> Partition_Q(int N)
```

* $n = 0, 1, 2, \dots, N$ に対して, $n$ を相異なる正の整数で分割する方法 (順序違いは同一視) の数 $q_n$ を求める.
* **計算量** : $O(N \log N)$ 時間
