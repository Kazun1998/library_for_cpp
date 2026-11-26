---
title: Gauss 整数
documentation_of: //Algebra/Gaussian_Integer.hpp
---

## Outline

Gauss 整数 $a + bi$ ($a, b \in \mathbb{Z}$) に対して, 四則演算 (加法・減法・乗法と, 余り付きの除法), 共役, ノルムの計算を行う. また, 2 つの Gauss 整数 $\alpha, \beta$ の最大公約数を求める.

除法は商の実部と虚部を四捨五入することで行い, 余りのノルムは割る数のノルムの半分以下になる. 最大公約数は Euclid の互除法で求め, 計算量は $\beta \neq 0$ のとき $O(\log N(\beta))$ である (ただし, $N(\beta)$ は $\beta$ のノルム).

## Theory

このページにおいて, $\mathbb{Z}$ を整数環, $i \in \mathbb{C}$ を虚数単位とする.

#### Gauss 整数の定義と基本的性質

<div class="definition" markdown="1">

定義 1
---

$\mathbb{Z}$ 上 $i$ で生成される $\mathbb{C}$ の部分環 $\mathbb{Z}[i]$ を Gauss 整数環といい, $\mathbb{Z}[i]$ の元を Gauss 整数という.

</div>

<div class="proposition" markdown="1">

命題 2
---

$$ \mathbb{Z}[i] = \lbrace a + bi \in \mathbb{C} \mid a, b \in \mathbb{Z} \rbrace $$

である.

</div>

<div class="proof" markdown="1">

証明
---

$S \subset \mathbb{C}$ を

$$ S := \lbrace a + bi \in \mathbb{C} \mid a, b \in \mathbb{Z} \rbrace $$

とおく. $\mathbb{Z}[i] = S$ を示す.

($\supset$) $a, b \in \mathbb{Z}$ とする. $\mathbb{Z}[i]$ は $a, b \in \mathbb{Z}$ と $i$ を含む環であるから, 乗法と加法で閉じていることより $a + bi \in \mathbb{Z}[i]$ である. よって, $S \subset \mathbb{Z}[i]$ である.

($\subset$) $S$ が $\mathbb{Z}$ と $i$ を含む $\mathbb{C}$ の部分環であることを示す.

まず, $a \in \mathbb{Z}$ に対して $a = a + 0i \in S$ であり, $i = 0 + 1i \in S$ である. 特に $1 \in S$ である.

次に, $\alpha = a + bi, \beta = c + di \in S$ ($a, b, c, d \in \mathbb{Z}$) とする. $\mathbb{Z}$ は加法・減法・乗法で閉じているので,

$$ \alpha - \beta = (a - c) + (b - d) i \in S $$

であり, $i^2 = -1$ より

$$ \alpha \beta = ac + adi + bci + bd i^2 = (ac - bd) + (ad + bc) i \in S $$

である.

以上より, $S$ は $1$ を含み, 減法と乗法で閉じているので, $\mathbb{C}$ の部分環である. さらに $S$ は $\mathbb{Z}$ と $i$ を含む. $\mathbb{Z}[i]$ は $\mathbb{Z}$ と $i$ を含む $\mathbb{C}$ の部分環のうち最小のものであるから, $\mathbb{Z}[i] \subset S$ である.

したがって, $\mathbb{Z}[i] = S$ である.

</div>

命題 2 より, 任意の $\alpha \in \mathbb{Z}[i]$ は $a, b \in \mathbb{Z}$ を用いて $\alpha = a + bi$ と表せる. さらに, $a = \operatorname{Re} \alpha, b = \operatorname{Im} \alpha$ であるから, このような $a, b$ は $\alpha$ に対して一意に定まる.

<div class="definition" markdown="1">

定義 3
---

$\alpha = a + bi \in \mathbb{Z}[i]$ ($a, b \in \mathbb{Z}$) に対して, $\alpha$ の共役 $\overline{\alpha}$ を

$$ \overline{\alpha} := a - bi $$

