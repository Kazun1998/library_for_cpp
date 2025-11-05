---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.test.cpp
    title: verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC\u306E\u7B2C\
      \ m \u8981\u7D20\u3092\u66F4\u65B0\u3057, \u9045\u5EF6\u3057\u3066\u3044\u305F\
      \u4F5C\u7528\u3092\u5B50\u306B\u4F1D\u642C\u3055\u305B\u308B."
    links: []
  bundledCode: "#line 2 \"Segment_Tree/Lazy_Segment_Tree.hpp\"\n\n/* \u9045\u5EF6\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\nM \u3092 Monoid \u3068\u3059\u308B. M \u4E0A\u306E\
    \u5217\u306B\u5BFE\u3057\u3066, Monid F \u304B\u3089\u306E\u533A\u9593\u4F5C\u7528\
    \u3068, \u9023\u7D9A\u90E8\u5206\u5217\u306B\u5BFE\u3059\u308B\u533A\u9593\u7A4D\
    \u306E\u8A08\u7B97\u306E\u51E6\u7406\u3092\u9AD8\u901F\u306B\u884C\u3046.\n\n\
    * M: Monoid\n* F: Monoid\n* op: M x M \u2192 M: M \u4E0A\u306E\u6F14\u7B97\n*\
    \ unit: M \u306E\u5358\u4F4D\u5143\n* act: F x M \u2192 M: F \u304B\u3089\u306E\
    \ M \u306E\u6F14\u7B97\n* comp: F x F \u2192 F: F \u540C\u58EB\u306E\u5408\u6210\
    \ (\u5DE6\u306E\u8981\u7D20\u304C\u65B0\u3057\u3044)\n* id: F \u306E\u5358\u4F4D\
    \u5143\n\n(\u6761\u4EF6)\nM: Monoid, F = {f: F x M \u2192 M: \u4F5C\u7528\u7D20\
    } \u306B\u5BFE\u3057\u3066, \u4EE5\u4E0B\u304C\u6210\u7ACB\u3059\u308B.\n* F \u306F\
    \u5199\u50CF\u306E\u5408\u6210\u306B\u9589\u3058\u3066\u3044\u308B. \u3064\u307E\
    \u308A, \u4EFB\u610F\u306E f,g in F \u306B\u5BFE\u3057\u3066, comp(f,g) in F\n\
    * F \u306F M \u306B\u4F5C\u7528\u3059\u308B. \u3064\u307E\u308A, \u4EE5\u4E0B\u304C\
    \u6210\u308A\u7ACB\u3064.\n    * F \u306E\u5358\u4F4D\u5143 id \u306F\u6052\u7B49\
    \u7684\u306B\u4F5C\u7528\u3059\u308B. \u3064\u307E\u308A, \u4EFB\u610F\u306E x\
    \ in M \u306B\u5BFE\u3057\u3066 id(x) = x \u3068\u306A\u308B.\n    * \u4EFB\u610F\
    \u306E f in F, x,y in M \u306B\u5BFE\u3057\u3066, f(xy) = f(x) f(y) \u3067\u3042\
    \u308B.\n\n\n(\u6CE8\u610F)\n\u4F5C\u7528\u7D20\u306F\u5DE6\u304B\u3089\u639B\u3051\
    \u308B. \u66F4\u65B0\u3082\u5DE6\u304B\u3089\u884C\u3046.\n*/\n\ntemplate<typename\
    \ M, typename F>\nclass Lazy_Segment_Tree {\n    public:\n    int n, depth;\n\
    \    const function<M(M, M)> op;\n    const function<M(F, M)> act;\n    const\
    \ function<F(F, F)> comp;\n    vector<M> data; const M unit;\n    vector<F> lazy;\
    \ const F id;\n\n    public:\n    Lazy_Segment_Tree(int size, const function<M(M,\
    \ M)> op, const M unit, const function<M(F, M)> act, const function<F(F, F)> comp,\
    \ const F id):\n        n(), op(op), unit(unit), act(act), comp(comp), id(id),\
    \ depth(0) {\n            int m = 1;\n            while (size > m) { depth++,\
    \ m *= 2; }\n            n = m;\n            data.assign(2 * m, unit);\n     \
    \       lazy.assign(2 * m, id);\n        }\n\n    Lazy_Segment_Tree(const vector<M>\
    \ &vec, const function<M(M, M)> op, const M unit, const function<M(F, M)> act,\
    \ const function<F(F, F)> comp, const F id):\n        Lazy_Segment_Tree(vec.size(),\
    \ op, unit, act, comp, id){\n            for (int k = 0; k < vec.size(); k++)\
    \ { data[k+n] = vec[k]; }\n            for (int k = n - 1; k > 0; k--) { data[k]\
    \ = op(data[k << 1], data[k << 1 | 1]); }\n        }\n\n    private:\n    inline\
    \ M evaluate_at(int m){ return lazy[m] == id ? data[m] : act(lazy[m], data[m]);\
    \ }\n\n    /// @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC\u306E\u7B2C\
    \ m \u8981\u7D20\u3092\u66F4\u65B0\u3057, \u9045\u5EF6\u3057\u3066\u3044\u305F\
    \u4F5C\u7528\u3092\u5B50\u306B\u4F1D\u642C\u3055\u305B\u308B.\n    /// @param\
    \ m \n    void push(int m){\n        data[m] = evaluate_at(m);\n\n        if ((m\
    \ < n) && (lazy[m] != id)){\n            int left = m << 1;\n            lazy[left]\
    \ = (lazy[left] == id) ? lazy[m] : comp(lazy[m], lazy[left]);\n\n            int\
    \ right = m << 1 | 1;\n            lazy[right] = (lazy[right] == id) ? lazy[m]\
    \ : comp(lazy[m], lazy[right]); \n        }\n\n        lazy[m] = id;\n    }\n\n\
    \    /// @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC\u306E\u7B2C m\
    \ \u8981\u7D20\u3092\u542B\u3080\u533A\u9593\u306B\u3064\u3044\u3066\u306E lazy\
    \ \u306E\u8981\u7D20\u306B\u3064\u3044\u3066, \u5B50\u3078\u306E\u66F4\u65B0\u3092\
    \u884C\u3046.\n    /// @param m \n    inline void propagate_above(int m){\n  \
    \      int h = 0, mm = m;\n        for (mm; mm; mm >>= 1, h++){}\n\n        for\
    \ (h--; h >= 0; h--) { push(m >> h); }\n    }\n\n    /// @brief \u30BB\u30B0\u30E1\
    \u30F3\u30C8\u30C4\u30EA\u30FC\u306E\u7B2C m \u8981\u7D20\u3092\u542B\u3080\u533A\
    \u9593\u306B\u3064\u3044\u3066\u306E data \u306E\u8981\u7D20\u3092\u66F4\u65B0\
    \u3059\u308B.\n    /// @param m \n    inline void recalc_above(int m){\n     \
    \   while (m > 1){\n            m >>= 1;\n            data[m] = op(evaluate_at(m\
    \ << 1), evaluate_at(m << 1 | 1));\n        }\n    }\n\n    pair<int, int> range_propagate(int\
    \ l, int r){\n        int X = l + n, Y = r + n - 1, L0 = -1, R0 = -1;\n    \n\
    \        while (X < Y){\n            if (X & 1) { L0 = max(L0, X++); }\n     \
    \       if ((Y & 1) ==0 ) { R0 = max(R0, Y--); }\n\n            X >>= 1; Y >>=\
    \ 1;\n        }\n\n        L0 = max(L0, X); R0 = max(R0, Y);\n        propagate_above(L0);\
    \ propagate_above(R0);\n        return make_pair(L0, R0);\n    }\n\n    public:\n\
    \    /// @brief \u7B2C k \u9805\u3092\u53D6\u5F97\u3059\u308B.\n    /// @param\
    \ k \n    /// @return \u7B2C k \u9805\n    inline M operator[](int k){\n     \
    \   int m = k + n;\n        propagate_above(m);\n        lazy[m] = id;\n     \
    \   return data[m] = evaluate_at(m);\n    }\n\n    /// @brief i = l, l + 1, ...,\
    \ r \u306B\u5BFE\u3057\u3066, \u7B2C i \u9805\u306B\u5BFE\u3057\u3066 alpha \u3092\
    \u4F5C\u7528\u3055\u305B\u308B.\n    /// @param l \u533A\u9593\u306E\u5DE6\u7AEF\
    \n    /// @param r \u533A\u9593\u306E\u53F3\u7AEF\n    /// @param alpha \u4F5C\
    \u7528\n    void action(int l, int r, F alpha){\n        int L0, R0;\n       \
    \ tie(L0, R0) = range_propagate(l, r + 1);\n\n        int L = l + n, R = r + n\
    \ + 1;\n        while (L < R){\n            if (L & 1){\n                lazy[L]\
    \ = (alpha == id) ? id : comp(alpha, lazy[L]); \n                L++;\n      \
    \      }\n\n            if (R & 1){\n                R--;\n                lazy[R]\
    \ = (alpha == id) ? id : comp(alpha, lazy[R]);\n            }\n\n            L\
    \ >>= 1; R >>= 1;\n        }\n\n        recalc_above(L0); recalc_above(R0);\n\
    \    }\n\n    /// @brief \u7B2C k \u9805\u3092 x \u306B\u66F4\u65B0\u3059\u308B\
    .\n    /// @param k \u66F4\u65B0\u5834\u6240\n    /// @param x \u66F4\u65B0\u5F8C\
    \u306E\u8981\u7D20\n    inline void update(int k, M x){\n        int m = k + n;\n\
    \        propagate_above(m);\n        data[m] = x; lazy[m] = id;\n        recalc_above(m);\n\
    \    }\n\n\n    /// @brief \u7A4D x[l] * x[l + 1] * ... * x[r] \u3092\u6C42\u3081\
    \u308B.\n    /// @param l \u533A\u9593\u306E\u5DE6\u7AEF\n    /// @param r \u533A\
    \u9593\u306E\u53F3\u7AEF\n    /// @return \u7A4D\n    M product(int l, int r){\n\
    \        int L0, R0;\n        tie(L0, R0) = range_propagate(l, r + 1);\n\n   \
    \     int L = l + n, R = r + n + 1;\n        M vL = unit, vR = unit;\n       \
    \ while (L < R){\n            if (L & 1) { vL = op(vL, evaluate_at(L)); L++; }\n\
    \            if (R & 1) { R--; vR=op(evaluate_at(R), vR); }\n\n            L >>=\
    \ 1; R >>= 1;\n        }\n\n        return op(vL, vR);\n    }\n\n    /// @brief\
    \ \u5168\u8981\u7D20\u306B\u304A\u3051\u308B\u533A\u9593\u7A4D\u3092\u6C42\u3081\
    \u308B.\n    /// @return \u6B8B\u8981\u7D20\u306B\u304A\u3051\u308B\u533A\u9593\
    \u7A4D\n    inline M all_product() {return product(0, n);}\n\n    void refresh()\
    \ {\n        for (int m = 1; m < 2 * n; m++){\n            data[m] = evaluate_at(m);\n\
    \            if ((m < n) && (lazy[m] != id)){\n                int left = m <<\
    \ 1;\n                lazy[left] = (lazy[left] == id) ? lazy[m] : comp(lazy[m],\
    \ lazy[left]);\n\n                int right = m << 1 | 1;\n                lazy[right]\
    \ = (lazy[right] == id) ? lazy[m] : comp(lazy[m], lazy[m << 1 | 1]);\n       \
    \     }\n            lazy[m] = id;\n        }\n    }\n};\n"
  code: "#pragma once\n\n/* \u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\nM \u3092\
    \ Monoid \u3068\u3059\u308B. M \u4E0A\u306E\u5217\u306B\u5BFE\u3057\u3066, Monid\
    \ F \u304B\u3089\u306E\u533A\u9593\u4F5C\u7528\u3068, \u9023\u7D9A\u90E8\u5206\
    \u5217\u306B\u5BFE\u3059\u308B\u533A\u9593\u7A4D\u306E\u8A08\u7B97\u306E\u51E6\
    \u7406\u3092\u9AD8\u901F\u306B\u884C\u3046.\n\n* M: Monoid\n* F: Monoid\n* op:\
    \ M x M \u2192 M: M \u4E0A\u306E\u6F14\u7B97\n* unit: M \u306E\u5358\u4F4D\u5143\
    \n* act: F x M \u2192 M: F \u304B\u3089\u306E M \u306E\u6F14\u7B97\n* comp: F\
    \ x F \u2192 F: F \u540C\u58EB\u306E\u5408\u6210 (\u5DE6\u306E\u8981\u7D20\u304C\
    \u65B0\u3057\u3044)\n* id: F \u306E\u5358\u4F4D\u5143\n\n(\u6761\u4EF6)\nM: Monoid,\
    \ F = {f: F x M \u2192 M: \u4F5C\u7528\u7D20} \u306B\u5BFE\u3057\u3066, \u4EE5\
    \u4E0B\u304C\u6210\u7ACB\u3059\u308B.\n* F \u306F\u5199\u50CF\u306E\u5408\u6210\
    \u306B\u9589\u3058\u3066\u3044\u308B. \u3064\u307E\u308A, \u4EFB\u610F\u306E f,g\
    \ in F \u306B\u5BFE\u3057\u3066, comp(f,g) in F\n* F \u306F M \u306B\u4F5C\u7528\
    \u3059\u308B. \u3064\u307E\u308A, \u4EE5\u4E0B\u304C\u6210\u308A\u7ACB\u3064.\n\
    \    * F \u306E\u5358\u4F4D\u5143 id \u306F\u6052\u7B49\u7684\u306B\u4F5C\u7528\
    \u3059\u308B. \u3064\u307E\u308A, \u4EFB\u610F\u306E x in M \u306B\u5BFE\u3057\
    \u3066 id(x) = x \u3068\u306A\u308B.\n    * \u4EFB\u610F\u306E f in F, x,y in\
    \ M \u306B\u5BFE\u3057\u3066, f(xy) = f(x) f(y) \u3067\u3042\u308B.\n\n\n(\u6CE8\
    \u610F)\n\u4F5C\u7528\u7D20\u306F\u5DE6\u304B\u3089\u639B\u3051\u308B. \u66F4\u65B0\
    \u3082\u5DE6\u304B\u3089\u884C\u3046.\n*/\n\ntemplate<typename M, typename F>\n\
    class Lazy_Segment_Tree {\n    public:\n    int n, depth;\n    const function<M(M,\
    \ M)> op;\n    const function<M(F, M)> act;\n    const function<F(F, F)> comp;\n\
    \    vector<M> data; const M unit;\n    vector<F> lazy; const F id;\n\n    public:\n\
    \    Lazy_Segment_Tree(int size, const function<M(M, M)> op, const M unit, const\
    \ function<M(F, M)> act, const function<F(F, F)> comp, const F id):\n        n(),\
    \ op(op), unit(unit), act(act), comp(comp), id(id), depth(0) {\n            int\
    \ m = 1;\n            while (size > m) { depth++, m *= 2; }\n            n = m;\n\
    \            data.assign(2 * m, unit);\n            lazy.assign(2 * m, id);\n\
    \        }\n\n    Lazy_Segment_Tree(const vector<M> &vec, const function<M(M,\
    \ M)> op, const M unit, const function<M(F, M)> act, const function<F(F, F)> comp,\
    \ const F id):\n        Lazy_Segment_Tree(vec.size(), op, unit, act, comp, id){\n\
    \            for (int k = 0; k < vec.size(); k++) { data[k+n] = vec[k]; }\n  \
    \          for (int k = n - 1; k > 0; k--) { data[k] = op(data[k << 1], data[k\
    \ << 1 | 1]); }\n        }\n\n    private:\n    inline M evaluate_at(int m){ return\
    \ lazy[m] == id ? data[m] : act(lazy[m], data[m]); }\n\n    /// @brief \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u30C4\u30EA\u30FC\u306E\u7B2C m \u8981\u7D20\u3092\u66F4\u65B0\
    \u3057, \u9045\u5EF6\u3057\u3066\u3044\u305F\u4F5C\u7528\u3092\u5B50\u306B\u4F1D\
    \u642C\u3055\u305B\u308B.\n    /// @param m \n    void push(int m){\n        data[m]\
    \ = evaluate_at(m);\n\n        if ((m < n) && (lazy[m] != id)){\n            int\
    \ left = m << 1;\n            lazy[left] = (lazy[left] == id) ? lazy[m] : comp(lazy[m],\
    \ lazy[left]);\n\n            int right = m << 1 | 1;\n            lazy[right]\
    \ = (lazy[right] == id) ? lazy[m] : comp(lazy[m], lazy[right]); \n        }\n\n\
    \        lazy[m] = id;\n    }\n\n    /// @brief \u30BB\u30B0\u30E1\u30F3\u30C8\
    \u30C4\u30EA\u30FC\u306E\u7B2C m \u8981\u7D20\u3092\u542B\u3080\u533A\u9593\u306B\
    \u3064\u3044\u3066\u306E lazy \u306E\u8981\u7D20\u306B\u3064\u3044\u3066, \u5B50\
    \u3078\u306E\u66F4\u65B0\u3092\u884C\u3046.\n    /// @param m \n    inline void\
    \ propagate_above(int m){\n        int h = 0, mm = m;\n        for (mm; mm; mm\
    \ >>= 1, h++){}\n\n        for (h--; h >= 0; h--) { push(m >> h); }\n    }\n\n\
    \    /// @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u30C4\u30EA\u30FC\u306E\u7B2C m\
    \ \u8981\u7D20\u3092\u542B\u3080\u533A\u9593\u306B\u3064\u3044\u3066\u306E data\
    \ \u306E\u8981\u7D20\u3092\u66F4\u65B0\u3059\u308B.\n    /// @param m \n    inline\
    \ void recalc_above(int m){\n        while (m > 1){\n            m >>= 1;\n  \
    \          data[m] = op(evaluate_at(m << 1), evaluate_at(m << 1 | 1));\n     \
    \   }\n    }\n\n    pair<int, int> range_propagate(int l, int r){\n        int\
    \ X = l + n, Y = r + n - 1, L0 = -1, R0 = -1;\n    \n        while (X < Y){\n\
    \            if (X & 1) { L0 = max(L0, X++); }\n            if ((Y & 1) ==0 )\
    \ { R0 = max(R0, Y--); }\n\n            X >>= 1; Y >>= 1;\n        }\n\n     \
    \   L0 = max(L0, X); R0 = max(R0, Y);\n        propagate_above(L0); propagate_above(R0);\n\
    \        return make_pair(L0, R0);\n    }\n\n    public:\n    /// @brief \u7B2C\
    \ k \u9805\u3092\u53D6\u5F97\u3059\u308B.\n    /// @param k \n    /// @return\
    \ \u7B2C k \u9805\n    inline M operator[](int k){\n        int m = k + n;\n \
    \       propagate_above(m);\n        lazy[m] = id;\n        return data[m] = evaluate_at(m);\n\
    \    }\n\n    /// @brief i = l, l + 1, ..., r \u306B\u5BFE\u3057\u3066, \u7B2C\
    \ i \u9805\u306B\u5BFE\u3057\u3066 alpha \u3092\u4F5C\u7528\u3055\u305B\u308B\
    .\n    /// @param l \u533A\u9593\u306E\u5DE6\u7AEF\n    /// @param r \u533A\u9593\
    \u306E\u53F3\u7AEF\n    /// @param alpha \u4F5C\u7528\n    void action(int l,\
    \ int r, F alpha){\n        int L0, R0;\n        tie(L0, R0) = range_propagate(l,\
    \ r + 1);\n\n        int L = l + n, R = r + n + 1;\n        while (L < R){\n \
    \           if (L & 1){\n                lazy[L] = (alpha == id) ? id : comp(alpha,\
    \ lazy[L]); \n                L++;\n            }\n\n            if (R & 1){\n\
    \                R--;\n                lazy[R] = (alpha == id) ? id : comp(alpha,\
    \ lazy[R]);\n            }\n\n            L >>= 1; R >>= 1;\n        }\n\n   \
    \     recalc_above(L0); recalc_above(R0);\n    }\n\n    /// @brief \u7B2C k \u9805\
    \u3092 x \u306B\u66F4\u65B0\u3059\u308B.\n    /// @param k \u66F4\u65B0\u5834\u6240\
    \n    /// @param x \u66F4\u65B0\u5F8C\u306E\u8981\u7D20\n    inline void update(int\
    \ k, M x){\n        int m = k + n;\n        propagate_above(m);\n        data[m]\
    \ = x; lazy[m] = id;\n        recalc_above(m);\n    }\n\n\n    /// @brief \u7A4D\
    \ x[l] * x[l + 1] * ... * x[r] \u3092\u6C42\u3081\u308B.\n    /// @param l \u533A\
    \u9593\u306E\u5DE6\u7AEF\n    /// @param r \u533A\u9593\u306E\u53F3\u7AEF\n  \
    \  /// @return \u7A4D\n    M product(int l, int r){\n        int L0, R0;\n   \
    \     tie(L0, R0) = range_propagate(l, r + 1);\n\n        int L = l + n, R = r\
    \ + n + 1;\n        M vL = unit, vR = unit;\n        while (L < R){\n        \
    \    if (L & 1) { vL = op(vL, evaluate_at(L)); L++; }\n            if (R & 1)\
    \ { R--; vR=op(evaluate_at(R), vR); }\n\n            L >>= 1; R >>= 1;\n     \
    \   }\n\n        return op(vL, vR);\n    }\n\n    /// @brief \u5168\u8981\u7D20\
    \u306B\u304A\u3051\u308B\u533A\u9593\u7A4D\u3092\u6C42\u3081\u308B.\n    /// @return\
    \ \u6B8B\u8981\u7D20\u306B\u304A\u3051\u308B\u533A\u9593\u7A4D\n    inline M all_product()\
    \ {return product(0, n);}\n\n    void refresh() {\n        for (int m = 1; m <\
    \ 2 * n; m++){\n            data[m] = evaluate_at(m);\n            if ((m < n)\
    \ && (lazy[m] != id)){\n                int left = m << 1;\n                lazy[left]\
    \ = (lazy[left] == id) ? lazy[m] : comp(lazy[m], lazy[left]);\n\n            \
    \    int right = m << 1 | 1;\n                lazy[right] = (lazy[right] == id)\
    \ ? lazy[m] : comp(lazy[m], lazy[m << 1 | 1]);\n            }\n            lazy[m]\
    \ = id;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Segment_Tree/Lazy_Segment_Tree.hpp
  requiredBy: []
  timestamp: '2025-11-06 00:16:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Lazy_Segment_Tree.test.cpp
