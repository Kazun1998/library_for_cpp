---
title: 二分木分割
documentation_of: //Interval_Query/Binary_Decomposer.hpp
---

## Outline

[Range_Decomposer](Range_Decomposer.hpp) をセグメント木型 (二分木) の分割によって実装したもの. 根を区間 $[0, N)$, 深さ $0$ のノードとし, ノード $[l, r)$ ( $r - l > 1$ ) は, $\mathrm{mid} = l + \lfloor (r - l) / 2 \rfloor$ を用いて,

* 左の子: $[l, \mathrm{mid})$, 深さ $+1$.
* 右の子: $[\mathrm{mid}, r)$, 深さ $+1$.

の $2$ つに再帰的に分割される. $N$ が $2$ の冪でない場合, 葉 (単独要素) の深さは要素ごとに異なりうる.

## Contents

以下, $N$ を全体の要素数とする. ノードの総数は $2N - 1$ (ただし $N = 0$ のときは $0$ ), 木の高さは $O(\log N)$ である.

### Constructer

```cpp
explicit Binary_Decomposer(int n)
```

- 全体の要素数が `n` であるような二分木分割器を構築する.
- **計算量** : $O(N)$ Time, $O(N)$ Space ( 全 $2N - 1$ 個のノードを構築するため ).

### decompose

```cpp
vector<tuple<int, int, int>> decompose(int l, int r) const override
```

- 半開区間 $[l, r)$ を, 根から再帰的に辿り, 完全に含まれる最小個数のノードに分解する ( いわゆる segment tree の canonical decomposition ).
- **制約**
  - $0 \leq l \leq r \leq N$.
- **計算量** : $O(\log N)$ Time.

### all_nodes

```cpp
vector<tuple<int, int, int>> all_nodes() const override
```

- 構造全体に存在する全ノード ( $2N - 1$ 個 ) を列挙する.
- **計算量** : $O(N)$ Time.

### ancestors

```cpp
vector<tuple<int, int, int>> ancestors(int i) const override
```

- 要素 $i$ を含む, 根から葉までの経路上にある全てのノードを列挙する.
- **制約**
  - $0 \leq i \lt N$.
- **計算量** : $O(\log N)$ Time.

### node_count

```cpp
int node_count() const override
```

- ノードの総数 $2N - 1$ ( $N = 0$ のときは $0$ ) を返す.
- **計算量** : $O(1)$ Time.

### node_index

```cpp
int node_index(int depth, int start) const override
```

- 構築時に割り振った, ノード $(depth, start)$ に対する $[0, node\_count())$ の一意な添字を返す.
- **制約**
  - `(depth, start)` は, 構造中に実際に存在するノードでなければならない.
- **計算量** : 平均 $O(1)$ Time ( 内部で `unordered_map` を用いているため ).

### children

```cpp
vector<tuple<int, int, int>> children(int depth, int start) const override
```

- ノード $(depth, start)$ が葉でなければ, その左右の子 (深さ $depth + 1$) の $2$ つを返す. 葉であれば空のリストを返す.
- **制約**
  - `(depth, start)` は, 構造中に実際に存在するノードでなければならない.
- **計算量** : 平均 $O(1)$ Time.
