---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Segment_Tree/Segment_Tree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Segment_Tree_2.test.cpp
    title: verify/yosupo_library_checker/data_structure/Segment_Tree_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Segment_Tree/preset/Range_Min.hpp\"\n\n#line 2 \"Segment_Tree/Segment_Tree.hpp\"\
    \n\ntemplate<typename M>\nclass Segment_Tree{\n    private:\n    int n;\n    vector<M>\
    \ data;\n    const function<M(M, M)> op;\n    const M unit;\n\n    public:\n \
    \   Segment_Tree(int size, const function<M(M, M)> op, const M unit): n(), op(op),\
    \ unit(unit) {\n        int m = 1;\n        while (m < size) { m *= 2; }\n\n \
    \       n = m;\n        data.assign(2 * n, unit);\n    }\n\n    Segment_Tree(const\
    \ vector<M> &vec, const function<M(M, M)> op, const M unit): \n        Segment_Tree(vec.size(),\
    \ op, unit) {\n            for (int k = 0; k < vec.size(); k++) { data[k + n]\
    \ = vec[k]; }\n            for (int k = n - 1; k > 0; k--) { recalc(k); }\n  \
    \      }\n\n    private:\n    void recalc(int k) { data[k] = op(data[k << 1],\
    \ data[k << 1 | 1]); }\n\n    public:\n    // \u7B2C k \u8981\u7D20\u3092 x \u306B\
    \u66F4\u65B0\u3059\u308B\n    void update(int k, M x) {\n        k += n;\n   \
    \     data[k] = x;\n\n        for (k >>= 1; k; k >>= 1) { recalc(k); }\n    }\n\
    \n    // \u7B2C k \u8981\u7D20\u3092\u53D6\u5F97\u3059\u308B\n    M get(int k)\
    \ { return data[k + n]; }\n\n    M operator[](int k) { return get(k); }\n\n  \
    \  // \u7B2C l \u8981\u7D20\u304B\u3089\u7B2C r \u8981\u7D20\u307E\u3067\u306E\
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
    \    }\n};\n#line 4 \"Segment_Tree/preset/Range_Min.hpp\"\n\ntemplate<typename\
    \ T>\nclass Range_Min_Segment_Tree : public Segment_Tree<T> {\n    static T op(T\
    \ x, T y) { return x < y ? x : y; }\n\n    public:\n    Range_Min_Segment_Tree(int\
    \ n, T unit) : Segment_Tree<T>(n, op, unit) {}\n\n    Range_Min_Segment_Tree(const\
    \ vector<T> &vec, T unit) : Segment_Tree<T>(vec, op, unit) {}\n\n    void update(int\
    \ k, T x) { Segment_Tree<T>::update(k, x); }\n\n    // \u7B2C k \u8981\u7D20\u3092\
    \u53D6\u5F97\u3059\u308B\n    T get(int k) { return Segment_Tree<T>::get(k); }\n\
    \n    T operator[](int k) { return get(k); }\n\n    // \u533A\u9593 [l, r] \u306E\
    \u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\n    T min(int l, int r) { return this->product(l,\
    \ r); }\n};\n"
  code: "#pragma once\n\n#include \"../Segment_Tree.hpp\"\n\ntemplate<typename T>\n\
    class Range_Min_Segment_Tree : public Segment_Tree<T> {\n    static T op(T x,\
    \ T y) { return x < y ? x : y; }\n\n    public:\n    Range_Min_Segment_Tree(int\
    \ n, T unit) : Segment_Tree<T>(n, op, unit) {}\n\n    Range_Min_Segment_Tree(const\
    \ vector<T> &vec, T unit) : Segment_Tree<T>(vec, op, unit) {}\n\n    void update(int\
    \ k, T x) { Segment_Tree<T>::update(k, x); }\n\n    // \u7B2C k \u8981\u7D20\u3092\
    \u53D6\u5F97\u3059\u308B\n    T get(int k) { return Segment_Tree<T>::get(k); }\n\
    \n    T operator[](int k) { return get(k); }\n\n    // \u533A\u9593 [l, r] \u306E\
    \u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\n    T min(int l, int r) { return this->product(l,\
    \ r); }\n};\n"
  dependsOn:
  - Segment_Tree/Segment_Tree.hpp
  isVerificationFile: false
  path: Segment_Tree/preset/Range_Min.hpp
  requiredBy: []
  timestamp: '2026-09-20 00:02:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Segment_Tree_2.test.cpp
documentation_of: Segment_Tree/preset/Range_Min.hpp
layout: document
redirect_from:
- /library/Segment_Tree/preset/Range_Min.hpp
- /library/Segment_Tree/preset/Range_Min.hpp.html
title: Segment_Tree/preset/Range_Min.hpp
---