documentation_of: Segment_Tree/Lazy_Segment_Tree.hpp
layout: document
title: "\u9045\u5EF6\u8A55\u4FA1 Segment Tree"
---

## Outline

$M = (M, *, e_M), F = (F, \circ, 1_F)$ はそれぞれモノイドであり, $F$ は $M$ に左から作用するとする. この作用を $F \times M \to M; (\alpha,x) \mapsto \alpha(x)$ と書くことにする.

また, 任意の作用 $\alpha \in F$ は準同型であるとする.

つまり, この作用は以下を満たすとする.

- $\forall \alpha, \beta \in F, \forall x \in M; (\alpha \circ \beta)(x)=\alpha(\beta(x))$
- $\forall x \in M; 1_F(x)=x$
- $\forall \alpha \in F, \forall x,y \in M; \alpha(x * y)=\alpha(x) * \alpha(y)$

このような $M$ の列 $S$ に対する1点更新, $F$ の元による区間更新, $S$ の連続部分列における区間積の取得を得意とするデータ構造である.

## 注意点

$F$ における作用は左からである. $\alpha \circ \beta$ において, $\alpha$ が後から作用させる作用素になる.

## Contents

計算量において, $N$ を列の長さとする.

### Constructer

```cpp
Lazy_Segment_Tree(int size, const function<M(M, M)> op, const M unit, const function<M(F, M)> act, const function<F(F, F)> comp, const F id)
```

