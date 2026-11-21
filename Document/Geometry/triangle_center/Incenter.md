---
title: 三角形の内心
documentation_of: //Geometry/triangle_center/Incenter.hpp
---

## Outline

三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内心 $\textrm{I}$ を求める.

## Theory

以下, 点とその位置ベクトルを同一視する. また, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の頂点 $\textrm{A}$ における内角の二等分線とは, $\textrm{A}$ を端点とし, 角 $\textrm{B}\textrm{A}\textrm{C}$ を二等分する半直線のことである. 頂点 $\textrm{B}, \textrm{C}$ についても同様である.

<div class="lemma" markdown="1">

補題 1
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ において, 頂点 $\textrm{A}$ における内角の二等分線と辺 $\textrm{B}\textrm{C}$ の交点を $\textrm{D}$ とする. このとき,

$$ d(\textrm{B}, \textrm{D}) : d(\textrm{D}, \textrm{C}) = d(\textrm{A}, \textrm{B}) : d(\textrm{A}, \textrm{C}) $$

である.

</div>

<div class="proof" markdown="1">

証明
---

$\theta = \dfrac{\textrm{A}}{2}$ とおくと, $\angle \textrm{B}\textrm{A}\textrm{D} = \angle \textrm{D}\textrm{A}\textrm{C} = \theta$ である. 三角形 $\textrm{A}\textrm{B}\textrm{D}, \textrm{A}\textrm{D}\textrm{C}$ の面積をそれぞれ $S_1, S_2$ とおく.

三角形 $\textrm{A}\textrm{B}\textrm{D}, \textrm{A}\textrm{D}\textrm{C}$ は, 底辺をそれぞれ $\textrm{B}\textrm{D}, \textrm{D}\textrm{C}$ とすると, 高さはともに $\textrm{A}$ から直線 $\textrm{B}\textrm{C}$ までの距離であるから,

$$ S_1 : S_2 = d(\textrm{B}, \textrm{D}) : d(\textrm{D}, \textrm{C}) $$

である. 一方, $2$ 辺とその間の角を用いて面積を表すと,

$$ S_1 = \dfrac{1}{2} d(\textrm{A}, \textrm{B}) \, d(\textrm{A}, \textrm{D}) \sin \theta, \quad S_2 = \dfrac{1}{2} d(\textrm{A}, \textrm{C}) \, d(\textrm{A}, \textrm{D}) \sin \theta $$

であるから,

$$ S_1 : S_2 = d(\textrm{A}, \textrm{B}) : d(\textrm{A}, \textrm{C}) $$

である. 以上から, $d(\textrm{B}, \textrm{D}) : d(\textrm{D}, \textrm{C}) = d(\textrm{A}, \textrm{B}) : d(\textrm{A}, \textrm{C})$ である.

</div>

<div class="theorem" markdown="1">

定理 2
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ において, 頂点 $\textrm{A}, \textrm{B}, \textrm{C}$ における内角の二等分線は一点で交わる.

</div>

<div class="proof" markdown="1">

証明
---

$a = d(\textrm{B}, \textrm{C}), b = d(\textrm{C}, \textrm{A}), c = d(\textrm{A}, \textrm{B})$ とする.

頂点 $\textrm{A}$ における内角の二等分線と辺 $\textrm{B}\textrm{C}$ の交点を $\textrm{D}$ とする. 補題 1 より $d(\textrm{B}, \textrm{D}) : d(\textrm{D}, \textrm{C}) = c : b$ であるから,

$$ \textrm{D} = \dfrac{b \textrm{B} + c \textrm{C}}{b + c}, \quad d(\textrm{B}, \textrm{D}) = \dfrac{ac}{b + c} $$

である.

次に, 頂点 $\textrm{B}$ における内角の二等分線を考える. $\textrm{D}$ は辺 $\textrm{B}\textrm{C}$ 上にあるので, これは三角形 $\textrm{A}\textrm{B}\textrm{D}$ の頂点 $\textrm{B}$ における内角の二等分線でもある. よって, これは線分 $\textrm{A}\textrm{D}$ とただ一点 $\textrm{I}$ で交わり, 三角形 $\textrm{A}\textrm{B}\textrm{D}$ に補題 1 を適用すると

