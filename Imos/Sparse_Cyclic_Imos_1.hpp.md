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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/3166.test.cpp
    title: verify/yukicoder/3166.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5468\u9577 n \u306E\u5186\u74B0\u4E0A\u3067, l \u304B\u3089\
      \ r \u307E\u3067 (l \u304B\u3089\u6642\u8A08\u56DE\u308A\u306B r \u307E\u3067\
      ) \u306E\u5404\u8981\u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B"
    links:
    - https://github.com/Kazun1998/library_for_cpp/blob/main/Imos/Sparse_Cyclic_Imos_1.hpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ Imos/Sparse_Cyclic_Imos_1.hpp: line 2: #pragma once found in a non-first line\n"
  code: "// https://github.com/Kazun1998/library_for_cpp/blob/main/Imos/Sparse_Cyclic_Imos_1.hpp\n\
    #pragma once\n\n#include \"../template/template.hpp\"\n\ntemplate <typename T,\
    \ typename I = long long>\nclass Sparse_Cyclic_Imos_1 {\n    private:\n    std::map<I,\
    \ T> diff;\n    I n;\n\n    inline I norm(I t) const { return ((t % n) + n) %\
    \ n; }\n\n    public:\n    Sparse_Cyclic_Imos_1(const I n) : n(n) {}\n\n    ///\
    \ @brief \u5468\u9577 n \u306E\u5186\u74B0\u4E0A\u3067, l \u304B\u3089 r \u307E\
    \u3067 (l \u304B\u3089\u6642\u8A08\u56DE\u308A\u306B r \u307E\u3067) \u306E\u5404\
    \u8981\u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B\n    /// @details l <= r (mod\
    \ \u3067\u6B63\u898F\u5316\u3057\u305F\u4E0A\u3067) \u306E\u3068\u304D\u306F\u901A\
    \u5E38\u306E\u9589\u533A\u9593 [l, r] \u3078\u306E\u52A0\u7B97, l > r \u306E\u3068\
    \u304D\u306F [l, n - 1] \u3068 [0, r] \u3078\u306E\u52A0\u7B97\u3092\u610F\u5473\
    \u3059\u308B.\n    /// @param l \u59CB\u70B9\n    /// @param r \u7D42\u70B9\n\
    \    /// @param x \u52A0\u7B97\u5024\n    void add(I l, I r, const T x = 1) {\n\
    \        if (n == 0) return;\n\n        l = norm(l);\n        r = norm(r);\n\n\
    \        // l <= r : [l, r] \u304C (n-1, 0) \u3092\u307E\u305F\u304C\u306A\u3044\
    \u533A\u9593\u3067\u3042\u308B\u3053\u3068\u3092\u610F\u5473\u3059\u308B\n   \
    \     if (l <= r) {\n            diff[l] += x;\n            if (r + 1 < n) diff[r\
    \ + 1] -= x;\n        } else {\n            diff[0] += x;\n            diff[r\
    \ + 1] -= x;\n            diff[l] += x;\n        }\n    }\n\n    /// @brief \u5468\
    \u9577 n \u306E\u5186\u74B0\u4E0A\u3067, \u8981\u7D20 t \u306B x \u3092\u52A0\u7B97\
    \u3059\u308B\n    /// @param t \u52A0\u7B97\u3059\u308B\u4F4D\u7F6E\n    /// @param\
    \ x \u52A0\u7B97\u5024\n    void add_point(const I t, const T x) { add(t, t, x);\
    \ }\n\n    /// @brief \u5468\u9577 n \u306E\u5186\u74B0\u4E0A\u3067, l, l + 1,\
    \ ..., l + (k - 1) \u306E\u5404\u8981\u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B\
    \n    /// @param l \u59CB\u70B9\n    /// @param k \u52A0\u7B97\u3059\u308B\u8981\
    \u7D20\u6570\n    /// @param x \u52A0\u7B97\u5024\n    void add_forward(const\
    \ I l, const I k, const T x) {\n        if (n == 0 || k <= 0) return;\n\n    \
    \    // q : \u5186\u74B0\u3092\u4F55\u5468\u5206\u52A0\u7B97\u3059\u308B\u304B\
    , m : \u7AEF\u6570\u3068\u3057\u3066\u52A0\u7B97\u3059\u308B\u8981\u7D20\u6570\
    \n        const I q = k / n, m = k % n;\n        if (q > 0) add(0, n - 1, x *\
    \ q);\n        if (m > 0) add(l, l + m - 1, x);\n    }\n\n    /// @brief \u5468\
    \u9577 n \u306E\u5186\u74B0\u4E0A\u3067, r, r - 1, ..., r - (k - 1) \u306E\u5404\
    \u8981\u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B\n    /// @param r \u59CB\u70B9\
    \n    /// @param k \u52A0\u7B97\u3059\u308B\u8981\u7D20\u6570\n    /// @param\
    \ x \u52A0\u7B97\u5024\n    void add_back(const I r, const I k, const T x) {\n\
    \        if (n == 0 || k <= 0) return;\n\n        // q : \u5186\u74B0\u3092\u4F55\
    \u5468\u5206\u52A0\u7B97\u3059\u308B\u304B, m : \u7AEF\u6570\u3068\u3057\u3066\
    \u52A0\u7B97\u3059\u308B\u8981\u7D20\u6570\n        const I q = k / n, m = k %\
    \ n;\n        if (q > 0) add(0, n - 1, x * q);\n        if (m > 0) add(r - m +\
    \ 1, r, x);\n    }\n\n    /// @brief \u3053\u308C\u307E\u3067\u306E\u52A0\u7B97\
    \u30AF\u30A8\u30EA\u3092\u5186\u74B0\u5168\u4F53 [0, n - 1] \u306B\u3064\u3044\
    \u3066\u7D2F\u7A4D\u3059\u308B\n    /// @return (y, l, r) \u3068\u3044\u3046\u5F62\
    \u306E\u30EA\u30B9\u30C8. l <= x <= r \u306E\u7BC4\u56F2\u306B\u304A\u3044\u3066\
    \u306F\u7D2F\u7A4D\u548C\u304C y \u3067\u3042\u308B\u3053\u3068\u3092\u610F\u5473\
    \u3059\u308B.\n    std::vector<std::tuple<T, I, I>> cumulative() {\n        std::vector<std::tuple<T,\
    \ I, I>> res;\n        if (n == 0) return res;\n\n        T cum = 0;\n       \
    \ I t_old = 0;\n\n        for (const auto &[t, d] : diff) {\n            if (t\
    \ > n - 1) break;\n            if (d == 0) continue;\n\n            if (t_old\
    \ <= t - 1) res.emplace_back(cum, t_old, t - 1);\n\n            cum += d;\n  \
    \          t_old = t;\n        }\n\n        if (t_old <= n - 1) res.emplace_back(cum,\
    \ t_old, n - 1);\n\n        return res;\n    }\n\n    /// @brief \u5185\u90E8\u72B6\
    \u614B\u3092\u30AF\u30EA\u30A2\u3057\u3066\u3001\u518D\u5EA6 add \u3067\u304D\u308B\
    \u72B6\u614B\u306B\u3059\u308B\n    void clear() {\n        diff.clear();\n  \
    \  }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/utility.hpp
  - template/math.hpp
  - template/inout.hpp
  - template/macro.hpp
  - template/bitop.hpp
  - template/exception.hpp
  isVerificationFile: false
  path: Imos/Sparse_Cyclic_Imos_1.hpp
  requiredBy: []
  timestamp: '2026-08-19 00:51:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/3166.test.cpp
documentation_of: Imos/Sparse_Cyclic_Imos_1.hpp
layout: document
redirect_from:
- /library/Imos/Sparse_Cyclic_Imos_1.hpp
- /library/Imos/Sparse_Cyclic_Imos_1.hpp.html
title: "\u5468\u9577 n \u306E\u5186\u74B0\u4E0A\u3067, l \u304B\u3089 r \u307E\u3067\
  \ (l \u304B\u3089\u6642\u8A08\u56DE\u308A\u306B r \u307E\u3067) \u306E\u5404\u8981\
  \u7D20\u306B x \u3092\u52A0\u7B97\u3059\u308B"
---
