---
title: Montmort 数
documentation_of: //Math/Montmort_Number.hpp
---

## Outline

攪乱順列の数を求める.

## Define

$\{1, 2, \dots, n\}$ の順列全体の集合を $\mathfrak{S}_n$ とする.

$\sigma \in \mathfrak{S}_n$ が攪乱順列であるとは, 以下を満たすことである.

* $i=1,2,\dots,n$ に対して, $\sigma(i) \neq i$ を満たす.

$n$ 要素順列における攪乱順列の数を $m_n$ としたとき, $(m_n)$ を Montmort 数という.

## Theory

Montmort 数の漸化式を考える.

$a_0 = 1, a_1 = 1$ をベースケースとする.

$n \geq 2$ とする. $\sigma \in \mathfrak{S}_n$ に対して, $\sigma(\sigma(1))$ の値で場合分けをする. なお, $k := \sigma(1)$ とする.

### $\sigma(\sigma(1)) = 1$ のとき

$\sigma(1), \sigma(k)$ が確定している. 残りの $(n-2)$ 個の $\sigma(j)~(1 \leq j \leq n, j \neq 1,k)$ に対して, $\sigma(j) = j$ の条件が課される.

よって, この場合分けの条件を満たす $\sigma \in \mathfrak{S}_n$ の数は $m_{n-2}$ である.


### $\sigma(\sigma(1)) \neq 1$ のとき

$\sigma(k) \neq 1$ である. $\sigma(j)~(1 \leq j \leq n, j \neq 1)$ についての要素が決まっていないが, 以下のようになっている.

* $\sigma(j)~(1 \leq j \leq n, j \neq 1)$ は $(1, 2, \dots, k-1, k+1, \dots, n)$ の並び替え.
* 以下の禁止条件がある.
  * $j \neq k$ のときは, $\sigma(j) \neq j$ である.
  * $j = k$ のときは $\sigma(j) \neq 1$ である.

禁止条件の右辺における値は $j \neq 1$ より, 互いに交わらない. よって, $(n-1)$ 要素の攪乱順列の条件とみなすことができる.

よって, この場合分けの条件を満たす $\sigma \in \mathfrak{S}_n$ の数は $m_{n-1}$ である.

以上から, $\sigma(1)=k$ を満たす攪乱順列の数は $m_{n-1}+m_{n-2}$ である.

これが $k = 2, 3, \dots, n$ の $(n-1)$ 個の値について考えられる.

よって,

$$ m_n = (n-1)(m_{n-1}+m_{n-2}) \quad (n \geq 2)$$

を満たす.

この漸化式を変形させる. $n \geq 2$ のとき

$$\begin{align*}
    m_n - m a_{n-1}
    &= (n-1)(m_{n-1}+m_{n-2}) - n m_{n-1} \\
    &= -(m_{n-1}+(n-1)m_{n-2})
\end{align*}$$

となる. よって, 

$$\begin{align*}
    m_n - n m_{n-1}
    &= -(m_{n-1}+(n-1) m_{n-2}) \\
    &= (-1)^2 (m_{n-2} + (n-2) m_{n-3}) \\
    &= \vdots \\
    &= (-1)^{n-1} (m_1-m_0) \\
    &= (-1)^{n-1} (0-1) \\
    &= (-1)^n
\end{align*}$$

である. また, この関係式の結論は $n = 1$ でも成立する, $(m_n)$ は二項間漸化式

$$ m_n = \begin{cases} 1 & (n = 0) \\ n m_{n-1} + (-1)^n & (n \geq 1) \end{cases} $$

を満たす.

### Contents

```cpp
vector<Modulo>Montmort_Number(int N, const ll M)
```

* Montmort 数 $m_0, m_1, \dots, m_N$ をそれぞれ $M$ で割った余りを求める.

