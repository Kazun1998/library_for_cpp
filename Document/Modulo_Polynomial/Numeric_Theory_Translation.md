---
title: 離散フーリエ変換, 数論変換
documentation_of: //Modulo_Polynomial/Numeric_Theory_Translation.hpp
---

## Outline

数論変換 (NTT) による畳み込みを高速に行う. 形式的ベキ級数に関する演算 (逆元, 除算など) は [Fast_Power_Series](Fast_Power_Series.md) が担う.

## Theory

$F$ を体とし, $n$ を正の整数とする.

<div class="definition" markdown="1">

定義 1
---

$\zeta \in F$ が $1$ の**原始 $n$ 乗根**であるとは, $\zeta^n = 1$ であり, $0 \lt k \lt n$ を満たす任意の整数 $k$ について $\zeta^k \neq 1$ であることをいう.

</div>

以降, $F$ には $1$ の原始 $n$ 乗根 $\zeta$ が存在するとする.

<div class="lemma" markdown="1">

補題 2
---

$X^n - 1 = \prod_{k=0}^{n-1} (X - \zeta^k)$ である. 特に, $\zeta^0, \dots, \zeta^{n-1}$ は相異なる.

</div>

<div class="proof" markdown="1">

証明
---

$0 \leq i \lt j \lt n$ ならば $\zeta^{j-i} \neq 1$ より $\zeta^i \neq \zeta^j$ であるから, $\zeta^0, \dots, \zeta^{n-1}$ は相異なる. また, $(\zeta^k)^n = (\zeta^n)^k = 1$ であるから, これらは $X^n - 1$ の根である.

$F$ は体であるから, 因数定理より $X^n - 1$ は $X - \zeta^k$ ($0 \leq k \lt n$) で割り切れる. これらは互いに素なので, $X^n - 1$ は積 $\prod_{k=0}^{n-1} (X - \zeta^k)$ で割り切れる. 両辺とも次数 $n$ のモニック多項式であるから, 等しい.

</div>

<div class="proposition" markdown="1">

命題 3
---

$n$ は $F$ において可逆である.

</div>

<div class="proof" markdown="1">

証明
---

補題 2 の両辺を $X - 1 = X - \zeta^0$ で割ると,

$$ 1 + X + \dots + X^{n-1} = \prod_{k=1}^{n-1} (X - \zeta^k) $$

であり, $X = 1$ を代入して $n = \prod_{k=1}^{n-1} (1 - \zeta^k)$ を得る. 各因子は $0$ でないので, $n \neq 0$ である.

</div>

<div class="proposition" markdown="1">

命題 4
---

整数 $m$ に対して,

$$ \sum_{t=0}^{n-1} \zeta^{mt} = \begin{cases} n & (m \equiv 0 \pmod{n}) \\ 0 & (\text{otherwise}) \end{cases} $$

</div>

<div class="proof" markdown="1">

証明
---

$m \equiv 0 \pmod{n}$ のとき, $\zeta^m = 1$ なので各項は $1$ であり, 和は $n$ である.

そうでないとき, $r := \zeta^m$ とおくと $r \neq 1$ かつ $r^n = 1$ である. よって,

$$\begin{align*}
    (r-1) \sum_{t=0}^{n-1} r^t
    &= r^n - 1 \\
    &= 0
\end{align*}$$

であり, $r - 1 \neq 0$ より和は $0$ である.

</div>

### 離散フーリエ変換

長さ $n$ の列 $\boldsymbol{a} = (a_0, \dots, a_{n-1}) \in F^n$ に対して, 多項式 $A := \sum_{i=0}^{n-1} a_i X^i$ を対応させる.

<div class="definition" markdown="1">

定義 5
---

$\boldsymbol{a} \in F^n$ の**離散フーリエ変換** $\mathcal{F}_n \boldsymbol{a} \in F^n$ を, $A$ の $\zeta^k$ での値の列

$$ \left(\mathcal{F}_n \boldsymbol{a} \right)_k := A(\zeta^k) = \sum_{j=0}^{n-1} \zeta^{jk} a_j \quad (0 \leq k \lt n) $$

で定義する.

</div>

