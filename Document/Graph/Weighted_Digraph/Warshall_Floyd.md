---
title: Warshall-Floyd 法
documentation_of: //Graph/Weighted_Digraph/Warshall_Floyd.hpp
---

## Outline

重み付き有向グラフ $D = (V, A, W)$ の全ての頂点対 $(u, v)$ に対して, $u$ から $v$ への最短路長を Warshall-Floyd 法で求める. 弧の重みが負であってもよく, 負閉路があっても計算を続ける.

## Definition

重み付き有向グラフ $D = (V, A, W)$ の頂点 $u, v$ に対して, 以下のように定める.

* $u$ から $v$ に**到達可能**であるとは, $u$ から $v$ への歩道が存在することである.
* 長さが負である閉路を**負閉路**という.
* $u$ から $v$ への最短路長が $-\infty$ であるとは, $u$ から $v$ への歩道で, 長さがいくらでも小さくなるものが存在することである. これは, $u$ から $v$ への歩道が負閉路を経由できることと同値である.
* $u$ から $v$ への最短路長が**有限**であるとは, $u$ から $v$ に到達可能であり, かつ最短路長が $-\infty$ ではないことである.

## Theory

重み付き有向グラフ $D = (V, A, W)$ について, $V = \{v\_1, \dots, v\_N\}$ とする. 歩道 $p$ の長さ $\operatorname{weight}(p)$ は, $p$ に含まれる弧の重みの総和である. また, 歩道 $q$ の終点と歩道 $r$ の始点が等しいとき, それらを連結した歩道を $q \oplus r$ とする.

まず, $D$ に負閉路がない場合を考える. このとき, 歩道の長さは, その歩道から閉路を取り除いて得られるパスの長さ以上になる. よって, 歩道が存在するならば, 長さが最小の歩道が存在する.

$k = 0, 1, 2, \dots, N$ と $s, t \in V$ に対して, $P^{(k)}\_{s, t}$ と $d^{(k)}\_{s, t}$ を以下で定義する.

* $P^{(k)}\_{s, t}$ を, 頂点 $s$ から頂点 $t$ への有向歩道のうち, 始点と終点を除く途中で通る頂点が全て $\{v\_1, \dots, v\_k\}$ に含まれるもの全体の集合とする. $s, t$ 自身は $\{v\_1, \dots, v\_k\}$ に含まれなくてもよい.
* $d^{(k)}\_{s, t}$ を, $P^{(k)}\_{s, t}$ に含まれる歩道の長さの最小値とする. つまり, $\displaystyle d^{(k)}\_{s, t} = \min\_{p \in P^{(k)}\_{s, t}} \operatorname{weight}(p)$. ただし, $P^{(k)}\_{s, t} = \emptyset$ のときは $d^{(k)}\_{s, t} = +\infty$ とする.

最終的に求めるべきは各 $s, t$ に関する $d^{(N)}\_{s, t}$ である.

このとき, $d^{(k)}\_{s, t}$ について次のように求める.

### * $k = 0$ のとき

$P^{(0)}\_{s, t}$ とは, 途中で頂点を通らない $s$ から $t$ への有向歩道, つまり長さが $0$ または $1$ の歩道全体の集合である.

* $s = t$ のとき, $P^{(0)}\_{s, t}$ は頂点 $s$ のみからなる長さ $0$ の歩道と, $s$ の自己ループ $1$ 本からなる歩道全体の集合である. 負閉路がないので, 自己ループの重みは $0$ 以上であり, $d^{(0)}\_{s, s} = 0$ である.
* $s \neq t$ のとき, $P^{(0)}\_{s, t}$ は $s$ から $t$ への弧 $1$ 本からなる歩道全体の集合である. 弧が存在しなければ $P^{(0)}\_{s, t} = \emptyset$ である.

よって,

$$ d^{(0)}_{s, t} = \begin{cases} 0 & (s = t) \\ \displaystyle \min_{a: s \to t} W(a) & (s \neq t, \ s \text{ から } t \text{ への弧が存在する}) \\ +\infty & (s \neq t, \ s \text{ から } t \text{ への弧が存在しない}) \end{cases} $$

である.

### * $k \geq 1$ のとき

$$ d^{(k)}_{s, t} = \min \left(d^{(k-1)}_{s, t}, \ d^{(k-1)}_{s, v_k} + d^{(k-1)}_{v_k, t} \right) $$

が成り立つ. これは以下の理由による.

