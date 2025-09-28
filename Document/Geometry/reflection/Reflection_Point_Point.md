---
title: 点に関する点の反転
documentation_of: //Geometry/reflection/Reflection_Point_Point.hpp
---

## Outline

点 $\textrm{X}$ に関して点 $\textrm{P}$ と対称な点 $\textrm{Q}$ を求める.

## Theory

点 $\textrm{X}$ は線分 $\textrm{PQ}$ の点である. よって,

 $$ \dfrac{\textrm{P} + \textrm{Q}}{2} = \textrm{X} $$

が成り立つ.

これを $\textrm{Q}$ について整理すると,

  $$ \textrm{Q} = 2 \textrm{X} - \textrm{P} $$

が導ける.

## Contents

```cpp
Point<R> Reflection(const Point<R> &P, const Point<R> &X)
```

* 点 $\textrm{X}$ に関して点 $\textrm{P}$ と対称な点を求める.

