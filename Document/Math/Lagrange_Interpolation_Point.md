---
title: Lagrange 補完
documentation_of: //Math/Lagrange_Interpolation.hpp
---

## Outline

$(d+1)$ 個の点 $(x_0, y_0), (x_1, y_1), \dots, (x_d, y_d)$ について, $(d+1)$ 個の条件

$$ f(x_i) = y_i \quad (0 \leq i \leq d)$$

を満たす $d$ 次以下の多項式 $f$ に関する値を求める.

## Theory

### Lagrange 多項式を使った, 多項式の決定

$F$ を体とする.

$(d+1)$ 個の点 $(x_0, y_0), (x_1, y_1), \dots, (x_d, y_d)$ について, $x_0, x_1, \dots, x_d$ は互いに異なるとする.
このとき,

$$ f(x_i) = y_i \quad (0 \leq i \leq d)$$

を満たす $d$ 次以下の多項式 $f$ はただ $1$ つ存在する. 証明は Vandermonde 行列が正則であることから従う.

---

$i = 0, 1, \dots, d$ に対して, Lagrange 多項式 $\ell_i(x)$ を

$$ \ell_i(x) := \prod_{\substack{0 \leq j \leq d \\ j \neq i}} \dfrac{x - x_j}{x_i - x_j} $$

で定める. このとき, $i, j \in \\{0, 1, \dots, d \\}$ に対して,

$$ \ell_i(x_j) = \delta_{i, j} $$

が成り立つ.

このとき, 多項式 $g$ を

$$ g(x) := \sum_{i=0}^d y_i \ell_i(x) $$

で定めると,

$$ g(x_j) = \sum_{i=0}^d y_i \ell_i(x_j) = \sum_{i=0}^d y_i \delta_{i,j} = y_j $$

である. ただし, $\delta_{i,j}$ は Kronecker Delta.

よって, $f, g$ は相異なる $(d+1)$ 個の点で一致する $d$ 次以下の多項式であるため, $f = g$ が成り立つ. 故に,

$$ f(x) = \sum_{i=0}^d y_i \ell_i(x) $$

である.

### 特定の一点における値

$(d+1)$ 個の点 $(x_0, y_0), (x_1, y_1), \dots, (x_d, y_d)$ について, $(d+1)$ 個の条件

$$ f(x_i) = y_i \quad (0 \leq i \leq d)$$

を満たす $d$ 次以下の多項式 $f$ に関する $f(s)$ の値を求める.

各 $i$ に対して, $\ell_i(s)$ は $O(d)$ 時間で求められる. 故に,

$$ f(s) = \sum_{i=0}^d y_i \ell_i(s) $$

であるため, $f(s)$ は $O(d^2)$ 時間で求められる.

### 多項式の各係数を求める

多項式 $m(x)$ を

$$m(x) := \prod_{i=0}^d (x - x_i)$$

と置く. この $m(x)$ は $O(d^2)$ 時間で求めることができる. このとき,

$$\ell_i(x) = \dfrac{1}{m'(x_i)} \cdot \dfrac{m(x)}{x - x_i}$$

である.

ここで $m'(x_i) = \prod_{j \neq i} (x_i - x_j)$ であり, これは $m(x)$ を微分した多項式 $m'(x)$ に $x = x_i$ を代入することで得られる.

各 $i$ について, 微分係数 $m'(x_i)$ の計算に $O(d)$ 時間, 多項式の除算（組立除法）に $O(d)$ かかるため, 各 $\ell_i(x)$ は $O(d)$ 時間で求められる.

これを $(d+1)$ 個足し合わせるため, 全体の計算量は $O(d^2)$ 時間である。

故に, 各 $\ell_i(x)$ は $O(d)$ 時間で求められ, これを $(d+1)$ 個合計するため, 合計の時間計算量は $O(d^2)$ 時間である.

## 標本点が等差数列のとき

もし, 標本点 $x_i$ が等差数列 $x_i = ai + b$ を満たしているならば, 特定の点 $f(s)$ を求める計算量は $O(d^2)$ 時間から, $O(d)$ 時間に大きく落ちる.

Lagrange 多項式の値 $\ell_i(s)$ について,

$$\begin{align*}
    \ell_i(s)
    &= \prod_{\substack{0 \leq j \leq d \\ j \neq i}} \dfrac{s - x_j}{x_i - x_j} \\
    &= \prod_{\substack{0 \leq j \leq d \\ j \neq i}} \dfrac{s - (aj+b)}{(ai+b) - (aj+b)} \\
    &= \prod_{\substack{0 \leq j \leq d \\ j \neq i}} \dfrac{s - (aj+b)}{a(i-j)} \\
    &= \dfrac{1}{a^d} \prod_{\substack{0 \leq j \leq d \\ j \neq i}} \dfrac{s - (aj+b)}{i-j}
\end{align*}$$

である. ここで,

$$ \varepsilon_j := s - (a j + b) $$

とおくと,


$$\begin{align*}
    \ell_i(s)
    &= \dfrac{1}{a^d} \prod_{\substack{0 \leq j \leq d \\ j \neq i}} \dfrac{s - (aj+b)}{i-j} \\
    &= \dfrac{1}{a^d} \prod_{\substack{0 \leq j \leq d \\ j \neq i}} \dfrac{\varepsilon_j}{i-j} \\
    &= \dfrac{1}{a^d} \cdot \dfrac{\left(\varepsilon_0 \varepsilon_1 \dots \varepsilon_{i-1} \right) \left(\varepsilon_{i+1} \varepsilon_{i+2} \dots \varepsilon_{d} \right) }{i \cdot (i-1) \dots 1 \cdot (-1) \cdot (-2) \dots (-(i-d))} \\
    &= \dfrac{1}{a^d} \cdot \dfrac{\left(\varepsilon_0 \varepsilon_1 \dots \varepsilon_{i-1} \right) \left(\varepsilon_{i+1} \varepsilon_{i+2} \dots \varepsilon_{d} \right) }{i! \cdot (d-i)! \cdot (-1)^{d-i}} \\
    &= \dfrac{(-1)^i}{(-a)^d} \cdot \dfrac{\left(\varepsilon_0 \varepsilon_1 \dots \varepsilon_{i-1} \right) \left(\varepsilon_{i+1} \varepsilon_{i+2} \dots \varepsilon_{d} \right) }{i! \cdot (d-i)!}
\end{align*}$$

である.

$$ \textrm{prefix}_i := \varepsilon_0 \varepsilon_1 \dots \varepsilon_i, \quad \textrm{suffix}_i := \varepsilon_i \varepsilon_{i+1} \dots \varepsilon_d $$

とおくと,

$$ \ell_i(s) = \dfrac{(-1)^i}{(-a)^d} \cdot \dfrac{\textrm{prefix}_{i-1} \cdot \textrm{suffix}_{i+1} }{i! \cdot (d-i)!} $$

である.

$\textrm{prefix}_i, \textrm{suffix}_i$ はそれぞれ順番に注意して累積的に計算することにより, $i=0,1,\dots,d$ を合計で $O(d)$ 時間で求められる.

階乗の逆元も, $(0!)^{-1}, (1!)^{-1}, \dots, (d!)^{-1}$ を合計で $O(d)$ 時間で求められる.

以上から, 前計算 $O(d)$ 時間の元で $0 \leq i \leq d$ における $\ell_i(s)$ をで各 $O(1)$ 時間で求められる.

故に, $f(s)$ を $O(d)$ 時間で求められる.

## History 

|日付|内容|
|:---:|:---:|
|2026/04/18| Lagrange 補完に関するメソッドの実装 |
