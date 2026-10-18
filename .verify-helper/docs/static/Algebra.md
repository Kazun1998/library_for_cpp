# 代数的構造

## 代数系

<div class="definition" markdown="1">

定義 1
---

$A$ を集合として, $k$ を非負の整数とする. 写像 $O: A^k \to A$ を $A$ 上の $k$ 項演算という.

</div>

<div class="remark" markdown="1">

注意 2
---

$A$ を集合として, $\*$ を $A$ 上の $2$ 項演算とする.

このとき, $a, b \in A$ に対して, $\*(a, b)$ のことを $a \* b$ と書くこともある.
</div>

<div class="definition" markdown="1">

定義 3
---

$A$ を集合として, $O_1, \dots, O_n$ を $A$ 上の演算とする.

このとき, 組 $(A, O_1, \dots, O_n)$ を代数的構造 (代数系) という.

</div>

## 演算の性質

これ以降, 集合 $A$ に対して, 演算といった場合は $A$ 上の $2$ 項演算とする.

<div class="definition" markdown="1">

定義 4
---

$A$ を集合とする. $A$ 上の演算 $\*$ が以下を満たすとき, 演算 $\*$ は結合則を満たすという.

* 任意の $a, b, c \in A$ に対して, $(a \* b) \* c = a \* (b \* c)$ である.

</div>

<div class="definition" markdown="1">

定義 5
---

$A$ を集合とし, $\*$ を $A$ 上の演算とする.

* $a, b \in A$ に対して, $a \* b = b \* a$ であるとき, $a, b$ は可換であるという.
* 任意の $a, b \in A$ で $a, b$ が可換であるとき, $A$ は $\*$ に関して可換であるという.

</div>

<div class="definition" markdown="1">

定義 6
---

$A$ を集合とし, $\*$ を $A$ 上の演算とする. $e \in A$ が以下を満たすとき, $e$ は $\*$ の単位元であるという.

* 任意の $a \in A$ に対して, $a \* e = e \* a = a$ である.

</div>

<div class="proposition" markdown="1">

命題 7
---

$A$ を集合とし, $\*$ を $A$ 上の演算とする. このとき, $\*$ の単位元は存在するならば一意である.

</div>

<div class="proof" markdown="1">

証明
---

$e, e' \in A$ をともに $\*$ の単位元とする. $e \* e'$ について考える.

* $e$ は単位元なので, $e \* e' = e'$ である.
* $e'$ は単位元なので, $e \* e' = e$ である.

よって, $e = e \* e' = e'$ なので, 単位元は存在するならば一意である.

</div>

## 半群

<div class="definition" markdown="1">

定義 8
---

$S$ を集合, $\*$ を $S$ 上の結合則を満たす演算とする. このとき, 代数系 $(S, \*)$ を半群という.

</div>

### 具体例

以下は単位元をもたない (モノイドではない) 半群の例である.

| $S$ | 二項演算 | 可換則 |
|:---:|:---:|:---:|
| $\mathbb{Z}_{>0}$ | $+$ | 〇 |
| $\mathbb{Z}$ | $\max$ | 〇 |
| 空でない文字列全体 | 連結 | × |

## モノイド

<div class="definition" markdown="1">

定義 9
---

$(M, \*)$ を半群とする. $\*$ に関する単位元が存在するとき, $(M, \*)$ をモノイドという.

</div>

<div class="definition" markdown="1">

定義 10
---

$A$ を集合, $\*$ を $A$ 上の演算, $e \in A$ をその単位元とする. $a \in A$ に対して, $b \in A$ が以下を満たすとき, $b$ は $a$ の ($\*$ に関する) 逆元であるという.

* $a \* b = b \* a = e$ である.

</div>

<div class="proposition" markdown="1">

命題 11
---

$A$ を集合, $\*$ を $A$ 上の結合則を満たし単位元をもつ演算とする. このとき, $a \in A$ の逆元は存在するならば一意である.

</div>

<div class="proof" markdown="1">