で定める.

</div>

命題 2 より $\overline{\alpha} \in \mathbb{Z}[i]$ であり, $\overline{\alpha}$ は $\alpha$ の複素共役と一致する.

#### Gauss 整数環上のノルム

<div class="definition" markdown="1">

定義 4
---

$\alpha \in \mathbb{Z}[i]$ に対して, $\alpha$ のノルム $N(\alpha)$ を

$$ N(\alpha) := \lvert \alpha \rvert^2 $$

で定める. ただし, $\lvert \alpha \rvert$ は $\alpha$ の複素数としての絶対値である.

</div>

<div class="proposition" markdown="1">

命題 5
---

$\alpha, \beta \in \mathbb{Z}[i]$ とし, $\alpha = a + bi$ ($a, b \in \mathbb{Z}$) とする. このとき, 以下が成り立つ.

* (1) $N(\alpha) = a^2 + b^2$ である. 特に, $N(\alpha)$ は非負整数である.
* (2) $N(\alpha) = 0$ であることと $\alpha = 0$ であることは同値である.
* (3) $N(\alpha \beta) = N(\alpha) N(\beta)$ である.

</div>

<div class="proof" markdown="1">

証明
---

(1) 複素数の絶対値の定義より, $N(\alpha) = \lvert a + bi \rvert^2 = a^2 + b^2$ である. $a, b \in \mathbb{Z}$ より, これは非負整数である.

(2) 複素数の絶対値について, $\lvert \alpha \rvert = 0$ であることと $\alpha = 0$ であることは同値である.

(3) 複素数の絶対値について $\lvert \alpha \beta \rvert = \lvert \alpha \rvert \lvert \beta \rvert$ であるから, 両辺を $2$ 乗して $N(\alpha \beta) = N(\alpha) N(\beta)$ である.

</div>

#### Gauss 整数環上の整除と単数

<div class="definition" markdown="1">

定義 6
---

$\alpha, \beta \in \mathbb{Z}[i]$ とする. ある $\gamma \in \mathbb{Z}[i]$ が存在して $\alpha = \beta \gamma$ となるとき, $\beta$ は $\alpha$ を割り切るといい, $\beta \mid \alpha$ と書く. このとき, $\beta$ を $\alpha$ の約数, $\alpha$ を $\beta$ の倍数という.

</div>

定義から, 任意の $\beta \in \mathbb{Z}[i]$ に対して $\beta \mid 0$ である ($0 = \beta \cdot 0$). また, $0 \mid \alpha$ であることと $\alpha = 0$ であることは同値である.

<div class="proposition" markdown="1">

命題 7
---

$\alpha, \beta \in \mathbb{Z}[i]$ が $\beta \mid \alpha$ を満たすならば, 整数として $N(\beta) \mid N(\alpha)$ である.

</div>

<div class="proof" markdown="1">

証明
---

$\alpha = \beta \gamma$ ($\gamma \in \mathbb{Z}[i]$) とすると, 命題 5 (3) より $N(\alpha) = N(\beta) N(\gamma)$ である. 命題 5 (1) より $N(\gamma)$ は整数であるから, $N(\beta) \mid N(\alpha)$ である.

</div>

<div class="definition" markdown="1">

定義 8
---

$1$ の $\mathbb{Z}[i]$ 上の約数を単数という.

</div>

<div class="proposition" markdown="1">

命題 9
---

$\varepsilon \in \mathbb{Z}[i]$ に対して, 以下は同値である.

* (a) $\varepsilon$ は単数である.
* (b) $N(\varepsilon) = 1$ である.
* (c) $\varepsilon \in \lbrace 1, -1, i, -i \rbrace$ である.

</div>

<div class="proof" markdown="1">

証明
---

(a) $\Rightarrow$ (b): $\varepsilon \mid 1$ であるから, 命題 7 より整数として $N(\varepsilon) \mid N(1) = 1$ である. 命題 5 (1) より $N(\varepsilon)$ は非負整数であるから, $N(\varepsilon) = 1$ である.

