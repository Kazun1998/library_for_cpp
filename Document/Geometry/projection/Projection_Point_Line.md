---
title: 点の直線への射影
documentation_of: //Geometry/projection/Projection_Point_Line.hpp
---

## Outline

点 $\textrm{P}$ の直線 $\ell$ への射影を求める.

## Theory

<div class="proposition" markdown="1">

命題 1
---

$\textrm{P}$ を点, $\ell$ を直線とする.

このとき, 以下が成り立つ.

* (1) $\displaystyle \min_{\textrm{X} \in \ell} d(\textrm{P}, \textrm{X})$ は存在する.
* (2) $\displaystyle d(\textrm{P}, \textrm{H}) = \min_{\textrm{X} \in \ell} d(\textrm{P}, \textrm{X})$ なる $\textrm{H} \in \ell$ がただ一つ存在する.

</div>

<div class="proof" markdown="1">

証明
---

$\ell$ 上の相異なる $2$ 点を $\textrm{A}, \textrm{B}$ とする. このとき, $\textrm{X}$ は $\ell$ 上の点なので,

$$ \overrightarrow{\textrm{A}\textrm{X}} = k \overrightarrow{\textrm{A}\textrm{B}} $$

なる実数 $k$ が存在する. 逆に, このような実数 $k$ が存在することが $\textrm{X}$ が $\ell$ 上の点であることの特徴付けである.

このとき, $\overrightarrow{\textrm{P}\textrm{X}} = \overrightarrow{\textrm{A}\textrm{X}} - \overrightarrow{\textrm{A}\textrm{P}}$ であるから,

$$\begin{align*}
d(\textrm{P}, \textrm{X})^2
&= \left \lvert \overrightarrow{\textrm{A}\textrm{X}} - \overrightarrow{\textrm{A}\textrm{P}} \right \rvert^2 \\
&= \left \lvert \overrightarrow{\textrm{A}\textrm{X}} \right \rvert^2 - 2 \overrightarrow{\textrm{A}\textrm{X}} \cdot \overrightarrow{\textrm{A}\textrm{P}} + \left \lvert \overrightarrow{\textrm{A}\textrm{P}} \right \rvert^2 \\
&= \left \lvert \overrightarrow{\textrm{A}\textrm{B}} \right \rvert^2 k^2 - 2 \left(\overrightarrow{\textrm{A}\textrm{B}} \cdot \overrightarrow{\textrm{A}\textrm{P}} \right) k + \left \lvert \overrightarrow{\textrm{A}\textrm{P}} \right \rvert^2
\end{align*}$$

となる.

$\textrm{A} \neq \textrm{B}$ であるので, $\left \lvert \overrightarrow{\textrm{A}\textrm{B}} \right \rvert \neq 0$ である. よって, $d(\textrm{P}, \textrm{X})^2$ は $k$ に関する $2$ 次関数であり, その $2$ 次の係数は正である.

この $2$ 次関数は

$$ k = \dfrac{\overrightarrow{\textrm{A}\textrm{P}} \cdot \overrightarrow{\textrm{A}\textrm{B}}}{\left \lvert \overrightarrow{\textrm{A}\textrm{B}} \right \rvert^2} $$

で最小を取る. この右辺を $k_0$ とすると,

$$ \overrightarrow{\textrm{A}\textrm{X}} = k_0 \overrightarrow{\textrm{A}\textrm{B}} $$

を満たす $\textrm{X}$ において $d(\textrm{P}, \textrm{X})$ は最小になる. また, $2$ 次関数の性質から, 最小を取る $k$ はただ一つなので, 最小となる $\textrm{X}$ もただ一つである.

</div>

<div class="definition" markdown="1">

定義 2
---

$\textrm{P}$ を点, $\ell$ を直線とする.

このとき, $\displaystyle d(\textrm{P}, \textrm{H}) = \min_{\textrm{X} \in \ell} d(\textrm{P}, \textrm{X})$ を満たす $\textrm{H} \in \ell$ を $\textrm{P}$ の $\ell$ への射影という.

</div>

<div class="proposition" markdown="1">

命題 3
---

$\textrm{P}$ を点, $\ell$ を直線, $\textrm{A}, \textrm{B}$ を $\ell$ 上の相異なる $2$ 点とする.

このとき, $\ell$ 上の点 $\textrm{H}$ に対して, 以下は同値である.

