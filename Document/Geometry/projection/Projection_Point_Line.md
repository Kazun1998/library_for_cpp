---
title: 点の直線への射影
documentation_of: //Geometry/projection/Projection_Point_Line.hpp
---

## Outline

点 $\textrm{P}$ の直線 $\ell$ への射影を求める.

## Theory

$\ell$ 上の異なる $2$ 点を $\textrm{A}, \textrm{B}$ とする.

$\ell$ 上の点 $\textrm{H}$ に対して, 以下は同値である.

* (a): $\textrm{H}$ は点 $\textrm{P}$ の直線 $\ell$ への射影である.
* (b): $\overrightarrow{\textrm{PH}} \perp \overrightarrow{\textrm{AB}}$.

$\textrm{H}$ は $\ell$ 上の点であるため, 実数 $k \in \mathbb{R}$ を用いて,

$$ \textrm{H} = \textrm{A} + k \overrightarrow{\textrm{AB}} $$

と表せる.

このとき, $\textrm{H}$ が点 $\textrm{P}$ の直線 $\ell$ への射影であるとすると,

$$\begin{align*}
  0
  &= \overrightarrow{\textrm{PH}} \cdot \overrightarrow{\textrm{AB}} \\
  &= \left(\textrm{A} + k \overrightarrow{\textrm{AB}} - \textrm{P} \right) \cdot \overrightarrow{\textrm{AB}} \\
  &= \left(-\overrightarrow{\textrm{AP}} + k \overrightarrow{\textrm{AB}} \right) \cdot \overrightarrow{\textrm{AB}} \\
  &=-\overrightarrow{\textrm{AP}} \cdot \overrightarrow{\textrm{AB}} + k \left|\overrightarrow{\textrm{AB}}\right|^2 \\
\end{align*}$$

となる.

よって,

$$ k = \dfrac{\overrightarrow{\textrm{AP}} \cdot \overrightarrow{\textrm{AB}}}{\left|\overrightarrow{\textrm{AB}}\right|^2}$$

である. $ \textrm{H} = \textrm{A} + k \overrightarrow{\textrm{AB}} $ によって, $\textrm{H}$ を求めることができる.

## Contents

```cpp
Point<R> Projection(const Point<R> &P, const Line<R> &l)
```

* 点 $\textrm{P}$ の直線 $\ell$ への射影を求める.
