#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include"../../../Tree/Path_Group_Vertex_Query.hpp"

int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> a(N); cin >> a;

    vector<pair<int, int>> edges(N - 1);
    for (int j = 0; j < N - 1; ++j) {
        int u, v; scanf("%d%d", &u, &v);
        edges[j] = {u, v};
    }

    auto T = Construct_Tree(N, edges, 0);

    auto add = [](const ll &x, const ll &y) -> ll { return x + y; };
    auto neg = [](const ll &x) -> ll { return -x; };

    auto X = Path_Group_Vertex_Query<ll>(T, a, add, 0, neg);

    for (int q = 0; q < Q; q++) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int p; ll x;
            scanf("%d%lld", &p, &x);
            a[p] += x;
            X.update(p, a[p]);
        } else {
            int u, v;
            scanf("%d%d", &u, &v);
            cout << X.query(u, v) << "\n";
        }
    }
}