この写像は $F^n$ から $F^n$ への線形写像である. 行列で書けば, $n$ 次正方行列 $W$ を

$$ W := \left(\zeta^{kj} \right)_{\substack{0 \leq k \lt n \\ 0 \leq j \lt n}} $$

で定めて, $\mathcal{F}_n \boldsymbol{a} = W \boldsymbol{a}$ である.

<div class="proposition" markdown="1">

命題 6
---

$\mathcal{F}_n$ は全単射である.

</div>

<div class="proof" markdown="1">

証明
---

$\mathcal{F}_n$ は線形写像であるから, $\mathcal{F}_n \boldsymbol{a} = \boldsymbol{0}$ ならば $\boldsymbol{a} = \boldsymbol{0}$ であることを示せばよい. $\mathcal{F}_n \boldsymbol{a} = \boldsymbol{0}$ とすると, $A$ は命題 3 の証明で見たように相異なる $n$ 個の $\zeta^0, \dots, \zeta^{n-1}$ を根に持つ. $A$ の次数は $n$ 未満であるから $A = 0$, すなわち $\boldsymbol{a} = \boldsymbol{0}$ である. よって $\mathcal{F}_n$ は単射であり, $F^n$ は有限次元なので全単射である.

</div>

<div class="definition" markdown="1">

定義 7
---

$\mathcal{F}_n$ の逆写像を**逆離散フーリエ変換**といい, $\mathcal{F}_n^{-1}$ と書く.

</div>

次の系によって, 逆離散フーリエ変換を具体的に計算することが可能になる.

<div class="corollary" markdown="1">

系 8
---

$\boldsymbol{b} \in F^n$ に対して,

$$ \left(\mathcal{F}_n^{-1} \boldsymbol{b} \right)_i = \dfrac{1}{n} \sum_{t=0}^{n-1} \zeta^{-it} b_t $$

である.

</div>

<div class="proof" markdown="1">

証明
---

右辺で定まる写像を $\mathcal{G}$ とおく. 命題 4 より,

$$\begin{align*}
    \left(\mathcal{G} \left(\mathcal{F}_n \boldsymbol{a} \right) \right)_i
    &= \dfrac{1}{n} \sum_{t=0}^{n-1} \zeta^{-it} \sum_{j=0}^{n-1} \zeta^{jt} a_j \\
    &= \dfrac{1}{n} \sum_{j=0}^{n-1} a_j \sum_{t=0}^{n-1} \zeta^{(j-i)t} \\
    &= \dfrac{1}{n} \sum_{j=0}^{n-1} a_j \cdot n \left[ j \equiv i \pmod{n} \right] \\
    &= a_i
\end{align*}$$

である. よって $\mathcal{G} \circ \mathcal{F}_n$ は恒等写像である. $\mathcal{F}_n$ は全単射なので $\mathcal{G} = \mathcal{F}_n^{-1}$ である.

</div>

行列で言えば, $W$ は正則で $W^{-1} = \dfrac{1}{n} (\zeta^{-ij})_{\substack{0 \leq i \lt n \\ 0 \leq j \lt n}}$ である.

### 畳み込み

$\boldsymbol{a}, \boldsymbol{b} \in F^n$ に対して, **巡回畳み込み** $\boldsymbol{a} \ast \boldsymbol{b} \in F^n$ を

$$ (\boldsymbol{a} \ast \boldsymbol{b})_k := \sum_{\substack{0 \leq i \lt n \\ 0 \leq j \lt n \\ i + j \equiv k \pmod{n}}} a_i b_j $$

で定義する. また, 各点ごとの積を $\boldsymbol{a} \odot \boldsymbol{b}$ ($(\boldsymbol{a} \odot \boldsymbol{b})_k := a_k b_k$) と書く.

<div class="theorem" markdown="1">

定理 9
---

$\boldsymbol{a}, \boldsymbol{b} \in F^n$ に対して,

$$ \mathcal{F}_n (\boldsymbol{a} \ast \boldsymbol{b}) = \mathcal{F}_n \boldsymbol{a} \odot \mathcal{F}_n \boldsymbol{b} $$

