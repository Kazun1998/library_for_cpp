---
title: 添字が集合である畳み込み (Subset Convolution)
documentation_of: //Convolution/Subset_Convolution.hpp
---

## Outline

$U := \\{0, 1, \dots, N-1\\}$ とし, $I := 2^U$ (部分集合全体) とする. $f, g: 2^U \to R$ に対して, 次で定める $f * g$ を **Subset Convolution** (集合冪級数の積) という.

$$ (f * g)(S) := \sum_{\substack{T \subseteq S}} f(T) g(S \setminus T) = \sum_{\substack{A \cap B = \emptyset \\ A \cup B = S}} f(A) g(B) $$

定義通りに全ての $(A, B)$ の組を調べると $O(4^N)$ 時間かかり, 各 $S$ について $S$ の部分集合 $T$ のみを列挙しても $\Theta(3^N)$ 時間かかる. これに対し, ランク付きゼータ変換を用いることで $O(2^N N^2)$ 時間で計算できる.

[Bitwise_Or_Convolution](Bitwise_Or_Convolution.hpp) とは異なり, 「$A \cup B = S$」に加えて「$A \cap B = \emptyset$」を課している点に注意.

## Theory

集合 $S$ に対して $\lvert S \rvert$ をその要素数 (ランク) とする. $A \cup B = S$ のとき,

$$ A \cap B = \emptyset \iff \lvert A \rvert + \lvert B \rvert = \lvert S \rvert $$

が成り立つ. そこで, $f$ を $S$ と $\lvert S \rvert$ の組で添字付けた多項式

$$ \hat{f}(S, x) := f(S) x^{\lvert S \rvert} $$

を考える. $\hat{f}$ に対して, $S$ 方向にだけゼータ変換 (上位集合ではなく部分集合に関する和) を行う.

$$ (\zeta \hat{f})(S, x) := \sum_{T \subseteq S} f(T) x^{\lvert T \rvert} $$

$\zeta$ は $S$ 方向について OR 畳み込みを各点積にするので, 各 $S$ ごとに $x$ の多項式として積をとると,

$$ (\zeta \hat{f})(S, x) (\zeta \hat{g})(S, x) = \sum_{A \cup B \subseteq S} f(A) g(B) x^{\lvert A \rvert + \lvert B \rvert} $$

となる. これにメビウス変換 $\mu = \zeta^{-1}$ を $S$ 方向にかけると,

$$ \sum_{A \cup B = S} f(A) g(B) x^{\lvert A \rvert + \lvert B \rvert} $$

が得られる. この $x^{\lvert S \rvert}$ の係数をとると, $\lvert A \rvert + \lvert B \rvert = \lvert S \rvert$ すなわち $A \cap B = \emptyset$ となる項のみが残るので, $(f * g)(S)$ に一致する.

## Algorithm

1. 各 $S$ について, 長さ $N+1$ の配列 $\hat{f}(S, \cdot)$ を用意し, $x^{\lvert S \rvert}$ の係数に $f(S)$ を入れる ($g$ も同様).
2. $\hat{f}, \hat{g}$ にそれぞれランク付きゼータ変換をする. ($O(2^N N^2)$)
3. 各 $S$ について, 多項式 $\hat{f}(S, x) \hat{g}(S, x)$ を $x^N$ の項まで計算する. ($O(2^N N^2)$)
4. ランク付きメビウス変換をする. ($O(2^N N^2)$)
5. $S$ について $x^{\lvert S \rvert}$ の係数を取り出して結果とする.

## Contents

`convolution::Subset_Convolution<R>` (別名 `convolution::Sub<R>`) は [Convolution_Base](Convolution_Base.hpp) を継承している. 以下では, $N$ を全体集合の大きさとする.

### Constructer

```cpp
Subset_Convolution<R> A(size_t N)
```

* 長さ $2^N$ の, 全要素が $0$ の列を作る.
* **注意点**
  * 引数は列の長さではなく, 全体集合の大きさ $N$ である.
* **制約**
  * $R$ は可換環.

```cpp
Subset_Convolution<R> A(const vector<R>& data)
```

* `data` で初期化する. (基底クラスのコンストラクタ)
* 長さが $2$ べきでない場合は, 畳み込みの際に長さ $2^N$ になるよう $0$ で埋めて計算し, 先頭 $n$ 要素を結果とする.

### operator+, operator-

```cpp
Subset_Convolution<R> A + B
Subset_Convolution<R> A - B
```

* 各点毎の和・差を求める.
* **制約**
  * $A, B$ の長さが等しい.
* **計算量**
  * $O(2^N)$ 時間.

### operator* (スカラー倍)

```cpp
Subset_Convolution<R> a * A
Subset_Convolution<R> A * a
```

* 各要素を $a \in R$ 倍する.
* **計算量**
  * $O(2^N)$ 時間.

### operator* (畳み込み)

```cpp
Subset_Convolution<R> A * B
Subset_Convolution<R>& A *= B
```

* Subset Convolution $A * B$ を求める.
* **制約**
  * $A, B$ の長さが等しいことを要求する. 異なる場合は `std::length_error` を投げる.
* **注意点**
  * 空列同士の積は空列になる.
* **計算量**
  * $O(2^N N^2)$ 時間.