(b) $\Rightarrow$ (c): $\varepsilon = a + bi$ ($a, b \in \mathbb{Z}$) とすると, 命題 5 (1) より $a^2 + b^2 = 1$ である. $a, b$ は整数であるから, $(a^2, b^2) = (1, 0), (0, 1)$ のいずれかであり, $(a, b) = (\pm 1, 0), (0, \pm 1)$ である. すなわち, $\varepsilon \in \lbrace 1, -1, i, -i \rbrace$ である.

(c) $\Rightarrow$ (a): $1 = 1 \cdot 1 = (-1) \cdot (-1) = i \cdot (-i) = (-i) \cdot i$ であるから, $1, -1, i, -i$ はいずれも $1$ を割り切る. よって, いずれも単数である.

</div>

<div class="definition" markdown="1">

定義 10
---

$\alpha, \beta \in \mathbb{Z}[i]$ とする. $\alpha \mid \beta$ かつ $\beta \mid \alpha$ であるとき, $\alpha$ と $\beta$ は同伴であるという.

</div>

<div class="proposition" markdown="1">

命題 11
---

$\alpha, \beta \in \mathbb{Z}[i]$ に対して, 以下は同値である.

* (a) $\alpha$ と $\beta$ は同伴である.
* (b) ある単数 $\varepsilon$ が存在して $\alpha = \varepsilon \beta$ である.

</div>

<div class="proof" markdown="1">

証明
---

(a) $\Rightarrow$ (b): $\beta = \alpha \gamma, \alpha = \beta \delta$ ($\gamma, \delta \in \mathbb{Z}[i]$) とする.

$\alpha = 0$ のとき, $\beta = \alpha \gamma = 0$ であるから, 単数 $1$ について $\alpha = 1 \cdot \beta$ である.

$\alpha \neq 0$ のとき, $\alpha = \beta \delta = \alpha \gamma \delta$ である. $\mathbb{C}$ において両辺を $\alpha$ で割ると $\gamma \delta = 1$ であるから, $\delta \mid 1$ であり, $\delta$ は単数である. よって, 単数 $\delta$ について $\alpha = \delta \beta$ である.

(b) $\Rightarrow$ (a): 単数 $\varepsilon$ を用いて $\alpha = \varepsilon \beta$ とすると, $\beta \mid \alpha$ である. また, $\varepsilon \mid 1$ より $\varepsilon \eta = 1$ となる $\eta \in \mathbb{Z}[i]$ が存在し, $\beta = \eta \varepsilon \beta = \eta \alpha$ であるから, $\alpha \mid \beta$ である. よって, $\alpha$ と $\beta$ は同伴である.

</div>

命題 9, 11 より, $\alpha$ と同伴な元は $\alpha, -\alpha, i \alpha, -i \alpha$ の高々 $4$ 個である.

#### Gauss 整数環上の最大公約数

<div class="definition" markdown="1">

定義 12
---

$\alpha, \beta \in \mathbb{Z}[i]$ とする.

* $\delta \mid \alpha$ かつ $\delta \mid \beta$ を満たす $\delta \in \mathbb{Z}[i]$ を, $\alpha$ と $\beta$ の公約数という.
* $\alpha$ と $\beta$ の公約数 $g$ であって, $\alpha$ と $\beta$ の任意の公約数 $\delta$ に対して $\delta \mid g$ を満たすものを, $\alpha$ と $\beta$ の最大公約数という.

</div>

<div class="proposition" markdown="1">

命題 13
---

$\alpha, \beta \in \mathbb{Z}[i]$ とし, $g$ を $\alpha$ と $\beta$ の最大公約数とする. このとき, $g' \in \mathbb{Z}[i]$ に対して, 以下は同値である.

* (a) $g'$ は $\alpha$ と $\beta$ の最大公約数である.
* (b) $g'$ と $g$ は同伴である.

</div>

<div class="proof" markdown="1">

