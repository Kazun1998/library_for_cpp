---
title: 最大流
documentation_of: //Max_Flow/Max_Flow.hpp
---

## Outline

容量付き有向グラフ (フロー場) 上の最大流問題を Dinic 法で解く. 最大流を求めた後に, 最小カットも求められる.

## Theory

<div class="problem" markdown="1">

最大流問題
---

$D = (V, A)$ を有向グラフとする.

* 頂点 $v \in V$ に対して, $v$ を始点とする弧全体の集合を $\delta^+(v)$, $v$ を終点とする弧全体の集合を $\delta^-(v)$ と書く.
* 各弧 $a \in A$ に対して, 容量 $c(a) \geq 0$ が与えられている.

$s \neq t$ なる $s, t \in V$ に対して, 以下の $f: A \to \mathbb{R}$ に関する最大化問題を最大流問題という.

* Maximize $\displaystyle \sum_{a \in \delta^+(s)} f(a) - \sum_{a \in \delta^-(s)} f(a)$.
* Subject to
  * $0 \leq f(a) \leq c(a) \quad (a \in A)$.
  * $\displaystyle \sum_{a \in \delta^+(v)} f(a) = \sum_{a \in \delta^-(v)} f(a) \quad (v \in V \setminus \lbrace s, t \rbrace)$.

</div>

以下, 総和が意味を持ち, 最大値の存在が言えるように, $V$ と $A$ は有限集合 (多重辺・自己ループは許す) とし, 容量 $c(a)$ は実数とする.

### 理論付け

<div class="definition" markdown="1">

定義 1
---

最大流問題の制約を全て満たす $f: A \to \mathbb{R}$ を **$s$-$t$ フロー** (または単にフロー) という. フロー $f$ に対して, 目的関数の値

$$ \lvert f \rvert := \sum_{a \in \delta^+(s)} f(a) - \sum_{a \in \delta^-(s)} f(a) $$

を $f$ の **流量** という. 流量が最大となるフローを **最大流** といい, その流量を **最大流量** という.

</div>

<div class="proposition" markdown="1">

命題 2
---

最大流は存在する.

</div>

<div class="proof" markdown="1">

証明
---

全ての弧で $f(a) = 0$ とした $f$ はフローなので, フロー全体の集合 $F$ は空でない. また, $F$ は $\mathbb{R}^A$ の有限個の等式と不等式で定まり, 各成分が $0 \leq f(a) \leq c(a)$ を満たすので, 有界閉集合である. $A$ は有限集合なので, $F$ はコンパクトである. 流量 $\lvert f \rvert$ は $f$ について連続なので, 最大値・最小値の定理より $F$ 上で最大値をとる.

</div>

<div class="definition" markdown="1">

定義 3
---

$S \cup T = V$ かつ $S \cap T = \emptyset$ を満たす $S, T \subset V$ の組 $(S, T)$ を $V$ の分割という. $V$ の分割 $(S, T)$ であって, $s \in S$ かつ $t \in T$ を満たすものを **$s$-$t$ カット** (または単にカット) という. カット $(S, T)$ に対して,

* $S$ の頂点から $T$ の頂点への弧全体の集合を $\delta(S, T)$
* $T$ の頂点から $S$ の頂点への弧全体の集合を $\delta(T, S)$

と書き,

$$ \mathrm{cap}(S, T) := \sum_{a \in \delta(S, T)} c(a) $$

を $(S, T)$ の **容量** という. 容量が最小となるカットを **最小カット** という.

</div>

<div class="proposition" markdown="1">

命題 4
---

$f$ をフロー, $(S, T)$ をカットとする. このとき,

$$ \lvert f \rvert = \sum_{a \in \delta(S, T)} f(a) - \sum_{a \in \delta(T, S)} f(a) $$

が成り立つ.

</div>

<div class="proof" markdown="1">

証明
---

頂点 $v$ に対して,

$$ \mathrm{ex}(v) := \sum_{a \in \delta^+(v)} f(a) - \sum_{a \in \delta^-(v)} f(a) $$

とおく. $\mathrm{ex}(s) = \lvert f \rvert$ である. また, $t \in T$ と $S \cap T = \emptyset$ より $t \notin S$ なので, $v \in S \setminus \lbrace s \rbrace$ ならば $v \neq s, t$ であり, 流量保存則より $\mathrm{ex}(v) = 0$ である. よって,

