---
title: Functional Graph
documentation_of: //Functional_Graph/Functional_Graph.hpp
---

## Outline

Functional Graph に関する構造の決定及び, 計算を高速に行う.

## Theory

### 定義と写像との対応

<div class="definition" markdown="1">

定義 1
---

$D = (V, A)$ を有向グラフとする.

任意の頂点 $v \in V$ における出次数が $1$ であるとき, この $D$ は Functional Graph であるという.

</div>

<div class="proposition" markdown="1">

命題 2
---

Functional Graph $D = (V, A)$ の位数を $n$ とすると, サイズも $n$ である.

</div>

<div class="proof" markdown="1">

証明
---

各頂点 $v \in V$ について, $v$ を始点とする有向辺全体の集合を $A_v$ とする. 各有向辺の始点はただ一つであるから, $A_v ~(v \in V)$ は $A$ を分割する. また, $D$ は Functional Graph であるから, $\lvert A_v \rvert$ は $v$ の出次数 $1$ に等しい. よって,

$$\lvert A \rvert = \sum_{v \in V} \lvert A_v \rvert = \sum_{v \in V} 1 = \lvert V \rvert = n$$

である.

</div>

<div class="theorem" markdown="1">

定理 3
---

$V$ を集合とする. このとき, $V$ を頂点集合とする Functional Graph $D = (V, A)$ と写像 $f: V \to V$ は一対一対応する.

</div>

<div class="proof" markdown="1">

証明
---

$V$ を頂点集合とする Functional Graph 全体の集合を $\mathcal{D}$, 写像 $V \to V$ 全体の集合を $\mathcal{F}$ とする. ここで, 有向辺の集合は $A \subset V \times V$ であり, ループ $(v, v)$ も許すものとする.

まず, 写像 $\Phi: \mathcal{D} \to \mathcal{F}$ を構成する. $D = (V, A) \in \mathcal{D}$ とする. 各頂点 $v \in V$ の出次数は $1$ であるから, $(v, w) \in A$ となる $w \in V$ がただ一つ存在する. この $w$ を $f_D(v)$ と書くことにより, 写像 $f_D: V \to V$ が定まる. $\Phi(D) := f_D$ とする.

次に, 写像 $\Psi: \mathcal{F} \to \mathcal{D}$ を構成する. $f \in \mathcal{F}$ とし, $A_f := \lbrace (v, f(v)) \mid v \in V \rbrace$ とする. 各頂点 $v \in V$ について, $v$ を始点とする $A_f$ の有向辺は $(v, f(v))$ のみであるから, $v$ の出次数は $1$ である. よって, $D_f := (V, A_f) \in \mathcal{D}$ であり, $\Psi(f) := D_f$ とする.

任意の $D \in \mathcal{D}$ に対して $\Psi(\Phi(D)) = D$ であることを示す. $D = (V, A) \in \mathcal{D}$ とする. 任意の $v \in V$ について, $f_D$ の定義から $(v, f_D(v)) \in A$ であるので, $A_{f_D} \subset A$ である. 逆に, $(v, w) \in A$ とすると, $v$ を始点とする $A$ の有向辺はただ一つなので $w = f_D(v)$ であり, $(v, w) \in A_{f_D}$ である. よって $A \subset A_{f_D}$ であり, $A_{f_D} = A$, すなわち $\Psi(\Phi(D)) = D$ である.

任意の $f \in \mathcal{F}$ に対して $\Phi(\Psi(f)) = f$ であることを示す. $f \in \mathcal{F}$ とする. 任意の $v \in V$ について, $v$ を始点とする $A_f$ のただ一つの有向辺は $(v, f(v))$ であるから, $f_{D_f}(v) = f(v)$ である. よって $\Phi(\Psi(f)) = f$ である.

以上より, $\Phi$ と $\Psi$ は互いに逆写像であり, $\mathcal{D}$ と $\mathcal{F}$ は一対一対応する.

</div>

### Functional Graph の構造

