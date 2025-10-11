---
title: 最長増加部分列
documentation_of: //Sequence/Longest_Increasing_Subsequence.hpp
---

## Outline

全順序集合 $O$ の列 $A = (A_1, A_2, \dots, A_N)$ における最長増加部分列の長さ及びその一例を求める.

## Define

* $O$ 上の列 $B = (B_1, \dots, B_M)$ が $ B_1 < B_2 < \dots < B_M $ であるとき, $B$ は増加列であるという.
* 全順序集合 $O$ の列 $A = (A_1, A_2, \dots, A_N)$ の部分列 $B$ が増加列であるとき, $B$ は $A$ の部分増加列であるという.
* 全順序集合 $O$ の列 $A = (A_1, A_2, \dots, A_N)$ の部分列 $B$ が以下をみたすとき, $B$ は $A$ の最長増加部分列であるという.
  * $B$ は $A$ の部分増加列である.
  * $B$ より真に長い $A$ の部分増加列が存在しない.

## Contents

```cpp
template<typename O>
Longest_Increasing_Subsequence(const vector<O> &data, bool equal = false)
```

* $O$ 上の列 `data` の最長増加部分列の長さとその一例を求める.
* **引数**
  * `equal`: `true` にすると, 最長増加部分列の条件における $<$ が $\leq$ になる.
* **返り値**: 以下をインスタンス変数に持つインスタンス
  * `length`: 最長増加部分列の長さ
  * `lis`: 最長増加部分列の一例
  * `index`: `lis` における各要素の添字番号からなる列
* **計算量**: $N$ を `data` の長さとして, $O(N \log N)$ 時間