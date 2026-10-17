---
title: 整数係数の多項式による不等式
documentation_of: //Integer/Integer_Inequality.hpp
---

## Outline

整数 $l$ 以上の範囲で狭義単調増加な非定数多項式

  $$ P(x) = p_0 + p_1 x + \dots + p_{n-1} x^{n-1} $$

と整数 $y$ に対して, 不等式 $P(x) \leq y$ (または $P(x) < y$) を満たす最大の整数 $x \geq l$ を二分探索で求める.

多項式の評価の方法 (Horner 法, オーバーフローを避けるための打ち切り) は [Integer_Equation](Integer_Equation.hpp) と同一である. 詳細はそちらを参照.

## Theory

$P$ は $[l, \infty)$ 上で狭義単調増加であるため, 条件を満たす $x \geq l$ の全体は $l$ から始まる区間である. よって, 条件を満たす最大の $x$ は二分探索で求まる. 二分探索の上界は, 条件を満たさなくなる $l + d$ ($d$ は $2$ の冪) として求める.

## Contents

```cpp
template<unsigned_integral T>
optional<T> Integer_Inequality(vector<T> P, const T y, const T l = 0, const bool equal = true)
```

* 符号なし整数版. $\mathrm{equal}$ が `true` のときは $P(x) \leq y$, `false` のときは $P(x) < y$ を満たす最大の整数 $x \geq l$ を求める.
* **制約**
  * $P$ の最高次の係数 $0$ は取り除かれる. その結果, $P$ は $1$ 次以上でなくてはならない.
  * $y + 1$ と $l + 2d$ ($d$ は上界の探索で得られる値) が `T` の範囲内であること. 目安として, $y$ が `T` の最大値の約半分以下であること.
* **返り値**: 存在する場合はその値, 存在しない場合 ($x = l$ でも条件を満たさない場合) は `nullopt`.
* **計算量**: 答えを $x^\ast$ として $O(n \log (x^\ast - l + 1))$ 時間 ($n$ は $P$ の長さ).

```cpp
template<signed_integral T>
optional<T> Integer_Inequality(vector<T> P, const T y, const T l = 0, const bool equal = true)
```

* 符号付き整数版. $\mathrm{equal}$ が `true` のときは $P(x) \leq y$, `false` のときは $P(x) < y$ を満たす最大の整数 $x \geq l$ を求める.
* **制約**
  * $P$ は $[l, \infty)$ 上で狭義単調増加でなくてはならない. 係数, $l$, $y$ は負でもよい.
  * $P$ の最高次の係数 $0$ は取り除かれる. その結果, $P$ は $1$ 次以上でなくてはならない.
  * $2 \max(C, \lvert y \rvert) + \lvert l \rvert$ が `T` の範囲内であること ($C$ は係数の絶対値の最大値).
* **返り値**: 存在する場合はその値, 存在しない場合 ($x = l$ でも条件を満たさない場合) は `nullopt`.
* **計算量**: 答えを $x^\ast$ として $O(n \log (x^\ast - l + 1))$ 時間 ($n$ は $P$ の長さ).
