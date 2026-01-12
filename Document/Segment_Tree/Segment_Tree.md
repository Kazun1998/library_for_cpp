---
title: Segment Tree
documentation_of: //Segment_Tree/Segment_Tree.hpp
---

## Outline

モノイド $M = (M, *, e_M)$ の列に $A$ に対する 1 点更新, 区間積の取得を得意とするデータ構造.

## Contents

### Constructer

```cpp
Segment_Tree S(int size, const function<M(M, M)> op, const M unit)
```

- 長さが `size` の各項が $e_M$ の列で初期化する.
- $\operatorname{op}: M \times M \to M; (x, y) \mapsto x * y$ : 二項演算
- $\mathrm{unit}$ : $M$ の単位元 $e_M$.

```cpp
Segment_Tree S(const vector<M> &vec, const function<M(M, M)> op, const M unit)
```

- `vec` で初期化する.
- $\operatorname{op}: M \times M \to M; (x, y) \mapsto x * y$ : 二項演算
- $\mathrm{unit}$ : $M$ の単位元 $e_M$.
- **計算量** : $O(1)$ Time.

### update

```cpp
void S.update(int k, M x)
```

- 第 $k$ 要素を $x$ に更新する.
- **制約**
  - $0 \leq k \lt N$.
- **計算量** : $O(\log N)$ 時間

### product

```cpp
M S.product(int l, int r)
```

* 連続部分列における積 $A_l * A_{l+1} * \dots A_{r-1} * A_r$ を求める.
* **制約**
  * $0 \leq l \leq r \lt N$.
* **注意点**
  * $l \leq r$ でないとき, 返り値は単位元 $e_M$ になる.

### max_right

```cpp
int max_right(int l, const Func &cond)
```

* $M$ の部分集合 $T$ を $T := \{x \in M \mid \textrm{cond}(x)\}$ で定義する. このとき, 以下の条件を両方満たす $r$ (のいずれか 1 つ) 返す.
  * $r = l$ もしくは $A_l * A_{l + 1} * \dots * A_{r-1} \in T$.
  * $r = N$ もしくは $A_l * A_{l + 1} * \dots * A_r \not \in T$.
* $\textrm{cond}$ が単調だとすれば, $A_l * A_{l + 1} \dots * A_{r - 1} \in T$ となる最大の $r$ と解釈することが可能である.
* **制約**
  * $e_M \in T$.
* **計算量**
  * $O(\log N)$ 時間.

### min_left

```cpp
int min_left(int r, const Func &cond)
```

* $M$ の部分集合 $T$ を $T := \{x \in M \mid \textrm{cond}(x)\}$ で定義する. このとき, 以下の条件を両方満たす $l$ (のいずれか 1 つ) 返す.
  * $l = r$ もしくは $A_l * A_{l + 1} * \dots * A_{r-1} \in T$.
  * $l = 0$ もしくは $A_{l-1} * A_l * \dots * A_{r-1} \not \in T$.
* $\textrm{cond}$ が単調だとすれば, $A_l * A_{l + 1} \dots * A_{r - 1} \in T$ となる最大の $l$ と解釈することが可能である.
* **制約**
  * $e_M \in T$.
* **計算量**
  * $O(\log N)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/01/12|max_right, min_left の実装|
|2025/10/30|初期化の際に発生していた, 配列外参照バグの修正|
|2025/08/15|Segment_Tree 実装|