以下, Functional Graph $D = (V, A)$ に対して, 各 $v \in V$ について $(v, f(v)) \in A$ となる写像 $f: V \to V$ を考える (定理 3). また, $f^0 = \mathrm{id}_V, f^{k+1} = f \circ f^k$ とする.

<div class="definition" markdown="1">

定義 4
---

$D = (V, A)$ を Functional Graph とし, $f: V \to V$ を $D$ に対応する写像とする.

* ある $k \geq 1$ について $f^k(v) = v$ となるとき, $v \in V$ をサイクル上の頂点という. サイクル上の頂点全体の集合を $C$ とする.
* 相異なる頂点の列 $u_0, u_1, \dots, u_{m-1} ~(m \geq 1)$ が, $0 \leq j < m - 1$ について $(u_j, u_{j+1}) \in A$ であり, かつ $(u_{m-1}, u_0) \in A$ であるとき, この列を $D$ のサイクルという. ただし, 巡回的に並べ替えて得られる列は同じサイクルとみなす.

</div>

<div class="proposition" markdown="1">

命題 5
---

$V$ を有限集合とし, $D = (V, A)$ を Functional Graph とし, $f: V \to V$ を $D$ に対応する写像とする. また, $C$ をサイクル上の頂点全体の集合とする. このとき, 以下が成り立つ.

1. $f(C) \subset C$ であり, $f$ の $C$ への制限は $C$ 上の全単射である.
2. $c \in C$ とし, $m := \min \lbrace k \geq 1 \mid f^k(c) = c \rbrace$ とする. このとき, $c, f(c), \dots, f^{m-1}(c)$ は $D$ のサイクルである. 逆に, $c$ を通る $D$ のサイクルはこれに限る. 特に, 各 $c \in C$ を通るサイクルはただ一つ存在し, $D$ のサイクルの頂点集合全体は $C$ を分割する.
3. 任意の $v \in V$ に対して, ある $k \geq 0$ が存在して, $f^k(v) \in C$ となる.

</div>

<div class="proof" markdown="1">

証明
---

(1) $c \in C$ とし, $k \geq 1$ を $f^k(c) = c$ となるように取る. $f^k(f(c)) = f(f^k(c)) = f(c)$ であるから, $f(c) \in C$ である.

次に, $f$ の $C$ への制限が単射であることを示す. $a, b \in C$ が $f(a) = f(b)$ を満たすとする. $k, l \geq 1$ を $f^k(a) = a, f^l(b) = b$ となるように取ると, $f^{kl}(a) = a, f^{kl}(b) = b$ であるから,

$$a = f^{kl}(a) = f^{kl-1}(f(a)) = f^{kl-1}(f(b)) = f^{kl}(b) = b$$

である. よって, $f$ の $C$ への制限は単射である.