証明
---

$e \in A$ を $\*$ の単位元, $b, c \in A$ を $a$ の $\*$ に関する逆元とする. このとき, $b \* a = a \* c = e$ であるから,

$$
\begin{aligned}
b &= b \ast e && (e \text{ は単位元}) \\
  &= b \ast (a \ast c) && (a \ast c = e) \\
  &= (b \ast a) \ast c && (\text{結合則}) \\
  &= e \ast c && (b \ast a = e) \\
  &= c && (e \text{ は単位元})
\end{aligned}
$$

である. よって, $a$ の $\*$ に関する逆元は存在するならば一意である.

</div>

<div class="definition" markdown="1">

定義 12
---

集合 $A$ 上の結合則を満たし単位元をもつ演算 $\ast$ について, $a \in A$ の逆元が存在するとき, その逆元を $a^{-1}$ と書く.

</div>

<div class="proposition" markdown="1">

命題 13
---

$(S, \*)$ を半群として, $e \not \in S$ とする. $M := S \cup \\{ e \\}$ 上の演算 $\*'$ を

  $$ a \ast' b := \begin{cases}
    a \ast b & (a, b \in S) \\
    b & (a = e, b \in S) \\
    a & (a \in S, b = e) \\
    e & (a = b = e)
  \end{cases} $$

