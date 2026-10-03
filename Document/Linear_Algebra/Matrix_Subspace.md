---
title: 行列が作る空間
documentation_of: //Linear_Algebra/Matrix_Subspace.hpp
---

## Outline

体 $F$ 上の行列から生成される空間を求める.

## Theory

$F$ を体とし, $A$ を $F$ 上の $m \times n$ 行列とする.

### 行空間 (Row Space)

$A$ の各行ベクトル $\boldsymbol{r}_1, \dots, \boldsymbol{r}_m \in F^n$ が張る $F^n$ の部分空間を **行空間** といい,

$$ \operatorname{Row} A := \operatorname{span}(\boldsymbol{r}_1, \dots, \boldsymbol{r}_m) \subseteq F^n $$

で定める.

### 列空間 (Column Space / Image)

$A$ の各列ベクトル $\boldsymbol{c}_1, \dots, \boldsymbol{c}_n \in F^m$ が張る $F^m$ の部分空間を **列空間** (または **像**) といい,

$$ \operatorname{Im} A := \operatorname{span}(\boldsymbol{c}_1, \dots, \boldsymbol{c}_n) = \{ A \boldsymbol{x} \mid \boldsymbol{x} \in F^n \} \subseteq F^m $$

で定める.

### 核 (Kernel / Null Space)

$$ \operatorname{Ker} A := \{ \boldsymbol{x} \in F^n \mid A \boldsymbol{x} = \boldsymbol{0} \} \subseteq F^n $$

を $A$ の **核** (または **零空間**) という. $\operatorname{Ker} A$ は $F^n$ の部分空間になる.

### 解空間

$\boldsymbol{b} \in F^m$ に対して, 線形方程式 $A \boldsymbol{x} = \boldsymbol{b}$ の解全体の集合を **解空間** という.

解 $\boldsymbol{x}_0$ (特殊解) が存在するとき, 解空間は

$$ \{ \boldsymbol{x} \in F^n \mid A \boldsymbol{x} = \boldsymbol{b} \} = \boldsymbol{x}_0 + \operatorname{Ker} A $$

というアフィン空間 (剰余類) になる. 特に, $\boldsymbol{b} = \boldsymbol{0}$ のときは $\operatorname{Ker} A$ 自身と一致する.

### 性質

以下, $\operatorname{rank} A$ で $A$ の階数 (行空間, 列空間の次元) を表す.

#### 行空間と列空間の次元の一致

$$ \dim \operatorname{Row} A = \dim \operatorname{Im} A = \operatorname{rank} A $$

行基本変形は行空間を変えないため, $A$ を行簡約階段形にしたときの非零行の個数が $\dim \operatorname{Row} A$ に一致する. また, 行基本変形は列ベクトル間の線形関係を保つため, 非零行の個数 (ピボットの個数) は列空間の次元 $\dim \operatorname{Im} A$ とも一致する.

#### 次元定理 (Rank-Nullity Theorem)

$$ \dim \operatorname{Ker} A + \operatorname{rank} A = n $$

自由変数 (ピボットでない列) の個数が $\dim \operatorname{Ker} A$ に, ピボットの個数が $\operatorname{rank} A$ に対応し, 両者の和は列の総数 $n$ に一致する.

#### 転置との関係

$$ \operatorname{Row} A = \operatorname{Im} A^\top, \quad \operatorname{Im} A = \operatorname{Row} A^\top $$

行空間・列空間の定義から直ちに従う. `Column_Space` は内部で $A^\top$ に対して `Row_Space` を適用することで実装できる.

#### 解の存在条件

$$ A \boldsymbol{x} = \boldsymbol{b} \text{ が解を持つ} \iff \boldsymbol{b} \in \operatorname{Im} A $$

列空間の定義 $\operatorname{Im} A = \{ A \boldsymbol{x} \mid \boldsymbol{x} \in F^n \}$ より直ちに従う.

#### 解の一意性

$$ \operatorname{Ker} A = \{ \boldsymbol{0} \} \iff A \boldsymbol{x} = \boldsymbol{b} \text{ の解は存在すれば一意} $$

解 $\boldsymbol{x}_1, \boldsymbol{x}_2$ が存在するとき, $A(\boldsymbol{x}_1 - \boldsymbol{x}_2) = \boldsymbol{0}$ より $\boldsymbol{x}_1 - \boldsymbol{x}_2 \in \operatorname{Ker} A$ となることから従う.

## Contents

### Row_Space

```cpp
template<typename F>
Field_Vector_Space<F> Row_Space(const Field_Matrix<F> &A)
```

* 行列 $A$ の行空間 (Row Space) を求める.
* **入力**
  * $A$: 体 $F$ 上の $m \times n$ 行列
* **出力**: $A$ の行ベクトルたちが張る空間
* **計算量**: $A$ の行基本変形を行うため, $O(mn \min(m, n))$ 時間.

### Column_Space

```cpp
template<typename F>
Field_Vector_Space<F> Column_Space(const Field_Matrix<F> &A)
```

* 行列 $A$ の列空間 (Column Space / Image) を求める.
* **入力**
  * $A$: 体 $F$ 上の $m \times n$ 行列
* **出力**: $A$ の列ベクトルたちが張る空間
* **計算量**: $A^\top$ の行基本変形を行うため, $O(mn \min(m, n))$ 時間.

### Solve_Linear_System

```cpp
template<typename F>
optional<pair<Field_Vector<F>, Field_Vector_Space<F>>> Solve_Linear_System(const Field_Matrix<F> &A, const Field_Vector<F> &b)
```

* 線形方程式 $Ax = b$ を解く.
* **入力**
  * $A$: 体 $F$ 上の $m \times n$ 行列
  * $b$: $F^m$ のベクトル
* **出力**
  * 解が存在する場合: ベクトルと部分空間の組 $(x_0, \operatorname{Ker} A)$ が返ってくる. $x_0$ は $Ax_0 = b$ の特殊解, $\operatorname{Ker} A$ は $A$ の核空間を表す. これにより, 一般解は $x_0 + \operatorname{Ker} A$ で表される.
  * 解が存在しない場合: `nullopt` が返ってくる.
* **計算量**: 拡大係数行列 $[A \mid b]$ ( $m \times (n + 1)$ 行列) の行基本変形を行うため, $O(mn \min(m, n))$ 時間.

### Kernel_Space

```cpp
template<typename F>
Field_Vector_Space<F> Kernel_Space(const Field_Matrix<F> &A)
```

* 行列 $A$ の核 (Kernel / Null Space) を求める.
* **入力**
  * $A$: 体 $F$ 上の $m \times n$ 行列
* **出力**: $Ax = 0$ を満たすベクトル $x$ 全体が張る空間 $\operatorname{Ker} A$
* **計算量**: 内部で `Solve_Linear_System(A, 0)` を呼び出しているため, $O(mn \min(m, n))$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/05/10| Row_Space, Column_Space, Solve_Linear_System, Kernel_Space メソッドの実装 |
