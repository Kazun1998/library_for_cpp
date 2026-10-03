---
title: Slope Trick
documentation_of: //Calculate/Slope_Trick.hpp
---

## Outline

区分線形凸関数 $f : \mathbb{R} \to \mathbb{R}$ を,

* $\max(0, x - a)$ の加算
* $\max(0, a - x)$ の加算
* $\lvert x - a \rvert$ の加算
* (直前に行った上記の加算の逆操作)
* 定数の加算

によって更新しながら,

* $f$ の最小値
* $f$ が最小値をとる区間
* 特定の点, 区間における $f$ の値・最小値

を管理するデータ構造.

内部では $f$ の傾きが $-1$ 減る点の集合 (`negative`) と傾きが $+1$ 増える点の集合 (`positive`) をそれぞれ `Additive_Treap` (多重集合を扱える Treap) で管理する.

## Theory

### 表現

区分線形凸関数 $f$ は, ある区間 $[L_0, R_0]$ (境界は $\pm\infty$ でもよい) で最小値をとり, その左右で傾きが単調に (絶対値が) 増えていく形をしている.

そこで, $f$ を次の組で表現することを考える.

* $m := \min_x f(x)$.
* $x < L_0$ の範囲で傾きが $1$ 減る点全体からなる多重集合

  $$ L = \{L_0, L_1, \dots \}, \quad L_0 \geq L_1 \geq \dots $$

* $x > R_0$ の範囲で傾きが $1$ 増える点全体からなる多重集合

  $$ R = \{R_0, R_1, \dots \}, \quad R_0 \leq R_1 \leq \dots $$

つまり,

$$
  f(x) = m + \sum_{i} \max(0, L_i - x) + \sum_{j} \max(0, x - R_j)
$$

であり, $L_0 = \max L \leq \min R = R_0$ が不変条件として保たれる. $L, R$ をそれぞれ多重集合として扱える平衡二分探索木 (Treap) で管理することで, 最大値・最小値の取得や要素の挿入・削除を $O(\log n)$ 時間で行う.

### $\max(0, x - a)$ の加算

$g(x) := f(x) + \max(0, x - a)$ を考える. これは $L, R, m$ を用いて次のように更新すればよい.

* $a$ を $L$ に加え, その中の最大値 $\ell := \max(L_0, a)$ を取り除く (取り除いた後の $L$ を改めて $L$ とする).
* $\ell$ を $R$ に加える.
* $m$ に $\max(0, L_0 - a)$ を加える (ここでの $L_0$ は更新前の値. $L = \emptyset$ のときは $0$ とみなす).

このとき, $g$ は更新後の $L, R, m$ によって表現される. 直感的には,

* $a \geq R_0$ のとき, $g$ は $x \in [L_0, a]$ で最小値 $m$ をとる. これは $a$ をそのまま $R$ 側 (右側の傾き変化点) に加えることに対応する.
* $a < R_0$ のとき, $g$ の最小値をとる区間は $[L_0, R_0]$ から $[L_0, R_1]$ へ広がり, 最小値は $m + (R_0 - a)$ に増える. これは, 新しい変化点 $a$ を $L$ 側に加えつつ, それまで $R$ の最小要素だった $R_0$ を $L$ 側へ繰り込む操作に対応する.

上の更新規則は, 「$a$ を一旦 $L$ に加えてから, $L$ の最大値を $R$ に移す」という操作として書けており, $L_0$ と $a$ の大小によって上記 2 つの場合が自動的に区別される.

$\max(0, a - x)$ の加算は, これと左右対称な操作 ($L$ と $R$, 最大と最小, 左右の不等号を入れ替えたもの) である.

### $\lvert x - a \rvert$ の加算

$\lvert x - a \rvert = \max(0, x - a) + \max(0, a - x)$ であることから, 上の 2 つの操作を順に行えばよい.

### 減算 (逆操作)

上の加算の逆操作は, 直前に加えた傾き変化点 $a$ を取り除きつつ, $L, R$ の役割 ($L_0 \leq R_0$ という不変条件) を回復し, $m$ の増分を逆算して引くことで実現できる. そのため, 対応する加算がまだ行われていない状態やあり得ない値に対して呼び出すと, $L, R, m$ の対応関係が崩れ, 以後の結果は不正になる (未定義動作).

