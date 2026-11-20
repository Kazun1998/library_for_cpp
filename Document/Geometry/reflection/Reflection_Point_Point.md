---
title: 点に関する対称移動
documentation_of: //Geometry/reflection/Reflection_Point_Point.hpp
---

## Outline

点 $\textrm{X}$ に関して点 $\textrm{P}$ と対称な点を求める.

## Theory

以下, 点 $\textrm{P}$ とその位置ベクトルを同一視する.

<div class="definition" markdown="1">

定義 1
---

$\textrm{P}, \textrm{X}$ を点とする.

このとき, $\textrm{X}$ が線分 $\textrm{P}\textrm{Q}$ の中点となるような点 $\textrm{Q}$ を, 点 $\textrm{X}$ に関して点 $\textrm{P}$ と対称な点という.

</div>

<div class="proposition" markdown="1">

命題 2
---

$\textrm{P}, \textrm{X}$ を点とする.

このとき, 点 $\textrm{X}$ に関して点 $\textrm{P}$ と対称な点 $\textrm{Q}$ はただ一つ存在し,

$$ \textrm{Q} = 2 \textrm{X} - \textrm{P} $$

である.

</div>

<div class="proof" markdown="1">

証明
---

$\textrm{X}$ が線分 $\textrm{P}\textrm{Q}$ の中点であることは,

$$ \textrm{X} = \dfrac{\textrm{P} + \textrm{Q}}{2} $$

と同値である. これを $\textrm{Q}$ について解くと $\textrm{Q} = 2 \textrm{X} - \textrm{P}$ となり, $\textrm{Q}$ はただ一つに定まる.

</div>

## Contents

```cpp
Point<R> Reflection(const Point<R> &P, const Point<R> &X)
```

* 点 $\textrm{X}$ に関して点 $\textrm{P}$ と対称な点を, 命題 2 の式で求める.
* **計算量**
  * $O(1)$.