$$ \sum_{v \in S} \mathrm{ex}(v) = \lvert f \rvert $$

である.

一方, 左辺を弧ごとにまとめる. $u$ から $v$ への弧 $a$ について, $f(a)$ は $\mathrm{ex}(u)$ に $+f(a)$, $\mathrm{ex}(v)$ に $-f(a)$ として現れる.

* $u, v \in S$ のとき (自己ループを含む), $a$ の寄与は $f(a) - f(a) = 0$ である.
* $u \in S, v \in T$ のとき, すなわち $a \in \delta(S, T)$ のとき, $a$ の寄与は $+f(a)$ である.
* $u \in T, v \in S$ のとき, すなわち $a \in \delta(T, S)$ のとき, $a$ の寄与は $-f(a)$ である.
* $u, v \in T$ のとき, $a$ は左辺に現れない.

よって, 左辺は $\displaystyle \sum_{a \in \delta(S, T)} f(a) - \sum_{a \in \delta(T, S)} f(a)$ に等しい.

</div>

<div class="proposition" markdown="1">

命題 5 (弱双対性)
---

$f$ をフロー, $(S, T)$ をカットとする. このとき, $\lvert f \rvert \leq \mathrm{cap}(S, T)$ が成り立つ.

さらに, 等号が成り立つための必要十分条件は, 次の $2$ つがともに成り立つことである.

* 任意の $a \in \delta(S, T)$ に対して, $f(a) = c(a)$.
* 任意の $a \in \delta(T, S)$ に対して, $f(a) = 0$.

</div>

<div class="proof" markdown="1">

証明
---

命題 4 と容量制約 $0 \leq f(a) \leq c(a)$ より,

$$ \lvert f \rvert = \sum_{a \in \delta(S, T)} f(a) - \sum_{a \in \delta(T, S)} f(a) \leq \sum_{a \in \delta(S, T)} f(a) \leq \sum_{a \in \delta(S, T)} c(a) = \mathrm{cap}(S, T) $$

である. $1$ つ目の不等号で等号が成り立つことは, 任意の $a \in \delta(T, S)$ で $f(a) = 0$ となることと同値であり, $2$ つ目の不等号で等号が成り立つことは, 任意の $a \in \delta(S, T)$ で $f(a) = c(a)$ となることと同値である.

</div>

### 残余グラフによる最大流の導出

<div class="definition" markdown="1">

定義 6
---

$f$ をフローとする. 各弧 $a \in A$ が $u$ から $v$ への弧であるとき, 次の $2$ 種類の弧を考える.

* **順辺** $a$: $u$ から $v$ への弧で, **残余容量** は $c(a) - f(a)$ である.
* **逆辺** $\overline{a}$: $v$ から $u$ への弧で, **残余容量** は $f(a)$ である.

これらのうち, 残余容量が正であるもの全体を $A_f$ とし, 有向グラフ $D_f = (V, A_f)$ を $f$ に関する **残余グラフ** という. また, $D_f$ 上の $s$ から $t$ への路を **増加パス** という.

</div>

実装では, 順辺を `cap` $= c(a)$, `flow` $= f(a)$ として持ち, 逆辺を `cap` $= 0$, `flow` $= -f(a)$ として持つ. こうすると, どちらの弧でも残余容量は `remain()` $=$ `cap` $-$ `flow` で求まり, 残余グラフの弧であることは `is_flowable()` (`flow` $<$ `cap`) で判定できる. また, 順辺に $d$ だけ流すことと, 逆辺に $d$ だけ流す (順辺の流量を $d$ だけ減らす) ことは, どちらも `push(d)` で表せる.

<div class="theorem" markdown="1">

定理 7 (最大流最小カット定理)
---

$f$ をフローとする. 以下は同値である.

* (a) $f$ は最大流である.
* (b) 残余グラフ $D_f$ に増加パスが存在しない.
* (c) $\lvert f \rvert = \mathrm{cap}(S, T)$ となるカット $(S, T)$ が存在する.

</div>

<div class="proof" markdown="1">

証明
---

