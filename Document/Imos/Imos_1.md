---
title: いもす法 (1 次元 0 次)
documentation_of: //Imos/Imos_1.hpp
---

## Outline

1 次元いもす法 (Imos Method) を行うためのクラス.
特定の区間へ一括して加算を行うクエリを多数処理した後, 最後に累積和をとることで, 各要素の最終的な値を高速に求めることができる.

## Theory

### 累積和作用素と差分作用素

可換環 $A$ 上の列の集合を $\mathcal{A}$ とする. $\mathcal{A}$ 上の作用素 $S: \mathcal{A} \to \mathcal{A}$ を $\boldsymbol{x} = (x_i) \in \mathcal{A}$ に対して,

$$ S \boldsymbol{x} := \left(\sum_{p=0}^i x_p \right) $$

で定める. この $S$ を累積和作用素という.

累積和作用素 $S$ は同型写像である. つまり, 逆作用素が存在する.

その逆作用素 $D$ は恒等作用素 $I$ をシフト作用素 $R$ を用いて,

$$ D = I - R $$

と書ける. この $D$ を差分作用素という. つまり, $\boldsymbol{y} \in \mathcal{A}$ に対して,

$$ D \boldsymbol{y} = (y_0, y_1 - y_0, y_2 - y_1, \dots ) $$

である.

### いもす法への応用

いもす法は, 以下の問いを高速に答えることができる.

> $Q$ 個の $l_q \leq r_q$ を満たす非負整数の組 $(l_q, r_q)$ と $\alpha_q \in A$ が与えられる.
>
> このとき, $\displaystyle \sum_{q=1}^Q \alpha_q \left(\sum_{i=l_q}^{r_q} \boldsymbol{e}_i \right)$ の先頭 $N$ 項を求めろ.

愚直な方法だと, $O(NQ)$ 時間になるが, いもす法を使うことによって, $O(N+Q)$ 時間に短縮できる.

$$
\begin{align*}
\sum_{i=l_q}^{r_q} \boldsymbol{e}_i
&= SD \left(\sum_{i=l}^{r} \boldsymbol{e}_i \right) \\
&= S \left(\sum_{i=l}^{r} D \boldsymbol{e}_i \right) \\
&= S \left(\sum_{i=l}^{r} \left(I \boldsymbol{e}_i - R \boldsymbol{e}_i \right)\right) \\
&= S \left(\sum_{i=l}^{r} \boldsymbol{e}_i - \boldsymbol{e}_{i+1} \right) \\
&= S \left(\boldsymbol{e}_l - \boldsymbol{e}_{r+1} \right)
\end{align*}
$$

であるので,

$$
\begin{align*}
\sum_{q=1}^Q \alpha_q \left(\sum_{i=l_q}^{r_q} \boldsymbol{e}_i \right)
&= \sum_{q=1}^Q \alpha_q S \left(\boldsymbol{e}_{l_q} - \boldsymbol{e}_{r_q+1} \right) \\
&= S \left(\sum_{q=1}^Q \left(\alpha_q \boldsymbol{e}_{l_q} - \alpha_q \boldsymbol{e}_{r_q+1} \right)\right)
\end{align*}
$$

となる.

$S$ の中身は $2Q$ 個の項の和である. また, 前 $N$ 項の累積和は $O(N)$ 時間で計算できる.

よって, 合計で $O(N+Q)$ 時間で先頭 $N$ 項を求められる.

## Contents

### Constructor

```cpp
Imos_1(const int n)
```

* サイズ $n$ の 1 次元いもす法オブジェクトを生成する.
* **引数**
  * $n$: 要素数
* **計算量** : $O(n)$ 時間.

### add

```cpp
void add(int l, int r, const T x)
void add(const int l, const int r)
```

* 閉区間 $[l, r]$ の各要素に加算を行う.
* 引数の範囲が $[0, n-1]$ の範囲外にある場合は, 自動的に $[0, n-1]$ の範囲にクリップ（丸め込み）される. クリップされた結果, 閉区間が正しく構成できない場合 (例: $l > r$ または範囲外) は何も行わない.
* **引数**
  * (1) (引数が3つの場合)
    * $l$: 閉区間の左端
    * $r$: 閉区間の右端
    * $x$: 加算値
  * (2) (引数が2つの場合)
    * $l$: 閉区間の左端
    * $r$: 閉区間の右端
* **計算量** : $O(1)$ 時間.

### cumulate

```cpp
std::vector<T> cumulate()
```

* これまでの加算クエリの結果を累積し, 各要素の最終的な値からなるサイズ $n$ の配列を生成・返却する.
* **計算量** : $O(n)$ 時間.

### clear

```cpp
void clear()
```

* 内部の差分配列を $0$ で初期化し, 再度 `add` を行えるようにクリアする.
* **計算量** : $O(n)$ 時間.

|日付|内容|
|:---:|:---|
|2026/05/27| いもす法 (1 次元 0 次) の実装 |
