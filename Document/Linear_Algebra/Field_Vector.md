---
title: 数ベクトル
documentation_of: //Linear_Algebra/Field_Vector.hpp
---

## Outline

体 $F$ 上のベクトル空間に関する機能を提供する.

## Theory

### ベクトル空間

$F$ を体とする. 集合 $V$ が以下の条件を満たすとき, $V$ を **$F$ 上のベクトル空間** (線形空間) という.

$V$ には加法 $+: V \times V \to V$ とスカラー倍 $\cdot: F \times V \to V$ が定義されており, 以下を満たす.

* (V1). 任意の $u,v,w \in V$ に対して, $(u + v) + w = u + (v + w)$.
* (V2). 任意の $u,v \in V$ に対して, $u + v = v + u$.
* (V3). 次を満たす $0 \in V$ が存在する: 任意の $v \in V$ に対して, $v + 0 = v$.
* (V4). 任意の $v \in V$ に対して, $v + (-v) = 0$ となる $-v \in V$ が存在する.
* (V5). 任意の $\alpha \in F, u,v \in V$ に対して, $\alpha(u + v) = \alpha u + \alpha v$.
* (V6). 任意の $\alpha, \beta \in F, v \in V$ に対して, $(\alpha + \beta) v = \alpha v + \beta v$.
* (V7). 任意の $\alpha, \beta \in F, v \in V$ に対して, $\alpha (\beta v) = (\alpha \beta) v$.
* (V8). 任意の $v \in V$ に対して, $1 v = v$.

このとき, $F$ の元を **スカラー**, $V$ の元を **ベクトル** という.

### 数ベクトル空間

非負整数 $n$ に対して,

$$ F^n := \{ (v_1, \dots, v_n) \mid v_1, \dots, v_n \in F \} $$

に対して, 成分ごとの加法

$$ (u_1, \dots, u_n) + (v_1, \dots, v_n) := (u_1 + v_1, \dots, u_n + v_n) $$

と, 成分ごとのスカラー倍

$$ a (v_1, \dots, v_n) := (a v_1, \dots, a v_n) $$

を定める. これを **数ベクトル空間** といい, `Field_Vector<F>` はこれを表すクラスである.

$F^n$ の零ベクトルは $\boldsymbol{0} = (0, \dots, 0)$ であり, $F^n$ の次元は $n$ である.

### 内積

$\boldsymbol{u} = (u_1, \dots, u_n), \boldsymbol{v} = (v_1, \dots, v_n) \in F^n$ に対して,

$$ \langle \boldsymbol{u}, \boldsymbol{v} \rangle := \sum_{i=1}^n u_i v_i $$

を $\boldsymbol{u}$ と $\boldsymbol{v}$ の **内積** という.

### 直和

$\boldsymbol{u} \in F^m, \boldsymbol{v} \in F^n$ に対して, これらを連結したベクトル

$$ \boldsymbol{u} \oplus \boldsymbol{v} := (u_1, \dots, u_m, v_1, \dots, v_n) \in F^{m+n} $$

を $\boldsymbol{u}$ と $\boldsymbol{v}$ の **直和** という.

## Contents

### Constructor

```cpp
Field_Vector()
```

* 空のベクトルを生成する.

```cpp
Field_Vector(const vector<F> &_vec)
```

* `std::vector<F>` から変換する.

```cpp
Field_Vector(const int n)
```

* 次元 $n$ の零ベクトル $\boldsymbol{0} \in F^n$ を生成する.

```cpp
Field_Vector(initializer_list<F> init)
```

* 初期化リストからベクトルを生成する.

### dimension / size

```cpp
int dimension() const
int size() const
```

* ベクトルの次元 (要素数) を返す. `size` は `dimension` のエイリアス.
* **計算量**: $O(1)$ 時間.

### operator[]

```cpp
const F &operator[](int i) const
F &operator[](int i)
```

* 第 $i$ 成分へアクセスする.
* **計算量**: $O(1)$ 時間.

### 比較演算子

```cpp
bool operator==(const Field_Vector &w) const
bool operator!=(const Field_Vector &w) const
```

* 全成分が等しいかどうかを判定する.
* **計算量**: $O(n)$ 時間. ($n$ は次元)

### 算術演算子

```cpp
Field_Vector operator-() const
```

* $v$ に対して, $-v$ (実は各要素を $-1$ 倍したベクトル) を求める.

```cpp
Field_Vector &operator+=(const Field_Vector &w)
Field_Vector operator+(const Field_Vector &w) const
```

* ベクトルの和を求める.
* 次元が異なる場合は `assert` で失敗する.

```cpp
Field_Vector &operator-=(const Field_Vector &w)
Field_Vector operator-(const Field_Vector &w) const
```

* ベクトルの差を求める.
* 次元が異なる場合は `assert` で失敗する.

* **計算量**: いずれも $O(n)$ 時間.

### スカラー演算

```cpp
Field_Vector &operator*=(const F &a)
Field_Vector operator*(const F &a) const
Field_Vector<F> operator*(const F &a, const Field_Vector<F> &v)
```

* ベクトルのスカラー倍 $a \boldsymbol{v}$ を求める.

```cpp
Field_Vector &operator/=(const F &a)
Field_Vector operator/(const F &a) const
```

* ベクトルのスカラー除算 $\boldsymbol{v} / a$ を求める. $a$ の逆元 `a.inverse()` を利用するため, $a \neq 0$ である必要がある.

* **計算量**: いずれも $O(n)$ 時間.

### is_zero

```cpp
bool is_zero() const
```

* 零ベクトルかどうかを判定する.
* **計算量**: $O(n)$ 時間.

### 入出力

```cpp
istream &operator>>(istream &is, Field_Vector &v)
ostream &operator<<(ostream &os, const Field_Vector &v)
```

* 成分を空白区切りで入出力する.
* **計算量**: $O(n)$ 時間.

### inner

```cpp
F inner(const Field_Vector<F> &w) const
F inner(const Field_Vector<F> &u, const Field_Vector<F> &v)
```

* 内積 $\langle \boldsymbol{v}, \boldsymbol{w} \rangle := \sum_i v_i w_i$ を求める.
* 次元が異なる場合は `assert` で失敗する.
* **計算量**: $O(n)$ 時間.

### Unit

```cpp
static Field_Vector Unit(int n, int i)
```

* 次元 $n$ の単位ベクトル $\boldsymbol{e}_i$ (第 $i$ 成分が $1$ で, 他が $0$) を生成する.
* **計算量**: $O(n)$ 時間.

### Direct_Sum

```cpp
Field_Vector<F> Direct_Sum(const Field_Vector<F> &u, const Field_Vector<F> &v)
Field_Vector<F> Direct_Sum(const vector<Field_Vector<F>> &vs)
```

* 複数のベクトルの直和 (成分を連結したベクトル) を求める.
* **計算量**: 出力の次元を $N$ として, $O(N)$ 時間.

### Action

```cpp
Field_Vector<F> Action(const Field_Matrix<F> &A, const Field_Vector<F> &v)
```

* 行列 $A$ によるベクトル $\boldsymbol{v}$ の線形変換 $A \boldsymbol{v}$ を求める.
* **入力**
  * $A$: $m \times n$ 行列
  * $v$: $F^n$ のベクトル
* **出力**: $A \boldsymbol{v} \in F^m$
* **計算量**: $O(mn)$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/04/02| Field_Vector クラスの実装 |
