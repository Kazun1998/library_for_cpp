---
title: 三角形の重心
documentation_of: //Geometry/triangle_center/Centroid.hpp
---

## Outline

三角形 $\textrm{A}\textrm{B}\textrm{C}$ の重心 $\textrm{G}$ を求める.

## Theory

以下, 点とその位置ベクトルを同一視する.

<div class="theorem" markdown="1">

定理 1
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ において, 線分 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ の中点をそれぞれ $\textrm{L}, \textrm{M}, \textrm{N}$ とおく.

このとき, 線分 $\textrm{A}\textrm{L}, \textrm{B}\textrm{M}, \textrm{C}\textrm{N}$ は一点で交わる. さらに, その交点は

$$ \dfrac{\textrm{A} + \textrm{B} + \textrm{C}}{3} $$

である.

</div>

<div class="proof" markdown="1">

証明
---

$\boldsymbol{b} = \overrightarrow{\textrm{A}\textrm{B}}, \boldsymbol{c} = \overrightarrow{\textrm{A}\textrm{C}}$ とおく. $\textrm{A}, \textrm{B}, \textrm{C}$ は三角形を成すので, $\boldsymbol{b}, \boldsymbol{c}$ は一次独立である. また,

$$ \overrightarrow{\textrm{A}\textrm{L}} = \dfrac{1}{2} \boldsymbol{b} + \dfrac{1}{2} \boldsymbol{c}, \quad \overrightarrow{\textrm{A}\textrm{M}} = \dfrac{1}{2} \boldsymbol{c} $$

である.

まず, 直線 $\textrm{A}\textrm{L}$ と直線 $\textrm{B}\textrm{M}$ の交点を求める. 直線 $\textrm{A}\textrm{L}$ 上の点 $\textrm{X}$ は, 実数 $s$ を用いて

$$ \overrightarrow{\textrm{A}\textrm{X}} = s \overrightarrow{\textrm{A}\textrm{L}} = \dfrac{s}{2} \boldsymbol{b} + \dfrac{s}{2} \boldsymbol{c} $$

と表せる. 同様に, 直線 $\textrm{B}\textrm{M}$ 上の点 $\textrm{X}$ は, 実数 $t$ を用いて

$$ \overrightarrow{\textrm{A}\textrm{X}} = \overrightarrow{\textrm{A}\textrm{B}} + t \overrightarrow{\textrm{B}\textrm{M}} = \boldsymbol{b} + t \left(\dfrac{1}{2} \boldsymbol{c} - \boldsymbol{b} \right) = (1 - t) \boldsymbol{b} + \dfrac{t}{2} \boldsymbol{c} $$

と表せる. $\boldsymbol{b}, \boldsymbol{c}$ は一次独立であるから, 点 $\textrm{X}$ が $2$ 直線の交点であることは, 係数を比較して

$$ \dfrac{s}{2} = 1 - t, \quad \dfrac{s}{2} = \dfrac{t}{2} $$

を満たす実数 $s, t$ が存在することと同値である. これを解くと $s = t = \dfrac{2}{3}$ がただ一つの解である. よって, $2$ 直線はただ一点で交わり, その交点 $\textrm{G}$ は

$$ \overrightarrow{\textrm{A}\textrm{G}} = \dfrac{1}{3} \boldsymbol{b} + \dfrac{1}{3} \boldsymbol{c} = \dfrac{1}{3} \left(\overrightarrow{\textrm{A}\textrm{B}} + \overrightarrow{\textrm{A}\textrm{C}} \right) $$

すなわち

$$ \textrm{G} = \dfrac{\textrm{A} + \textrm{B} + \textrm{C}}{3} $$

である. さらに, $0 \leq s \leq 1, 0 \leq t \leq 1$ であるから, $\textrm{G}$ は線分 $\textrm{A}\textrm{L}$ 上にも線分 $\textrm{B}\textrm{M}$ 上にもある.

次に, 線分 $\textrm{C}\textrm{N}$ も $\textrm{G}$ を通ることを示す. $\textrm{N} = \dfrac{\textrm{A} + \textrm{B}}{2}$ であるから,

$$ \textrm{G} = \dfrac{\textrm{A} + \textrm{B} + \textrm{C}}{3} = \dfrac{1}{3} \textrm{C} + \dfrac{2}{3} \cdot \dfrac{\textrm{A} + \textrm{B}}{2} = \dfrac{1}{3} \textrm{C} + \dfrac{2}{3} \textrm{N} $$

である. 係数 $\dfrac{1}{3}, \dfrac{2}{3}$ はともに $0$ 以上 $1$ 以下で, 和が $1$ であるから, $\textrm{G}$ は線分 $\textrm{C}\textrm{N}$ 上の点である.

以上から, 線分 $\textrm{A}\textrm{L}, \textrm{B}\textrm{M}, \textrm{C}\textrm{N}$ は一点 $\textrm{G}$ で交わり, $\textrm{G} = \dfrac{\textrm{A} + \textrm{B} + \textrm{C}}{3}$ である.

</div>

<div class="definition" markdown="1">

定義 2
---

定理 1 における交点 $\textrm{G}$ を, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の重心という.

</div>

定理 1 より, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の重心 $\textrm{G}$ は

$$ \textrm{G} = \dfrac{\textrm{A} + \textrm{B} + \textrm{C}}{3} $$

によって計算できる.

## Contents

```cpp
template<typename R>
Point<R> Centroid(const Triangle<R> &T)
```

* 三角形 $\textrm{T}$ の重心を求める.
* **計算量**
  * $O(1)$.
