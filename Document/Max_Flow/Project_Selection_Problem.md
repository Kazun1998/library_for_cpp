---
title: Project Selection Problem
documentation_of: //Max_Flow/Project_Selection_Problem.hpp
---

## Outline

$N$ 個の変数それぞれに $0$ か $1$ を割り当てるとき, 割り当てに応じて決まる利得の総和を最大化する問題 (Project Selection Problem や燃やす埋める問題と呼ばれている) を, 最小カットに帰着して解く.

扱える利得は, そのコスト (利得の符号を反転したもの) が劣モジュラ関数になるものに限られる. 計算は, 最大流を $1$ 回求めることで行う.

## Theory

<div class="definition" markdown="1">

定義 1 (アイバーソンの記法)
---

条件 $Q$ に対して,

$$ [Q] := \begin{cases} 1 & (Q \text{ が真}) \\ 0 & (Q \text{ が偽}) \end{cases} $$

と定める. また, $a \in \mathbb{R} \cup \lbrace -\infty \rbrace$ と条件 $Q$ に対して, $a [Q]$ は $Q$ が真ならば $a$, 偽ならば $0$ を表す. すなわち, $(-\infty) \cdot 0 = 0$ と約束する.

</div>

<div class="problem" markdown="1">

Project Selection Problem
---

有限集合 $I$ の各元 $i$ に変数 $x_i \in \lbrace 0, 1 \rbrace$ が対応しているとする. 以下が与えられる.

* 各 $i \in I$ に対して, $x_i = 0$ のときの利得 $\alpha_i$ と, $x_i = 1$ のときの利得 $\beta_i$. ただし, $\alpha_i, \beta_i \in \mathbb{R} \cup \lbrace -\infty \rbrace$.
* 組の集合 $P \subset I \times I$ と, 各 $(i, j) \in P$ に対して, $x_i = 0$ かつ $x_j = 1$ のときの利得 $\gamma_{ij} \in \mathbb{R} \cup \lbrace -\infty \rbrace$. ただし, $\gamma_{ij} \leq 0$.

$\theta_i(0) := \alpha_i, \theta_i(1) := \beta_i$ とする. このとき, 以下の $x \in \lbrace 0, 1 \rbrace^I$ に関する最大化問題を Project Selection Problem という.

* Maximize $\displaystyle g(x) := \sum_{i \in I} \theta_i(x_i) + \sum_{(i, j) \in P} \gamma_{ij} [x_i = 0 \land x_j = 1]$.

</div>

利得 $-\infty$ は, その割り当てを禁止することを表す.

実装のメソッドとの対応は次の通りである.

* `set_zero(i, a)`, `set_one(i, a)` : $\alpha_i, \beta_i$ に $a$ を足す. `ban_zero(i)`, `ban_one(i)` は $\alpha_i, \beta_i$ を $-\infty$ にする.
* `set_zero_one(i, j, a)` : $(i, j)$ を $P$ に加え, $\gamma_{ij} = a$ とする.

### 理論付け

$g$ の符号を反転した $E(x) := -g(x)$ を **コスト** という. $E$ は $\mathbb{R} \cup \lbrace +\infty \rbrace$ に値をとり, Project Selection Problem は $E$ の最小化問題と同じである.

<div class="definition" markdown="1">

定義 2
---

$U$ を有限集合とする. $x, y \in \lbrace 0, 1 \rbrace^U$ に対して, 成分ごとに最小値・最大値をとったものを $x \wedge y, x \vee y$ と書く.

関数 $E: \lbrace 0, 1 \rbrace^U \to \mathbb{R} \cup \lbrace +\infty \rbrace$ が, 任意の $x, y \in \lbrace 0, 1 \rbrace^U$ に対して

$$ E(x \wedge y) + E(x \vee y) \leq E(x) + E(y) $$

を満たすとき, $E$ は **劣モジュラ** であるという.

</div>

