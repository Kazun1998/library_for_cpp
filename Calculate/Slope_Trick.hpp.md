---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data_Structure/Additive_Treap.hpp
    title: "key \u3092 1 \u3064\u524A\u9664\u3059\u308B."
  - icon: ':heavy_check_mark:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':heavy_check_mark:'
    path: template/exception.hpp
    title: template/exception.hpp
  - icon: ':heavy_check_mark:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/math.hpp
    title: template/math.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/utility.hpp
    title: template/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/2654.test.cpp
    title: verify/yukicoder/2654.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u533A\u5206\u7DDA\u5F62\u51F8\u95A2\u6570 f(x) \u3092\u7BA1\u7406\
      \u3059\u308B\u30C7\u30FC\u30BF\u69CB\u9020 (Slope Trick)."
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Calculate/Slope_Trick.hpp: line 2: #pragma once found in a non-first line\n"
  code: "\n#pragma once\n\n#include \"../Data_Structure/Additive_Treap.hpp\"\n\n///\
    \ @brief \u533A\u5206\u7DDA\u5F62\u51F8\u95A2\u6570 f(x) \u3092\u7BA1\u7406\u3059\
    \u308B\u30C7\u30FC\u30BF\u69CB\u9020 (Slope Trick).\n/// @tparam T \u5EA7\u6A19\
    \u30FB\u5024\u306E\u578B (\u52A0\u7B97\u30FB\u6BD4\u8F03\u30FBmax \u304C\u5B9A\
    \u7FA9\u3055\u308C\u305F\u6570\u5024\u578B\u3092\u60F3\u5B9A)\ntemplate<typename\
    \ T>\nclass Slope_Trick {\n    Additive_Treap<T> negative, positive;\n    T f_min;\n\
    \n    public:\n    Slope_Trick(): negative(), positive(), f_min(0) {}\n\n    ///\
    \ @brief \u5B9A\u6570 a \u3092\u52A0\u7B97\u3059\u308B.\n    /// @param a\n  \
    \  void add_const(const T &a) { return f_min += a; }\n\n    /// @brief \u3053\u306E\
    \u95A2\u6570\u306E\u6700\u5C0F\u5024\u3092\u5F97\u308B.\n    /// @return\n   \
    \ T get_min() const { return f_min; }\n\n    /// @brief f(x) \u3092 f(x) + max(0,\
    \ x - a) \u306B\u66F4\u65B0\u3059\u308B.\n    /// @param a\n    void add_x_minus_a(const\
    \ T &a) {\n        unless (negative.empty()) {\n            f_min += max(T(0),\
    \ negative.max() - a);\n        }\n\n        negative.insert(a);\n        positive.insert(negative.pop_max());\n\
    \    }\n\n    /// @brief f(x) \u3092 f(x) + max(0, a - x) \u306B\u66F4\u65B0\u3059\
    \u308B.\n    /// @param a\n    void add_a_minus_x(const T &a) {\n        unless\
    \ (positive.empty()) {\n            f_min += max(T(0), a - positive.min());\n\
    \        }\n\n        positive.insert(a);\n        negative.insert(positive.pop_min());\n\
    \    }\n\n    /// @brief f(x) \u3092 f(x) + |x - a| \u306B\u66F4\u65B0\u3059\u308B\
    .\n    /// @param a\n    void add_abs(const T &a) {\n        add_x_minus_a(a);\n\
    \        add_a_minus_x(a);\n    }\n\n    /// @brief add_x_minus_a(a) \u306E\u9006\
    \u64CD\u4F5C. \u5BFE\u5FDC\u3059\u308B add_x_minus_a(a) \u6E08\u307F\u306E\u72B6\
    \u614B\u3067\u306E\u307F\u6B63\u3057\u304F\u52D5\u4F5C\u3059\u308B.\n    /// @param\
    \ a\n    void sub_x_minus_a(const T &a) {\n        if (positive.contains(a)) {\n\
    \            positive.erase(a);\n        } else {\n            negative.insert(positive.pop_min());\n\
    \            negative.erase(a);\n        }\n\n        unless (negative.empty())\
    \ {\n            f_min -= max(T(0), negative.max() - a);\n        }\n    }\n\n\
    \    /// @brief add_a_minus_x(a) \u306E\u9006\u64CD\u4F5C. \u5BFE\u5FDC\u3059\u308B\
    \ add_a_minus_x(a) \u6E08\u307F\u306E\u72B6\u614B\u3067\u306E\u307F\u6B63\u3057\
    \u304F\u52D5\u4F5C\u3059\u308B.\n    /// @param a\n    void sub_a_minus_x(const\
    \ T &a) {\n        if (negative.contains(a)) {\n            negative.erase(a);\n\
    \        } else {\n            positive.insert(negative.pop_max());\n        \
    \    positive.erase(a);\n        }\n\n        unless (positive.empty()) {\n  \
    \          f_min -= max(T(0), a - positive.min());\n        }\n    }\n\n    ///\
    \ @brief add_abs(a) \u306E\u9006\u64CD\u4F5C. \u5BFE\u5FDC\u3059\u308B add_abs(a)\
    \ \u6E08\u307F\u306E\u72B6\u614B\u3067\u306E\u307F\u6B63\u3057\u304F\u52D5\u4F5C\
    \u3059\u308B.\n    /// @param a\n    void sub_abs(const T &a) {\n        sub_x_minus_a(a);\n\
    \        sub_a_minus_x(a);\n    }\n\n    /// @brief f(x) \u306E\u5024\u3092\u8A08\
    \u7B97\u3059\u308B.\n    /// @param x\n    /// @return f(x)\n    T calculate_at(const\
    \ T &x) const {\n        T res = f_min;\n\n        unless (negative.empty()) {\n\
    \            T sum_l = negative.more_sum(x, false);\n            int count_l =\
    \ negative.count_more(x, false);\n            res += sum_l - count_l * x;\n  \
    \      }\n\n        unless (positive.empty()) {\n            T sum_r = positive.less_sum(x,\
    \ false);\n            int count_r = positive.count_less(x, false);\n        \
    \    res += count_r * x - sum_r;\n        }\n\n        return res;\n    }\n\n\
    \    /// @brief calculate_at(x) \u3068\u540C\u3058.\n    /// @param x\n    ///\
    \ @return f(x)\n    T operator()(const T &x) const { return calculate_at(x); }\n\
    \n    /// @brief \u533A\u9593 [l, r] \u306B\u304A\u3051\u308B f(x) \u306E\u6700\
    \u5C0F\u5024 min_{l <= x <= r} f(x) \u3092\u6C42\u3081\u308B.\n    /// @param\
    \ l\n    /// @param r\n    /// @return min_{l <= x <= r} f(x)\n    T calculate_min(const\
    \ T &l, const T &r) const {\n        if (!negative.empty() && r < negative.max())\
    \ {\n            return calculate_at(r);\n        }\n\n        if (!positive.empty()\
    \ && l > positive.min()) {\n            return calculate_at(l);\n        }\n\n\
    \        return f_min;\n    }\n\n    /// @brief l <= x <= r \u306B\u304A\u3044\
    \u3066 f(x) \u304C\u6700\u5C0F\u5024\u3092\u3068\u308B\u533A\u9593 [a, b] \u3092\
    \u6C42\u3081\u308B.\n    /// @param l\n    /// @param r\n    /// @return f(x)\
    \ \u304C\u6700\u5C0F\u5024\u3092\u3068\u308B\u533A\u9593 [a, b]\n    std::pair<T,\
    \ T> argmin(const T &l, const T &r) const {\n        assert(l <= r);\n       \
    \ T L_opt = negative.empty() ? l : negative.max();\n        T R_opt = positive.empty()\
    \ ? r : positive.min();\n\n        if (r < L_opt) {\n            return {r, r};\n\
    \        }\n        if (l > R_opt) {\n            return {l, l};\n        }\n\
    \        return {std::max(l, L_opt), std::min(r, R_opt)};\n    }\n};\n"
  dependsOn:
  - Data_Structure/Additive_Treap.hpp
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Calculate/Slope_Trick.hpp
  requiredBy: []
  timestamp: '2026-09-13 14:27:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/2654.test.cpp
documentation_of: Calculate/Slope_Trick.hpp
layout: document
title: Slope Trick
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
