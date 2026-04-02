---
title: Nimber
documentation_of: //Algebra/Nimber.hpp
---

## Outline

組み合わせゲーム理論において用いられる Nim から導入された Nimber の計算を行う.

## Theory

非負整数 $n$ に対して,

$$F_n := \{0, 1, \dots, 2^n - 1 \}$$

とする.

### 加法

$F_n$ 上の演算 $\oplus: F_n \times F_n \to F_n$ を

$$x \oplus y := \mathrm{mex} \left(\{ a \oplus y \mid 0 \leq a < x \} \cup \{ x \oplus b \mid 0 \leq b < y \} \right)$$

によって帰納的に定める. ただし, $S \subsetneq \mathbb{N}$ に対して, $S$ の最小除外数 $\mathrm{mex}~S$ を

$$\mathrm{mex}~S := \min (\mathbb{N} \setminus S)$$

で定義する.

すると, $\oplus$ は Bitwise-XOR と一致する.

このことから, 以下が従う.

* $\oplus$ は $F_n$ において可換群になる. 特に, 以下が成り立つ.
  * $x < 2^m < 2^n$ に対して, $x \oplus 2^m = x + 2^m$.
  * 単位元は $0$ である.
  * $x \in F_n$ の逆元は $x$ 自身である.

### 乗法

$F_{2^n}$ 上の演算 $\otimes: F_{2^n} \times F_{2^n} \to F_{2^n}$ を

$$ x \otimes y := \mathrm{mex} \left(\{(a \otimes y) \oplus (x \otimes b) \oplus (a \otimes b) \mid 0 \leq a < x, 0 \leq b < y\} \right)$$

によって帰納的に定める.

このとき, $(F_{2^n}, \oplus, \otimes)$ は $1$ を乗法単位元とする可換体になる.

#### 計算

可換体 $(F_{2^n}, \oplus, \otimes)$ に対して, 以下が成り立つ. ただし, 非負整数 $k~(< n) $ に対して,

$$e_k := 2^{2^k}, \quad e'_k := 2^{2^k - 1} \left(= e_k / 2 \right)$$

とする.

* $x \in F$ に対して, $x < e_k$ ならば, $x \otimes e_k = x \times e_k$ である.
* $e_k \otimes e_k = \frac{3}{2} e_k = e_k + e'_k = e_k \oplus e'_k $.

これらの性質により, $x, y \in F_{2^n}$ に対して, $x \oplus y$ の計算を次のようにして, $F_{2^{n-1}}$ 上の計算に帰着させることができる.

まず, $x,y \in F_{2^n}$ より, $x, y$ はそれぞれ $x_0, x_1, y_0, y_1 \in F_{2^{n-1}}$ を用いて,

$$x = x_1 e_{k-1} + x_0, \quad y = y_1 e_{k-1} + y_0$$

と表せる.

すると,

