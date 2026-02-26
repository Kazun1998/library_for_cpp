---
title: 最大流
documentation_of: //Max_Flow/Max_Flow.hpp
---

## Outline

最大流問題を解く.

## Contents

### Constructor
```cpp
template<typename Cap>
Max_Flow F(int N = 0)
```

* 容量の型が `Cap` である位数 $N$ の有向グラフを生成する.

### order
```cpp
int F.order()
```

* 有向グラフの位数を求める.

### size
```cpp
int F.size()
```

* 有向グラフのサイズを求める.

### add_arc
```cpp
int F.add_arc(const int u, const int v, const Cap cap)
```

* 頂点 $u$ から頂点 $v$ への容量 $\text{cap}$ の有向辺を張る.
* **返り値** : 追加した辺の番号

### add_vertex
```cpp
int F.add_vertex()
```

* 頂点を追加する.
* **返り値** : 追加した頂点の番号

### get_flow
```cpp
vector<vector<tuple<int, int, Cap>>> F.get_flow()
```
* `flow` で得られた最大流を達成する流れを返す.
* **返り値** : 第 $u$ 要素にある tuple の要素 $(m, v, c)$ は以下を意味する.
  * 弧の番号が $m$.
  * $u$ から $v$ への弧.
  * 流量 $c$

### max_flow
```cpp
Cap F.max_flow(const V source, const V target)
Cap F.max_flow(const V source, const V target, Cap flow_limit)
```

* 頂点 $\text{source}$ から頂点 $\text{target}$ へ流せる最大流量を求める.
* **引数** : $\text{flow\_limit}$ を指定すると, 最大流量が高々 $\text{flow\_limit}$ になる.
* **計算量** : 計算量は色々ある. ただし, 位数を $N$, サイズを $M$ とする.
  * 一般には $O(N^2M)$ 時間.
  * 辺の容量が全て整数である場合
    * 辺容量の平均値が $K$ の場合, $O(K M^{3/2})$ 時間.
    * 辺容量の最大値が $K$ であり, 多重辺が無い場合, $O(K N^{2/3} M)$ 時間.
  * 二部マッチングを求める場合 $O(\sqrt{N} M)$ 時間.

### min_cut
```cpp
vector<bool> F.min_cut(const int s)
```

* 頂点 $s$ を始点とする最小カットを求める.
* **返り値** : 最小カット $C = (S, T)$ の一例. 長さ $N$ の boolean 配列 $x$であり, 以下を満たす.
  * $v \in S \iff x_v = \mathbb{T}$.
  * $v \in T \iff x_v = \mathbb{F}$.
  * $s \in S$.
* **計算量** : $O(N + M)$ 時間.