証明
---

(a) $\Rightarrow$ (b): $g, g'$ はともに最大公約数であり, 特に公約数であるから, 最大公約数の定義より $g' \mid g$ かつ $g \mid g'$ である. よって, $g'$ と $g$ は同伴である.

(b) $\Rightarrow$ (a): 同伴の定義より $g \mid g'$ かつ $g' \mid g$ である.

$g' \mid g$ かつ $g \mid \alpha, g \mid \beta$ であるから, $g' \mid \alpha, g' \mid \beta$ であり, $g'$ は公約数である.

また, $\alpha$ と $\beta$ の任意の公約数 $\delta$ に対して, $g$ が最大公約数であることより $\delta \mid g$ であり, $g \mid g'$ と合わせて $\delta \mid g'$ である.

よって, $g'$ は $\alpha$ と $\beta$ の最大公約数である.

</div>

命題 13 より, 最大公約数が存在するならば, それは同伴の違いを除いて一意に定まる. 最大公約数が常に存在することは, 後で Euclid の互除法によって示す.

なお, 任意の $\delta \in \mathbb{Z}[i]$ に対して $\delta \mid 0$ であるから, $0$ と $0$ の最大公約数は $0$ であり, $0$ と同伴な元は $0$ のみである.

#### Gauss 整数環上の除法

整数環 $\mathbb{Z}$ と同様に, Gauss 整数環 $\mathbb{Z}[i]$ においても, 余りのノルムが割る数のノルムより小さくなるような除法が存在する.

<div class="theorem" markdown="1">

定理 14
---

$\alpha, \beta \in \mathbb{Z}[i]$ とし, $\beta \neq 0$ とする. このとき, 以下を満たす $q, r \in \mathbb{Z}[i]$ が存在する.

* $\alpha = \beta q + r$
* $N(r) \leq \dfrac{1}{2} N(\beta)$

特に, $N(r) < N(\beta)$ である.

</div>

<div class="proof" markdown="1">

証明
---

$q \in \mathbb{Z}[i]$ に対して $r := \alpha - \beta q$ とおくと, $r \in \mathbb{Z}[i]$ であり, $\alpha = \beta q + r$ が成り立つ. $\beta \neq 0$ より, $\mathbb{C}$ において

$$ N(r) = \lvert \alpha - \beta q \rvert^2 = \lvert \beta \rvert^2 \left\lvert \frac{\alpha}{\beta} - q \right\rvert^2 = N(\beta) \left\lvert \frac{\alpha}{\beta} - q \right\rvert^2 $$

である. よって, $N(r)$ を小さくするには, $q$ を複素数 $\dfrac{\alpha}{\beta}$ になるべく近くとればよい.

命題 5 (2) より $N(\beta) \neq 0$ である. また, 定義 3 の直後に述べたように $\overline{\beta}$ は $\beta$ の複素共役であるから, $\beta \overline{\beta} = \lvert \beta \rvert^2 = N(\beta)$ である. よって,

$$ \frac{\alpha}{\beta} = \frac{\alpha \overline{\beta}}{\beta \overline{\beta}} = \frac{\alpha \overline{\beta}}{N(\beta)} $$

である. $\alpha \overline{\beta} = s + ti$ ($s, t \in \mathbb{Z}$) とおき, $x := \dfrac{s}{N(\beta)}, y := \dfrac{t}{N(\beta)}$ とすると, $\dfrac{\alpha}{\beta} = x + yi$ ($x, y \in \mathbb{R}$) である.

ここで, $\lvert x - k \rvert \leq \dfrac{1}{2}, \lvert y - l \rvert \leq \dfrac{1}{2}$ を満たす整数 $k, l$ をとり (例えば, $x, y$ に最も近い整数をとればよい), $q := k + li \in \mathbb{Z}[i]$ とする. このとき,

$$ \left\lvert \frac{\alpha}{\beta} - q \right\rvert^2 = (x - k)^2 + (y - l)^2 \leq \frac{1}{4} + \frac{1}{4} = \frac{1}{2} $$

