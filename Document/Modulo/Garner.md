---
title: Garner
documentation_of: //Modulo/Garner.hpp
---

## Outline

Garner のアルゴリズムを用いて, 連立合同式

$$ x \equiv a_1 \pmod{m_1}, \quad \dots, \quad x \equiv a_n \pmod{m_n} $$

を満たす最小の非負整数 $x$ を $R$ で割った余りを求める.

## Theory

### Garner アルゴリズム

$m_1, \dots, m_n$ はどの $2$ つも互いに素とする. このとき,

$$ x \equiv a_1 \pmod{m_1}, \quad \dots, \quad x \equiv a_n \pmod{m_n} \quad \cdots \cdots (*) $$

を満たす非負整数 $x$ は $0$ 以上 $m_1 \dots m_n$ 未満の中にただ一つ存在する.

また, これは $x$ の表現として,

$$ x = t_1 + m_1 t_2 + \dots + m_1 \dots m_{n-1} t_n \quad (0 \leq t_i < m_i) $$

を満たす非負整数列 $t = (t_1, \dots, t_n)$ と利用することができる.

$i = 1, 2, \dots, n$ の順に $t_i$ を求めていく. $(*)$ を $m_i$ で割った余りを考えることにより,

$$ t_1 + m_1 t_2 + \dots + m_1 \dots m_{i-2} t_{i-1} + m_1 \dots m_{i-1} t_i \equiv a_i \pmod{m_i} $$

となる. $m_1 \dots m_{i-1}$ は $m_i$ と互いに素なので,

$$ t_i \equiv \left(a_i - (t_1 + m_1 t_2 + \dots + m_1 \dots m_{i-2} t_{i-1}) \right) \left(m_1 \dots m_{i-1} \right)^{-1} \pmod{m_i}$$

となる.

これによって, $t_1, t_2, \dots, t_n$ を特定できる.

よって, 解が

$$ x \equiv t_1 + m_1 t_2 + \dots + m_1 \dots m_{n-1} t_n \pmod{m_1 \dots m_n} $$

となるため, これを満たす最小の非負整数 $x_0$ は

$$x_0 = t_1 + m_1 t_2 + \dots + m_1 \dots m_{n-1} t_n $$

である.

### 互いに素でないときの処理

$m_1, \dots, m_n$ が互いに素でないとする. 2 つの連立合同方程式

$$ x \equiv a_1 \pmod{m_1}, \quad x \equiv a_2 \pmod{m_2} $$

を互いに素である $m'_1, m'_2$ を用いた同値な連立合同方程式

$$ x \equiv b_1 \pmod{m'_1}, \quad x \equiv b_2 \pmod{m'_2} $$

に変換する.

共通の素因数 $p$ に対して, $m_1, m_2$ の $p$ における指数を $e, f$ とする. $e \leq f$ としても一般性を失わない.

このとき, $b_1 \equiv b_2 \pmod{p^e}$ を満たさないならば, この連立方程式は解無しになる.

$b_1 \equiv b_2 \pmod{p^e}$ であるとき,

$$ x \equiv a_1 \pmod{m_1} \quad \to \quad x \equiv a_1 \pmod{\frac{m_1}{p^e}}$$

と変換すると, $\frac{m_1}{p^e}, m_2$ は互いに素になる.

これを全てのペアに対して計算することにより, $(m_1, \dots, m_n)$ がどの $2$ つも互いに素な場合に帰着できる.

## Contents

### Garner_Base

```cpp
vector<ll> Garner_Base(const vector<Modulo> &X)
```

* $X$ に含まれる法は, どの $2$ つも互いに素であるとする. このとき, 以下を満たす $(t_0, t_1, \dots, t_{n-1})$ を求める.

$$ x \equiv t_0 + m_0 t_1 + \dots + m_0 \dots m_{n-2} t_{n-1} \pmod{m_0 \dots m_{n-1}} $$

* **計算量**: $O(n^2 + n \log \max(m_0, \dots, m_{n-1}))$ 時間.

### First_Garner

```cpp
optional<ll> First_Garner(vector<Modulo> X, const ll R, bool positive = false)
```

* $X$ を全て満たす非負整数 $x_0$ を $R$ で割った余りを求める.
* **引数**
    * `positive`: `true` にすると, 非負整数が正の整数になる.
* **計算量**: $O(n^2 + n \sqrt{\max(m_0, \dots, m_{n-1})})$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/03/15| Garner のアルゴリズム実装 |
