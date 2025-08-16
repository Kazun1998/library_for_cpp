#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include<bits/stdc++.h>

using namespace std;

#include"../../../Graph/Weighed_Digraph/Dijkstra.hpp"

int main(){
  int N, M, s, t; cin >> N >> M >> s >> t;
  auto D = Weighted_Digraph::Weighted_Digraph<long long>(N);

  for (int j = 0; j < M; j++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    D.add_arc(a, b, c);
  }

  try {
    auto shortest_path = Weighted_Digraph::Dijkstra::Dijkstra(D, s, t);
    cout << shortest_path.length << " " << shortest_path.path_arc_ids.size() << endl;
    auto P = shortest_path.path_vertices;
    for (int j = 0; j < shortest_path.path_arc_ids.size(); j++) {
      cout << P[j] << " " << P[j + 1] << "\n";
    }
  } catch (Weighted_Digraph::Dijkstra::UnreachableException &e) {
    cout << -1 << endl;
  }
}

