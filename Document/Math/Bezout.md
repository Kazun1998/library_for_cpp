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

## History 

|日付|内容|
|:---:|:---:|
|2026/01/24| Bezout の等式に関する実装 |