$x, y \in \lbrace 0, 1 \rbrace^U$ について, 全ての $u \in U$ で $x_u \leq y_u$ が成り立つことを $x \leq y$ と書く. $x \leq y$ または $y \leq x$ が成り立つならば, $\lbrace x \wedge y, x \vee y \rbrace = \lbrace x, y \rbrace$ なので, 不等式は自明に成り立つ. したがって, 不等式を確かめる必要があるのは, $x \leq y$ と $y \leq x$ のどちらも成り立たない組だけである. 特に $U$ が $2$ 元集合のとき, そのような組は $x = (0, 1), y = (1, 0)$ (とその入れ替え) だけであり, 劣モジュラであることは

$$ E(0, 0) + E(1, 1) \leq E(0, 1) + E(1, 0) $$

と同値である.

また, 劣モジュラ関数の和は劣モジュラである. 定義域を $\lbrace x \in \lbrace 0, 1 \rbrace^U \mid x_u = 0 \rbrace$ のように一部の成分を固定した集合に制限したものも, この集合が $\wedge, \vee$ について閉じているので, 残りの成分の関数として劣モジュラである.

以下, 有向グラフ $D = (V, A)$ の弧 $a$ の始点を $s(a)$, 終点を $t(a)$ と書き, 各弧の容量を $c(a) \in \mathbb{R} \cup \lbrace +\infty \rbrace, c(a) \geq 0$ とする. $x \in \lbrace 0, 1 \rbrace^V$ に対して,

$$ \kappa(x) := \sum_{a \in A} c(a) [x_{s(a)} = 0 \land x_{t(a)} = 1] $$

とおく. 相異なる $2$ 頂点 $s, t \in V$ について $x_s = 0, x_t = 1$ であるとき, $S := \lbrace v \in V \mid x_v = 0 \rbrace$, $T := \lbrace v \in V \mid x_v = 1 \rbrace$ とすると $(S, T)$ は $s$-$t$ カットであり, $\kappa(x)$ はその容量 $\mathrm{cap}(S, T)$ に等しい. 逆に, 全ての $s$-$t$ カットはこのようにして得られる.

<div class="proposition" markdown="1">

命題 3 (カットの容量の劣モジュラ性)
---

$\kappa$ は劣モジュラである. 特に, $x_s = 0, x_t = 1$ と固定して, カットの容量を残りの頂点への $0, 1$ の割り当ての関数とみなしたものも劣モジュラである.

</div>

<div class="proof" markdown="1">

証明
---

劣モジュラ関数の和は劣モジュラなので, 各弧 $a$ について $h(x) := c(a) [x_u = 0 \land x_v = 1]$ ($u = s(a), v = t(a)$) が劣モジュラであることを示せばよい. $u = v$ のときは $h = 0$ なので明らかである. 以下 $u \neq v$ とし, $x, y \in \lbrace 0, 1 \rbrace^V$ を任意にとる. $h \geq 0$ に注意する.

* $h(x \wedge y) > 0$ のとき, $\min(x_u, y_u) = 0$ かつ $\min(x_v, y_v) = 1$ である. よって $x_v = y_v = 1$ であり, $x_u, y_u$ の少なくとも一方は $0$ なので, $h(x), h(y)$ の少なくとも一方は $c(a)$ である.
* $h(x \vee y) > 0$ のとき, $\max(x_u, y_u) = 0$ かつ $\max(x_v, y_v) = 1$ である. よって $x_u = y_u = 0$ であり, $x_v, y_v$ の少なくとも一方は $1$ なので, $h(x), h(y)$ の少なくとも一方は $c(a)$ である.
* 両方が正のとき, 上の $2$ つより $x_u = y_u = 0$ かつ $x_v = y_v = 1$ なので, $h(x) = h(y) = c(a)$ である.

いずれの場合も $h(x \wedge y) + h(x \vee y) \leq h(x) + h(y)$ が成り立つ.

後半は, 定義 2 の後の注意より従う.

</div>

<div class="proposition" markdown="1">

命題 4 (最小カットへの帰着)
---

