---
title: 凹列同士の max-plus 畳み込み
documentation_of: //Convolution/Max_Plus_Convolution_Concave.hpp
---

## Outline

$G$ を可換全順序群とする. $G$ 上の上に凸な列 $f, g$ に対して, $(\max, +)$ 畳み込み

$$ h(k) := \max_{i + j = k} \left( f(i) + g(j) \right) $$

を線形時間で計算する. [Min_Plus_Convolution_Convex](Min_Plus_Convolution_Convex.hpp) の上に凸版である.

## Theory

$f$ が上に凸であることと, $-f$ が下に凸であることは同値である. また,

$$ \max_{i + j = k} \left( f(i) + g(j) \right) = - \min_{i + j = k} \left( (-f)(i) + (-g)(j) \right) $$

であるから, 上に凸な $f, g$ に対する $(\max, +)$ 畳み込みは, 下に凸な $-f, -g$ に対する $(\min, +)$ 畳み込みに帰着される.

計算量はお同じく $O(n+m)$ 時間である.

## Contents

### is_concave

```cpp
static bool is_concave(const vector<G> &f)
```

* $f$ が上に凸であるかどうかを判定する.
* **引数**
  * $f$: $G$ 上の列
* **返り値**: $f$ が上に凸であれば `true`, そうでなければ `false`.
* **計算量**: $O(\lvert f \rvert)$ 時間.

### convolve

```cpp
static vector<G> convolve(const vector<G> &f, const vector<G> &g)
```

* 上に凸な $f, g$ に対して, $(\max, +)$ 畳み込み $h(k) = \max_{i + j = k} (f(i) + g(j))$ を求める.
* $f, g$ のいずれかが空列ならば, 空列を返す.
* **制約**
  * $f, g$ は上に凸である (チェックはしない).
* **引数**
  * $f, g$: 上に凸な $G$ 上の列
* **返り値**: 長さ $\lvert f \rvert + \lvert g \rvert - 1$ の列 $h$.
* **計算量**: $O(\lvert f \rvert + \lvert g \rvert)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/10/03| Max_Plus_Convolution_Concave クラスの実装 |
