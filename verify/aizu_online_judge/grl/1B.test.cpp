#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include"../../../template/template.hpp"
#include"../../../Graph/Weighted_Digraph/Bellman_Ford.hpp"

int main() {
    int V, E, r; cin >> V >> E >> r;
    digraph::Digraph<ll> D(V);

    for (int j = 0; j < E; j++) {
        int s, t; ll d; cin >> s >> t >> d;
        D.add_arc(s, t, d);
    }

    auto result = weighted_digraph::bellman_ford::Bellman_Ford(D, r);
    if (result.has_negative_cycle()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    for (int v = 0; v < V; v++) {
        if (result.reachable[v]) {
            cout << result.dist[v] << "\n";
        } else {
            cout << "INF" << "\n";
        }
    }
}
