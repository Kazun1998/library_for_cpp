---
title: 整数の桁
documentation_of: //Integer/Digit.hpp
---

## Outline

整数の表示や桁に関する計算を行う.

## Theory

### b 進表記

<div class="theorem" markdown="1">

定理 1
---

$b$ を $2$ 以上の整数とする.

正の整数 $n$ に対して, 以下を満たす整数の有限列 $a$ がただ一つ存在する. ただし, $d$ を $a$ の長さとして, $a = (a_{d-1}, a_{d-2}, \dots, a_1, a_0)$ と添字を付ける.

* $i = d-1, d-2, \dots, 1, 0$ に対して, $0 \leq a_i < b$ である.
* $a_{d-1} \neq 0$.
* $n = a_{d-1} b^{d-1} + \dots + a_1 b + a_0$.

</div>

<div class="proof" markdown="1">

証明
---

$n$ に関する累積帰納法で示す. $n$ を $b$ で割った商を $q$, 余りを $r$ とする. すなわち, $n = qb + r$ かつ $0 \leq r < b$ である.

**存在**: $n < b$ のときは, $d = 1, a_0 = n$ とすればよい. $n \geq b$ のときは $1 \leq q < n$ であるから, 帰納法の仮定より, $q$ に対して条件を満たす列 $(e_{k-1}, \dots, e_0)$ が存在する. このとき, 長さ $k + 1$ の列 $a = (e_{k-1}, \dots, e_0, r)$ は $n$ に対して条件を満たす.

**一意性**: 長さ $d$ の列 $a$ が $n$ に対して条件を満たすとする. $n = (a_{d-1} b^{d-2} + \dots + a_1) b + a_0$ かつ $0 \leq a_0 < b$ であるから, 商と余りの一意性より $a_0 = r$ である. また,

* $d = 1$ のとき, $n = a_0 < b$ である.
* $d \geq 2$ のとき, $n \geq a_{d-1} b^{d-1} \geq b$ である.

よって, $n < b$ ならば $a = (r)$ に限る. $n \geq b$ ならば $d \geq 2$ であり, 列 $(a_{d-1}, \dots, a_1)$ は $q = a_{d-1} b^{d-2} + \dots + a_1$ に対して条件を満たす. $1 \leq q < n$ であるから, 帰納法の仮定より, この列は $q$ から一意に定まる. 以上より, $a$ は一意である.

</div>

<div class="definition" markdown="1">

定義 2
---

$b$ を $2$ 以上の整数とし, 正の整数 $n$ に対して, 定理 1 の列を $a = (a_{d-1}, \dots, a_1, a_0)$ とする.

* $b$ を底や基数という.
* $a$ を $n$ の $b$ 進表記という.
* $a$ の長さ $d$ を $n$ の $b$ 進表記における桁数という.
* $a_i$ を $n$ の $b$ 進表記における $b^i$ の位という.
  * 特に, $b^{d-1}$ の位 $a_{d-1}$ を $n$ の $b$ 進表記における最高位という.

また, $0$ の $b$ 進表記は空列とする. すなわち, $0$ の桁数は $0$ である.

$c_0, c_1, \dots, c_{b-1}$ を互いに異なる文字とするとき, $n$ を

$$ n = (c_{a_{d-1}} c_{a_{d-2}} \cdots c_{a_1} c_{a_0})_b $$

と書くこともある.

</div>

### 数字和/数字根

<div class="definition" markdown="1">

定義 3
---

$b$ を $2$ 以上の整数, $n$ を正の整数として, $a = (a_{d-1}, a_{d-2}, \dots, a_1, a_0)$ を $n$ の $b$ 進表記とする.

このとき,

$$ S_b(n) := \sum_{k=0}^{d-1} a_k $$

を $n$ の $b$ 進数字和という.

また, $0$ の $b$ 進数字和は $S_b(0) := 0$ とする.

</div>

<div class="proposition" markdown="1">

命題 4
---

$b$ を $2$ 以上の整数, $n$ を非負整数とする. このとき,

$$ n \equiv S_b(n) \pmod{(b-1)} $$

である.

</div>

<div class="proof" markdown="1">

証明
---

$n = 0$ のときは明らかである. $n \geq 1$ のとき, $n$ の $b$ 進表記を $(a_{d-1}, \dots, a_0)$ とする. $b \equiv 1 \pmod{(b-1)}$ より, 任意の非負整数 $k$ に対して $b^k \equiv 1 \pmod{(b-1)}$ であるから,

