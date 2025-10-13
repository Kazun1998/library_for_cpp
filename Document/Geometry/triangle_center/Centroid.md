---
title: 三角形の重心
documentation_of: //Geometry/triangle_center/Centroid.hpp
---

## Outline

三角形 $\mathrm{ABC}$ の重心 $\mathrm{G}$ を求める.

## Theory

以下の定理がある.

> 三角形 $\mathrm{ABC}$ において, 線分 $\mathrm{BC}, \mathrm{CA}, \mathrm{AB}$ の中点をそれぞれ $\mathrm{L}, \mathrm{M}, \mathrm{N}$ とおく.
> このとき, 線分 $\mathrm{AL}, \mathrm{BM}, \mathrm{CN}$ は一点で交わる.

### 証明

線分 $\mathrm{AL}, \mathrm{BM}$ の交点を $\mathrm{G}$ とする. このとき, それぞれ

$$ \mathrm{G} = s \mathrm{A} + (1-s) \mathrm{L} = s \mathrm{A} + (1-s) \cdot \dfrac{\mathrm{B}+\mathrm{C}}{2} $$

$$ \mathrm{G} = t \mathrm{B} + (1-t) \mathrm{M} = t \mathrm{B} + (1-s) \cdot \dfrac{\mathrm{C}+\mathrm{A}}{2} $$

となる $0$ 以上 $1$ 以下の整数 $s, t$ が存在する.

$\mathrm{A}$ を始点とするベクトルに変換させると,

* $\mathrm{G} = \overrightarrow{\mathrm{AG}} - \overrightarrow{\mathrm{AO}}$.
* $s \mathrm{A} + (1-s) \cdot \dfrac{\mathrm{B}+\mathrm{C}}{2} = -s \overrightarrow{\mathrm{AO}} + (1-s) \cdot \dfrac{\left(\overrightarrow{\mathrm{AB}} - \overrightarrow{\mathrm{AO}} \right) + \left(\overrightarrow{\mathrm{AC}} - \overrightarrow{\mathrm{AO}} \right)}{2} = \dfrac{1-s}{2} \cdot \overrightarrow{\mathrm{AB}} + \dfrac{1-s}{2} \cdot \overrightarrow{\mathrm{AC}} - \overrightarrow{\mathrm{AO}}$

である.

そのため,

$$ \overrightarrow{\mathrm{AG}} = \dfrac{1-s}{2} \cdot \overrightarrow{\mathrm{AB}} + \dfrac{1-s}{2} \cdot \overrightarrow{\mathrm{AC}} \cdots (1) $$

が導ける.

同様にして,

$$ \overrightarrow{\mathrm{AG}} = t \cdot \overrightarrow{\mathrm{AB}} + \dfrac{1-t}{2} \cdot \overrightarrow{\mathrm{AC}} \cdots (2) $$

も従う.

ここで, $\mathrm{A}, \mathrm{B}, \mathrm{C}$ は三角形を成す $3$ 点であるため, $\overrightarrow{\mathrm{AB}}, \overrightarrow{\mathrm{AC}}$ は一次独立である.

よって, (1), (2) における係数比較により, $s, t$ は

$$ \dfrac{1-s}{2} = t, \quad \dfrac{1-s}{2} = \dfrac{1-t}{2} $$

を満たす. これを解くと,

$$ s = t = \dfrac{1}{3} $$

となる.

これは, $\mathrm{G}$ は確かに 線分 $\mathrm{AL}, \mathrm{BM}$ 上に存在すること. そして,

$$\mathrm{G} = s \mathrm{A} + (1-s) \cdot \dfrac{\mathrm{B}+\mathrm{C}}{2} = \dfrac{\mathrm{A} + \mathrm{B} + \mathrm{C}}{3} $$

であることを意味する.

そして,

$$ G = \dfrac{\mathrm{A} + \mathrm{B} + \mathrm{C}}{3} = \dfrac{1}{3} \mathrm{C} + \dfrac{2}{3} \cdot \dfrac{\mathrm{A} + \mathrm{B}}{2} = \dfrac{1}{3} \mathrm{C} + \dfrac{2}{3} \mathrm{N} $$

であるため, $\mathrm{G}$ は線分 $\mathrm{CN}$ 上の点でもある.

以上から, 線分 $\mathrm{AL}, \mathrm{BM}, \mathrm{CN}$ は一点で交わる.

$\square$

この定理における, 点 $\mathrm{G}$ を三角形 $\mathrm{ABC}$ の重心という.

## Contents

```cpp
template<typename R>
Point<R> Centroid(const Triangle<R> &T)
```

* 三角形 $\mathrm{T}$ の重心を求める.