であるから,

$$ N(r) = N(\beta) \left\lvert \frac{\alpha}{\beta} - q \right\rvert^2 \leq \frac{1}{2} N(\beta) $$

である.

さらに, $N(\beta) > 0$ であるから, $N(r) \leq \dfrac{1}{2} N(\beta) < N(\beta)$ である.

</div>

定理 14 の証明では, 商 $q$ の実部と虚部を $x, y$ の近くにある整数から選んだ. 実装では, この選び方を次のように固定する.

<div class="definition" markdown="1">

定義 15
---

実数 $x$ に対して, $x$ の四捨五入 $\operatorname{round}(x)$ を

$$ \operatorname{round}(x) := \left\lfloor x + \frac{1}{2} \right\rfloor $$

で定める.

</div>

$\operatorname{round}(x)$ は $x$ に最も近い整数であり, そのような整数が $2$ つある場合 ($x$ の小数部分がちょうど $\dfrac{1}{2}$ の場合) は大きい方である. 特に, $\lvert x - \operatorname{round}(x) \rvert \leq \dfrac{1}{2}$ を満たす.

次の系によって, 商 $q$ と余り $r$ を整数の演算のみで具体的に計算することが可能になる.

<div class="corollary" markdown="1">

系 16
---

$\alpha = a + bi, \beta = c + di \in \mathbb{Z}[i]$ ($a, b, c, d \in \mathbb{Z}$) とし, $\beta \neq 0$ とする. $n := N(\beta) = c^2 + d^2$ とし,

$$ \begin{aligned} q &:= \operatorname{round} \left( \frac{ac + bd}{n} \right) + \operatorname{round} \left( \frac{bc - ad}{n} \right) i, \\ r &:= \alpha - \beta q \end{aligned} $$

とおく. このとき, $q, r \in \mathbb{Z}[i]$ であり, $\alpha = \beta q + r$ かつ $N(r) \leq \dfrac{1}{2} N(\beta)$ を満たす.

</div>

<div class="proof" markdown="1">

証明
---

$\alpha \overline{\beta} = (a + bi)(c - di) = (ac + bd) + (bc - ad) i$ であるから, 定理 14 の証明の記号で $s = ac + bd, t = bc - ad$ である. $x = \dfrac{s}{n}, y = \dfrac{t}{n}$ に対して $k := \operatorname{round}(x), l := \operatorname{round}(y)$ とすると, 定義 15 の直後に述べたことより $\lvert x - k \rvert \leq \dfrac{1}{2}, \lvert y - l \rvert \leq \dfrac{1}{2}$ であるから, 定理 14 の証明により $q = k + li$ と $r = \alpha - \beta q$ は条件を満たす.

</div>

<div class="remark" markdown="1">

注意 17
---

定理 14 の $q, r$ は一意とは限らない. 例えば, $\alpha = 1, \beta = 2$ のとき,

$$ 1 = 2 \cdot 0 + 1 = 2 \cdot 1 + (-1) $$

であり, $(q, r) = (0, 1), (1, -1)$ はどちらも $N(r) = 1 \leq \dfrac{1}{2} N(2) = 2$ を満たす. 系 16 の $q$ は, このうちの $1$ つを四捨五入によって選んだものである (この例では $\operatorname{round} \left( \dfrac{1}{2} \right) = 1$ より $(q, r) = (1, -1)$).

</div>

#### Euclid の互除法

定理 14 の除法を繰り返すことで, 整数環 $\mathbb{Z}$ と同様に, 最大公約数を求めることができる. まず, 次の $2$ つの命題を準備する.

<div class="proposition" markdown="1">

命題 18
---

$\alpha, \beta, q, r \in \mathbb{Z}[i]$ が $\alpha = \beta q + r$ を満たすとする. このとき, $\alpha$ と $\beta$ の公約数全体と, $\beta$ と $r$ の公約数全体は一致する. 特に, $g \in \mathbb{Z}[i]$ に対して, 以下は同値である.

