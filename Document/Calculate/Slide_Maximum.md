---
title: スライド最大値
documentation_of: //Calculate/Slide_Maximum.hpp
---

## Outline

全順序の列 $A = (A_1, \dots, A_N)$ と固定された整数 $K~(1 \leq K \leq N)$ に対して, 長さが $K$ の連続部分列に対する最大値を可能な全ての連続部分列を求める.

つまり, 以下によって定義される長さ $(N-K+1)$ の列 $B = (B_1, \dots, B_{N-K+1})$ を求める.

* $B_j := \max(A_j, A_{j+1}, \dots, A_{j+K-1})$.


## History 

|日付|内容|
|:---:|:---:|
|2026/02/24| Slide_Maximum_Index がテンプレート対応していなかったバグの修正 |
|2026/02/15| スライド最大値 実装 |