* (a) $\textrm{H}$ は $\textrm{P}$ の $\ell$ への射影である.
* (b) $\overrightarrow{\textrm{P}\textrm{H}} \cdot \overrightarrow{\textrm{A}\textrm{B}} = 0$ である.

</div>

<div class="proof" markdown="1">

証明
---

$\overrightarrow{\textrm{A}\textrm{H}} = k \overrightarrow{\textrm{A}\textrm{B}}$ とする. 命題 1 の証明より, (a) は $k = k_0$, すなわち

$$ \left \lvert \overrightarrow{\textrm{A}\textrm{B}} \right \rvert^2 k - \overrightarrow{\textrm{A}\textrm{P}} \cdot \overrightarrow{\textrm{A}\textrm{B}} = 0 $$

と同値である. ここで,

$$\begin{align*}
\left \lvert \overrightarrow{\textrm{A}\textrm{B}} \right \rvert^2 k - \overrightarrow{\textrm{A}\textrm{P}} \cdot \overrightarrow{\textrm{A}\textrm{B}}
&= \left(k \overrightarrow{\textrm{A}\textrm{B}} - \overrightarrow{\textrm{A}\textrm{P}} \right) \cdot \overrightarrow{\textrm{A}\textrm{B}} \\
&= \left(\overrightarrow{\textrm{A}\textrm{H}} - \overrightarrow{\textrm{A}\textrm{P}} \right) \cdot \overrightarrow{\textrm{A}\textrm{B}} \\
&= \overrightarrow{\textrm{P}\textrm{H}} \cdot \overrightarrow{\textrm{A}\textrm{B}}
\end{align*}$$

であるから, (a) と (b) は同値である.

</div>

次の系 4 によって, 点 $\textrm{P}$ の直線 $\ell$ への射影を具体的に計算することが可能になる.

<div class="corollary" markdown="1">

系 4
---

$\textrm{P}$ を点, $\ell$ を直線, $\textrm{A}, \textrm{B}$ を $\ell$ 上の相異なる $2$ 点とする.

このとき, $\textrm{P}$ の $\ell$ への射影 $\textrm{H}$ は

$$ \textrm{H} = \textrm{A} + \dfrac{\overrightarrow{\textrm{A}\textrm{P}} \cdot \overrightarrow{\textrm{A}\textrm{B}}}{\left \lvert \overrightarrow{\textrm{A}\textrm{B}} \right \rvert^2} \cdot \overrightarrow{\textrm{A}\textrm{B}} $$

である.

</div>

<div class="proof" markdown="1">

証明
---

$\textrm{H}$ は $\ell$ 上の点なので, $\overrightarrow{\textrm{A}\textrm{H}} = k \overrightarrow{\textrm{A}\textrm{B}}$ なる実数 $k$ が存在する. 命題 3 より, $\overrightarrow{\textrm{P}\textrm{H}} \cdot \overrightarrow{\textrm{A}\textrm{B}} = 0$ である. ここで, $\overrightarrow{\textrm{P}\textrm{H}} = k \overrightarrow{\textrm{A}\textrm{B}} - \overrightarrow{\textrm{A}\textrm{P}}$ であるから,

$$ 0 = \overrightarrow{\textrm{P}\textrm{H}} \cdot \overrightarrow{\textrm{A}\textrm{B}} = \left \lvert \overrightarrow{\textrm{A}\textrm{B}} \right \rvert^2 k - \overrightarrow{\textrm{A}\textrm{P}} \cdot \overrightarrow{\textrm{A}\textrm{B}} $$

となる. $\left \lvert \overrightarrow{\textrm{A}\textrm{B}} \right \rvert \neq 0$ より,

$$ k = \dfrac{\overrightarrow{\textrm{A}\textrm{P}} \cdot \overrightarrow{\textrm{A}\textrm{B}}}{\left \lvert \overrightarrow{\textrm{A}\textrm{B}} \right \rvert^2} $$

である. $\textrm{H} = \textrm{A} + k \overrightarrow{\textrm{A}\textrm{B}}$ に代入すると, 主張が従う.

</div>

## Contents

```cpp
Point<R> Projection(const Point<R> &P, const Line<R> &l)
```

* 点 $\textrm{P}$ の直線 $\ell$ への射影を, 系 4 の式で求める.
* **制約**
  * $\ell$ を定める $2$ 点 $\textrm{A}, \textrm{B}$ について, $\textrm{A} \neq \textrm{B}$.
  * `R` は浮動小数点型 (整数型では除算が切り捨てになり, 正しい値を返さない).
* **計算量**
  * $O(1)$.
