---
title: Suffix Array (接尾辞配列)
documentation_of: //String/Suffix_Array.hpp
---

## Outline

列 $A$ に対する Suffix Array を求める.

## Definition

$O$ を全順序集合とする.

* $O$ 上の列 $A = (A_1, \dots, A_N)$ に対して, ある $1$ 以上 $(N+1)$ 以下の整数 $i$ を用いて $(A_i, A_{i+1}, \dots, A_N)$ と表される列を $A$ の接尾辞という.
* $O$ 上の列 $A$ における $N$ 個の空ではない接尾辞を辞書式順序昇順に並べた長さ $N$ の列を $A$ の接尾辞配列という. なお, 異なる始点同士の接尾辞は互いに長さが異なるため, 接尾辞配列は一意である.

## Contents

```cpp
template<integral T>
vector<int> Suffix_Array(const vector<T> &A)
```

* 整数型 $T$ 上の列 $A$ に対する Suffix Array を求める.
* **計算量**: $N := \lvert A \rvert$ として, $O(N \log N)$ 時間

```cpp
template<typename T>
requires (!integral<T>)
vector<int> Suffix_Array(const vector<T> &A)
```

* 一般的な全順序 $T$ 上の列 $A$ に対する Suffix Array を求める.
* **計算量**: $N := \lvert A \rvert$ として, $O(N \log N)$ 時間

```cpp
vector<int> Suffix_Array(const string &S)
```

* 文字列 $S$ に対する Suffix Array を求める.
* **計算量**: $N := \lvert S \rvert$ として, $O(N \log N)$ 時間

## History

|日付|内容|
|:---:|:---|
|2026/04/05| Suffix Array 実装 |
