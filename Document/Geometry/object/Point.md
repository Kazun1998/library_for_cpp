---
title: 点
documentation_of: //Geometry/object/Point.hpp
---

## Outline

平面上の点を表すクラス.

## Theory

平面には直交座標系が定められているとし, その原点を $\textrm{O}$ とする.

このライブラリにおけるドキュメントでは, 実数 $x, y$ について, 以下の $3$ つを同一視する.

* 実数の組 $(x, y)$.
* 平面上の点 $(x, y)$, すなわち $x$ 座標が $x$, $y$ 座標が $y$ である点.
* 原点 $\textrm{O}$ に関する点 $(x, y)$ への位置ベクトル.

すなわち, 点 $\textrm{P} = (x, y)$ と位置ベクトル $\overrightarrow{\textrm{O}\textrm{P}}$ を区別せず, ともに実数の組 $(x, y)$ として扱う. この同一視のもとで, $2$ 点 $\textrm{P}, \textrm{Q}$ について $\overrightarrow{\textrm{P}\textrm{Q}} = \textrm{Q} - \textrm{P}$ である.
