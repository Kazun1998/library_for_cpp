---
title: 高速な形式的ベキ級数
documentation_of: //Modulo_Polynomial/Fast_Power_Series.hpp
---

## Outline

[数論変換](Numeric_Theory_Translation.md) を用いて, 精度付きの形式的ベキ級数の積・逆元・除算などを高速に行う. 加減算やスカラー倍などの線形演算は基底クラス [Modulo_Polynomial](Modulo_Polynomial.md) のものを使う.

精度 $d$ の形式的ベキ級数は $P \bmod{X^d}$ を表す. 2 つの級数の演算では, 精度は小さい方に合わせる.

## Theory

### 積

[Numeric_Theory_Translation](Numeric_Theory_Translation.md) の記号を用いる. すなわち, $\zeta$ を $1$ の原始 $n$ 乗根, $\mathcal{F}_n$ を離散フーリエ変換, $\ast$ を巡回畳み込み, $\odot$ を各点ごとの積とする.

<div class="corollary" markdown="1">

系 1
---

$f, g \in F[X]$ の次数をそれぞれ $d_f, d_g$ とし, $n \geq d_f + d_g + 1$ とする. $f, g, fg$ の $0$ 次から $n-1$ 次までの係数の列を $\boldsymbol{a}, \boldsymbol{b}, \boldsymbol{c} \in F^n$ とすると, $\boldsymbol{c} = \boldsymbol{a} \ast \boldsymbol{b}$ である.

</div>

<div class="proof" markdown="1">

証明
---

$a_i, b_j$ は $i \leq d_f$, $j \leq d_g$ でないとき $0$ であり, $i + j \leq d_f + d_g \lt n$ である. よって $i + j \equiv k \pmod{n}$ かつ非零の項は $i + j = k$ のものに限られ,

$$ (\boldsymbol{a} \ast \boldsymbol{b})_k = \sum_{i+j=k} a_i b_j = c_k $$

である.

</div>

したがって, 十分大きい $n$ に対して原始 $n$ 乗根があれば, 多項式の積は Numeric_Theory_Translation の定理 8 により $\mathcal{F}_n$ と各点積と $\mathcal{F}_n^{-1}$ で計算できる. すなわち $\boldsymbol{c} = \mathcal{F}_n^{-1} \left(\mathcal{F}_n \boldsymbol{a} \odot \mathcal{F}_n \boldsymbol{b} \right)$ である.

### 逆元

$F$ を体とする. 形式的ベキ級数 $f \in F[[X]]$ の $X^i$ の係数を $f_i$ と書く.

<div class="proposition" markdown="1">

命題 2
---

$f_0 \neq 0$ ならば, $fg = 1$ を満たす $g \in F[[X]]$ がただ一つ存在する.

</div>

<div class="proof" markdown="1">

証明
---

$fg = 1$ は, 係数を比べると $f_0 g_0 = 1$ と, $n \geq 1$ に対する

$$ \sum_{i=0}^{n} f_i g_{n-i} = 0 $$

である. $f_0 \neq 0$ より $g_0 = f_0^{-1}$ と定まり, $n \geq 1$ に対しては $g_n = -f_0^{-1} \sum_{i=1}^{n} f_i g_{n-i}$ と, $g_0, \dots, g_{n-1}$ から一意に定まる. よって $g$ は存在して一意である.

</div>

<div class="definition" markdown="1">

定義 3
---

命題 2 の $g$ を $f$ の**逆元**といい, $f^{-1}$ と書く.

</div>

以降, $f_0 \neq 0$ とし, $g := f^{-1}$ とおく. 正の整数 $n$ に対して, $g^{(n)} := g \bmod{X^n}$ ($n$ 次未満の多項式) とおく.

<div class="proposition" markdown="1">

命題 4
---

(a) $g^{(1)} = f_0^{-1}$ である.

(b) $n$ 次未満の多項式 $g'$ が $fg' \equiv 1 \pmod{X^n}$ を満たすならば, $g' = g^{(n)}$ である.

</div>

<div class="proof" markdown="1">

証明
---

(a) 命題 2 の証明より, $g_0 = f_0^{-1}$ である.