**(a) $\Rightarrow$ (b)**: 対偶を示す. $D_f$ に増加パスが存在するとする. 増加パスから閉路を取り除くことで, 同じ頂点を $2$ 度通らない増加パス $s = v_0, v_1, \dots, v_k = t$ が取れる. この路の弧の残余容量の最小値を $\varepsilon$ とすると, $\varepsilon > 0$ である.

同じ頂点を $2$ 度通らないので, この路は同じ $a \in A$ の順辺 $a$ と逆辺 $\overline{a}$ を両方使うことはない. そこで, 路の各弧について次のように $f$ を変更したものを $f'$ とする.

* 順辺 $a$ を使うとき, $f'(a) = f(a) + \varepsilon$.
* 逆辺 $\overline{a}$ を使うとき, $f'(a) = f(a) - \varepsilon$.

$\varepsilon$ の取り方から, $f'$ は容量制約を満たす.

次に, 命題 4 の証明と同じ $\mathrm{ex}$ の変化を見る. $D_f$ の $u$ から $v$ への弧を $1$ 本使うと,

* 順辺 $a$ (元の弧も $u$ から $v$) のとき, $f(a)$ が $\varepsilon$ 増えるので, $\mathrm{ex}(u)$ は $\varepsilon$ 増え, $\mathrm{ex}(v)$ は $\varepsilon$ 減る.
* 逆辺 $\overline{a}$ (元の弧は $v$ から $u$) のとき, $f(a)$ が $\varepsilon$ 減るので, $\mathrm{ex}(v)$ は $\varepsilon$ 減り, $\mathrm{ex}(u)$ は $\varepsilon$ 増える.

いずれの場合も, 始点側の $\mathrm{ex}$ が $\varepsilon$ 増え, 終点側の $\mathrm{ex}$ が $\varepsilon$ 減る. よって, 路の途中の頂点 $v_1, \dots, v_{k-1}$ では増減が打ち消し合い, $\mathrm{ex}$ は変わらない. したがって $f'$ は流量保存則も満たすフローであり, $\lvert f' \rvert = \mathrm{ex}(s) + \varepsilon = \lvert f \rvert + \varepsilon > \lvert f \rvert$ である. これは $f$ が最大流でないことを意味する.

**(b) $\Rightarrow$ (c)**: $D_f$ 上で $s$ から到達可能な頂点全体を $S$ とし, $T := V \setminus S$ とする. $s \in S$ であり, (b) より $t \notin S$, すなわち $t \in T$ なので, $(S, T)$ はカットである.

* $a \in \delta(S, T)$ を $u$ ($\in S$) から $v$ ($\in T$) への弧とする. $f(a) < c(a)$ ならば順辺 $a$ が $D_f$ の弧になり, $v$ が $s$ から到達可能になって矛盾する. よって $f(a) = c(a)$ である.
* $a \in \delta(T, S)$ を $u$ ($\in T$) から $v$ ($\in S$) への弧とする. $f(a) > 0$ ならば逆辺 $\overline{a}$ ($v$ から $u$ への弧) が $D_f$ の弧になり, $u$ が $s$ から到達可能になって矛盾する. よって $f(a) = 0$ である.

命題 5 の等号成立条件より, $\lvert f \rvert = \mathrm{cap}(S, T)$ である.

**(c) $\Rightarrow$ (a)**: 任意のフロー $g$ に対して, 命題 5 より $\lvert g \rvert \leq \mathrm{cap}(S, T) = \lvert f \rvert$ である. よって $f$ は最大流である.

</div>

### 最大流問題と最小カット問題の双対性

<div class="proposition" markdown="1">

命題 8
---

最大流量は, 最小カットの容量に等しい. さらに, $f$ が最大流であるとき, 残余グラフ $D_f$ 上で $s$ から到達可能な頂点全体を $S$, $T := V \setminus S$ とすると, $(S, T)$ は最小カットである.

</div>

<div class="proof" markdown="1">

証明
---

命題 2 より最大流 $f$ が存在する. 定理 7 の (a) $\Rightarrow$ (b) $\Rightarrow$ (c) の証明より, $S$ を $D_f$ 上で $s$ から到達可能な頂点全体, $T := V \setminus S$ とすると, $(S, T)$ はカットであり, $\lvert f \rvert = \mathrm{cap}(S, T)$ である. 一方, 任意のカット $(S', T')$ に対して, 命題 5 より $\mathrm{cap}(S', T') \geq \lvert f \rvert = \mathrm{cap}(S, T)$ である. よって $(S, T)$ は最小カットであり, その容量は最大流量に等しい.

