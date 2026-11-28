---
title: 全方位木 DP (Rerooting DP)
documentation_of: //Tree/Rerooting.hpp
---

## Outline

木上の全方位木 DP を計算するメソッドを提供する.

## Theory

このページでは, $T = (V, E)$ を木とする. また, 以下の記号を定義する.

* $T$ の根を $r$ とする.
* $v \in V \setminus \{r\}$ に対して, $\mathrm{par}^{(r)}(v) \in V$ を $T$ を $r$ を根としたときの $V$ の親とする.
* $v \in V$ に対して $\mathrm{ch}^{(r)}(v) \subset V$ $T$ を $r$ を根としたときの $v$ の子全体の集合とする.
* $v \in V$ に対して $\mathrm{des}^{(r)}(v) \subset V$ $T$ を $r$ を根としたときの $v$ の子孫全体の集合とする.

[葉からのDP](Tree_DP.hpp) では, 木 $T$ について, 固定された $1$ 頂点 $r_0$ を根とする根付き木に関して, 全ての部分木に関する値 $\mathrm{dp}^{(r_0)}(v)$ を $O(N)$ 時間で求めた.

全方位木 DP では, $T$ 上の各頂点について, その頂点を根とする根付き木と見なしたときの値 $\mathrm{dp}^{(r)}(r)$ を, 合計で $O(N)$ 時間で求めることができる.

オラクルは [葉からのDP](Tree_DP.hpp) と同様に行うことができる. ただし, 場合によっては, $g$ について, 頂点が根かどうかで切り分けることができる.

### 適用条件

$X$ を集合, $(M, \odot)$ を $e \in M$ を単位元とする可換モノイド, $f: X \times V \times V \to X, g: M \times V \to X$ とする. このとき, 固定された $r \in V$ において,

$$ \mathrm{dp}^{(r)}(v) = g \left(\bigodot_{w \in \mathrm{ch}^{(r)}(v)} f(\mathrm{dp}^{(r)}(w), v, w), v \right)$$

が成り立つときに適用できる. ただし, $f(x, v, w)$ について, 頂点 $v$ が頂点 $w$ に親であることを想定している.

## Examples

[[Library Checker] Tree Path Composite Sum](https://judge.yosupo.jp/problem/tree_path_composite_sum)

$r \in V$ と $x \in V$ に対して,

$$ \mathrm{dp}^{(r)}(x) := \sum_{y \in \mathrm{des}(x)} P(x, y) $$

とする.

このとき,

$$\begin{align*}
    \mathrm{dp}^{(r)}(v)
    &= \sum_{w \in \mathrm{des}(v)} P(v, w) \\
    &= P(v, v) + \sum_{\substack{w \in \mathrm{des}^{(r)}(v) \\ w \neq v}} P(v, w) \\
    &= a_v + \sum_{u \in \mathrm{ch}^{(r)}(v)} \sum_{w \in \mathrm{ch}^{(r)}(u) } P(v, w) \\
    &= a_v + \sum_{u \in \mathrm{ch}^{(r)}(v)} \sum_{w \in \mathrm{ch}^{(r)}(u) } f_{vu}(P(u, w)) \\
    &= a_v + \sum_{u \in \mathrm{ch}^{(r)}(v)} \sum_{w \in \mathrm{ch}^{(r)}(u) } \left(b_{uv} P(u, w) + c_{uv} \right) \\
    &= a_v + \sum_{u \in \mathrm{ch}^{(r)}(v)} \left(b_{uv} \sum_{w \in \mathrm{ch}^{(r)}(u) } P(u, w) + (\# \mathrm{des}^{(r)}(u)) c_{uv} \right) \\
    &= a_v + \sum_{u \in \mathrm{ch}^{(r)}(v)} \left(b_{uv} \mathrm{dp}^{(r)}(u) P(u, w) + (\# \mathrm{des}^{(r)}(u)) c_{uv} \right) \\
\end{align*}$$

となる.

そのため,

$$
    X = \mathbb{N}^2, \quad
    (M, \odot) = (\mathbb{N}^2, (0, 0)), \quad 
    f((s, t), u, v) = (b_{uv} \cdot s + c_{uv} \cdot t, t), \quad
    g\left((s, t), v \right) = (s + a_v, t + 1), \quad
    e = (0, 0) $$

## Contents

```cpp
template<typename X, typename M>
Rerooting_DP(Tree &T, function<M(X, int, int)> f, function<X(M, int)> g, function<M(M, M)> merge, const M unit)
```

* 全方位木 DP を行い, 各 $r \in V$ に対する $\mathrm{dp}^{(r)}(r)$ を求める. 適用条件等の詳細は Theory 節を参照.
* **引数**
  * $f: X \times V \times V \to M$.
  * $g: M \times V \to X$.
  * `merge`: $M$ 上の演算 $\odot$.
  * `unit`: $M$ の単位元.
* **返り値**: 第 $r$ 要素が $\mathrm{dp}(r)$ であるベクトル.
* **計算量**: $O(N)$ 時間.

```cpp
template<typename X, typename M>
Rerooting_DP(Tree &T, function<M(X, int, int)> f, function<X(M, int)> g, function<X(M, int)> h, function<M(M, M)> merge, const M unit)
```
