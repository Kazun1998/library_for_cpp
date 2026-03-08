#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include"../../../Tree/Subtree_Monoid_Vertex_Query.hpp"

int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> a(N); cin >> a;

    Tree T(N);

    T.set_root(0);
    for (int i = 1; i < N; i++) {
        int p; cin >> p;
        T.set_parent(i, p);
    }

    T.seal();

    auto add = [](const ll &x, const ll &y) -> ll { return x + y; };
    Subtree_Monoid_Vertex_Query<ll> X(T, a, add, 0LL);

    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 0) {
            int u; ll x;
            cin >> u >> x;
            a[u] += x;
            X.update(u, a[u]);
        } else {
            int u; cin >> u;
            cout << X.query(u) << "\n";
        }
    }
}
