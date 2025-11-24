---
title: 重み付き無向グラフ
documentation_of: //Graph/Weighted_Graph/Weighted_Graph.hpp
---

## Outline

重み付き無向グラフを構築する.

## Contents

### constructor

```cpp
template<typename W>
Weighted_Graph(int n, int edge_id_offset = 0)
```

* 位数が $n$ である重み付き無向グラフを構築する.
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
vector<Edge*>& incidence(int u)
```

* 頂点 $u$ に接続する辺のアドレスのリストを返す.

### get_edge

```cpp
const Edge* get_edge(int id)
Edge* get_edge(int id)
```

* ID が `id` である無向辺のアドレスを返す.

## History

|日付|内容|
|:---:|:---|
|2025/11/24|重み付き無向グラフの実装|
