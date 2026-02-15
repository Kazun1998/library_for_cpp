---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Binary_Indexed_Tree/Range_Binary_Indexed_Tree.hpp
    title: "\u533A\u9593\u52A0\u7B97 Binary Indexed Tree"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu_online_judge/dsl/2G.test.cpp
    title: verify/aizu_online_judge/dsl/2G.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Binary_Indexed_Tree.test.cpp
    title: verify/yosupo_library_checker/data_structure/Binary_Indexed_Tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Binary_Indexed_Tree/Binary_Indexed_Tree.hpp\"\n\ntemplate<typename\
    \ G>\nclass Binary_Indexed_Tree{\n    private:\n    int n;\n    vector<G> data;\n\
    \    G zero;\n    function<G(G, G)> op;\n    function<G(G)> neg;\n\n    // \u521D\
    \u671F\u5316\n    public:\n    Binary_Indexed_Tree() = default;\n\n    Binary_Indexed_Tree(int\
    \ n, const function<G(G, G)> op, const G zero, const function<G(G)> neg): n(n),\
    \ op(op), zero(zero), neg(neg) {\n        data.assign(n + 1, zero);\n    }\n\n\
    \    Binary_Indexed_Tree(const vector<G> &vec, const function<G(G, G)> op, const\
    \ G zero, const function<G(G)> neg):\n        Binary_Indexed_Tree(vec.size(),\
    \ op, zero, neg) {\n            for (int k = 1; k <= n; k++){\n              \
    \  data[k] = op(data[k], vec[k - 1]);\n                int l = k + (k & (-k));\n\
    \                if (l <= n) { data[l] = op(data[l], data[k]); }\n           \
    \ }\n        }\n\n    // \u7B2C k \u8981\u7D20\u306B x \u3092\u5DE6\u304B\u3089\
    \u52A0\u3048\u308B.\n    void add(int k, G x) {\n        for (++k; k <= n; k +=\
    \ k & (-k)) { data[k] = op(data[k], x); }\n    }\n\n    // \u7B2C k \u8981\u7D20\
    \u3092 x \u306B\u5909\u66F4\u3059\u308B.\n    void update(int k, G x) {\n    \
    \    add(k, op(neg((*this)[k]), x));\n    }\n\n    // \u53F3\u534A\u958B\u533A\
    \u9593 [0, k] \u306B\u304A\u3051\u308B\u7DCF\u548C\u3092\u6C42\u3081\u308B.\n\
    \    G sum(int k) const {\n        G total = zero;\n\n        for (++k; k > 0;\
    \ k -= k & (-k)) { total = op(total, data[k]); }\n\n        return total;\n  \
    \  }\n\n    // \u53F3\u534A\u958B\u533A\u9593 [l, r] \u306B\u304A\u3051\u308B\u7DCF\
    \u548C\u3092\u6C42\u3081\u308B.\n    G sum(int l, int r) const {\n        l =\
    \ max(l, 0);\n        r = min(r, n - 1);\n\n        if (l > r) { return zero;\
    \ }\n        else if (l == 0) { return sum(r); }\n        else { return op(sum(r),\
    \ neg(sum(l - 1))); }\n    }\n\n    // \u7B2C k \u8981\u7D20\u3092\u53D6\u5F97\
    \u3059\u308B.\n    inline G operator[](int k) const { return sum(k, k); }\n};\n\
    \ntemplate<typename G>\nBinary_Indexed_Tree<G> Group_Binary_Indexed_Tree(const\
    \ vector<G> &vec, G zero){\n    auto add = [](G x, G y) -> G { return x + y; };\n\
    \    auto inv = [](G x) -> G { return -x; };\n    return Binary_Indexed_Tree<G>(vec,\
    \ add, zero, inv);\n}\n"
  code: "#pragma once\n\ntemplate<typename G>\nclass Binary_Indexed_Tree{\n    private:\n\
    \    int n;\n    vector<G> data;\n    G zero;\n    function<G(G, G)> op;\n   \
    \ function<G(G)> neg;\n\n    // \u521D\u671F\u5316\n    public:\n    Binary_Indexed_Tree()\
    \ = default;\n\n    Binary_Indexed_Tree(int n, const function<G(G, G)> op, const\
    \ G zero, const function<G(G)> neg): n(n), op(op), zero(zero), neg(neg) {\n  \
    \      data.assign(n + 1, zero);\n    }\n\n    Binary_Indexed_Tree(const vector<G>\
    \ &vec, const function<G(G, G)> op, const G zero, const function<G(G)> neg):\n\
    \        Binary_Indexed_Tree(vec.size(), op, zero, neg) {\n            for (int\
    \ k = 1; k <= n; k++){\n                data[k] = op(data[k], vec[k - 1]);\n \
    \               int l = k + (k & (-k));\n                if (l <= n) { data[l]\
    \ = op(data[l], data[k]); }\n            }\n        }\n\n    // \u7B2C k \u8981\
    \u7D20\u306B x \u3092\u5DE6\u304B\u3089\u52A0\u3048\u308B.\n    void add(int k,\
    \ G x) {\n        for (++k; k <= n; k += k & (-k)) { data[k] = op(data[k], x);\
    \ }\n    }\n\n    // \u7B2C k \u8981\u7D20\u3092 x \u306B\u5909\u66F4\u3059\u308B\
    .\n    void update(int k, G x) {\n        add(k, op(neg((*this)[k]), x));\n  \
    \  }\n\n    // \u53F3\u534A\u958B\u533A\u9593 [0, k] \u306B\u304A\u3051\u308B\u7DCF\
    \u548C\u3092\u6C42\u3081\u308B.\n    G sum(int k) const {\n        G total = zero;\n\
    \n        for (++k; k > 0; k -= k & (-k)) { total = op(total, data[k]); }\n\n\
    \        return total;\n    }\n\n    // \u53F3\u534A\u958B\u533A\u9593 [l, r]\
    \ \u306B\u304A\u3051\u308B\u7DCF\u548C\u3092\u6C42\u3081\u308B.\n    G sum(int\
    \ l, int r) const {\n        l = max(l, 0);\n        r = min(r, n - 1);\n\n  \
    \      if (l > r) { return zero; }\n        else if (l == 0) { return sum(r);\
    \ }\n        else { return op(sum(r), neg(sum(l - 1))); }\n    }\n\n    // \u7B2C\
    \ k \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B.\n    inline G operator[](int k)\
    \ const { return sum(k, k); }\n};\n\ntemplate<typename G>\nBinary_Indexed_Tree<G>\
    \ Group_Binary_Indexed_Tree(const vector<G> &vec, G zero){\n    auto add = [](G\
    \ x, G y) -> G { return x + y; };\n    auto inv = [](G x) -> G { return -x; };\n\
    \    return Binary_Indexed_Tree<G>(vec, add, zero, inv);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Binary_Indexed_Tree/Binary_Indexed_Tree.hpp
  requiredBy:
  - Binary_Indexed_Tree/Range_Binary_Indexed_Tree.hpp
  timestamp: '2026-02-15 15:30:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Binary_Indexed_Tree.test.cpp
  - verify/aizu_online_judge/dsl/2G.test.cpp
