---
title: 添字が半束である畳み込み
documentation_of: //Convolution/Semilattice_Convolution_Base.hpp
---

## Define

代数系 $(I, \circ)$ が以下を満たす時, この代数系は半束であるという.

* (冪等律) 任意の $i \in I$ に対して, $i \circ i = i$.
* (交換律) 任意の $i, j \in I$ に対して, $i \circ j = j \circ i$.
* (結合律) 任意の $i, j, k \in I$ に対して, $(i \circ j) \circ k = i \circ (j \circ k)$.

順序集合 $(I, \leq)$ が以下を満たす時, この順序集合は (結び) 半束であるという.

* 任意の $a, b \in I$ に対して, 上界 $\sup \\{ a, b \\}$ が一意に存在する.

ここで, 半束 $(I, \circ)$ が与えられているとき, 以下のようにして $I$ 上の二項関係 $\leq$ を定めると, $(I, \leq)$ は結び半束になる.

* $i, j \in I$ に対して, $i \leq j \iff i \circ j = j$.

逆に, 結び半束 $(I, \leq)$ に対して, $i \circ j := \sup \\{ i, j \\}$ とすると, $(I, \circ)$ は半束になる.

これ以降, 半束には, 代数的構造と順序的構造の兼ね備えているとする.

## Theory

次で定める Zeta 変換 $\zeta: (R[I], *) \to (R[I], \cdot)$ を定義する. ただし, $(R[I], \cdot)$ とは, 積を各点毎でとる環である.

$$ (\zeta f)(p) := \sum_{i \leq p} f(i) $$

この Zeta 変換は実は環同型写像になる. 従って, $f, g \in R[I]$ に対して, 以下が従う.

$$ \zeta(f * g) = (\zeta f) \cdot (\zeta g) $$

$\zeta$ は同型であるため, 逆写像 $\mu: (R[I], \cdot) \to (R[I], *)$ が存在する. この $\mu$ も同型写像である.

なお, この $\mu$ は (記号の乱用にはなるが) $\mu: I^2 \to R$ を任意の $i, j \in I$ で

$$ \sum_{i \leq p \leq j} \mu(i, p) \zeta(p, j) = \delta_{i, j} $$

となるようにする (一意に定まる).

この $\mu$ を使って,

$$ (\mu h)(i) = \sum_{p \leq i} h(p) \mu(p, i) $$

になる.