* (a) $g$ は $\alpha$ と $\beta$ の最大公約数である.
* (b) $g$ は $\beta$ と $r$ の最大公約数である.

</div>

<div class="proof" markdown="1">

証明
---

$\delta$ を $\alpha$ と $\beta$ の公約数とし, $\alpha = \delta \alpha', \beta = \delta \beta'$ ($\alpha', \beta' \in \mathbb{Z}[i]$) とする. このとき, $r = \alpha - \beta q = \delta (\alpha' - \beta' q)$ であるから, $\delta \mid r$ である. よって, $\delta$ は $\beta$ と $r$ の公約数である.

逆に, $\delta$ を $\beta$ と $r$ の公約数とし, $\beta = \delta \beta', r = \delta r'$ ($\beta', r' \in \mathbb{Z}[i]$) とする. このとき, $\alpha = \beta q + r = \delta (\beta' q + r')$ であるから, $\delta \mid \alpha$ である. よって, $\delta$ は $\alpha$ と $\beta$ の公約数である.

最大公約数は公約数全体のみによって定まるので, (a) と (b) は同値である.

</div>

<div class="proposition" markdown="1">

命題 19
---

任意の $\alpha \in \mathbb{Z}[i]$ に対して, $\alpha$ は $\alpha$ と $0$ の最大公約数である.

</div>

<div class="proof" markdown="1">

証明
---

$\alpha \mid \alpha$ かつ $\alpha \mid 0$ であるから, $\alpha$ は $\alpha$ と $0$ の公約数である. また, $\alpha$ と $0$ の任意の公約数 $\delta$ は $\delta \mid \alpha$ を満たす. よって, $\alpha$ は $\alpha$ と $0$ の最大公約数である.

</div>

$\alpha, \beta \in \mathbb{Z}[i]$ に対して, $\mathbb{Z}[i]$ の列 $\alpha_0, \alpha_1, \alpha_2, \dots$ を次のように定める.

* $\alpha_0 := \alpha, \alpha_1 := \beta$ とする.
* $k \geq 0$ に対して, $\alpha_{k+1} \neq 0$ ならば, 系 16 によって $\alpha_k$ を $\alpha_{k+1}$ で割った余りを $\alpha_{k+2}$ とする. $\alpha_{k+1} = 0$ ならば, そこで列を終える.

これを Euclid の互除法という.

<div class="theorem" markdown="1">

定理 20
---

$\alpha, \beta \in \mathbb{Z}[i]$ とし, $\alpha_0, \alpha_1, \dots$ を Euclid の互除法で定まる列とする. このとき, 以下が成り立つ.

* (1) $\alpha_{K+1} = 0$ となる $K \geq 0$ が存在する. 以下, $K$ をそのような最小のものとする.
* (2) $\alpha_K$ は $\alpha$ と $\beta$ の最大公約数である.
* (3) $\beta \neq 0$ ならば, $K \leq \log_2 N(\beta) + 1$ である.

</div>

<div class="proof" markdown="1">

証明
---

(1) $\beta = 0$ のときは $K = 0$ である. $\beta \neq 0$ とする. $\alpha_1, \dots, \alpha_{k+1}$ がいずれも $0$ でないとき, 系 16 より

$$ N(\alpha_{k+2}) \leq \frac{1}{2} N(\alpha_{k+1}) $$

である. これを繰り返し用いると, $\alpha_1, \dots, \alpha_k$ がいずれも $0$ でないとき ($k \geq 1$),

$$ N(\alpha_k) \leq \frac{1}{2^{k-1}} N(\alpha_1) = \frac{1}{2^{k-1}} N(\beta) $$

