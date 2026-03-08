---
title: Hamming 距離
documentation_of: //Sequence/Hamming_Distance.hpp
---

## Outline

同じ長さの列に対する Hamming 距離を求める.

## Define

$T$ を集合として, $A = (A_i)\_{i=1}^n, B = (B_i)\_{i=1}^n$ を長さがともに $n$ である $T$ 上の列とする.

このとき, $A, B$ の Hamming 距離を $A_i \neq B_i$ である $1$ 以上 $n$ 以下の整数 $i$ の数と定義する.

## Contents

```cpp
template<typename T>
size_t Hamming_Distance(const std::vector<T> &A, const std::vector<T> &B)
```

* $T$ 上の列 $A, B$ の Hamming 距離を求める.
* **制約**
  * $A, B$ は長さが等しくなければならない.
* **返り値**: $A, B$ の Hamming 距離を求める.
* **計算量**: $O(\lvert A \rvert)$ 時間.

```cpp
size_t Hamming_Distance(const std::string &S, const std::string &T)
```


* 文字列 $S, T$ の Hamming 距離を求める.
* **制約**
  * $S, T$ は長さが等しくなければならない.
* **返り値**: $S, T$ の Hamming 距離を求める.
* **計算量**: $O(\lvert S \rvert)$ 時間.