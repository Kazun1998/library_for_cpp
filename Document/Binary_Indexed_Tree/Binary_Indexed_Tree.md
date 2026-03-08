---
title: Binary Indexed Tree (Fenwick Tree)
documentation_of: //Binary_Indexed_Tree/Binary_Indexed_Tree.hpp
---

## Outline

可換群 $G = (G, +, 0_G)$ の列に $A$ に対する 1 点更新, 区間積の取得を得意とするデータ構造.

## Contents

### Constructer

```cpp
Binary_Indexed_Tree B(int n, const function<G(G, G)> op, const G zero, const function<G(G)> neg)
```

* 長さが $n$ の各項が $0_G$ の列で初期化する.
* $\operatorname{op}: M \times M \to M; (x, y) \mapsto x + y$ : $G$ 上の二項演算
* $\mathrm{zero}$ : $G$ の単位元 $0_G$.
* $\mathrm{neg}: G \to G; x \mapsto -x$ : $G$ 上の逆元関数
* **計算量** : $O(N)$ 時間

```cpp
Binary_Indexed_Tree (const vector<G> &vec, const function<G(G, G)> op, const G zero, const function<G(G)> neg)
```

* $G$ の列 `vec` で初期化する.
* $\operatorname{op}: M \times M \to M; (x, y) \mapsto x + y$ : $G$ 上の二項演算
* $\mathrm{zero}$ : $G$ の単位元 $0_G$.
* $\mathrm{neg}: G \to G; x \mapsto -x$ : $G$ 上の逆元関数
* **計算量** : $O(N)$ 時間

### add

```cpp
void B.add(int k, G x)
```

* 第 $k$ 項に $x \in G$ を加算する.
* **制約**
  * $0 \leq k \lt N$.
* **計算量** : $O(\log N)$ 時間.

### update

```cpp
void B.update(int k, G x)
```

* 第 $k$ 項を $x \in G$ に変更する.
* **制約**
  * $0 \leq k \lt N$.
* **計算量** : $O(\log N)$ 時間.


### sum

```cpp
G B.sum(int k)
```

* 連続部分列における総和 $\displaystyle \sum_{k=0}^k A_x$ を求める.
* **制約**
  * $0 \leq k \lt N$.
* **計算量** : $O(\log N)$ 時間.

```cpp
G B.sum(int l, int r)
```

* 連続部分列における総和 $\displaystyle \sum_{k=l}^r A_k$ を求める.
* **制約**
  * $0 \leq l \leq r \lt N$.
* **計算量** : $O(\log N)$ 時間.
* **注意点**
  * $l \leq r$ でないとき, 返り値は単位元 $0_G$ になる.

### subscript operator
```cpp
G operator[](int k)
```

* $A_k$ を求める.
* **制約**
  * $0 \leq k \lt N$.
* **計算量** : $O(\log N)$ 時間.
