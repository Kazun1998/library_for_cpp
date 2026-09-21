---
title: ベクトル空間
documentation_of: //Linear_Algebra/Field_Vector_Space.hpp
---

## Outline

体 $F$ 上のベクトル空間に関するクラスを提供する.

## Theory

### 部分空間

$F$ を体とし, $V$ を $F$ 上のベクトル空間 ([Field_Vector](Field_Vector.hpp)) とする.

$W \subseteq V$ が, $V$ の加法・スカラー倍をそのまま制限することで, それ自体が $F$ 上のベクトル空間になるとき, $W$ を $V$ の **部分空間** という.

$W \subseteq V$ が部分空間であることは, 以下の条件を満たすことと同値である.

* $\boldsymbol{0} \in W$.
* 任意の $\boldsymbol{u}, \boldsymbol{v} \in W$ に対して, $\boldsymbol{u} + \boldsymbol{v} \in W$.
* 任意の $\alpha \in F, \boldsymbol{v} \in W$ に対して, $\alpha \boldsymbol{v} \in W$.

`Field_Vector_Space<F>` は, $F^n$ の部分空間を, その基底によって表現するクラスである.

### 基底と次元

部分空間 $W$ のベクトルの組 $\boldsymbol{e}_1, \dots, \boldsymbol{e}_d \in W$ が, 以下を満たすとき, これらを $W$ の **基底** という.

* (一次独立性) $\alpha_1 \boldsymbol{e}_1 + \dots + \alpha_d \boldsymbol{e}_d = \boldsymbol{0} \implies \alpha_1 = \dots = \alpha_d = 0$
* (全体を張る) 任意の $\boldsymbol{v} \in W$ に対して, ある $\alpha_1, \dots, \alpha_d \in F$ が存在して, $\boldsymbol{v} = \alpha_1 \boldsymbol{e}_1 + \dots + \alpha_d \boldsymbol{e}_d$

$W$ の基底に含まれるベクトルの本数 $d$ は基底の取り方によらず一定であり, これを $W$ の **次元** といい, $\dim W$ で表す.

零空間 $\{\boldsymbol{0}\}$ の基底は空集合であり, $\dim \{\boldsymbol{0}\} = 0$ である.

### 掃き出し法による基底の構成

`Field_Vector_Space` は, 基底の各ベクトル $\boldsymbol{e}_k$ について, ある成分 (`index[k]`) の値が $1$ であり, かつ他の基底ベクトルの同じ成分が $0$ になるように (簡約な形に) 管理する.

新たなベクトル $\boldsymbol{v}$ を追加するとき, まず既存の基底による **射影** $\operatorname{proj}(\boldsymbol{v})$ を

$$ \operatorname{proj}(\boldsymbol{v}) := \boldsymbol{v} - \sum_{k} v_{\mathrm{index}[k]} \boldsymbol{e}_k $$

を計算する (`projection`).

これは, $\boldsymbol{v}$ から既存の基底で表現できる成分を取り除いた残差である.

* $\operatorname{proj}(\boldsymbol{v}) = \boldsymbol{0}$ であることと, $\boldsymbol{v}$ が既存の部分空間 $W$ に含まれること (`contains`) は同値になる.
* $\operatorname{proj}(\boldsymbol{v}) \neq \boldsymbol{0}$ のとき, その非零成分 $i$ を $1$ に正規化した上で, 既存の基底ベクトルから成分 $i$ を消去し, 新たな基底ベクトルとして追加する (`add_vector`). こうして得られる基底は, 各基底ベクトルが担当する成分において, 他の基底ベクトルの値が $0$ になっているため, 部分空間の包含判定 (`contains`, `operator<=`) や和空間の計算 (`operator+`) を効率的に行える.

### 和空間

$V, W$ を $F^n$ の部分空間とする. これらの **和空間** $V+W$ を

$$ V + W := \{ \boldsymbol{v} + \boldsymbol{w} \mid \boldsymbol{v} \in V, \boldsymbol{w} \in W \} $$

で定める. $V + W$ もまた $F^n$ の部分空間になる.

**$V + W$ は基底の和集合が張る空間に一致する.**

$\boldsymbol{e}_1, \dots, \boldsymbol{e}_p$ を $V$ の基底, $\boldsymbol{f}_1, \dots, \boldsymbol{f}_q$ を $W$ の基底とする. このとき,

$$ V + W = \operatorname{Span}(\boldsymbol{e}_1, \dots, \boldsymbol{e}_p, \boldsymbol{f}_1, \dots, \boldsymbol{f}_q) $$

が成り立つ.

**証明**

($\subseteq$) $\boldsymbol{x} \in V + W$ とすると, ある $\boldsymbol{v} \in V, \boldsymbol{w} \in W$ が存在して $\boldsymbol{x} = \boldsymbol{v} + \boldsymbol{w}$ と書ける. $\boldsymbol{v}$ は $\boldsymbol{e}_1, \dots, \boldsymbol{e}_p$ の, $\boldsymbol{w}$ は $\boldsymbol{f}_1, \dots, \boldsymbol{f}_q$ の線形結合で表せるため, $\boldsymbol{x}$ もそれらの線形結合で表せる. よって $\boldsymbol{x} \in \operatorname{Span}(\boldsymbol{e}_1, \dots, \boldsymbol{e}_p, \boldsymbol{f}_1, \dots, \boldsymbol{f}_q)$.

($\supseteq$) $\boldsymbol{e}_1, \dots, \boldsymbol{e}_p \in V \subseteq V + W$ であり, $\boldsymbol{f}_1, \dots, \boldsymbol{f}_q \in W \subseteq V + W$ である. $V+W$ は部分空間なので, これらの線形結合もまた $V + W$ に含まれる. $\blacksquare$

