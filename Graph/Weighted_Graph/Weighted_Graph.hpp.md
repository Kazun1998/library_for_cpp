---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u8FBA ID \u304C id \u3067\u3042\u308B\u8FBA\u3092\u53D6\u5F97\
      \u3059\u308B."
    links: []
  bundledCode: "#line 2 \"Graph/Weighted_Graph/Weighted_Graph.hpp\"\n\nnamespace weighted_graph\
    \ {\n    template<typename W>\n    struct Weighted_Edge {\n        int id, source,\
    \ target;\n        W weight;\n        Weighted_Edge *rev;\n\n        Weighted_Edge()\
    \ = default;\n        Weighted_Edge (int id, int source, int target, W weight):\
    \ id(id), source(source), target(target), weight(weight) {}\n    };\n    \n  \
    \  template<typename W>\n    class Weighted_Graph {\n        using Edge = Weighted_Edge<W>;\n\
    \n        private:\n        int edge_id_offset;\n        vector<vector<Edge*>>\
    \ incidences;\n        vector<Edge*> edges, rev_edges;\n\n        public:\n  \
    \      Weighted_Graph(int n, int edge_id_offset = 0): edge_id_offset(edge_id_offset),\
    \ incidences(n), edges(edge_id_offset), rev_edges(edge_id_offset) {}\n\n     \
    \   ~Weighted_Graph() {\n            for (Edge* edge: edges) {\n             \
    \   if (edge != nullptr) { delete edge; }\n            }\n\n            for (Edge*\
    \ rev_edge: rev_edges) {\n                if (rev_edge != nullptr) { delete rev_edge;\
    \ }\n            }\n        }\n\n        inline int order() const { return int(incidences.size());\
    \ }\n\n        inline int size() const { return int(edges.size()) - edge_id_offset;\
    \ }\n\n        // \u9802\u70B9 u \u304B\u3089\u9802\u70B9 v \u3078\u306E\u91CD\
    \u307F w \u306E\u5F27\u3092\u8FFD\u52A0\u3059\u308B.\n        int add_edge(int\
    \ u, int v, W w){\n            int id = int(edges.size());\n\n            Edge*\
    \ edge = new Edge(id, u, v, w);\n            Edge* rev_edge = new Edge(id, v,\
    \ u, w);\n\n            edge->rev = rev_edge;\n            rev_edge->rev = edge;\n\
    \n            incidences[u].emplace_back(edge);\n            incidences[v].emplace_back(rev_edge);\n\
    \n            edges.emplace_back(edge);\n            rev_edges.emplace_back(rev_edge);\n\
    \n            return id;\n        }\n\n        inline const vector<Edge*>& incidence\
    \ (int u) const { return incidences[u]; }\n\n        /// @brief \u8FBA ID \u304C\
    \ id \u3067\u3042\u308B\u8FBA\u3092\u53D6\u5F97\u3059\u308B.\n        /// @param\
    \ id\n        inline const Edge* get_edge(int id) const { return edges[id]; }\n\
    \n        /// @brief \u8FBA ID \u304C id \u3067\u3042\u308B\u8FBA\u3092\u53D6\u5F97\
    \u3059\u308B.\n        /// @param id\n        inline Edge* get_edge(int id) {\
    \ return edges[id]; }\n    };\n}\n"
  code: "#pragma once\n\nnamespace weighted_graph {\n    template<typename W>\n  \
    \  struct Weighted_Edge {\n        int id, source, target;\n        W weight;\n\
    \        Weighted_Edge *rev;\n\n        Weighted_Edge() = default;\n        Weighted_Edge\
    \ (int id, int source, int target, W weight): id(id), source(source), target(target),\
    \ weight(weight) {}\n    };\n    \n    template<typename W>\n    class Weighted_Graph\
    \ {\n        using Edge = Weighted_Edge<W>;\n\n        private:\n        int edge_id_offset;\n\
    \        vector<vector<Edge*>> incidences;\n        vector<Edge*> edges, rev_edges;\n\
    \n        public:\n        Weighted_Graph(int n, int edge_id_offset = 0): edge_id_offset(edge_id_offset),\
    \ incidences(n), edges(edge_id_offset), rev_edges(edge_id_offset) {}\n\n     \
    \   ~Weighted_Graph() {\n            for (Edge* edge: edges) {\n             \
    \   if (edge != nullptr) { delete edge; }\n            }\n\n            for (Edge*\
    \ rev_edge: rev_edges) {\n                if (rev_edge != nullptr) { delete rev_edge;\
    \ }\n            }\n        }\n\n        inline int order() const { return int(incidences.size());\
    \ }\n\n        inline int size() const { return int(edges.size()) - edge_id_offset;\
    \ }\n\n        // \u9802\u70B9 u \u304B\u3089\u9802\u70B9 v \u3078\u306E\u91CD\
    \u307F w \u306E\u5F27\u3092\u8FFD\u52A0\u3059\u308B.\n        int add_edge(int\
    \ u, int v, W w){\n            int id = int(edges.size());\n\n            Edge*\
    \ edge = new Edge(id, u, v, w);\n            Edge* rev_edge = new Edge(id, v,\
    \ u, w);\n\n            edge->rev = rev_edge;\n            rev_edge->rev = edge;\n\
    \n            incidences[u].emplace_back(edge);\n            incidences[v].emplace_back(rev_edge);\n\
    \n            edges.emplace_back(edge);\n            rev_edges.emplace_back(rev_edge);\n\
    \n            return id;\n        }\n\n        inline const vector<Edge*>& incidence\
    \ (int u) const { return incidences[u]; }\n\n        /// @brief \u8FBA ID \u304C\
    \ id \u3067\u3042\u308B\u8FBA\u3092\u53D6\u5F97\u3059\u308B.\n        /// @param\
    \ id\n        inline const Edge* get_edge(int id) const { return edges[id]; }\n\
    \n        /// @brief \u8FBA ID \u304C id \u3067\u3042\u308B\u8FBA\u3092\u53D6\u5F97\
    \u3059\u308B.\n        /// @param id\n        inline Edge* get_edge(int id) {\
    \ return edges[id]; }\n    };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Weighted_Graph/Weighted_Graph.hpp
  requiredBy: []
  timestamp: '2025-11-24 15:16:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Weighted_Graph/Weighted_Graph.hpp
layout: document
redirect_from:
- /library/Graph/Weighted_Graph/Weighted_Graph.hpp
- /library/Graph/Weighted_Graph/Weighted_Graph.hpp.html
title: "\u8FBA ID \u304C id \u3067\u3042\u308B\u8FBA\u3092\u53D6\u5F97\u3059\u308B\
  ."
---
