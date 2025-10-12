---
title: Disjoint Sparse Table
documentation_of: //Data_Structure/Disjoint_Sparse_Table.hpp
---

## Outline

Monoid $M$ の静的な列 $S = (S_0, S_1, \dots, S_{N-1})$ に対する区間積を以下の高速な計算量で計算を行う.

* 前計算: $O(N \log N)$ 時間.
* 本計算: $O(1)$ 時間.

## Contents

### Constructer

```cpp
Disjoint_Sparse_Table D(const std::vector<M> &data, const std::function<M(M, M)> op, const M unit)
```

* Monoid $M$ 上の静的な列 `data` に関する Disjoint Sparse Table を構築する.
* **引数**
  * `data`: $M$ 上の列
  * `op`: $M$ における演算 $M \times M \to M; (x, y) \mapsto xy$.
  * `unit`: $M$ における単位元.
* **計算量**:
  * `data` のサイズを $N$ として, $O(N \log N)$ 時間.

### product

```cpp
M S.product(int l, int r, bool left_close = true, bool right_close = true)
```

* 区間積 $S_l * S_{l+1} * \dots * S_r$ を求める.
* **引数**
  * `left_close`: `false` にすると, 左端が開区間になる.
  * `right_close`: `false` にすると, 右端が開区間になる.
* **制約**
  * 積を取る区間が $[0, N)$ に含まれる.
* **計算量** : $O(1)$ 時間
