---
title: 全域木の計上
documentation_of: //Graph/Graph/Count_Spanning_Trees.hpp
---

## Outline

無向グラフ $G$ における全域木の個数 (同じ頂点間を結ぶ辺同士であっても, 異なる辺であるならば区別する) を求める.

## Definition

無向グラフ $G = (V, E)$ における部分木のうち, 頂点集合が $V$ である部分木のことを, $G$ の全域木という.

## Theory

行列木定理を用いる.

$G$ のラプラシアン行列 $L$ とは, 次数行列を $D$, 隣接行列を $A$ としたときの

$$ L := D - A $$

である.

このとき, 以下が成り立つ.

* $L$ の余因子は取り除く行と列に関わらず一致する.
* $G$ における全域木の数は $L$ における (任意の) 余因子と一致する.

## Contents


```cpp
template<typename F>
F Count_Spanning_Trees(const Graph &G)
```

* 無向グラフ $G = (V, E)$ における全域木の数を求める
* **引数**
  * $G$ : 無向グラフ
* **計算量** : $G$ の位数とサイズを $N, M$ とすると, $O \left(N^3 \right)$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/04/02| Count_Spanning_Trees 実装 |
