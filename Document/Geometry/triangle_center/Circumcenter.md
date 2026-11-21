---
title: 三角形の外心
documentation_of: //Geometry/triangle_center/Circumcenter.hpp
---

## Outline

三角形 $\textrm{A}\textrm{B}\textrm{C}$ の外心 $\textrm{O}$ を求める.

## Theory

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

以下, 外心の性質を述べる.

<div class="proposition" markdown="1">

命題 4
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ において, 線分 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ の垂直二等分線は一点で交わり, その交点は三角形 $\textrm{A}\textrm{B}\textrm{C}$ の外心である.

</div>

<div class="proof" markdown="1">

証明
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ の外心を $\textrm{O}$ とする. 系 3 より, 線分 $\textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ の垂直二等分線は $\textrm{O}$ でただ一点で交わる.

また, $d(\textrm{O}, \textrm{B}) = d(\textrm{O}, \textrm{C})$ であり, 線分 $\textrm{B}\textrm{C}$ の垂直二等分線は $d(\textrm{P}, \textrm{B}) = d(\textrm{P}, \textrm{C})$ となる点 $\textrm{P}$ の軌跡であるから, $\textrm{O}$ は線分 $\textrm{B}\textrm{C}$ の垂直二等分線上にもある.

以上から, $3$ 本の垂直二等分線は一点 $\textrm{O}$ で交わる.

</div>

<div class="proposition" markdown="1">

命題 5
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ について, $a = d(\textrm{B}, \textrm{C}), b = d(\textrm{C}, \textrm{A}), c = d(\textrm{A}, \textrm{B})$ とし, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の面積を $S$ とする. また, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の外心を $\textrm{O}$ とする.

$$ p = a^2 (b^2 + c^2 - a^2), \quad q = b^2 (c^2 + a^2 - b^2), \quad r = c^2 (a^2 + b^2 - c^2) $$

とおくと, $p + q + r = 16 S^2 > 0$ であり,

$$ \textrm{O} = \dfrac{p \textrm{A} + q \textrm{B} + r \textrm{C}}{p + q + r} $$

である.

</div>

<div class="proof" markdown="1">

証明
---

$\boldsymbol{u} = \overrightarrow{\textrm{A}\textrm{B}}, \boldsymbol{v} = \overrightarrow{\textrm{A}\textrm{C}}$ とおく. $\textrm{A}, \textrm{B}, \textrm{C}$ は同一直線上にないので, $\boldsymbol{u}, \boldsymbol{v}$ は一次独立である. また, $\lvert \boldsymbol{u} \rvert = c, \lvert \boldsymbol{v} \rvert = b$ であり, $a^2 = \lvert \boldsymbol{v} - \boldsymbol{u} \rvert^2 = b^2 - 2 \boldsymbol{u} \cdot \boldsymbol{v} + c^2$ より

$$ \boldsymbol{u} \cdot \boldsymbol{v} = \dfrac{b^2 + c^2 - a^2}{2} $$

である.

$\boldsymbol{u}, \boldsymbol{v}$ は一次独立であるから, 実数 $s, t$ を用いて $\overrightarrow{\textrm{A}\textrm{O}} = s \boldsymbol{u} + t \boldsymbol{v}$ と表せる. $\boldsymbol{x} = \overrightarrow{\textrm{A}\textrm{O}}$ とおくと, $d(\textrm{O}, \textrm{A}) = d(\textrm{O}, \textrm{B})$ は

$$ \lvert \boldsymbol{x} \rvert^2 = \lvert \boldsymbol{x} - \boldsymbol{u} \rvert^2 \iff \boldsymbol{x} \cdot \boldsymbol{u} = \dfrac{1}{2} \lvert \boldsymbol{u} \rvert^2 $$

と同値であり, 同様に $d(\textrm{O}, \textrm{A}) = d(\textrm{O}, \textrm{C})$ は $\boldsymbol{x} \cdot \boldsymbol{v} = \dfrac{1}{2} \lvert \boldsymbol{v} \rvert^2$ と同値である. これらに $\boldsymbol{x} = s \boldsymbol{u} + t \boldsymbol{v}$ を代入すると, 連立方程式

$$ \begin{aligned}
c^2 s + (\boldsymbol{u} \cdot \boldsymbol{v}) t &= \dfrac{c^2}{2} \\
(\boldsymbol{u} \cdot \boldsymbol{v}) s + b^2 t &= \dfrac{b^2}{2}
\end{aligned} $$

を得る. 係数行列の行列式を $D = b^2 c^2 - (\boldsymbol{u} \cdot \boldsymbol{v})^2$ とおく. $\boldsymbol{u} = (u_x, u_y), \boldsymbol{v} = (v_x, v_y)$ と成分で書くと,

$$ D = (u_x^2 + u_y^2)(v_x^2 + v_y^2) - (u_x v_x + u_y v_y)^2 = (u_x v_y - u_y v_x)^2 = (2S)^2 $$

