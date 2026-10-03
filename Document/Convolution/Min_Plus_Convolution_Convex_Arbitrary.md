---
title: 凸列と任意の列の min-plus 畳み込み
documentation_of: //Convolution/Min_Plus_Convolution_Convex_Arbitrary.hpp
---

## Outline

$G$ を可換全順序群とする. $G$ 上の下に凸な列 $f$ と, $G$ 上の任意の列 $g$ に対して, $(\min, +)$ 畳み込み

$$ h(k) := \min_{i + j = k} \left( f(i) + g(j) \right) $$

を $O((n + m) \log (n + m))$ 時間で計算する. ($f, g$ の長さをそれぞれ $n, m$ とする.)

$g$ も下に凸である場合は, [Min_Plus_Convolution_Convex](Min_Plus_Convolution_Convex.hpp) で $O(n + m)$ 時間で計算できる.

## Theory

$0 \leq k < n + m - 1$ に対して, $k = i + j$ をみたす $(i, j)$ は, $0 \leq i < n$, $0 \leq j < m$ より

$$ \max(0, k - n + 1) \leq j \leq \min(m - 1, k) $$

をみたす $j$ によって $i = k - j$ と定まる. よって

$$ h(k) = \min_{j} \left( f(k - j) + g(j) \right) $$

と書ける. ここで, $h(k)$ を達成する $j$ のうち最小のものを $j^*(k)$ とする.

### 最適な $j$ の単調性

$f$ が下に凸であるとき, $k < k'$ かつ $j < j'$ なる添字 ($f$ の添字が全て範囲内になるもの) について, $k - j'$ が最小, $k' - j$ が最大であり, $k - j$ と $k' - j'$ はその間にあって, 和が等しい:

$$ (k - j) + (k' - j') = (k - j') + (k' - j). $$

$f$ が下に凸であることから,

$$ f(k - j) + f(k' - j') \leq f(k - j') + f(k' - j) $$

が成り立つ. 両辺に $g(j) + g(j')$ を加えると, $A(k, j) := f(k - j) + g(j)$ について

$$ A(k, j) + A(k', j') \leq A(k, j') + A(k', j) $$

を得る. つまり, $A$ は Monge 配列であり, この性質から $j^*(k)$ は $k$ について広義単調増加になることが従う.

($f$ の添字が範囲外になる $(k, j)$ は $+\infty$ とみなす. これらは帯状の領域になるので, 上の性質は保たれる.)

### Monotone Minima

以上より, $A(k, j)$ ($f$ の添字が範囲外になる $(k, j)$ では $+\infty$ とする) は Monotone Minima を満たす. よって, 各 $k$ に対する $j^*(k)$ は [Monotone Minima](../Queries/Monotone_Minima.hpp) によって求めることができる.

$j^*(k)$ が求まれば, $h(k) = f(k - j^*(k)) + g(j^*(k))$ である. 全体の計算量は, 行数が $n + m - 1$ であることから, $O((n + m) \log (n + m))$ 時間である.

## Contents

### convolve

```cpp
static vector<G> convolve(const vector<G> &f, const vector<G> &g)
```

* 下に凸な $f$ と任意の $g$ に対して, $(\min, +)$ 畳み込み $h(k) = \min_{i + j = k} (f(i) + g(j))$ を求める.
* $f, g$ のいずれかが空列ならば, 空列を返す.
* **制約**
  * $f$ は下に凸である (チェックはしない). 判定は [Min_Plus_Convolution_Convex](Min_Plus_Convolution_Convex.hpp) の `is_convex` でできる.
* **引数**
  * $f$: 下に凸な $G$ 上の列
  * $g$: $G$ 上の任意の列
* **返り値**: 長さ $\lvert f \rvert + \lvert g \rvert - 1$ の列 $h$.
* **計算量**: $O((\lvert f \rvert + \lvert g \rvert) \log (\lvert f \rvert + \lvert g \rvert))$ 時間.

## History

|日付|内容|
|:---:|:---|
|2026/10/03| Min_Plus_Convolution_Convex_Arbitrary クラスの実装 |
