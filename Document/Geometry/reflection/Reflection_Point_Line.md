---
title: 点の直線に関する対称移動
documentation_of: //Geometry/reflection/Reflection_Point_Line.hpp
---

## Outline

点 $\textrm{P}$ の直線 $\ell$ に関して対称な点を求める.

## Theory

点 $\textrm{P}$ の直線 $\ell$ に関して対称な点とは, [点 $\mathrm{P}$ の直線 $\ell$ への斜影](../projection/Projection_Point_Line.hpp)に関する[直線 $\textrm{P}$ と対称な点](../reflection/Reflection_Point_Point.hpp)である.

## Contents

```cpp
Point<R> Reflection(const Point<R> &P, const Line<R> &l)
```

* 点 $\textrm{P}$ の直線 $\ell$ に関して対称な点を求める.
