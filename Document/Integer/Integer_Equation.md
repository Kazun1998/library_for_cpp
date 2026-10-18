---
title: 整数係数の多項式による方程式
documentation_of: //Integer/Integer_Equation.hpp
---

## Outline

整数 $l$ 以上の範囲で狭義単調増加な非定数多項式

  $$ P(x) = p_0 + p_1 x + \dots + p_{n-1} x^{n-1} $$

と整数 $y$ に対して, 方程式 $P(x) = y$ を満たす整数 $x \geq l$ を二分探索で求める.

## Theory

### アルゴリズム

$P$ は $[l, \infty)$ 上で狭義単調増加であるため, $P(x) = y$ を満たす $x \geq l$ は存在すれば一意であり, $P(x) \leq y$ を満たす最大の $x$ に一致する. そのため, この $x$ を二分探索で求め, $P(x) = y$ であるかを確認すればよい. 二分探索の上界は, $P(l + d) > y$ となる最小の $2$ の冪 $d$ を用いて $l + d$ とする.

### 多項式の評価とオーバーフローの回避

$P(x)$ は Horner 法

  $$ v_{n} := 0, \quad v_{i} := v_{i+1} x + p_i \quad (i = n-1, \dots, 0) $$

で評価する ($P(x) = v_0$). 途中値が `T` の範囲を超えないように, 以下のように打ち切る.

#### 符号なし整数の場合

$x \geq 1$ のとき, 係数と $x$ が $0$ 以上であるため, 途中値は非減少である. よって, 途中で $v_i > y$ となった時点で $P(x) > y$ が確定する. $x = 0$ のときは, 途中値が $y$ を超えても最終値は $P(0) = p_0$ であるため, 打ち切らずに $p_0$ をそのまま評価値とする.

$v_{i+1} x + p_i \leq y$ の判定は, 掛け算をせずに

  $$ p_i \leq y \quad \text{かつ} \quad v_{i+1} \leq \left\lfloor \dfrac{y - p_i}{x} \right\rfloor \quad (x > 0) $$

で行うため, オーバーフローは起こらない ($x \geq 1$).

#### 符号付き整数の場合

$C := \max_i \lvert p_i \rvert$, $B := \max(C, \lvert y \rvert)$ とする.

<div class="theorem" markdown="1">

定理 1
---

$\lvert x \rvert \geq 2$ とする. ある $i$ で $\lvert v_{i+1} \rvert > B$ ならば, $\lvert P(x) \rvert > B$ であり, $P(x)$ の符号は $v_{i+1}$ の符号と, $x < 0$ かつ残りの乗算回数 $i + 1$ が奇数であるか否かで定まる.

</div>

<div class="proof" markdown="1">

証明
---

$\lvert v_{i+1} \rvert > C$ とすると,

  $$ \lvert v_i \rvert \geq \lvert v_{i+1} \rvert \lvert x \rvert - \lvert p_i \rvert \geq 2 \lvert v_{i+1} \rvert - C > \lvert v_{i+1} \rvert $$

であり, $v_i$ の符号は $v_{i+1} x$ の符号に等しい. 以降も同様に, $\lvert v \rvert$ は真に増え続け, 符号は $x$ の符号のみで決まる. したがって $\lvert P(x) \rvert = \lvert v_0 \rvert > B \geq \lvert y \rvert$ である.

</div>

そのため, $\lvert v \rvert > B$ となった時点で $P(x)$ と $y$ の大小が確定する. 掛け算がオーバーフローしうる場合 ($\lvert v \rvert > (\mathrm{MAX} - C) / \lvert x \rvert$) も同様に打ち切る.

* $P(x) > y$ と確定した場合は $y + 1$ を, $P(x) < y$ と確定した場合は $y - 1$ を評価値とする.
* $\lvert x \rvert \leq 1$ のときは値が膨らまないため, そのまま評価する.

## Contents

```cpp
template<unsigned_integral T>
optional<T> Integer_Equation(vector<T> P, const T y, const T l = 0)
```

* 符号なし整数版. $P(x) = y$ を満たす整数 $x \geq l$ を求める.
* **制約**
  * $P$ の最高次の係数 $0$ は取り除かれる. その結果, $P$ は $1$ 次以上でなくてはならない.
  * $y + 1$ と $l + 2d$ ($d$ は上界の探索で得られる値) が `T` の範囲内であること. 目安として, $y$ が `T` の最大値の約半分以下であること.
* **返り値**: 解が存在する場合はその値, 存在しない場合は `nullopt`.
* **計算量**: 解を $x^\ast$ として $O(n \log (x^\ast - l + 1))$ 時間 ($n$ は $P$ の長さ).

```cpp
template<signed_integral T>
optional<T> Integer_Equation(vector<T> P, const T y, const T l = 0)
```

* 符号付き整数版. $P(x) = y$ を満たす整数 $x \geq l$ を求める.
* **制約**
  * $P$ は $[l, \infty)$ 上で狭義単調増加でなくてはならない. 係数, $l$, $y$ は負でもよい.
  * $P$ の最高次の係数 $0$ は取り除かれる. その結果, $P$ は $1$ 次以上でなくてはならない.
  * $2 \max(C, \lvert y \rvert) + \lvert l \rvert$ が `T` の範囲内であること.
* **返り値**: 解が存在する場合はその値, 存在しない場合は `nullopt`.
* **計算量**: 解を $x^\ast$ として $O(n \log (x^\ast - l + 1))$ 時間 ($n$ は $P$ の長さ).
