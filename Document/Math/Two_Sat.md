---
title: 2-SAT
documentation_of: //Math/Two_SAT.hpp
---

## Outline

- 論理変数 $X_1, \dots, X_N$ 及び, これらの否定 $\lnot X_1, \dots, \lnot X_N$ をリテラルという.
- リテラル $V_1, \dots, V_K$ の論理和 $V_1 \lor \dots \lor V_K$ を節という.

SATISFIABILITY (SAT) とは, 次のような問題である.

> $2N$ 個のリテラルからなる論理式 $\varphi(X_1,\dots, X_N)$ に対して, これを $\mathbb{T}$ にするような $X_1, \dots, X_N$ への $\mathbb{T}, \mathbb{F}$ は存在するか?

また, SAT のうち, 次のような特別な場合には名前がついている.

- CNF-SAT : $\varphi(X_1, \dots, X_N)$ が節の論理積からなっているもの.
- 2-SAT : CNF-SAT のうち, 全ての節の中のリテラルが高々2つであるもの.

つまり, 2-SAT とは次のような問題である.

> リテラル全体の集合を $\mathcal{X}:=\\{X_1, \ldots, X_N, \lnot X_1, \dots, \lnot X_N\\}$ とする.
>
> $j=1,2, \dots, M$ に対して, $F_j, G_j \in \mathcal{X}$ とする.
>
> $$\varphi(X_1, \dots, X_N):=\bigwedge_{j=1}^M (F_j \lor G_j)$$
>
> と定めるとき, $\varphi(X_1, \dots, X_N)=\mathbb{T}$ となるような　$X_1, \dots, X_N$ への $\mathbb{T}, \mathbb{F}$ の割り当ては存在するか?

## Theory

### 充足可能の判定

$2N$ 頂点, $2M$ 辺の有向グラフ $D = (\mathcal{X}, A)$ を次のように定める.

- $A:=\\{\lnot F_j \Rightarrow G_j \mid 1 \leq j \leq M\\} \cup \\{\lnot G_j \Rightarrow F_j \mid 1 \leq j \leq M\\}$

このとき, 以下は同値である.

- (a) 充足可能
- (b) 全ての $i = 1, 2, \dots, N$ に対して, $X_i$ と $\lnot X_i$ は異なる強連結成分に属している.

$D$ における強連結成分を順に $C_1 \sqsupset C_2 \sqsupset \dots \sqsupset C_P$ とし $X \in \mathcal{X}$ が属している連結成分が $C_p$ であるとき, $\gamma(X) := p$ と定める.

このとき, $i=1,2, \dots, N$ に対して,

$$
  X_i = \begin{cases}
    \mathbb{T} & (\gamma(X_i)>\gamma(\lnot X_i)) \\
    \mathbb{F} & (\gamma(X_i)<\gamma(\lnot X_i))
  \end{cases}
$$

とすると, この $(X_1, \dots, X_N)$ によって $\varphi$ は充足可能になる.

### 有向グラフへの帰着

上での帰着方法は $F \Rightarrow G$ の形のものに限られていたが, 実際には多くのパターンで $F \Rightarrow G$ の形に帰着することができる.

|変換前|変換後|
|:---:|:---:|
|$X \Rightarrow Y$|$X \Rightarrow Y$|
|$X \lor Y$|$\lnot X \Rightarrow Y$|
|$\lnot (X \land Y)$|$X \Rightarrow \lnot Y$|
|$X = Y$|$(X \Rightarrow Y) \land (\lnot X \Rightarrow \lnot Y)$|
|$X \neq Y$|$(X \Rightarrow \lnot Y) \land (\lnot X \Rightarrow Y)$|
|$X$|$\lnot X \Rightarrow X$|
|$\lnot X$|$X \Rightarrow \lnot X$|

- $X_1 = X_2 = \dots = X_K$
  - 以下の $K$ 個の含意の連言
    - $X_1 \Rightarrow X_2$
    - $X_2 \Rightarrow X_3$
    - $\vdots$
    - $X_{K-1} \Rightarrow X_K$
    - $X_K \Rightarrow X_1$
