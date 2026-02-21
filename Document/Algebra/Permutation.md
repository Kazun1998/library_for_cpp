---
title: 置換
documentation_of: //Algebra/Permutaion.hpp
---

## Outline

$N$ 次対称群 $\mathfrak{S}_N$ に対する計算を行う.

## Theory

$X$ を集合とする. $X$ から $X$ への全単射全体の集合を $\mathfrak{S}_X$ と書く.

$\mathfrak{S}_X$ は写像の合成を演算として群を成す.

特に, 非負整数 $N$ に対して,

$$ \mathfrak{S}_N := \mathfrak{S}_{\{1, 2, \dots, N \}} $$

として, この群を $N$ 次巡回群という. なお, このライブラリでは, C++ の言語仕様上,

$$ \mathfrak{S}_N = \mathfrak{S}_{\{0, 1, 2, \dots, N-1 \}} $$

として計算する.

## History

|日付|内容|
|:---:|:---:|
|2026/01/26| Permutation クラスの実装 |
