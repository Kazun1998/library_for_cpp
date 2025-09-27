---
title: Subset Sum (多項式)
documentation_of: //Modulo_Polynomial/Subset_Sum.hpp
---

## Outline

正の整数からなる $A$ の (連続とは限らない) 部分列のうち, 和が $k=0,1,...,K$ になる組み合わせの総数 ($\textrm{Mod}$ で割った余り) を求める.

## Theory

$A = (A_1, \dots, A_N)$ とする.

$A$ における各項を選ぶ/選ばないを独立に選び, 総和を $k$ にする. そのため, 総和が $k$ になる部分列の数は

$$ \left[X^k \right] \prod_{i=1}^N \left(1 + X^{a_i} \right) $$

となる. よって,

$$ P := \prod_{i=1}^N \left(1 + X^{a_i} \right) $$

を求められればよい.

$1 \leq k \leq K$ に対して, $A$ における $k$ の数を $b_k$ とする.

このとき,

$$\begin{align*}
    \prod_{i=1}^N \left(1 + X^{a_i} \right)
    &= \prod_{k=1}^\infty \left(1 + X^k \right)^{b_k} \\
    &= \exp \left( \log \left( \prod_{k=1}^\infty \left(1 + X^k \right)^{b_k} \right) \right) \\
    &= \exp \left( \sum_{k=1}^\infty b_k \log \left(1 + X^k \right) \right) \\
    &= \exp \left( \sum_{k=1}^\infty b_k \sum_{m=1}^\infty \dfrac{(-1)^{m-1} X^{k m}}{m!} \right) \\
    &= \exp \left( \sum_{k=1}^\infty \sum_{m=1}^\infty \dfrac{(-1)^{m-1} b_k}{m!} X^{k m} \right)
\end{align*}$$

となる.

ここで, $k \leq K$ の範囲を求めるためには, $\pmod{X^K}$ を考えれば良い.

$$ Q := \sum_{k=1}^\infty \sum_{m=1}^\infty \dfrac{(-1)^{m-1} b_k}{m!} X^{k m}$$

の $Q \pmod{X^K}$ を求めるためには, $km \leq K$ を満たす正の整数の組 $(k, m)$ について考えれば良い.

$km \leq K$ となる正の整数の組の数 $(k, m)$ は $O(K \log K)$ 個である.

よって, $Q$ を $O(K \log K)$ 時間で求められる.

$Q$ を求められれば, $P = \exp Q$ も $O(K \log K)$ 時間で求められる.

従って, $P$ を $O(K \log K)$ 時間で求められる.

## Contents

```cpp
template<const ll Mod>
vector<modint<Mod>> Subset_Sum(vector<int> A, int K)
```

*  $A$ の (連続とは限らない) 部分列のうち, 和が $k=0,1,...,K$ になる組み合わせの総数 $b_k$ を $\textrm{Mod}$ で割った余りを求める.
* **返り値**
  * 長さが $(K + 1)$ の `modint<Mod>` からなるベクトル. 第 $k$ 項は $b_k$ を $\textrm{Mod}$ で割った余り (を表す `modint<Mod>` 型のインスタンス) をである.
* **計算量** : $O(K \log K)$ 時間
