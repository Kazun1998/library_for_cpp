#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include "../../../template/template.hpp"
#include "../../../Graph/Weighted_Digraph/Warshall_Floyd.hpp"

using namespace digraph;
using namespace weighted_digraph::warshall_floyd;
using Weight = ll;

int V;

Result<Weight> verify() {
    int E; cin >> V >> E;
    Digraph<Weight> D(V);

    for (int j = 0; j < E; j++) {
        int s, t; ll d; cin >> s >> t >> d;
        D.add_arc(s, t, d);
    }

    return Warshall_Floyd<Weight>(D);
}

void export_result(Result<Weight> &result) {
    if (result.has_negative_cycle()) {
        cout << "NEGATIVE CYCLE" << endl;
        return;
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

int main() {
    auto result = verify();
    export_result(result);
}
