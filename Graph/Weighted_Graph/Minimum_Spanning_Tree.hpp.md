---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Graph/Weighted_Graph/Weighted_Graph.hpp
    title: "\u91CD\u307F\u4ED8\u304D\u7121\u5411\u30B0\u30E9\u30D5"
  _extendedRequiredBy:
  - icon: ':x:'
    path: Graph/Weighted_Graph/Kruskal.hpp
    title: "Kruskal \u6CD5"
  - icon: ':x:'
    path: Graph/Weighted_Graph/Prim.hpp
    title: "Prim \u6CD5"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo_library_checker/graph/Minimum_Spanning_Tree_by_Kruskal.test.cpp
    title: verify/yosupo_library_checker/graph/Minimum_Spanning_Tree_by_Kruskal.test.cpp
  - icon: ':x:'
    path: verify/yosupo_library_checker/graph/Minimum_Spanning_Tree_by_Prim.test.cpp
    title: verify/yosupo_library_checker/graph/Minimum_Spanning_Tree_by_Prim.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/Weighted_Graph/Minimum_Spanning_Tree.hpp\"\n\n#line\
    \ 2 \"Graph/Weighted_Graph/Weighted_Graph.hpp\"\n\nnamespace weighted_graph {\n\
    \    template<typename W>\n    struct Weighted_Edge {\n        int id, source,\
    \ target;\n        W weight;\n        Weighted_Edge *rev;\n\n        Weighted_Edge()\
    \ = default;\n        Weighted_Edge (int id, int source, int target, W weight):\
    \ id(id), source(source), target(target), weight(weight) {}\n    };\n    \n  \
    \  template<typename W>\n    class Weighted_Graph {\n        using Edge = Weighted_Edge<W>;\n\
    \n        private:\n        vector<vector<Edge*>> incidences;\n\n        public:\n\
    \        int edge_id_offset;\n        vector<Edge*> edges, rev_edges;\n\n    \
    \    /// @brief \u4F4D\u6570\u304C n \u306E\u91CD\u307F\u4ED8\u304D\u7121\u5411\
    \u30B0\u30E9\u30D5\u3092\u751F\u6210\u3059\u308B.\n        /// @param n \u4F4D\
    \u6570\n        /// @param edge_id_offset \u8FBA\u306E ID \u306E\u30AA\u30D5\u30BB\
    \u30C3\u30C8\n        Weighted_Graph(int n, int edge_id_offset = 0): edge_id_offset(edge_id_offset),\
    \ incidences(n), edges(edge_id_offset), rev_edges(edge_id_offset) {}\n\n     \
    \   ~Weighted_Graph() {\n            for (Edge* edge: edges) {\n             \
    \   if (edge != nullptr) { delete edge; }\n            }\n\n            for (Edge*\
    \ rev_edge: rev_edges) {\n                if (rev_edge != nullptr) { delete rev_edge;\
    \ }\n            }\n        }\n\n        /// @brief \u4F4D\u6570 (\u9802\u70B9\
    \u306E\u6570) \u3092\u6C42\u3081\u308B\n        inline int order() const { return\
    \ int(incidences.size()); }\n\n        /// @brief \u30B5\u30A4\u30BA (\u8FBA\u306E\
    \u6570) \u3092\u6C42\u3081\u308B\n        inline int size() const { return int(edges.size())\
    \ - edge_id_offset; }\n\n\n        /// @brief \u9802\u70B9 u \u304B\u3089\u9802\
    \u70B9 v \u3078\u306E\u91CD\u307F w \u306E\u5F27\u3092\u8FFD\u52A0\u3059\u308B\
    .\n        /// @param u \u9802\u70B9 1\n        /// @param v \u9802\u70B9 2\n\
    \        /// @param w \u91CD\u307F\n        /// @return \u8FFD\u52A0\u3057\u305F\
    \u8FBA\u306E ID\n        int add_edge(int u, int v, W w){\n            int id\
    \ = int(edges.size());\n\n            Edge* edge = new Edge(id, u, v, w);\n  \
    \          Edge* rev_edge = new Edge(id, v, u, w);\n\n            edge->rev =\
    \ rev_edge;\n            rev_edge->rev = edge;\n\n            incidences[u].emplace_back(edge);\n\
    \            incidences[v].emplace_back(rev_edge);\n\n            edges.emplace_back(edge);\n\
    \            rev_edges.emplace_back(rev_edge);\n\n            return id;\n   \
    \     }\n\n        /// @brief \u9802\u70B9 u \u306B\u63A5\u7D9A\u3059\u308B\u8FBA\
    \ (\u30A2\u30C9\u30EC\u30B9) \u306E\u30EA\u30B9\u30C8\u3092\u6C42\u3081\u308B\
    .\n        /// @param u \n        inline const vector<Edge*>& incidence (int u)\
    \ const { return incidences[u]; }\n\n        /// @brief \u8FBA ID \u304C id \u3067\
    \u3042\u308B\u8FBA\u3092\u53D6\u5F97\u3059\u308B.\n        /// @param id\n   \
    \     inline const Edge* get_edge(int id) const { return edges[id]; }\n\n    \
    \    /// @brief \u8FBA ID \u304C id \u3067\u3042\u308B\u8FBA\u3092\u53D6\u5F97\
    \u3059\u308B.\n        /// @param id\n        inline Edge* get_edge(int id) {\
    \ return edges[id]; }\n    };\n}\n#line 4 \"Graph/Weighted_Graph/Minimum_Spanning_Tree.hpp\"\
    \n\nnamespace weighted_graph {\n    template<typename W>\n    struct Minimum_Spanning_Tree\
    \ {\n        vector<Weighted_Edge<W>*> edges;\n        W weight;\n    };\n}\n"
  code: "#pragma once\n\n#include\"Weighted_Graph.hpp\"\n\nnamespace weighted_graph\
    \ {\n    template<typename W>\n    struct Minimum_Spanning_Tree {\n        vector<Weighted_Edge<W>*>\
    \ edges;\n        W weight;\n    };\n}\n"
  dependsOn:
  - Graph/Weighted_Graph/Weighted_Graph.hpp
  isVerificationFile: false
  path: Graph/Weighted_Graph/Minimum_Spanning_Tree.hpp
  requiredBy:
  - Graph/Weighted_Graph/Kruskal.hpp
  - Graph/Weighted_Graph/Prim.hpp
  timestamp: '2026-02-14 19:18:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo_library_checker/graph/Minimum_Spanning_Tree_by_Prim.test.cpp
  - verify/yosupo_library_checker/graph/Minimum_Spanning_Tree_by_Kruskal.test.cpp
documentation_of: Graph/Weighted_Graph/Minimum_Spanning_Tree.hpp
layout: document
redirect_from:
- /library/Graph/Weighted_Graph/Minimum_Spanning_Tree.hpp
- /library/Graph/Weighted_Graph/Minimum_Spanning_Tree.hpp.html
title: Graph/Weighted_Graph/Minimum_Spanning_Tree.hpp
---