$$ n = \sum_{k=0}^{d-1} a_k b^k \equiv \sum_{k=0}^{d-1} a_k = S_b(n) \pmod{(b-1)} $$

である.

</div>

<div class="proposition" markdown="1">

命題 5
---

$b$ を $2$ 以上の整数, $n$ を非負整数とする. 次のようにして整数列 $(x_k)$ を定める.

* $x_0 := n$.
* $x_k := S_b(x_{k-1}) \quad (k \geq 1)$.

このとき, $(x_k)$ は有限個の例外を除いて定数列である.

</div>

<div class="proof" markdown="1">

証明
---

まず, 非負整数 $m$ に対して次が成り立つことを示す.

* $0 \leq m < b$ ならば $S_b(m) = m$.
* $m \geq b$ ならば $S_b(m) < m$.

$m = 0$ のときは定義より $S_b(0) = 0$ である. $1 \leq m < b$ のときは, $m$ の $b$ 進表記は $(m)$ であるから $S_b(m) = m$ である. $m \geq b$ のときは, 定理 1 の証明より $m$ の桁数 $d$ は $d \geq 2$ であり, $m$ の $b$ 進表記を $(a_{d-1}, \dots, a_0)$ とすると,

$$ m - S_b(m) = \sum_{k=1}^{d-1} a_k \left( b^k - 1 \right) \geq a_{d-1} \left( b^{d-1} - 1 \right) \geq 1 $$

である.

よって, $x_k \geq b$ である間は $(x_k)$ は非負整数の狭義単調減少列であるから, $x_K < b$ となる $K$ が存在する. このとき, $k \geq K$ に対して $x_k = x_K$ である.

</div>

<div class="definition" markdown="1">

定義 6
---

命題 5 の数列 $(x_k)$ が最終的にとる値を, $n$ の $b$ 進数字根という.

</div>

<div class="proposition" markdown="1">

命題 7
---

$b$ を $2$ 以上の整数, $n$ を非負整数とし, $n$ の $b$ 進数字根を $r$ とする. このとき, 以下が成り立つ.

$$ r = \begin{cases}
  0 & (n = 0) \\
  n \bmod (b - 1) & (n \not \equiv 0 \pmod{(b-1)}) \\
  b - 1 & (n > 0 \land (b-1) \mid n)
\end{cases}$$

</div>

<div class="proof" markdown="1">

証明
---

命題 5 と同様に, $x_0 := n, x_k := S_b(x_{k-1}) \ (k \geq 1)$ とする. 命題 5 の証明より, $x_K < b$ となる $K$ が存在し, $r = x_K$ である. 特に, $0 \leq r < b$ である.

また, 命題 4 より, 任意の $k \geq 1$ に対して $x_k = S_b(x_{k-1}) \equiv x_{k-1} \pmod{(b-1)}$ であるから, $r = x_K \equiv x_0 = n \pmod{(b-1)}$ である.

$n = 0$ のとき, $S_b(0) = 0$ より, 任意の $k$ に対して $x_k = 0$ であるから, $r = 0$ である.

$n > 0$ のとき, 正の整数 $m$ の $b$ 進表記を $(a_{d-1}, \dots, a_0)$ とすると, $S_b(m) \geq a_{d-1} \geq 1$ である. よって, 帰納的に任意の $k$ に対して $x_k \geq 1$ であり, 特に $1 \leq r \leq b - 1$ である.

$1, 2, \dots, b-1$ は $b - 1$ を法としてどの 2 つも合同でないから, $1 \leq r \leq b-1$ かつ $r \equiv n \pmod{(b-1)}$ を満たす $r$ はただ一つである. したがって,

* $n \not\equiv 0 \pmod{(b-1)}$ のとき, $1 \leq n \bmod (b-1) \leq b - 2$ であり, $n \bmod (b-1) \equiv n \pmod{(b-1)}$ であるから, $r = n \bmod (b-1)$ である.
* $(b-1) \mid n$ のとき, $b - 1 \equiv 0 \equiv n \pmod{(b-1)}$ であるから, $r = b - 1$ である.

</div>

## Remark

このライブラリの関数は, $b$ 進表記を最高位 $a_{d-1}$ から $a_0$ の順に並べた列 $(a_{d-1}, a_{d-2}, \dots, a_1, a_0)$ として扱う.

## Contents

### Integer_Digits

```cpp
vector<ll> Integer_Digits(ll N, const ll b = 10, const int l = -1)
```