が成り立つ. 特に, $\boldsymbol{a} \ast \boldsymbol{b} = \mathcal{F}_n^{-1} \left(\mathcal{F}_n \boldsymbol{a} \odot \mathcal{F}_n \boldsymbol{b} \right)$ である.

</div>

<div class="proof" markdown="1">

証明
---

$\zeta^n = 1$ より, $\zeta^{k(i+j)} = \zeta^{k((i+j) \bmod n)}$ である. したがって,

$$\begin{align*}
    \left(\mathcal{F}_n \boldsymbol{a} \right)_k \left(\mathcal{F}_n \boldsymbol{b} \right)_k
    &= \sum_{i,j=0}^{n-1} \zeta^{k(i+j)} a_i b_j \\
    &= \sum_{l=0}^{n-1} \zeta^{kl} \sum_{\substack{0 \leq i \lt n \\ 0 \leq j \lt n \\ i + j \equiv l \pmod{n}}} a_i b_j \\
    &= \sum_{l=0}^{n-1} \zeta^{kl} (\boldsymbol{a} \ast \boldsymbol{b})_l \\
    &= \left(\mathcal{F}_n (\boldsymbol{a} \ast \boldsymbol{b}) \right)_k
\end{align*}$$

である. 後半は, 両辺に $\mathcal{F}_n^{-1}$ (定義 7) を作用させればよい.

</div>

多項式の言葉では, $\boldsymbol{a} \ast \boldsymbol{b}$ は $AB \bmod (X^n - 1)$ の係数列である.

### 高速離散フーリエ変換

定義 5 のとおりに $\mathcal{F}_n \boldsymbol{a}$ を計算すると $O(n^2)$ 時間かかる. $n$ が合成数のときは, より短い変換に帰着できる.

$\zeta$ に依存することを明示するために, $1$ の原始 $n$ 乗根 $\zeta$ に対する長さ $n$ の離散フーリエ変換を $\mathcal{F}_{n, \zeta}$ と書く.

$n = pq$ ($p, q$ は正の整数) とする.

<div class="proposition" markdown="1">

命題 10
---

$\zeta$ を $1$ の原始 $n$ 乗根とする. このとき, $\zeta^q$ は $1$ の原始 $p$ 乗根, $\zeta^p$ は $1$ の原始 $q$ 乗根である.

</div>

<div class="proof" markdown="1">

証明
---

$(\zeta^q)^p = \zeta^n = 1$ である. また $0 \lt k \lt p$ ならば $0 \lt qk \lt n$ なので, $(\zeta^q)^k = \zeta^{qk} \neq 1$ である. よって $\zeta^q$ は原始 $p$ 乗根である. $\zeta^p$ についても同様である.

</div>

以降, 入力の添字 $i$ と出力の添字 $k$ を

$$ i = i_0 + q i_1 \quad (0 \leq i_0 \lt q, ~ 0 \leq i_1 \lt p), \qquad k = r + p s \quad (0 \leq r \lt p, ~ 0 \leq s \lt q) $$

と表す. これらは, それぞれ $0$ 以上 $n$ 未満の整数と $1$ 対 $1$ に対応する.

<div class="proposition" markdown="1">

命題 11
---

$\boldsymbol{a} \in F^n$ とし, $0 \leq i_0 \lt q$, $0 \leq r \lt p$ に対して

$$ u_{r, i_0} := \zeta^{i_0 r} \sum_{i_1=0}^{p-1} \left(\zeta^q \right)^{i_1 r} a_{i_0 + q i_1} $$

とおく. このとき, $0 \leq r \lt p$, $0 \leq s \lt q$ に対して,

$$ \left(\mathcal{F}_{n, \zeta} \boldsymbol{a} \right)_{r + ps} = \sum_{i_0=0}^{q-1} \left(\zeta^p \right)^{i_0 s} u_{r, i_0} $$

が成り立つ.

</div>

<div class="proof" markdown="1">

証明
---

$\zeta^n = 1$ に注意すると,

$$\begin{align*}
    \zeta^{ik} = \zeta^{(i_0 + q i_1)(r + ps)}
    &= \zeta^{i_0 r} \cdot \zeta^{p i_0 s} \cdot \zeta^{q i_1 r} \cdot \zeta^{n i_1 s} \\
    &= \zeta^{i_0 r} \left(\zeta^p \right)^{i_0 s} \left(\zeta^q \right)^{i_1 r}
