#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include"template/template.hpp"
#include"Algebra/modint.hpp"
#include"Tree/Generator.hpp"
#include"Tree/Rerooting.hpp"

using mint = modint<998244353>;

struct X {
    mint p;
    int subtree_size;
};

struct M {
    mint q;
    int subtree_size;
};

int main() {
    int N; cin >> N;

    vector<pair<int, int>> edges(N - 1);
    vector<mint> a(N);
    map<pair<int, int>, pair<mint, mint>> edge_function;

    for (int i = 0; i < N; i++) { int x; scanf("%d", &x); a[i] = mint(x); }
    for (int j = 0; j < N - 1; j++) {
        int u, v, x, y;
        scanf("%d%d%d%d", &u, &v, &x, &y);
        mint b(x), c(y);

        if (u > v) { swap(u, v); }
        edge_function[{u, v}] = { b, c };
        edges[j] = { u, v };
    }

    Tree T = Generate_Tree(N, edges, 0);

    function<M(X, int, int)> f = [&edge_function](const X x, int u, int v) -> M {
        if (u > v) { swap(u, v); }
        const auto &[b, c] = edge_function[{u, v}];

        return { b * x.p + c * x.subtree_size, x.subtree_size };
    };

    function<X(M, int)> g = [&a](const M s, const int v) -> X {
        return { s.q + a[v], s.subtree_size + 1};
    };

    function<M(M, M)> merge = [](const M s, const M t) -> M {
        return { s.q + t.q, s.subtree_size + t.subtree_size};
    };

    Rerooting_DP<X, M> rerooting(T, f, g, merge, {0, 0});

    for (int v = 0; v < N; v++) {
        cout << (v ? " " : "") << rerooting.result[v].p;
    }
}
