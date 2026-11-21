---
title: 点の直線に関する対称移動
documentation_of: //Geometry/reflection/Reflection_Point_Line.hpp
---

## Outline

直線 $\ell$ に関して点 $\textrm{P}$ と対称な点を求める.

## Theory

<div class="proposition" markdown="1">

命題 1
---

$\textrm{P}$ を点, $\ell$ を直線とする.

以下を満たす $\textrm{Q}$ がただ一つ存在する.

* 線分 $\textrm{P}\textrm{Q}$ の中点が $\ell$ 上にある.
* $\ell$ の方向ベクトルを $\boldsymbol{d}$ としたとき, $\overrightarrow{\textrm{P}\textrm{Q}} \cdot \boldsymbol{d} = 0$ である.

</div>

<div class="proof" markdown="1">

証明
---

$\textrm{A}, \textrm{B}$ を $\ell$ 上の相異なる $2$ 点, $\textrm{H}$ を [$\textrm{P}$ の $\ell$ への射影](../projection/Projection_Point_Line.hpp)とする. $\overrightarrow{\textrm{A}\textrm{B}}$ も $\ell$ の方向ベクトルであるから, $\boldsymbol{d} = c \overrightarrow{\textrm{A}\textrm{B}}$ なる $0$ でない実数 $c$ が存在する.

点 $\textrm{Q}$ に対して, 線分 $\textrm{P}\textrm{Q}$ の中点を $\textrm{M}$ とすると, $\overrightarrow{\textrm{P}\textrm{Q}} \cdot \boldsymbol{d} = 2c \overrightarrow{\textrm{P}\textrm{M}} \cdot \overrightarrow{\textrm{A}\textrm{B}}$ であり, $2c \neq 0$ であるから, $\textrm{Q}$ が条件を満たすことは

* $\textrm{M}$ は $\ell$ 上の点である.
* $\overrightarrow{\textrm{P}\textrm{M}} \cdot \overrightarrow{\textrm{A}\textrm{B}} = 0$ である.

と同値である. [射影の特徴付け](../projection/Projection_Point_Line.hpp) (命題 3) より, これは $\textrm{M} = \textrm{H}$ と同値である.

$\textrm{M} = \textrm{H}$ を満たす $\textrm{Q}$ は, 点 $\textrm{H}$ に関して点 $\textrm{P}$ と対称な点にほかならない. [点に関する対称移動](Reflection_Point_Point.hpp) (命題 2) より, そのような点はただ一つ存在する. よって, 条件を満たす $\textrm{Q}$ はただ一つ存在する.

</div>

<div class="definition" markdown="1">

定義 2
---

$\textrm{P}$ を点, $\ell$ を直線とする.

以下を満たすただ一つの点 $\textrm{Q}$ を, 直線 $\ell$ に関して点 $\textrm{P}$ と対称な点という.

* 線分 $\textrm{P}\textrm{Q}$ の中点が $\ell$ 上にある.
* $\ell$ の方向ベクトルを $\boldsymbol{d}$ としたとき, $\overrightarrow{\textrm{P}\textrm{Q}} \cdot \boldsymbol{d} = 0$ である.

</div>

次の系 3 によって, 直線 $\ell$ に関して点 $\textrm{P}$ と対称な点を具体的に計算することが可能になる.

<div class="corollary" markdown="1">

系 3
---

$\textrm{P}$ を点, $\ell$ を直線とし, $\textrm{H}$ を $\textrm{P}$ の $\ell$ への射影とする.

このとき, 直線 $\ell$ に関して点 $\textrm{P}$ と対称な点 $\textrm{Q}$ は

$$ \textrm{Q} = 2 \textrm{H} - \textrm{P} $$

である.

</div>

<div class="proof" markdown="1">

証明
---

命題 1 の証明より, $\textrm{Q}$ は点 $\textrm{H}$ に関して点 $\textrm{P}$ と対称な点である. よって, $\textrm{Q} = 2 \textrm{H} - \textrm{P}$ である.

</div>

## Contents

```cpp
Point<R> Reflection(const Point<R> &P, const Line<R> &l)
```

* 直線 $\ell$ に関して点 $\textrm{P}$ と対称な点を求める.
* **制約**
  * $\ell$ を定める $2$ 点 $\textrm{A}, \textrm{B}$ について, $\textrm{A} \neq \textrm{B}$.
* **計算量**
  * $O(1)$.