\end{align*}$$

である. これを

$$ \left(\mathcal{F}_{n, \zeta} \boldsymbol{a} \right)_k = \sum_{i=0}^{n-1} \zeta^{ik} a_i $$

に代入し, $i$ に関する和を $(i_0, i_1)$ に関する和に書き直せば,

$$\begin{align*}
    \left(\mathcal{F}_{n, \zeta} \boldsymbol{a} \right)_{r + ps}
    &= \sum_{i_0=0}^{q-1} \left(\zeta^p \right)^{i_0 s} \left(\zeta^{i_0 r} \sum_{i_1=0}^{p-1} \left(\zeta^q \right)^{i_1 r} a_{i_0 + q i_1} \right) \\
    &= \sum_{i_0=0}^{q-1} \left(\zeta^p \right)^{i_0 s} u_{r, i_0}
\end{align*}$$

である.

</div>

命題 11 は, 次の 3 段階の計算になっている. 命題 10 より, 2 つの変換は原始 $p$ 乗根, 原始 $q$ 乗根に関する離散フーリエ変換である.

1. 各 $i_0$ に対して, 長さ $p$ の列 $a_{i_0}, a_{i_0+q}, \dots, a_{i_0+q(p-1)}$ に $\mathcal{F}_{p, \zeta^q}$ を施して, $r$ 番目の成分を得る. ($q$ 個の変換)
2. 得られた値に $\zeta^{i_0 r}$ を掛けて, $u_{r, i_0}$ を得る. ($n$ 回の乗算)
3. 各 $r$ に対して, 長さ $q$ の列 $u_{r,0}, u_{r,1}, \dots, u_{r,q-1}$ に $\mathcal{F}_{q, \zeta^p}$ を施すと, その $s$ 番目の成分が出力の $r + ps$ 番目となる. ($p$ 個の変換)

特に $p = 2$ のとき, 段階 1 は $a_{i_0} \pm a_{i_0 + q}$ を求める操作であり, 段階 2 で $\zeta^{i_0}$ を掛けるのは $-$ の側のみである.

<div class="corollary" markdown="1">

系 12
---

$n = p_1 p_2 \cdots p_h$ ($p_j \geq 2$) と分解できるとき, $\mathcal{F}_{n, \zeta} \boldsymbol{a}$ は $O \left(n (p_1 + p_2 + \dots + p_h) \right)$ 時間で求められる. 特に, $n$ が $2$ ベキのときは $O(n \log n)$ 時間で求められる.

</div>

<div class="proof" markdown="1">

証明
---

$T(n)$ を長さ $n$ の変換に必要な時間の上界とする. 長さ $p$ の変換は定義どおりに $c p^2$ 時間でできるとする.

$h$ に関する帰納法で, $T(n) \leq (c + 1) n (p_1 + \dots + p_h)$ を示す. $h = 1$ のときは $T(p_1) \leq c p_1^2$ から成り立つ.

$h \geq 2$ のとき, $p = p_1$, $q = p_2 \cdots p_h$ として命題 11 を用いる. $\zeta^{i}$ ($0 \leq i \lt n$) を順に掛けて求めておけば, 段階 2 は $O(n)$ 時間であり, 乗算の回数を $n$ としてよい. すると,

$$\begin{align*}
    T(n)
    &\leq q \cdot c p^2 + n + p \cdot T(q) \\
    &\leq c n p_1 + n + (c+1) n (p_2 + \dots + p_h) \\
    &\leq (c+1) n (p_1 + \dots + p_h)
\end{align*}$$

である. ここで, $p_1 \geq 2$ より $c n p_1 + n \leq (c+1) n p_1$ を用いた.

$n$ が $2$ ベキのとき, $n = 2^h$ とすると, $p_1 = \dots = p_h = 2$ であり, $n(p_1 + \dots + p_h) = 2 n \log_2 n$ である.

</div>

逆変換については, $\zeta^{-1}$ も原始 $n$ 乗根であり, 系 8 により

$$ \mathcal{F}_{n, \zeta}^{-1} \boldsymbol{b} = \dfrac{1}{n} \mathcal{F}_{n, \zeta^{-1}} \boldsymbol{b} $$

