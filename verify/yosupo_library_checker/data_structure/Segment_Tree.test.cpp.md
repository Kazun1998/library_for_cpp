---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Segment_Tree/Segment_Tree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/yosupo_library_checker/data_structure/Segment_Tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include<bits/stdc++.h>\n\
    \nusing namespace std;\n\n#line 2 \"Segment_Tree/Segment_Tree.hpp\"\n\ntemplate<typename\
    \ M>\nclass Segment_Tree{\n    private:\n    int n;\n    vector<M> data;\n   \
    \ const function<M(M, M)> op;\n    const M unit;\n\n    public:\n    Segment_Tree(int\
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
    \ >>= 1;\n        }\n\n        return op(vl, vr);\n    }\n};\n#line 8 \"verify/yosupo_library_checker/data_structure/Segment_Tree.test.cpp\"\
    \n\nint main(){\n    int N, Q; cin >> N >> Q;\n    vector<int> a(N);\n    for\
    \ (int i = 0; i < N; i++) { cin >> a[i]; }\n\n    auto op = [](int x, int y) ->\
    \ int { return min(x, y); };\n    int unit = numeric_limits<int>::max();\n\n \
    \   Segment_Tree<int> S(a, op, unit);\n\n    for (; Q; Q--) {\n        int l,\
    \ r;\n        scanf(\"%d%d\", &l, &r);\n        cout << S.product(l, r - 1) <<\
    \ \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include<bits/stdc++.h>\n\
    \nusing namespace std;\n\n#include\"../../../Segment_Tree/Segment_Tree.hpp\"\n\
    \nint main(){\n    int N, Q; cin >> N >> Q;\n    vector<int> a(N);\n    for (int\
    \ i = 0; i < N; i++) { cin >> a[i]; }\n\n    auto op = [](int x, int y) -> int\
    \ { return min(x, y); };\n    int unit = numeric_limits<int>::max();\n\n    Segment_Tree<int>\
    \ S(a, op, unit);\n\n    for (; Q; Q--) {\n        int l, r;\n        scanf(\"\
    %d%d\", &l, &r);\n        cout << S.product(l, r - 1) << \"\\n\";\n    }\n}\n"
  dependsOn:
  - Segment_Tree/Segment_Tree.hpp
  isVerificationFile: true
  path: verify/yosupo_library_checker/data_structure/Segment_Tree.test.cpp
  requiredBy: []
  timestamp: '2025-10-30 00:10:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo_library_checker/data_structure/Segment_Tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo_library_checker/data_structure/Segment_Tree.test.cpp
- /verify/verify/yosupo_library_checker/data_structure/Segment_Tree.test.cpp.html
title: verify/yosupo_library_checker/data_structure/Segment_Tree.test.cpp
---
