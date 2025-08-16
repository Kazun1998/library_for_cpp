---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Union_Find.test.cpp
    title: verify/yosupo_library_checker/data_structure/Union_Find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Union_Find/Union_Find.hpp\"\n\nclass Union_Find{\n    private:\n\
    \    int N;\n    vector<int> data;\n    int group_number;\n\n    public:\n   \
    \ Union_Find(int N) : N(N), data(N, -1), group_number(N) {}\n\n    // x \u304C\
    \u5C5E\u3059\u308B\u65CF\u306E\u4EE3\u8868\u5143\u3092\u6C42\u3081\u308B.\n  \
    \  int find(int x) { return data[x] < 0 ? x: data[x] = find(data[x]); }\n\n  \
    \  // x \u3068 y \u3092\u7D50\u5408\u3059\u308B.\n    // \u8FD4\u308A\u5024: \u5143\
    \u3005\u975E\u9023\u7D50\u306A\u3089\u3070 true, \u9023\u7D50\u306A\u3089\u3070\
    \ false\n    bool unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n\
    \n        if (x == y) { return false; }\n\n        if (data[x] > data[y]) { swap(x,\
    \ y); }\n\n        data[x] += data[y];\n        data[y] = x;\n\n        group_number--;\n\
    \n        return true;\n    }\n\n    // x \u304C\u5C5E\u3059\u308B\u65CF\u306B\
    \u304A\u3051\u308B\u4F4D\u6570\u3092\u6C42\u3081\u308B.\n    int size(int x) {\
    \ return -data[find(x)]; }\n\n    // x, y \u306F\u540C\u3058\u9023\u7D50\u6210\
    \u5206\u306B\u3042\u308B?\n    int same(int x, int y) { return find(x) == find(y);\
    \ }\n};\n"
  code: "#pragma once\n\nclass Union_Find{\n    private:\n    int N;\n    vector<int>\
    \ data;\n    int group_number;\n\n    public:\n    Union_Find(int N) : N(N), data(N,\
    \ -1), group_number(N) {}\n\n    // x \u304C\u5C5E\u3059\u308B\u65CF\u306E\u4EE3\
    \u8868\u5143\u3092\u6C42\u3081\u308B.\n    int find(int x) { return data[x] <\
    \ 0 ? x: data[x] = find(data[x]); }\n\n    // x \u3068 y \u3092\u7D50\u5408\u3059\
    \u308B.\n    // \u8FD4\u308A\u5024: \u5143\u3005\u975E\u9023\u7D50\u306A\u3089\
    \u3070 true, \u9023\u7D50\u306A\u3089\u3070 false\n    bool unite(int x, int y)\
    \ {\n        x = find(x);\n        y = find(y);\n\n        if (x == y) { return\
    \ false; }\n\n        if (data[x] > data[y]) { swap(x, y); }\n\n        data[x]\
    \ += data[y];\n        data[y] = x;\n\n        group_number--;\n\n        return\
    \ true;\n    }\n\n    // x \u304C\u5C5E\u3059\u308B\u65CF\u306B\u304A\u3051\u308B\
    \u4F4D\u6570\u3092\u6C42\u3081\u308B.\n    int size(int x) { return -data[find(x)];\
    \ }\n\n    // x, y \u306F\u540C\u3058\u9023\u7D50\u6210\u5206\u306B\u3042\u308B\
    ?\n    int same(int x, int y) { return find(x) == find(y); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Union_Find/Union_Find.hpp
  requiredBy: []
  timestamp: '2025-08-16 19:50:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Union_Find.test.cpp
documentation_of: Union_Find/Union_Find.hpp
layout: document
redirect_from:
- /library/Union_Find/Union_Find.hpp
- /library/Union_Find/Union_Find.hpp.html
title: Union_Find/Union_Find.hpp
---
