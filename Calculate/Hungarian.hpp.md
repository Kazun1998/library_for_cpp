---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_library_checker/graph/Assignment_Problem.test.cpp
    title: verify/yosupo_library_checker/graph/Assignment_Problem.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Calculate/Hungarian.hpp\"\n#include <iostream>\n#include\
    \ <vector>\n#include <algorithm>\n#include <limits>\n\nusing namespace std;\n\n\
    template<typename T>\nclass Hungarian {\n    int n, m;\n    vector<vector<T>>\
    \ matrix;\n    const T INF = numeric_limits<T>::max();\n    vector<T> u, v, minv;\n\
    \    vector<int> p, way;\n    vector<bool> used;\n    bool maximize_mode;\n\n\
    \    void step(int &j0) {\n        used[j0] = true;\n        int i0 = p[j0];\n\
    \        T delta = INF;\n        int j1 = -1;\n\n        for (int j = 0; j < m;\
    \ ++j) {\n            if (!used[j]) {\n                T cur = matrix[i0][j] -\
    \ u[i0] - v[j];\n                if (cur < minv[j]) {\n                    minv[j]\
    \ = cur;\n                    way[j] = j0;\n                }\n              \
    \  if (minv[j] < delta) {\n                    delta = minv[j];\n            \
    \        j1 = j;\n                }\n            }\n        }\n\n        for (int\
    \ j = 0; j <= m; ++j) {\n            if (used[j]) {\n                u[p[j]] +=\
    \ delta;\n                v[j] -= delta;\n            } else {\n             \
    \   if (minv[j] < INF) minv[j] -= delta;\n            }\n        }\n        j0\
    \ = j1;\n    }\n\n    void update_matching(int j0) {\n        do {\n         \
    \   int j1 = way[j0];\n            p[j0] = p[j1];\n            j0 = j1;\n    \
    \    } while (j0 != m);\n    }\n\n    void construct_result() {\n        total_cost\
    \ = 0;\n        matching.assign(n, -1);\n        for (int j = 0; j < m; ++j) {\n\
    \            int i = p[j];\n            if (i != n) {\n                matching[i]\
    \ = j;\n                total_cost += matrix[i][j];\n            }\n        }\n\
    \        if (maximize_mode) total_cost = -total_cost;\n    }\n\n    void augment(int\
    \ s) {\n        p[m] = s;\n        int j0 = m;\n\n        fill(minv.begin(), minv.end(),\
    \ INF);\n        fill(used.begin(), used.end(), false);\n\n        do {\n    \
    \        step(j0);\n        } while (p[j0] != n);\n\n        update_matching(j0);\n\
    \    }\n\n    public:\n    vector<int> matching;\n    T total_cost;\n\n    Hungarian(vector<vector<T>>\
    \ cost_matrix, bool maximize = false) : matrix(cost_matrix), maximize_mode(maximize)\
    \ {\n        n = matrix.size();\n        m = n == 0 ? 0 : matrix[0].size();\n\n\
    \        if (maximize_mode) {\n            for (int i = 0; i < n; ++i) {\n   \
    \             for (int j = 0; j < m; ++j) {\n                    matrix[i][j]\
    \ = -matrix[i][j];\n                }\n            }\n        }\n\n        //\
    \ initialize\n        // 0-based indexing for internal logic, n is dummy\n   \
    \     u.assign(n + 1, 0);\n        v.assign(m + 1, 0);\n        p.assign(m + 1,\
    \ n);\n        way.assign(m + 1, -1);\n        minv.assign(m + 1, INF);\n    \
    \    used.assign(m + 1, false);\n\n        solve();\n    }\n\n    void solve()\
    \ {\n        for (int i = 0; i < n; ++i) augment(i);\n\n        construct_result();\n\
    \    }\n};\n"
  code: "#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <limits>\n\
    \nusing namespace std;\n\ntemplate<typename T>\nclass Hungarian {\n    int n,\
    \ m;\n    vector<vector<T>> matrix;\n    const T INF = numeric_limits<T>::max();\n\
    \    vector<T> u, v, minv;\n    vector<int> p, way;\n    vector<bool> used;\n\
    \    bool maximize_mode;\n\n    void step(int &j0) {\n        used[j0] = true;\n\
    \        int i0 = p[j0];\n        T delta = INF;\n        int j1 = -1;\n\n   \
    \     for (int j = 0; j < m; ++j) {\n            if (!used[j]) {\n           \
    \     T cur = matrix[i0][j] - u[i0] - v[j];\n                if (cur < minv[j])\
    \ {\n                    minv[j] = cur;\n                    way[j] = j0;\n  \
    \              }\n                if (minv[j] < delta) {\n                   \
    \ delta = minv[j];\n                    j1 = j;\n                }\n         \
    \   }\n        }\n\n        for (int j = 0; j <= m; ++j) {\n            if (used[j])\
    \ {\n                u[p[j]] += delta;\n                v[j] -= delta;\n     \
    \       } else {\n                if (minv[j] < INF) minv[j] -= delta;\n     \
    \       }\n        }\n        j0 = j1;\n    }\n\n    void update_matching(int\
    \ j0) {\n        do {\n            int j1 = way[j0];\n            p[j0] = p[j1];\n\
    \            j0 = j1;\n        } while (j0 != m);\n    }\n\n    void construct_result()\
    \ {\n        total_cost = 0;\n        matching.assign(n, -1);\n        for (int\
    \ j = 0; j < m; ++j) {\n            int i = p[j];\n            if (i != n) {\n\
    \                matching[i] = j;\n                total_cost += matrix[i][j];\n\
    \            }\n        }\n        if (maximize_mode) total_cost = -total_cost;\n\
    \    }\n\n    void augment(int s) {\n        p[m] = s;\n        int j0 = m;\n\n\
    \        fill(minv.begin(), minv.end(), INF);\n        fill(used.begin(), used.end(),\
    \ false);\n\n        do {\n            step(j0);\n        } while (p[j0] != n);\n\
    \n        update_matching(j0);\n    }\n\n    public:\n    vector<int> matching;\n\
    \    T total_cost;\n\n    Hungarian(vector<vector<T>> cost_matrix, bool maximize\
    \ = false) : matrix(cost_matrix), maximize_mode(maximize) {\n        n = matrix.size();\n\
    \        m = n == 0 ? 0 : matrix[0].size();\n\n        if (maximize_mode) {\n\
    \            for (int i = 0; i < n; ++i) {\n                for (int j = 0; j\
    \ < m; ++j) {\n                    matrix[i][j] = -matrix[i][j];\n           \
    \     }\n            }\n        }\n\n        // initialize\n        // 0-based\
    \ indexing for internal logic, n is dummy\n        u.assign(n + 1, 0);\n     \
    \   v.assign(m + 1, 0);\n        p.assign(m + 1, n);\n        way.assign(m + 1,\
    \ -1);\n        minv.assign(m + 1, INF);\n        used.assign(m + 1, false);\n\
    \n        solve();\n    }\n\n    void solve() {\n        for (int i = 0; i < n;\
    \ ++i) augment(i);\n\n        construct_result();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Calculate/Hungarian.hpp
  requiredBy: []
  timestamp: '2026-02-15 15:30:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_library_checker/graph/Assignment_Problem.test.cpp
documentation_of: Calculate/Hungarian.hpp
layout: document
title: "Hungarian \u6CD5"
---

## Outline

以下で表される割当問題を Hungarian 法で解く.

$N \leq M$ とする. $N$ 行 $M$ 列の行列 $A = (A_{i,j})_{\substack{1 \leq i \leq N \\ 1 \leq j \leq M}}$ が与えられる.

このとき,

$$ \sum_{i=1}^N A_{i, P_i} $$

を最小にする, 以下を満たす長さ $N$ の列を求める.

* $1 \leq P_i \leq M$.
* $P_1, \dots, P_M$ は全て異なる.

このクラスでは, この問題を Hungarian 法で解く.

## History 

|日付|内容|
|:---:|:---:|
|2026/02/15| スライド最大値 実装 |
