---
title: Monotone Minima
documentation_of: //Queries/Monotone_Minima.hpp
---

## Outline

Monotone Minima な $2$ 変数関数 $f(i, j)$ について, 各 $i$ に対する $\displaystyle \min \left(\operatorname*{argmin}_j f(i, j) \right)$ を求める.

## Definition

$Y$ を全順序集合とする.

$f: \\{0, 1, \dots, n - 1 \\} \times \\{0, 1, \dots, m - 1 \\} \to Y$ が Monotone Minima を満たすとは,

$$ \min \left(\operatorname*{argmin}_{0 \leq j < m} f(0, j) \right) \leq \min \left(\operatorname*{argmin}_{0 \leq j < m} f(1, j) \right) \leq \dots \leq \min \left(\operatorname*{argmin}_{0 \leq j < m} f(n-1, j) \right)$$

を満たすことである.

## Contents

### constructor

```cpp
template<typename FUNC>
vector<int> Monotone_Minima(const int n, const int m, const FUNC eval)
```

* Monotone Minima である関数 `eval` について, 各 $i~(0 \leq i < n)$ に対する $\displaystyle \min \left(\operatorname*{argmin}_{0 \leq j < m} f(i, j) \right)$ を求める.
* **引数**
  * $n$: 第 $1$ 引数の範囲
  * $m$: 第 $2$ 引数の範囲
  * `eval`: Monotone Minima 関数
* **計算量**
  * $O(n + m \log n)$ 時間

## History

|日付|内容|
|:---:|:---:|
|2026/07/13| Monotone_Minima 実装 |