- $X_1, \dots, X_K$ のうち, 高々1つが $\mathbb{T}$.
  - $K$ 個の変数 $Y_1, \dots, Y_K$ を追加し, 以下の $(3K-2)$ 個の連言に帰着させる.
    - $X_i \Rightarrow Y_i \quad (i=1,2, \dots, K)$
    - $Y_{i-1} \Rightarrow Y_i \quad (i=2,3, \dots, K)$
    - $\lnot (X_i \land Y_{i-1}) \quad  (i=2,3, \dots, K)$
    - 説明: $Y_i = X_1 \lor \dots \lor X_i$ であり, $Y_i$ は $X_i$ のある意味の累積和となっている. つまり, $X_i \land Y_{i-1}$ が満たされるということは, $X_1, \dots, X_{i-1}, X_i$ の中に満たされるものが $2$ つ以上あることを意味する.

## Contents

---

### Constructer

```cpp
Two_SAT(int N)
```

* $N$ 変数の 2-SAT を定義する.
* **計算量** : $O(N)$ Time.

---

### add_variable

```Python
add_variable()
```

* 変数を $1$ 個追加する.
* **返り値**
  * 新たに追加された変数の番号
* **計算量**
  * $O(1)$ Time.

---

### add_variables

```cpp
vector<int> add_variables(int k = 1)
```

* 変数を $k$ 個追加する.
* **返り値**
  * 新たに追加された変数の番号のリスト
* **計算量**
  * $O(k)$ Time.

---

### variable_number

```cpp
int variable_number()
```

* 現在の変数の数を返す.
* **返り値**
  * 変数の数
* **計算量**
  * $O(1)$ Time.

---

### add_imply

```cpp
(1) void add_imply(int i, bool f, int j, bool g)
(2) void add_imply(int i, int j)
```

* 制約を追加する.
  * (1) $(X_i = f) \Rightarrow (X_j = g)$
  * (2) リテラル $i \Rightarrow$ リテラル $j$ (負の数は `~i` で否定を表現する)
* **計算量**
  * $O(1)$ Time.

---

### add_or

```cpp
(1) void add_or(int i, bool f, int j, bool g)
(2) void add_or(int i, int j)
```

* 制約を追加する.
  * (1) $(X_i = f) \lor (X_j = g)$
  * (2) リテラル $i \lor$ リテラル $j$
* **計算量**
  * $O(1)$ Time.

---

### add_nand

```cpp
(1) void add_nand(int i, bool f, int j, bool g)
(2) void add_nand(int i, int j)
```

* 制約を追加する.
  * (1) $\lnot ((X_i = f) \land (X_j = g))$
  * (2) リテラル $i \text{ nand }$ リテラル $j$
* **計算量**
  * $O(1)$ Time.

---

### add_equal

```cpp
void add_equal(int i, int j)
```

* 制約 $X_i = X_j$ を追加する.
* **計算量**
  * $O(1)$ Time.

---

### add_not_equal

```cpp
void add_not_equal(int i, int j)
```

* 制約 $X_i \neq X_j$ を追加する.
* **計算量**
  * $O(1)$ Time.

---

### set_true

```cpp
void set_true(int i)
```

* 制約 $X_i = \mathbb{T}$ を追加する.
* **計算量**
  * $O(1)$ Time.

---

### set_false

```cpp
void set_false(int i)
```

* 制約 $X_i = \mathbb{F}$ を追加する.
* **計算量**
  * $O(1)$ Time.

---

### add_at_most_one

```cpp
(1) void add_at_most_one(const vector<int>& literals)
(2) void add_at_most_one(const vector<pair<int, bool>>& literals)
```

* 与えられたリテラルの集合のうち, 真になるものが高々 1 つであるという制約を追加する.
  * (1) リテラル $i_1, \dots, i_k$ のうち, 真になるのは高々 $1$ つ.
  * (2) $X_i = f_i$ という条件を満たすのは高々 $1$ つ.
* **計算量**
  * `literals` の長さを $k$ として, $O(k)$ Time.

---

### solve

```cpp
bool solve()
```

* 2-SAT を解き, 充足可能性を判定する.
* **返り値**
  * 充足可能であれば `true`, 不可能であれば `false`.
  * 解が `true` の場合, `answer` メンバー変数に各変数の真偽値が格納される.
* **計算量**
  * $O(N + M)$ Time. (ここで $N$ は変数の数,$M$ は制約数)

## History

|日付|内容|
|:---:|:---|
|2026/07/01| Two_SAT クラスの実装 |