</div>

`min_cut(s)` は, `max_flow(s, t)` で最大流を求めた後の残余グラフ上で $s$ から BFS を行い, 命題 8 の $(S, T)$ を求めている. 返り値では $S$ に属する頂点が `false`, $T$ に属する頂点が `true` である.

最大流問題は $f$ に関する線形計画問題なので, その双対問題を考えることができる. 以下, 弧 $a \in A$ の始点を $s(a)$, 終点を $t(a)$ と書く.

<div class="proposition" markdown="1">

命題 9 (最大流問題の双対問題)
---

最大流問題の双対問題は, $p: V \to \mathbb{R}$ と $z: A \to \mathbb{R}$ に関する次の最小化問題 (D) である.

* Minimize $\displaystyle \sum_{a \in A} c(a) z(a)$.
* Subject to
  * $z(a) \geq p(s(a)) - p(t(a)) \quad (a \in A)$.
  * $z(a) \geq 0 \quad (a \in A)$.
  * $p(s) = 1, \quad p(t) = 0$.

さらに, 以下が成り立つ.

* (D) の最適値は, 最小カットの容量に等しい. したがって, 最大流量にも等しい.
* $(S, T)$ を最小カットとし, $p(v) = 1 ~ (v \in S)$, $p(v) = 0 ~ (v \in T)$, $z(a) = 1 ~ (a \in \delta(S, T))$, $z(a) = 0 ~ (a \notin \delta(S, T))$ とすると, $(p, z)$ は (D) の最適解である.

</div>

<div class="proof" markdown="1">

証明
---

**双対問題の導出**: 線形計画問題

* Maximize $\displaystyle \sum_{j} w_j x_j$.
* Subject to
  * $\displaystyle \sum_{j} \alpha_{ij} x_j \leq b_i \quad (i \in I)$.
  * $\displaystyle \sum_{j} \beta_{kj} x_j = d_k \quad (k \in K)$.
  * $x_j \geq 0$.

の双対問題は, 不等式制約 $i$ に変数 $y_i \geq 0$ を, 等式制約 $k$ に符号制約の無い変数 $q_k$ を対応させた

* Minimize $\displaystyle \sum_{i \in I} b_i y_i + \sum_{k \in K} d_k q_k$.
* Subject to
  * $\displaystyle \sum_{i \in I} \alpha_{ij} y_i + \sum_{k \in K} \beta_{kj} q_k \geq w_j$ (各 $j$).
  * $y_i \geq 0 \quad (i \in I)$.

である. 最大流問題では, 変数は $f(a) ~ (a \in A)$ であり,

* 容量制約 $f(a) \leq c(a)$ に $z(a) \geq 0$ を,
* 頂点 $w \in V \setminus \lbrace s, t \rbrace$ における流量保存則 $\displaystyle \sum_{a \in \delta^+(w)} f(a) - \sum_{a \in \delta^-(w)} f(a) = 0$ に $q(w)$ を

対応させる. 目的関数における $f(a)$ の係数は, $s(a) = s$ ならば $1$ を, $t(a) = s$ ならば $-1$ を足したものである. また, 流量保存則の左辺において, $f(a)$ は $w = s(a)$ の式に係数 $1$ で, $w = t(a)$ の式に係数 $-1$ で現れる. よって, $q(s) = q(t) = 0$ と約束すると, $f(a)$ に対応する双対問題の制約は

$$ z(a) + q(s(a)) - q(t(a)) \geq [s(a) = s] - [t(a) = s] $$

となる. ただし, $[P]$ は条件 $P$ が真ならば $1$, 偽ならば $0$ を表す. ここで, $p(v) := [v = s] - q(v)$ とおくと, $p(s) = 1$, $p(t) = 0$ であり, 上の制約は $z(a) \geq p(s(a)) - p(t(a))$ と書き直せる. $s, t$ 以外の頂点 $v$ では $q(v)$ に符号制約が無いので, $p(v)$ にも符号制約は無い. 等式制約の右辺は $0$ なので, 目的関数は $\displaystyle \sum_{a \in A} c(a) z(a)$ である. 以上より, 双対問題は (D) である.