Project Selection Problem に対して, 有向グラフ $D = (V, A)$ ($V = I \cup \lbrace s, t \rbrace$), 容量 $c(a) \geq 0$ ($+\infty$ を許す), 実数 $C$ を適切に選ぶと, 任意の $x \in \lbrace 0, 1 \rbrace^I$ に対して

$$ g(x) = C - \kappa(x) $$

が成り立つ. ただし, 右辺の $\kappa(x)$ は, $I$ の頂点に $x$ を, $s$ に $0$ を, $t$ に $1$ を割り当てたときの $\kappa$ の値である.

特に, Project Selection Problem の最適値は $C - (\text{最小カットの容量})$ に等しく, 最小カット $(S, T)$ に対して $x_i := [i \in T]$ とおいたものは最適解である.

</div>

<div class="proof" markdown="1">

証明
---

$g$ の各項 $w$ ごとに, 弧の集合 $A_w$ と実数 $C_w$ を

$$ w(x) = C_w - \kappa_w(x) $$

となるように作る. ここで, $\kappa_w$ は弧を $A_w$ に限った $\kappa$ である. $A$, $C$ をそれぞれの和集合・和とすると, $\kappa$ は弧ごとの和なので, 主張の等式を得る.

**$\alpha_i [x_i = 0]$ の項**: $\alpha_i \geq 0$ のとき, $C_w = \alpha_i$ とし, $s$ から $i$ への容量 $\alpha_i$ の弧を張る. この弧は $x_i = 1$ のときにカットされるので, $C_w - \kappa_w = \alpha_i - \alpha_i [x_i = 1] = \alpha_i [x_i = 0]$ である. $\alpha_i < 0$ のとき ($-\infty$ を含む), $C_w = 0$ とし, $i$ から $t$ への容量 $-\alpha_i$ の弧を張る. この弧は $x_i = 0$ のときにカットされるので, $C_w - \kappa_w = \alpha_i [x_i = 0]$ である.

**$\beta_i [x_i = 1]$ の項**: $\beta_i \geq 0$ のとき, $C_w = \beta_i$ とし, $i$ から $t$ への容量 $\beta_i$ の弧を張る. $\beta_i < 0$ のとき, $C_w = 0$ とし, $s$ から $i$ への容量 $-\beta_i$ の弧を張る. 同様に $C_w - \kappa_w = \beta_i [x_i = 1]$ である.

**$\gamma_{ij} [x_i = 0 \land x_j = 1]$ の項**: $C_w = 0$ とし, $i$ から $j$ への容量 $-\gamma_{ij} \geq 0$ の弧を張る. この弧は $x_i = 0$ かつ $x_j = 1$ のときにカットされるので, $C_w - \kappa_w = \gamma_{ij} [x_i = 0 \land x_j = 1]$ である.

後半について. 等式より

$$ \max_{x} g(x) = C - \min_{x} \kappa(x) $$

であり, 右辺の $\min$ は $s$-$t$ カットの容量の最小値である. 最小カット $(S, T)$ に対応する $x$ はこの $\min$ を達成するので, その $x$, すなわち $x_i = [i \in T]$ は $g$ を最大にする.

</div>

容量 $+\infty$ の弧があっても, 容量が有限のカットが存在する (つまり $g(x) > -\infty$ となる $x$ が存在する) ならば, $+\infty$ を有限の容量の総和より大きい実数に置き換えても最小カットは変わらない. よって, 容量が実数の場合の最大流最小カット定理がそのまま使え, 最大流を $1$ 回求めることで最適値と最適解が求まる.

実装の `solve()` は, 命題 4 の証明の通りにグラフを作る. `base` が $C$ であり, `ans` $=$ `base` $-$ (最大流量) が最適値, `choice` $=$ `min_cut(source)` が最小カットである. `choice[i]` が `true` であることは $i \in T$, すなわち $x_i = 1$ を意味する.

<div class="proposition" markdown="1">

命題 5 (コストの劣モジュラ性)
---

