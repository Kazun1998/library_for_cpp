---
title: 遅延評価 Segment Tree
documentation_of: //Segment_Tree/Lazy_Segment_Tree.hpp
---

## Outline

$M = (M, *, e_M), F = (F, \circ, 1_F)$ はそれぞれモノイドであり, $F$ は $M$ に左から作用するとする. この作用を $F \times M \to M; (\alpha,x) \mapsto \alpha(x)$ と書くことにする.

また, 任意の作用 $\alpha \in F$ は準同型であるとする.

つまり, この作用は以下を満たすとする.

- $\forall \alpha, \beta \in F, \forall x \in M; (\alpha \circ \beta)(x)=\alpha(\beta(x))$
- $\forall x \in M; 1_F(x)=x$
- $\forall \alpha \in F, \forall x,y \in M; \alpha(x * y)=\alpha(x) * \alpha(y)$

このような $M$ の列 $S$ に対する1点更新, $F$ の元による区間更新, $S$ の連続部分列における区間積の取得を得意とするデータ構造である.

## 注意点

$F$ における作用は左からである. $\alpha \circ \beta$ において, $\alpha$ が後から作用させる作用素になる.

## Contents

計算量において, $N$ を列の長さとする.

### Constructer

```cpp
Lazy_Segment_Tree(int size, const function<M(M, M)> op, const M unit, const function<M(F, M)> act, const function<F(F, F)> comp, const F id)
```

* 長さが `size` で各項が $e_M$ である列で初期化する.
* 引数
  * $\operatorname{op}: M \times M \to M; (x, y) \mapsto x * y$ : $M$ 上の二項演算.
  * $\mathrm{unit}$ : $M$ の単位元 $e_M$.
  * $\operatorname{act}: F \times M \to M; (\alpha, x) \mapsto \alpha(x)$: $F$ による $M$ への作用.
  * $\operatorname{comp}: F \times F \to M; (\alpha, \beta) \mapsto \alpha(x)$: $F$ における合成.
  * $\mathrm{id}$: $F$ の単位元.
* **計算量** : $O(N \log N)$ Time.

```cpp
Lazy_Segment_Tree(const vector<M> &vec, const function<M(M, M)> op, const M unit, const function<M(F, M)> act, const function<F(F, F)> comp, const F id)
```

* `vec` で初期化する.
* 引数
  * $\operatorname{op}: M \times M \to M; (x, y) \mapsto x * y$ : $M$ 上の二項演算.
  * $\mathrm{unit}$ : $M$ の単位元 $e_M$.
  * $\operatorname{act}: F \times M \to M; (\alpha, x) \mapsto \alpha(x)$: $F$ による $M$ への作用.
  * $\operatorname{comp}: F \times F \to M; (\alpha, \beta) \mapsto \alpha(x)$: $F$ における合成.
  * $\mathrm{id}$: $F$ の単位元.
  * **計算量** : $O(N \log N)$ Time.

### subscript operator
```cpp
M operator[](int k)
```

* $S_k$ を求める.
* **制約**
  * $0 \leq k \lt N$.
* **計算量** : $O(\log N)$ Time.

### action

```cpp
void action(int l, int r, F alpha)
```

- 第 $l$ 要素から第 $r$ 要素 $S_l, S_{l+1}, \dots, S_r$ に $\alpha \in F$ を作用させる.
- **制約**
  - $0 \leq l \leq r \lt N$
- **計算量** : $O(\log N)$ Time.

### update

```cpp
void update(int k, M x)
```

- 第 $k$ 要素 $S_k$ を $x \in M$ に更新する.
- **制約**
  - $0 \leq k \lt N$
- **計算量** : $O(\log N)$ Time.

### product

```cpp
M product(int l, int r)
```

- 積 $S_l * S_{l+1} * \dots * S_r$ を求める
- **制約**
  - $0 \leq l \leq r \lt N$
- **計算量** : $O(\log N)$ Time.

### all_product

```cpp
M all_product()
```
- $S$ の全ての要素に対する積 $S_0 * S_1 * \dots * S_{N-1}$ を求める
- **計算量** : $O(\log N)$ Time.
