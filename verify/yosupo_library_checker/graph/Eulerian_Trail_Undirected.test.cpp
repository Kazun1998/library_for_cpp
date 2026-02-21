
#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_undirected"

#include "../../../template/template.hpp"
#include "../../../Graph/Graph/Eulerian_Trail.hpp"

using namespace graph;

optional<Path> verify() {
    int n, m;
    cin >> n >> m;
    auto D = Graph(n);
    for (int j = 0; j < m; ++j) {
        int u, v; scanf("%d%d", &u, &v);
        D.add_edge(u, v);
    }

    return Eulerian_Trail(D);
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; ++t) {
        auto pre_trail = verify();
        if (pre_trail == nullopt) {
            cout << "No" << "\n";
            continue;
        }

        Path trail = pre_trail.value();
        cout << "Yes" << "\n";

        cout << trail.vertices << "\n";
        for (int j = 0; j < trail.edges.size(); ++j) {
            cout << (j ? " " : "") << trail.edges[j].id;
        }
        cout << "\n";
    }
}
