---
title: 区間アフィン変換, 区間和に関する遅延セグメント木
documentation_of: //Segment_Tree/preset/Range_Composite_Range_Sum.hpp
---

## Outline

アフィン変換に関する遅延セグメント木

## Theory

可換体 $T$ 上の列 $A = (a_0, a_1, \dots, a_{n-1})$ における以下の処理を高速におこなう.

* $a_l, \dots, a_r$ に対して, 以下のように更新する: $x$ から $b + cx$.
* $\sum_{k=l}^r a_k$ を求める.

## History

|日付|内容|
|:---:|:---:|
|2026/03/22| Range_Composite_Range_Sum_Lazy_Segment_Tree 実装 |
