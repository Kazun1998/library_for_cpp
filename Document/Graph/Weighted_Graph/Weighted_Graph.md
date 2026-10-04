---
title: 重み付き無向グラフ
documentation_of: //Graph/Weighted_Graph/Weighted_Graph.hpp
---

## Outline

重み付き無向グラフを構築する.

**注意:** `graph::Graph<W>` に統合された. `weighted_graph::Weighted_Graph<W>` は互換用の別名で, 詳細は [無向 Graph](../Graph/Graph.html) を参照.

## Contents

### constructor

```cpp
template<typename W>
Weighted_Graph(int n, int edge_id_offset = 0)
```

* 位数が $n$ である重み付き無向グラフを構築する.

**注意:** `graph::Graph<W>` に統合された. `weighted_graph::Weighted_Graph<W>` は互換用の別名で, 詳細は [無向 Graph](../Graph/Graph.html) を参照.
* 重みの型は $W$ である.

### order

```cpp
int order()
```

* 位数 (頂点数) を求める.

### size

```cpp
int order()
```

* サイズ (辺の数) を求める.

### size

```cpp
int add_edge(int u, int v, W w)
```

* 重みが $w$ である無向辺 $uv$ を加える.

### incidence

```cpp
vector<Oriented_Edge>& incidence(int u)
```

* 頂点 $u$ に接続する辺を, $u$ から出る向きにしたリストを返す.

### get_edge

```cpp
const Edge<W>& get_edge(int id)
Edge<W>& get_edge(int id)
```

* ID が `id` である無向辺を返す.

## History

|日付|内容|
|:---:|:---|
|2026/10/04|`Graph<W>` に統合|
|2025/11/24|重み付き無向グラフの実装|
