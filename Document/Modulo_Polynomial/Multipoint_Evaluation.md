---
title: 多点評価
documentation_of: //Modulo_Polynomial/Multipoint_Evaluation.hpp
---

## Outline

多項式 $P$ と $a_1, \dots, a_m \in F$ に対して, $P(a_1), \dots, P(a_m)$ を高速に求める.

## Theory

次の事実を用いる.

* (**剰余の定理**) $P \in F[x]$ を多項式, $a \in F$ とする. このとき, $P(x) \equiv P(a) \pmod{(x-a)}$ が成り立つ.
* $P, Q, R, S, T \in F[x]$ とする. このとき, $P(x) \equiv Q(x) \pmod{S(x) T(x)}$ かつ $P(x) \equiv R(x) \pmod{S(x)}$ ならば, $Q(x) \equiv R(x) \pmod{S(x)}$ である.

以上から, 次のように計算することによって, $P(a_1), \dots, P(a_m)$ を高速に求めることが可能になる.

* $Q(x) := (x - a_1) \dots (x - a_m)$ を求める.
* $R(x) := P(x) \bmod Q(x)$ とする.
* 各 $j$ に対して, $P(a_j) = P(x) \bmod (x - a_j) = R(x) \bmod (x - a_j)$ によって $P(a_j)$ を求められる.

これを直接求めるのは厳しいが, 以下のようにして根付き木 Subproduct Tree, Subremainder Tree を構築することに寄って, $P(a_j)$ を高速に求められる.

* Subproduct Tree
  * $m$ 個の葉を持ち, それぞれの葉には $x−a_1, x−a_2, \dots, x−a_m$ が書かれている.
  * 葉以外の頂点には、子に書かれた多項式の積が書いている.
* Subremainder Tree
  * 木の構造は Subproduct Tree と一致
  * 各頂点 $v$における Subproduct Tree に書かれている多項式を $Q_v(x)$ としたとき, $P(x)$ を $Q_v(x)$ で割った余り $R_v(x)$ が Subremainder Tree の頂点 $v$ に書かれている多項式とする. これは以下のようにして求められる.
    * $v$ が根のとき, $R_v(x) = P(x) \bmod Q_v(x)$ である.
    * $v$ が根以外のとき, $v$ の親を $p$ とするとき, $R_v(x) = R_p(x) \bmod Q_v(x)$ である.

## Contents

```cpp
Multipoint_Evaluation(Fast_Power_Series<mint> P, const vector<mint> &X)
```

* 多項式 $P$ と $X := (x_0, x_1, \dots, x_{M-1})$ に対して, $P(x_i)~(0 \leq i < m)$ を求める.
* **計算量** : $P$ の次数を $N$ として, $O(M (\log M)^2 + N \log N)$ 時間.

|日付|内容|
|:---:|:---:|
|2026/02/08| Multipoint_Evaluation の実装|
