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

## Theory

Monotone Minima を満たす関数は, [2 変数関数における単調性](/library_for_cpp/Monge.html) で扱う Monotone 行列 ($f(i, j)$ を第 $i$ 行第 $j$ 列の成分とみなしたもの) に他ならない. 以下の条件は, いずれも Monotone Minima を満たすための十分条件である.

* Monge 行列である. すなわち, 任意の $i_1 < i_2$, $j_1 < j_2$ に対して, $f(i_1, j_1) + f(i_2, j_2) \leq f(i_1, j_2) + f(i_2, j_1)$ を満たす.
* 全単調行列である. (Monge 行列ならば全単調行列である.)

これらの証明や, 関係の詳細は [2 変数関数における単調性](/library_for_cpp/Monge.html) を参照すること.

### Example

下に凸な列 $f$ と任意の列 $g$ に対して, $f(k - j) + g(j)$ は Monge 行列であるため, $(\min, +)$ 畳み込みを Monotone Minima によって計算できる.

* [Min_Plus_Convolution_Convex_Arbitrary](/library_for_cpp/Convolution/Min_Plus_Convolution_Convex_Arbitrary.html)

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
|2026/10/03| Monge 行列, 全単調行列との関係をドキュメントに追記 |
