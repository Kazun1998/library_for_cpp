---
title: トポロジカルソート
documentation_of: //Others/Topological_Sort.hpp
---

## Outline

有向グラフ $D = (V , A)$ のトポロジカルソートを求める. また, $D$ が DAG かどうかを判定する.

実装は DFS (深さ優先探索) に基づき, 計算量は頂点数 $n$, 弧数 $m$ に対して $O(n + m)$ である.

## Theory

<div class="definition" markdown="1">

定義 1
---

$D = (V, A)$ を有向グラフとする. $D$ のトポロジカルソートとは, 以下を満たす $V$ 上の順序関係 $\leq$ のことである.

* $\leq$ は全順序関係である.
* 任意の $\overrightarrow{uv} \in A$ に対して, $u < v ~(\Leftrightarrow u \leq v \land u \neq v)$ である.

</div>

<div class="definition" markdown="1">

定義 2
---

$D = (V, A)$ を有向グラフとする. $D$ 内に回路を含まないとき, $D$ は有向非巡回グラフ (DAG) であるという.

</div>

<div class="proposition" markdown="1">

命題 3
---

有向グラフ $D = (V, A)$ は $V \neq \emptyset$ であり, DAG であるとする. このとき, 入近傍が存在しない頂点が存在する.

</div>

<div class="proof" markdown="1">

証明
---

背理法で示す. 全ての頂点に入近傍が存在するとする.

$v_0 \in V$ を固定する. このとき, 次のようにして $V$ 上の列 $v_0, v_1, v_2, \dots$ を取ることができる.

* $v_i$ の入近傍を $1$ つ選び, $v_{i+1}$ とする. すなわち, $\overrightarrow{v_{i+1} v_i} \in A$ である.

$D$ の位数を $n$ とすると, 鳩ノ巣原理により, $v_0, v_1, v_2, \dots, v_n$ の中に重複が存在する. その重複を $v_l = v_r ~ (0 \leq l < r \leq n)$ とする.

すると, 各 $i$ について $\overrightarrow{v_{i+1} v_i} \in A$ なので,

$$ v_r, v_{r-1}, \dots, v_l (= v_r) $$

は $D$ 上の回路になり, $D$ が DAG であることに矛盾する.

よって, $D$ には入近傍が存在しない頂点が存在する.

</div>

<div class="theorem" markdown="1">

定理 4
---

有向グラフ $D = (V, A)$ について, 以下は同値である.

* (a) $D$ はトポロジカルソートを持つ.
* (b) $D$ は DAG である.

</div>

<div class="proof" markdown="1">

証明
---

**(a) ならば (b)**

対偶を示す. $D$ が DAG でないとする. このとき, $D$ 上の回路 $v_1, v_2, \dots, v_k, v_1 ~ (k \geq 1)$ が存在する. ここで, $v_{k+1} = v_1$ とおく.

$D$ がトポロジカルソート $\leq$ を持つと仮定する. $\overrightarrow{v_i v_{i+1}} \in A ~ (1 \leq i \leq k)$ なので, 定義 1 より

$$ v_1 < v_2 < \dots < v_k < v_{k+1} = v_1 $$

である. ここで, $<$ は推移的である. 実際, $u < v < w$ とすると, 推移律より $u \leq w$ である. もし $u = w$ ならば $u \leq v \leq u$ となり反対称律より $u = v$ となって $u \neq v$ に矛盾するので, $u \neq w$ すなわち $u < w$ である.

したがって $v_1 < v_1$ となるが, これは $v_1 \neq v_1$ を意味し矛盾する. (特に $k = 1$, つまり自己ループの場合は, $\overrightarrow{v_1 v_1} \in A$ から直ちに $v_1 < v_1$ となり矛盾する.)

よって, $D$ はトポロジカルソートを持たない.

**(b) ならば (a)**

$D$ の位数 $n$ に関する数学的帰納法で示す.

$n = 1$ のとき: $D$ は DAG なので自己ループを持たず, 弧は存在しない. よって, $V$ 上の唯一の全順序がトポロジカルソートである.

$n$ のときに成立するとする. $D$ の位数が $n+1$ であり, DAG であるとする. 命題 3 より, $D$ には入近傍が存在しない頂点 $x$ が存在する.

$D$ から $x$ と $x$ に接続する弧を除いた有向グラフを $D'$ とする. $D'$ の位数は $n$ である. また, $D'$ 上の回路は $D$ 上の回路でもあるので, $D'$ は DAG である. よって, 数学的帰納法の仮定により, $D'$ にはトポロジカルソート $\leq'$ が存在する.

$\leq'$ を使って, $V$ 上の関係 $\leq$ を次のように定義する.

* $u, v \in V$ に対して, 以下のうちのいずれかを満たすとき, そしてその時に限り $u \leq v$ とする.
  * $u = x$.
  * $u, v \neq x$ であり, $u \leq' v$.

この $\leq$ が $D$ のトポロジカルソートであることを示す.

