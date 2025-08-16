---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \u671F\u5316\n    public:\n    Binary_Indexed_Tree(int n, const function<G(G,\
    \ G)> op, const G zero, const function<G(G)> neg): n(n), op(op), zero(zero), neg(neg)\
    \ {\n        data.assign(n + 1, zero);\n    }\n\n    Binary_Indexed_Tree(const\
    \ vector<G> &vec, const function<G(G, G)> op, const G zero, const function<G(G)>\
    \ neg):\n        Binary_Indexed_Tree(vec.size(), op, zero, neg) {\n          \
    \  for (int k = 1; k <= n; k++){\n                data[k] = op(data[k], vec[k\
    \ - 1]);\n                int l = k + (k & (-k));\n                if (l <= n)\
    \ { data[l] = op(data[l], data[k]); }\n            }\n        }\n\n    // \u7B2C\
    \ k \u8981\u7D20\u306B x \u3092\u5DE6\u304B\u3089\u52A0\u3048\u308B.\n    void\
    \ add(int k, G x) {\n        for (++k; k <= n; k += k & (-k)) { data[k] = op(data[k],\
    \ x); }\n    }\n\n    // \u7B2C k \u8981\u7D20\u3092 x \u306B\u5909\u66F4\u3059\
    \u308B.\n    void update(int k, G x) {\n        add(k, op(neg((*this)[k]), x));\n\
    \    }\n\n    // \u53F3\u534A\u958B\u533A\u9593 [0, k] \u306B\u304A\u3051\u308B\
    \u7DCF\u548C\u3092\u6C42\u3081\u308B.\n    G sum(int k) const {\n        G total\
    \ = zero;\n\n        for (++k; k > 0; k -= k & (-k)) { total = op(total, data[k]);\
    \ }\n\n        return total;\n    }\n\n    // \u53F3\u534A\u958B\u533A\u9593 [l,\
    \ r] \u306B\u304A\u3051\u308B\u7DCF\u548C\u3092\u6C42\u3081\u308B.\n    G sum(int\
    \ l, int r) const {\n        l = max(l, 0);\n        r = min(r, n - 1);\n\n  \
    \      if (l > r) { return zero; }\n        else if (l == 0) { return sum(r);\
    \ }\n        else { return op(sum(r), neg(sum(l - 1))); }\n    }\n\n    // \u7B2C\
    \ k \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B.\n    inline G operator[](int k)\
    \ const { return sum(k, k + 1); }\n};\n\ntemplate<typename G>\nBinary_Indexed_Tree<G>\
    \ Group_Binary_Indexed_Tree(const vector<G> &vec, G zero){\n    auto add = [](G\
    \ x, G y) -> G { return x + y; };\n    auto inv = [](G x) -> G { return -x; };\n\
    \    return Binary_Indexed_Tree<G>(vec, add, zero, inv);\n}\n"
  code: "#pragma once\n\ntemplate<typename G>\nclass Binary_Indexed_Tree{\n    private:\n\
    \    int n;\n    vector<G> data;\n    G zero;\n    function<G(G, G)> op;\n   \
    \ function<G(G)> neg;\n\n    // \u521D\u671F\u5316\n    public:\n    Binary_Indexed_Tree(int\
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
    \u3059\u308B.\n    inline G operator[](int k) const { return sum(k, k + 1); }\n\
    };\n\ntemplate<typename G>\nBinary_Indexed_Tree<G> Group_Binary_Indexed_Tree(const\
    \ vector<G> &vec, G zero){\n    auto add = [](G x, G y) -> G { return x + y; };\n\
    \    auto inv = [](G x) -> G { return -x; };\n    return Binary_Indexed_Tree<G>(vec,\
    \ add, zero, inv);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Binary_Indexed_Tree/Binary_Indexed_Tree.hpp
  requiredBy: []
  timestamp: '2025-08-16 23:42:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Binary_Indexed_Tree.test.cpp
documentation_of: Binary_Indexed_Tree/Binary_Indexed_Tree.hpp
layout: document
redirect_from:
- /library/Binary_Indexed_Tree/Binary_Indexed_Tree.hpp
- /library/Binary_Indexed_Tree/Binary_Indexed_Tree.hpp.html
title: Binary_Indexed_Tree/Binary_Indexed_Tree.hpp
---
