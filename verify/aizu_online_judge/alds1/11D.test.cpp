#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D"

#include"../../../template/template.hpp"
#include"../../../Graph/Graph/Connected_Components.hpp"

int main() {
    using namespace graph;

    int N, M; cin >> N >> M;
    Graph G(N);
    for (int j = 0; j < M; j++) {
        int u, v; cin >> u >> v;
        G.add_edge(u, v);
    }

    Connected_Components comp(G);
    int Q; cin >> Q;
    for (int q = 1; q <= Q; q++) {
        int s, t; cin >> s >> t;
        cout << (comp.component_ids[s] == comp.component_ids[t] ? "yes" : "no") << "\n";
    }
}
