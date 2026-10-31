---
title: Todd–Coxeter 法
documentation_of: //Algebra/Todd_Coxeter.hpp
---

## Outline

生成元と関係式によるモノイドの表示 $M = \langle x_0, \dots, x_{K-1} \mid l_0 = r_0, \dots, l_{m-1} = r_{m-1} \rangle$ に対して, $M$ の位数と, 各元への生成元の右からの作用 (右 Cayley グラフ) を求める.

戦略は HLT (Hazelgrove–Leech–Trotter) で, 同一視された元の併合は Union Find で行う.

$M$ が無限のとき, Todd–Coxeter 法は終了しない (命題 12). 有限であるかどうかは一般には判定できない (決定不能) ので, 呼び出し側が $M$ が有限であることを保証する必要がある.

## Define

列/文字列に関する記法 (空列 $\emptyset$, 結合 $\oplus$, 長さ $\lvert \alpha \rvert$ など) は, [列/文字列](/String.html) に従う.

* 実装では, アルファベットを $X = \lbrace 0, 1, \dots, K-1 \rbrace$ とし, 文字 $i$ は生成元 $x_i$ を表す.
* 文字列は文字の列 (`vector<int>`) で表す. 空列 $\emptyset$ は $M$ の単位元 $e$ を表す.
* 関係式 $l = r$ は, 文字列の組 $(l, r)$ (`pair<vector<int>, vector<int>>`) で表す.
* 元は $0, 1, \dots, \lvert M \rvert - 1$ の整数で番号付けする. 単位元の番号は $0$ である.
* 元 $\alpha$ に文字 $x$ を右から掛けた元を $\alpha \cdot x$ で表す.

## Theory

このページでは, $X$ をアルファベットとする. $X^\ast$ は文字列の結合 $\oplus$ に関してモノイドになる ([列/文字列](/String.html) の命題 4).

### 商モノイド

<div class="definition" markdown="1">

定義 1
---

$X^\ast$ 上の同値関係 $\sim$ について, 以下を満たすとき, $\sim$ は合同関係であるという.

* 任意の $u, v \in X^\ast$ に対して, $u \sim v$ ならば, 任意の $a, b \in X^\ast$ に対して, $a \oplus u \oplus b \sim a \oplus v \oplus b$.

</div>

<div class="proposition" markdown="1">

命題 2
---

$X^\ast$ 上の関係 $R \subset X^\ast \times X^\ast$ について, $R$ を含む合同関係のうち, 最小のものが唯一存在する.

</div>

<div class="proof" markdown="1">

証明
---

$R$ を含む合同関係全体を $\mathcal{C}$ とする. $X^\ast \times X^\ast$ は $R$ を含む合同関係なので, $\mathcal{C}$ は空ではない. $\mathcal{C}$ に属する全ての関係の共通部分を $\sim_0$ とする.

* $\sim_0$ は同値関係である. 反射律, 対称律, 推移律は, $\mathcal{C}$ の各元が満たすので, 共通部分も満たす.
* $\sim_0$ は合同関係である. $u \sim_0 v$ ならば, $\mathcal{C}$ の各元について $u \sim v$ なので, 任意の $a, b$ について $a \oplus u \oplus b \sim a \oplus v \oplus b$ である. よって $a \oplus u \oplus b \sim_0 a \oplus v \oplus b$.
* $\sim_0$ は $R$ を含む.

したがって $\sim_0 \in \mathcal{C}$ であり, $\sim_0$ は $\mathcal{C}$ の全ての元に含まれるので最小である. 最小のものは明らかに唯一である.

</div>

<div class="definition" markdown="1">

定義 3
---

$X^\ast$ 上の関係 $R$ について, $R$ を含む合同関係のうち最小であるものを $\sim_R$ と書く. また, $\sim_R$ における $u \in X^\ast$ の同値類を $[u]$ と書く.

</div>

以下, $R \subset X^\ast \times X^\ast$ を与えられた関係式の集合とし, その元 $(l, r)$ を関係式 $l = r$ と呼ぶ.

<div class="definition" markdown="1">

定義 4
---

$M := X^\ast / {\sim_R}$ とする.

</div>

<div class="proposition" markdown="1">

命題 5
---

$[u] \oplus [v] := [u \oplus v]$ は代表元 $u, v$ の取り方によらず定まり, $M$ はこれを演算として, $e := [\emptyset]$ を単位元とするモノイドになる.

</div>

<div class="proof" markdown="1">

証明
---