で定めると, $(M, \*')$ はモノイドである.

また, $S$ が可換ならば $M$ も可換である.
</div>

<div class="proof" markdown="1">

証明
---

定義より, 任意の $x \in M$ に対して $e \ast' x = x \ast' e = x$ なので, $e$ は $\ast'$ の単位元である.

結合則を示す. $a, b, c \in M$ とする.

* $a, b, c \in S$ のとき, $\ast'$ は $\ast$ と一致し, $S$ の結合則から成り立つ.
* $a = e$ のとき, 両辺とも $b \ast' c$ である.
* $b = e$ のとき, 両辺とも $a \ast' c$ である.
* $c = e$ のとき, 両辺とも $a \ast' b$ である.

よって, $(M, \ast')$ はモノイドである.

また, $S$ が可換とする. $a, b \in S$ のときは $a \ast' b = a \ast b = b \ast a = b \ast' a$ であり, $a, b$ の少なくとも一方が $e$ のときは $e$ が単位元なので $a \ast' b = b \ast' a$ である. よって, $M$ も可換である.

</div>

### 具体例

以下はモノイドの例である. 逆元をもたない元があるので, 群ではない.

| $M$ | 二項演算 | 単位元 | 可換則 |
|:---:|:---:|:---:|:---:|
| $\mathbb{Z}_{\ge 0}$ | $+$ | $0$ | 〇 |
| $\mathbb{Z} \cup \\{ \infty \\}$ | $\min$ | $\infty$ | 〇 |
| $\mathbb{Z} \cup \\{ -\infty \\}$ | $\max$ | $-\infty$ | 〇 |
| 文字列全体 | 連結 | 空文字列 | × |
| $n$ 次正方行列全体 | 行列の積 | 単位行列 | $n \ge 2$ のとき × |

## 群

<div class="definition" markdown="1">

定義 14
---

モノイド $(G, \*)$ について, 任意の元に対する逆元が存在するとき, このモノイドは群であるという.

</div>

<div class="remark" markdown="1">

注意 15
---

$(G, \*)$ を群とする.

* 任意の $a, b \in G$ に対して, $a \* b$ のことを $ab$ と書くことがある.
* そして, $G$ が可換群ならば, $ab$ のことを $a + b$ と書くこともある.

</div>

<div class="proposition" markdown="1">

命題 16
---

$G$ を群とする. このとき, 任意の $a, b, c \in G$ に対して以下が成り立つ.

1. $(a^{-1})^{-1} = a$.
2. $(ab)^{-1} = b^{-1} a^{-1}$.
3. $ab = ac$ ならば $b = c$ であり, $ba = ca$ ならば $b = c$ である (簡約律).
4. $ax = b$ を満たす $x \in G$ はただ $1$ つ存在し, $x = a^{-1} b$ である. 同様に, $xa = b$ を満たす $x \in G$ はただ $1$ つ存在し, $x = b a^{-1}$ である.

</div>

<div class="proof" markdown="1">

証明
---

$e$ を $G$ の単位元とする.

1. $a^{-1} a = a a^{-1} = e$ なので, $a$ は $a^{-1}$ の逆元である. 命題 11 より逆元は一意なので, $(a^{-1})^{-1} = a$ である.
2. 結合則より,

   $$ (ab)(b^{-1} a^{-1}) = a (b b^{-1}) a^{-1} = a a^{-1} = e, \quad (b^{-1} a^{-1})(ab) = b^{-1} (a^{-1} a) b = b^{-1} b = e $$

   なので, $b^{-1} a^{-1}$ は $ab$ の逆元である. 命題 11 より, $(ab)^{-1} = b^{-1} a^{-1}$ である.
3. $ab = ac$ の両辺に左から $a^{-1}$ を掛けると, $b = a^{-1}(ab) = a^{-1}(ac) = c$ である. $ba = ca$ のときは右から $a^{-1}$ を掛ければよい.
4. $a (a^{-1} b) = (a a^{-1}) b = b$ なので, $x = a^{-1} b$ は $ax = b$ を満たす. 逆に $ax = b$ ならば, 左から $a^{-1}$ を掛けて $x = a^{-1} b$ を得るので, 解はこれのみである. $xa = b$ についても, 右から $a^{-1}$ を掛けることで同様に示される.

</div>

### 具体例

| $G$ | 二項演算 | 可換則 |
|:---:|:---:|:---:|
| $\mathbb{Z}$ | $+$ | 〇 |
| $\\{0, 1, \dots, n - 1 \\}$ | $(a + b) \bmod{n} $ | 〇 |
| $\\{1, 2, \dots, n \\}$ における全単射全体 <br> $\mathfrak{S}_n$ | 写像の合成 | $n \ge 3$ のとき × |

## 環

<div class="definition" markdown="1">

定義 17
---

集合 $A$ の $2$ つの演算 $\circ, \bullet$ が以下を満たすとき, $\circ$ を加法, $\bullet$ を乗法とする分配則を満たすという.

* 任意の $a, b, c \in A$ に対して, $a \bullet (b \circ c) = a \bullet b \circ a \bullet c$.
* 任意の $a, b, c \in A$ に対して, $(a \circ b) \bullet c = a \bullet c \circ b \bullet c$.

</div>

<div class="definition" markdown="1">

定義 18
---

代数系 $(R, +, \times)$ について, 以下を満たすとき, この代数系は $+$ を加法, $\times$ を乗法とする環であるという.

* $(R, +)$ は可換群である.
* $(R, \times)$ はモノイドである.
* $+$ を加法, $\times$ を乗法とする分配則を満たす.

</div>

<div class="remark" markdown="1">

注意 19
---

環 $R$ に対して, $R$ の加法的単位元を $0$, 乗法的単位元を $1$ と書くことが多い.

また, $a \in R$ における加法的逆元を $-a$ と書く.
</div>

<div class="proposition" markdown="1">

命題 20
---

$R$ を環とする. このとき, 任意の $a, b \in R$ に対して以下が成り立つ.

1. $0a = a0 = 0$.
2. $(-a)b = a(-b) = -(ab)$.
3. $(-1)a = -a$.
4. $0 = 1$ ならば $R = \\{ 0 \\}$ である.

</div>

<div class="proof" markdown="1">

証明
---

1. 分配則より $0a = (0 + 0)a = 0a + 0a$ なので, 両辺に $-(0a)$ を加えて $0a = 0$ を得る. $a0 = 0$ も同様である.
2. 分配則と (1) より $ab + (-a)b = (a + (-a))b = 0b = 0$ なので, 命題 11 ($(R, +)$ における逆元の一意性) から $(-a)b = -(ab)$ である. $a(-b) = -(ab)$ も同様である.
3. (2) より $(-1)a = -(1a) = -a$ である.
4. $0 = 1$ ならば, 任意の $a \in R$ に対して $a = a1 = a0 = 0$ である.

</div>

<div class="definition" markdown="1">

定義 21
---

環 $(R, +, \times)$ に対して,

$$ R^\times := \{ a \in R \mid \exists b \in R ~\textrm{s.t.}~ ab=ba = 1 \} $$

として, $R$ の乗法群という.

</div>

<div class="proposition" markdown="1">

命題 22
---

環 $R$ に対して, $R^\times$ は乗法 $\times$ に関して群である.

</div>

<div class="proof" markdown="1">

証明
---

* $1 \cdot 1 = 1$ なので, $1 \in R^\times$ である.
* $a, a' \in R^\times$ とし, それぞれの逆元を $b, b'$ とする. このとき,

  $$ (aa')(b'b) = a (a'b') b = ab = 1, \quad (b'b)(aa') = b' (ba) a' = b'a' = 1 $$

  なので, $aa' \in R^\times$ である.
* $a \in R^\times$ の逆元を $b$ とすると, $ab = ba = 1$ なので $b \in R^\times$ である. また, 命題 11 よりこの $b$ が $a$ の逆元である.

結合則は $R$ の乗法から従い, $1$ が単位元であることも明らかなので, $R^\times$ は群である.

</div>


### 具体例

| $R$ | 加法・乗法 | 乗法の可換則 |
|:---:|:---:|:---:|
| $\mathbb{Z}$ | 通常の和・積 | 〇 |
| $\\{0, 1, \dots, n - 1 \\}$ | $\bmod{n}$ での和・積 | 〇 |
| $\mathbb{R}[x]$ | 多項式の和・積 | 〇 |
| $n$ 次正方行列全体 | 行列の和・積 | $n \ge 2$ のとき × |

## 体

<div class="definition" markdown="1">

定義 23
---

可換環 $(F, +, \times)$ について, $F^\times = F \setminus \\{ 0 \\}$ が成り立つとき, $F$ は体であるという.

</div>

<div class="proposition" markdown="1">

命題 24
---

$F$ を体とする.

1. $0 \ne 1$ である.
2. $a, b \in F$ が $ab = 0$ を満たすならば, $a = 0$ または $b = 0$ である.

</div>

<div class="proof" markdown="1">

証明
---

1. $0 = 1$ と仮定すると, 命題 20 より $F = \\{ 0 \\}$ である. このとき $0 \cdot 0 = 0 = 1$ なので $F^\times = \\{ 0 \\}$ であり, $F^\times = F \setminus \\{ 0 \\} = \emptyset$ に矛盾する. よって, $0 \ne 1$ である.
2. $a \ne 0$ とする. $a \in F \setminus \\{ 0 \\} = F^\times$ なので, $a$ の逆元 $a^{-1}$ が存在する. 命題 20 より,

  $$ b = (a^{-1} a) b = a^{-1} (ab) = a^{-1} \cdot 0 = 0 $$

  である. よって, $a = 0$ または $b = 0$ である.

</div>

### 具体例

| $F$ | 加法・乗法 | 備考 |
|:---:|:---:|:---:|
| $\mathbb{Q}$, $\mathbb{R}$, $\mathbb{C}$ | 通常の和・積 | |
| $\\{0, 1, \dots, p - 1 \\}$ ($p$ は素数) | $\bmod{p}$ での和・積 | 有限体 $\mathbb{F}_p$ |

$\mathbb{Z}$ は体ではない ($2$ は乗法的逆元をもたない). また, $n$ が合成数のとき, $\{0, 1, \dots, n - 1 \}$ は $\bmod{n}$ での和・積に関して体ではない ($n = ab$ ($1 < a, b < n$) とすると $ab \equiv 0$ であり, 命題 24 に反する).
