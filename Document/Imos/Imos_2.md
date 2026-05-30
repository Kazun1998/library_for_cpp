---
title: いもす法 (2 次元 0 次)
documentation_of: //Imos/Imos_2.hpp
---

## Outline

2 次元いもす法を行うためのクラス.

## Theory

[1 次元バージョン](Imos_1.hpp) の記号を引き継ぐことにする.

$2$ 次元いもす法は, 以下の問いを高速に答えることができる. これ以降, $\otimes$ で線形写像やベクトルのテンソル積を表すことにする.

> $Q$ 個の $u_q \leq d_q, l_q \leq r_q$ を満たす非負整数の組 $(u_q, d_q, l_q, r_q)$ と $\alpha_q \in A$ が与えられる.
>
> このとき, $\displaystyle \sum_{q=1}^Q \alpha_q \left(\sum_{\substack{u_q \leq i \leq d_q \\ l_q \leq j \leq r_q}} \boldsymbol{e}_i \otimes \boldsymbol{e}_j \right)$ の $0 \leq i < H, 0 \leq j < W$ における項を求めろ.

愚直な方法だと, $O(NHQ)$ 時間になるが, いもす法を使うことによって, $O(NH+Q)$ 時間に短縮できる.

$$
\begin{align*}
\sum_{\substack{u \leq i \leq d \\ l \leq j \leq r}} \boldsymbol{e}_i \otimes \boldsymbol{e}_j
&= \sum_{i=u}^d \left( \sum_{j=l}^r \boldsymbol{e}_i \otimes \boldsymbol{e}_j \right) \\
&= \sum_{i=u}^d \left(\boldsymbol{e}_i \otimes \left( \sum_{j=l}^r \boldsymbol{e}_j \right) \right) \\
&= \left(\sum_{i=u}^d \boldsymbol{e}_i \right) \otimes \left( \sum_{j=l}^r \boldsymbol{e}_j \right) \\
&= \left(S(\boldsymbol{e}_u - \boldsymbol{e}_{d+1}) \right) \otimes \left(S(\boldsymbol{e}_l - \boldsymbol{e}_{r+1}) \right) \\
&= (S \otimes S) \left(\left(\boldsymbol{e}_u - \boldsymbol{e}_{d+1} \right) \otimes \left( \boldsymbol{e}_l - \boldsymbol{e}_{r+1} \right) \right) \\
&= (S \otimes S) \left(\boldsymbol{e}_u \otimes \boldsymbol{e}_l - \boldsymbol{e}_u \otimes \boldsymbol{e}_{r+1} - \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_l + \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_{r+1} \right) \\
\end{align*}
$$

である. よって,

$$
\begin{align*}
\sum_{q=1}^Q \alpha_q \left(\sum_{\substack{u_q \leq i \leq d_q \\ l_q \leq j \leq r_q}} \boldsymbol{e}_i \otimes \boldsymbol{e}_j \right)
&= \sum_{q=1}^Q \alpha_q (S \otimes S) \left(\boldsymbol{e}_u \otimes \boldsymbol{e}_l - \boldsymbol{e}_u \otimes \boldsymbol{e}_{r+1} - \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_l + \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_{r+1} \right) \\
&= \sum_{q=1}^Q (S \otimes S) \left(\alpha_q \boldsymbol{e}_u \otimes \boldsymbol{e}_l - \alpha_q \boldsymbol{e}_u \otimes \boldsymbol{e}_{r+1} - \alpha_q \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_l + \alpha_q \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_{r+1} \right) \\
\end{align*}
$$

となる.

$S$ の中身は $4Q$ 個の項の和である.

ここから, $S \otimes S$ の計算を行う.

$$ \sum_{q=1}^Q (S \otimes S) \left(\alpha_q \boldsymbol{e}_u \otimes \boldsymbol{e}_l - \alpha_q \boldsymbol{e}_u \otimes \boldsymbol{e}_{r+1} - \alpha_q \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_l + \alpha_q \boldsymbol{e}_{d+1} \otimes \boldsymbol{e}_{r+1} \right) = \sum_{i,j} \beta_{i,j} \boldsymbol{e}_i \otimes \boldsymbol{e}_j $$

と書くことができる.

$$ S \otimes S = (S \otimes I)(I \otimes S)$$

であることに注意する.

