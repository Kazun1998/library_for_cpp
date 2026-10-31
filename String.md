# 列/文字列

<div class="definition" markdown="1">

定義 1
---

$X$ を集合とする.

* (1) $X^0$ を, ただ一つの元 $\emptyset$ のみからなる集合とする. この $\emptyset$ を空列という.
* (2) 正の整数 $n$ に対し, $X^n := \underbrace{X \times \dots \times X}_n$ と定義する.
* (3) 非負整数 $n$ に対し, $X^n$ の元を $(a_1, \dots, a_n)$ ($a_i \in X$) と書く. 特に $n = 0$ のとき, この記法は空列 $\emptyset$ を表し, $()$ と書く. すなわち $() = \emptyset$ である.
* (4) $\displaystyle X^* := \bigsqcup_{n=0}^\infty X^n$ と定義し, $X^*$ の元を列という.
* (5) $\alpha \in X^*$ に対し, 直和の定義から $\alpha \in X^n$ となる非負整数 $n$ がただ一つ存在する. この $n$ を $\alpha$ の長さといい, $\lvert \alpha \rvert$ と書く. 特に $\lvert \emptyset \rvert = 0$ である.

</div>

<div class="remark" markdown="1">

注意 2
---

* (1) 空列は文献によっては $\varepsilon$ や $\lambda$ で書くこともある.
* (2) $X$ をアルファベット, $X$ の元を文字というとき, $X$ 上の列を文字列という.
* (3) $n \geq 1$ のとき, 文字列 $(a_1, \dots, a_n)$ はカッコやカンマなしに $a_1 \dots a_n$ と書くこともある.

</div>

<div class="definition" markdown="1">

定義 3
---

$X$ を集合とし, 非負整数 $n, m$ に対し $\alpha = (a_1, \dots, a_n)$, $\beta = (b_1, \dots, b_m) \in X^*$ とする.

このとき, $\alpha$ と $\beta$ の結合 $\alpha \oplus \beta \in X^{n+m}$ を

$$ \alpha \oplus \beta := (a_1, \dots, a_n, b_1, \dots, b_m) $$

で定義する.

</div>

<div class="proposition" markdown="1">

命題 4
---

$X$ を集合とする. $X^*$ は $\oplus$ を演算としてモノイドになる.

</div>

<div class="definition" markdown="1">

定義 5
---

$X$ を集合として, $\alpha, \beta \in X^*$ とする.

* (1) $\beta = \alpha \oplus \gamma$ となる $\gamma \in X^*$ が存在するとき, $\alpha$ は $\beta$ の接頭辞であるという.
* (2) $\beta = \gamma \oplus \alpha$ となる $\gamma \in X^*$ が存在するとき, $\alpha$ は $\beta$ の接尾辞であるという.
* (3) $\beta = \gamma \oplus \alpha \oplus \delta$ となる $\gamma, \delta \in X^*$ が存在するとき, $\alpha$ は $\beta$ の部分文字列であるという.
* (4) 次を満たす $\xi_i, \eta_j \in X^*$ が存在するとき, $\alpha$ は $\beta$ の部分列であるという.
  * $\alpha = \xi_1 \oplus \dots \oplus \xi_n$.
  * $\beta = \eta_1 \oplus \xi_1 \oplus \dots \oplus \eta_n \oplus \xi_n \oplus \eta_{n+1}$.

</div>

<div class="definition" markdown="1">

定義 6
---

$(X, \leq)$ を全順序集合とする. $\alpha = (a_1, \dots, a_n)$, $\beta = (b_1, \dots, b_m) \in X^\ast$ に対し, 次の (a), (b) のいずれか一方が成り立つとき, $\alpha \leq \beta$ と定める. この $X^\ast$ 上の順序を $X$ の辞書式順序という.

* (a) $\alpha$ は $\beta$ の接頭辞である.
* (b) ある整数 $i$ ($1 \leq i \leq \min(n, m)$) が存在して, 次が成り立つ.
  * $1 \leq j < i$ なる任意の整数 $j$ に対して, $a_j = b_j$.
  * $a_i < b_i$.

</div>

<div class="proposition" markdown="1">

命題 7
---

$(X, \leq)$ を全順序集合とする. このとき, $X^*$ は辞書式順序によって全順序集合となる.

</div>

<div class="proposition" markdown="1">

命題 8
---

$(X, \leq)$ を全順序集合とする. このとき, 以下が成り立つ.

* (1) $X^*$ は最小元を持ち, $\emptyset$ である.
* (2) $\alpha, \beta \in X^\ast$ とする. 任意の $\xi \in X^\ast$ に対して, 以下は同値になる.
  * $\alpha \leq \beta$.
  * $\xi \oplus \alpha \leq \xi \oplus \beta$.
* (3) $\alpha, \beta \in X^\ast$ は互いに接頭辞にならないとする. このとき, 任意の $\xi, \eta \in X^\ast$ に対して, 以下は同値になる.
  * $\alpha \leq \beta$.
  * $\xi \oplus \alpha \oplus \eta \leq \xi \oplus \beta \oplus \eta$.

</div>

<div class="definition" markdown="1">

定義 9
---

$X$ を集合とする. $\alpha = (a_1, \dots, a_n) \in X^*$ に対して, $\alpha$ の反転 $\overline{\alpha}$ を

$$ \overline{\alpha} := (a_n, a_{n-1}, \dots, a_1) $$

と定義する.

</div>

<div class="definition" markdown="1">

定義 10
---

$X$ を集合とする. $\alpha \in X^*$ に対して, $\overline{\alpha} = \alpha$ であるとき, $\alpha$ は回文であるという.

</div>

<div class="proposition" markdown="1">

命題 11
---

$X$ を集合とする.

* (1) $\alpha \in X^*$ に対して, $\overline{\overline{\alpha}} = \alpha$ である.
* (2) $\alpha, \beta \in X^*$ に対して, $\overline{\alpha \oplus \beta} = \overline{\beta} \oplus \overline{\alpha}$ である.

</div>
