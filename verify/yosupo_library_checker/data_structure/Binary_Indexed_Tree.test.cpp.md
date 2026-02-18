---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Binary_Indexed_Tree/Binary_Indexed_Tree.hpp
    title: Binary Indexed Tree (Fenwick Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/yosupo_library_checker/data_structure/Binary_Indexed_Tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include<bits/stdc++.h>\n\nusing namespace std;\n\n#line 2 \"Binary_Indexed_Tree/Binary_Indexed_Tree.hpp\"\
    \n\ntemplate<typename G>\nclass Binary_Indexed_Tree{\n    private:\n    int n;\n\
    \    vector<G> data;\n    G zero;\n    function<G(G, G)> op;\n    function<G(G)>\
    \ neg;\n\n    // \u521D\u671F\u5316\n    public:\n    Binary_Indexed_Tree() =\
    \ default;\n\n    Binary_Indexed_Tree(int n, const function<G(G, G)> op, const\
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
    \    return Binary_Indexed_Tree<G>(vec, add, zero, inv);\n}\n#line 8 \"verify/yosupo_library_checker/data_structure/Binary_Indexed_Tree.test.cpp\"\
    \n\nint main() {\n    int N, Q; cin >> N >> Q;\n    vector<long long> a(N);\n\
    \    for (int i = 0; i < N; i ++) { scanf(\"%lld\", &a[i]); }\n\n    Binary_Indexed_Tree<long\
    \ long> B = Group_Binary_Indexed_Tree(a, 0LL);\n    for (; Q > 0; Q--) {\n   \
    \     int t; scanf(\"%d\", &t);\n        if (t == 0) {\n            int p, x;\
    \ scanf(\"%d%d\", &p, &x);\n            B.add(p, x);\n        } else {\n     \
    \       int l, r; scanf(\"%d%d\", &l, &r);\n            cout << B.sum(l, r - 1)\
    \ << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include<bits/stdc++.h>\n\nusing namespace std;\n\n#include\"../../../Binary_Indexed_Tree/Binary_Indexed_Tree.hpp\"\
    \n\nint main() {\n    int N, Q; cin >> N >> Q;\n    vector<long long> a(N);\n\
    \    for (int i = 0; i < N; i ++) { scanf(\"%lld\", &a[i]); }\n\n    Binary_Indexed_Tree<long\
    \ long> B = Group_Binary_Indexed_Tree(a, 0LL);\n    for (; Q > 0; Q--) {\n   \
    \     int t; scanf(\"%d\", &t);\n        if (t == 0) {\n            int p, x;\
    \ scanf(\"%d%d\", &p, &x);\n            B.add(p, x);\n        } else {\n     \
    \       int l, r; scanf(\"%d%d\", &l, &r);\n            cout << B.sum(l, r - 1)\
    \ << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - Binary_Indexed_Tree/Binary_Indexed_Tree.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/data_structure/Binary_Indexed_Tree.test.cpp
  requiredBy: []
  timestamp: '2025-11-18 00:49:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/data_structure/Binary_Indexed_Tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/data_structure/Binary_Indexed_Tree.test.cpp
- /verify/verify/yosupo_library_checker/data_structure/Binary_Indexed_Tree.test.cpp.html
title: verify/yosupo_library_checker/data_structure/Binary_Indexed_Tree.test.cpp
---
