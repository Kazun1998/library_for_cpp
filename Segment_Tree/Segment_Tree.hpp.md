---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Segment_Tree/Segment_Tree.hpp\"\n\ntemplate<typename M>\n\
    class Segment_Tree{\n    private:\n    int n;\n    vector<M> data;\n    const\
    \ function<M(M, M)> op;\n    const M unit;\n\n    public:\n    Segment_Tree(int\
    \ size, const function<M(M, M)> op, const M unit): n(), op(op), unit(unit) {\n\
    \        int m = 1;\n        while (m < size) { m *= 2; }\n\n        n = m;\n\
    \        data.assign(2 * n, unit);\n    }\n\n    Segment_Tree(const vector<M>\
    \ &vec, const function<M(M, M)> op, const M unit): \n        Segment_Tree(vec.size(),\
    \ op, unit) {\n            for (int k = 0; k < n; k++) { data[k + n] = vec[k];\
    \ }\n            for (int k = n - 1; k > 0; k--) { recalc(k); }\n        }\n\n\
    \    private:\n    void recalc(int k) { data[k] = op(data[k << 1], data[k << 1\
    \ | 1]); }\n\n    public:\n    // \u7B2C k \u8981\u7D20\u3092 x \u306B\u66F4\u65B0\
    \u3059\u308B\n    void update(int k, M x) {\n        k += n;\n        data[k]\
    \ = x;\n\n        for (k >>= 1; k; k >>= 1) { recalc(k); }\n    }\n\n    // \u7B2C\
    \ l \u8981\u7D20\u304B\u3089\u7B2C r \u8981\u7D20\u307E\u3067\u306E\u7DCF\u7A4D\
    \u3092\u6C42\u3081\u308B\n    M product(int l, int r){\n        l += n; r += n\
    \ + 1;\n        M vl = unit, vr = unit;\n        while (l < r){\n            if\
    \ (l & 1){\n                vl = op(vl, data[l]);\n                l++;\n    \
    \        }\n\n            if (r & 1){\n                r--;\n                vr\
    \ = op(data[r], vr);\n            }\n\n            l >>= 1; r >>= 1;\n       \
    \ }\n\n        return op(vl, vr);\n    }\n};\n"
  code: "#pragma once\n\ntemplate<typename M>\nclass Segment_Tree{\n    private:\n\
    \    int n;\n    vector<M> data;\n    const function<M(M, M)> op;\n    const M\
    \ unit;\n\n    public:\n    Segment_Tree(int size, const function<M(M, M)> op,\
    \ const M unit): n(), op(op), unit(unit) {\n        int m = 1;\n        while\
    \ (m < size) { m *= 2; }\n\n        n = m;\n        data.assign(2 * n, unit);\n\
    \    }\n\n    Segment_Tree(const vector<M> &vec, const function<M(M, M)> op, const\
    \ M unit): \n        Segment_Tree(vec.size(), op, unit) {\n            for (int\
    \ k = 0; k < n; k++) { data[k + n] = vec[k]; }\n            for (int k = n - 1;\
    \ k > 0; k--) { recalc(k); }\n        }\n\n    private:\n    void recalc(int k)\
    \ { data[k] = op(data[k << 1], data[k << 1 | 1]); }\n\n    public:\n    // \u7B2C\
    \ k \u8981\u7D20\u3092 x \u306B\u66F4\u65B0\u3059\u308B\n    void update(int k,\
    \ M x) {\n        k += n;\n        data[k] = x;\n\n        for (k >>= 1; k; k\
    \ >>= 1) { recalc(k); }\n    }\n\n    // \u7B2C l \u8981\u7D20\u304B\u3089\u7B2C\
    \ r \u8981\u7D20\u307E\u3067\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\u308B\n    M\
    \ product(int l, int r){\n        l += n; r += n + 1;\n        M vl = unit, vr\
    \ = unit;\n        while (l < r){\n            if (l & 1){\n                vl\
    \ = op(vl, data[l]);\n                l++;\n            }\n\n            if (r\
    \ & 1){\n                r--;\n                vr = op(data[r], vr);\n       \
    \     }\n\n            l >>= 1; r >>= 1;\n        }\n\n        return op(vl, vr);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Segment_Tree/Segment_Tree.hpp
  requiredBy: []
  timestamp: '2025-08-16 19:37:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Segment_Tree/Segment_Tree.hpp
layout: document
redirect_from:
- /library/Segment_Tree/Segment_Tree.hpp
- /library/Segment_Tree/Segment_Tree.hpp.html
title: Segment_Tree/Segment_Tree.hpp
---
