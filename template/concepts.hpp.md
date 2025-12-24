---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Math/Interval_Product.hpp
    title: "\u533A\u9593\u7A4D"
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
    \ G>;\n"
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
    \ G>;\n"
  dependsOn: []
  isVerificationFile: false
  path: template/concepts.hpp
  requiredBy:
  - Math/Interval_Product.hpp
  timestamp: '2025-12-25 00:31:39+09:00'
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