最後に, 全射であることを示す. $c \in C$ とし, $k \geq 1$ を $f^k(c) = c$ となるように取る. $c' := f^{k-1}(c)$ とすると, 前半の議論を繰り返し用いて $c' \in C$ であり, $f(c') = f^k(c) = c$ である. よって, $f$ の $C$ への制限は全射である.

(2) $u_j := f^j(c) ~(0 \leq j < m)$ とする. $0 \leq i < j < m$ で $u_i = u_j$ となるものが存在したとすると, 両辺に $f^{m-j}$ を作用させて $f^{m-j+i}(c) = f^m(c) = c$ を得る. $0 < m - j + i < m$ であるから, これは $m$ の最小性に反する. よって, $u_0, \dots, u_{m-1}$ は相異なる. また, $f$ の定義から $(u_j, u_{j+1}) = (u_j, f(u_j)) \in A ~(0 \leq j < m - 1)$ であり, $(u_{m-1}, u_0) = (f^{m-1}(c), f^m(c)) \in A$ である. よって, $u_0, \dots, u_{m-1}$ はサイクルである.

逆に, $w_0, w_1, \dots, w_{l-1}$ を $c$ を通るサイクルとする. 巡回的に並べ替えて $w_0 = c$ としてよい. 各頂点の出次数は $1$ であるから, $(w_j, w_{j+1}) \in A$ より $w_{j+1} = f(w_j)$ であり, 同様に $w_0 = f(w_{l-1})$ である. よって, $w_j = f^j(c) ~(0 \leq j < l)$ かつ $f^l(c) = c$ である. もし $1 \leq k < l$ で $f^k(c) = c$ となるものがあれば $w_k = w_0$ となり, $w_0, \dots, w_{l-1}$ が相異なることに反する. よって $l = m$ であり, このサイクルは $u_0, \dots, u_{m-1}$ と一致する.

以上より, 各 $c \in C$ を通るサイクルはただ一つである. また, 任意のサイクル $w_0, \dots, w_{l-1}$ について, 上と同様に $w_{j+1} = f(w_j) ~(0 \leq j < l - 1)$, $w_0 = f(w_{l-1})$ であるから, $f^l(w_j) = w_j$ であり, サイクルの頂点は全てサイクル上の頂点である. よって, $D$ のサイクルの頂点集合全体は $C$ を分割する.

(3) $n := \lvert V \rvert$ とする. $v, f(v), \dots, f^n(v)$ は $V$ の $n + 1$ 個の元であるから, 鳩の巣原理より, $0 \leq i < j \leq n$ で $f^i(v) = f^j(v)$ となるものが存在する. このとき $f^{j-i}(f^i(v)) = f^i(v)$ であり, $j - i \geq 1$ であるから, $f^i(v) \in C$ である.

</div>

<div class="definition" markdown="1">

定義 6
---

$V$ を有限集合とし, $D = (V, A)$ を Functional Graph とし, $f: V \to V$ を $D$ に対応する写像とする. また, $C$ をサイクル上の頂点全体の集合とする.

* $v \in V$ に対して, $d(v) := \min \lbrace k \geq 0 \mid f^k(v) \in C \rbrace$ を $v$ の深さ, $r(v) := f^{d(v)}(v)$ を $v$ の根という (命題 5 (3) より well-defined である).
* $c \in C$ に対して, $T(c) := \lbrace v \in V \mid r(v) = c \rbrace$ とする.
* $c \in C$ に対して, $c$ を通るただ一つのサイクルの頂点集合を $Z(c)$ とする (命題 5 (2)).

</div>

サイクル上の頂点 $v$ については $d(v) = 0, r(v) = v$ である. また, $r$ は写像 $V \to C$ であるから, $T(c) ~(c \in C)$ は $V$ を分割する.

<div class="proposition" markdown="1">

命題 7
---

$V$ を有限集合とし, $D = (V, A)$ を Functional Graph とし, $f: V \to V$ を $D$ に対応する写像とする. $c$ をサイクル上の頂点とし, 根が $c$ である頂点全体の集合を $T$ とする. このとき, 以下が成り立つ.

1. $v \in T \setminus \lbrace c \rbrace$ ならば, $f(v) \in T$ であり, $f(v)$ の深さは $v$ の深さより $1$ だけ小さい.
2. $A_T := \lbrace (v, f(v)) \mid v \in T \setminus \lbrace c \rbrace \rbrace$ とすると, 有向グラフ $(T, A_T)$ は $c$ を根とする有向根付き木である. すなわち, $(T, A_T)$ の基礎グラフは木であり, 任意の $v \in T$ について, $v$ から $c$ への $(T, A_T)$ 上の有向路が存在する. また, その長さは $v$ の深さに等しい.

</div>

<div class="proof" markdown="1">

証明
---

深さ, 根を定義 6 の $d, r$ で表し, $C$ をサイクル上の頂点全体の集合とする.

(1) $v \in T \setminus \lbrace c \rbrace$ とする. もし $d(v) = 0$ ならば, $v \in C$ であり $r(v) = v$ であるから $v = c$ となって矛盾する. よって $d(v) \geq 1$ である.

$f^{d(v)-1}(f(v)) = f^{d(v)}(v) \in C$ であるから, $d(f(v)) \leq d(v) - 1$ である. また, ある $k < d(v) - 1$ について $f^k(f(v)) \in C$ であるとすると, $f^{k+1}(v) \in C$ かつ $k + 1 < d(v)$ となり, $d(v)$ の最小性に反する. よって $d(f(v)) = d(v) - 1$ である. さらに,

$$r(f(v)) = f^{d(v)-1}(f(v)) = f^{d(v)}(v) = r(v) = c$$

であるから, $f(v) \in T$ である.

(2) $v \in T$ とし, $v_j := f^j(v) ~(0 \leq j \leq d(v))$ とする. (1) を繰り返し用いると, $0 \leq j \leq d(v)$ について $v_j \in T$ かつ $d(v_j) = d(v) - j$ である. $d(c) = 0$ であるから, $0 \leq j < d(v)$ について $v_j \neq c$ であり, $(v_j, v_{j+1}) = (v_j, f(v_j)) \in A_T$ である. また, $v_{d(v)} = r(v) = c$ である. よって, $v_0, v_1, \dots, v_{d(v)}$ は $v$ から $c$ への長さ $d(v)$ の有向路である. 特に, $(T, A_T)$ の基礎グラフは連結である.

$A_T$ の有向辺 $(v, f(v))$ について, (1) より $d(f(v)) = d(v) - 1 < d(v)$ である. よって, $A_T$ はループを含まず, $(u, w), (w, u)$ の両方を含むこともない. また, 各頂点を始点とする $A_T$ の有向辺は高々 $1$ 本であるから, $A_T$ に重複する有向辺はない. したがって, $(T, A_T)$ の基礎グラフは, $\lvert T \rvert$ 頂点, $\lvert T \rvert - 1$ 辺の連結な単純グラフであり, 木である.

</div>

<div class="theorem" markdown="1">

定理 8
---

$V$ を有限集合とし, $D = (V, A)$ を Functional Graph とし, $f: V \to V$ を $D$ に対応する写像とする. $W$ を $D$ の弱連結成分の頂点集合とする. このとき, 以下が成り立つ.

1. $W$ に含まれる $D$ のサイクルはただ一つである.
2. そのサイクルの頂点集合を $Z$ とすると, $W = \lbrace v \in V \mid \text{ある } k \geq 0 \text{ について } f^k(v) \in Z \rbrace$ である.

</div>

<div class="proof" markdown="1">

証明
---

定義 6 の記法を用いる. $D$ のサイクルの頂点集合 $Z$ に対して,

$$W_Z := \lbrace v \in V \mid r(v) \in Z \rbrace = \bigcup_{c \in Z} T(c)$$

とする. 命題 5 (2) より, サイクルの頂点集合全体は $C$ を分割するから, $W_Z$ 全体は $V$ を分割する. 以下, 各 $W_Z$ が弱連結成分であること, $W_Z$ に含まれるサイクルは $Z$ を頂点集合とするものただ一つであること, $W_Z = \lbrace v \in V \mid \text{ある } k \geq 0 \text{ について } f^k(v) \in Z \rbrace$ であることを示す.

まず, 異なる $W_Z$ の間に有向辺がないことを示す. $(v, f(v)) \in A$ とする. $v \notin C$ のときは, $v \in T(r(v)) \setminus \lbrace r(v) \rbrace$ であるから, 命題 7 (1) より $r(f(v)) = r(v)$ である. $v \in C$ のときは, 命題 5 (1) より $f(v) \in C$ であり, $r(f(v)) = f(v) \in Z(v) = Z(r(v))$ である. いずれの場合も $v$ と $f(v)$ は同じ $W_Z$ に属する. よって, 各弱連結成分はある $W_Z$ に含まれる.

次に, $W_Z$ の基礎グラフが連結であることを示す. 命題 7 (2) より, 各 $v \in W_Z$ から $r(v) \in Z$ への有向路が存在し, その頂点は全て $T(r(v)) \subset W_Z$ に属する. また, $Z$ の頂点同士はサイクルの有向辺で結ばれている. よって $W_Z$ は連結であり, 前段と合わせて, $W_Z$ は弱連結成分の頂点集合である.

$W_Z$ に含まれるサイクルの頂点集合を $Z'$ とすると, $Z' \subset C$ であるから, $c' \in Z'$ について $r(c') = c' \in Z$ である. よって $Z \cap Z' \neq \emptyset$ であり, 命題 5 (2) よりサイクルの頂点集合全体は $C$ を分割するから, $Z' = Z$ である. 同じく命題 5 (2) より, 頂点集合が $Z$ であるサイクルはただ一つである. よって (1) が成り立つ.

最後に (2) を示す. $v \in W_Z$ ならば, $f^{d(v)}(v) = r(v) \in Z$ である. 逆に, ある $k \geq 0$ について $f^k(v) \in Z \subset C$ であるとすると, $d(v)$ の最小性より $k \geq d(v)$ であり, $f^k(v) = f^{k - d(v)}(r(v)) \in Z(r(v))$ である. よって $Z \cap Z(r(v)) \neq \emptyset$ であるから, $Z(r(v)) = Z$, すなわち $r(v) \in Z$ であり, $v \in W_Z$ である.

</div>

すなわち, Functional Graph の各弱連結成分は, ただ一つのサイクルと, その各頂点 $c$ を根とし, 根へ向かう向きに有向辺が付いた有向根付き木 $T(c)$ (命題 7) から成る.

### クエリの処理について

続いて, $f^k(x)$ の求め方を述べる. 移動先は, $k$ が深さ未満であれば木の上, 深さ以上であればサイクルの上にある.

<div class="proposition" markdown="1">

命題 9
---

$V$ を有限集合とし, $D = (V, A)$ を Functional Graph, $f: V \to V$ を $D$ に対応する写像とする. $x \in V$ の深さを $d$, 根を $r$ とし, $r$ を通るサイクルを $c_0, c_1, \dots, c_{m-1}$ ($f(c_i) = c_{i+1} ~(0 \leq i < m - 1)$, $f(c_{m-1}) = c_0$) として, $r = c_j$ とする. このとき, 整数 $k \geq 0$ について以下が成り立つ.

1. $k < d$ ならば, $f^k(x)$ はサイクル上の頂点ではなく, その根は $r$, 深さは $d - k$ である.
2. $k \geq d$ ならば, $f^k(x) = c_{(j + k - d) \bmod m}$ である. 特に, $f^k(x)$ はサイクル上の頂点である.

</div>

<div class="proof" markdown="1">

証明
---

深さ, 根を定義 6 の記号で表す.

(1) $0 \leq i \leq k$ について, $r(f^i(x)) = r$ かつ $d(f^i(x)) = d - i$ であることを $i$ に関する帰納法で示す. $i = 0$ のときは明らかである. $i < k$ について成り立つとすると, $d(f^i(x)) = d - i > d - k > 0$ であるから, $f^i(x) \neq r$ である. よって, 命題 7 (1) より $r(f^{i+1}(x)) = r$ かつ $d(f^{i+1}(x)) = d - i - 1$ である.

特に $d(f^k(x)) = d - k > 0$ であるから, $f^k(x)$ はサイクル上の頂点ではない.

(2) $f^k(x) = f^{k-d}(f^d(x)) = f^{k-d}(r) = f^{k-d}(c_j)$ である. $f(c_i) = c_{(i + 1) \bmod m} ~(0 \leq i < m)$ であるから, $n \geq 0$ に関する帰納法により $f^n(c_j) = c_{(j + n) \bmod m}$ である. $n = k - d$ とすればよい.

</div>

命題 9 (2) より, $k \geq d(x)$ の場合は, 根 $r(x)$ を含むサイクルとその中での $r(x)$ の位置を前計算しておけば, $f^k(x)$ を $O(1)$ 時間で求められる.

$k < d(x)$ の場合は, 命題 9 (1) より, $f^k(x)$ は $x$ を含む木 $T(r(x))$ の中で $x$ から根の方向へ $k$ 回移動した頂点である. これは次の命題によって, 木ごとのダブリングで求められる.

<div class="proposition" markdown="1">

命題 10
---

$V$ を有限集合とし, $D = (V, A)$ を Functional Graph, $f: V \to V$ を $D$ に対応する写像とする. $c$ をサイクル上の頂点とし, 根が $c$ である頂点全体の集合を $T$ とする. 写像 $g: T \to T$ を

$$g(v) := \begin{cases} f(v) & (v \neq c) \\ c & (v = c) \end{cases}$$

で定める. このとき, $v \in T$ と $0 \leq k \leq d(v)$ を満たす整数 $k$ について, $g^k(v) = f^k(v)$ である. ただし, $d(v)$ は $v$ の深さである.

</div>

<div class="proof" markdown="1">

証明
---

命題 7 (1) より, $v \in T \setminus \lbrace c \rbrace$ ならば $f(v) \in T$ であるから, $g$ は $T$ から $T$ への写像として定まる.

$k$ に関する帰納法で示す. $k = 0$ のときは明らかである. $k < d(v)$ について $g^k(v) = f^k(v)$ が成り立つとする. 命題 9 (1) より $f^k(v)$ はサイクル上の頂点ではないから, $f^k(v) \neq c$ である. よって, $g^{k+1}(v) = g(f^k(v)) = f(f^k(v)) = f^{k+1}(v)$ である.

</div>

以上をもとに, 次のようにして $f^k(x)$ を求める.

**前計算.** サイクル上の頂点の集合 $C$ と各サイクルを求め, 各 $c \in C$ について木 $T(c)$ とその各頂点の深さを求める. これらは $O(N)$ 時間で求められる. さらに, 各 $c \in C$ について, $T(c)$ の頂点の深さの最大値を $D_c$, $L_c := \max(1, \lfloor \log_2 D_c \rfloor + 1)$ ($D_c = 0$ のときは $L_c = 1$) とし, 命題 10 の $g$ について $g^{2^b} ~(0 \leq b < L_c)$ の表を

$$g^{2^b} = g^{2^{b-1}} \circ g^{2^{b-1}} \quad (1 \leq b < L_c)$$

により作る. $D_c \leq N - 1$ より $L_c = O(\log N)$ であるから, この表は $O(\lvert T(c) \rvert \log N)$ 時間で作れる. 定義 6 の後で述べたように $T(c) ~(c \in C)$ は $V$ を分割するので, 前計算全体の計算量は $O(N \log N)$ 時間である.

**クエリ.** $d := d(x)$ とする.

* $k \geq d$ のとき, 命題 9 (2) より $O(1)$ 時間で求められる.
* $k < d$ のとき, $k$ を $2$ 進展開して $k = 2^{b_1} + 2^{b_2} + \dots + 2^{b_s} ~(b_1 < b_2 < \dots < b_s)$ とする. $k < d \leq D_{r(x)}$ より, 各 $b_i$ は $b_i < L_{r(x)}$ を満たす. 命題 10 より

  $$f^k(x) = g^k(x) = g^{2^{b_s}} \circ \dots \circ g^{2^{b_1}} (x)$$

  であるから, 表を $s$ 回引くことで求められる. $s \leq \lfloor \log_2 k \rfloor + 1$ であるから, $O(\log k)$ 時間である.

$d < N$ であるから, いずれの場合も $O(\log N)$ 時間である.

## Contents

以下, $N$ を頂点数とし, 頂点は $0, 1, \dots, N - 1$ で表す. また, $f$ を Functional Graph に対応する写像とし, 深さ $d(x)$, 根 $r(x)$ は定義 6 のものとする.

### Constructor

```cpp
Functional_Graph(const vector<int> &f)
```

* 写像 $f: \lbrace 0, 1, \dots, N - 1 \rbrace \to \lbrace 0, 1, \dots, N - 1 \rbrace$ による Functional Graph を生成する. ただし, $N$ は `f` の長さである.
* サイクルの検出と, サイクル上の各頂点を根とする木 (命題 7) の構築, および木ごとのダブリングの表 (命題 10) の構築を行う.
* **制約**
  * $0 \leq f(x) < N ~(0 \leq x < N)$. 確認は行わない.
* **計算量** : $O(N \log N)$ 時間 (Theory の前計算を参照).

### calculate

```cpp
int F.calculate(int x, ll k) const
```

* $f^k(x)$ を求める.
* $k < d(x)$ のときは, $x$ を含む木の上でダブリングにより $k$ 回移動する (命題 10). $k \geq d(x)$ のときは, 根 $r(x)$ を含むサイクルの上で $k - d(x)$ 回移動する (命題 9 (2)).
* **制約**
  * $0 \leq x < N$.
  * $k \geq 0$. 満たさない場合は `assert` で停止する.
* **計算量** : $O(\log N)$ 時間.
  * 厳密には, $k \geq d(x)$ (すなわち, $f^k(x)$ がサイクル上の頂点) ならば $O(1)$ 時間, $k < d(x)$ ならば $O(\log k)$ 時間 (Theory のクエリを参照).

### is_on_cycle

```cpp
bool F.is_on_cycle(int x) const
```

* $x$ がサイクル上の頂点 (定義 4) かどうかを判定する.
* **制約**
  * $0 \leq x < N$.
* **計算量** : $O(1)$ 時間.

### depth

```cpp
int F.depth(int x) const
```

* $x$ の深さ $d(x)$ を求める.
* **制約**
  * $0 \leq x < N$.
* **計算量** : $O(1)$ 時間.

### root

```cpp
int F.root(int x) const
```

* $x$ の根 $r(x)$ を求める.
* **制約**
  * $0 \leq x < N$.
* **計算量** : $O(1)$ 時間.

### get_cycle_id

```cpp
int F.get_cycle_id(int x) const
```

* $x$ の根 $r(x)$ を含むサイクルの番号を求める. 番号は `get_cycle`, `get_cycles` の添字と対応する.
* 定理 8 より, $2$ 頂点 $x, y$ が同じ弱連結成分に属することと, `F.get_cycle_id(x) == F.get_cycle_id(y)` であることは同値である.
* **制約**
  * $0 \leq x < N$.
* **計算量** : $O(1)$ 時間.

### get_tree_vertices

```cpp
const vector<int> &F.get_tree_vertices(int c) const
```

* サイクル上の頂点 $c$ に対して, $T(c)$ (根が $c$ である頂点全体) を求める.
* 先頭の要素は $c$ である. それ以外の順番は保証しない.
* **制約**
  * $0 \leq c < N$.
  * $c$ はサイクル上の頂点である. 満たさない場合は `assert` で停止する.
* **計算量** : $O(1)$ 時間.

### cycle_count

```cpp
int F.cycle_count() const
```

* サイクルの個数を求める. 定理 8 より, これは弱連結成分の個数に等しい.
* **計算量** : $O(1)$ 時間.

### get_cycle

```cpp
const vector<int> &F.get_cycle(int id) const
```

* 番号 `id` のサイクル $c_0, c_1, \dots, c_{m-1}$ を求める. ここで, $f(c_j) = c_{j+1} ~(0 \leq j < m - 1)$, $f(c_{m-1}) = c_0$ である.
* **制約**
  * `F.cycle_count()` を $M$ として, $0 \leq \mathrm{id} < M$. 確認は行わない.
* **計算量** : $O(1)$ 時間.

### get_cycles

```cpp
vector<vector<int>> F.get_cycles() const
```

* 全てのサイクルを, 番号順に並べたリストとして求める. 各サイクルの形式は `get_cycle` と同じである.
* **計算量** : $O(N)$ 時間.
  * 新しいリストを作って返すため. 特定のサイクルのみが必要な場合は `get_cycle` を用いる.

## History

|日付|内容|
|:---:|:---:|
|2026/11/21| サイクルと木のデータを `Cycle`, `Tree` クラスに再構成 <br> `is_on_cycle`, `depth`, `get_cycle_id`, `get_tree_vertices`, `cycle_count`, `get_cycle` の実装 <br> `get_cycles` の返り値を参照から値に変更 <br> `calculate` で `k` が負のときに `assert` で停止するように変更 <br> ダブリング表の範囲外アクセスと, `calculate` でのダブリング表のコピーを修正 |
|2025/10/26| `root` の実装 |
|2025/10/23| Functional_Graph クラスの実装 <br> `get_cycles` の実装 |
