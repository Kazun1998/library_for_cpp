---
title: 三角形の外接円
documentation_of: //Geometry/triangle_center/Circumcircle.hpp
---

## Outline

三角形 $\textrm{A}\textrm{B}\textrm{C}$ の外接円を求める.

## Theory

中心 $\textrm{P}$, 半径 $r$ の円とは, $d(\textrm{P}, \textrm{X}) = r$ を満たす点 $\textrm{X}$ 全体のことである ( $r > 0$ ).

<div class="theorem" markdown="1">

定理 1
---

同一直線上にない $3$ 点 $\textrm{A}, \textrm{B}, \textrm{C}$ について, $3$ 点 $\textrm{A}, \textrm{B}, \textrm{C}$ をすべて通る円がただ一つ存在する.

</div>

<div class="proof" markdown="1">

証明
---

中心 $\textrm{P}$, 半径 $r$ の円が $3$ 点 $\textrm{A}, \textrm{B}, \textrm{C}$ をすべて通ることは,

$$ d(\textrm{P}, \textrm{A}) = d(\textrm{P}, \textrm{B}) = d(\textrm{P}, \textrm{C}) = r $$

と同値である.

[三角形の外心](Circumcenter.hpp) の定理 1 より, $d(\textrm{P}, \textrm{A}) = d(\textrm{P}, \textrm{B}) = d(\textrm{P}, \textrm{C})$ を満たす点 $\textrm{P}$ はただ一つ存在する. その点を $\textrm{O}$ とおく. よって, 条件を満たす円の中心は $\textrm{O}$ でなければならず, そのとき半径は $r = d(\textrm{O}, \textrm{A})$ に定まる. したがって, 条件を満たす円は高々一つである.

逆に, 中心 $\textrm{O}$, 半径 $d(\textrm{O}, \textrm{A})$ の円を考える. もし $d(\textrm{O}, \textrm{A}) = 0$ ならば, $d(\textrm{O}, \textrm{B}) = d(\textrm{O}, \textrm{A}) = 0$ より $\textrm{A} = \textrm{O} = \textrm{B}$ となり, $\textrm{A}, \textrm{B}, \textrm{C}$ が同一直線上にないことに反する. よって $d(\textrm{O}, \textrm{A}) > 0$ であり, これは円である. さらに $d(\textrm{O}, \textrm{A}) = d(\textrm{O}, \textrm{B}) = d(\textrm{O}, \textrm{C})$ であるから, この円は $3$ 点 $\textrm{A}, \textrm{B}, \textrm{C}$ をすべて通る.

以上から, 条件を満たす円はただ一つ存在する.

</div>

<div class="definition" markdown="1">

定義 2
---

同一直線上にない $3$ 点 $\textrm{A}, \textrm{B}, \textrm{C}$ について, $3$ 点 $\textrm{A}, \textrm{B}, \textrm{C}$ をすべて通るただ一つの円を, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の外接円という.

</div>

次の系によって外接円を具体的に計算することが可能になる.

<div class="corollary" markdown="1">

系 3
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ の外心を $\textrm{O}$ とする. このとき, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の外接円は, 中心 $\textrm{O}$, 半径 $d(\textrm{O}, \textrm{A})$ の円である.

</div>

<div class="proof" markdown="1">

証明
---

定理 1 の証明から従う.

</div>

外心 $\textrm{O}$ は [三角形の外心](Circumcenter.hpp) の方法で求められる.

## Contents

```cpp
template<typename R>
Circle<R> Circumcircle(const Triangle<R> &T)
```

* 三角形 $\textrm{T}$ の外接円を求める.
* **計算量**
  * $O(1)$.
