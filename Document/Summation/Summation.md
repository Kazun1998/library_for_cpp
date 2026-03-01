---
title: 特殊な数列の総和
documentation_of: //Summation/Summation.hpp
---

## Outline

特別な数列に対する総和を求める.

## Theory

### linear

$\displaystyle \sum_{k=l}^r (ak+b)$ は等差数列の総和なので,

$$ \sum_{k=l}^r (ak+b) = \dfrac{((al+b)+(ar+b))(r-l+1)}{2} = \dfrac{(a(l+r)+2b)(r-l+1)}{2}$$

である.

### relu_linear

$\operatorname{relu}(x) := \max(x, 0)$ とする. このときの $\displaystyle \sum_{k=l}^r \operatorname{relu}(ak+b)$ を求める.

$a = 0$ のときは自明, $a < 0$ のときは, 

$$\sum_{k=l}^r \operatorname{relu}(ak+b) = \sum_{k'=l}^r \operatorname{relu}(a (r+l-k')+b) = \sum_{k'=l}^r \operatorname{relu}(-ak'+a(r+l)+b) $$

という式変形を行うことにより, $a > 0$ の場合のみを考えれば良いことがわかる.

$a > 0$ のとき, 整数 $k$ に対して,

$$ ak+b \geq 0 \iff k \geq \left \lceil \dfrac{-b}{a} \right \rceil$$

である. $t := \max\left(l, \left \lceil \dfrac{-b}{a} \right \rceil \right)$ とおくことで, 総和の対象は $t$ 以上のみが有効になるため,

$$ \sum_{k=l}^r \operatorname{relu}(ak+b) = \sum_{k = l}^{t-1} 0 + \sum_{k = t}^r (ak+b) $$

となる.

### max_linear

$\displaystyle \sum_{k=l}^r \max(ak+b, ck+d)$ を求める. 実数 $x, y \in \mathbb{R}$ に対して,

$$ \max(x, y) = \max(x - y, 0) + y = \operatorname{relu}(x - y) + y $$

であるため,

$$ \begin{align*}
\sum_{k=l}^r \max(ak+b, ck+d)
&= \sum_{k=l}^r \left(\operatorname{relu}((ak+b) - (ck+d)) + (ck+d) \right) \\
&= \sum_{k=l}^r \left(\operatorname{relu}((a-c)k+(b-d)) + (ck+d) \right) \\
&= \sum_{k=l}^r \operatorname{relu}((a-c)k+(b-d)) + \sum_{k=l}^r (ck+d) \\
\end{align*}$$

となる.

### min_linear

$\displaystyle \sum_{k=l}^r \min(ak+b, ck+d)$ を求める. 実数 $x, y \in \mathbb{R}$ に対して,

$$ \min(x, y) = \min(x - y, 0) + y = -\max(x - y, 0) + y = -\operatorname{relu}(-(x-y)) + y $$

である. よって, max_linear と同様にして,

$$ \sum_{k=l}^r \min(ak+b, ck+d) = -\sum_{k=l}^r \operatorname{relu}(-(a-c)k-(b-d)) + \sum_{k=l}^r (ck+d) $$

で求められる.

### sum_lower_cut_linear, sum_upper_cut_linear

$\displaystyle \sum_{k=l}^r \max(ak+b, d), \sum_{k=l}^r \min(ak+b, u)$ はそれぞれ max_linear, min_linear における $c = 0$ の特殊バージョンである.

### abs_linear

$\displaystyle \sum_{k=l}^r \lvert ak+b \rvert$ を求める. 任意の実数 $x \in \mathbb{R}$ に対して,

$$ \lvert x \rvert = \max(x, -x) $$

であるため,

$$ \sum_{k=l}^r \lvert ak+b \rvert = \sum_{k=l}^r \max(ak+b, -ak-b) $$

で求められる.

### clamp_linear

$d, u \in \mathbb{R}$ は $d \leq u$ であるとする. $x \in \mathbb{R}$ に対して, $\operatorname{clamp}(x)$ を

$$\operatorname{clamp}(x) := \begin{cases} d & (x \lt d) \\ x & (d \leq x \leq u) \\ u & (x \gt u) \end{cases}$$

で定義する. ここで,

$$ \operatorname{clamp}(x) = \max(d, \min(x, u)) $$

が成り立つ. このとき, 

$$ \operatorname{clamp}(x) = x - \operatorname{relu}(x-u) + \operatorname{relu}(d-x) $$

が成り立つ. これを証明する.

$$\begin{align*}
x - \operatorname{relu}(x-u) + \operatorname{relu}(d-x)
&= x + \max(d-x, 0) - \operatorname{relu}(x-u)\\
&= \max(d, x) - \operatorname{relu}(x-u) \cdots (*)
\end{align*}$$

である.

#### $x < u$ のとき

