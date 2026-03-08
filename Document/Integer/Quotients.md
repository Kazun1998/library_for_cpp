---
title: 商の列挙 (Quotients)
documentation_of: //Integer/Quotients.hpp
---

## Outline

正の整数 $N$ に対して, 関数 $f: \mathbb{N} \to \mathbb{N}$ を

  $$ f(x) := \left \lfloor \dfrac{N}{x} \right \rfloor $$

で定義する.

  $$ E_N := \left\{ f(x) ~\middle|~ 1 \leq x \leq N \right\}$$

と, 各 $y \in E_N$ に対して, $f(x) = y$ を満たす $x$ の範囲を合計で $O(\sqrt{N})$ 時間で求める.

## Theory

### 主となる定理の証明
以下の定理が成り立つ.
> $ \\# E_N = O(\sqrt{N})$

#### 証明

  $$ E_N = \left\{ f(x) ~\middle|~ 1 \leq x \leq \sqrt{N} \right\} \cup \left\{ f(x) ~\middle|~ \sqrt{N} \leq x \leq N \right\}$$

と分割できる.

  $$ L_N := \left\{ f(x) ~\middle|~ 1 \leq x \leq \sqrt{N} \right\}, \quad R_N := \left\{ f(x) ~\middle|~ \sqrt{N} \leq x \leq N \right\} $$

とする.

##### $L_N$ について

$x$ が走る範囲は $1 \leq x \leq \sqrt{N}$ であるため, $\\# L_N \leq \sqrt{N}$ である.

##### $R_N$ について

$x \geq \sqrt{N}$ に対して, $\dfrac{N}{x} \leq \sqrt{N}$ である. よって, $f(x) \leq \sqrt{N}$ である. 故に, $\\# R_N \leq \sqrt{N}$ である.

以上から,

  $$ \# E_N = \# (L_N \cup R_N) \leq \# L_N + \# R_N \leq 2 \sqrt{N}$$

であるので, $\\# E_N = O(\sqrt{N})$ となる.

### アルゴリズムの構築

$f$ は広義単調減少であるため, 以下のアルゴリズムによって, 商の可能性を降順に全て列挙できる.

* $l \gets 1$ とする.
* 以下のループを $l \leq N$ である限り繰り返す.
    * $q \gets f(l)$ とする.
    * $x \in \mathbb{N}$ に対して, $f(x) = q \iff l \leq x \leq f(q)$ である. そのため, $f(x) = q$ となる範囲は $l \leq x \leq f(q)$ となる.
    * $l \gets f(q) + 1$ とする.

## Contents

```cpp
vector<tuple<ll, ll, ll>> Quotients(ll N)
```

* $E_N$ の要素 $q$ と $f(x) = q$ を満たす $q$ の範囲を $q$ の降順に出力する.
* **返り値**
  * $(q, l, r)$ の形. 各要素 (`tuple<ll, ll, ll>`) は以下を意味する.
    * $q \in E_N$ である.
    * $f(x) = q$ である範囲が $l \leq x \leq r$ となることを意味する.
* **計算量** : $O(\sqrt{N})$ 時間