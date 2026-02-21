---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Tree/Subtree_Monoid_Vertex_Query.hpp
    title: "\u90E8\u5206\u6728\u306B\u95A2\u3059\u308B\u30AF\u30A8\u30EA"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Point_Set_Range_Composite.test.cpp
    title: verify/yosupo_library_checker/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Segment_Tree.test.cpp
    title: verify/yosupo_library_checker/data_structure/Segment_Tree.test.cpp
  - icon: ':x:'
    path: verify/yosupo_library_checker/tree/Vertex_Add_Subtree_Sum.test.cpp
    title: verify/yosupo_library_checker/tree/Vertex_Add_Subtree_Sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Segment_Tree/Segment_Tree.hpp\"\n\ntemplate<typename M>\n\
    class Segment_Tree{\n    private:\n    int n;\n    vector<M> data;\n    const\
    \ function<M(M, M)> op;\n    const M unit;\n\n    public:\n    Segment_Tree(int\
    \ size, const function<M(M, M)> op, const M unit): n(), op(op), unit(unit) {\n\
    \        int m = 1;\n        while (m < size) { m *= 2; }\n\n        n = m;\n\
    \        data.assign(2 * n, unit);\n    }\n\n    Segment_Tree(const vector<M>\
    \ &vec, const function<M(M, M)> op, const M unit): \n        Segment_Tree(vec.size(),\
    \ op, unit) {\n            for (int k = 0; k < vec.size(); k++) { data[k + n]\
    \ = vec[k]; }\n            for (int k = n - 1; k > 0; k--) { recalc(k); }\n  \
    \      }\n\n    private:\n    void recalc(int k) { data[k] = op(data[k << 1],\
    \ data[k << 1 | 1]); }\n\n    public:\n    // \u7B2C k \u8981\u7D20\u3092 x \u306B\
    \u66F4\u65B0\u3059\u308B\n    void update(int k, M x) {\n        k += n;\n   \
    \     data[k] = x;\n\n        for (k >>= 1; k; k >>= 1) { recalc(k); }\n    }\n\
    \n    // \u7B2C l \u8981\u7D20\u304B\u3089\u7B2C r \u8981\u7D20\u307E\u3067\u306E\
    \u7DCF\u7A4D\u3092\u6C42\u3081\u308B\n    M product(int l, int r){\n        l\
    \ += n; r += n + 1;\n        M vl = unit, vr = unit;\n        while (l < r){\n\
    \            if (l & 1){\n                vl = op(vl, data[l]);\n            \
    \    l++;\n            }\n\n            if (r & 1){\n                r--;\n  \
    \              vr = op(data[r], vr);\n            }\n\n            l >>= 1; r\
    \ >>= 1;\n        }\n\n        return op(vl, vr);\n    }\n\n    template<typename\
    \ Func>\n    int max_right(int l, const Func &cond) {\n        assert(cond(unit));\n\
    \        if (l == n) return n;\n\n        l += n;\n        M sm = unit;\n    \
    \    do {\n            while (l % 2 == 0) l >>= 1;\n\n            if (cond(op(sm,\
    \ data[l]))) {\n                sm = op(sm ,data[l]);\n                ++l;\n\
    \                continue;\n            }\n\n            while (l < n) {\n   \
    \             l = l << 1;\n                if (cond(op(sm, data[l]))) {\n    \
    \                sm = op(sm, data[l]);\n                    ++l;\n           \
    \     }\n            }\n            return l - n;\n        } while ((l & -l) !=\
    \ l);\n        return n;\n    }\n\n    template<typename Func>\n    int min_left(int\
    \ r, const Func &cond) {\n        assert(cond(unit));\n        if (r == 0) return\
    \ 0;\n\n        r += n;\n        M sm = unit;\n        do {\n            r--;\n\
    \            while (r > 1 && (r % 2)) r >>= 1;\n\n            if (cond(op(data[r],\
    \ sm))) {\n                sm = op(data[r], sm);\n                continue;\n\
    \            }\n\n            while (r < n) {\n                r = (r << 1) |\
    \ 1;\n                if (cond(op(data[r], sm))) {\n                    sm = op(data[r],\
    \ sm);\n                    r--;\n                }\n            }\n         \
    \   return r + 1 - n;\n\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n};\n"
  code: "#pragma once\n\ntemplate<typename M>\nclass Segment_Tree{\n    private:\n\
    \    int n;\n    vector<M> data;\n    const function<M(M, M)> op;\n    const M\
    \ unit;\n\n    public:\n    Segment_Tree(int size, const function<M(M, M)> op,\
    \ const M unit): n(), op(op), unit(unit) {\n        int m = 1;\n        while\
    \ (m < size) { m *= 2; }\n\n        n = m;\n        data.assign(2 * n, unit);\n\
    \    }\n\n    Segment_Tree(const vector<M> &vec, const function<M(M, M)> op, const\
    \ M unit): \n        Segment_Tree(vec.size(), op, unit) {\n            for (int\
    \ k = 0; k < vec.size(); k++) { data[k + n] = vec[k]; }\n            for (int\
    \ k = n - 1; k > 0; k--) { recalc(k); }\n        }\n\n    private:\n    void recalc(int\
    \ k) { data[k] = op(data[k << 1], data[k << 1 | 1]); }\n\n    public:\n    //\
    \ \u7B2C k \u8981\u7D20\u3092 x \u306B\u66F4\u65B0\u3059\u308B\n    void update(int\
    \ k, M x) {\n        k += n;\n        data[k] = x;\n\n        for (k >>= 1; k;\
    \ k >>= 1) { recalc(k); }\n    }\n\n    // \u7B2C l \u8981\u7D20\u304B\u3089\u7B2C\
    \ r \u8981\u7D20\u307E\u3067\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\n    M\
    \ product(int l, int r){\n        l += n; r += n + 1;\n        M vl = unit, vr\
    \ = unit;\n        while (l < r){\n            if (l & 1){\n                vl\
    \ = op(vl, data[l]);\n                l++;\n            }\n\n            if (r\
    \ & 1){\n                r--;\n                vr = op(data[r], vr);\n       \
    \     }\n\n            l >>= 1; r >>= 1;\n        }\n\n        return op(vl, vr);\n\
    \    }\n\n    template<typename Func>\n    int max_right(int l, const Func &cond)\
    \ {\n        assert(cond(unit));\n        if (l == n) return n;\n\n        l +=\
    \ n;\n        M sm = unit;\n        do {\n            while (l % 2 == 0) l >>=\
    \ 1;\n\n            if (cond(op(sm, data[l]))) {\n                sm = op(sm ,data[l]);\n\
    \                ++l;\n                continue;\n            }\n\n          \
    \  while (l < n) {\n                l = l << 1;\n                if (cond(op(sm,\
    \ data[l]))) {\n                    sm = op(sm, data[l]);\n                  \
    \  ++l;\n                }\n            }\n            return l - n;\n       \
    \ } while ((l & -l) != l);\n        return n;\n    }\n\n    template<typename\
    \ Func>\n    int min_left(int r, const Func &cond) {\n        assert(cond(unit));\n\
    \        if (r == 0) return 0;\n\n        r += n;\n        M sm = unit;\n    \
    \    do {\n            r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n\n\
    \            if (cond(op(data[r], sm))) {\n                sm = op(data[r], sm);\n\
    \                continue;\n            }\n\n            while (r < n) {\n   \
    \             r = (r << 1) | 1;\n                if (cond(op(data[r], sm))) {\n\
    \                    sm = op(data[r], sm);\n                    r--;\n       \
    \         }\n            }\n            return r + 1 - n;\n\n        } while ((r\
    \ & -r) != r);\n        return 0;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Segment_Tree/Segment_Tree.hpp
  requiredBy:
  - Tree/Subtree_Monoid_Vertex_Query.hpp
  timestamp: '2026-01-12 13:35:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Point_Set_Range_Composite.test.cpp
  - verify/yosupo_library_checker/data_structure/Segment_Tree.test.cpp
  - verify/yosupo_library_checker/tree/Vertex_Add_Subtree_Sum.test.cpp
