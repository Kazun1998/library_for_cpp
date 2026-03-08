---
title: Bernoulli 数
documentation_of: //Modulo_Polynomial/Bernoulli_Number.hpp
---

## Outline

$n = 0, 1, 2, \dots, N$ に対する Bernoulli 数 $B_n$ を形式的ベキ級数の理論を用いて, 高速に求める.

## Theory

以下を満たすようにして定義される列 $(B_n)_{n \geq 0}$ を Bernoulli 数という.

$$ \dfrac{x}{e^x-1} = \sum_{n=0}^\infty \dfrac{B_n}{n!}{x^n} $$