$u \sim_R u'$ かつ $v \sim_R v'$ とする. $\sim_R$ は合同関係なので, $u \oplus v \sim_R u' \oplus v$ かつ $u' \oplus v \sim_R u' \oplus v'$ である. 推移律より $u \oplus v \sim_R u' \oplus v'$ なので, 演算は代表元によらず定まる. 結合律と $e$ が単位元であることは, $X^\ast$ がモノイドであることから従う.

</div>

<div class="definition" markdown="1">

定義 6
---

$x \in X$ と $[u] \in M$ に対して, $[u] \cdot x := [u \oplus (x)]$ と定める. 命題 5 より, これは代表元 $u$ の取り方によらず定まる. これを文字 $x$ の右作用という.

また, $w = (x_1, \dots, x_n) \in X^\ast$ に対して, $[u] \cdot w := [u] \cdot x_1 \cdot \dots \cdot x_n$ と定める. ただし, $[u] \cdot \emptyset := [u]$ とする.

</div>

<div class="proposition" markdown="1">

命題 7
---

$u, w \in X^\ast$ に対して, $[u] \cdot w = [u \oplus w]$ である. 特に $[w] = e \cdot w$ である.

</div>

<div class="proof" markdown="1">

証明
---

$w$ の長さに関する帰納法で示す. $w = \emptyset$ のときは定義から明らか. $w = w' \oplus (x)$ のとき, 帰納法の仮定から $[u] \cdot w = ([u] \cdot w') \cdot x = [u \oplus w'] \cdot x = [u \oplus w' \oplus (x)] = [u \oplus w]$ である.

</div>

命題 7 より, 単位元 $e$ から右作用だけで $M$ の全ての元に到達できる. したがって, 頂点を $M$ の元, 辺を $[u] \xrightarrow{x} [u] \cdot x$ としたグラフ (右 Cayley グラフ) が分かれば, $M$ の位数と, 文字列が表す元が分かる.

<div class="proposition" markdown="1">

命題 8
---

$u, v \in X^\ast$ に対して, 以下は同値である.

* (a) $u \sim_R v$.
* (b) $X^\ast$ の列 $u = w_0, w_1, \dots, w_k = v$ ($k \geq 0$) であって, 各 $i$ について, ある $a, b \in X^\ast$ と $(p, q) \in R$ が存在して, $\lbrace w_{i-1}, w_i \rbrace = \lbrace a \oplus p \oplus b, a \oplus q \oplus b \rbrace$ となるものが存在する.

</div>

<div class="proof" markdown="1">

証明
---

(b) を満たすとき $u \approx v$ と書く.

**(b) ⇒ (a)**: $\sim_R$ は $R$ を含む合同関係なので, $(p, q) \in R$ ならば $a \oplus p \oplus b \sim_R a \oplus q \oplus b$ である. よって $w_{i-1} \sim_R w_i$ であり, 推移律より $u \sim_R v$ である.

**(a) ⇒ (b)**: $\approx$ が $R$ を含む合同関係であることを示せば, $\sim_R$ の最小性より $\sim_R \subset \approx$ である. $k = 0$ をとれば反射律が, 列を逆順にすれば対称律が, 列を連結すれば推移律が成り立つので, $\approx$ は同値関係である. $(p, q) \in R$ は $a = b = \emptyset$, $k = 1$ の場合なので, $\approx$ は $R$ を含む. $u \approx v$ ならば, 列の各項の前後に $a', b'$ を結合すれば $a' \oplus u \oplus b' \approx a' \oplus v \oplus b'$ の列が得られるので, $\approx$ は合同関係である.

</div>

### Todd–Coxeter 法

<div class="definition" markdown="1">

定義 9
---

次のものの組を状態という.

* 頂点の集合 $V$ と, 頂点 $0 \in V$.
* 部分的に定義された辺. 頂点 $\alpha$ と文字 $x$ に対して, $\alpha$ から $x$ の辺が定義されているとき, その行き先を $\alpha \cdot x$ と書く.
* $V$ 上の同値関係 $\equiv$.
* 写像 $\varphi : V \to M$.

頂点 $\alpha$ と $w = (x_1, \dots, x_n) \in X^\ast$ について, $\alpha \cdot x_1 \cdot \dots \cdot x_n$ が全て定義されているとき, その行き先を $\alpha \cdot w$ と書く. 特に $\alpha \cdot \emptyset = \alpha$ である.

状態が次の (a) から (d) を満たすとき, 整合的であるという.