* 反射律: $u = x$ ならば $u \leq u$. $u \neq x$ ならば $\leq'$ の反射律より $u \leq u$.
* 反対称律: $u \leq v$ かつ $v \leq u$ とする. $u = x$ ならば, $v \leq x$ より $v = x$ なので $u = v$. $v = x$ の場合も同様. $u, v \neq x$ ならば, $u \leq' v$ かつ $v \leq' u$ なので $u = v$.
* 推移律: $u \leq v$ かつ $v \leq w$ とする. $u = x$ ならば $u \leq w$. $u \neq x$ ならば, $u \leq v$ より $v \neq x$ であり, さらに $v \leq w$ より $w \neq x$ である. よって $u \leq' v \leq' w$ なので $u \leq w$.
* 全順序性: $u = x$ または $v = x$ ならば, $u \leq v$ または $v \leq u$ が成り立つ. $u, v \neq x$ ならば, $\leq'$ が全順序なので $u \leq' v$ または $v \leq' u$ である.
* 弧の条件: $\overrightarrow{uv} \in A$ とする. $x$ には入近傍が存在しないので $v \neq x$ である. $u = x$ ならば, $x \leq v$ かつ $x \neq v$ なので $u < v$. $u \neq x$ ならば, $\overrightarrow{uv}$ は $D'$ の弧であり, $\leq'$ の性質から $u <' v$ なので, $u \leq v$ かつ $u \neq v$ すなわち $u < v$.

以上より, $\leq$ は $D$ のトポロジカルソートである.

</div>

## Contents

### Constructor

```cpp
Topological_Sort(int n, bool ignore_self_loop = true)
```

* $n$ 頂点の空有向グラフを生成する.
* **引数**
  * `ignore_self_loop`: 自己ループを無視するか?
    * `true` (既定値) のとき, `add_arc` で追加される自己ループは無視される. つまり, 自己ループは順序の制約に影響しないものとして扱う.
    * `false` のとき, 自己ループは通常の弧として追加される. 定義 1 より自己ループを持つ有向グラフはトポロジカルソートを持たないので, `sort` は `nullopt` を返す.

### add_arc

```cpp
void add_arc(const int source, const int target)
```

* 弧 $\overrightarrow{st}$ を追加する. ただし, $s = t$ かつ `ignore_self_loop` = `true` のときは何もしない.

### add_arc_multiple

```cpp
int add_arc_multiple(const vector<int> sources, const vector<int> targets)
```

* `sources` の各頂点から `targets` の各頂点への弧を追加する.
* 新しい頂点 $x$ を $1$ 個追加し, `sources` の各頂点から $x$ へ, $x$ から `targets` の各頂点へ弧を張ることで実現する. これにより, 弧の本数は $|\mathrm{sources}| \times |\mathrm{targets}|$ 本ではなく $|\mathrm{sources}| + |\mathrm{targets}|$ 本で済む.
* **返り値**
  * 追加された頂点 $x$ の番号が返ってくる.
* **注意**
  * $x$ は `sort` の結果にも現れる.
  * `sources` と `targets` に共通する頂点 $s$ があると, $s \to x \to s$ という閉路ができるので, `ignore_self_loop` の設定にかかわらず `sort` は `nullopt` を返す.

### add_vertex

```cpp
int add_vertex()
```

* 頂点を $1$ 個追加する.
* **返り値**
  * 追加された頂点の番号.

### sort

```cpp
optional<vector<int>> sort() const
```

* トポロジカルソートを求める.
* **返り値**
  * DAG の場合は, 全ての弧 $\overrightarrow{uv}$ について $u$ が $v$ より前に来るように並べた頂点列 (トポロジカルソートで小さい順).
  * DAG でない場合は `nullopt`.
* **計算量**
  * $O(n + m)$
* **注意**
  * 再帰による DFS で実装しているので, 再帰の深さが最大で $n$ になる. $n$ が非常に大きい ($10^6$ 程度) 場合は, スタックオーバーフローに注意すること.

### is_DAG

```cpp
bool is_DAG() const
```

* $D$ が DAG かどうかを判定する.
* **返り値**
  * DAG ならば `true`, そうでなければ `false`.
* **計算量**
  * $O(n + m)$

## Usage

```cpp
Topological_Sort T(3);
T.add_arc(0, 2);
T.add_arc(2, 1);

auto order = T.sort(); // order = {0, 2, 1}
```

## Algorithm

頂点 $v$ を始点として DFS を行い, $v$ から出る全ての弧の先の探索が終わった時点 (帰りがけ) で $v$ を列に追加する. 全頂点について行った後, 列を逆順にしたものがトポロジカルソートである.

* 弧 $\overrightarrow{uv}$ について, $v$ は $u$ より先に列に追加される (閉路がない場合) ので, 逆順にすると $u$ が $v$ より前に来る.
* 探索中の頂点 (`use`) に再び到達した場合は閉路が存在するので, `nullopt` を返す.

## History

|日付|内容|
|:---:|:---:|
|2026/01/31|トポロジカルソートの実装|
