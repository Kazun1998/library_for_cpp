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

定理 4 より, $D$ が DAG であることと $D$ がトポロジカルソートを持つことは同値である. よって, トポロジカルソートの存在判定がそのまま DAG 判定になる.

また, 定理 4 の (b) ⇒ (a) の証明は構成的であり, 入近傍のない頂点を $1$ 個ずつ取り除いていくことでトポロジカルソートを構築できる. 途中で入近傍のない頂点がなくなったのに頂点が残っている場合, 残りの部分は命題 3 より DAG ではないので, $D$ は DAG ではない.

頂点 $x$ を取り除いたとき, 新たに入近傍がなくなりうる頂点は $x$ の出近傍に限られる. そこで各頂点の入次数を管理し, $x$ の出近傍の入次数を $1$ ずつ減らして, $0$ になった頂点を次の候補に加える. 各頂点・各弧は高々 $1$ 回ずつしか処理されないので, 位数 $n$, 大きさ $m$ の有向グラフに対して $O(n+m)$ 時間でトポロジカルソートを構築できる.

<div class="proposition" markdown="1">

命題 5
---

有向グラフ $D = (V, A)$ と $S, T \subseteq V$ に対して, 次の $2$ つの有向グラフを考える.

* $D^+ = (V, A^+)$: $A^+ = A \cup \{ \overrightarrow{st} \mid s \in S, t \in T \}$ とする.
* $D^x = (V \cup \{x\}, A^x)$: $x \notin V$ を新しい頂点として, $A^x = A \cup \{ \overrightarrow{sx} \mid s \in S \} \cup \{ \overrightarrow{xt} \mid t \in T \}$ とする.

このとき, 以下が成り立つ.

* (a) $D^x$ のトポロジカルソート $\leq$ を $V$ に制限したものは, $D^+$ のトポロジカルソートである.
* (b) $D^+$ がトポロジカルソートを持つならば, $D^x$ もトポロジカルソートを持つ.

特に, 定理 4 より, $D^+$ が DAG であることと $D^x$ が DAG であることは同値である.

</div>

<div class="proof" markdown="1">

証明
---

**(a)**

$\leq$ を $D^x$ のトポロジカルソートとし, $V$ への制限を $\leq_V$ とする. 全順序を制限したものは全順序である. $\overrightarrow{uv} \in A^+$ とする.

* $\overrightarrow{uv} \in A$ のとき: $\overrightarrow{uv} \in A^x$ なので $u < v$ である.
* $u \in S$ かつ $v \in T$ のとき: $\overrightarrow{ux}, \overrightarrow{xv} \in A^x$ なので $u < x < v$ である. 推移律より $u \leq v$ であり, もし $u = v$ ならば $u \leq x \leq u$ から $u = x$ となって $u \neq x$ に矛盾する. よって $u < v$ である.

よって, $\leq_V$ は $D^+$ のトポロジカルソートである.

**(b)**

$\leq$ を $D^+$ のトポロジカルソートとする. $S, T$ の任意の元 $s \in S, t \in T$ について $\overrightarrow{st} \in A^+$ なので $s < t$ である.

$V \cup \{x\}$ 上の関係 $\leq^x$ を, $x$ を $S$ の最大元の直後に挿入することで, 次のように定める. $u, v \in V$ に対して $u \leq^x v \iff u \leq v$ とし, $x$ との比較は以下で定める.

* $S = \emptyset$ のとき: 任意の $u \in V$ について $x \leq^x u$ (つまり $x$ を最小の元とする).
* $S \neq \emptyset$ のとき: $s^* = \max S$ として, $u \in V$ について $u \leq^x x \iff u \leq s^*$, $x \leq^x u \iff s^* < u$ (つまり $x$ を $s^*$ の直後に置く).

これは $\leq$ の全順序の $s^*$ と, その次の元の間に $x$ を挿入したものなので, 全順序である. また, $A$ の弧については $\leq$ と同じ順序なので条件を満たす. さらに,

* 任意の $s \in S$ について, $s \leq s^* < x$ なので $s < x$ である.
* 任意の $t \in T$ について, $S = \emptyset$ ならば $x < t$ である. $S \neq \emptyset$ ならば $s^* < t$ であり, $x$ は $s^*$ の直後なので $x < t$ である.

よって, $\leq^x$ は $D^x$ のトポロジカルソートである.

**最後の主張**

$D^+$ が DAG ならば, 定理 4 より $D^+$ はトポロジカルソートを持つので, (b) より $D^x$ もトポロジカルソートを持ち, 定理 4 より $D^x$ は DAG である. 逆に, $D^x$ が DAG ならば, 定理 4 より $D^x$ はトポロジカルソートを持つので, (a) より $D^+$ もトポロジカルソートを持ち, 定理 4 より $D^+$ は DAG である.

</div>

命題 5 は, `add_arc_multiple` の理論的な裏付けである. `sources` を $S$, `targets` を $T$ とすると, $D^+$ は $S$ の各頂点から $T$ の各頂点へ弧を直接張ったグラフ, $D^x$ は `add_arc_multiple` が実際に作る (新しい頂点 $x$ を経由する) グラフに対応する. 命題 5 より, 弧を $\lvert S \rvert \times \lvert T \rvert$ 本張る代わりに $\lvert S \rvert + \lvert T \rvert$ 本で済ませても, DAG かどうかの判定は変わらない. また, $D^x$ のトポロジカルソートから $x$ を取り除けば, $D^+$ のトポロジカルソートが得られる.

なお, 命題 5 では自己ループも通常の弧として扱う. $S \cap T \neq \emptyset$ のとき, $D^+$ は自己ループを, $D^x$ は $s \to x \to s$ という閉路を持つので, どちらも DAG ではない. これは `ignore_self_loop` = `false` の場合に対応し, `ignore_self_loop` = `true` の場合も `add_arc_multiple` では閉路が残るため `sort` は `nullopt` を返す.

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
* 新しい頂点 $x$ を $1$ 個追加し, `sources` の各頂点から $x$ へ, $x$ から `targets` の各頂点へ弧を張ることで実現する. これにより, 弧の本数は $\lvert \mathrm{sources} \rvert \times \lvert \mathrm{targets} \rvert$ 本ではなく $\lvert \mathrm{sources} \rvert + \lvert \mathrm{targets} \rvert$ 本で済む.
  * 命題 5 より, この方法でも DAG かどうかの判定は変わらず, 結果から $x$ を取り除けば直接弧を張った場合のトポロジカルソートが得られる.
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

### is_DAG

```cpp
bool is_DAG() const
```

* $D$ が DAG かどうかを判定する.
* **返り値**
  * DAG ならば `true`, そうでなければ `false`.
* **計算量**
  * $O(n + m)$

## History

|日付|内容|
|:---:|:---:|
|2026/10/20|`self_loop` を `ignore_self_loop` に改名 <br> トポロジカルソートの構築アルゴリズムを Kahn 法に変更|
|2026/01/31|トポロジカルソートの実装|

