---
title: 木 DP
documentation_of: //Tree/Tree_DP.hpp
---

## Outline

木上の DP を計算するメソッドを提供する.

## Theory

このページでは, $T = (V, E)$ を木とする. また, 以下の記号を定義する.

* $T$ の根を $r$ とする.
* $v \in V \setminus \{r\}$ に対して, $\mathrm{par}(v) \in V$ を $V$ の親とする.
* $v \in V$ に対して $\mathrm{ch}(v) \subset V$ を $v$ の子全体の集合とする.

### Tree_DP_from_Root

`Tree_DP_from_Root` では, $\mathrm{dp}(v)$ が以下の要件をみたす場合の各 $\mathrm{dp}(v)$ を求める.

$X$ を集合, $\alpha \in X, f: X \times V \times V \to X$ とする. このとき,

$$ \mathrm{dp}(v) = \begin{cases}
        \alpha & (v = r) \\
        f(\mathrm{dp}(\mathrm{par}(v)), \mathrm{par}(v), v) & (\text{otherwise})
    \end{cases}$$

が成り立つときに適用できる.

つまり, $\mathrm{dp}(v)$ は根から $v$ へのパスを $u_0, u_1, \dots, u_k$ としたとき,

$$ \alpha , f(u_0, u_1), f(u_1, u_2), \dots, f(u_{k-1}, u_k) $$

から定まる値を求めることができる.

ここで, $f$ について,

* $f(v, w)$ について, $w$ のみに着目すれば, 頂点に着目していることになる.
* $f(v, w)$ について, $f(v, w) = f(w, v)$ が成立すれば, 辺に着目していることになる.

### Tree_DP_from_Leaf

`Tree_DP_from_Leaf` では, $\mathrm{dp}(v)$ が以下の要件をみたす場合の各 $\mathrm{dp}(v)$ を求める.

$X$ を集合, $(M, \odot)$ を $e \in M$ を単位元とする可換モノイド, $f: X \times V \times V \to X, g: M \times V \to X$ とする. このとき,

$$ \mathrm{dp}(v) = g \left(\bigodot_{w \in \mathrm{ch}(v)} f(\mathrm{dp}(w), v, w), v \right)$$

が成り立つときに適用できる.

これは, $\mathrm{dp}(v)$ は $v$ を含む部分木から定まる値を求めることができる.

## Examples

### Tree_DP_from_Root

[[Library Checker] Tree Diameter](https://judge.yosupo.jp/problem/tree_diameter)

適当な頂点 $r$ からの距離 $\mathrm{dist}(v)$ を求める必要がある. これは

$$\mathrm{dp}(v) = \begin{cases}
        0 & (v = r) \\
        \mathrm{dist}(\mathrm{par}(v)) + \mathrm{weight}(\mathrm{par}(v), v) & (\text{otherwise})
    \end{cases}$$

によって書ける. ただし, $uv \in E$ に対して, $\mathrm{weight}(u, v)$ で辺 $uv$ を表すとする.

このとき,

$$ X = \mathbb{N}, \quad f(w, u, v) = w + \mathrm{weight}(u, v), \quad \alpha = 0 $$

とすればよい.

### Tree_DP_from_Leaf

[[yukicoder] No.763 Noelちゃんと木遊び](https://yukicoder.me/problems/no/763)

$T$ を $r \in V$ を根とする根付き木と見なす.

各 $v \in V$ に対して, $x_v, y_v \in \mathbb{N}$ をそれぞれ以下で定める.

* $x_v$: 頂点 $v$ を根とする部分木において, 頂点 $v$ を削除する場合での連結成分の数の最大値.
* $y_v$: 頂点 $v$ を根とする部分木において, 頂点 $v$ を削除しない場合での連結成分の数の最大値.

このとき, $v \in V$ に対して,

$$ x_v = \sum_{w \in \mathrm{ch}(v)} \max(x_w, y_w), \quad y_v = \sum_{w \in \mathrm{ch}(v)} \max(x_w, y_w - 1) + 1 $$

をみたす.

$\boldsymbol{z}_v := \begin{pmatrix} x_v \\ y_v \end{pmatrix} \in \mathbb{N}^2$ と定めると,

$$ \mathbb{z}_v = \sum_{w \in \mathrm{ch}(v)} \begin{pmatrix} \max(x_w, y_w) \\ \max(x_w, y_w - 1) \end{pmatrix} + 1$$

である.

そのため,

$$
  X = \mathbb{N}^2, \quad
  (M, \odot) = (\mathbb{N}^2, +), \quad
  f \left(\begin{pmatrix} x \\ y \end{pmatrix}, u, v \right)
    = \begin{pmatrix} \max(x, y) \\ \max(x, y - 1) \end{pmatrix}, \quad
  g \left(\begin{pmatrix} x \\ y \end{pmatrix} \right)
    = \begin{pmatrix} x \\ y + 1 \end{pmatrix}, \quad
  e = \begin{pmatrix} 0 \\ 0 \end{pmatrix}
$$

とすればよい.

なお, 最終解答は $\max(x_r, y_r)$ である. このように, $\mathrm{dp}(r)$ そのままが最終解答になるとは限らないので注意すること.

## Contents

### Tree_DP_from_Root
```cpp
vector<X> Tree_DP_from_Root(Tree &T, function<X(X, int, int)> f, const X alpha)
```

* 根からの DP を行い, 各頂点における結果が入っているベクトルを求める. 適用条件等の詳細は Theory 節を参照.
* **引数**
  * $f: X \times V \times V \to X$.
  * $\alpha \in X$.
* **返り値**: 第 $v$ 要素が $\mathrm{dp}(v)$ であるベクトル.
* **計算量**: $O(N)$ 時間.

### Tree_DP_from_Leaf

```cpp
vector<X> Tree_DP_from_Leaf(Tree &T, function<M(X, int, int)> f, function<X(M, int)> g, function<M(M, M)> merge, const M unit)
```

* 根からの DP を行い, 各頂点における結果が入っているベクトルを求める. 適用条件等の詳細は Theory 節を参照.
* **引数**
  * $f: X \times V \times V \to M$.
  * $g: M \times V \to X$.
  * `merge`: $M$ 上の演算 $\odot$.
  * `unit`: $M$ の単位元.
* **返り値**: 第 $v$ 要素が $\mathrm{dp}(v)$ であるベクトル.
* **計算量**: $O(N)$ 時間.
