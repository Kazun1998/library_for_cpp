---
data:
  _extendedDependsOn:
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5468\u9577 n \u306E\u5186\u74B0\u4E0A\u3067, l \u304B\u3089\
      \ r \u307E\u3067 (l \u304B\u3089\u6642\u8A08\u56DE\u308A\u306B r \u307E\u3067\
      ) \u306E\u5404\u8981\u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B"
    links:
    - https://github.com/Kazun1998/library_for_cpp/blob/main/Imos/Cyclic_Imos_1.hpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Imos/Cyclic_Imos_1.hpp: line 3: #pragma once found in a non-first line\n"
  code: "// https://github.com/Kazun1998/library_for_cpp/blob/main/Imos/Cyclic_Imos_1.hpp\n\
    \n#pragma once\n\n#include \"../template/template.hpp\"\n\ntemplate <typename\
    \ T>\nclass Cyclic_Imos_1 {\n    private:\n    std::vector<T> lazy;\n    int n;\n\
    \n    inline int norm(int t) const { return ((t % n) + n) % n; }\n\n    public:\n\
    \    Cyclic_Imos_1(const int n) : n(n), lazy(n, 0) {}\n\n    /// @brief \u5468\
    \u9577 n \u306E\u5186\u74B0\u4E0A\u3067, l \u304B\u3089 r \u307E\u3067 (l \u304B\
    \u3089\u6642\u8A08\u56DE\u308A\u306B r \u307E\u3067) \u306E\u5404\u8981\u7D20\u306B\
    \ x \u3092\u52A0\u7B97\u3059\u308B\n    /// @details l <= r (mod \u3067\u6B63\u898F\
    \u5316\u3057\u305F\u4E0A\u3067) \u306E\u3068\u304D\u306F\u901A\u5E38\u306E\u9589\
    \u533A\u9593 [l, r] \u3078\u306E\u52A0\u7B97, l > r \u306E\u3068\u304D\u306F [l,\
    \ n - 1] \u3068 [0, r] \u3078\u306E\u52A0\u7B97\u3092\u610F\u5473\u3059\u308B\
    .\n    /// @param l \u59CB\u70B9\n    /// @param r \u7D42\u70B9\n    /// @param\
    \ x \u52A0\u7B97\u5024\n    void add(int l, int r, const T x) {\n        if (n\
    \ == 0) return;\n\n        l = norm(l);\n        r = norm(r);\n\n        // l\
    \ <= r : [l, r] \u304C (n-1, 0) \u3092\u307E\u305F\u304C\u306A\u3044\u533A\u9593\
    \u3067\u3042\u308B\u3053\u3068\u3092\u610F\u5473\u3059\u308B\n        if (l <=\
    \ r) {\n            lazy[l] += x;\n            if (r + 1 < n) lazy[r + 1] -= x;\n\
    \        } else {\n            lazy[0] += x;\n            lazy[r + 1] -= x;\n\
    \            lazy[l] += x;\n        }\n    }\n\n    /// @brief \u5468\u9577 n\
    \ \u306E\u5186\u74B0\u4E0A\u3067, l \u304B\u3089 r \u307E\u3067 (l \u304B\u3089\
    \u6642\u8A08\u56DE\u308A\u306B r \u307E\u3067) \u306E\u5404\u8981\u7D20\u306B\
    \ 1 \u3092\u52A0\u7B97\u3059\u308B\n    /// @param l \u59CB\u70B9\n    /// @param\
    \ r \u7D42\u70B9\n    void add(const int l, const int r) { add(l, r, 1); }\n\n\
    \    /// @brief \u5468\u9577 n \u306E\u5186\u74B0\u4E0A\u3067, \u8981\u7D20 t\
    \ \u306B x \u3092\u52A0\u7B97\u3059\u308B\n    /// @param t \u52A0\u7B97\u3059\
    \u308B\u4F4D\u7F6E\n    /// @param x \u52A0\u7B97\u5024\n    void add_point(const\
    \ int t, const T x) { add(t, t, x); }\n\n    /// @brief \u5468\u9577 n \u306E\u5186\
    \u74B0\u4E0A\u3067, l, l + 1, ..., l + (k - 1) \u306E\u5404\u8981\u7D20\u306B\
    \ x \u3092\u52A0\u7B97\u3059\u308B\n    /// @param l \u59CB\u70B9\n    /// @param\
    \ k \u52A0\u7B97\u3059\u308B\u8981\u7D20\u6570\n    /// @param x \u52A0\u7B97\u5024\
    \n    void add_forward(const int l, const int k, const T x) {\n        if (n ==\
    \ 0 || k <= 0) return;\n\n        // q : \u5186\u74B0\u3092\u4F55\u5468\u5206\u52A0\
    \u7B97\u3059\u308B\u304B, m : \u7AEF\u6570\u3068\u3057\u3066\u52A0\u7B97\u3059\
    \u308B\u8981\u7D20\u6570\n        const int q = k / n, m = k % n;\n        if\
    \ (q > 0) add(0, n - 1, x * q);\n        if (m > 0) add(l, l + m - 1, x);\n  \
    \  }\n\n    /// @brief \u5468\u9577 n \u306E\u5186\u74B0\u4E0A\u3067, r, r - 1,\
    \ ..., r - (k - 1) \u306E\u5404\u8981\u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B\
    \n    /// @param r \u59CB\u70B9\n    /// @param k \u52A0\u7B97\u3059\u308B\u8981\
    \u7D20\u6570\n    /// @param x \u52A0\u7B97\u5024\n    void add_back(const int\
    \ r, const int k, const T x) {\n        if (n == 0 || k <= 0) return;\n\n    \
    \    // q : \u5186\u74B0\u3092\u4F55\u5468\u5206\u52A0\u7B97\u3059\u308B\u304B\
    , m : \u7AEF\u6570\u3068\u3057\u3066\u52A0\u7B97\u3059\u308B\u8981\u7D20\u6570\
    \n        const int q = k / n, m = k % n;\n        if (q > 0) add(0, n - 1, x\
    \ * q);\n        if (m > 0) add(r - m + 1, r, x);\n    }\n\n    /// @brief \u7D2F\
    \u7A4D\u548C\u3092\u8A08\u7B97\u3059\u308B\n    std::vector<T> cumulate() {\n\
    \        if (n == 0) return std::vector<T>();\n\n        std::vector<T> res(lazy.begin(),\
    \ lazy.end());\n        for (int i = 1; i < n; ++i) res[i] += res[i - 1];\n\n\
    \        return res;\n    }\n\n    /// @brief \u5185\u90E8\u72B6\u614B\u3092\u30AF\
    \u30EA\u30A2\u3057\u3066\u3001\u518D\u5EA6 add \u3067\u304D\u308B\u72B6\u614B\u306B\
    \u3059\u308B\n    void clear() {\n        std::fill(lazy.begin(), lazy.end(),\
    \ T(0));\n    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Imos/Cyclic_Imos_1.hpp
  requiredBy: []
  timestamp: '2026-08-19 00:51:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Imos/Cyclic_Imos_1.hpp
