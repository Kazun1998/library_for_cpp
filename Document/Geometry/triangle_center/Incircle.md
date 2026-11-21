---
title: 三角形の内接円
documentation_of: //Geometry/triangle_center/Incircle.hpp
---

## Outline

三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内接円を求める.

## Theory

中心 $\textrm{P}$, 半径 $r$ の円とは, $d(\textrm{P}, \textrm{X}) = r$ を満たす点 $\textrm{X}$ 全体のことである ( $r > 0$ ).

中心 $\textrm{P}$, 半径 $r$ の円と直線 $\ell$ が接するとは, $\textrm{P}$ から $\ell$ までの距離が $r$ であることをいう. このとき, $\textrm{P}$ から $\ell$ に下ろした垂線の足を接点という. また, 円が線分 $\textrm{X}\textrm{Y}$ に接するとは, 円が直線 $\textrm{X}\textrm{Y}$ に接し, かつ接点が線分 $\textrm{X}\textrm{Y}$ 上にあることをいう.

<div class="proposition" markdown="1">

命題 1
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ について, $a = d(\textrm{B}, \textrm{C}), b = d(\textrm{C}, \textrm{A}), c = d(\textrm{A}, \textrm{B})$ とし, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の面積を $S$ とする. また, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内心を $\textrm{I}$ とする.

このとき, $\textrm{I}$ から直線 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ までの距離はすべて

$$ \dfrac{2S}{a + b + c} $$

である.

</div>

<div class="proof" markdown="1">

証明
---

$2$ つのベクトル $\boldsymbol{p} = (p_x, p_y), \boldsymbol{q} = (q_x, q_y)$ に対して $\boldsymbol{p} \times \boldsymbol{q} = p_x q_y - p_y q_x$ とおく. 点 $\textrm{X}$ から直線 $\textrm{B}\textrm{C}$ までの距離は, 三角形 $\textrm{X}\textrm{B}\textrm{C}$ の面積の $\dfrac{2}{a}$ 倍であるから,

$$ \dfrac{1}{a} \left \lvert (\textrm{B} - \textrm{X}) \times (\textrm{C} - \textrm{X}) \right \rvert $$

である.

$\lambda + \mu + \nu = 1$ を満たす実数 $\lambda, \mu, \nu$ を用いて $\textrm{X} = \lambda \textrm{A} + \mu \textrm{B} + \nu \textrm{C}$ と表す. $\times$ は各引数について線形であり, $\boldsymbol{p} \times \boldsymbol{p} = 0, \boldsymbol{q} \times \boldsymbol{p} = -\boldsymbol{p} \times \boldsymbol{q}$ を満たす. $\textrm{B} - \textrm{X} = \lambda (\textrm{B} - \textrm{A}) + \nu (\textrm{B} - \textrm{C})$, $\textrm{C} - \textrm{X} = \lambda (\textrm{C} - \textrm{A}) + \mu (\textrm{C} - \textrm{B})$ であるから, $(\textrm{B} - \textrm{C}) \times (\textrm{C} - \textrm{B}) = 0$ に注意して展開すると,

$$ \begin{aligned}
(\textrm{B} - \textrm{X}) \times (\textrm{C} - \textrm{X})
&= \lambda^2 (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) + \lambda \mu (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{B}) + \lambda \nu (\textrm{B} - \textrm{C}) \times (\textrm{C} - \textrm{A}) \\
&= \lambda^2 (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) + \lambda \mu (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) + \lambda \nu (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) \\
&= \lambda (\lambda + \mu + \nu) (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) \\
&= \lambda (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A})
\end{aligned} $$

である. ここで, $2$ 行目では

$$ (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{B}) = (\textrm{B} - \textrm{A}) \times \left((\textrm{C} - \textrm{A}) - (\textrm{B} - \textrm{A}) \right) = (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) $$

$$ (\textrm{B} - \textrm{C}) \times (\textrm{C} - \textrm{A}) = \left((\textrm{B} - \textrm{A}) - (\textrm{C} - \textrm{A}) \right) \times (\textrm{C} - \textrm{A}) = (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) $$

を用いた. $\left \lvert (\textrm{B} - \textrm{A}) \times (\textrm{C} - \textrm{A}) \right \rvert = 2S$ であるから, $\textrm{X}$ から直線 $\textrm{B}\textrm{C}$ までの距離は $\dfrac{2S}{a} \lvert \lambda \rvert$ である.

[三角形の内心](Incenter.hpp) の系 4 より, $\textrm{I}$ は $\lambda = \dfrac{a}{a + b + c}$ の場合であるから, $\textrm{I}$ から直線 $\textrm{B}\textrm{C}$ までの距離は

$$ \dfrac{2S}{a} \cdot \dfrac{a}{a + b + c} = \dfrac{2S}{a + b + c} $$

である. 直線 $\textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ についても, 頂点の役割を入れ替えて同様に計算すると, 距離はともに $\dfrac{2S}{a + b + c}$ である.

</div>

<div class="theorem" markdown="1">

定理 2
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ について, $3$ 辺 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ すべてに接する円がただ一つ存在する.

</div>

<div class="proof" markdown="1">

証明
---

$a = d(\textrm{B}, \textrm{C}), b = d(\textrm{C}, \textrm{A}), c = d(\textrm{A}, \textrm{B})$ とし, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の面積を $S$ とする.

**一意性.** 中心 $\textrm{P}$, 半径 $r$ の円が $3$ 辺すべてに接するとし, 辺 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ 上の接点をそれぞれ $\textrm{D}, \textrm{E}, \textrm{F}$ とする. $\textrm{P}\textrm{F}$ は直線 $\textrm{A}\textrm{B}$ に垂直であるから, 三平方の定理より

