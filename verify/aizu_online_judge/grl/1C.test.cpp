#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include"../../../template/template.hpp"
#include"../../../Graph/Weighted_Digraph/Warshall_Floyd.hpp"

int main() {
    int V, E; cin >> V >> E;
    digraph::Digraph<ll> D(V);

    for (int j = 0; j < E; j++) {
        int s, t; ll d; cin >> s >> t >> d;
        D.add_arc(s, t, d);
    }

    auto result = weighted_digraph::warshall_floyd::Warshall_Floyd(D);
    if (result.has_negative_cycle()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (v) { cout << " "; }

            if (result.is_reachable(u, v)) {
                cout << result.distance(u, v);
            } else {
                cout << "INF";
            }
        }
        cout << "\n";
    }
}
