---
title: 永続 Segment Tree
documentation_of: //Segment_Tree/Persistent_Segment_Tree.hpp
---

## Outline

Segment Tree を永続化する. 区間を表すノードをポインタで実装する. そのため, 区間のコピーなどに対する処理を得意としている.
## Contents

### Constructor

```cpp
(1)
template<typename M>
Persistent_Segment_Tree(const vector<M> &data, const function<M(M, M)> op, const M identity)

(2)
template<typename M>
Persistent_Segment_Tree(const int n, const function<M(M, M)> op, const M identity)
```

- $\textrm{op}$ を演算, $\textrm{identity}$ を単位元とするモノイド $M$ に関する Segment Tree を作成する.
  * (1) $M$ の列 $\textrm{data}$ で初期化する.
  * (2) 長さ $n$ の単位元だけからなる列で初期化する.
- **計算量**
  * $O(N)$ Time.

### update

```cpp
(1) int update(const int s, const int t, const int k, const M x)
(2) int update(const int t, const int k, const M x)
(3) int update(const int k, const M x)
```

- Segment Tree に対して, バージョンと場所を指定して, $x$ に変更する.
  * (1) バージョン $s$ の Segment Tree の第 $k$ 要素を, $x$ に更新したものを, バージョン $t$ として上書きする.
  * (2) バージョン $t$ の Segment Tree の第 $k$ 要素を, $x$ に更新したものを, 最新バージョンとして上書きする.
  * (3) 最新バージョンの Segment Tree の第 $k$ 要素を, $x$ に更新したものを, 最新バージョンとして上書きする.
* **制約**
  * 指定するバージョン $s, t$ が存在すること.
  * $0 \leq k < N$.
* **返り値**
  * 更新先のバージョン
- **計算量**
  * $O(\log N)$ Time.

### amend

```cpp
int amend(const int t, const int k, const M x)
```
- `update(t, t, k, x)` のシノニム. つまり, バージョン $t$ の Segment Tree を, 第 $k$ 要素を $x$ に更新したものに上書きする.
* **制約**
  * 指定するバージョン $t$ が存在すること.
  * $0 \leq k < N$.
* **返り値**
  * 更新先のバージョン
- **計算量**
  * $O(\log N)$ Time.

### copy

```cpp
(1) int copy(const int s, const int t, const int l, const int r)
(2) int copy(const int t, const int l, const int r)
```

* 閉区間 $[l, r]$ におけるノードをコピー（部分共有）する.
  * (1) バージョン $s$ における閉区間 $[l, r]$ をバージョン $t$ の閉区間 $[l, r]$ にコピーする.
  * (2) バージョン $t$ における閉区間 $[l, r]$ を最新バージョン閉区間 $[l, r]$ にコピーする.
* **制約**
  * $0 \leq l \leq r \lt N$.
* **計算量**
  * $O(\log N)$ Time.

### increment

```cpp
int increment(int t = -1)
```

* バージョン $t$ をコピーして新しい最新バージョンを作成する. $t = -1$ の場合は現在の最新バージョンをコピーする.
* **返り値**
  * 新しい最新バージョンの番号
* **計算量**
  * $O(1)$ Time.

### clone

```cpp
(1) int clone(const int s, const int t)
(2) int clone(const int t)
```

* `copy(s, t, 0, n - 1)` 相当の処理を行い, Segment Tree をそのままコピーする.
  * (1) バージョン $s$ の Segment Tree をバージョン $t$ の Segment Tree に完全コピーする.
  * (2) バージョン $t$ の Segment Tree を最新バージョンの Segment Tree に完全コピーする.
* **制約**
  * 指定するバージョン $s, t$ が存在すること.
* **計算量**
  * $O(1)$ Time.

### product

```cpp
(1) M product(const int t, const int l, const int r) const
(2) M product(const int l, const int r) const
```

* 閉区間 $[l, r]$ における要素の総積を求める.
  * (1) バージョン $t$ の Segment Tree 上の閉区間 $[l, r]$ における要素の総積を求める.
  * (2) 最新バージョンの Segment Tree 上の閉区間 $[l, r]$ における要素の総積を求める.
* **制約**
  * 指定するバージョン $t$ が存在すること.
  * $0 \leq l \leq r < N$.
* **計算量**
  * $O(\log N)$ Time.

### all_product

```cpp
(1) M all_product(const int t) const
(2) M all_product() const
```

* 全区間の総積を求める.
* **計算量**
  * $O(1)$ Time.

### get

```cpp
(1) M get(const int t, const int k) const
(2) M get(const int k) const
(3) M operator[](const int k) const
```

* 第 $k$ 要素を取得する.
  * (1) バージョン $t$ の第 $k$ 要素を取得する.
  * (2), (3) 最新バージョンの第 $k$ 要素を取得する.
* **制約**
  * 指定するバージョン $t$ が存在すること.
  * $0 \leq t < N$.
* **計算量**
  * $O(\log N)$ Time.

### current_version

```cpp
int current_version()
```

* 最新バージョンの番号を取得する.
* **計算量**
  * $O(1)$ Time.

### size

```cpp
size_t size()
```

* 1 つのバージョンにおける, Segment Tree の要素数を取得する.
* **計算量**
  * $O(1)$ Time.
