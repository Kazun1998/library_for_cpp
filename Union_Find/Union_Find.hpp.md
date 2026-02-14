---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Graph/Weighted_Graph/Kruskal.hpp
    title: "Kruskal \u6CD5"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_library_checker/data_structure/Union_Find.test.cpp
    title: verify/yosupo_library_checker/data_structure/Union_Find.test.cpp
  - icon: ':x:'
    path: verify/yosupo_library_checker/graph/Minimum_Spanning_Tree_by_Kruskal.test.cpp
    title: verify/yosupo_library_checker/graph/Minimum_Spanning_Tree_by_Kruskal.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Union_Find/Union_Find.hpp\"\n\nclass Union_Find{\n    private:\n\
    \    int N;\n    vector<int> data;\n    int _group_number;\n\n    public:\n  \
    \  Union_Find(int N) : N(N), data(N, -1), _group_number(N) {}\n\n    // x \u304C\
    \u5C5E\u3059\u308B\u65CF\u306E\u4EE3\u8868\u5143\u3092\u6C42\u3081\u308B.\n  \
    \  int find(int x) { return data[x] < 0 ? x: data[x] = find(data[x]); }\n\n  \
    \  // \u9802\u70B9\u3092 1 \u500B\u8FFD\u52A0\u3059\u308B.\n    int add_vertex()\
    \ {\n      data.emplace_back(-1);\n      N++;\n      _group_number++;\n\n    \
    \  return N - 1;\n    }\n\n    // \u9802\u70B9\u3092 k \u500B\u8FFD\u52A0\u3059\
    \u308B.\n    vector<int> add_vertices(int k) {\n      vector<int> ids;\n     \
    \ for (; k; k--) { ids.emplace_back(add_vertex()); }\n\n      return ids;\n  \
    \  }\n\n    // x \u3068 y \u3092\u7D50\u5408\u3059\u308B.\n    // force \u3092\
    \ true \u306B\u3059\u308B\u3068, \u5FC5\u305A find(x) \u304C\u6839\u306B\u306A\
    \u308B\u3088\u3046\u306B\u7D50\u5408\u3059\u308B.\n    // \u8FD4\u308A\u5024:\
    \ \u5143\u3005\u975E\u9023\u7D50\u306A\u3089\u3070 true, \u9023\u7D50\u306A\u3089\
    \u3070 false\n    bool unite(int x, int y, bool force = false) {\n        x =\
    \ find(x);\n        y = find(y);\n\n        if (x == y) { return false; }\n\n\
    \        if (!force && (data[x] > data[y])) { swap(x, y); }\n\n        data[x]\
    \ += data[y];\n        data[y] = x;\n\n        _group_number--;\n\n        return\
    \ true;\n    }\n\n    // x \u304C\u5C5E\u3059\u308B\u65CF\u306B\u304A\u3051\u308B\
    \u4F4D\u6570\u3092\u6C42\u3081\u308B.\n    int size(int x) { return -data[find(x)];\
    \ }\n\n    // x, y \u306F\u540C\u3058\u9023\u7D50\u6210\u5206\u306B\u3042\u308B\
    ?\n    int same(int x, int y) { return find(x) == find(y); }\n\n    // \u9023\u7D50\
    \u6210\u5206\u306E\u6570\u3092\u6C42\u3081\u308B.\n    inline int group_count()\
    \ const { return _group_number; }\n};\n"
  code: "#pragma once\n\nclass Union_Find{\n    private:\n    int N;\n    vector<int>\
    \ data;\n    int _group_number;\n\n    public:\n    Union_Find(int N) : N(N),\
    \ data(N, -1), _group_number(N) {}\n\n    // x \u304C\u5C5E\u3059\u308B\u65CF\u306E\
    \u4EE3\u8868\u5143\u3092\u6C42\u3081\u308B.\n    int find(int x) { return data[x]\
    \ < 0 ? x: data[x] = find(data[x]); }\n\n    // \u9802\u70B9\u3092 1 \u500B\u8FFD\
    \u52A0\u3059\u308B.\n    int add_vertex() {\n      data.emplace_back(-1);\n  \
    \    N++;\n      _group_number++;\n\n      return N - 1;\n    }\n\n    // \u9802\
    \u70B9\u3092 k \u500B\u8FFD\u52A0\u3059\u308B.\n    vector<int> add_vertices(int\
    \ k) {\n      vector<int> ids;\n      for (; k; k--) { ids.emplace_back(add_vertex());\
    \ }\n\n      return ids;\n    }\n\n    // x \u3068 y \u3092\u7D50\u5408\u3059\u308B\
    .\n    // force \u3092 true \u306B\u3059\u308B\u3068, \u5FC5\u305A find(x) \u304C\
    \u6839\u306B\u306A\u308B\u3088\u3046\u306B\u7D50\u5408\u3059\u308B.\n    // \u8FD4\
    \u308A\u5024: \u5143\u3005\u975E\u9023\u7D50\u306A\u3089\u3070 true, \u9023\u7D50\
    \u306A\u3089\u3070 false\n    bool unite(int x, int y, bool force = false) {\n\
    \        x = find(x);\n        y = find(y);\n\n        if (x == y) { return false;\
    \ }\n\n        if (!force && (data[x] > data[y])) { swap(x, y); }\n\n        data[x]\
    \ += data[y];\n        data[y] = x;\n\n        _group_number--;\n\n        return\
    \ true;\n    }\n\n    // x \u304C\u5C5E\u3059\u308B\u65CF\u306B\u304A\u3051\u308B\
    \u4F4D\u6570\u3092\u6C42\u3081\u308B.\n    int size(int x) { return -data[find(x)];\
    \ }\n\n    // x, y \u306F\u540C\u3058\u9023\u7D50\u6210\u5206\u306B\u3042\u308B\
    ?\n    int same(int x, int y) { return find(x) == find(y); }\n\n    // \u9023\u7D50\
    \u6210\u5206\u306E\u6570\u3092\u6C42\u3081\u308B.\n    inline int group_count()\
    \ const { return _group_number; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Union_Find/Union_Find.hpp
  requiredBy:
  - Graph/Weighted_Graph/Kruskal.hpp
  timestamp: '2026-02-14 20:38:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_library_checker/graph/Minimum_Spanning_Tree_by_Kruskal.test.cpp
  - verify/yosupo_library_checker/data_structure/Union_Find.test.cpp