* 長さが `size` で各項が $e_M$ である列で初期化する.
* 引数
  * $\operatorname{op}: M \times M \to M; (x, y) \mapsto x * y$ : $M$ 上の二項演算.
  * $\mathrm{unit}$ : $M$ の単位元 $e_M$.
  * $\operatorname{act}: F \times M \to M; (\alpha, x) \mapsto \alpha(x)$: $F$ による $M$ への作用.
  * $\operatorname{comp}: F \times F \to M; (\alpha, \beta) \mapsto \alpha(x)$: $F$ における合成.
  * $\mathrm{id}$: $F$ の単位元.
* **計算量** : $O(N \log N)$ Time.

```cpp
Lazy_Segment_Tree(const vector<M> &vec, const function<M(M, M)> op, const M unit, const function<M(F, M)> act, const function<F(F, F)> comp, const F id)
```

* `vec` で初期化する.
* 引数
  * $\operatorname{op}: M \times M \to M; (x, y) \mapsto x * y$ : $M$ 上の二項演算.
  * $\mathrm{unit}$ : $M$ の単位元 $e_M$.
  * $\operatorname{act}: F \times M \to M; (\alpha, x) \mapsto \alpha(x)$: $F$ による $M$ への作用.
  * $\operatorname{comp}: F \times F \to M; (\alpha, \beta) \mapsto \alpha(x)$: $F$ における合成.
  * $\mathrm{id}$: $F$ の単位元.
  * **計算量** : $O(N \log N)$ Time.

### subscript operator
```cpp
M operator[](int k)
```

* $S_k$ を求める.
* **制約**
  * $0 \leq k \lt N$.
* **計算量** : $O(\log N)$ Time.

### action

```cpp
void action(int l, int r, F alpha)
```

- 第 $l$ 要素から第 $r$ 要素 $S_l, S_{l+1}, \dots, S_r$ に $\alpha \in F$ を作用させる.
- **制約**
  - $0 \leq l \leq r \lt N$
- **計算量** : $O(\log N)$ Time.

### update

```cpp
void update(int k, M x)
```

- 第 $k$ 要素 $S_k$ を $x \in M$ に更新する.
- **制約**
  - $0 \leq k \lt N$
- **計算量** : $O(\log N)$ Time.

### product

```cpp
M product(int l, int r)
```

- 積 $S_l * S_{l+1} * \dots * S_r$ を求める
- **制約**
  - $0 \leq l \leq r \lt N$
- **計算量** : $O(\log N)$ Time.

### all_product

```cpp
M all_product()
```
- $S$ の全ての要素に対する積 $S_0 * S_1 * \dots * S_{N-1}$ を求める
- **計算量** : $O(\log N)$ Time.
