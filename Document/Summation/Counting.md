---
title: 条件を満たす整数の組の計上
documentation_of: //Summation/Counting.hpp
---

## Outline

条件を満たす整数の組 $(x, y)$ の数を求める.

## Theory

### count_between_lines (1 つ)

以下を満たす整数の組 $(x, y)$ の数を求める.

* $ax+b \leq y \leq cx+d$.
* $l \leq x \leq r$.

$l \leq x \leq r$ である $x$ を固定する. このとき, 条件を満たす $y$ の数は

$$ \begin{cases} (cx+d)-(ax+b)+1 & (ax+b \leq cx+d) \\ 0 & (ax+b \gt cx+d) \end{cases} = \operatorname{relu}((c-a)x+(d-b+1))$$

となる. 従って, $x$ を走らせることにより, 求めるべき個数は

$$ \sum_{x=l}^r \operatorname{relu}((c-a)x+(d-b+1)) $$

である. よって, `relu_linear` を利用して求められる.

### count_between_lines (2 つ)

以下を満たす整数の組 $(x, y)$ の数を求める.

* $ax+b \leq y \leq cx+d$.
* $ex+f \leq y \leq gx+h$.
* $l \leq x \leq r$.

各 $x$ に対して, 条件を満たす $y$ の個数は

$$\begin{align*}
\max(0, \min(cx + d, gx + h) - \max(ax + b, ex + f) + 1)
&= \max(0, \min(
    (c - a)x + (d - b + 1),
    (c - e)x + (d - f + 1),
    (g - a)x + (h - b + 1),
    (g - e)x + (h - f + 1)))
\end{align*}$$

と分割できる.

よって, これら 4 つの直線の最小値 (ただし負なら0) の和を求める問題に帰着される.

従って, それぞれの直線について最小値を担う区間を計算し, その区間内における $\operatorname{relu}$ に関する総和を求めれば良い.

### count_sum_eq, count_sum_range

以下を満たす整数の組 $(x, y)$ の数を求める.

* $p \leq x \leq q$.
* $r \leq y \leq s$.
* $a \leq x + y \leq b$.

この条件式を変形すると,

* $-x+a \leq y \leq -x+b$.
* $r \leq y \leq s$.
* $p \leq x \leq q$.

と変形できる. よって, `count_between_lines` に帰着できる.

また, 以下を満たす整数の組 $(x, y)$ の数は上での問題における $a = b = k$ とした特別バージョンである.

* $p \leq x \leq q$.
* $r \leq y \leq s$.
* $x + y = k$.

### count_diff_eq, count_diff_range

以下を満たす整数の組 $(x, y)$ の数を求める.

* $p \leq x \leq q$.
* $r \leq y \leq s$.
* $a \leq x - y \leq b$.

$y = -z$ と変数変換すると,

* $p \leq x \leq q$.
* $-s \leq z \leq -r$.
* $a \leq x + z \leq b$.

となり, `count_sum_range` に帰着できる.

## Contents

### count_between_lines

```cpp
template<typename T>
T count_between_lines(T a, T b, T c, T d, T l, T r)
```

* 以下を満たす整数の組 $(x, y)$ の数を求める.
  * $ax+b \leq cx+d$.
  * $l \leq x \leq r$.

```cpp
template<typename T>
T count_between_lines(T a, T b, T c, T d, T e, T f, T g, T h, T l, T r)
```

* 以下を満たす整数の組 $(x, y)$ の数を求める.
  * $ax+b \leq cx+d$.
  * $ex+f \leq gx+h$.
  * $l \leq x \leq r$.

### count_sum_eq

```cpp
template<typename T>
T count_sum_eq(T p, T q, T r, T s, T k)
```

* 以下を満たす整数の組 $(x, y)$ の数を求める.
  * $p \leq x \leq q$.
  * $r \leq y \leq s$.
  * $x + y = k$.

### count_sum_range

```cpp
template<typename T>
T count_sum_eq(T p, T q, T r, T s, T a, T b)
```

* 以下を満たす整数の組 $(x, y)$ の数を求める.
  * $p \leq x \leq q$.
  * $r \leq y \leq s$.
  * $a \leq x + y \leq b$.

### count_diff_eq

```cpp
template<typename T>
T count_diff_eq(T p, T q, T r, T s, T k)
```

* 以下を満たす整数の組 $(x, y)$ の数を求める.
  * $p \leq x \leq q$.
  * $r \leq y \leq s$.
  * $x - y = k$.

### count_diff_range

```cpp
template<typename T>
T count_diff_eq(T p, T q, T r, T s, T a, T b)
```

* 以下を満たす整数の組 $(x, y)$ の数を求める.
  * $p \leq x \leq q$.
  * $r \leq y \leq s$.
  * $a \leq x - y \leq b$.
