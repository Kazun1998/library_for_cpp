#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include "../../../template/template.hpp"
#include "../../../Min_Cost_Flow/Min_Cost_Flow.hpp"

int main() {
    int V, E, F; cin >> V >> E >> F;
    min_cost_flow::Min_Cost_Flow<int, int> X(V);

    for (int j = 0; j < E; ++j) {
        int u, v, c, d; cin >> u >> v >> c >> d;
        X.add_arc(u, v, c, d);
    }

    cout << X.flow(0, V - 1, F).value_or(-1) << endl;
}
