---
title: 三角形の外心
documentation_of: //Geometry/triangle_center/Circumcenter.hpp
---

## Outline

三角形 $\textrm{A}\textrm{B}\textrm{C}$ の外心 $\textrm{O}$ を求める.

## Theory

以下, 点とその位置ベクトルを同一視する.

<div class="theorem" markdown="1">

定理 1
---

同一直線上にない $3$ 点 $\textrm{A}, \textrm{B}, \textrm{C}$ について,

$$ d(\textrm{O}, \textrm{A}) = d(\textrm{O}, \textrm{B}) = d(\textrm{O}, \textrm{C}) $$

なる点 $\textrm{O}$ がただ一つ存在する.

</div>

<div class="proof" markdown="1">

証明
---

線分 $\textrm{A}\textrm{B}$ に関する垂直二等分線を $\ell$, 線分 $\textrm{A}\textrm{C}$ に関する垂直二等分線を $m$ とする.

さて, $\ell$ とは, $d(\textrm{P}, \textrm{A}) = d(\textrm{P}, \textrm{B})$ となる点 $\textrm{P}$ の軌跡である. $m$ についても同様である.

すると, 点 $\textrm{P}$ について,

$$\begin{align*}
d(\textrm{P}, \textrm{A}) = d(\textrm{P}, \textrm{B}) = d(\textrm{P}, \textrm{C})
&\iff d(\textrm{P}, \textrm{A}) = d(\textrm{P}, \textrm{B}) \land d(\textrm{P}, \textrm{A}) = d(\textrm{P}, \textrm{C}) \\
&\iff \textrm{P} \in \ell \land \textrm{P} \in m \\
&\iff \textrm{P} \in \ell \cap m
\end{align*}$$

となる. よって, 点 $\textrm{P}$ が条件を満たすことは, $\textrm{P}$ が $\ell, m$ の共有点であることと同値である.

$\ell$ は直線 $\textrm{A}\textrm{B}$ に垂直で, $m$ は直線 $\textrm{A}\textrm{C}$ に垂直である. $\textrm{A}, \textrm{B}, \textrm{C}$ は同一直線上にないので, 直線 $\textrm{A}\textrm{B}$ と直線 $\textrm{A}\textrm{C}$ は平行でなく, 一致もしない. よって, $\ell, m$ も平行でなく, 一致もしないから, $\ell, m$ はただ一点で交わる. すなわち, 共有点はただ一つである.

これにより, 存在性と一意性が示せた.

</div>

<div class="definition" markdown="1">

定義 2
---

同一直線上にない $3$ 点 $\textrm{A}, \textrm{B}, \textrm{C}$ について, $d(\textrm{O}, \textrm{A}) = d(\textrm{O}, \textrm{B}) = d(\textrm{O}, \textrm{C})$ を満たすただ一つの点 $\textrm{O}$ を, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の外心という.

</div>

次の系によって外心を具体的に計算することが可能になる.

<div class="corollary" markdown="1">

系 3
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ の外心 $\textrm{O}$ は, 線分 $\textrm{A}\textrm{B}$ の垂直二等分線と線分 $\textrm{A}\textrm{C}$ の垂直二等分線のただ一つの交点である.

</div>

<div class="proof" markdown="1">

証明
---

定理 1 の証明より, 点 $\textrm{P}$ について $d(\textrm{P}, \textrm{A}) = d(\textrm{P}, \textrm{B}) = d(\textrm{P}, \textrm{C})$ であることと $\textrm{P}$ が $2$ 本の垂直二等分線の共有点であることは同値であり, その共有点はただ一つである. よって, 外心 $\textrm{O}$ は $2$ 本の垂直二等分線のただ一つの交点である.

</div>

## Contents

```cpp
template<typename R>
Point<R> Circumcenter(const Triangle<R> &T)
```

* 三角形 $\textrm{T}$ の外心を求める.
* **計算量**
  * $O(1)$.
