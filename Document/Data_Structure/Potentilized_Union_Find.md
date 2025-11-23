---
title: ポテンシャル付き Union Find
documentation_of: //Union_Find/Potentilized_Union_Find.hpp
---

## Outline

Union Find にポテンシャルの概念を付け加え, $2$ 頂点間のポテンシャルの差を取得する.

## Define

$G$ を群とする.

各弧に $G$ の重みが付いた有向グラフ $D = (V, A, W: V \to G)$ において, 以下をみたす時, この $D$ は対称的であるという.

* 任意の $a \in A$ に対して, 以下をみたす逆弧 $\operatorname{rev}: A \to A$ が定まっている.
  * $\operatorname{rev}(a)$ は $a$ の逆向きである. つまり, 以下を満たす.
    * $s(a) = t(\operatorname{rev}(a))$.
    * $t(a) = s(\operatorname{rev}(a))$.
  * $\operatorname{rev}$ は対合である. つまり, 任意の $a \in A$ に対して, $\operatorname{rev}(\operatorname{rev}(a)) = a$ となる.
* 任意の $a \in A$ に対して, $W(\operatorname{rev}(a)) = W(a)^{-1}$ である.

---

各弧に $G$ の重みが付いた有向グラフ $D = (V, A, W: V \to G)$ 上のパス $p = (v_0, v_1, v_2, \dots, v_m)$ に対して, $p$ のポテンシャルエネルギー $E(p)$ を

$$ E(p) := \sum_{j=1}^m W\left(\overrightarrow{v_{j-1} v_j} \right)$$

で定義する.

---

対称的な各弧に $G$ の重みが付いた有向グラフ $D = (V, A, W: V \to G)$ について, 以下の条件をみたす時, $D$ はポテンシャルを持つという.

* 任意の $u, v\in V$ に対して, $u$ を始点, $v$ を終点とするパスにおけるポテンシャルエネルギーはパスに依らない.
* つまり, $p, q$ を $u$ を始点, $v$ を終点とするパスとしたとき, $E(p) = E(q)$ が成り立つ.

---

$D$ はポテンシャルを持つとする.

$$ R := \{(u, v) \in V^2 \mid v \text{ is reachable from } u \text{ on } D. \}$$

とする. このとき, $D$ におけるポテンシャル $P: R \to G$ を $u$ を始点, $v$ を終点とするパスを $p$ としたとき, $P(u, v) := E(p)$ とする. $D$ がポテンシャルを持つことから, Well-Defined 性が従う.

## Theory

対称的な各弧に $G$ の重みが付いた有向グラフ $D = (V, A, W: V \to G)$ について, 以下は同値になる.

* (a) $D$ はポテンシャルを持つ.
* (b) 任意の $D$ 上のサイクルに対するポテンシャルエネルギーは単位元である.
