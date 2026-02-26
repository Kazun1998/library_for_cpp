---
title: 部分木に関するクエリ
documentation_of: //Tree/Subtree_Monoid_Vertex_Query.hpp
---

## Outline

頂点 $r$ を根とする根付き木 $T = (V, E)$ がある. 可換モノイド $M$ と $a: V \to M$ に関する以下の処理を高速に行う.

* $v \in V, x \in M$ に対して, $a_v \gets x$.
* 頂点 $v$ を根とする部分木における $a_v$ 達の総積を求める.

## Contents

### Constructor

```cpp
template<typename M>
Subtree_Monoid_Vertex_Query(Tree &tree, const vector<M> &data, const function<M(M, M)> op, const M unit)
```

* 根付き木 $T$ と可換モノイド $M$ からなる部分木計算クエリの準備を行う.
* **引数**
  * $T$: 根付き木.
  * `merge`: $M$ 上の演算 $\odot$.
  * `unit`: $M$ の単位元.
* **計算量**: $T$ の位数を $N$ として, $O(N \log N)$ 時間.

### update

```cpp
void update(const int &v, const M &x)
```

* 頂点 $v$ における値 $a_v$ を $x$ に変える.
* **引数**
  * $v$: 頂点.
  * $x \in M$.
* **計算量**: $O(\log N)$ 時間.

### update

```cpp
void query(const int &v, const M &x)
```

* 頂点 $v$ を根とする部分木に関する総積を求める.
* **引数**
  * $v$: 頂点.
* **計算量**: $O(\log N)$ 時間.