であるから, $D = 4 S^2 > 0$ である. Cramer の公式より,

$$ s = \dfrac{b^2 \left(c^2 - \boldsymbol{u} \cdot \boldsymbol{v} \right)}{2D} = \dfrac{b^2 (c^2 + a^2 - b^2)}{4D} = \dfrac{q}{4D}, \quad t = \dfrac{c^2 \left(b^2 - \boldsymbol{u} \cdot \boldsymbol{v} \right)}{2D} = \dfrac{c^2 (a^2 + b^2 - c^2)}{4D} = \dfrac{r}{4D} $$

である.

ここで,

$$ \begin{aligned}
4D &= 4 b^2 c^2 - (b^2 + c^2 - a^2)^2 \\
&= 2 a^2 b^2 + 2 b^2 c^2 + 2 c^2 a^2 - a^4 - b^4 - c^4 \\
&= a^2 (b^2 + c^2 - a^2) + b^2 (c^2 + a^2 - b^2) + c^2 (a^2 + b^2 - c^2) \\
&= p + q + r
\end{aligned} $$

であるから, $p + q + r = 4D = 16 S^2 > 0$ である. よって,

$$ \textrm{O} = \textrm{A} + s (\textrm{B} - \textrm{A}) + t (\textrm{C} - \textrm{A}) = (1 - s - t) \textrm{A} + s \textrm{B} + t \textrm{C} $$

であり, $1 - s - t = \dfrac{4D - q - r}{4D} = \dfrac{p}{4D}$ であるから,

$$ \textrm{O} = \dfrac{p \textrm{A} + q \textrm{B} + r \textrm{C}}{p + q + r} $$

である.

</div>

<div class="corollary" markdown="1">

系 6
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ について, $\alpha = \angle \textrm{A}, \beta = \angle \textrm{B}, \gamma = \angle \textrm{C}$ とし, 外心を $\textrm{O}$ とする. このとき, $\sin 2 \alpha + \sin 2 \beta + \sin 2 \gamma > 0$ であり,

$$ \textrm{O} = \dfrac{\sin 2 \alpha \cdot \textrm{A} + \sin 2 \beta \cdot \textrm{B} + \sin 2 \gamma \cdot \textrm{C}}{\sin 2 \alpha + \sin 2 \beta + \sin 2 \gamma} $$

である.

</div>

<div class="proof" markdown="1">

証明
---

命題 5 の記号を用いる. $\alpha$ は $\boldsymbol{u}, \boldsymbol{v}$ のなす角であるから $\boldsymbol{u} \cdot \boldsymbol{v} = bc \cos \alpha$ であり, 命題 5 の証明より $\boldsymbol{u} \cdot \boldsymbol{v} = \dfrac{b^2 + c^2 - a^2}{2}$ であるから,

$$ \cos \alpha = \dfrac{b^2 + c^2 - a^2}{2bc} $$

である. また, $0 < \alpha < \pi$ より $\sin \alpha > 0$ であり, $S = \dfrac{1}{2} \lvert u_x v_y - u_y v_x \rvert = \dfrac{1}{2} bc \sin \alpha$ であるから,

$$ \sin \alpha = \dfrac{2S}{bc} $$

である. よって,

$$ \sin 2 \alpha = 2 \sin \alpha \cos \alpha = \dfrac{2S (b^2 + c^2 - a^2)}{b^2 c^2} = \dfrac{2S}{a^2 b^2 c^2} \cdot a^2 (b^2 + c^2 - a^2) = \dfrac{2S}{a^2 b^2 c^2} p $$

である. 同様に,

$$ \sin 2 \beta = \dfrac{2S}{a^2 b^2 c^2} q, \quad \sin 2 \gamma = \dfrac{2S}{a^2 b^2 c^2} r $$

である. $k = \dfrac{2S}{a^2 b^2 c^2}$ とおくと $k > 0$ であり, 命題 5 より

$$ \sin 2 \alpha + \sin 2 \beta + \sin 2 \gamma = k (p + q + r) > 0 $$

である. さらに, 命題 5 の式の分子と分母に $k$ を掛けると,

$$ \textrm{O} = \dfrac{k p \textrm{A} + k q \textrm{B} + k r \textrm{C}}{k (p + q + r)} = \dfrac{\sin 2 \alpha \cdot \textrm{A} + \sin 2 \beta \cdot \textrm{B} + \sin 2 \gamma \cdot \textrm{C}}{\sin 2 \alpha + \sin 2 \beta + \sin 2 \gamma} $$

を得る.

</div>

点 $\textrm{X}$ が三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内部にあるとは, $\lambda + \mu + \nu = 1, \lambda > 0, \mu > 0, \nu > 0$ を満たす実数 $\lambda, \mu, \nu$ を用いて $\textrm{X} = \lambda \textrm{A} + \mu \textrm{B} + \nu \textrm{C}$ と表せることをいう.