* $\operatorname{relu}(x-u) = 0$.
* $x = \min(x, u)$.

であるため,

$$\begin{align*}
(*)
&= \max(d, x) - \operatorname{relu}(x-u) \\
&= \max(d, x) \\
&= \max(d, \min(x, u)) \\
&= \operatorname{clamp}(x)
\end{align*}$$

となる.

#### $x \geq u$ のとき

* $\operatorname{relu}(x-u) = x-u$.
* $d-(x-u) \geq d \leq u$.
* $u = \min(x, u)$.


であるため,

$$\begin{align*}
(*)
&= \max(d, x) - \operatorname{relu}(x-u) \\
&= \max(d, x) - (x-u)\\
&= \max(d - (x - u), u) \\
&= u \\
&= \max(d, u) \\
&= \max(d, \min(x, u)) \\
&= \operatorname{clamp}(x)
\end{align*}$$

となる.

よって,

$$ \operatorname{clamp}(x) = x - \operatorname{relu}(x-u) + \operatorname{relu}(d-x) $$

であるため, 右辺についてそれぞれ総和を取ることで総和を計算できる.

### sum_sq

$$ \sum_{k=0}^n k^2 = \dfrac{n(n+1)(2n+1)}{6} $$

である.

### square_linear

$\displaystyle \sum_{k=l}^r (ak+b)^2$ はこの後説明する `sum_product_linear` における $c = a, d = b$ の特別パターンである.

### sum_product_linear

$\displaystyle \sum_{k=l}^r (ak+b)(ck+d)$ は

$$ (ak+b)(ck+d) = ack^2 + (ad+bc) k + bd $$

であるため,

$$ \sum_{k=l}^r (ak+b)(ck+d) = ac \sum_{k=l}^r k^2 + \sum_{k=l}^r ((ac+bd)k + bd) $$

で求められる.

### product_relu_linear

$\displaystyle \sum_{k=l}^r \operatorname{relu}(ak+b) \operatorname{relu}(ck+d)$ を求める. $a, c$ の符号に注意して, $ak+b, ck+d$ が共に正になる $k$ の範囲を求める (そのような $k$ が存在するならば, その範囲は区間になる).

この範囲の中では, `sum_product_linear` で求められる.

## Contents

### linear

```cpp
template<typename T>
T linear(T a, T b, T l, T r)
```

* $\displaystyle \sum_{k=l}^r (ak+b)$ を求める.

### relu_linear

```cpp
template<typename T>
T relu_linear(T a, T b, T l, T r)
```

* $\displaystyle \sum_{k=l}^r \operatorname{relu}(ak+b)$ を求める.

### max_linear

```cpp
template<typename T>
T max_linear(T a, T b, T c, T d, T l, T r)
```

* $\displaystyle \sum_{k=l}^r \max(ak+b, ck+d)$ を求める.

```cpp
template<typename T>
T max_linear(T a, T b, T d, T l, T r)
```

* $\displaystyle \sum_{k=l}^r \max(ak+b, d)$ を求める.

### min_linear

```cpp
template<typename T>
T min_linear(T a, T b, T c, T d, T l, T r)
```

* $\displaystyle \sum_{k=l}^r \min(ak+b, ck+d)$ を求める.

```cpp
template<typename T>
T min_linear(T a, T b, T d, T l, T r)
```

* $\displaystyle \sum_{k=l}^r \min(ak+b, d)$ を求める.

### min_linear

```cpp
template<typename T>
T abs_linear(T a, T b, T l, T r)
```

* $\displaystyle \sum_{k=l}^r \lvert ak+b \rvert$ を求める.

### clamp_linear

```cpp
template<typename T>
T clamp_linear(T a, T b, T d, T u, T l, T r)
```

* 下側を $d$, 上側を $u$ とした $\displaystyle \sum_{k=l}^r \operatorname{clamp}(x)$ を求める.

### sum_sq

```cpp
template<typename T>
T sum_sq(T n)
```

* $\displaystyle \sum_{k=0}^n k^2$ を求める.

### square_linear

```cpp
template<typename T>
T square_linear(T a, T b, T l, T r)
```

* $\displaystyle \sum_{k=0}^n (ak+b)^2$ を求める.

### sum_product_linear

```cpp
template<typename T>
T sum_product_linear(T a, T b, T c, T d, T l, T r)
```

* $\displaystyle \sum_{k=0}^n (ak+b)(ck+d)$ を求める.

### product_relu_linear

```cpp
template<typename T>
T product_relu_linear(T a, T b, T c, T d, T l, T r)
```

* $\displaystyle \sum_{k=0}^n \operatorname{relu}(ak+b) \operatorname{relu}(ck+d)$ を求める.

## History

|日付|内容|
|:---:|:---:|
|2026/03/01| Summation 系のメソッドの実装 |

