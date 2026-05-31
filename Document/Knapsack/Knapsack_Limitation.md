---
title: 個数制限付き Knapsack 問題
documentation_of: //Knapsack/Knapsack_Limitation.hpp
---

## Outline

Knapsack 問題を解く.

## Definition

以下で定義される最大化問題のことを, 「個数制限付き Knapsack 問題」という.

> * maximize $\displaystyle \sum_{i=1}^N v_i x_i$.
> * subject to
>    * $\displaystyle \sum_{i=1}^N w_i x_i \leq W$.
>    * $0 \leq x_i \in m_i, x_i \in \mathbb{N}$.

## History

|日付|内容|
|:---:|:---|
|2026/03/29| Knapsack_Limitation の実装 |
