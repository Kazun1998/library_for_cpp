---
title: 離散対数問題
documentation_of: //Modulo/Discrete_Log.hpp
---

## Outline

$X,Y \in \mathbb{Z}/M\mathbb{Z}$ に対して, $X^K = Y$ を満たす最小の非負整数 $K$ を求める。.

## Theory

非負整数 $p, q \in \mathbb{N}$ を $pq \geq M$ を満たすようにする.

次のようにして $X^K = Y$ を満たす $K$ の存在性と最小値 $K$ を行う.

* Baby: $B \subset \mathbb{Z}/M\mathbb{Z}$ を以下で定義する.
  * $B := \left\\{ X^s Y \in \mathbb{Z}/M\mathbb{Z} \mid s = 1, 2, \dots, p \right\\}$
* Giant: $t = 1, 2, \dots, q$ の順に以下を行う.
  * $X^{pt} \in B$ でなければ, 以下の手順は行わない.
  * $X^{pt} \in B$ ならば, $X^{pt} = X^s Y$ となる $1 \leq s \leq p$ が存在し, 必要性が成り立つ.
  * (*) $u = 0, 1, \dots, p - 1$ の順に $X^{p(t-1)+u}=Y$ かどうかを判定する. もし, $X^{p(t-1)+u}=Y$ となる $u$ が見つかれば, 最初に見つかった $u$ に対して, $K = p(t-1)+u$ が最小値となる.
  * (*) を $2$ 回やっても, 条件を満たす $u$ が存在しない場合, 条件を満たす $K$ は存在しない.

ボトルネックとなるパートの計算量は以下のようになる.

* Baby: $O(p)$ 時間
* Giant: ループの回数が $O(q)$ 回
* (*) は $O(p)$ 時間であるが, 実行は高々 $2$ 回である.

よって, 合計で $O(p+q)$ 時間である.

$pq \geq M$ の条件下では, $p = q = \left \lceil \sqrt{M} \right \rceil$ とすると, 計算量が $O(\sqrt{M})$ 時間になる.

## Contents

```cpp
long long Discrete_Log (Modulo &X, Modulo &Y, long long not_exist = -1)
```

* $X^K = Y$ を満たす最小の非負整数 $K$ を求める. ただし, そのような $K$ が存在しない場合は `not_exist` を返り値とする.
* **注意**
  * $X, Y$ の剰余は同じでなくてはならない.
  * $0^0 = 1$ とする.
* **計算量** : $X, Y$ の剰余を $M$ としたとき, $O(\sqrt{M})$ 時間.
