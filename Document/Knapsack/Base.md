---
title: Knapsack 問題の Base クラス
documentation_of: //Knapsack/Base.hpp
---

## Outline

Knapsack 問題に関する解を定める.

## Definition

記号について, 以下のように定める.

* $I$: 有限集合
* 各 $i \in I$ に対して, $v_i, w_i$ はそれぞれ非負の整数である
* 各 $i \in I$ に対して, $M_i \subset \mathbb{N}$ であるとする.

以下で定義される最大化問題のことを, 「Knapsack 問題」という.

> * maximize $\displaystyle \sum_{i \in I} v_i x_i$.
> * subject to
>    * $\displaystyle \sum_{i \in I} w_i x_i \leq W$.
>    * $x_i \in M_i$.

この問題は一般には NP 困難ではあるが, 特別な強い制約がつくと, 現実的な時間で解けるようになる.

以下は具体例である.

* 任意の $i \in I$ に対して, $M_i = \\{0, 1\\}$ のとき: [0-1 Knapsack 問題](Knapsack_01.hpp)
* 任意の $i \in I$ に対して, $M_i = \mathbb{N}$ のとき: [Knapsack 問題](Knapsack_Infinity.hpp)
* 任意の $i \in I$ に対して, $M_i = \\{0, 1, \dots, m_i \\}$ のとき: [個数制限付き Knapsack 問題](Knapsack_Limitation.hpp)

## History

|日付|内容|
|:---:|:---|
|2026/03/31| Base に関する説明の追加 |
