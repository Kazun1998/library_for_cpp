---
title: 実数上の二分探索による境目の計算
documentation_of: //Binary_Search/General_Real.hpp
---

## Outline

実数（浮動小数点数）の探索範囲 $[l, r]$ において, 単調性のある判定条件 `cond` を満たす境目の値を二分探索によって求めます.

## Contents

### General_Binary_Increase_Search_Real

```cpp
template<typename T>
T General_Binary_Increase_Search_Real(const T l, const T r, const auto cond, int trial, T default_value)
```

* $[l, r]$ 上で広義単調増加な条件 $\mathrm{cond}$（$\mathrm{cond}(x)$ が真ならば, 任意の $y \ge x$ についても $\mathrm{cond}(y)$ が真）に対し, $\mathrm{cond}(x)$ が真となる最小の実数 $x$ を二分探索で求める.
* **引数**
  * `l`: 探索範囲の下限.
  * `r`: 探索範囲の上限.
  * `cond`: $[l, r]$ 上の単調増加な関数.
  * `trial`: 二分探索の反復回数.
  * `default_value`: $\mathrm{cond}(r)$ が偽のときの返り値.
* **返り値**
  * $\mathrm{cond}(r)$ が偽の場合は `default_value` である.
  * $\mathrm{cond}(l)$ が真の場合は $l$ である.
  * そうでないときは実数 $\inf \{ x \in [l, r] \mid \mathrm{cond}(x) \}$ (反復回数 `trial` に基づく近似値) である.
* **計算量**
  * $O(\text{trial} \times f)$ 時間（ただし $f$ は `cond` の計算量）.

### General_Binary_Decrease_Search_Real

```cpp
template<typename T>
T General_Binary_Decrease_Search_Real(const T l, const T r, const auto& cond, int trial, T default_value)
```

* $[l, r]$ 上で広義単調減少な条件 $\mathrm{cond}$（$\mathrm{cond}(x)$ が真ならば, 任意の $y \le x$ についても $\mathrm{cond}(y)$ が真）に対し, $\mathrm{cond}(x)$ が真となる最大の実数 $x$ を二分探索で求める.
* **引数**
  * `l`: 探索範囲の下限.
  * `r`: 探索範囲の上限.
  * `cond`: $[l, r]$ 上の単調減少な関数.
  * `trial`: 二分探索の反復回数.
  * `default_value`: $\mathrm{cond}(l)$ が偽のときの返り値.
* **返り値**
  * $\mathrm{cond}(l)$ が偽の場合は `default_value` である.
  * $\mathrm{cond}(r)$ が真の場合は $r$ である.
  * そうでないときは実数 $\sup \{ y \in [l, r] \mid \mathrm{cond}(y) \}$ (反復回数 `trial` に基づく近似値) である.
* **計算量**
  * $O(\text{trial} \times f)$ 時間（ただし $f$ は `cond` の計算量）.

## History 

|日付|内容|
|:---:|:---:|
|2026/05/24| 実数上の二分探索 実装 |
