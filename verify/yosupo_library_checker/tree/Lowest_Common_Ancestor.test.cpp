#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include"../../../Tree/Tree.hpp"

int main () {
    int N, Q; cin >> N >> Q;
    vector<int> p(N + 1);
    auto T = Tree(N);

    for (int i = 1; i < N; i++) {
        scanf("%d", &p[i]);
        T.set_parent(i, p[i]);
    }

    T.seal();

    for (int q = 0; q < Q; q++) {
        int u, v; scanf("%d%d", &u, &v);
        cout << T.lowest_common_ancestor(u, v) << "\n";
    }
}