(b) $fg = 1$ より $f(g' - g) \equiv 0 \pmod{X^n}$ である. $f_0 \neq 0$ なので $f$ は $F[[X]]$ で可逆であり, $g' \equiv g \pmod{X^n}$ を得る. $g'$ は $n$ 次未満なので $g' = g^{(n)}$ である.

</div>

次の命題が, 逆元を求める Newton 法の核心である.

<div class="proposition" markdown="1">

命題 5
---

正の整数 $n$ に対して,

$$ g^{(2n)} = \left(2 g^{(n)} - f \left(g^{(n)} \right)^2 \right) \bmod{X^{2n}} $$

が成り立つ.

</div>

<div class="proof" markdown="1">

証明
---

$g \equiv g^{(n)} \pmod{X^n}$ であるから, $g - g^{(n)}$ は $X^n$ で割り切れ, $\left(g - g^{(n)} \right)^2 \equiv 0 \pmod{X^{2n}}$ である. すなわち,

$$ g^2 - 2 g g^{(n)} + \left(g^{(n)} \right)^2 \equiv 0 \pmod{X^{2n}} $$

である. 両辺に $f$ を掛け, $fg = 1$ に注意して整理すると,

$$ g \equiv 2g^{(n)} - f \left(g^{(n)} \right)^2 \pmod{X^{2n}} $$

である. $g^{(2n)} = g \bmod{X^{2n}}$ なので, 主張が従う.

</div>

命題 5 をそのまま使うと $f \left(g^{(n)} \right)^2$ に積が 2 回必要だが, 次の系を使うと定数倍が小さくなる.

<div class="corollary" markdown="1">

系 6
---

$fg^{(n)} \equiv 1 \pmod{X^n}$ であるから, ある多項式 $h^{(n)}$ が存在して $fg^{(n)} = 1 + X^n h^{(n)}$ と書ける. このとき,

$$ g^{(2n)} = g^{(n)} - X^n \left(g^{(n)} h^{(n)} \bmod{X^n} \right) $$

が成り立つ. すなわち, $g$ の $n$ 次未満の係数は $g^{(n)}$ と一致し, $n$ 次以上 $2n$ 次未満の係数は $-g^{(n)} h^{(n)}$ の $n$ 次未満の係数と一致する.

</div>

<div class="proof" markdown="1">

証明
---

命題 5 に $fg^{(n)} = 1 + X^n h^{(n)}$ を代入すると, $\bmod{X^{2n}}$ で

$$ g^{(2n)} \equiv 2 g^{(n)} - \left(1 + X^n h^{(n)} \right) g^{(n)} = g^{(n)} - X^n g^{(n)} h^{(n)} $$

である. 右辺の $X^n g^{(n)} h^{(n)}$ のうち, $2n$ 次未満の部分は $X^n$ 倍した $g^{(n)} h^{(n)}$ の $n$ 次未満の部分だけであるから, 主張が従う.

</div>

<div class="corollary" markdown="1">

系 7
---

$n$ を正の整数とする. $g \bmod{X^n}$ は, 係数の積を $O(n \log n)$ 時間で行えるとき, $O(n \log n)$ 時間で求められる.

</div>

<div class="proof" markdown="1">

証明
---

$n \leq M = 2^m$ となる最小の $M$ をとり, 命題 4 (a) の $g^{(1)}$ から系 6 を $m$ 回用いて $g^{(M)}$ を求める. $g \bmod{X^n} = g^{(M)} \bmod{X^n}$ である. $g^{(k)}$ から $g^{(2k)}$ を求めるには, $fg^{(k)}$ ($f$ は $2k$ 次未満まで使う) と $g^{(k)} h^{(k)}$ の 2 回の積が必要で, 長さは $O(k)$ であるから, $O(k \log k)$ 時間である. よって全体の時間は $\sum_{j=0}^{m-1} O(2^j \cdot j) = O(M \log M) = O(n \log n)$ である.

</div>

### 除算

形式的ベキ級数の除算 $P / Q$ は, $Q$ の逆元を求めて $P$ に掛けることで行う.

### 多項式の商と余り

多項式 $A$ ($n$ 次), $B$ ($m$ 次, $n \geq m$) に対して $A = BQ + R$, $\deg R \lt m$ を満たす $Q, R$ を求める. 係数列を反転した多項式を $A^{\mathrm{rev}}, B^{\mathrm{rev}}$ とすると,

$$ Q^{\mathrm{rev}} \equiv A^{\mathrm{rev}} \left(B^{\mathrm{rev}}\right)^{-1} \pmod{X^{n-m+1}} $$

である. よってこの式から $Q$ が求まり, $R = A - BQ$ となる.

## Contents

```cpp
template<typename mint>
class Fast_Power_Series : public Modulo_Polynomial<mint, Fast_Power_Series<mint>>
```

[Modulo_Polynomial](Modulo_Polynomial.md) を CRTP で継承する. 積と除算のみをこのクラスで定義し, 線形演算の戻り値は `Fast_Power_Series` になる.

### コンストラクタ

```cpp
Fast_Power_Series(vector<mint> poly, int precision)
Fast_Power_Series(vector<mint> poly)
Fast_Power_Series(int precision)
Fast_Power_Series()
```

* 係数列 `poly` と精度 `precision` から構築する. 精度を省略したときは `poly.size()`, 係数列を省略したときは零級数になる.

### translator, convolution

```cpp
static Numeric_Theory_Translation<mint>& translator()
static vector<mint> convolution(const vector<mint> &A, const vector<mint> &B)
```

* `translator` は, 全ての `Fast_Power_Series<mint>` で共有される数論変換器を返す. `ntt` を直接使う処理 (Bostan–Mori 法など) から参照する.
* `convolution` は, 係数列 $A, B$ の畳み込みを求める.
* **計算量** : [Numeric_Theory_Translation](Numeric_Theory_Translation.md) の `convolution` と同じ.

### 積

```cpp
Fast_Power_Series& operator*=(const Fast_Power_Series &P)
friend Fast_Power_Series operator*(const Fast_Power_Series &lhs, const Fast_Power_Series &rhs)
Fast_Power_Series mul_poly(const Fast_Power_Series &P) const
```

* `*`, `*=` は, 精度を小さい方に合わせた積 (精度を超える項は切り捨てる) を求める.
* `mul_poly` は, 多項式としての積を求める. 精度は結果の長さになる.
* **計算量** : 2 つの係数列の長さの和を $L$ として, $O(L \log L)$ 時間.

### inverse_vector, inverse

```cpp
static vector<mint> inverse_vector(const vector<mint> &P, int d)
Fast_Power_Series inverse(int d = -1) const
```

* `inverse_vector` は, 係数列 $P$ を持つ級数の $\bmod{X^d}$ における逆元の係数列を求める.
* `inverse` は, $\bmod{X^d}$ における逆元を求める. $d = -1$ のときは $d$ は精度になる. $d$ が精度より大きいときは精度に切り詰める.
* **制約** : $P$ は空でなく, 定数項は $0$ でない (満たさないときは `assert` に失敗する).
* **計算量** : $O(d \log d)$ 時間.

### multiple_convolution

```cpp
static vector<mint> multiple_convolution(vector<vector<mint>> A)
```

* 係数列の列 $A_0, A_1, \dots$ について, 多項式としての総積の係数列を求める. $A$ が空のときは $\lbrace 1 \rbrace$ を返す.
* 先頭から 2 つずつ取り出して積を取り, 末尾に戻すことを繰り返す.
* **計算量** : 総積の長さを $L$, 多項式の個数を $K$ として, $O(L \log L \log K)$ 時間.

### 除算

```cpp
Fast_Power_Series& operator/=(const Fast_Power_Series &P)
friend Fast_Power_Series operator/(const Fast_Power_Series &lhs, const Fast_Power_Series &rhs)
```

* 形式的ベキ級数としての除算 $P_1 / P_2$ を, 精度を小さい方に合わせて求める.
* **制約** : $P_2$ の定数項は $0$ でない.
* **計算量** : 精度を $d$ として, $O(d \log d)$ 時間.

### div, %, divmod

```cpp
Fast_Power_Series div(const Fast_Power_Series &B)
Fast_Power_Series& operator%=(const Fast_Power_Series &B)
friend Fast_Power_Series operator%(const Fast_Power_Series &lhs, const Fast_Power_Series &rhs)
pair<Fast_Power_Series, Fast_Power_Series> divmod(const Fast_Power_Series &B)
```

* 多項式として $A = BQ + R$ とするときの, 商 $Q$ (`div`), 余り $R$ (`%`), 両方 (`divmod`) を求める.
* $A$ の次数が $B$ の次数より小さいとき, 商は $0$ である.
* **制約** : $B$ の最高次の係数は $0$ でない.
* **計算量** : $A, B$ の長さを $n, m$ として, $O(n \log n)$ 時間.

## History

|日付|内容|
|---|---|
|2026-11-28|Numeric_Theory_Translation から `inverse`, `multiple_convolution` を移した. CRTP 化し, 線形演算を基底に移した. `translator`, `convolution` を公開した.|
