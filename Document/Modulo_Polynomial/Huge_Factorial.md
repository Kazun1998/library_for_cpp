---
title: 巨大な $N$ に対する $N!$
documentation_of: //Modulo_Polynomial/Huge_Factorial.hpp
---

## Outline

整数 $N$ に対する $N!$ を NTT Friendly である素数 $p$ で割った余りを求める.

## Theory

$N = 0$ のときは, $0! = 1$ である. また, $N \geq p$ のときは, $N!$ の式の中に $p$ を掛ける部分が現れるので, $N! \equiv 0 \pmod{p}$ である.

以降は, $1 \leq N < p$ とする.

$M := \left \lfloor \sqrt{N} \right \rfloor$ とする.

多項式 $P(x)$ を以下で定める.

$$ P(x) := \prod_{i=1}^M (x + i) $$

このとき, $a \in \mathbb{Z}$ に対して,

$$ P(a) = \prod_{k=a+1}^{a+M} k$$

となる. すると,

$$ P(0) P(M) \dots P((t-1) M) = \prod_{k=1}^{tM} k = (tM) ! $$

である.

よって,

$$\begin{align*}
    N!
    &= \prod_{k=1}^N k \\
    &= \left(\prod_{k=1}^{M^2} k \right) \left(\prod_{k=M^2+1}^{N} k \right) \\
    &= P(0) P(M) \dots P((M-1)M) \prod_{k=M^2+1}^{N} k
\end{align*}$$

になる.

* $P(x)$ は掛け合わせる順番を工夫する畳み込みによって, $M$ 次式 $P(x)$ を $O(M (\log M)^2)$ 時間で求められる.
* $P(0), P(M), \dots, P((M-1)M)$ は多点評価によって, $O(M (\log M)^2)$ 時間で求められる.
* $M^2+1 \leq k \leq N$ をみたす整数 $k$ の個数は, $\sqrt{N} - 1 \leq M \leq \sqrt{M}$ を満たすため, $N - M^2 \leq 2 \sqrt{N} - 1 = O(\sqrt{N})$ となる. よって, $\prod_{k=M^2+1}^{N} k$ は $O(\sqrt{N})$ 時間で求められる.

以上から, $N!$ は $O(M (\log M)^2 + \sqrt{N}) = O(\sqrt{N} (\log N)^2)$ 時間で求められる.

## Contents

```cpp
template<typename mint>
mint Huge_Factorial(const ll N)
```

* $N!$ を求める.
* **計算量** : $O(\sqrt{N} (\log N)^2)$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/02/08| Huge_Factorial の実装 |
