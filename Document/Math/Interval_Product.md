---
title: 区間積
documentation_of: //Math/Interval_Product.hpp
---

## Outline

$G$ を群とする. 固定された $G$ 上の列 $A = (A_0, A_1, \dots, A_{N-1})$ に対して, 各 $0 \leq l \leq r \lt N$ に対して, 区間積

$$ A_l A_{l+1} \dots A_r $$

を高速に求められる.

## Theory

長さ $N$ の $G$ 上の列 $B$ を

$$ B_i = A_0 A_1 \dots A_i $$

で定める. このとき, $B_i = B_{i-1} A_i$ の関係を用いることによって, $B$ は合計で $O(N)$ 時間で求められる.

また,

$$ A_l A_{l+1} \dots A_r  = \left(B_{l-1} \right)^{-1} B_r $$

が成り立つため, 区間積を求める $1$ つのクエリについて, 区間積を $O(1)$ 時間で求められる.
