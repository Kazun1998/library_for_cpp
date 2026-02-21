---
title: 無向 Graph における Eulerian Trail
documentation_of: //Graph/Graph/Eulerian_Trail.hpp
---

## Outline

無向 Graph $G = (V, E)$ における Eulerian Trail を求める.

## Definition

* 同じ弧を通らない歩道を路という.
* 全ての弧を通る路を Eulerian Trail という.

## Theory

以下は同値になる.

* (a) $G$ は Eulerian Trail を持つ.
* (b) 以下が全て従う.
  * (1) $G$ における孤立点以外の任意の頂点は連結である.
  * (2) 次数が奇数である頂点は $0$ 個または $2$ 個である.
## History

|日付|内容|
|:---:|:---|
|2026/02/19| 無向グラフにおける Eulerian_Trail の実装|
