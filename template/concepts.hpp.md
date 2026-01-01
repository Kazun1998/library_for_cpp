---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/Interval_Product.hpp
    title: "\u533A\u9593\u7A4D"
  - icon: ':warning:'
    path: Sequence/Trie.hpp
    title: "Trie \u6728"
  - icon: ':warning:'
    path: Union_Find/Coloring_Union_Find.hpp
    title: "\u8FBA xy \u3092\u52A0\u3048\u308B. \u3053\u308C\u306B\u3088\u3063\u3066\
      \ x, y \u304C\u9023\u7D50\u306B\u306A\u3063\u305F\u5834\u5408, \u9023\u7D50\u6210\
      \u5206\u306E\u8272\u306E\u66F4\u65B0\u3092\u884C\u3046."
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Static_Range_Sum-2.test.cpp
    title: verify/yosupo_library_checker/data_structure/Static_Range_Sum-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/concepts.hpp\"\n\n// \u5358\u9805\u6F14\u7B97\u5B50\
    \u30B3\u30F3\u30BB\u30D7\u30C8\ntemplate <typename Op, typename X>\nconcept Unary_Operator_Concept\
    \ = requires(Op op, const X &x) {\n    { op(x) } -> std::convertible_to<X>;\n\
    };\n\n// \u4E8C\u9805\u6F14\u7B97\u5B50\u30B3\u30F3\u30BB\u30D7\u30C8\ntemplate\
    \ <typename Op, typename X>\nconcept Binary_Operator_Concept = requires(Op op,const\
    \ X &x, const X &y) {\n    { op(x, y) } -> std::convertible_to<X>;\n};\n\n// \u30E2\
    \u30CE\u30A4\u30C9\u30B3\u30F3\u30BB\u30D7\u30C8\n// \u4E8C\u9805\u6F14\u7B97\
    \ + \u5358\u4F4D\u5143\ntemplate <typename M, auto op, auto identity>\nconcept\
    \ Monoid_Concept = \n    Binary_Operator_Concept<decltype(op), M>\n    && std::convertible_to<decltype(identity),\
    \ M>;\n\n// \u7FA4\u30B3\u30F3\u30BB\u30D7\u30C8\n// \u30E2\u30CE\u30A4\u30C9\
    \ + \u9006\u5143\ntemplate <typename G, auto op, auto inv, auto identity>\nconcept\
    \ Group_Concept = \n    Monoid_Concept<G, op, identity>\n    && Unary_Operator_Concept<decltype(inv),\
    \ G>;\n\n// \u30CF\u30C3\u30B7\u30E5\u53EF\u80FD\u30B3\u30F3\u30BB\u30D7\u30C8\
    \ntemplate<typename T>\nconcept Hashable = requires(T x) {\n    { hash<T>{}(x)\
    \ } -> convertible_to<size_t>;\n};\n"
  code: "#pragma once\n\n// \u5358\u9805\u6F14\u7B97\u5B50\u30B3\u30F3\u30BB\u30D7\
    \u30C8\ntemplate <typename Op, typename X>\nconcept Unary_Operator_Concept = requires(Op\
    \ op, const X &x) {\n    { op(x) } -> std::convertible_to<X>;\n};\n\n// \u4E8C\
    \u9805\u6F14\u7B97\u5B50\u30B3\u30F3\u30BB\u30D7\u30C8\ntemplate <typename Op,\
    \ typename X>\nconcept Binary_Operator_Concept = requires(Op op,const X &x, const\
    \ X &y) {\n    { op(x, y) } -> std::convertible_to<X>;\n};\n\n// \u30E2\u30CE\u30A4\
    \u30C9\u30B3\u30F3\u30BB\u30D7\u30C8\n// \u4E8C\u9805\u6F14\u7B97 + \u5358\u4F4D\
    \u5143\ntemplate <typename M, auto op, auto identity>\nconcept Monoid_Concept\
    \ = \n    Binary_Operator_Concept<decltype(op), M>\n    && std::convertible_to<decltype(identity),\
    \ M>;\n\n// \u7FA4\u30B3\u30F3\u30BB\u30D7\u30C8\n// \u30E2\u30CE\u30A4\u30C9\
    \ + \u9006\u5143\ntemplate <typename G, auto op, auto inv, auto identity>\nconcept\
    \ Group_Concept = \n    Monoid_Concept<G, op, identity>\n    && Unary_Operator_Concept<decltype(inv),\
    \ G>;\n\n// \u30CF\u30C3\u30B7\u30E5\u53EF\u80FD\u30B3\u30F3\u30BB\u30D7\u30C8\
    \ntemplate<typename T>\nconcept Hashable = requires(T x) {\n    { hash<T>{}(x)\
    \ } -> convertible_to<size_t>;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: template/concepts.hpp
  requiredBy:
  - Sequence/Trie.hpp
  - Union_Find/Coloring_Union_Find.hpp
  - Math/Interval_Product.hpp
  timestamp: '2025-12-25 00:44:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Static_Range_Sum-2.test.cpp
documentation_of: template/concepts.hpp
layout: document
redirect_from:
- /library/template/concepts.hpp
- /library/template/concepts.hpp.html
title: template/concepts.hpp
---