* $d^{(k)}\_{s, t} \leq$ 右辺: $P^{(k-1)}\_{s, t} \subset P^{(k)}\_{s, t}$ なので, $d^{(k)}\_{s, t} \leq d^{(k-1)}\_{s, t}$ である. また, $q \in P^{(k-1)}\_{s, v\_k}$, $r \in P^{(k-1)}\_{v\_k, t}$ に対して, $q \oplus r$ は途中の頂点が $\{v\_1, \dots, v\_k\}$ に含まれるので, $q \oplus r \in P^{(k)}\_{s, t}$ である. $q, r$ をそれぞれ長さが最小のものにとれば, $\operatorname{weight}(q \oplus r) = d^{(k-1)}\_{s, v\_k} + d^{(k-1)}\_{v\_k, t}$ なので, $d^{(k)}\_{s, t} \leq d^{(k-1)}\_{s, v\_k} + d^{(k-1)}\_{v\_k, t}$ である.
* $d^{(k)}\_{s, t} \geq$ 右辺: $p \in P^{(k)}\_{s, t}$ を長さが最小の歩道とする.
  * $p$ が途中で $v\_k$ を通らないとき, $p \in P^{(k-1)}\_{s, t}$ なので, $\operatorname{weight}(p) \geq d^{(k-1)}\_{s, t}$ である.
  * $p$ が途中で $v\_k$ を通るとき, 途中で最初に $v\_k$ を通る点と最後に $v\_k$ を通る点で, $p = q \oplus c \oplus r$ と分ける. ここで, $c$ は $v\_k$ から $v\_k$ への閉歩道である. $q \in P^{(k-1)}\_{s, v\_k}$, $r \in P^{(k-1)}\_{v\_k, t}$ であり, 負閉路がないので $\operatorname{weight}(c) \geq 0$ である. よって, $\operatorname{weight}(p) \geq \operatorname{weight}(q) + \operatorname{weight}(r) \geq d^{(k-1)}\_{s, v\_k} + d^{(k-1)}\_{v\_k, t}$ である.

計算量について, 各 $d^{(k)}\_{s, t}$ についての更新式は $O(1)$ 時間で計算でき, $0 \leq k \leq N, s, t \in V$ の全てを走るので, $O(N^3)$ 時間である.

また, $d^{(k-1)}\_{v\_k, v\_k} = 0$ なので, $d^{(k)}\_{s, v\_k} = d^{(k-1)}\_{s, v\_k}$, $d^{(k)}\_{v\_k, t} = d^{(k-1)}\_{v\_k, t}$ となり, $v\_k$ に関する行と列は更新で変化しない. そのため, $d^{(k)}$ を $d^{(k-1)}$ に上書きして計算できて, 空間計算量は $O(N^2)$ である.

### 負閉路がある場合

負閉路があるときは, 上の議論はそのままでは成り立たない. 負閉路上の頂点 $v$ は, 計算の過程で $d\_{v, v} < 0$ となる. 本実装では, 以下のようにして扱う.

* $d\_{v\_k, v\_k} < 0$ である $v\_k$ を経由する更新では, 値の発散を防ぐために, 到達可能性のみを更新して距離は更新しない.
* 最後に, $d\_{v, v} < 0$ である頂点 $v$ について, $u$ から $v$ に到達可能かつ $v$ から $w$ に到達可能な $(u, w)$ の最短路長を $-\infty$ とする.

最短路長が有限である $(u, w)$ については, $u$ から $w$ への歩道上に負閉路上の頂点が存在しない. そのため, 負閉路がない場合と同じ議論が成り立ち, 距離と経路は正しく求まる.

## Contents

### Warshall_Floyd

```cpp
template<typename W>
Result<W> Warshall_Floyd(const digraph::Digraph<W> &D)
```

* 重み付き有向グラフ $D$ の全頂点対の最短路を求める. 名前空間は `weighted_digraph::warshall_floyd` である.
* **引数**
  * $D$ : 重み付き有向グラフ ([`digraph::Digraph<W>`](../Digraph/Digraph.html)). 多重弧や自己ループがあってもよい.
* **制約** : 重みの和が `W` の範囲に収まる.
* **計算量** : $D$ の位数を $N$ とすると, $O(N^3)$ 時間, $O(N^2)$ 空間.

### Result

`Warshall_Floyd` の結果を表す構造体である. 到達可能性, 最短路長が $-\infty$ か, 最短路長は, 以下のメンバ関数から取得する.

|メンバ|内容|
|:---|:---|
|`vector<vector<int>> parent_arc_ids`|`parent_arc_ids[u][v]`: $u$ から $v$ への最短路における $v$ に入る弧の ID. $u = v$ や, 意味を持たないときは $-1$|

### has_negative_cycle

```cpp
bool has_negative_cycle() const
```

* $D$ に負閉路が存在するか.
* **計算量** : $O(N)$ 時間.

### is_reachable

```cpp
bool is_reachable(int u, int v) const
```

* $u$ から $v$ に到達可能か.
* **計算量** : $O(1)$ 時間.

### is_unbounded

```cpp
bool is_unbounded(int u, int v) const
```

* $u$ から $v$ への最短路長が $-\infty$ か.
* **計算量** : $O(1)$ 時間.

### is_finite

```cpp
bool is_finite(int u, int v) const
```

* $u$ から $v$ への最短路長が, $-\infty$ ではない有限値として存在するか.
* **計算量** : $O(1)$ 時間.

### distance

```cpp
W distance(int u, int v) const
```

* $u$ から $v$ への最短路長を返す.
* **制約** : `is_finite(u, v)` が `true` である.
* **計算量** : $O(1)$ 時間.

### restore

```cpp
optional<digraph::Path<W>> restore(const digraph::Digraph<W> &D, int start, int goal) const
```

* $\mathrm{start}$ から $\mathrm{goal}$ への最短路を復元する.
* **引数**
  * $D$ : `Warshall_Floyd` に渡したものと同じグラフ.
  * $\mathrm{start}, \mathrm{goal}$ : 始点, 終点.
* **戻り値** : 最短路. $\mathrm{goal}$ に到達できない, または最短路長が $-\infty$ のときは `nullopt`.
* **計算量** : 経路の長さを $L$ とすると, $O(L)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/10/08| Warshall-Floyd 法の実装 |
