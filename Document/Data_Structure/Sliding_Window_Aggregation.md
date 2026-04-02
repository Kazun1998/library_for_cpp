---
title: Sliding Window Aggregation
documentation_of: //Data_Structure/Sliding_Window_Aggregation.hpp
---

## Outline

Monoid $M$ に対する Queue $Q$ に対して, 以下の処理を高速に行う.

* $Q$ の先頭に $a \in M$ を挿入する.
* $Q$ の末尾に $a \in M$ を挿入する.
* $Q$ の先頭要素を削除する.
* $Q$ の末尾要素を削除する.
* $Q = (a_1, a_2, \dots, a_n)$ として, 総積 $a_1 a_2 \dots a_n$ を求める.

## History 

|日付|内容|
|:---:|:---:|
|2026/02/14| Sliding Window Aggregation 実装 |
