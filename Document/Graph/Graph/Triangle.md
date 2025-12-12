---
title: 三角形に関する計算
documentation_of: //Graph/Graph/Triangle.hpp
---

## Outline

無向 Graph $G$ 上の三角形全てに関する値の合計を計算する.

$X$ を $\mathrm{unit}$ を単位元とする可換モノイドとする.

無向グラフ $G = (V, E)$ における関数 $\mathrm{calc}: V^3 \to X$ が与えられる.

このとき, $G$ における三角形の集合を $\mathcal{T}$ としたとき,

$$ \prod_{\{i, j, k \} \in \mathcal{T}} \mathrm{calc}(i, j, k) $$

を求める. ただし, $\mathrm{calc}$ は対称性を持つ $3$ 変数であることを要求する.

## Definition

無向グラフ $G = (V, E)$ における相異なる $3$ 個の頂点 $u, v, w \in V$ について, $uv, vw, wu \in E$ であるとき, この $3$ 点は三角形という.

## History

|日付|内容|
|:---:|:---|
|2025/12/06|Triangle の実装|
