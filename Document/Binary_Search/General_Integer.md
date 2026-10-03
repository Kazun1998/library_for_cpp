---
title: 整数上の二分探索による境目の計算
documentation_of: //Binary_Search/General_Integer.hpp
---

## Outline

整数 $x$ に関する条件 $\operatorname{cond}(x)$ について, 以下を求める.

* $\operatorname{cond}$ が単調増加の場合 : $\operatorname{cond}(x)=\mathbb{T}$ になるような最小の整数 $x$.
* $\operatorname{cond}$ が単調減少の場合 : $\operatorname{cond}(x)=\mathbb{T}$ になるような最大の整数 $x$.

## Definition

$\mathbb{Z}$ 上の条件 $\operatorname{cond}: \mathbb{Z} \to \\{\mathbb{T}, \mathbb{F}\\}$ について, 以下を定義する.

* 以下を満たすとき, $\operatorname{cond}$ は単調増加であるという
  * $\forall x \in \mathbb{Z};\,\operatorname{cond}(x) = \mathbb{T} \Rightarrow \left(\forall y \geq x;\, \operatorname{cond}(y)=\mathbb{T} \right)$.
* 以下を満たすとき, $\operatorname{cond}$ は単調減少であるという
  * $\forall x \in \mathbb{Z};\,\operatorname{cond}(x) = \mathbb{F} \Rightarrow \left(\forall y \geq x;\,\operatorname{cond}(y)=\mathbb{F} \right)$.
* $\operatorname{cond}$ が単調増加または単調減少であるとき, $\operatorname{cond}$ は単調であるという.

## Theory

単調増加である $\operatorname{cond}$ に対して, $\operatorname{cond}(x) = \mathbb{T}$ となる最小の $x \in \mathbb{Z}$ を $X$ として, $X$ を求める.

このとき, 以下のアルゴリズムを適用させることで高速に求められる.

1. $L_0, R_0 \in \mathbb{Z}$ を $\operatorname{cond}(L_0) = \mathbb{F}, \operatorname{cond}(R_0) = \mathbb{T}$ であるとする. このとき, 単調性から, $L_0 \lt X \leq R_0$ が保証されている.
2. $L \gets L_0, R \gets R_0$ とする.
3. $R - L > 1$ である限り, 以下を繰り返し行う.
    * $C:=\left \lfloor \dfrac{L+R}{2} \right \rfloor$ とする.
    * $\operatorname{cond}(C)=\mathbb{T}$ ならば, $L \lt X \leq C$ であることが分かる. よって, $R \gets C$ とする.
    * $\operatorname{cond}(C)=\mathbb{F}$ ならば, $C \lt X \leq R$ であることが分かる. よって, $L \gets C$ とする.
4. イテレートの条件と初期値の定め方から, ここに来たときは $R - L = 1$ である. よって, $L \lt X \leq R$ となる整数 $X$ は $X = R$ に限られる. 従って, $R$ を出力すれば良い.

このアルゴリズムにおいて, イテレート $1$ 回で $(R-L)$ はもともとの約半分になる.

よって, $X$ を $O(\log (R-L))$ 回のイテレートで求められ, $\operatorname{cond}$ の $1$ 回当たりの計算量を $O(K)$ とすると, 合計で $O(K \log(R-L))$ 時間で $X$ を求められる.

## Contents

$\textrm{cond}$ の時間計算量を $O(K)$ 時間とする.

### General_Binary_Increase_Search_Integer

```cpp
template<typename T>
T General_Binary_Increase_Search_Integer(T L, T R, const auto& cond, T default_value)
```

* $[L, R]$ 上で単調増加な条件 $\mathrm{cond}$ に対し, $\mathrm{cond}(x)$ が真となる最小の整数 $x$ を二分探索で求める.
* **引数**
  * $L$ : 探索範囲の下端.
  * $R$ : 探索範囲の上端.
  * $\textrm{cond}$: $[L, R]$ 上の単調増加な関数.
  * `default_value`: $\mathrm{cond}(R)$ が偽のときの返り値.
* **返り値**
  * $\mathrm{cond}(R)$ が偽の場合は `default_value` である.
  * そうでない場合は $\mathrm{cond}(x)$ が真となる最小の整数 $x \in [L, R]$ である.
* **制約**
  * $L \leq R$.
* **計算量**
  * $O(K \log(R - L))$ 時間.

### General_Binary_Decrease_Search_Integer

```cpp
template<typename T>
T General_Binary_Decrease_Search_Integer(T L, T R, const auto& cond, T default_value)
```

* $[L, R]$ 上で単調減少な条件 $\mathrm{cond}$ に対し, $\mathrm{cond}(x)$ が真となる最大の整数 $x$ を二分探索で求める.
* **引数**
  * $L$ : 探索範囲の下端.
  * $R$ : 探索範囲の上端.
  * $\textrm{cond}$ : $[L, R]$ 上の単調減少な関数.
  * `default_value`: $\mathrm{cond}(L)$ が偽のときの返り値.
* **返り値**
  * $\mathrm{cond}(L)$ が偽の場合は `default_value` である.
  * そうでない場合は $\mathrm{cond}(x)$ が真となる最大の整数 $x \in [L, R]$ である.
* **制約**
  * $L \leq R$.
* **計算量**
  * $O(K \log(R - L))$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/08/20| document の作成 |
|2025/09/24| 整数上の二分探索 実装 |
