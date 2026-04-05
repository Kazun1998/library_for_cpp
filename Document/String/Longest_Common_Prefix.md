---
title: Longest Common Prefix (接尾辞における最長共通接頭辞)
documentation_of: //String/Longest_Common_Prefix.hpp
---

## Outline

列 $A$ に対する接尾辞配列で互いに隣り合うもの同士の Longest Common Prefix の長さを求める.

## Theory

以下のように記号を定義する.

* 列 $A$ の長さを $N$ とする.
* $A$ における第 $i$ 接尾辞を $B_i$ とする.
* $A$ における接尾辞配列を $(S_1, \dots, S_N)$ とする.
* $B_{S_i}$ と $B_{S_{i+1}}$ の最長共通接頭辞の長さを $L_i$ とする.

このとき, 以下が成り立つ.

* $i < j$ とする. このとき, $B_{S_i}$ と $B_{S_j}$ の最長共通接頭辞の長さは
  $$ \min(B_{S_i}, B_{S_{i+1}}, \dots, B_{S_{j-1}}) $$
である.

## Contents

```cpp
template<integral T>
vector<int> Longest_Common_Prefix(const vector<T> &A)
```

* 整数型 $T$ 上の列 $A$ に対する Longes Common Prefix の長さを求める.
* **返り値**
  * $N := \lvert A \rvert$ とする.
  * 返り値は長さ $(N-1)$ の配列 $P$.
  * $A$ の接尾辞配列を $S = (S_1, S_2, \dots, S_N)$ としたとき, $P_i$ は ${A[S_i:N]}$ と ${A[S_{i+1}:N]}$ の最長共通接頭辞の長さをである.
* **計算量**: $N := \lvert A \rvert$ として, $O(N \log N)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/04/05| Longest_Suffix_Prefix 実装 |
