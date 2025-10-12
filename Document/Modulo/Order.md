---
title: 剰余類の指数
documentation_of: //Modulo/Order.hpp
---

## Outline

$X \in \mathbb{Z}/M \mathbb{Z}$ に対して, $X$ の位数を求める.

## Theory

$X \in \mathbb{Z}/M \mathbb{Z}$ の位数とは, $ X^K = 1 $ を満たす最小の正の整数 $K$ として定義される.

位数が存在することに関する以下の命題を証明する.

> $X \in \mathbb{Z}/M \mathbb{Z}$ に対して, 以下は同値である.
> * (a) $X^K = 1$ となる正の整数 $K$ が存在する.
> * (b) $X$ は可逆である.

### 証明

* (a) ならば (b)

$K$ は正の整数であるので, $K - 1 \geq 0$ である. よって, $X \cdot X^{K-1} = 1$ であるため, $X$ は可逆である.

* (b) ならば (a)

$M$ 個の値 $X^0, X^1, X^2, \dots, X^M$ について, 鳩ノ巣原理により, $X^a = X^b$ となる整数 $a, b ~(0 \leq a \lt b \leq M)$ が存在する.

$X$ は可逆であるため, $X^{b-a}=1$ である. $b-a \gt 0$ であるため, $X^K=1$ となる正の整数 $K$ が存在する.

$\square$

これ以降, $X$ が可逆であるとして, $X$ の位数を求める.

$\mathbb{Z}/M \mathbb{Z}$ における可逆元からなる集合 $G := (\mathbb{Z}/M \mathbb{Z})^\times$ は積を演算として群になる. 特に, $X \in G$ である.

群論の知識により, 以下が従う.

* $G$ の位数は $\varphi(M)$ である.
* $\operatorname{ord}_G(X) = \\# \left \langle X \right \rangle$ である. なお, $\left \langle X \right \rangle$ とは, $X$ によって生成される $G$ の部分群である.
* $\left \langle X \right \rangle$ は $G$ の部分群であるので, Lagrange の定理から, $\\# \left \langle X \right \rangle$ は $\\# G$ の約数である.

以上から, $\operatorname{ord}_G(X)$ は $\varphi(M)$ の約数である.

ボトルネックとなるパートの計算量は以下である.

* $\varphi(M)$ の計算: $O \left(\sqrt{M} \right)$ 時間.
* $\varphi(M)$ の約数列挙: $O \left(\sqrt{\varphi(M)} \right)$ 時間.
* $\varphi(M)$ の各約数 $k$ に対して, $X^k$ の計算に $O(\log M)$ 時間かかる

よって, 位数の存在判定と最小値を求めるための計算量は $M$ の約数の個数を $d(M)$ として, $O\left(\sqrt{M} + d(M) \log M \right)$ 時間である.

## Contents

```cpp
ll Order(const Modulo &X, ll irreversible = -1)
```
* $X \in \mathbb{Z}/M \mathbb{Z}$ の位数を求める. $X$ が非可逆の場合, 返り値は `irreversible` となる.
* **計算量** : $O\left(\sqrt{M} + d(M) \log M \right)$ 時間.
