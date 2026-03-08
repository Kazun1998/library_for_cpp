---
title: Bezout の等式
documentation_of: //Math/Bezout.hpp
---

## Outline

整数 $a, b, c \in \mathbb{Z}$ に関して, $x, y \in \mathbb{Z}$ に関する方程式 $ax+by=c$ に関する計算を行う.

## Theory

整数 $a, b, c \in \mathbb{Z}$ に関して, 以下は同値になる.

* (a) $x, y \in \mathbb{Z}$ に関する不定方程式 $ax+by=c$ は解を持つ.
* (b) $g := \gcd(a, b)$ とすると, $c$ は $g$ の倍数である.

特に, $a, b$ が互いに素ならば, $ax+by=1$ は整数解 $(x, y) = (x_0, y_0)$ を持つ. このとき, $ax+by=1, ax_0+by_0=1$ を両辺引くと

$$ a (x-x_0) + b(y-y_0) = 0 \quad \therefore a(x-x_0) = -b(y-y_0)$$

となる. このとき, $a,b$ は互いに素なので, $x-x_0$ は $b$ の倍数にならなければならない.

つまり, ある整数 $k$ を用いて, $x-x_0 = bk$ と表せる. これを代入して, 整理すると, $y-y_0=-ak$ も導ける.

よって,

$$ x = x_0 + bk, \quad y = y_0 - ak \quad (k \in \mathbb{Z}) $$

となる. 逆に, こう表せる整数の組 $(x, y)$ は不定方程式の解になる.

## Contents

### Find_Particular_Solution
```cpp
template<integral T>
optional<pair<T, T>> Find_Particular_Solution(const T a, const T b, const T c, const pair<T, T> &hint)
```
```cpp
template<integral T>
optional<pair<T, T>> Find_Particular_Solution(const T a, const T b, const T c)
```

* $x, y$ に関する整数方程式 $ax+by=c$ を満たす整数解 $(x, y)$ の一例を求める.
* `hint` として, $ap+bq=\gcd(a,b)$ を満たす整数の組 $(p, q)$ を与えると, 一部の計算をスキップできる (同じ $a, b$ に関する沢山の計算を行う場合に有効).

### Solve
```cpp
template<integral T>
optional<tuple<T, T, T, T, T, T>> Solve(T a, T b, T c, const T lx, const T rx, const T ly, const T ry, const pair<T, T> &hint)
```
```cpp
template<integral T>
optional<tuple<T, T, T, T, T, T>> Solve(T a, T b, T c, const T lx, const T rx, const T ly, const T ry)
```

* $x, y$ に関する整数方程式 $ax+by=c$ を満たす整数解 $(x, y)$ の解を求める.
* **返り値**
  * 解が存在しない場合は `nullopt`.
  * 解が存在する場合, 6-tuple $(x_0, x_1, y_0, y_1, k_l, k_r)$ が返される. これは以下を意味している.
    * $x = x_0 + k x_1$.
    * $y = y_0 + k y_1$.
    * $k_l \leq k \leq k_r$.
* `hint` として, $ap+bq=\gcd(a,b)$ を満たす整数の組 $(p, q)$ を与えると, 一部の計算をスキップできる (同じ $a, b$ に関する沢山の計算を行う場合に有効).

### Count_Solutions
```cpp
template<integral T>
T Count_Solutions(const T a, const T b, const T c, const T lx, const T rx, const T ly, const T ry, const pair<T, T> &hint)
```
```cpp
template<integral T>
T Count_Solutions(const T a, const T b, const T c, const T lx, const T rx, const T ly, const T ry)
```

* $x, y$ に関する以下の整数方程式を満たす整数解 $(x, y)$ の解を求める.
  * $ax+by=c$.
  * $l_x \leq x \leq r_x$.
  * $l_y \leq y \leq r_y$.
* `hint` として, $ap+bq=\gcd(a,b)$ を満たす整数の組 $(p, q)$ を与えると, 一部の計算をスキップできる (同じ $a, b$ に関する沢山の計算を行う場合に有効).

### Find_Non_Negative_Solution
```cpp
template<integral T>
optional<pair<T, T>> Find_Non_Negative_Solution(const T a, const T b, const T c, const pair<T, T> &hint)
```
```cpp
template<integral T>
optional<pair<T, T>> Find_Non_Negative_Solution(const T a, const T b, const T c)
```

* $x, y$ に関する整数方程式 $ax+by=c$ を満たす**非負の**整数解 $(x, y)$ の一例を求める.
* `hint` として, $ap+bq=\gcd(a,b)$ を満たす整数の組 $(p, q)$ を与えると, 一部の計算をスキップできる (同じ $a, b$ に関する沢山の計算を行う場合に有効).
* **返り値**
  * 解が存在しない場合は `nullopt`.
  * 解が存在する場合は非負整数解 $(x, y)$.

## History 

|日付|内容|
|:---:|:---:|
|2026/01/24| Bezout の等式に関する実装 |