<div class="proposition" markdown="1">

命題 7
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ の外心を $\textrm{O}$ とする.

* $\textrm{A}, \textrm{B}, \textrm{C}$ がすべて鋭角ならば, $\textrm{O}$ は三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内部にある.
* $\textrm{A}$ が直角ならば, $\textrm{O}$ は辺 $\textrm{B}\textrm{C}$ の中点である.
* $\textrm{A}$ が鈍角ならば, 線分 $\textrm{A}\textrm{O}$ は辺 $\textrm{B}\textrm{C}$ と端点以外で交わる. 特に, $\textrm{O}$ は直線 $\textrm{B}\textrm{C}$ に関して $\textrm{A}$ と反対側にあり, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の外部にある.

</div>

<div class="proof" markdown="1">

証明
---

命題 5, 系 6 の記号を用いる. 系 6 の証明より $b^2 + c^2 - a^2 = 2 bc \cos \alpha$ であるから, $p$ の符号は $\cos \alpha$ の符号と一致する. 同様に, $q, r$ の符号はそれぞれ $\cos \beta, \cos \gamma$ の符号と一致する. また,

$$\lambda = \dfrac{p}{p + q + r}, \quad \mu = \dfrac{q}{p + q + r}, \quad \nu = \dfrac{r}{p + q + r}$$

とおくと, 命題 5 より $\textrm{O} = \lambda \textrm{A} + \mu \textrm{B} + \nu \textrm{C}, \lambda + \mu + \nu = 1$ であり, $p + q + r > 0$ より $\lambda, \mu, \nu$ の符号はそれぞれ $p, q, r$ の符号と一致する.

$3$ つの角がすべて鋭角のとき, $\lambda, \mu, \nu$ はすべて正であるから, $\textrm{O}$ は三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内部にある.

$\textrm{A}$ が直角または鈍角のとき, すなわち $a^2 \geq b^2 + c^2$ のとき,

$$ c^2 + a^2 - b^2 \geq 2 c^2 > 0, \quad a^2 + b^2 - c^2 \geq 2 b^2 > 0 $$

であるから, $\mu > 0, \nu > 0$ である.

$\textrm{A}$ が直角のとき, $a^2 = b^2 + c^2$ であるから, $p = 0, q = r = 2 b^2 c^2$ となる. よって $\lambda = 0, \mu = \nu = \dfrac{1}{2}$ であり, $\textrm{O} = \dfrac{\textrm{B} + \textrm{C}}{2}$ は辺 $\textrm{B}\textrm{C}$ の中点である.

$\textrm{A}$ が鈍角のとき, $\lambda < 0$ である. $\mu + \nu = 1 - \lambda > 0$ であるから, $\textrm{Q} = \dfrac{\mu \textrm{B} + \nu \textrm{C}}{\mu + \nu}$ とおくと, $\mu, \nu > 0$ より $\textrm{Q}$ は辺 $\textrm{B}\textrm{C}$ 上の端点以外の点である. さらに, $\textrm{O} = \lambda \textrm{A} + (1 - \lambda) \textrm{Q}$ より

$$ \textrm{Q} = \dfrac{1}{1 - \lambda} \textrm{O} + \dfrac{-\lambda}{1 - \lambda} \textrm{A} $$

であり, 係数 $\dfrac{1}{1 - \lambda}, \dfrac{-\lambda}{1 - \lambda}$ はともに正で和が $1$ であるから, $\textrm{Q}$ は線分 $\textrm{A}\textrm{O}$ 上の端点以外の点である. よって, 線分 $\textrm{A}\textrm{O}$ は辺 $\textrm{B}\textrm{C}$ と端点以外の点 $\textrm{Q}$ で交わる. $\textrm{A}$ は直線 $\textrm{B}\textrm{C}$ 上にない. もし $\textrm{O}$ が直線 $\textrm{B}\textrm{C}$ 上にあれば, 直線 $\textrm{O}\textrm{Q}$ は直線 $\textrm{B}\textrm{C}$ と一致し, それは $\textrm{A}$ を通るので矛盾する. よって $\textrm{A}, \textrm{O}$ はともに直線 $\textrm{B}\textrm{C}$ 上になく, 線分 $\textrm{A}\textrm{O}$ が直線 $\textrm{B}\textrm{C}$ と交わるから, $\textrm{O}$ は直線 $\textrm{B}\textrm{C}$ に関して $\textrm{A}$ と反対側にある. 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内部の点は直線 $\textrm{B}\textrm{C}$ に関して $\textrm{A}$ と同じ側にあるから, $\textrm{O}$ は三角形 $\textrm{A}\textrm{B}\textrm{C}$ の外部にある.

</div>

## Contents

```cpp
template<typename R>
Point<R> Circumcenter(const Triangle<R> &T)
```

* 三角形 $\textrm{T}$ の外心を求める.
* **計算量**
  * $O(1)$.
