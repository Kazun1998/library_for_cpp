---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':heavy_check_mark:'
    path: template/exception.hpp
    title: template/exception.hpp
  - icon: ':heavy_check_mark:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/math.hpp
    title: template/math.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/utility.hpp
    title: template/utility.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5468\u9577 n \u306E\u5186\u74B0\u4E0A\u3067, l \u304B\u3089\
      \ r \u307E\u3067 (l \u304B\u3089\u6642\u8A08\u56DE\u308A\u306B r \u307E\u3067\
      ) \u306E\u5404\u8981\u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B"
    links:
    - https://github.com/Kazun1998/library_for_cpp/blob/main/Imos/Cyclic_Imos_1.hpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Imos/Cyclic_Imos_1.hpp: line 3: #pragma once found in a non-first line\n"
  code: "// https://github.com/Kazun1998/library_for_cpp/blob/main/Imos/Cyclic_Imos_1.hpp\n\
    \n#pragma once\n\n#include \"../template/template.hpp\"\n\ntemplate <typename\
    \ T>\nclass Cyclic_Imos_1 {\n    private:\n    std::vector<T> lazy;\n    int n;\n\
    \n    inline int norm(int t) const { return ((t % n) + n) % n; }\n\n    public:\n\
    \    Cyclic_Imos_1(const int n) : n(n), lazy(n, 0) {}\n\n    /// @brief \u5468\
    \u9577 n \u306E\u5186\u74B0\u4E0A\u3067, l \u304B\u3089 r \u307E\u3067 (l \u304B\
    \u3089\u6642\u8A08\u56DE\u308A\u306B r \u307E\u3067) \u306E\u5404\u8981\u7D20\u306B\
    \ x \u3092\u52A0\u7B97\u3059\u308B\n    /// @details l <= r (mod \u3067\u6B63\u898F\
    \u5316\u3057\u305F\u4E0A\u3067) \u306E\u3068\u304D\u306F\u901A\u5E38\u306E\u9589\
    \u533A\u9593 [l, r] \u3078\u306E\u52A0\u7B97, l > r \u306E\u3068\u304D\u306F [l,\
    \ n - 1] \u3068 [0, r] \u3078\u306E\u52A0\u7B97\u3092\u610F\u5473\u3059\u308B\
    .\n    /// @param l \u59CB\u70B9\n    /// @param r \u7D42\u70B9\n    /// @param\
    \ x \u52A0\u7B97\u5024\n    void add(int l, int r, const T x) {\n        if (n\
    \ == 0) return;\n\n        l = norm(l);\n        r = norm(r);\n\n        // l\
    \ <= r : [l, r] \u304C (n-1, 0) \u3092\u307E\u305F\u304C\u306A\u3044\u533A\u9593\
    \u3067\u3042\u308B\u3053\u3068\u3092\u610F\u5473\u3059\u308B\n        if (l <=\
    \ r) {\n            lazy[l] += x;\n            if (r + 1 < n) lazy[r + 1] -= x;\n\
    \        } else {\n            lazy[0] += x;\n            lazy[r + 1] -= x;\n\
    \            lazy[l] += x;\n        }\n    }\n\n    /// @brief \u5468\u9577 n\
    \ \u306E\u5186\u74B0\u4E0A\u3067, l \u304B\u3089 r \u307E\u3067 (l \u304B\u3089\
    \u6642\u8A08\u56DE\u308A\u306B r \u307E\u3067) \u306E\u5404\u8981\u7D20\u306B\
    \ 1 \u3092\u52A0\u7B97\u3059\u308B\n    /// @param l \u59CB\u70B9\n    /// @param\
    \ r \u7D42\u70B9\n    void add(const int l, const int r) { add(l, r, 1); }\n\n\
    \    /// @brief \u5468\u9577 n \u306E\u5186\u74B0\u4E0A\u3067, \u8981\u7D20 t\
    \ \u306B x \u3092\u52A0\u7B97\u3059\u308B\n    /// @param t \u52A0\u7B97\u3059\
    \u308B\u4F4D\u7F6E\n    /// @param x \u52A0\u7B97\u5024\n    void add_point(const\
    \ int t, const T x) { add(t, t, x); }\n\n    /// @brief \u5468\u9577 n \u306E\u5186\
    \u74B0\u4E0A\u3067, l, l + 1, ..., l + (k - 1) \u306E\u5404\u8981\u7D20\u306B\
    \ x \u3092\u52A0\u7B97\u3059\u308B\n    /// @param l \u59CB\u70B9\n    /// @param\
    \ k \u52A0\u7B97\u3059\u308B\u8981\u7D20\u6570\n    /// @param x \u52A0\u7B97\u5024\
    \n    void add_forward(const int l, const int k, const T x) {\n        if (n ==\
    \ 0 || k <= 0) return;\n\n        // q : \u5186\u74B0\u3092\u4F55\u5468\u5206\u52A0\
    \u7B97\u3059\u308B\u304B, m : \u7AEF\u6570\u3068\u3057\u3066\u52A0\u7B97\u3059\
    \u308B\u8981\u7D20\u6570\n        const int q = k / n, m = k % n;\n        if\
    \ (q > 0) add(0, n - 1, x * q);\n        if (m > 0) add(l, l + m - 1, x);\n  \
    \  }\n\n    /// @brief \u5468\u9577 n \u306E\u5186\u74B0\u4E0A\u3067, r, r - 1,\
    \ ..., r - (k - 1) \u306E\u5404\u8981\u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B\
    \n    /// @param r \u59CB\u70B9\n    /// @param k \u52A0\u7B97\u3059\u308B\u8981\
    \u7D20\u6570\n    /// @param x \u52A0\u7B97\u5024\n    void add_back(const int\
    \ r, const int k, const T x) {\n        if (n == 0 || k <= 0) return;\n\n    \
    \    // q : \u5186\u74B0\u3092\u4F55\u5468\u5206\u52A0\u7B97\u3059\u308B\u304B\
    , m : \u7AEF\u6570\u3068\u3057\u3066\u52A0\u7B97\u3059\u308B\u8981\u7D20\u6570\
    \n        const int q = k / n, m = k % n;\n        if (q > 0) add(0, n - 1, x\
    \ * q);\n        if (m > 0) add(r - m + 1, r, x);\n    }\n\n    /// @brief \u7D2F\
    \u7A4D\u548C\u3092\u8A08\u7B97\u3059\u308B\n    std::vector<T> cumulate() {\n\
    \        if (n == 0) return std::vector<T>();\n\n        std::vector<T> res(lazy.begin(),\
    \ lazy.end());\n        for (int i = 1; i < n; ++i) res[i] += res[i - 1];\n\n\
    \        return res;\n    }\n\n    /// @brief \u5185\u90E8\u72B6\u614B\u3092\u30AF\
    \u30EA\u30A2\u3057\u3066\u3001\u518D\u5EA6 add \u3067\u304D\u308B\u72B6\u614B\u306B\
    \u3059\u308B\n    void clear() {\n        std::fill(lazy.begin(), lazy.end(),\
    \ T(0));\n    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Imos/Cyclic_Imos_1.hpp
  requiredBy: []
  timestamp: '2026-08-19 00:51:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Imos/Cyclic_Imos_1.hpp
layout: document
redirect_from:
- /library/Imos/Cyclic_Imos_1.hpp
- /library/Imos/Cyclic_Imos_1.hpp.html
title: "\u5468\u9577 n \u306E\u5186\u74B0\u4E0A\u3067, l \u304B\u3089 r \u307E\u3067\
  \ (l \u304B\u3089\u6642\u8A08\u56DE\u308A\u306B r \u307E\u3067) \u306E\u5404\u8981\
  \u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B"
---
