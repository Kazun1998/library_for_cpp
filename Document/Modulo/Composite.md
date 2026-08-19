---
title: 剰余類の合成
documentation_of: //Modulo/Composite.hpp
---

## Outline

$2$ つの剰余類 $a + m \mathbb{Z}, b + n \mathbb{Z}$ の共通部分を求める.

即ち, 整数 $a, b$ と正の整数 $m, n$ に対して, $x$ の連立合同方程式

$$ \begin{cases} x \equiv a \pmod{m} \\ x \equiv b \pmod{n} \end{cases}$$

を解く.

## Theory

### 合同方程式

$x \equiv a \pmod{m}$ であることと, 整数 $p$ が存在して,

$$ x = a + mp $$

となることが同値である.

どうようにして, 整数 $q$ が存在して,

$$ x = b + n(-q) $$

となる (後の議論の関係から, $-q$ としている).

よって,

$$ a + mp = b + n(-q) $$

である. 式を整理して,

$$ mp + nq = b - a $$

である.

このとき, $g := \gcd(m, n)$ としたとき, 整数解 $(p, q) = (p_0, q_0)$ が存在することと, $b-a$ が $g$ の倍数であること, 即ち

$$ a \equiv b \pmod{g} $$

であることが同値である.

$m, n, b-a$ をそれぞれ $g$ でわった商を $m', n', c'$ とする.

即ち,

$$ m'p + n'q = c' \quad \cdots (1) $$

となる.

このとき, $m', n'$ は互いに素なので,

$$ m'p_0 + n'q_0 = 1 \quad \cdots (2) $$

である.

(2) 式を $c'$ 倍して, (1) 式から引くと,

$$ m' (p - c' p_0) + n' (q - c' q_0) = 0 \quad \cdots (3) $$


である.

$m', n'$ は互いに素なので, $p - c' p_0$ は $n'$ の倍数である. 故に, ある整数 $k$ が存在して,

$$ p - c'p_0 = n'k \iff p = c'p_0 + n'k $$

である. これを (3) 式に代入することで,

$$ q = c'q_0 - m'k $$

を得る.

よって,

$$ (p, q) = (c'p_0 + n'k, c'q_0 - m'k) \quad (k \in \mathbb{Z}) $$

である.

逆に, $(p, q)$ がこのように表されるとき, (1) 式の解になる.


よって,

$$ x = a + mp = a + m(c'p_0 + n'k) = (a + mc'p_0) + n'mk = a + mc'p_0 + \operatorname{lcm}(m, n) k $$

であるので, 連立合同方程式の解は

$$ x \equiv a + mc'p_0 \pmod{\operatorname{lcm}(m, n)} $$

である.

## Contents

### Composite

#### 2 要素版
```cpp
Modulo Composite(Modulo A, Modulo B)
```

* 剰余類 $A, B$ の共通部分を求める.
* 解が存在しない場合: 例外 `IncompatibleModuloComposite` を送出する.
* **計算量**: $A, B$ の法を $m, n$ としたとき, $O(\log(\min(m, n)))$ 時間.


#### 任意個要素版

```cpp
Modulo Composite()
```

* 引数無しの場合, 恒等的に成り立つ剰余類 $\mathbb{Z} = 0 + 1\mathbb{Z}$ を返す.

```cpp
Modulo Composite(const T& first, const Args&... rest)
```

* $3$ つ以上の `Modulo` を可変長引数として受け取り, それらすべてを満たす合同式を先頭から順に合成して返す.
* 途中で合成できない組が現れた場合, 例外 `IncompatibleModuloComposite` を送出する.

```cpp
Modulo Composite(vector<Modulo> As)
```

* `Modulo` の列 `As` を先頭から順に合成し, それらの共通部分の剰余類を求める.
* 途中で合成できない組が現れた場合, 例外 `IncompatibleModuloComposite` を送出する.
* **計算量**: $n$ を剰余類の数, $i$ 番目の剰余類における法を $m_i$ として, $O(n \log \max(m_0, \dots, m_{n-1}))$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/08/19| document 作成 |
|2025/08/22| Solve 系関数作成 |