documentation_of: Union_Find/Union_Find.hpp
layout: document
title: Union Find
---

## Outline

無向グラフ $G = (V, E)$ に対して,

* 辺の追加
* $2$ 頂点 $x, y \in V$ に対する連結判定

を高速に行うことができるデータ構造

## Contents

### Constructer

```cpp
Union_Find U(int N)
```

* $N$ 頂点の空グラフを生成する.

### find

```cpp
int U.find(int x)
```

* 頂点 $x$ が属する連結成分の代表元を求める.
* **制約**
  * $0 \leq x \lt N$.
* **計算量**
  * ならし $O(\alpha(N))$ 時間.

### unite

```cpp
bool U.unite(int x, int y, bool force = false)
```

* 無向辺 $xy$ を追加する.
* **引数**
  * `force` を `true` にすると, 連結成分の代表元を `find(x)` になるようにマージするようになる.
* **制約**
  * $0 \leq x \lt N$.
  * $0 \leq y \lt N$.
* **返り値**
  * $x, y$ が元々非連結ならば `true`, 元々連結ならば `false`.
* **計算量**
  * ならし $O(\alpha(N))$ 時間.

### size
```cpp
bool U.size(int x)
```

* 頂点 $x$ が属する連結成分における頂点数を求める.
* **制約**
  * $0 \leq x \lt N$.
* **計算量**
  * ならし $O(\alpha(N))$ 時間.

### same

```cpp
bool U.same(int x, int y)
```

* 頂点 $x, y$ が連結かどうかを判定する.
* **制約**
  * $0 \leq x \lt N$.
  * $0 \leq y \lt N$.
* **計算量**
  * ならし $O(\alpha(N))$ 時間.

### group_count

```cpp
int U.group_count()
```

* グラフ $G$ の連結成分を求める.
* **計算量**
  * $O(1)$ 時間.