* (a) $\varphi(0) = e$.
* (b) $\alpha \cdot x$ が定義されているならば, $\varphi(\alpha \cdot x) = \varphi(\alpha) \cdot x$.
* (c) $\alpha \equiv \beta$ ならば, $\varphi(\alpha) = \varphi(\beta)$.
* (d) 全ての頂点 $\alpha$ について, $\alpha = 0 \cdot w$ となる $w \in X^\ast$ が存在する.

</div>

(b) から, 帰納法により $\alpha \cdot w$ が定義されていれば $\varphi(\alpha \cdot w) = \varphi(\alpha) \cdot w$ である.

Todd–Coxeter 法は, $V = \lbrace 0 \rbrace$, 辺はなし, $\equiv$ は等号, $\varphi(0) = e$ という整合的な状態から始めて, 次の操作を繰り返す.

<div class="proposition" markdown="1">

命題 10
---

整合的な状態に, 以下の操作をしても, 整合的である.

* (1) **定義** (`step`): $\alpha \cdot x$ が未定義のとき, 新しい頂点 $\beta$ を $V$ に加え, $\alpha \cdot x := \beta$ とする. $\equiv$ では $\beta$ は自分自身とのみ同値とし, $\varphi(\beta) := \varphi(\alpha) \cdot x$ とする.
* (2) **関係式の走査** (`walk`, `merge`): $(l, r) \in R$ と頂点 $\alpha$ について, $\alpha \cdot l$ と $\alpha \cdot r$ が定義されているとき, $\alpha \cdot l \equiv \alpha \cdot r$ を加える (すなわち, この対を含む最小の同値関係に $\equiv$ を取り替える).
* (3) **併合の連鎖** (`merge`): $\alpha \equiv \beta$ であり, $\alpha \cdot x$ が定義されているとき, $\beta \cdot x$ が未定義ならば $\beta \cdot x := \alpha \cdot x$ とし, 定義されているならば $\alpha \cdot x \equiv \beta \cdot x$ を加える.

</div>

<div class="proof" markdown="1">

証明
---

**(1)**: (a) と (c) は明らか. (b) は, $\varphi(\alpha \cdot x) = \varphi(\beta) = \varphi(\alpha) \cdot x$ で成り立つ. (d) は, $\alpha = 0 \cdot w$ ならば $\beta = 0 \cdot (w \oplus (x))$ なので成り立つ.

**(2)**: 辺と $\varphi$ は変わらないので, (a), (b), (d) は保たれる. (c) を示す. $\varphi(\alpha) = [u]$ とすると, $\varphi(\alpha \cdot l) = [u] \cdot l = [u \oplus l]$, $\varphi(\alpha \cdot r) = [u \oplus r]$ である. $(l, r) \in R$ より $l \sim_R r$ なので, $\sim_R$ が合同関係であることから $u \oplus l \sim_R u \oplus r$ であり, $\varphi(\alpha \cdot l) = \varphi(\alpha \cdot r)$ が成り立つ. 一方, $\varphi(\alpha) = \varphi(\beta)$ をみたす $(\alpha, \beta)$ の全体は, 同値関係であり, 元の $\equiv$ と $(\alpha \cdot l, \alpha \cdot r)$ を含む. よって, これらを含む最小の同値関係もこれに含まれ, (c) が成り立つ.

**(3)**: $\beta \cdot x := \alpha \cdot x$ とするときは, (c) より $\varphi(\alpha) = \varphi(\beta)$ なので, $\varphi(\beta \cdot x) = \varphi(\alpha \cdot x) = \varphi(\alpha) \cdot x = \varphi(\beta) \cdot x$ で (b) が成り立つ. 辺を加えても (a), (d) は保たれる. 同値関係を加えるときは, $\varphi(\alpha \cdot x) = \varphi(\alpha) \cdot x = \varphi(\beta) \cdot x = \varphi(\beta \cdot x)$ なので, (2) と同様に (c) が成り立つ.

</div>

<div class="proposition" markdown="1">

命題 11
---

整合的な状態が, 以下の (i), (ii), (iii) を満たすとする.

* (i) 全ての頂点 $\alpha$ と全ての文字 $x$ について, $\alpha \cdot x$ が定義されている.
* (ii) $\alpha \equiv \beta$ ならば, 全ての文字 $x$ について $\alpha \cdot x \equiv \beta \cdot x$ である.
* (iii) 全ての頂点 $\alpha$ と全ての $(l, r) \in R$ について, $\alpha \cdot l \equiv \alpha \cdot r$ である.

