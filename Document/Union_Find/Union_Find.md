---
title: Union Find
documentation_of: //Union_Find/Union_Find.hpp
---

## Outline

無向グラフ $G = (V, E)$ に対して,

* 辺の追加
* $2$ 頂点 $x, y \in V$ に対する連結判定

を高速に行うことができるデータ構造

## Contents

### Constructer

```cpp
Union_Find U(int N)
```

* $N$ 頂点の空グラフを生成する.

### find

```cpp
int U.find(int x)
```

* 頂点 $x$ が属する連結成分の代表元を求める.
* **制約**
  * $0 \leq x \lt N$.
* **計算量**
  * ならし $O(\alpha(N))$ 時間.

### unite

```cpp
bool U.unite(int x, int y, bool force = false)
```

* 無向辺 $xy$ を追加する.
* **引数**
  * `force` を `true` にすると, 連結成分の代表元を `find(x)` になるようにマージするようになる.
* **制約**
  * $0 \leq x \lt N$.
  * $0 \leq y \lt N$.
* **返り値**
  * $x, y$ が元々非連結ならば `true`, 元々連結ならば `false`.
* **計算量**
  * ならし $O(\alpha(N))$ 時間.

### size
```cpp
bool U.size(int x)
```

* 頂点 $x$ が属する連結成分における頂点数を求める.
* **制約**
  * $0 \leq x \lt N$.
* **計算量**
  * ならし $O(\alpha(N))$ 時間.

### same

```cpp
bool U.same(int x, int y)
```

* 頂点 $x, y$ が連結かどうかを判定する.
* **制約**
  * $0 \leq x \lt N$.
  * $0 \leq y \lt N$.
* **計算量**
  * ならし $O(\alpha(N))$ 時間.

### group_count

```cpp
int U.group_count()
```

* グラフ $G$ の連結成分を求める.
* **計算量**
  * $O(1)$ 時間.