documentation_of: Binary_Indexed_Tree/Binary_Indexed_Tree.hpp
layout: document
title: Binary Indexed Tree (Fenwick Tree)
---

## Outline

可換群 $G = (G, +, 0_G)$ の列に $A$ に対する 1 点更新, 区間積の取得を得意とするデータ構造.

## Contents

### Constructer

```cpp
Binary_Indexed_Tree B(int n, const function<G(G, G)> op, const G zero, const function<G(G)> neg)
```

* 長さが $n$ の各項が $0_G$ の列で初期化する.
* $\operatorname{op}: M \times M \to M; (x, y) \mapsto x + y$ : $G$ 上の二項演算
* $\mathrm{zero}$ : $G$ の単位元 $0_G$.
* $\mathrm{neg}: G \to G; x \mapsto -x$ : $G$ 上の逆元関数
* **計算量** : $O(N)$ 時間

```cpp
Binary_Indexed_Tree (const vector<G> &vec, const function<G(G, G)> op, const G zero, const function<G(G)> neg)
```

* $G$ の列 `vec` で初期化する.
* $\operatorname{op}: M \times M \to M; (x, y) \mapsto x + y$ : $G$ 上の二項演算
* $\mathrm{zero}$ : $G$ の単位元 $0_G$.
* $\mathrm{neg}: G \to G; x \mapsto -x$ : $G$ 上の逆元関数
* **計算量** : $O(N)$ 時間

### add

```cpp
void B.add(int k, G x)
```

* 第 $k$ 項に $x \in G$ を加算する.
* **制約**
  * $0 \leq k \lt N$.
* **計算量** : $O(\log N)$ 時間.

### update

```cpp
void B.update(int k, G x)
```

* 第 $k$ 項を $x \in G$ に変更する.
* **制約**
  * $0 \leq k \lt N$.
* **計算量** : $O(\log N)$ 時間.


### sum

```cpp
G B.sum(int k)
```

* 連続部分列における総和 $\displaystyle \sum_{k=0}^k A_x$ を求める.
* **制約**
  * $0 \leq k \lt N$.
* **計算量** : $O(\log N)$ 時間.

```cpp
G B.sum(int l, int r)
```

* 連続部分列における総和 $\displaystyle \sum_{k=l}^r A_k$ を求める.
* **制約**
  * $0 \leq l \leq r \lt N$.
* **計算量** : $O(\log N)$ 時間.
* **注意点**
  * $l \leq r$ でないとき, 返り値は単位元 $0_G$ になる.

### subscript operator
```cpp
G operator[](int k)
```

* $A_k$ を求める.
* **制約**
  * $0 \leq k \lt N$.
* **計算量** : $O(\log N)$ 時間.
