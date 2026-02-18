#pragma once
#include"Weighted_Digraph.hpp"

namespace weighted_digraph::dijkstra {
    class UnreachableException : public exception {
      public: // publicに指定
      const char* what() const noexcept override { return "求めるパスが存在しません"; }
    };

  template<typename W>
  struct Shortest_Path {
    vector<int> path_arc_ids;
    vector<int> path_vertices;
    W length;

    Shortest_Path<W>(vector<int> path_arc_ids, vector<int> path_vertices, W length):
      path_arc_ids(path_arc_ids), path_vertices(path_vertices), length(length) {}
  };

  template<typename W>
  Shortest_Path<W> Dijkstra(Weighted_Digraph<W> &D, int start, int goal) {
    int n = D.order();

    vector<bool> reachable(n, false); reachable[start] = true;
    vector<int> parent_arc_ids(n, -1);
    vector<W> dist(n); dist[start] = 0;

    using P = pair<W, int>;
    priority_queue<P, vector<P>, greater<P>> Q; Q.emplace(dist[start], start);

    while (!Q.empty()) {
      P pair = Q.top(); Q.pop();
      W d = pair.first;
      int v = pair.second;

      if (dist[v] < d) { continue; }

      for (auto arc_id: D.successors(v)) {
        Weighted_Arc<W> arc = D.get_arc(arc_id);
        if (!reachable[arc.target] || dist[arc.target] > dist[v] + arc.weight) {
          dist[arc.target] = dist[v] + arc.weight;
          reachable[arc.target] = true;
          parent_arc_ids[arc.target] = arc.id;
          Q.emplace(dist[arc.target], arc.target);
        }
      }
    }

    if (!reachable[goal]) { throw UnreachableException(); }

    vector<int> path_arc_ids;
    vector<int> path_vertices{goal}; 

    while (path_vertices.back() != start) {
      int arc_id = parent_arc_ids[path_vertices.back()];
      auto arc = D.get_arc(arc_id);

      path_arc_ids.emplace_back(arc_id);
      path_vertices.emplace_back(arc.source);
    }

    reverse(path_arc_ids.begin(), path_arc_ids.end());
    reverse(path_vertices.begin(), path_vertices.end());

    return Shortest_Path<W>(path_arc_ids, path_vertices, dist[goal]);
  }
}
