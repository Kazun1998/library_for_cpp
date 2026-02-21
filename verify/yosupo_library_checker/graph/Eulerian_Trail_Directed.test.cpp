#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_directed"

#include "../../../template/template.hpp"
#include "../../../Graph/Digraph/Eulerian_Trail.hpp"

using namespace digraph;

optional<Path> verify() {
    int n, m;
    cin >> n >> m;
    auto D = Digraph(n);
    for (int j = 0; j < m; ++j) {
        int u, v; scanf("%d%d", &u, &v);
        D.add_arc(u, v);
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
        for (int j = 0; j < trail.arcs.size(); ++j) {
            cout << (j ? " " : "") << trail.arcs[j].id;
        }
        cout << "\n";
    }
}