以下, 頂点 $\alpha$ の $\equiv$ に関する同値類を $\overline{\alpha}$ と書く. このとき, $V / {\equiv}$ に $\overline{\alpha} \cdot x := \overline{\alpha \cdot x}$ で辺を定めたグラフは, $M$ の右 Cayley グラフと同型である. 特に $M$ と $V / {\equiv}$ の間には全単射が存在し, どちらかが有限ならば $\lvert M \rvert = \lvert V / {\equiv} \rvert$ である.

</div>

<div class="proof" markdown="1">

証明
---

(i) より, 全ての頂点 $\alpha$ と $w \in X^\ast$ について $\alpha \cdot w$ が定義される. (ii) より, $\overline{\alpha} \cdot x$ は代表元の取り方によらず定まる. これを繰り返せば, $\overline{\alpha} \cdot w = \overline{\alpha \cdot w}$ である.

**(1) $\psi : M \to V / {\equiv}$, $\psi([w]) := \overline{0 \cdot w}$ が定まる.**

$u \sim_R v$ とする. 命題 8 より, 置き換え $1$ 回の場合, すなわち $u = a \oplus p \oplus b$, $v = a \oplus q \oplus b$ ($(p, q) \in R$ またはその逆) について $\overline{0 \cdot u} = \overline{0 \cdot v}$ を示せばよい. $\gamma := 0 \cdot a$ とすると, (iii) より $\gamma \cdot p \equiv \gamma \cdot q$ である. (ii) を $b$ の文字について繰り返すと, $\gamma \cdot p \cdot b \equiv \gamma \cdot q \cdot b$ である. これは $0 \cdot u \equiv 0 \cdot v$ に他ならない.

**(2) $\psi$ は全射である.**

(d) より, 全ての頂点は $0 \cdot w$ の形で表される.

**(3) $\psi$ は単射である.**

(c) より $\varphi$ は $V / {\equiv}$ から $M$ への写像 $\bar{\varphi}$ を誘導する. (a), (b) から $\varphi(0 \cdot w) = e \cdot w = [w]$ なので, $\bar{\varphi}(\psi([w])) = [w]$, すなわち $\bar{\varphi} \circ \psi = \mathrm{id}_M$ である. よって $\psi$ は単射である.

**(4) 辺が保たれる.**

$\psi([w] \cdot x) = \psi([w \oplus (x)]) = \overline{0 \cdot w \cdot x} = \overline{0 \cdot w} \cdot x = \psi([w]) \cdot x$.

以上から $\psi$ は全単射で, 辺を保つ.

</div>

Todd–Coxeter 法は, 状態が (i), (ii), (iii) を満たしたところで終了し, 頂点の同値類に $0, 1, \dots$ と番号を振り直す (`compress`). このとき, 単位元 $e$ に対応する頂点の同値類の番号は $0$ になる. 実装では各同値類の代表元だけが辺を持つが, 併合のときに (命題 10 の (3) により) 辺を引き継ぐので, (i), (ii), (iii) は同値類ごとに見ても同じである.

<div class="proposition" markdown="1">

命題 12
---

$M$ が無限ならば, Todd–Coxeter 法は終了しない.

</div>

<div class="proof" markdown="1">

証明
---

終了したとき, $V$ は有限である. 命題 10 より状態は整合的であり, 終了条件より (i), (ii), (iii) を満たすので, 命題 11 より $M$ も有限である. 対偶をとれば, $M$ が無限ならば終了しない.

</div>

有限表示のモノイド $M$ が有限かどうかを判定するアルゴリズムは存在しない (決定不能である). 終了しない入力を事前に検出することはできず, Todd–Coxeter 法も, 終了しないことを検出する仕組みは持たない.


また, 終了する場合でも, 途中で作る頂点の個数は $\lvert M \rvert$ を大きく超えることがある. HLT は, 先に全ての頂点で全ての辺を埋めるので, 併合される頂点が多く出る.

実装との対応は以下の通りである.

|概念|実装|
|:---:|:---:|
|頂点, 辺|`T[alpha][x]` (未定義は $-1$)|
|同値関係 $\equiv$|`UF` (union-find)|
|全ての関係式を調べ終えた頂点|`done[alpha]`|
|併合の連鎖|`merge` (スタック)|
|番号の振り直し|`compress`|

調べ終えた性質は, 頂点を併合しても保たれる. そのため, 併合後の頂点の `done` は `done[alpha] || done[beta]` とする.