* $\lvert N \rvert$ の $b$ 進表記を求める ($N$ の符号は無視される).
* **入力**
  * $b$ : 基数. デフォルトは $b = 10$.
  * $l$ : 出力される長さについて制御する.
    * $l = -1$ のときは, 厳密な意味での $b$ 進表記が返される. ただし, $N = 0$ のときは $(0)$ が返される.
    * $l \geq 0$ のときは, 長さが $l$ になるように調整される. 具体的には, $N$ の $b$ 進表記での表示を $a = (a_{d-1}, \dots, a_1, a_0)$ とするとき, それぞれ以下のようになる.
      * $l \gt d$ のとき: 返り値は $(\underbrace{0, \dots, 0}\_{l-d}, a_{d-1}, \dots, a_1, a_0)$ となる.
      * $l \leq d$ のとき: 返り値は $(a_{l-1}, \dots, a_1, a_0)$ となる.
* **制約**
  * $b \geq 2$ (満たさない場合は `BaseException` が送出される).
  * $l = -1$ または $l \geq 0$.
  * $N \neq -2^{63}$.
* **計算量** : $l = -1$ のとき $O \left( \log_b \lvert N \rvert \right)$ 時間, $l \geq 0$ のとき $O(l)$ 時間.

### Integer_Length

```cpp
int Integer_Length(ll N, const ll b = 10)
```

* $\lvert N \rvert$ の $b$ 進表記における桁数を求める ($N$ の符号は無視される).
* **入力**
  * $b$ : 基数. デフォルトは $b = 10$.
* **注意** : $0$ の桁数は $0$ とする. したがって, `Integer_Length(0)` と `Integer_Digits(0).size()` は一致しない.
* **制約**
  * $b \geq 2$ (満たさない場合は `BaseException` が送出される).
  * $N \neq -2^{63}$.
* **計算量** : $O \left( \log_b \lvert N \rvert \right)$ 時間.

### Digit_Sum

```cpp
ll Digit_Sum(ll N, const ll b = 10)
```

* $\lvert N \rvert$ の $b$ 進表記における数字和を求める ($N$ の符号は無視される).
* **入力**
  * $b$ : 基数. デフォルトは $b = 10$.
* **制約**
  * $b \geq 2$ (満たさない場合は `BaseException` が送出される).
  * $N \neq -2^{63}$.
* **計算量** : $O \left( \log_b \lvert N \rvert \right)$ 時間.

### Digit_Count

```cpp
vector<ll> Digit_Count(ll N, const ll b = 10)
```

* $\lvert N \rvert$ の $b$ 進表記における各数の出現回数を求める ($N$ の符号は無視される).
* **入力**
  * $b$ : 基数. デフォルトは $b = 10$.
* **出力**
  * 長さ $b$ のリスト. 第 $j$ 要素には, $\lvert N \rvert$ の $b$ 進表記における $j$ の出現回数が格納されている.
  * $N = 0$ のときは, `Integer_Digits` と同様に $(0)$ を表記とみなすため, 第 $0$ 要素が $1$ になる.
* **制約**
  * $b \geq 2$ (満たさない場合は `BaseException` が送出される).
  * $N \neq -2^{63}$.
  * 長さ $b$ の配列を確保するため, $b$ が大きすぎるとメモリが不足する.
* **計算量** : $O \left( b + \log_b \lvert N \rvert \right)$ 時間, $O(b)$ 空間.

### From_Digits

```cpp
ll From_Digits(const vector<ll> &digits, const ll b = 10)
```

* $b$ 進表記が `digits` となる整数を求める (`Integer_Digits` の逆関数).
* **入力**
  * `digits` : 最上位桁から最下位桁の順に並べた数のリスト.
  * $b$ : 基数. デフォルトは $b = 10$.
* **制約**
  * $b \geq 2$ (満たさない場合は `BaseException` が送出される).
* **注意**
  * `digits` の各要素が $0$ 以上 $b$ 未満であるかは検査しない. `digits` $= (c_{L-1}, \dots, c_1, c_0)$ とするとき, 範囲外の要素があっても $\displaystyle \sum_{i=0}^{L-1} c_i b^i$ をそのまま計算した値を返す ($L$ は `digits` の長さ).
  * オーバーフローに注意.
* **計算量** : $L$ を `digits` の長さとして, $O(L)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/11/20|ドキュメントの誤記修正, 制約の追記, Theory の整理と証明の追加|
|2025/11/24|引数の変更 & ドキュメントの追加|