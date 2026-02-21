---
title: Hungarian 法
documentation_of: //Calculate/Hungarian.hpp
---

## Outline

以下で表される割当問題を Hungarian 法で解く.

$N \leq M$ とする. $N$ 行 $M$ 列の行列 $A = (A_{i,j})_{\substack{1 \leq i \leq N \\ 1 \leq j \leq M}}$ が与えられる.

このとき,

$$ \sum_{i=1}^N A_{i, P_i} $$

を最小にする, 以下を満たす長さ $N$ の列を求める.

* $1 \leq P_i \leq M$.
* $P_1, \dots, P_M$ は全て異なる.

このクラスでは, この問題を Hungarian 法で解く.

## History 

|日付|内容|
|:---:|:---:|
|2026/02/15| スライド最大値 実装 |
