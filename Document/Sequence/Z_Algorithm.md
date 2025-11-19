---
title: 最長共通接頭辞 (Z-Algorithm)
documentation_of: //Sequence/Z_Algorithm.hpp
---

## Outline

Z Algorithm を用いて, $i = 1, 2, \dots, \lvert S \rvert$ に対する以下を合計で $O\left(\lvert S \rvert \right)$ 時間で求める.

* $S$ と $S[i:]$ の最長共通接頭辞の長さ

## Define

* 列 $T$ が列 $S$ の接頭辞であるとは, 以下を満たすことである.
  * $\lvert T \rvert \leq \lvert S \rvert$.
  * $S_i = T_i \quad (i = 1, 2, \dots, \lvert T \rvert)$.
* 列 $U$ が列 $S, T$ の接頭辞であるとき, $U$ は $S, T$ の共通接頭辞であるという.
* 列 $S, T$ の接頭辞のうち, 長さが最大である列がただ一つ存在する. その列を $S, T$ の最長共通接頭辞という.

## Contents

```cpp
template<typename T>
vector<int> Z_Algorithm(const vector<T> &data)
```

* $T$ 上の列 `data` に関して, 以下を計算する.
  * $i = 0, 1, \dots, (n-1)$ に対して, `data` と `data` の 第 $i$ 要素目以降における最長接頭辞の長さを求める.
* 長さ $n$ からなる `vector<int>` 型の列. 第 $i$ 要素目は以下を表す.
  * `data` と `data` の第 $i$ 要素目以降における最長接頭辞の長さ
* **計算量**: $O(n)$ 時間.

```cpp
vector<int> Z_Algorithm(const string &str)
```

* 文字列 $S$ に対して, 以下を計算する.
  * $i = 0, 1, \dots, (n-1)$ に対して, $S$ と $S$ の $i$ 文字目以降における最長接頭辞の長さを求める.
* 長さ $n$ からなる `vector<int>` 型の列. 第 $i$ 要素目は以下を表す.
  * $S$ と $S$ の $i$ 文字目以降における最長接頭辞の長さ
* **計算量**: $O(\lvert S \rvert)$ 時間.