**(D) の最適値が最大流量以上であること**: $(p, z)$ を (D) の制約を満たす任意の組, $f$ を任意のフローとする. $0 \leq f(a) \leq c(a)$ と $z(a) \geq 0$ より $c(a) z(a) \geq f(a) z(a)$ であり, $f(a) \geq 0$ と $z(a) \geq p(s(a)) - p(t(a))$ より $f(a) z(a) \geq f(a) (p(s(a)) - p(t(a)))$ である. よって,

$$ \sum_{a \in A} c(a) z(a) \geq \sum_{a \in A} f(a) (p(s(a)) - p(t(a))) $$

である. 右辺を頂点ごとにまとめると, 命題 4 の証明と同じ $\mathrm{ex}$ を用いて

$$ \sum_{a \in A} f(a) (p(s(a)) - p(t(a))) = \sum_{w \in V} p(w) \mathrm{ex}(w) $$

となる. 流量保存則より $w \neq s, t$ では $\mathrm{ex}(w) = 0$ であり, $p(s) = 1$, $p(t) = 0$, $\mathrm{ex}(s) = \lvert f \rvert$ なので, 右辺は $\lvert f \rvert$ に等しい. したがって, (D) の目的関数の値は, 任意のフローの流量以上である. 命題 2 より最大流が存在するので, (D) の目的関数の値は最大流量以上である.

**最小カットから (D) の解が作れること**: $(S, T)$ を最小カットとし, $(p, z)$ を命題の主張の通りに定める. $s \in S$, $t \in T$ より $p(s) = 1$, $p(t) = 0$ である. 弧 $a$ について, $p(s(a)) - p(t(a)) = 1$ となるのは $s(a) \in S$ かつ $t(a) \in T$ のとき, すなわち $a \in \delta(S, T)$ のときに限り, このとき $z(a) = 1$ である. それ以外のとき $p(s(a)) - p(t(a)) \leq 0 \leq z(a)$ である. よって $(p, z)$ は (D) の制約を満たし, その目的関数の値は

$$ \sum_{a \in A} c(a) z(a) = \sum_{a \in \delta(S, T)} c(a) = \mathrm{cap}(S, T) $$

である. 命題 8 より $\mathrm{cap}(S, T)$ は最大流量に等しい.

以上より, (D) の目的関数の値は常に最大流量以上であり, 最小カットから作った $(p, z)$ で最大流量に一致する. よって, この $(p, z)$ は (D) の最適解であり, (D) の最適値は最小カットの容量 (= 最大流量) に等しい.

</div>

(D) に $p(v) \in \lbrace 0, 1 \rbrace$ という制約を加えると, $S = \lbrace v \in V \mid p(v) = 1 \rbrace$, $T = \lbrace v \in V \mid p(v) = 0 \rbrace$ とすると, $(S, T)$ がカットに対応する. このとき $z(a) = 1 ~ (a \in \delta(S, T))$, $z(a) = 0 ~ (a \notin \delta(S, T))$ とするのが最適なので, (D) は最小カット問題そのものになる. 命題 9 は, この制約を外しても最適値が変わらないことを示している.

最後に, 容量が整数の場合に成り立つ命題を紹介する. 最大流問題に, 各弧の流量が整数であるという制約を加えた次の整数線形計画問題を考える.

* Maximize $\displaystyle \sum_{a \in \delta^+(s)} f(a) - \sum_{a \in \delta^-(s)} f(a)$.
* Subject to
  * $0 \leq f(a) \leq c(a) \quad (a \in A)$.
  * $\displaystyle \sum_{a \in \delta^+(v)} f(a) = \sum_{a \in \delta^-(v)} f(a) \quad (v \in V \setminus \lbrace s, t \rbrace)$.
  * $f(a) \in \mathbb{Z} \quad (a \in A)$.

次の命題 10 より, 容量が整数ならば, この問題は最大流問題と同じ最適値を持つ. このため, 整数の範囲の計算だけで最大流を求めることができる. 証明は, 最大流問題の制約行列が完全ユニモジュラであることによる (ここでは省略する).

<div class="proposition" markdown="1">

命題 10 (整数性)
---

