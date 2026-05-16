#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include"../../../Tree/Lowest_Common_Ancestor.hpp"

int main () {
    int N, Q; cin >> N >> Q;
    vector<int> p(N);
    auto T = Tree(N);

    T.set_root(0);
    for (int i = 1; i < N; i++) {
        scanf("%d", &p[i]);
        T.set_parent(i, p[i]);
    }

    T.seal();

    Lowest_Common_Ancestor L(T);

    for (int q = 0; q < Q; q++) {
        int u, v; scanf("%d%d", &u, &v);
        cout << L.lowest_common_ancestor(u, v) << "\n";
    }
}
