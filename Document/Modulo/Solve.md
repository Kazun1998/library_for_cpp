---
title: 合同方程式
documentation_of: //Modulo/Solve.hpp
---

## Outline

整数 $a, b$ と正の整数 $m$ に対して, $x$ の方程式

$$ ax \equiv b \pmod{m} $$

を解く.

## Theory

### 合同方程式

$g := \gcd(a, m)$ とする.

このとき, 任意の整数 $x$ に対して, $ax$ を $m$ で割った余りは必ず $g$ の倍数になる. そのため, $b$ が $g$ の倍数であることが必要である. この必要条件を満たさないならば, この方程式は解なしになる.

これ以降, $b$ は $g$ の倍数であるとする.

$a, b, m$ をそれぞれ $g$ で割った $a', b', m'$ について,

$$ ax \equiv b \pmod{m} \iff a'x \equiv b' \pmod{m'} $$

が成り立つ.

$a', m'$ は互いに素なので, $a'$ は $\pmod{m'}$ 上で可逆である. その可逆元を $(a')^{-1}$ と書くことにすると,

$$ a'x \equiv b' \pmod{m'} \iff x \equiv (a')^{-1} b' \pmod{m'} $$

である.

よって,

$$ ax \equiv b \pmod{m} \iff x \equiv (a')^{-1} b' \pmod{m'} $$

となる.

この解法におけるボトルネックは $g$ を求める部分と $(a')^{-1}$ を求める部分であるが, どちらも (拡張) Euclid の互除法を使うことにより, $O(\log m)$ 時間で求められる.

### 連立合同方程式

連立合同方程式

$$ a_i x \equiv b_i \pmod{m_i} \quad (i = 1, \dots, k) $$

を解く.

まず各 $i$ について, 方程式

$$ a_i x \equiv b_i \pmod{m_i} $$

を解き,

$$ x \equiv c_i \pmod{m_i'} $$

の形に変形する.

すると, [剰余類の合成](Composite.hpp) を使うことができるため, 合成によって連立合同方程式の解を

$$ x \equiv c \pmod{m}$$

の形で表すことができる.

ただし, もとの方程式に $1$ つでも解なしがあるならば, 連立系も解なしになる.

また, それぞれの方程式において解があったとしても, $m_1', \dots, m_k'$ が互いに素とは限らないため, 合成の際に法どうしが両立しない (矛盾する) 場合は解なしとなる.

## Contents

### Solve_Congruence_Equation

```cpp
Modulo Solve_Congruence_Equation(ll a, ll b, ll m)
```

* 線形合同方程式 $ax \equiv b \pmod{m}$ を解き, 解を `Modulo` 型として返す.
* **例外**
    * 解が存在しない場合, `NoSolutionException` を送出する.
    * $m = 0$ の場合, 例外を送出する.
* **計算量**: $O(\log m)$ 時間.

### Solve_System_of_Congruence_Equations

```cpp
Modulo Solve_System_of_Congruence_Equations(vector<tuple<ll, ll, ll>> equations)
```

* $(a_i, b_i, m_i)$ の列 `equations` に対して, 連立線形合同方程式

$$ a_i x \equiv b_i \pmod{m_i} \quad (i = 1, \dots, k) $$

  を解き, 解を `Modulo` 型として返す.
* **例外**
  * 連立線形合同方程式の解が存在しないとき, 例外を送出する.
* **計算量**: $k$ を `equations` の要素数, $M := \max(m_1, \dots, m_k)$ として, $O(k \log M)$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/08/19| document 作成 |
|2025/08/22| Solve 系関数作成 |