各 $i, j$ に対して,

$$
\begin{align*}
  (I \otimes S)(\boldsymbol{e}_i \otimes \boldsymbol{e}_j)
  &= (I \boldsymbol{e}_i) \otimes (S \boldsymbol{e}_j) \\
  &= \boldsymbol{e}_i \otimes \sum_{q \geq j} \boldsymbol{e}_q \\
  &= \sum_{q \geq j }\boldsymbol{e}_i \otimes  \boldsymbol{e}_q
\end{align*}
$$

である.

よって,

$$
\begin{align*}
  (I \otimes S)\left(\sum_{i,j} \beta_{i,j} \boldsymbol{e}_i \otimes \boldsymbol{e}_j \right)
  &= \sum_{i,j} \beta_{i,j} (I \otimes S) \left(\boldsymbol{e}_i \otimes \boldsymbol{e}_j \right) \\
  &= \sum_{i,j} \beta_{i,j} \sum_{q \geq j} \boldsymbol{e}_i \otimes  \boldsymbol{e}_q \\
  &= \sum_{i,j} \left(\sum_{q=0}^j \beta_{i,q} \right) \boldsymbol{e}_i \otimes \boldsymbol{e}_j \\
\end{align*}
$$

である.

$$ \gamma_{i,j} := \sum_{q=0}^j \beta_{i,q} $$

とおく.

同様にして,

$$\begin{align*}
  (I \otimes S) \left( \sum_{i, j} \gamma_{i,j} \boldsymbol{e}_i \otimes \boldsymbol{e}_j \right)
  &= \sum_{i,j} \gamma_{i,j} (I \otimes S) \left(\boldsymbol{e}_i \otimes \boldsymbol{e}_j \right) \\
  &= \sum_{i,j} \left(\sum_{p=0}^i \gamma_{p,j} \right) \left(\boldsymbol{e}_i \otimes \boldsymbol{e}_j \right)
\end{align*}$$

となる.

ここで,

$$ \sum_{p=0}^i \gamma_{i,j} = \sum_{p=0}^i \sum_{q=0}^j \beta_{i,j} $$

である.

よって, $2$ 次元累積和とは,

$$ \left(\beta_{i,j} \right) \mapsto \left(\sum_{p=0}^i \sum_{q=0}^j \beta_{i,j} \right) $$

とする変換である.

この変換は $(S \otimes I), (I \otimes S)$ を連続して計算することによって, $O(HW)$ 時間で求められる.


## Contents

### Constructor

```cpp
Imos_2(const int h, const int w)
```

* サイズ $h \times w$ の 2 次元いもす法オブジェクトを生成する.
* **引数**
  * $h$: 縦方向の要素数
  * $w$: 横方向の要素数
* **計算量** : $O(hw)$ 時間.

### add

```cpp
void add(int u, int d, int l, int r, const T x)
void add(const int u, const int d, const int l, const int r)
```

* 閉区間 $[u, d] \times [l, r]$ の各要素に加算を行う.
* 引数の範囲が $[0, h-1] \times [0, w-1]$ の範囲外にある場合は, 自動的に $[0, h-1] \times [0, w-1]$ の範囲にクリップ（丸め込み）される. クリップされた結果, 閉区間が正しく構成できない場合 (例: $u > d$ または $l > r$ または範囲外) は何も行わない.
* **引数**
  * (1) (引数が5つの場合)
    * $u$: 閉区間の上端
    * $d$: 閉区間の下端
    * $l$: 閉区間の左端
    * $r$: 閉区間の右端
    * $x$: 加算値
  * (2) (引数が4つの場合)
    * $u$: 閉区間の上端
    * $d$: 閉区間の下端
    * $l$: 閉区間の左端
    * $r$: 閉区間の右端
* **計算量** : $O(1)$ 時間.

### cumulate

```cpp
std::vector<std::vector<T>> cumulate()
```

* これまでの加算クエリの結果を累積し, 各要素の最終的な値からなるサイズ $h \times w$ の 2 次元配列を生成・返却する.
* **計算量** : $O(hw)$ 時間.

### clear

```cpp
void clear()
```

* 内部の差分配列を $0$ で初期化し, 再度 `add` を行えるようにクリアする.
* **計算量** : $O(hw)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/05/30| いもす法 (2 次元 0 次) の実装 |