### 具体例

以下では, 文字 $x_0, x_1$ をそれぞれ生成元 $a, b$ とみなす. 元の番号は構成の過程で決まるので, 単位元の番号が $0$ であること以外は, 番号そのものではなく `eval` の一致・不一致で例を述べる.

#### 巡回群

位数 $3$ の巡回群 $\langle a \mid a^3 = e \rangle$ に対応する例である.

{% raw %}
```cpp
Todd_Coxeter M(1, {{{0, 0, 0}, {}}});

M.order();                          // 3
M.eval({0, 0, 0}) == M.eval({});    // true (a^3 = e)
M.eval({0, 0}) == M.eval({0});      // false
```
{% endraw %}

#### 群にならないモノイド

$\langle a \mid a^3 = a \rangle$ に対応する例である. $a^3 = a$ だが $a^2 \neq a$ より, $a$ に逆元が存在しない.

{% raw %}
```cpp
Todd_Coxeter M(1, {{{0, 0, 0}, {0}}});

M.order();                          // 3 (e, a, a^2)
M.eval({0, 0, 0}) == M.eval({0});   // true
M.eval({0, 0}) == M.eval({0});      // false
M.eval({0}) == M.eval({});          // false
```
{% endraw %}

#### 冪等な元が生成する可換モノイド

$\langle a, b \mid a^2 = a, b^2 = b, ab = ba \rangle$ に対応する例である. 元は $e, a, b, ab$ の $4$ 個である.

{% raw %}
```cpp
Todd_Coxeter M(2, {{{0, 0}, {0}}, {{1, 1}, {1}}, {{0, 1}, {1, 0}}});

M.order();                              // 4
M.eval({0, 1}) == M.eval({1, 0});       // true
M.eval({0, 1, 0}) == M.eval({0, 1});    // true
```
{% endraw %}

#### 3 次対称群

$3$ 次対称群 $\mathfrak{S}_3 = \langle a, b \mid a^2 = b^2 = (ab)^3 = e \rangle$ に対応する例である.

{% raw %}
```cpp
Todd_Coxeter M(2, {{{0, 0}, {}}, {{1, 1}, {}}, {{0, 1, 0, 1, 0, 1}, {}}});

M.order();                              // 6
M.eval({0, 1, 0}) == M.eval({1, 0, 1}); // true  (aba = bab)
M.eval({0, 1}) == M.eval({1, 0});       // false (ab ≠ ba)
```
{% endraw %}

#### 終了しない例

次のように $M$ が無限になる表示は, 命題 12 より終了しない.

* $\langle a \rangle$ ($\mathbb{N}$ と同型).
* $\langle a, b \mid ab = ba \rangle$ ($\mathbb{N}^2$ と同型).

## Contents

### Types

```cpp
using Word = vector<int>
using Relation = pair<Word, Word>
```

* それぞれ文字列, 関係式を表す型.

### Constructor

```cpp
Todd_Coxeter(int K, const vector<Relation> &R)
```

* $K$ 個の文字 $x_0, x_1, \dots, x_{K-1}$ からなる自由モノイドを, 関係式 $R$ で割った商モノイド $M$ を構成する.
* **制約**
  * $M$ は有限でなければならない. 無限の場合は, 命題 12 より終了しない. また, $M$ が有限かどうかは決定不能なので, 終了しない入力を事前に検出することはできない.
* **計算量**
  * 構成の途中で定義する元の個数に依存し, 理論的に押さえつけることは難しい. 特に, 途中の個数は, $M$ の位数と比較しても大きくなることがある.

### order

```cpp
int order() const
```

* $M$ の位数 $\lvert M \rvert$ を返す.

### act

```cpp
int act(int alpha, int x) const
```

* 元 $\alpha$ に文字 $x$ を右から掛けた元 $\alpha \cdot x$ の番号を返す.
* **計算量**
  * $O(1)$

### eval

```cpp
int eval(const Word &w) const
```

* 文字列 $w$ が表す元の番号を返す. すなわち, 単位元に $w$ の文字を左から順に作用させた元である.
* **計算量**
  * $O(\lvert w \rvert)$

### table

```cpp
const vector<vector<int>> &table() const
```

* 作用表を返す. `table()[alpha][x]` は $\alpha \cdot x$ の番号に等しい.

## History

|日付|内容|
|:---:|:---:|
|2026/10/31|Todd–Coxeter 法の実装|