Project Selection Problem のコスト $E = -g$ は, $\lbrace 0, 1 \rbrace^I$ 上の劣モジュラ関数である.

</div>

<div class="proof" markdown="1">

証明
---

命題 4 の $D$ と $C$ をとると, $E(x) = \kappa(x) - C$ である. 命題 3 より, $x_s = 0, x_t = 1$ と固定した $\kappa$ は $\lbrace 0, 1 \rbrace^I$ 上の劣モジュラ関数であり, 定数を引いても劣モジュラ性は変わらない. よって $E$ は劣モジュラである.

</div>

命題 5 より, コストが劣モジュラでない目的関数は, Project Selection Problem の形では表せない. 一方, $2$ 変数の項については, 逆に劣モジュラならば必ず表せる.

<div class="proposition" markdown="1">

命題 6 ($2$ 変数の項)
---

$\phi: \lbrace 0, 1 \rbrace^2 \to \mathbb{R}$ を $2$ 変数 $x_i, x_j$ のコストとし, $\phi_{00} := \phi(0, 0)$ などと書く. 以下は同値である.

* (a) $\phi$ は劣モジュラである. すなわち, $\phi_{00} + \phi_{11} \leq \phi_{01} + \phi_{10}$ である.
* (b) 実数 $\alpha_i, \beta_i, \alpha_j, \beta_j$ と実数 $\gamma_{ij} \leq 0$ が存在して, 任意の $x_i, x_j \in \lbrace 0, 1 \rbrace$ に対して

  $$ -\phi(x_i, x_j) = \theta_i(x_i) + \theta_j(x_j) + \gamma_{ij} [x_i = 0 \land x_j = 1] $$

  が成り立つ. すなわち, 利得 $-\phi$ は Project Selection Problem の $1$ 変数の項と $\gamma$ の項の和で表せる.

</div>

<div class="proof" markdown="1">

証明
---

**(a) $\Rightarrow$ (b)**: $4$ 通りの $(x_i, x_j)$ を代入すると確かめられるように,

$$ \phi(x_i, x_j) = \phi_{00} + (\phi_{10} - \phi_{00}) x_i + (\phi_{11} - \phi_{10}) x_j + (\phi_{01} + \phi_{10} - \phi_{00} - \phi_{11}) (1 - x_i) x_j $$

が成り立つ. そこで,

* $\alpha_i := -\phi_{00}$, $\beta_i := -\phi_{10}$,
* $\alpha_j := 0$, $\beta_j := -(\phi_{11} - \phi_{10})$,
* $\gamma_{ij} := -(\phi_{01} + \phi_{10} - \phi_{00} - \phi_{11})$

とおけばよい. (a) より $\gamma_{ij} \leq 0$ である.

**(b) $\Rightarrow$ (a)**: (b) の右辺は $I = \lbrace i, j \rbrace$ の Project Selection Problem の目的関数なので, 命題 5 より $\phi$ は劣モジュラである.

</div>

例えば, 次のような項はコストが劣モジュラなので表せる.

* $x_i \neq x_j$ のときに利得 $a \leq 0$ (`set_not_equal`) : コストは $\phi_{00} = \phi_{11} = 0$, $\phi_{01} = \phi_{10} = -a \geq 0$ である. 実装では $\gamma_{ij} = \gamma_{ji} = a$ として表す.
* $x_i = x_j$ のときに利得 $a \geq 0$ (`set_equal`) : コストは $\phi_{00} = \phi_{11} = -a$, $\phi_{01} = \phi_{10} = 0$ である. 命題 6 の証明の構成より, $\alpha_i = \beta_j = a$, $\beta_i = \alpha_j = 0$, $\gamma_{ij} = -2a$ とすれば表せる.

一方, $x_i = x_j$ のときに利得 $a < 0$ (等しいと罰金) となる項は, コストが $\phi_{00} = \phi_{11} = -a > 0$, $\phi_{01} = \phi_{10} = 0$ となり劣モジュラでないので, そのままでは表せない.
