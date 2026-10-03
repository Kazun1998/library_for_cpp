---
title: 尺取り法
documentation_of: //Queries/Two_Pointers.hpp
---

## Outline

列 $A$ に対する尺取り法を行うメソッドを提供する.

## Theory

$X$ を集合とする.

$X$ 上の列全体の集合の部分集合を $\mathcal{B}$ とする.

$X$ 上の列 $A$ が以下を満たすとする.

* $A$ の任意の連続部分列 $B$ について, $B \in \mathcal{B}$ ならば, 任意の $B$ の連続部分列 $C$ について, $C \in \mathcal{B}$ である.

$A$ の長さを $N$ として, $1 \leq l \leq r \leq N$ に対する $A$ の第 $l$ 項から第 $r$ までの連続部分列を $[l, r]$ と書くことにする.

このとき, $l = 1, 2, \dots, N$ に対して, 以下で定める $r_l$ を求めたい.

* $[l, l] \in \mathcal{B}$ ならば, $r_l = \max \{ k \mid l \leq k \leq N, [l, k] \in \mathcal{B} \}$.
* $[l, l] \notin \mathcal{B}$ ならば, $r_l = l - 1$.

### 尺取り法によるアルゴリズム

$\mathcal{B}$ がこの条件を満たすとき, $r_1, \dots, r_N$ について, 広義単調増加である. これは, $l < k \leq r_l$ を満たす任意の整数 $k$ に対して, 閉区間 $[l + 1, k]$ が $[l, r_l]$ の連続部分列であり, $[l, r_l] \in \mathcal{B}$ と $A$ に関する仮定により $[l + 1, k] \in \mathcal{B}$ となる.

すなわち $r_{l+1} \geq r_l$ となることに由来する.

そのため, $r_{l-1}$ が求められると, $r_l$ の計算は $r = r_{l-1}$ から計算できる.

これを利用することで, 以下のアルゴリズムで $r_1, \dots, r_N$ を高速に求められる.

1. $l = 1$, $r = 0$ から始め, 閉区間 $[l, r]$ を空として管理する.
2. $l = 1, 2, \dots, N$ の順に以下を行う.
   1. $r < N$ かつ, $[l, r + 1] \in \mathcal{B}$ の条件を満たす限り, 閉区間の末尾に $A_{r+1}$ を追加して $r$ を $1$ 増やす.
   2. このとき $r_l = r$ である.
   3. 次の $l$ に移る前に, 閉区間 $[l, r]$ の先頭から要素 $A_l$ を取り除く.

計算量について, $r$ は $l$ が増加する間, 減らずに $1, 2, \dots, N$ をたどるため, 全体を通して要素の追加・削除はそれぞれ高々 $N$ 回しか行われない.

従って, 追加・削除・条件判定の計算量が $O(T)$ 時間とすると, 全体で $O(NT)$ 時間で $r_1, \dots, r_N$ を求められる.

なお, $X, \mathcal{B}$ が特別な場合については, 尺取り法の一部処理を簡略化することができる.

* 区間 $[l, r]$ が条件を満たすかどうかを, 独立な判定問題として $O(T)$ で判定できる場合は, 追加・削除の手続きを省略して同様に尺取り法を適用できる.
* $X$ が群である場合は, 追加として右からの作用, 削除として左からの逆作用, 総積に関する条件で尺取り法を行える.

## Contents

Theory 欄では, 1-indexed だったが, 実装としては 0-indexed にしている.

### Two_Pointers

```cpp
template <class AddFunc, class RemoveFunc, class CondFunc>
vector<int> Two_Pointers(const int n, const AddFunc &add, const RemoveFunc &remove, const CondFunc &cond)
```

* 尺取り法の一般化版. 閉区間 $[l, r]$ を管理する `add` / `remove` / `cond` を渡すことで, 区間和に限らない条件について $r_0, \dots, r_{n-1}$ を求める (0-indexed).
* **引数**
  * $n$: 数列の長さ.
  * `add`: `void(int r)` 型. 要素 $r$ を区間に追加する.
  * `remove`: `void(int i)` 型. 要素 $i$ を区間から除く.
  * `cond`: `bool()` 型. 現在保持している閉区間が条件 $\mathcal{B}$ を満たすかを返す (`add(r)` した直後に `false` であれば, その場で `remove(r)` して取り消される).
* **戻り値**
  * `result[l]` := $l$ を固定したとき, 閉区間 $[l, r]$ が条件を満たすような最大の $r$ を格納する (満たす $r$ が存在しなければ $l - 1$).
* **計算量**
  * `add` / `remove` / `cond` 1 回あたりの計算量を $O(T)$ として, $O(nT)$ 時間.

### Two_Pointers_Group

```cpp
template <class G, class OpFunc, class InvFunc, class CondFunc>
vector<int> Two_Pointers_Group(const vector<G> &data, const G &e, const OpFunc &op, const InvFunc &inv, const CondFunc &cond)
```

* `Two_Pointers` の群版. `data` の要素が群 $G$ (単位元 $e$, 演算 $\textrm{op}$, 逆元 $\textrm{inv}$) をなす場合に, 区間の総積を自動で管理しながら $r_0, \dots, r_{n-1}$ を求める.
* **引数**
  * `data`: 数列.
  * $G$ に関する情報
    * `e`: 単位元.
    * `op`: $G \times G \to G$. 群 $G$ の演算.
    * `inv`: $G \to G$. 群 $G$ の逆元関数.
  * `cond`: $G \to \{\mathbb{T}, \mathbb{F}\}$. 区間の総積 $\textrm{op}(A_l, \textrm{op}(A_{l+1}, \dots, A_r))$ が条件を満たすかを返す.
* **戻り値**
  * `Two_Pointers` と同様.
* **計算量**
  * `op` / `inv` / `cond` 1 回あたりの計算量を $O(T)$ として, $O(nT)$ 時間.

### Two_Pointers_Direct

```cpp
template <class CondFunc>
vector<int> Two_Pointers_Direct(const int n, const CondFunc &cond)
```

* `Two_Pointers` の直接判定版. 閉区間 $[l, r]$ が条件を満たすかどうかを `cond(l, r)` で直接判定できる場合に用いる (状態の追加・削除の管理が不要).
* **引数**
  * $n$: 数列の長さ.
  * `cond`: `bool(int, int)` 型. `cond(l, r)` は閉区間 $[l, r]$ が条件を満たすかを返す. $l$ を固定したとき $r$ に関して単調 ($r$ が条件を満たすなら $l \leq r' \leq r$ を満たす $r'$ も条件を満たす) である必要がある.
* **戻り値**
  * `Two_Pointers` と同様.
* **計算量**
  * `cond` 1 回あたりの計算量を $O(T)$ として, $O(nT)$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/08/22| document を作成 |
|2026/08/21| 尺取り法に関するメソッドの作成 |