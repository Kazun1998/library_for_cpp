---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Union_Find/Union_Find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/yosupo_library_checker/data_structure/Union_Find.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include<bits/stdc++.h>\n\
    \nusing namespace std;\n\n#line 2 \"Union_Find/Union_Find.hpp\"\n\nclass Union_Find{\n\
    \    private:\n    int N;\n    vector<int> data;\n    int _group_number;\n\n \
    \   public:\n    Union_Find(int N) : N(N), data(N, -1), _group_number(N) {}\n\n\
    \    // x \u304C\u5C5E\u3059\u308B\u65CF\u306E\u4EE3\u8868\u5143\u3092\u6C42\u3081\
    \u308B.\n    int find(int x) { return data[x] < 0 ? x: data[x] = find(data[x]);\
    \ }\n\n    // \u9802\u70B9\u3092 1 \u500B\u8FFD\u52A0\u3059\u308B.\n    int add_vertex()\
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
    \ const { return _group_number; }\n};\n#line 8 \"verify/yosupo_library_checker/data_structure/Union_Find.test.cpp\"\
    \n\nint main() {\n    int N, Q; cin >> N >> Q;\n    Union_Find U(N);\n\n    for\
    \ (int q = 1; q <= Q; q++){\n        int t, u, v; scanf(\"%d%d%d\", &t, &u, &v);\n\
    \        if (t == 0) { U.unite(u, v); }\n        else if (t == 1) { cout << U.same(u,\
    \ v) << \"\\n\"; }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include<bits/stdc++.h>\n\
    \nusing namespace std;\n\n#include\"../../../Union_Find/Union_Find.hpp\"\n\nint\
    \ main() {\n    int N, Q; cin >> N >> Q;\n    Union_Find U(N);\n\n    for (int\
    \ q = 1; q <= Q; q++){\n        int t, u, v; scanf(\"%d%d%d\", &t, &u, &v);\n\
    \        if (t == 0) { U.unite(u, v); }\n        else if (t == 1) { cout << U.same(u,\
    \ v) << \"\\n\"; }\n    }\n}\n"
  dependsOn:
  - Union_Find/Union_Find.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/data_structure/Union_Find.test.cpp
  requiredBy: []
  timestamp: '2025-10-18 12:03:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/data_structure/Union_Find.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/data_structure/Union_Find.test.cpp
- /verify/verify/yosupo_library_checker/data_structure/Union_Find.test.cpp.html
title: verify/yosupo_library_checker/data_structure/Union_Find.test.cpp
---
