---
title: 凸列同士の min-plus 畳み込み
documentation_of: //Convolution/Min_Plus_Convolution_Convex.hpp
---

## Outline

$G$ を可換全順序群とする. $G$ 上の下に凸な列 $f, g$ に対して, $(\min, +)$ 畳み込み

$$ h(k) := \min_{i + j = k} \left( f(i) + g(j) \right) $$

を線形時間で計算する.

## Definition

長さ $n$ の $G$ 上の列 $f = (f_0, f_1, \dots, f_{n-1})$ について, 以下を定義する.

* $(\Delta f)_i = f_{i+1}-f_i~(0 \leq i < n - 1)$ で定められる長さ $(n-1)$ の列 $\Delta f$ を $f$ の階差列という.
* $\Delta f$ が広義単調増加であるとき, $f$ は **下に凸** (または凸) という.
* $\Delta f$ が広義単調減少であるとき, $f$ は **上に凸** (または凹) という.

## Theory

$f, g$ はともに下に凸であるとする. このとき, 以下で定義される min-plus 畳み込み $h$ も下に凸になる.

$$ h(k) := \min_{i + j = k} \left( f(i) + g(j) \right) $$

ここで, $h$ の階差列 $\Delta h$ は $\Delta f$ と $\Delta g$ を (昇順に) マージした列に一致することが証明できる. また,

$$h(0) = \min_{i + j = 0} \left( f(i) + g(j) \right) = \min(f(0) + g(0)) = f(0) + g(0) $$

である.

よって, $f, g$ の長さをそれぞれ $n, m$ とするとき, 以下の手続きで $h$ を求めることができる.

1. $(i, j) := (0, 0)$ とする.
2. $k = 0, 1, \dots, n + m - 2$ の順に, 以下を行う.
    1. $h(k) := f(i) + g(j)$ と確定する. (このとき $i + j = k$ である.)
    2. $i$ と $j$ のどちらを $1$ 進めるかを決める.
        * $j = m - 1$ ならば, $g$ は使い切っているので, $i$ を $1$ 進める.
        * $i = n - 1$ ならば, $f$ は使い切っているので, $j$ を $1$ 進める.
        * そうでなければ, $\Delta f_i$ と $\Delta g_j$ の小さい方を採用し, $\Delta f_i \leq \Delta g_j$ ならば $i$ を, そうでなければ $j$ を $1$ 進める.

比較 $\Delta f_i \leq \Delta g_j$ は, 階差を作らずに $f_{i+1} + g_j \leq f_i + g_{j+1}$ によって行う.

各ステップで $k = i + j$ は $1$ ずつ増え, $h(k)$ が $1$ 個確定する. $k$ は $0$ から $n + m - 2$ まで動くので, ステップ数は $n + m - 1$ である. 1 ステップは $O(1)$ 時間なので, $h$ を $O(n + m)$ 時間で求めることができる.

## Contents

### is_convex

```cpp
static bool is_convex(const vector<G> &f)
```

* $f$ が下に凸であるかどうかを判定する.
* **引数**
  * $f$: $G$ 上の列
* **返り値**: $f$ が下に凸であれば `true`, そうでなければ `false`.
* **計算量**: $O(\lvert f \rvert)$ 時間.

### convolve

```cpp
static vector<G> convolve(const vector<G> &f, const vector<G> &g)
```

* 下に凸な $f, g$ に対して, $(\min, +)$ 畳み込み $h(k) = \min_{i + j = k} (f(i) + g(j))$ を求める.
* $f, g$ のいずれかが空列ならば, 空列を返す.
* **制約**
  * $f, g$ は下に凸である (チェックはしない).
* **引数**
  * $f, g$: 下に凸な $G$ 上の列
* **返り値**: 長さ $\lvert f \rvert + \lvert g \rvert - 1$ の列 $h$.
* **計算量**: $O(\lvert f \rvert + \lvert g \rvert)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/10/03| Min_Plus_Convolution_Convex クラスの実装 |