である. 一方, 命題 5 (1), (2) より, $\alpha_k \neq 0$ ならば $N(\alpha_k)$ は正の整数であるから, $N(\alpha_k) \geq 1$ である. よって, $\alpha_1, \dots, \alpha_k$ がいずれも $0$ でないならば, $2^{k-1} \leq N(\beta)$, すなわち $k \leq \log_2 N(\beta) + 1$ である. したがって, $0$ でない項が無限に続くことはなく, $\alpha_{K+1} = 0$ となる $K \geq 1$ が存在する.

(2) $0 \leq k < K$ に対して, $\alpha_k = \alpha_{k+1} q_k + \alpha_{k+2}$ を満たす $q_k \in \mathbb{Z}[i]$ が存在する. よって, 命題 18 より, $g \in \mathbb{Z}[i]$ について

$$ g \text{ が } \alpha_k \text{ と } \alpha_{k+1} \text{ の最大公約数} \iff g \text{ が } \alpha_{k+1} \text{ と } \alpha_{k+2} \text{ の最大公約数} $$

である. これを $k = 0, 1, \dots, K-1$ について繋げると, $g$ が $\alpha = \alpha_0$ と $\beta = \alpha_1$ の最大公約数であることと, $g$ が $\alpha_K$ と $\alpha_{K+1} = 0$ の最大公約数であることは同値である. 命題 19 より $\alpha_K$ は $\alpha_K$ と $0$ の最大公約数であるから, $\alpha_K$ は $\alpha$ と $\beta$ の最大公約数である.

(3) (1) の証明において, $\alpha_1, \dots, \alpha_K$ はいずれも $0$ でないから, $k = K$ として $K \leq \log_2 N(\beta) + 1$ である.

</div>

<div class="corollary" markdown="1">

系 21
---

任意の $\alpha, \beta \in \mathbb{Z}[i]$ に対して, $\alpha$ と $\beta$ の最大公約数が存在する. さらに, それは同伴の違いを除いて一意に定まる.

</div>

<div class="proof" markdown="1">

証明
---

存在は定理 20 (2) より従い, 同伴の違いを除いた一意性は命題 13 より従う.

</div>

定理 20 の $K$ は, 除算 (系 16) を行う回数である. 各除算は整数の加減乗除の定数回で計算できるので, Euclid の互除法による最大公約数の計算は, $\beta \neq 0$ のとき $O(\log N(\beta))$ 時間で行える.

## Contents

### コンストラクタ

```cpp
template<typename R>
Gaussian_Integer<R>(R re, R im)
Gaussian_Integer<R>(R re)
```

* 1 つ目は Gauss 整数 $\textrm{re} + \textrm{im} \cdot i$ を生成する.
* 2 つ目は整数 $\textrm{re}$ (つまり $\textrm{re} + 0 \cdot i$) を生成する.
* 実部と虚部はそれぞれメンバ変数 `re`, `im` で参照できる.
* **制約**
  * `R` は整数型 (除法で `round` を使うため, `integral` を満たす必要がある).
* **計算量**
  * $O(1)$ 時間.

### 加法・減法・乗法

```cpp
Gaussian_Integer operator-() const
Gaussian_Integer& operator+=(const Gaussian_Integer &b)
Gaussian_Integer& operator-=(const Gaussian_Integer &b)
Gaussian_Integer& operator*=(const Gaussian_Integer &b)
friend Gaussian_Integer operator+(const Gaussian_Integer &x, const Gaussian_Integer &y)
friend Gaussian_Integer operator-(const Gaussian_Integer &x, const Gaussian_Integer &y)
friend Gaussian_Integer operator*(const Gaussian_Integer &x, const Gaussian_Integer &y)
```

* $\alpha = a + bi, \beta = c + di$ に対して, 以下を計算する.
  * `-alpha`: $-\alpha = (-a) + (-b) i$
  * `alpha + beta`: $\alpha + \beta = (a + c) + (b + d) i$
  * `alpha - beta`: $\alpha - \beta = (a - c) + (b - d) i$
  * `alpha * beta`: $\alpha \beta = (ac - bd) + (ad + bc) i$
* **注意**
  * 計算途中の値が `R` の範囲に収まらない場合, オーバーフローする.