### 値・区間の計算

$[L_0, R_0]$ の外側では, $L$ (または $R$) に含まれる各点との差の総和として $f$ の値が線形に計算できる.

$f$ は凸関数なので, 区間 $[l, r]$ 上の最小値は,

* $[l, r]$ が $[L_0, R_0]$ と交わるならば $m$,
* $[l, r]$ が $[L_0, R_0]$ より真に左側にあるならば $f(r)$ (単調減少している部分),
* $[l, r]$ が $[L_0, R_0]$ より真に右側にあるならば $f(l)$ (単調増加部分)

で求められる.

最小値をとる区間は $[l, r] \cap [L_0, R_0]$ (交わらない場合は端点のみからなる区間) として求められる.

## Contents

### Constructer

```cpp
Slope_Trick<T> F
```

* $f(x) = 0$ (定数関数) で初期化する.

### add_const

```cpp
void F.add_const(T a)
```

* $f(x) \leftarrow f(x) + a$ に更新する.
* **計算量** : $O(1)$ 時間.

### get_min

```cpp
T F.get_min()
```

* $f$ の最小値 $\min_x f(x)$ を求める.
* **計算量** : $O(1)$ 時間.

### add_x_minus_a

```cpp
void F.add_x_minus_a(T a)
```

* $f(x) \leftarrow f(x) + \max(0, x - a)$ に更新する.
* **計算量** : ならし $O(\log n)$ 時間 ($n$ はこれまでに加算した傾き変化点の個数).

### add_a_minus_x

```cpp
void F.add_a_minus_x(T a)
```

* $f(x) \leftarrow f(x) + \max(0, a - x)$ に更新する.
* **計算量** : ならし $O(\log n)$ 時間.

### add_abs

```cpp
void F.add_abs(T a)
```

* $f(x) \leftarrow f(x) + \lvert x - a \rvert$ に更新する.
* `add_x_minus_a(a)` と `add_a_minus_x(a)` を順に行うことと同じ.
* **計算量** : ならし $O(\log n)$ 時間.

### sub_x_minus_a

```cpp
void F.sub_x_minus_a(T a)
```

* `add_x_minus_a(a)` の逆操作, すなわち $f(x) \leftarrow f(x) - \max(0, x - a)$ に更新する.
* **制約**
  * この呼び出しに対応する `add_x_minus_a(a)` が (このタイミングまでに) 行われていること.
* **計算量** : ならし $O(\log n)$ 時間.

### sub_a_minus_x

```cpp
void F.sub_a_minus_x(T a)
```

* `add_a_minus_x(a)` の逆操作, すなわち $f(x) \leftarrow f(x) - \max(0, a - x)$ に更新する.
* **制約**
  * この呼び出しに対応する `add_a_minus_x(a)` が (このタイミングまでに) 行われていること.
* **計算量** : ならし $O(\log n)$ 時間.

### sub_abs

```cpp
void F.sub_abs(T a)
```

* `add_abs(a)` の逆操作, すなわち $f(x) \leftarrow f(x) - \lvert x - a \rvert$ に更新する.
* `sub_x_minus_a(a)` と `sub_a_minus_x(a)` を順に行うことと同じ.
* **制約**
  * この呼び出しに対応する `add_abs(a)` が (このタイミングまでに) 行われていること.
* **計算量** : ならし $O(\log n)$ 時間.

### calculate_at / operator()

```cpp
T F.calculate_at(T x)
T F(x)
```

* $f(x)$ の値を求める.
* **計算量** : $O(\log n)$ 時間.

### calculate_min

```cpp
T F.calculate_min(T l, T r)
```

* 区間の最小値 $\displaystyle \min_{l \leq x \leq r} f(x)$ を求める.
* **制約**
  * $l \leq r$.
* **計算量** : $O(\log n)$ 時間.

### argmin

```cpp
pair<T, T> F.argmin(T l, T r)
```

* $l \leq x \leq r$ の範囲で $f(x)$ が最小値をとる区間 $[a, b]$ を求める.
* **制約**
  * $l \leq r$.
* **計算量** : $O(\log n)$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/09/13| Slope Trick 実装 |
