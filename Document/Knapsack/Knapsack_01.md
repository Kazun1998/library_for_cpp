---
title: 0-1 Knapsack 問題
documentation_of: //Knapsack/Knapsack_01.hpp
---

## Outline

0-1 Knapsack 問題を解く.

## Definition

以下で定義される最大化問題のことを, 「0-1 Knapsack 問題」という.

> * maximize $\displaystyle \sum_{i=1}^N v_i x_i$.
> * subject to
>    * $\displaystyle \sum_{i=1}^N w_i x_i \leq W$.
>    * $x_i \in \{0, 1\}$.

この問題は一般には NP 困難ではあるが, 特別な強い制約がつくと, 現実的な時間で解けるようになる.

## History

|日付|内容|
|:---:|:---|
|2026/01/04|Knapsack_01 の実装|
