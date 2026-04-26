---
title: 疎行列における行列式
documentation_of: //Linear_Algebra/Determinant_of_Sparse_Matrix.hpp
---

## Outline

体 $F$ 上の疎行列 $A$ に対する行列式 $\det A$ を高速に求める.

## Theory

### 線形漸化式の存在
$A$ を次数 $N$ の行列とする. また, $\boldsymbol{u}, \boldsymbol{v} \in F^N$ とする.

このとき, 以下が従う.

> $d_k := \left \langle \boldsymbol{u} \mid A^k \boldsymbol{v} \right \rangle$ としたとき, 列 $(d_k)$ は線形漸化式を持つ.

**証明**

Cayley-Hamilton の定理により, $c_0, c_1, \dots, c_{N-1} \in  F$ が存在して,

$$ A^N = c_{N-1} A^{N-1} + \dots + c_1 A + c_0 I_N $$

が成り立つ.

すると,

$$
\begin{align*}
    d_{N+k} 
    &= \left \langle \boldsymbol{u} \mid A^{N+k} \boldsymbol{v} \right \rangle \\
    &= \left \langle \boldsymbol{u} \mid A^k (c_{N-1} A^{N-1} + \dots + c_1 A + c_0 I_N) \boldsymbol{v} \right \rangle \\
    &= c_{N-1}  \left \langle \boldsymbol{u} \mid A^k \cdot A^{N-1} \boldsymbol{v} \right \rangle + \dots + c_1 \left \langle \boldsymbol{u} \mid A^k \cdot A \boldsymbol{v} \right \rangle + c_0 \left \langle \boldsymbol{u} \mid A^k \cdot I_N \boldsymbol{v} \right \rangle \\
    &= c_{N-1} \left \langle \boldsymbol{u} \mid A^{N+k-1} \boldsymbol{v} \right \rangle + \dots + c_1 \left \langle \boldsymbol{u}\mid A^{k+1} \boldsymbol{v} \right \rangle + c_0 \left \langle \boldsymbol{u} \mid A^k \boldsymbol{v} \right \rangle \\
    &= c_{N-1} d_{N+k-1} + \dots + c_1 d_{N+1} + c_0 d_N
\end{align*}
$$

である. 故に, $(d_k)$ は $N$ 次の線形漸化式

$$ d_{N+k} = c_{N-1} d_{N+k-1} + \dots + c_1 d_{N+1} + c_0 d_N $$

を持つ.

### アルゴリズムの構築

$A$ の固有多項式 $\varphi_A(t) (:= \det(t I_N - A))$ について, $0 \leq k < N$ に対して,

$$ \left[t^k \right] \varphi_A = -c_k $$

が成り立つ. ここで,

$$ \left[t^0 \right] \varphi_A = \varphi_A(0) = \det(-A) = (-1)^N \det A $$

であるため,

$$ \det A = (-1)^{N+1} c_0 $$

が成り立つ.

故に, $(d_k)$ が満たす線形漸化式を求められれば良い.

### 乱択の利用

$\boldsymbol{u}, \boldsymbol{v}$ をランダムに選ぶことにする.

理論上は, $(d_k)$ が満たす $N$ 次の線形漸化式を求められれば良い.

これは [Find_Linear_Recurrence](Find_Linear_Recurrence.hpp) を使うことで, 最小の線形漸化式を求められる. しかし, 全ての場合で対応できるわけではない.

具体的には, $A$ において, 重複した固有値がある場合, 最小の線形漸化式が縮退して, $N$ 次の線形漸化式を得られない.

そのため, $A$ にあるランダムな行列 $B$ をかけて, $B$ の固有値が相異なることを期待する.

$BA$ に関する行列式を上記のアルゴリズムによって得た後,

$$ \det A = \dfrac{\det BA}{\det B} $$

によって, $\det A$ を求められる. ただし $\det B \neq 0$ である必要がある.

このアルゴリズムを使うために, $B$ として, 対角行列 $D$を使うことにする.

$$ D := \operatorname{diag}(\lambda_1, \dots \lambda_N) $$

とすると,

$$ \det D = \lambda_1 \dots \lambda_N $$

になるため,

$$ \det A = \dfrac{\det DA}{\det D} $$

となる. また, $D$ は対角行列なので, $A$ における非零要素の個数と, $DA$ における非零要素の個数は一致する.

### 計算量について

$A$ の非零要素の個数を $K$ とする. 各 $\boldsymbol{x} \in F^N$ に対して, $A \boldsymbol{x}$ は非零要素のみに着目することで, $O(K)$ 時間で求められる.

ここで, $(d_k)$ は, $N$ 次の線形漸化式を持つため, `Find_Linear_Recurrence` で線形漸化式を見つけるためには, $2N$ 個の項が必要である.

よって, 必要な計算とその計算量は

* $\boldsymbol{u}, \boldsymbol{v}, D$ をランダムに決定する: $O(N)$ 時間.
* $\boldsymbol{v}, DA\boldsymbol{v}, (DA)^2 \boldsymbol{v}, \dots, (DA)^{2N-1} \boldsymbol{v}$ を求める.
  * 各 $(DA)^k \boldsymbol{v}$ の計算に $O(K + N)$ 時間かかるため, 全体で $O(NK + N^2)$ 時間.
* 各 $k$ について $d_k = \langle \boldsymbol{u} \mid (DA)^k \boldsymbol{v} \rangle$ を求める: 各 $k$ に対して $O(N)$ 時間で, 合計 $O(N^2)$ 時間.
* $(d_0, d_1, \dots, d_{2N-1})$ から線形漸化式を求める: $O(N^2)$ 時間.

そのため, 全体の計算量は $O(N (N + K))$ 時間になる.

## Contents

```cpp
template<typename F>
F Determinant_of_Sparse_Matrix(const int N, const vector<tuple<int, int, F>> &elements)
```

* $N$ 次の疎行列における行列式を求める.
* **入力**
  * $N$: 行列の次数
  * $\textrm{elements}$: 整数 $i, j$ と $F$ の元 $a \in F$ からなるトリプル $(i, j, a)$ のリスト. $(i, j, a)$ は $(i, j)$ 成分が $a$ であることを示す. そして, 残りは全て $0$.
* **計算量**: 非零要素の個数. つまり, $\textrm{elements}$ の長さを $K$ として, $O(N (N + K))$ 時間.

## History 

|日付|内容|
|:---:|:---:|
|2026/04/26| Determinant_of_Sparse_Matrix の実装 |
