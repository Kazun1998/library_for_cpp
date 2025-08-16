---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Weighed_Digraph/Weighted_Digraph.hpp
    title: Graph/Weighed_Digraph/Weighted_Digraph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/graph/Directed_Dijkstra.test.cpp
    title: verify/yosupo_library_checker/graph/Directed_Dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/Weighed_Digraph/Weighted_Digraph.hpp\"\n\nnamespace\
    \ Weighted_Digraph {\n  template<typename W>\n  struct Weighted_Arc {\n    int\
    \ id, source, target;\n    W weight;\n\n    Weighted_Arc (int id, int source,\
    \ int target, W weight): id(id), source(source), target(target), weight(weight)\
    \ {}\n  };\n\n  template<typename W>\n  class Weighted_Digraph {\n    using Arc\
    \ = Weighted_Arc<W>;\n\n    private:\n    int arc_id_offset;\n    vector<vector<int>>\
    \ adjacent_out, adjacent_in;\n    vector<Arc> arcs;\n\n    public:\n    Weighted_Digraph(int\
    \ n, int arc_id_offset = 0): arc_id_offset(arc_id_offset) {\n        adjacent_out.assign(n,\
    \ {});\n        adjacent_in.assign(n, {});\n        arcs.resize(arc_id_offset,\
    \ Weighted_Arc<W>(-1, -1, -1, W()));\n      }\n    \n    inline int order() const\
    \ { return int(adjacent_in.size()); }\n\n    inline int size() const { return\
    \ int(arcs.size()) - arc_id_offset; }\n\n    // \u9802\u70B9 u \u304B\u3089\u9802\
    \u70B9 v \u3078\u306E\u91CD\u307F w \u306E\u5F27\u3092\u8FFD\u52A0\u3059\u308B\
    .\n    int add_arc(int u, int v, W w){\n      int id = int(arcs.size());\n\n \
    \     adjacent_out[u].emplace_back(id);\n      adjacent_in[v].emplace_back(id);\n\
    \      arcs.emplace_back(id, u, v, w);\n\n      return id;\n    }\n\n    // \u9802\
    \u70B9 u \u304B\u3089\u51FA\u308B\u5F27\u306E ID \u306E\u30EA\u30B9\u30C8\u3092\
    \u53D6\u5F97\n    inline const std::vector<int>& successors(int u) const { return\
    \ adjacent_out[u]; }\n\n    // \u9802\u70B9 u \u306B\u5165\u308B\u5F27\u306E ID\
    \ \u306E\u30EA\u30B9\u30C8\u3092\u53D6\u5F97\n    inline const std::vector<int>&\
    \ predecessors(int u) const { return adjacent_in[u]; }\n\n    // \u5F27 ID \u304C\
    \ id \u3067\u3042\u308B\u5F27\u3092\u53D6\u5F97\u3059\u308B.\n    inline const\
    \ Arc& get_arc(int id) const { return arcs[id]; }\n    inline Arc& get_arc(int\
    \ id) { return arcs[id]; }\n  };\n}\n#line 3 \"Graph/Weighed_Digraph/Dijkstra.hpp\"\
    \n\nnamespace Weighted_Digraph::Dijkstra {\n    class UnreachableException : public\
    \ exception {\n      public: // public\u306B\u6307\u5B9A\n      const char* what()\
    \ const noexcept override { return \"\u6C42\u3081\u308B\u30D1\u30B9\u304C\u5B58\
    \u5728\u3057\u307E\u305B\u3093\"; }\n    };\n\n  template<typename W>\n  struct\
    \ Shortest_Path {\n    vector<int> path_arc_ids;\n    vector<int> path_vertices;\n\
    \    W length;\n\n    Shortest_Path<W>(vector<int> path_arc_ids, vector<int> path_vertices,\
    \ W length):\n      path_arc_ids(path_arc_ids), path_vertices(path_vertices),\
    \ length(length) {}\n  };\n\n  template<typename W>\n  Shortest_Path<W> Dijkstra(Weighted_Digraph<W>\
    \ &D, int start, int goal) {\n    int n = D.order();\n\n    vector<bool> reachable(n,\
    \ false); reachable[start] = true;\n    vector<int> parent_arc_ids(n, -1);\n \
    \   vector<W> dist(n); dist[start] = 0;\n\n    using P = pair<W, int>;\n    priority_queue<P,\
    \ vector<P>, greater<P>> Q; Q.emplace(dist[start], start);\n\n    while (!Q.empty())\
    \ {\n      P pair = Q.top(); Q.pop();\n      W d = pair.first;\n      int v =\
    \ pair.second;\n\n      if (dist[v] < d) { continue; }\n\n      for (auto arc_id:\
    \ D.successors(v)) {\n        Weighted_Arc<W> arc = D.get_arc(arc_id);\n     \
    \   if (!reachable[arc.target] || dist[arc.target] > dist[v] + arc.weight) {\n\
    \          dist[arc.target] = dist[v] + arc.weight;\n          reachable[arc.target]\
    \ = true;\n          parent_arc_ids[arc.target] = arc.id;\n          Q.emplace(dist[arc.target],\
    \ arc.target);\n        }\n      }\n    }\n\n    if (!reachable[goal]) { throw\
    \ UnreachableException(); }\n\n    vector<int> path_arc_ids;\n    vector<int>\
    \ path_vertices{goal}; \n\n    while (path_vertices.back() != start) {\n     \
    \ int arc_id = parent_arc_ids[path_vertices.back()];\n      auto arc = D.get_arc(arc_id);\n\
    \n      path_arc_ids.emplace_back(arc_id);\n      path_vertices.emplace_back(arc.source);\n\
    \    }\n\n    reverse(path_arc_ids.begin(), path_arc_ids.end());\n    reverse(path_vertices.begin(),\
    \ path_vertices.end());\n\n    return Shortest_Path<W>(path_arc_ids, path_vertices,\
    \ dist[goal]);\n  }\n}\n"
  code: "#pragma once\n#include\"Weighted_Digraph.hpp\"\n\nnamespace Weighted_Digraph::Dijkstra\
    \ {\n    class UnreachableException : public exception {\n      public: // public\u306B\
    \u6307\u5B9A\n      const char* what() const noexcept override { return \"\u6C42\
    \u3081\u308B\u30D1\u30B9\u304C\u5B58\u5728\u3057\u307E\u305B\u3093\"; }\n    };\n\
    \n  template<typename W>\n  struct Shortest_Path {\n    vector<int> path_arc_ids;\n\
    \    vector<int> path_vertices;\n    W length;\n\n    Shortest_Path<W>(vector<int>\
    \ path_arc_ids, vector<int> path_vertices, W length):\n      path_arc_ids(path_arc_ids),\
    \ path_vertices(path_vertices), length(length) {}\n  };\n\n  template<typename\
    \ W>\n  Shortest_Path<W> Dijkstra(Weighted_Digraph<W> &D, int start, int goal)\
    \ {\n    int n = D.order();\n\n    vector<bool> reachable(n, false); reachable[start]\
    \ = true;\n    vector<int> parent_arc_ids(n, -1);\n    vector<W> dist(n); dist[start]\
    \ = 0;\n\n    using P = pair<W, int>;\n    priority_queue<P, vector<P>, greater<P>>\
    \ Q; Q.emplace(dist[start], start);\n\n    while (!Q.empty()) {\n      P pair\
    \ = Q.top(); Q.pop();\n      W d = pair.first;\n      int v = pair.second;\n\n\
    \      if (dist[v] < d) { continue; }\n\n      for (auto arc_id: D.successors(v))\
    \ {\n        Weighted_Arc<W> arc = D.get_arc(arc_id);\n        if (!reachable[arc.target]\
    \ || dist[arc.target] > dist[v] + arc.weight) {\n          dist[arc.target] =\
    \ dist[v] + arc.weight;\n          reachable[arc.target] = true;\n          parent_arc_ids[arc.target]\
    \ = arc.id;\n          Q.emplace(dist[arc.target], arc.target);\n        }\n \
    \     }\n    }\n\n    if (!reachable[goal]) { throw UnreachableException(); }\n\
    \n    vector<int> path_arc_ids;\n    vector<int> path_vertices{goal}; \n\n   \
    \ while (path_vertices.back() != start) {\n      int arc_id = parent_arc_ids[path_vertices.back()];\n\
    \      auto arc = D.get_arc(arc_id);\n\n      path_arc_ids.emplace_back(arc_id);\n\
    \      path_vertices.emplace_back(arc.source);\n    }\n\n    reverse(path_arc_ids.begin(),\
    \ path_arc_ids.end());\n    reverse(path_vertices.begin(), path_vertices.end());\n\
    \n    return Shortest_Path<W>(path_arc_ids, path_vertices, dist[goal]);\n  }\n\
    }\n"
  dependsOn:
  - Graph/Weighed_Digraph/Weighted_Digraph.hpp
  isVerificationFile: false
  path: Graph/Weighed_Digraph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2025-08-16 20:33:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/graph/Directed_Dijkstra.test.cpp
documentation_of: Graph/Weighed_Digraph/Dijkstra.hpp
layout: document
redirect_from:
- /library/Graph/Weighed_Digraph/Dijkstra.hpp
- /library/Graph/Weighed_Digraph/Dijkstra.hpp.html
title: Graph/Weighed_Digraph/Dijkstra.hpp
---
