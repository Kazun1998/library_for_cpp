---
title: 頂点に関するパスクエリ
documentation_of: //Tree/Path_Group_Vertex_Query.hpp
---

## Outline

頂点 $r$ を根とする根付き木 $T = (V, E)$ がある.
可換とは限らない群 $(G, \odot)$ と $a: V \to G$ に関する以下の処理を高速に行う.

* $v \in V, x \in G$ に対して, $a_v \gets x$.
* $u, v \in V$ に対して, 頂点 $u$ から頂点 $v$ へのパス (両端含む) 上にある $a$ の値達を, $u$ 側から $v$ 側の順に演算した総積 $a_{p_0} \odot a_{p_1} \odot \cdots \odot a_{p_k}$ (ただし $p_0, p_1, \ldots, p_k$ は $u = p_0, v = p_k$ なるパス上の頂点列) を求める.

$G$ が可換であることを要求しないため, パスの向き (どちらの端点から演算を始めるか) によって結果が異なりうることに注意する.

## Theory

木 $T$ の Euler tour, すなわち根から始めて, 頂点 $x$ に入るときに $x$ を記録し, $x$ の子を (どれか固定した順序で) 全て再帰的に処理し終えた後に (根でなければ) 親に戻って $x$ の親を記録する, という DFS によって得られる, 長さ $(2N-1)$ の頂点列を考える. 頂点 $x$ が最初に記録される時刻を $\mathrm{in}(x)$, $x$ の部分木の処理が終わって最後に $x$ 自身が記録される時刻を $\mathrm{out}(x)$ とする.

この時刻列上に, 各頂点 $x$ について次の $2$ つの値を配置する.

* 時刻 $\mathrm{in}(x)$: $a_x$
* 時刻 $\mathrm{out}(x) + 1$ ($x$ が根でない場合のみ存在): $a_x^{-1}$

このとき, 時刻 $0$ から時刻 $\mathrm{in}(x)$ までに配置された値を, 時刻の昇順に $\odot$ で演算した総積を考える. 兄弟の部分木への寄り道の部分は, その部分木の根とみなせる頂点 $y$ について $a_y \odot a_y^{-1} = e$ という形で打ち消し合うため (これは $\odot$ の可換性を用いていない), 結局この総積はちょうど根から $x$ までのパス上の値の総積

$$\mathrm{to\_root}(x) = a_r \odot a_{c_1} \odot \cdots \odot a_x$$

(根側が先, $r$ は根, $c_1, \ldots$ は根から $x$ に向かう経路上の頂点) に一致する. 同様に, 同じ時刻列上の値を, **逆順の演算** $\odot' (x, y) := y \odot x$ を用いて時刻 $0$ から時刻 $\mathrm{in}(x)$ まで演算すると,

$$\mathrm{from\_root}(x) = a_x \odot a_{c_{k-1}} \odot \cdots \odot a_r$$

($x$ から根までのパス上の値の総積, $x$ 側が先) が得られる. これらはいずれも, 時刻 $0$ から時刻 $t$ までの区間に関する総積として, $O(\log N)$ で計算できる.

$u, v \in V$ とその最近共通祖先 $w$ について, $u$ から $v$ へのパスの総積は, 以下のように求まる.

$$
\begin{align*}
U &:= \mathrm{from\_root}(u) \odot \mathrm{from\_root}(\mathrm{par}(w))^{-1} \\
D &:= \mathrm{to\_root}(w)^{-1} \odot \mathrm{to\_root}(v) \\
\mathrm{query}(u, v) &= U \odot D
\end{align*}
$$

ただし, $w$ が根の場合は $\mathrm{from\_root}(\mathrm{par}(w))$ を単位元とみなす. $U$ は $u$ から $w$ までのパスの総積 ($u$ 側が先), $D$ は $w$ から $v$ までのパスの総積 ($w$ 側が先, $w$ を含む) であり, $U \odot D$ は $w$ を $1$ 回だけ含む, $u$ から $v$ へのパス全体の総積になる.

$1$ 頂点の値の更新は, `tour` 上の高々 $2$ 箇所 (`in_time[v]` と, $v$ が根でなければ `out_time[v] + 1`) をそれぞれのセグメント木で更新すればよい.

## Contents

### Constructor

```cpp
template<typename G>
Path_Group_Vertex_Query(Tree &tree, const vector<G> &data, const function<G(G, G)> op, const G unit, const function<G(G)> neg)
```

* 根付き木 $T$ と群 $(G, \odot)$ からなるパスクエリの準備を行う.
* **引数**
  * `tree`: 根付き木. 事前に `seal()` 済みである必要がある.
  * `data`: 各頂点 $v$ における初期値 `data[v]`.
  * `op`: $G$ 上の演算 $\odot$.
  * `unit`: $G$ の単位元.
  * `neg`: $G$ における逆元を求める関数.
* **計算量**: $T$ の位数を $N$ として, $O(N \log N)$ 時間.

### update

```cpp
void update(const int &v, const G &x)
```

* 頂点 $v$ における値 $a_v$ を $x$ に変える.
* **引数**
  * $v$: 頂点.
  * $x \in G$.
* **計算量**: $O(\log N)$ 時間.

### query

```cpp
G query(const int &u, const int &v) const
```

* 頂点 $u$ から頂点 $v$ へのパス (両端含む) 上にある値達を, $u$ 側から $v$ 側の順に演算した総積を求める.
* **引数**
  * $u$: パスの始点.
  * $v$: パスの終点.
* **返り値**: $a_{p_0} \odot a_{p_1} \odot \cdots \odot a_{p_k}$ ($p_0, \ldots, p_k$ は $u$ から $v$ へのパス上の頂点列, $p_0 = u, p_k = v$).
* **計算量**: $O(\log N)$ 時間.