全ての弧 $a \in A$ について容量 $c(a)$ が整数であるとする. このとき, 以下が成り立つ.

* 最大流量は整数である.
* 全ての弧で $f(a)$ が整数であるような最大流 $f$ が存在する.

特に, 上の整数線形計画問題の最適値は, 最大流問題の最適値 (最大流量) に等しい.

</div>

## Contents

### Constructor

```cpp
template<typename Cap>
Max_Flow<Cap> F(int N = 0)
```

* 容量の型が `Cap` である, 位数 $N$ のフロー場を生成する. 弧は無い.

### order

```cpp
int F.order()
```

* フロー場の位数を返す.

### size

```cpp
int F.size()
```

* フロー場のサイズ (`add_arc` で追加した弧の本数) を返す. 残余グラフ用の逆辺は数えない.

### add_arc

```cpp
int F.add_arc(const int u, const int v, const Cap cap)
```

* 頂点 $u$ から頂点 $v$ への容量 `cap` の弧を追加する.
* **返り値**
  * 追加した弧の番号. $0, 1, 2, \dots$ の順に振られる.
* **制約**
  * $0 \leq u, v < N$
  * `cap` $\geq 0$

### add_vertex

```cpp
int F.add_vertex()
```

* 頂点を $1$ 個追加する.
* **返り値**
  * 追加した頂点の番号.

### max_flow

```cpp
Cap F.max_flow(const int source, const int target)
Cap F.max_flow(const int source, const int target, Cap flow_limit)
```

* 頂点 `source` から頂点 `target` へ流せる最大流量を求める.
* `flow_limit` を指定すると, 流す量が高々 `flow_limit` になるところで打ち切る. つまり, 返り値は `flow_limit` と最大流量のうち小さい方になる.
* **返り値**
  * この呼び出しで流した量.
* **注意**
  * 流した結果 (残余グラフ) はフロー場に残る. そのため, `max_flow` を続けて呼ぶと, 前回の流れに追加で流せる量が返る. 例えば, `flow_limit` を指定して途中で打ち切った後に `flow_limit` を指定せずに呼ぶと, $2$ 回の返り値の和が最大流量になる.
* **制約**
  * $0 \leq$ `source`, `target` $< N$
  * `source` $\neq$ `target`
* **計算量** : 計算量は色々ある.
  * 一般には $O(N^2 M)$ 時間.
  * 辺の容量が全て整数である場合
    * 辺容量の平均値が $K$ の場合, $O(K M^{3/2})$ 時間.
    * 辺容量の最大値が $K$ であり, 多重辺が無い場合, $O(K N^{2/3} M)$ 時間.
  * 二部マッチングを求める場合 $O(\sqrt{N} M)$ 時間.

### get_flow

```cpp
vector<vector<tuple<int, int, Cap>>> F.get_flow()
```

* `max_flow` で求めた流れを返す.
* **返り値**
  * 長さ $N$ の配列. 第 $u$ 要素には, $u$ を始点とする各弧について, 次の tuple $(m, v, c)$ が弧の番号の小さい順に並ぶ.
    * 弧の番号が $m$ である.
    * $u$ から $v$ への弧である.
    * その弧の流量が $c$ である.
* **計算量**
  * $O(N + M)$ 時間.

### min_cut

```cpp
vector<bool> F.min_cut(const int s)
```

* 頂点 $s$ を始点とする最小カットを求める. `flow_limit` を指定せずに `F.max_flow(s, t)` を呼んだ後に使う (以下, この $t$ を終点とする).
* **返り値**
  * 長さ $N$ の `bool` 配列 $x$. 最小カット $(S, T)$ の一例を表し, 以下を満たす.
    * $v \in S \iff x_v = \mathtt{false}$ (残余グラフ上で $s$ から到達可能)
    * $v \in T \iff x_v = \mathtt{true}$
    * $s \in S, t \in T$
  * $S$ から $T$ へ向かう弧の容量の総和は, 最大流量に等しい.
* **計算量**
  * $O(N + M)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/11/06| `flow_limit` を指定した `max_flow` が上限を超えて流す不具合と, current-arc が働かない不具合を修正. ドキュメントの `min_cut` の返り値の説明を実装に合わせて修正 ($S$ 側が `false`) |