* **計算量**
  * $O(1)$ 時間.

### 除法・剰余

```cpp
Gaussian_Integer& operator/=(const Gaussian_Integer &b)
Gaussian_Integer& operator%=(const Gaussian_Integer &b)
friend Gaussian_Integer operator/(const Gaussian_Integer &x, const Gaussian_Integer &y)
friend Gaussian_Integer operator%(const Gaussian_Integer &x, const Gaussian_Integer &y)
```

* $\alpha, \beta$ ($\beta \neq 0$) に対して, 定理 14 を満たす Gauss 整数の組 $(q, r)$ のうちの 1 つを求め, `alpha / beta` は商 $q$ を, `alpha % beta` は余り $r$ を返す.
* 商 $q$ と余り $r$ は系 16 の式で計算する. すなわち, 商 $q$ は複素数 $\dfrac{\alpha}{\beta} = \dfrac{\alpha \overline{\beta}}{N(\beta)}$ の実部と虚部をそれぞれ四捨五入 (定義 15) したものであり, 余り $r$ は $r = \alpha - \beta q$ である.
  * このとき, $\alpha = \beta q + r$ かつ $N(r) \leq \dfrac{1}{2} N(\beta)$ を満たす.
  * 条件を満たす $(q, r)$ は一意とは限らない (注意 17).
* **制約**
  * $\beta \neq 0$.
* **注意**
  * 計算途中で $\alpha \overline{\beta}$ の実部・虚部と $N(\beta)$ を計算するので, これらが `R` の範囲に収まらない場合, オーバーフローする.
* **計算量**
  * $O(1)$ 時間.

### conjugate

```cpp
Gaussian_Integer conjugate() const
```

* $\alpha = a + bi$ の共役 $\overline{\alpha} = a - bi$ (定義 3) を返す.
* **計算量**
  * $O(1)$ 時間.

### norm

```cpp
R norm() const
```

* $\alpha = a + bi$ のノルム $N(\alpha) = \lvert \alpha \rvert^2 = a^2 + b^2$ (定義 4, 命題 5 (1)) を返す.
* **注意**
  * $a^2 + b^2$ が `R` の範囲に収まらない場合, オーバーフローする.
* **計算量**
  * $O(1)$ 時間.

### is_zero

```cpp
bool is_zero() const
```

* $\alpha = 0$ かどうかを判定する.
* **計算量**
  * $O(1)$ 時間.

### 入出力

```cpp
friend istream &operator>>(istream &is, Gaussian_Integer &a)
friend ostream &operator<<(ostream &os, const Gaussian_Integer &x)
```

* 入力: 実部, 虚部の順に 2 個の整数を読み込む.
* 出力: `re+imi` の形式で出力する.
  * 虚部が負の場合も `+` を出力する (例: $3 - 4i$ は `3+-4i` と出力される).
* **計算量**
  * $O(1)$ 時間.

### gcd

```cpp
template<typename R>
Gaussian_Integer<R> gcd(Gaussian_Integer<R> alpha, Gaussian_Integer<R> beta)
```

* Euclid の互除法 (定理 20) により, $\alpha$ と $\beta$ の最大公約数 (定義 12) を 1 つ求める.
* **返り値**
  * $\alpha$ と $\beta$ の最大公約数の 1 つ. 最大公約数は同伴の違い (命題 9, 11 より $\pm 1, \pm i$ 倍の違い) を除いて一意であり (系 21), どれが返るかは指定しない.
  * $\alpha = \beta = 0$ のときは $0$ を返す.
* **計算量**
  * $\beta \neq 0$ のとき, $O(\log N(\beta))$ 時間.
    * 定理 20 (3) より, 除算の回数は $\log_2 N(\beta) + 1$ 回以下である.

## History

|日付|内容|
|:---:|:---:|
|2026/11/27| Gauss 整数のドキュメントの作成 |
|2025/08/23| Gaussian_Integer クラスの実装 |