である. よって, 逆離散フーリエ変換も同じ時間で求められる. これと定理 9 から, $n = 2^h$ のとき, 巡回畳み込み $\boldsymbol{a} \ast \boldsymbol{b}$ も $O(n \log n)$ 時間で求められる.

### 素数を法とする体

有限体の乗法群は巡回群である (既知の事実として用いる).

<div class="proposition" markdown="1">

命題 13
---

$p$ を素数とし, $p = u \cdot 2^e + 1$ ($u$ は奇数, $e \geq 0$) と表す. このとき, $0 \leq f \leq e$ を満たす任意の整数 $f$ に対して, $\mathbb{F}_p$ には $1$ の原始 $2^f$ 乗根が存在する.

</div>

<div class="proof" markdown="1">

証明
---

$\mathbb{F}_p^{\times}$ は位数 $p - 1 = u \cdot 2^e$ の巡回群であるから, 生成元 $g$ が存在する. $\zeta := g^{u \cdot 2^{e-f}}$ とおく.

$$ \zeta^{2^f} = g^{u \cdot 2^e} = g^{p-1} = 1 $$

である. また, 整数 $k$ に対して, $g$ の位数が $u \cdot 2^e$ であることから,

$$\begin{align*}
    \zeta^k = 1
    &\iff g^{u \cdot 2^{e-f} k} = 1 \\
    &\iff u \cdot 2^e \mid u \cdot 2^{e-f} k \\
    &\iff 2^f \mid k
\end{align*}$$

である. よって $0 \lt k \lt 2^f$ ならば $\zeta^k \neq 1$ であり, $\zeta$ は $1$ の原始 $2^f$ 乗根である.

</div>

したがって, $h \leq e$ を満たす $h$ に対して, $\mathbb{F}_p$ 上で長さ $2^h$ の離散フーリエ変換が行える. 例えば $998244353 = 119 \cdot 2^{23} + 1$ であるから, 長さ $2^{23}$ まで行える.

## Contents

`F` は NTT が可能な体 (`modint` など) である. 以下, 配列の長さ $N$ について, `ntt`, `inverse_ntt` では $N$ は $2$ の冪とする.

```cpp
Numeric_Theory_Translation<F> calculator
```

* 数論変換器を構築する. 原始根と回転因子の表を作る.

### ntt

```cpp
void ntt(vector<F> &A)
```

* $A$ を離散フーリエ変換 $\mathcal{F}_N A$ に置き換える. ただし, 値の並びは $k$ のビット反転の順になる. 各点積を取って `inverse_ntt` で戻す用途では, 並びは影響しない.
* **制約** : $\lvert A \rvert \mid (F \text{ の標数} - 1)$ かつ $\lvert A \rvert$ は $2$ の冪.
* **計算量** : $N := \lvert A \rvert$ として, $O(N \log N)$ 時間.

### inverse_ntt

```cpp
void inverse_ntt(vector<F> &A)
```

* $A$ を逆離散フーリエ変換 $\mathcal{F}_N^{-1} A$ に置き換える (`ntt` の出力の並びを受け取る). $\frac{1}{N}$ 倍も行う.
* **制約** : `ntt` と同じ.
* **計算量** : $N := \lvert A \rvert$ として, $O(N \log N)$ 時間.

### convolution

```cpp
vector<F> convolution(vector<F> A, vector<F> B)
```

* 係数列 $A, B$ の畳み込み (多項式としての積の係数列) を求める. どちらかが空のときは空列を返す. 短い方の長さが $64$ 未満のときは愚直に計算する.
* **計算量** : $L := \lvert A \rvert + \lvert B \rvert - 1$ として, $O(L \log L)$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/11/28|高速離散フーリエ変換の Theory を追加した. Theory を, 離散フーリエ変換を多項式の評価で定義する形に書き直した. 逆元 (`inverse`) と `multiple_convolution` を [Fast_Power_Series](Fast_Power_Series.md) に移した. これに伴い, 逆元の節を移動した.|
|2025/10/10|ドキュメントの作成|
|2025/09/14|Numeric_Theory_Translation の実装|
