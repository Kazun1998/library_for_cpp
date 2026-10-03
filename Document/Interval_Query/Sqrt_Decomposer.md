---
title: 平方分割
documentation_of: //Interval_Query/Sqrt_Decomposer.hpp
---

## Outline

[Interval_Decomposer](Interval_Decomposer.hpp) を平方分割によって実装したもの. ブロックサイズ $B = \max(1, \lfloor \sqrt{N} \rfloor)$ とし,

* 深さ $0$: 各ブロック (長さ $B$ 以下の区間 $B$ 個程度) を担当するノード.
* 深さ $1$: 各単独要素 $\{i\}$ を担当するノード (深さ $0$ のノードの葉).

の $2$ 段のみから成る森を構成する.

## Contents

以下, $N$ を全体の要素数, $B = \max(1, \lfloor \sqrt{N} \rfloor)$ をブロックサイズ, ブロック数を $\lceil N / B \rceil$ とする.

### Constructer

```cpp
explicit Sqrt_Decomposer(int n)
```

- 全体の要素数が `n` であるような平方分割器を構築する.
- **計算量** : $O(1)$ Time.

### decompose

```cpp
vector<tuple<int, int, int>> decompose(int l, int r) const override
```

- 半開区間 $[l, r)$ を, 完全に含まれるブロック (深さ $0$) と, 端に掛かる単独要素 (深さ $1$) に分解する.
- **制約**
  - $0 \leq l \leq r \leq N$.
- **計算量** : $O(\sqrt{N})$ Time.

### all_nodes

```cpp
vector<tuple<int, int, int>> all_nodes() const override
```

- 全てのブロック (深さ $0$) と全ての単独要素 (深さ $1$) を列挙する.
- **計算量** : $O(N)$ Time.

### ancestors

```cpp
vector<tuple<int, int, int>> ancestors(int i) const override
```

- 要素 $i$ の単独要素ノード (深さ $1$) と, それが属するブロックノード (深さ $0$) の, 計 $2$ 個のノードを返す.
- **制約**
  - $0 \leq i \lt N$.
- **計算量** : $O(1)$ Time.

### node_count

```cpp
int node_count() const override
```

- ノードの総数 ( ブロック数 $+ N$ ) を返す.
- **計算量** : $O(1)$ Time.

### node_index

```cpp
int node_index(int depth, int start) const override
```

- 深さ $0$ (ブロック) のノードは $[0, \lceil N/B \rceil)$ に, 深さ $1$ (単独要素) のノードは $[\lceil N/B \rceil, \lceil N/B \rceil + N)$ に, それぞれ一意な添字を割り当てる.
- **制約**
  - `(depth, start)` は, 構造中に実際に存在するノードでなければならない.
- **計算量** : $O(1)$ Time.

### children

```cpp
vector<tuple<int, int, int>> children(int depth, int start) const override
```

- 深さ $0$ (ブロック) のノードに対しては, そのブロックが担当する各単独要素 (深さ $1$) を返す.
- 深さ $1$ (単独要素) のノードは葉なので, 空のリストを返す.
- **制約**
  - `(depth, start)` は, 構造中に実際に存在するノードでなければならない.
- **計算量** : ブロックの場合 $O(\sqrt{N})$, 単独要素の場合 $O(1)$ Time.
