---
title: Rolling Hash 基底クラス
documentation_of: //Rolling_Hash/Rolling_Hash_Base.hpp
---

## Outline

Rolling Hash に関する基底クラスを提供する

## Theory

$\mathcal{A}$ をアルファベット (文字の集合) として, $R$ を可換環とする.

$b \in R$ を適当にとる. また, 文字に関する単射 $h: \mathcal{A} \to R$ をとる (単射でないと, 異なる文字を同一視してしまう).

このとき, $\mathcal{A}$ 上の列 $X = (x_i)_{i=0}^{n-1}$ に関する Rolling Hash $\textrm{hash}(X)$ を

$$ \textrm{hash}(X) := \sum_{i=0}^{n-1} h(x_i) b^{n-1-i} $$

と定義する.

$R$ 上の列 $A = (a_i)_{i=0}^{n-1}$ に対して, $H_0, H_1, \dots, H_n$ を

$$ H_i := \textrm{hash}(A[0:i)) $$

で定める (ただし $A[l:r)$ は $A$ の半開区間 $[l, r)$ に対応する連続部分列を表す).

すると, $A$ の連続部分列 $A[l:r)$ に対する $\textrm{hash}(A[l:r))$ は

$$ \textrm{hash}(A[l:r)) = H_r - H_l \, b^{r-l} $$

で求められる.

ここで, $H_0, H_1, \dots, H_n$ は

$$ H_0 = 0, \quad H_i = b H_{i-1} + h(a_{i-1}) $$

によって求められる.

以上から, 連続部分列に対するハッシュ値を前計算 $O(n)$ 時間, クエリを $O(1)$ 時間/クエリで求められる.

## Contents

`Rolling_Hash_Base<F, Derived>` は Rolling Hash を実現するクラス群 (`Rolling_Hash<F>`, `Rolling_Hash_Mersenne` など) の共通処理をまとめた基底クラスであり, 直接インスタンス化することは想定していない (コンストラクタは `protected`).

`Derived` は `one() / zero() / mul(a, b) / add(a, b) / sub(a, b)` (それぞれ $R$ の単位元, 零元, 乗法, 加法, 減法に対応) を実装している必要がある.

### size

```cpp
int size() const
```

* 元の列 $A$ の長さ $n$ を返す.
* **計算量**
  * $O(1)$ 時間

### get_base

```cpp
F get_base() const
```

* 基数 $b$ を返す.
* **計算量**
  * $O(1)$ 時間

### get (1変数)

```cpp
F get(const int p) const
```

* $\textrm{hash}(A[0:p))$, すなわち $H_p$ を返す.
* **引数**
  * $p$: 右端 (含まれない)
* **計算量**
  * $O(1)$ 時間

### get (2変数)

```cpp
F get(const int l, const int r) const
```

* $\textrm{hash}(A[l:r))$ を返す.
* **引数**
  * $l$: 左端 (含まれる)
  * $r$: 右端 (含まれない)
* **計算量**
  * $O(1)$ 時間

### docking

```cpp
F docking(const int l0, const int r0, const int l1, const int r1) const
```

* $A[l_0:r_0)$ と $A[l_1:r_1)$ をこの順に連結した列に対する Rolling Hash 値, すなわち $\textrm{hash}(A[l_0:r_0)) \cdot b^{r_1-l_1} + \textrm{hash}(A[l_1:r_1))$ を返す.
* **引数**
  * $l_0, r_0$: 前半区間 ($[l_0, r_0)$)
  * $l_1, r_1$: 後半区間 ($[l_1, r_1)$)
* **計算量**
  * $O(1)$ 時間

### hashing

```cpp
F hashing(const vector<F> &X) const
```

* この Rolling Hash と同じ基数 $b$ を用いて, 列 $X$ 全体の $\textrm{hash}(X)$ を求める.
* **引数**
  * `X`: ハッシュ値を求めたい列
* **計算量**
  * $O(\lvert X \rvert)$ 時間

### count

```cpp
int count(const vector<F> &X, int start = 0) const
```

* $A[\bullet : \bullet + \lvert X \rvert)$ が $X$ と一致するような開始位置が, $\texttt{start}$ 以上にいくつあるかを返す.
* **引数**
  * `X`: 探索するパターン
  * `start`: 探索を開始する位置 (省略時は $0$)
* **計算量**
  * $O(n)$ 時間

### find

```cpp
int find(const vector<F> &X, int start = 0) const
```

* $A$ 内で $X$ が最初に出現する位置 ($\texttt{start}$ 以上で最小の位置) を返す. 存在しなければ $-1$ を返す.
* **引数**
  * `X`: 探索するパターン
  * `start`: 探索を開始する位置 (省略時は $0$)
* **計算量**
  * $O(n)$ 時間

### rfind

```cpp
int rfind(const vector<F> &X, int pos = size()) const
```

* $A$ 内で $X$ が出現する位置のうち, $\texttt{pos}$ 以下で最大のものを返す. 存在しなければ $-1$ を返す. (`std::string::rfind` と同じ仕様)
* **引数**
  * `X`: 探索するパターン
  * `pos`: 探索範囲の上限 (省略時は $n$, すなわち列全体)
* **計算量**
  * $O(n)$ 時間

## History

|日付|内容|
|:---:|:---:|
|2026/08/09| Rolling_Hash_Base 実装 |