layout: document
title: "\u5186\u74B0\u4E0A\u306E\u3044\u3082\u3059\u6CD5 (1 \u6B21\u5143 0 \u6B21)"
---

## Outline

周長 $n$ の円環上でいもす法を行うためのクラス.
円環上の弧 (区間が末尾から先頭へまたがることを許す) への一括加算クエリを多数処理した後, 最後に累積和をとることで, 各要素の最終的な値を高速に求めることができる.
[Imos_1](Imos_1.hpp) の円環版.

## Theory

周長 $n$ の円環上の列を, 通常の 1 次元の列 $(x_0, x_1, \dots, x_{n-1})$ とみなし, 添字を $\bmod ~n$ で正規化して扱う.

円環上で $l$ から時計回りに $r$ まで (端点 $l, r$ を含む) の弧を考える.

* $l \leq r$ のとき, この弧は通常の閉区間 $[l, r]$ に一致する.
* $l > r$ のとき, この弧は $(n-1, 0)$ をまたぐため, $[l, n-1]$ と $[0, r]$ の 2 つの閉区間の和集合になる.

いずれの場合も, 差分配列に対して高々 2 箇所の更新を行うだけで弧への一括加算を表現できるので, [Imos_1](Imos_1.hpp) と同様に $O(1)$ 時間で `add` クエリを処理でき, 最後に累積和を $O(n)$ 時間で計算することで, 各要素の最終的な値を求めることができる.

## Contents

### Constructor

```cpp
Cyclic_Imos_1(const int n)
```

* 周長 $n$ の円環いもす法オブジェクトを生成する.
* **引数**
  * $n$: 円環の周長 (要素数)
* **計算量** : $O(n)$ 時間.

### add

```cpp
void add(int l, int r, const T x)
void add(const int l, const int r)
```

* 周長 $n$ の円環上で, $l$ から時計回りに $r$ まで ($l$ から $r$ まで) の各要素に加算を行う.
* $l, r$ は $\bmod n$ で正規化される (負の値や $n$ 以上の値を渡してもよい).
* 正規化後に $l \leq r$ ならば, これは通常の閉区間 $[l, r]$ への加算を意味する. $l > r$ ならば, $[l, n-1]$ と $[0, r]$ への加算を意味する.
* **引数**
  * (1) (引数が3つの場合)
    * $l$: 始点
    * $r$: 終点
    * $x$: 加算値
  * (2) (引数が2つの場合)
    * $l$: 始点
    * $r$: 終点 (加算値は $1$ として扱われる)
* **計算量** : $O(1)$ 時間.

### add_point

```cpp
void add_point(const int t, const T x)
```

* 周長 $n$ の円環上で, 要素 $t$ (mod で正規化) に $x$ を加算する.
* **引数**
  * $t$: 加算する位置
  * $x$: 加算値
* **計算量** : $O(1)$ 時間.

### add_forward

```cpp
void add_forward(const int l, const int k, const T x)
```

* 周長 $n$ の円環上で, $l, l+1, \dots, l+(k-1)$ (mod で正規化, 円環を複数周してもよい) の各要素に $x$ を加算する.
* **引数**
  * $l$: 始点
  * $k$: 加算する要素数 ($k \leq 0$ の場合は何も行わない)
  * $x$: 加算値
* **計算量** : $O(1)$ 時間.

### add_back

```cpp
void add_back(const int r, const int k, const T x)
```

* 周長 $n$ の円環上で, $r, r-1, \dots, r-(k-1)$ (mod で正規化, 円環を複数周してもよい) の各要素に $x$ を加算する.
* **引数**
  * $r$: 始点
  * $k$: 加算する要素数 ($k \leq 0$ の場合は何も行わない)
  * $x$: 加算値
* **計算量** : $O(1)$ 時間.

### cumulate

```cpp
std::vector<T> cumulate()
```

* これまでの加算クエリの結果を累積し, 各要素の最終的な値からなるサイズ $n$ の配列を生成・返却する.
* **計算量** : $O(n)$ 時間.

### clear

```cpp
void clear()
```

* 内部の差分配列を $0$ で初期化し, 再度 `add` を行えるようにクリアする.
* **計算量** : $O(n)$ 時間.

|日付|内容|
|:---:|:---|
|2026/09/13| 円環いもす法 (1 次元 0 次) の実装 |