これにより, $V + W$ の基底は, $V$ の基底と $W$ の基底を合わせたベクトルの組に対して掃き出し法 (`add_vector` の繰り返し適用) を行うことで得られる. これが `operator+` / `operator+=` の実装方針である.

### 包含関係

$V, W$ を $F^n$ の部分空間とする. $\boldsymbol{e}_1, \dots, \boldsymbol{e}_p$ を $V$ の基底とする.

**$V \subseteq W$ であることと, $\boldsymbol{e}_1, \dots, \boldsymbol{e}_p \in W$ であることは同値である.**

**証明**

($\Rightarrow$) $V \subseteq W$ とする. $\boldsymbol{e}_1, \dots, \boldsymbol{e}_p \in V$ であるから, $\boldsymbol{e}_1, \dots, \boldsymbol{e}_p \in W$ である.

($\Leftarrow$) $\boldsymbol{e}_1, \dots, \boldsymbol{e}_p \in W$ とする. 任意の $\boldsymbol{v} \in V$ は, ある $\alpha_1, \dots, \alpha_p \in F$ を用いて $\boldsymbol{v} = \alpha_1 \boldsymbol{e}_1 + \dots + \alpha_p \boldsymbol{e}_p$ と書ける. $W$ は部分空間であるため, この線形結合もまた $W$ に含まれる. よって $\boldsymbol{v} \in W$ となり, $V \subseteq W$ である. $\blacksquare$

すなわち, $V \subseteq W$ であるかどうかは, $V$ のすべての元について判定する必要はなく, $V$ の基底の各ベクトルが $W$ に含まれるか (`contains`) を判定すれば十分である. これが `operator<=` の実装方針であり, 部分空間の等価性 $V = W$ の判定 (`operator==`) も, $\dim V = \dim W$ かつ $V \subseteq W$ であることの確認に帰着できる.

## Contents

以下, $n$ を全体空間 $F^n$ の次元, $d$ をこの部分空間の次元とする.

### Constructor

```cpp
Field_Vector_Space(const int _n)
```

* 全体空間の次元 $n$ を指定して, 零空間 $\\{\boldsymbol{0}\\} \subseteq F^n$ を生成する.

```cpp
Field_Vector_Space(const int _n, const vector<Field_Vector<F>> &vectors)
```

* 全体空間の次元 $n$ と, ベクトルの列 `vectors` を指定して, `vectors` が張る部分空間を生成する.
* **計算量**: `vectors` の長さを $m$ として, $O(m d n)$ 時間.

### Zero_Space

```cpp
static Field_Vector_Space Zero_Space(int n)
```

* 零空間 $\\{\boldsymbol{0}\\} \subseteq F^n$ を生成する.
* **計算量**: $O(1)$ 時間.

### Full_Space

```cpp
static Field_Vector_Space Full_Space(int n)
```

* 全体空間 $F^n$ を生成する.
* **計算量**: $O(n^2)$ 時間.

### dimension

```cpp
int dimension() const
```

* この部分空間の次元 $d$ を返す.
* **計算量**: $O(1)$ 時間.

### add_vector

```cpp
bool add_vector(const Field_Vector<F> &v)
```

* ベクトル $\boldsymbol{v}$ をこの部分空間に追加する.
* **出力**: $\boldsymbol{v}$ が追加前の部分空間に含まれていなければ `true` (次元が $1$ 増える), 含まれていれば `false` (部分空間は変化しない).
* **計算量**: $O(dn)$ 時間.

### projection

```cpp
Field_Vector<F> projection(const Field_Vector<F> &v) const
```

* $\boldsymbol{v}$ から, この部分空間の基底で表現できる成分を取り除いた残差 $\operatorname{proj}(\boldsymbol{v})$ を求める.
* **計算量**: $O(dn)$ 時間.

### contains

```cpp
bool contains(const Field_Vector<F> &v) const
```

* ベクトル $\boldsymbol{v}$ がこの部分空間に含まれるかを判定する.
* **計算量**: $O(dn)$ 時間.

### get_basis

```cpp
vector<Field_Vector<F>> get_basis() const
```

* この部分空間の基底を返す.
* **計算量**: $O(dn)$ 時間.

### operator+ / operator+=

```cpp
Field_Vector_Space operator+(const Field_Vector_Space &other) const
Field_Vector_Space& operator+=(const Field_Vector_Space &other)
```

* $2$ つの部分空間の和空間 $V + W := \\{ \boldsymbol{v} + \boldsymbol{w} \mid \boldsymbol{v} \in V, \boldsymbol{w} \in W \\}$ を求める.
* 全体空間の次元 $n$ が異なる場合は `assert` で失敗する.
* **計算量**: `other` の次元を $d'$ として, $O(d' d n)$ 時間.

### operator<=

```cpp
bool operator<=(const Field_Vector_Space &other) const
```

* 包含関係 $V \subseteq W$ を判定する.
* 全体空間の次元 $n$ が異なる場合は `assert` で失敗する.
* **計算量**: $O(d \cdot d' \cdot n)$ 時間. ($d'$ は `other` の次元)

### operator==

```cpp
bool operator==(const Field_Vector_Space &other) const
```

* $2$ つの部分空間が一致するか ($V = W$) を判定する.
* $\dim V = \dim W$ かつ $V \subseteq W$ であることと同値であることを利用している.
* **計算量**: $O(d \cdot d' \cdot n)$ 時間. ($d'$ は `other` の次元)

## History

|日付|内容|
|:---:|:---:|
|2026/05/10| Field_Vector_Space クラスの実装 |
