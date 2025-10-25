---
title: 双対 Segment Tree
documentation_of: //Segment_Tree/Dual_Segment_Tree.hpp
---

## Outline

モノイド $F = (F, \circ, 1_F)$ 上の列 $A$ に対する 区間更新, 一点取得を得意とするデータ構造.

"双対" とついているのは, [Segment Tree](Segment_Tree.hpp) が一点更新と区間積取得を得意としているのに対して区間と一点が入れ替わっているからである.

また, 双対 Segment Tree は, [遅延評価 Segment Tree](Lazy_Segment_Tree.hpp) の作用素部分のみを抜き出したデータ構造とも言える.

## Contents

### Constructer

```cpp
Dual_Segment_Tree(int N, std::function<F(F, F)> comp, const F& id): N(N), comp(comp), id(id)
```

- 長さが $N$ の各項が $1_F$ の列で初期化する.
- $\operatorname{comp}: F \times F \to F; (\alpha, \beta) \mapsto \alpha \circ \beta$ : $F$ 上の二項演算
- $\mathrm{id}$ : $F$ の単位元 $1_F$.
- **計算量**
  * $O(N)$ Time.

### action

```cpp
void action(int l, int r, const F &alpha, bool left_closed = true, bool right_closed = true)
```

- 第 $l$ 要素から第 $r$ 要素に $\alpha \in F$ を作用させる.
* **引数**
  * `left_close`: `false` にすると, 左端が開区間になる.
  * `right_close`: `false` にすると, 右端が開区間になる.
* **制約**
  * 積を取る区間が $[0, N)$ に含まれる.
- **計算量**
  * $O(\log N)$ Time.

### get

```cpp
F get(int k)
```

* 第 $k$ 要素を取得する.
* **制約**
  * $0 \leq k \lt N$.
* **計算量**
  * $O(\log N)$ 時間.

### subscript operator

```cpp
F operator[](const int k)
```

* `get(k)` のエイリアス.
