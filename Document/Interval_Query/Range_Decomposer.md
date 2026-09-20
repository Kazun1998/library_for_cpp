---
title: Range Decomposer
documentation_of: //Interval_Query/Range_Decomposer.hpp
---

## Outline

列に対するクエリを部分区間に分割して高速に処理する場合における部分区間への分割を求める.

## Theory

深さ $d$ と区間 $[l, r) \subset [0, N)$ の組をノードと呼び, 次を満たすノードの集合 (森) を考える.

* 深さ $0$ のノードが持つ区間全体は, $[0, N)$ の分割になる.
* 各ノードは子ノードの集合 (空でもよい) を持ち, 子ノードが持つ区間は, 親ノードが持つ区間の分割になる. 子ノードの深さは, 親ノードの深さ $+1$ である.
* 子ノードを持たないノード (葉) が持つ区間は, ある $i \in [0, N)$ に対する単独区間 $\{i\}$ である. 葉の深さは, ノードごとに異なっていてもよい.
* 任意の $i \in [0, N)$ に対して, 区間 $\{i\}$ を持つ葉がただ $1$ つ存在する.

このとき, 任意の区間 $[l, r) \subset [0, N)$ に対して, なるべく少ない個数のノードに含まれる区間 $I_1, \dots, I_k$ を用いて,

$$ [l, r) = I_1 \sqcup \dots \sqcup I_k $$

としたい.

## Contents

以下, $N$ を全体の要素数とする. 各メソッドの計算量は, 派生クラスの実装に依存する.

### Constructer

```cpp
explicit Range_Decomposer(int n)
```

- 全体の要素数が `n` であるような区間 $[0, n)$ に対する分解器を構築する (抽象基底クラスなので, 実際には派生クラスのコンストラクタを通して呼ばれる).

### size

```cpp
int size() const
```

- 全体の要素数 $N$ を返す.
- **計算量** : $O(1)$ Time.

### decompose

```cpp
virtual vector<tuple<int, int, int>> decompose(int l, int r) const = 0;
```

- 半開区間 $[l, r)$ を, なるべく少ない個数のノードの区間 $I_1, \dots, I_k$ に分解する ( $[l, r) = I_1 \sqcup \dots \sqcup I_k$ ).
- 返り値は `(depth, start, end)` のリストであり, 各要素は区間 `[start, end)` を持つノードを表す.
- **制約**
  - $0 \leq l \leq r \leq N$.

### all_nodes

```cpp
virtual vector<tuple<int, int, int>> all_nodes() const = 0;
```

- 構造全体に存在する全てのノードを列挙する.
- 返り値は `(depth, start, end)` のリスト.

### ancestors

```cpp
virtual vector<tuple<int, int, int>> ancestors(int i) const = 0;
```

- 要素 $i$ を含む全てのノード (すなわち, 区間 $\{i\}$ を持つ葉から根までの経路上にあるノード) を列挙する.
- 返り値は `(depth, start, end)` のリスト.
- **制約**
  - $0 \leq i \lt N$.

### node_count

```cpp
virtual int node_count() const = 0;
```

- 構造全体に存在するノードの総数を返す.

### node_index

```cpp
virtual int node_index(int depth, int start) const = 0;
```

- 深さ `depth`, 左端 `start` を持つノードを, `[0, node_count())` の一意な添字に変換する.
- **制約**
  - `(depth, start)` は, 構造中に実際に存在するノードでなければならない.

### children

```cpp
virtual vector<tuple<int, int, int>> children(int depth, int start) const = 0;
```

- 深さ `depth`, 左端 `start` を持つノードの子ノードを列挙する. 子ノードを持たない場合 (葉) は空のリストを返す.
- 返り値は `(depth + 1, start, end)` のリスト.
- **制約**
  - `(depth, start)` は, 構造中に実際に存在するノードでなければならない.