$$ d(\textrm{A}, \textrm{I}) : d(\textrm{I}, \textrm{D}) = d(\textrm{B}, \textrm{A}) : d(\textrm{B}, \textrm{D}) = c : \dfrac{ac}{b + c} = (b + c) : a $$

である. したがって,

$$ \textrm{I} = \dfrac{a \textrm{A} + (b + c) \textrm{D}}{a + b + c} = \dfrac{a \textrm{A} + b \textrm{B} + c \textrm{C}}{a + b + c} $$

である. 頂点 $\textrm{A}, \textrm{B}$ における内角の二等分線は直線として異なるので, その共有点は $\textrm{I}$ のみである.

頂点 $\textrm{B}$ の代わりに頂点 $\textrm{C}$ における内角の二等分線について同じ議論を行うと, 頂点 $\textrm{A}, \textrm{C}$ における内角の二等分線の交点も, $\textrm{B}$ と $\textrm{C}$ (および $b$ と $c$ ) の役割を入れ替えた $\dfrac{a \textrm{A} + c \textrm{C} + b \textrm{B}}{a + c + b}$, すなわち $\textrm{I}$ である.

以上から, $3$ 本の内角の二等分線は一点 $\textrm{I}$ で交わる.

</div>

<div class="definition" markdown="1">

定義 3
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ において, 頂点 $\textrm{A}, \textrm{B}, \textrm{C}$ における内角の二等分線の交点 $\textrm{I}$ を, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内心という.

</div>

次の系によって内心を具体的に計算することが可能になる.

<div class="corollary" markdown="1">

系 4
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ について, $a = d(\textrm{B}, \textrm{C}), b = d(\textrm{C}, \textrm{A}), c = d(\textrm{A}, \textrm{B})$ とし, 内心を $\textrm{I}$ とする. このとき,

$$ \textrm{I} = \dfrac{a \textrm{A} + b \textrm{B} + c \textrm{C}}{a + b + c} $$

である.

</div>

<div class="proof" markdown="1">

証明
---

定理 2 の証明から従う.

</div>

以下, 内心の性質を述べる.

<div class="corollary" markdown="1">

系 5
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ について, $\alpha = \angle \textrm{A}, \beta = \angle \textrm{B}, \gamma = \angle \textrm{C}$ とし, 内心を $\textrm{I}$ とする. このとき,

$$ \textrm{I} = \dfrac{\sin \alpha \cdot \textrm{A} + \sin \beta \cdot \textrm{B} + \sin \gamma \cdot \textrm{C}}{\sin \alpha + \sin \beta + \sin \gamma} $$

である.

</div>

<div class="proof" markdown="1">

証明
---

$a = d(\textrm{B}, \textrm{C}), b = d(\textrm{C}, \textrm{A}), c = d(\textrm{A}, \textrm{B})$ とし, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の面積を $S$ とする. 三角形の面積の公式より

$$ S = \dfrac{1}{2} bc \sin \alpha = \dfrac{1}{2} ca \sin \beta = \dfrac{1}{2} ab \sin \gamma $$

であるから, $k = \dfrac{2S}{abc}$ とおくと $k > 0$ であり,

$$ \sin \alpha = k a, \quad \sin \beta = k b, \quad \sin \gamma = k c $$

である. よって, 系 4 の式の分子と分母に $k$ を掛けると,

$$ \textrm{I} = \dfrac{k a \textrm{A} + k b \textrm{B} + k c \textrm{C}}{k (a + b + c)} = \dfrac{\sin \alpha \cdot \textrm{A} + \sin \beta \cdot \textrm{B} + \sin \gamma \cdot \textrm{C}}{\sin \alpha + \sin \beta + \sin \gamma} $$

を得る.

</div>

## Contents

```cpp
template<typename R>
Point<R> Incenter(const Triangle<R> &T)
```

* 三角形 $\textrm{T}$ の内心を求める.
* **計算量**
  * $O(1)$.
