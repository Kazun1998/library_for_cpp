---
title: 群作用 Union Find
documentation_of: //Union_Find/Group_Action_Union_Find.hpp
---

## Outline

無向グラフ $X = (V, E)$ と群 $G$ に対して,

* 辺の追加
* $2$ 頂点 $x, y \in V$ に対する連結判定
* 頂点 $x$ の属する連結成分全ての頂点に対して, $a \in G$ を作用させる
* 頂点 $x$ の値を取得する

を高速に行うことができるデータ構造

## Contents

### Constructer

```cpp
Group_Action_Union_Find(int n)
```

* $n$ 頂点の空グラフを生成する.

### find

```cpp
int find(int x)
```

* 頂点 $x$ が属する連結成分の代表元を求める.
* **制約**
  * $0 \leq x \lt n$.
* **計算量**
  * ならし $O(\alpha(n))$ 時間.

### unite

```cpp
bool unite(int x, int y)
```

* 無向辺 $xy$ を追加する.
* **制約**
  * $0 \leq x \lt n$.
  * $0 \leq y \lt n$.
* **返り値**
  * $x, y$ が元々非連結ならば `true`, 元々連結ならば `false`.
* **計算量**
  * ならし $O(\alpha(n))$ 時間.

### size
```cpp
int size(int x)
```

* 頂点 $x$ が属する連結成分における頂点数を求める.
* **制約**
  * $0 \leq x \lt n$.
* **計算量**
  * ならし $O(\alpha(n))$ 時間.

### same

```cpp
bool same(int x, int y)
```

* 頂点 $x, y$ が連結かどうかを判定する.
* **制約**
  * $0 \leq x \lt n$.
  * $0 \leq y \lt n$.
* **計算量**
  * ならし $O(\alpha(n))$ 時間.

### action

```cpp
void action(int x, G a)
```

* 頂点 $x$ が属する連結成分全てに左から $a$ を作用させる.
* **制約**
  * $0 \leq x \lt n$.
  * $a \in G$.
* **計算量**
  * ならし $O(\alpha(n))$ 時間.

### vertex_action

```cpp
void vertex_action(int x, G a)
```

* 頂点 $x$ に左から $a$ を作用させる.
* **制約**
  * $0 \leq x \lt n$.
  * $a \in G$.
* **計算量**
  * ならし $O(1)$ 時間.

### update

```cpp
void update(int x, const G& a)
```

* 頂点 $x$ を $a$ に更新する.
* **制約**
  * $0 \leq x \lt n$.
  * $a \in G$.
* **計算量**
  * ならし $O(1)$ 時間.

### get

```cpp
G get(int x)
G operator[](int x)
```

* 頂点 $x$ の値を取得する.
* **制約**
  * $0 \leq x \lt n$.
* **計算量**
  * ならし $O(\alpha(n))$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/03/22| Group_Action_Union_Find 実装 |
