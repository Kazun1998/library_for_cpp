---
title: 第 I 種 Stirling 数
documentation_of: //Modulo_Polynomial/Stirling_1st.hpp
---

## Outline

第 I 種 Stirling 数 $S^{(1)}_{n,k}$ を求める.

## Define

第 I 種 Stirling 数 $S^{(1)}_{n,k}$ とは, 以下の展開係数として定義される.

$$ x (x+1) (x+2) \cdots (x+n-1) = \sum_{k=0}^n S^{(1)}_{n,k} x^k $$

## Theory

### 漸化式としての特徴づけ
第 I 種 Stirling 数 $S^{(1)}_{n,k}$ について, 以下が成り立つ.

$$ S^{(1)}_{n,k} = S^{(1)}_{n-1,k-1} + (n-1) S^{(1)}_{n-1,k} \quad (n \geq 1, 0 \leq k \leq n) $$

#### 証明

$$\begin{align*}
    \sum_{k=0}^n S^{(1)}_{n,k} x^k
    &= x (x+1) (x+2) \cdots (x+n-1) \\
    &= \left(\sum_{k=0}^{n-1} S^{(1)}_{n-1,k} x^k \right) (x+n-1) \\
    &= 1 + \sum_{k=1}^n \left(S^{(1)}_{n-1,k-1} + (n-1) S^{(1)}_{n-1,k} \right) x^k \\
\end{align*}$$

より,

$$ S^{(1)}_{n,k} = S^{(1)}_{n-1,k-1} + (n-1) S^{(1)}_{n-1,k} $$

となる.

$\square$

### 組み合わせ理論による特徴づけ
$S^{(1)}_{n,k}$ について, 以下が成り立つ.

> $n$ 次置換群 $\mathfrak{S}\_n$ の元のうち, ちょうど $k$ 個の互いに交わらない巡回置換の積で表せる置換の数は $S^{(1)}_{n,k}$ である.

#### 証明

$n$ 次置換群 $\sigma \in \mathfrak{S}\_n$ の元のうち, ちょうど $k$ 個の互いに交わらない巡回置換の数を $T_{n,k}$ とする. これは次のようにして作ることができる.

##### $\sigma(n) = n$ とする場合

$(n)$ で $1$ 個の巡回置換になる. そのため, 残りは $1,2,\dots,n-1$ のちょうど $(k-1)$ 個の互いに交わらない巡回置換である.

##### $\sigma(n) \neq n$ とする場合

$1,2,\dots,n-1$ の $k$ 個の個の互いに交わらない $k$ 個の巡回置換の積のどこかに $n$ を挿入すると, この場合の置換をもれなく, 重複なく列挙できる.

$1,2,\dots,n-1$ の $k$ 個の個の互いに交わらない $k$ 個の巡回置換の積の作り方は $S^{(1)}_{n-1,k}$ 個, それぞれの巡回置換の積について, 挿入する箇所は $(n-1)$ 箇所である.

よって, 合計 $(n-1) S^{(1)}_{n-1,k}$ 個である.

以上を合計して,

$$ T_{n,k} = T_{n-1,k-1} + (n-1) T_{n-1,k} $$

である.

この漸化式は, $S^{(1)}\_{n,k}$ と一致する. また, $T_{0,0} = 1$ であるため, $T_{n,k} = S^{(1)}\_{n,k}$ となる.

$\square$

### 多項式による性質

第 I 種 Stirling 数について, 以下が成り立つ.

$$ t (t-1) (t-2) \cdots (t-(n-1)) = \sum_{k=0}^n (-1)^{n-k} S^{(1)}_{n,k} t^k $$

### 証明

$$\begin{align*}
    t (t-1) (t-2) \cdots (t-(n-1))
    &= (-1)^n \left. \Bigl[x (x+1) (t+2) \cdots (x+n-1) \Bigr] \right|_{x=-t} \\
    &= (-1)^n \left. \sum_{k=0}^n S^{(1)}_{n,k} x^k \right|_{x=-t} \\
    &= (-1)^n \sum_{k=0}^n S^{(1)}_{n,k} (-t)^k \\
    &= (-1)^n \sum_{k=0}^n (-1)^k S^{(1)}_{n,k} t^k \\
    &= \sum_{k=0}^n (-1)^{n-k} S^{(1)}_{n,k} t^k \\
\end{align*}$$

なお, 第 I 種 Stirling 数を $(-1)^{n-k} S^{(1)}_{n,k}$ として定義する流儀もある.

## Contents

```cpp
vector<mint> Stirling_1st(int N, bool sign = false)
```

* 第 I 種 Stirling 数 $S^{(1)}_{N,0}, S^{(1)}_{N,1}, \dots, S^{(1)}_{N,N}$ を求める.
* **引数**
  * `sign`: `true` にすると, 第 I 種 Stirling 数が符号を付けたバージョンの返り値になる. つまり, $(-1)^{N-k} S^{(1)}_{N,k}$ になる.
* **計算量** : $O(N \log N)$ 時間.