$$\begin{align*}
    x \otimes y
    &= (x_1 e_{k-1} + x_0) \otimes (y_1 e_{k-1} + y_0) \\
    &= (x_1 e_{k-1} \oplus x_0) \otimes (y_1 e_{k-1} \oplus y_0) \\
    &= (x_1 \otimes e_{k-1} \oplus x_0) \otimes (y_1 \otimes e_{k-1} \oplus y_0) \\
    &= \left((x_1 \otimes y_1) \otimes (e_{k-1} \otimes e_{k-1}) \right) \oplus \left((x_0 \otimes y_1 \oplus x_1 \otimes y_0) \otimes e_{k-1} \right) \oplus (x_0 \otimes y_0) \\
    &= \left((x_1 \otimes y_1) \otimes (e_{k-1} \oplus e'_{k-1}) \right) \oplus \left((x_0 \otimes y_1 \oplus x_1 \otimes y_0) \otimes e_{k-1} \right) \oplus (x_0 \otimes y_0) \\
    &= \left((x_1 \otimes y_1 \oplus x_0 \otimes y_1 \oplus x_1 \otimes y_0) \otimes e_{k-1} \right) \oplus (x_1 \otimes y_1 \otimes e'_{k-1}) \oplus (x_0 \otimes y_0) \\
    &= \left(((x_1 \otimes y_1 \oplus x_0 \otimes y_1 \oplus x_1 \otimes y_0 \oplus x_0 \otimes y_0) \oplus x_0 \otimes y_0) \otimes e_{k-1} \right) \oplus (x_1 \otimes y_1 \otimes e'_{k-1}) \oplus (x_0 \otimes y_0) \\
    &= \left(((x_1 \oplus x_0) \otimes (y_1 \oplus y_0) \oplus (x_0 \otimes y_0)) \otimes e_{k-1} \right) \oplus (x_1 \otimes y_1 \otimes e'_{k-1}) \oplus (x_0 \otimes y_0)\\
    &= \left(((x_1 \oplus x_0) \otimes (y_1 \oplus y_0) \oplus (x_0 \otimes y_0)) \times e_{k-1} \right) \oplus (x_1 \otimes y_1 \otimes e'_{k-1}) \oplus (x_0 \otimes y_0) \\
\end{align*}$$

となり,

$$(x_1 \oplus x_0) \otimes (y_1 \oplus y_0), \quad x_0 \otimes y_0, \quad x_1 \otimes y_1 \otimes e'_{k-1}$$

の $4$ つの "1 レベル下" の積に帰着される.

### 逆元

$x \in F_{2^n}$ は $x \neq 0$ であるとする. Nimber 積の意味での $x$ の $m$ 乗を $\operatorname{power}(x, m)$ と書くことにする.

体における乗法群 $F_{2^n}^\times$ の位数は $(2^{2^n}-1)$ であるため, Lagrange の定理により, $\operatorname{power}(x, 2^{2^n}-1) = 1$ である.

よって, $x$ の Nimber 積の意味での逆元は $\operatorname{power}(x, 2^{2^n}-2)$ である.

### 平方根

まず, 平方根の定義ができることを証明する.

> (定理 1) 任意の $b \in F_{2^n}$ に対して, $a \otimes a = b$ となる $a \in F_{2^n}$ がただ一つ存在する.

(証明)

$x, y \in F_{2^n}$ に対して, $x \otimes x = y \otimes y$ とする. すると, $F_{2^n}$ は位数 $2$ の体であるため, Freshman's Dream により, $(x \oplus y) \otimes (x \oplus y) = 0$ が成り立つ.

$F_{2^n}$ は体であるため, $x \oplus y = 0$ である. つまり, $x = y$ である.

すると, $g: F_{2^n} \to F_{2^n}; x \mapsto x \otimes x$ は定義域と値域が同じ有限集合の $F_{2^n}$ である単射になるため, $g$ は全単射になる.

故に, 任意の $b \in F_{2^n}$ に対して, $g(a) = b$ となる $a \in F_{2^n}$ がただ一つ存在する.

$b \in F_{2^n}$ に対して, $a \otimes a = b$ となる $a \in F_{2^n}$ のことを, $b$ の平方根といい, $\sqrt{b}$ と書く.

#### 計算

$x \in F_{2^n}$ として, $n$ に関して帰納的に求めていく.

$n = 1$ の場合. つまり, $x = 0, 1$ の場合はそれぞれ $\sqrt{0} = 0, \sqrt{1} = 1$ である.

つまり, $x \in F_{2^n}$ とすると, $n \geq 2$ である.

$x = x_1 e_{n-1} + x_0, x_1, x_0 \in F_{2^{n-1}}$ として $x$ を分割することができる.

ここで,

$$ y_1 := \sqrt{x_1}, \quad y_0 := \sqrt{x_1 \otimes e'_{k-1} \oplus x_0}, \quad y := y_1 e_{k-1} + y_0 $$

とする. このとき, $x\_1, x\_1 \otimes e'\_{k-1} \oplus x\_0 \in F\_{2^{n-1}}$ になる.

すると,

$$
\begin{align*}
y \otimes y
&= (y_1 e_{k-1} + y_0) \otimes (y_1 e_{k-1} + y_0) \\
&= (y_1 \otimes e_{k-1} \oplus y_0) \otimes (y_1 \otimes e_{k-1} \oplus y_0) \\
&= (y_1 \otimes y_1) \otimes (e_{k-1} \otimes e_{k-1}) \oplus (y_0 \oplus y_0) \\
&= x_1 \otimes (e_{k-1} \oplus e'_k) \oplus (x_1 \otimes e'_{k-1} \oplus x_0) \\
&= x_1 \otimes e_{k-1} \oplus x_0 \\
&= x
\end{align*}
$$

となる. よって, $y = \sqrt{x}$ である.

## Reference

* https://drive.google.com/file/d/16g1tfSHUU4NXNTDgaD8FSA1WB4FtJCyV/edit
* https://natsugiri.hatenablog.com/entry/2020/03/29/073605

## History

|日付|内容|
|:---:|:---:|
|2026/02/21| sqrt の実装 |
|2026/02/15| Nimber クラスの実装 |