documentation_of: Segment_Tree/Segment_Tree.hpp
layout: document
title: Segment Tree
---

## Outline

モノイド $M = (M, *, e_M)$ の列に $A$ に対する 1 点更新, 区間積の取得を得意とするデータ構造.

## Contents

### Constructer

```cpp
Segment_Tree S(int size, const function<M(M, M)> op, const M unit)
```

- 長さが `size` の各項が $e_M$ の列で初期化する.
- $\operatorname{op}: M \times M \to M; (x, y) \mapsto x * y$ : 二項演算
- $\mathrm{unit}$ : $M$ の単位元 $e_M$.

```cpp
Segment_Tree S(const vector<M> &vec, const function<M(M, M)> op, const M unit)
```

- `vec` で初期化する.
- $\operatorname{op}: M \times M \to M; (x, y) \mapsto x * y$ : 二項演算
- $\mathrm{unit}$ : $M$ の単位元 $e_M$.
- **計算量** : $O(1)$ Time.

### update

```cpp
void S.update(int k, M x)
```

- 第 $k$ 要素を $x$ に更新する.
- **制約**
  - $0 \leq k \lt N$.
- **計算量** : $O(\log N)$ 時間

### product

```cpp
M S.product(int l, int r)
```

* 連続部分列における積 $A_l * A_{l+1} * \dots A_{r-1} * A_r$ を求める.
* **制約**
  * $0 \leq l \leq r \lt N$.
* **注意点**
  * $l \leq r$ でないとき, 返り値は単位元 $e_M$ になる.
