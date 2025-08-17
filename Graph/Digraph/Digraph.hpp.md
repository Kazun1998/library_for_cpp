---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/Digraph/Strongly_Connected_Components.hpp
    title: Graph/Digraph/Strongly_Connected_Components.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
    title: verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/Digraph/Digraph.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nnamespace Digraph {\n  struct Arc {\n    int id, source,\
    \ target;\n\n    Arc(int id, int source, int target): id(id), source(source),\
    \ target(target) {}\n  };\n\n  class Digraph {\n    private:\n    int arc_id_offset;\n\
    \    vector<vector<int>> adjacent_out, adjacent_in;\n    vector<Arc> arcs;\n\n\
    \    public:\n    Digraph(int n, int arc_id_offset = 0): arc_id_offset(arc_id_offset)\
    \ {\n        adjacent_out.assign(n, {});\n        adjacent_in.assign(n, {});\n\
    \        arcs.resize(arc_id_offset, Arc(-1, -1, -1));\n      }\n    \n    inline\
    \ int order() const { return int(adjacent_in.size()); }\n\n    inline int size()\
    \ const { return int(arcs.size()) - arc_id_offset; }\n\n    // \u9802\u70B9 u\
    \ \u304B\u3089\u9802\u70B9 v \u3078\u306E\u91CD\u307F w \u306E\u5F27\u3092\u8FFD\
    \u52A0\u3059\u308B.\n    int add_arc(int u, int v){\n      int id = int(arcs.size());\n\
    \n      adjacent_out[u].emplace_back(id);\n      adjacent_in[v].emplace_back(id);\n\
    \      arcs.emplace_back(id, u, v);\n\n      return id;\n    }\n\n    // \u9802\
    \u70B9 u \u304B\u3089\u51FA\u308B\u5F27\u306E ID \u306E\u30EA\u30B9\u30C8\u3092\
    \u53D6\u5F97\n    inline const std::vector<int>& successors(int u) const { return\
    \ adjacent_out[u]; }\n\n    // \u9802\u70B9 u \u306B\u5165\u308B\u5F27\u306E ID\
    \ \u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\n    inline const std::vector<int>&\
    \ predecessors(int u) const { return adjacent_in[u]; }\n\n    // \u5F27 ID \u304C\
    \ id \u3067\u3042\u308B\u5F27\u3092\u53D6\u5F97\u3059\u308B.\n    inline const\
    \ Arc& get_arc(int id) const { return arcs[id]; }\n    inline Arc& get_arc(int\
    \ id) { return arcs[id]; }\n  };\n}\n"
  code: "#pragma once\n\n#include<bits/stdc++.h>\nusing namespace std;\n\nnamespace\
    \ Digraph {\n  struct Arc {\n    int id, source, target;\n\n    Arc(int id, int\
    \ source, int target): id(id), source(source), target(target) {}\n  };\n\n  class\
    \ Digraph {\n    private:\n    int arc_id_offset;\n    vector<vector<int>> adjacent_out,\
    \ adjacent_in;\n    vector<Arc> arcs;\n\n    public:\n    Digraph(int n, int arc_id_offset\
    \ = 0): arc_id_offset(arc_id_offset) {\n        adjacent_out.assign(n, {});\n\
    \        adjacent_in.assign(n, {});\n        arcs.resize(arc_id_offset, Arc(-1,\
    \ -1, -1));\n      }\n    \n    inline int order() const { return int(adjacent_in.size());\
    \ }\n\n    inline int size() const { return int(arcs.size()) - arc_id_offset;\
    \ }\n\n    // \u9802\u70B9 u \u304B\u3089\u9802\u70B9 v \u3078\u306E\u91CD\u307F\
    \ w \u306E\u5F27\u3092\u8FFD\u52A0\u3059\u308B.\n    int add_arc(int u, int v){\n\
    \      int id = int(arcs.size());\n\n      adjacent_out[u].emplace_back(id);\n\
    \      adjacent_in[v].emplace_back(id);\n      arcs.emplace_back(id, u, v);\n\n\
    \      return id;\n    }\n\n    // \u9802\u70B9 u \u304B\u3089\u51FA\u308B\u5F27\
    \u306E ID \u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\n    inline const std::vector<int>&\
    \ successors(int u) const { return adjacent_out[u]; }\n\n    // \u9802\u70B9 u\
    \ \u306B\u5165\u308B\u5F27\u306E ID \u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\
    \n    inline const std::vector<int>& predecessors(int u) const { return adjacent_in[u];\
    \ }\n\n    // \u5F27 ID \u304C id \u3067\u3042\u308B\u5F27\u3092\u53D6\u5F97\u3059\
    \u308B.\n    inline const Arc& get_arc(int id) const { return arcs[id]; }\n  \
    \  inline Arc& get_arc(int id) { return arcs[id]; }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Digraph/Digraph.hpp
  requiredBy:
  - Graph/Digraph/Strongly_Connected_Components.hpp
  timestamp: '2025-08-17 23:17:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/graph/Strongly_Connected_Components.test.cpp
documentation_of: Graph/Digraph/Digraph.hpp
layout: document
redirect_from:
- /library/Graph/Digraph/Digraph.hpp
- /library/Graph/Digraph/Digraph.hpp.html
title: Graph/Digraph/Digraph.hpp
---