$$ d(\textrm{A}, \textrm{F})^2 = d(\textrm{A}, \textrm{P})^2 - r^2 $$

である. 同様に $d(\textrm{A}, \textrm{E})^2 = d(\textrm{A}, \textrm{P})^2 - r^2$ であるから, $d(\textrm{A}, \textrm{E}) = d(\textrm{A}, \textrm{F})$ である. 同様に, $d(\textrm{B}, \textrm{F}) = d(\textrm{B}, \textrm{D}), d(\textrm{C}, \textrm{D}) = d(\textrm{C}, \textrm{E})$ である. これらをそれぞれ $x, y, z$ とおく.

$\textrm{D}, \textrm{E}, \textrm{F}$ はそれぞれ線分 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ 上にあるから,

$$ y + z = a, \quad z + x = b, \quad x + y = c $$

である. これを解くと,

$$ x = \dfrac{b + c - a}{2}, \quad y = \dfrac{c + a - b}{2}, \quad z = \dfrac{a + b - c}{2} $$

である. よって, 接点 $\textrm{D}, \textrm{E}$ は $a, b, c$ のみから定まる. $\textrm{P}$ は $\textrm{D}$ を通り直線 $\textrm{B}\textrm{C}$ に垂直な直線と, $\textrm{E}$ を通り直線 $\textrm{C}\textrm{A}$ に垂直な直線の両方の上にある. 直線 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}$ は平行でないから, この $2$ 本の垂線も平行でなく, $\textrm{P}$ はその交点としてただ一つに定まる. さらに $r = d(\textrm{P}, \textrm{D})$ も定まる. したがって, $3$ 辺すべてに接する円は高々一つである.

**存在性.** 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内心を $\textrm{I}$ とし, $r = \dfrac{2S}{a + b + c}$ とおく. $r > 0$ である. 命題 1 より, $\textrm{I}$ から直線 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ までの距離はすべて $r$ であるから, 中心 $\textrm{I}$, 半径 $r$ の円はこの $3$ 直線に接する.

あとは, 接点が辺上にあることを示せばよい. $\textrm{I}$ から直線 $\textrm{B}\textrm{C}$ に下ろした垂線の足を $\textrm{H}$ とし, 実数 $t$ を用いて $\textrm{H} = \textrm{B} + t (\textrm{C} - \textrm{B})$ と表す. $\textrm{I} - \textrm{H}$ は $\textrm{C} - \textrm{B}$ に垂直であるから,

$$ (\textrm{I} - \textrm{B}) \cdot (\textrm{C} - \textrm{B}) = (\textrm{H} - \textrm{B}) \cdot (\textrm{C} - \textrm{B}) = t a^2 $$

である. $\textrm{I}$ は頂点 $\textrm{B}$ における内角の二等分線上にあるから, $\textrm{I} - \textrm{B}$ と $\textrm{C} - \textrm{B}$ のなす角は $\dfrac{\textrm{B}}{2}$ であり, $0 < \dfrac{\textrm{B}}{2} < \dfrac{\pi}{2}$ であるから左辺は正である. よって $t > 0$ である. 同様に, $\textrm{B}$ と $\textrm{C}$ の役割を入れ替えると $1 - t > 0$ を得る. したがって $0 < t < 1$ であり, $\textrm{H}$ は辺 $\textrm{B}\textrm{C}$ 上にある. 辺 $\textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ についても同様である.

以上から, $3$ 辺すべてに接する円はただ一つ存在する.

</div>

<div class="definition" markdown="1">

定義 3
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ について, $3$ 辺 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ すべてに接するただ一つの円を, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内接円という.

</div>

次の系によって内接円を具体的に計算することが可能になる.

<div class="corollary" markdown="1">

系 4
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ について, $a = d(\textrm{B}, \textrm{C}), b = d(\textrm{C}, \textrm{A}), c = d(\textrm{A}, \textrm{B})$ とし, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の面積を $S$, 内心を $\textrm{I}$ とする. このとき, 三角形 $\textrm{A}\textrm{B}\textrm{C}$ の内接円は, 中心 $\textrm{I}$, 半径 $\dfrac{2S}{a + b + c}$ の円である.

</div>

<div class="proof" markdown="1">

証明
---

定理 2 の証明から従う.

</div>

内心 $\textrm{I}$ は [三角形の内心](Incenter.hpp) の方法で求められる.

以下, 内接円の性質を述べる.

<div class="proposition" markdown="1">

命題 5
---

三角形 $\textrm{A}\textrm{B}\textrm{C}$ について, $a = d(\textrm{B}, \textrm{C}), b = d(\textrm{C}, \textrm{A}), c = d(\textrm{A}, \textrm{B})$ とし, 内接円と辺 $\textrm{B}\textrm{C}, \textrm{C}\textrm{A}, \textrm{A}\textrm{B}$ の接点をそれぞれ $\textrm{D}, \textrm{E}, \textrm{F}$ とする. このとき,

$$ d(\textrm{A}, \textrm{E}) = d(\textrm{A}, \textrm{F}) = \dfrac{b + c - a}{2} $$

$$ d(\textrm{B}, \textrm{F}) = d(\textrm{B}, \textrm{D}) = \dfrac{c + a - b}{2} $$

$$ d(\textrm{C}, \textrm{D}) = d(\textrm{C}, \textrm{E}) = \dfrac{a + b - c}{2} $$

である.

</div>

<div class="proof" markdown="1">

証明
---

定理 2 の証明の一意性の部分から従う.

</div>

## Contents

```cpp
template<typename R>
Circle<R> Incircle(const Triangle<R> &T)
```

* 三角形 $\textrm{T}$ の内接円を求める.
* **計算量**
  * $O(1)$.
