#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include"../../../template/template.hpp"
#include"../../../Tree/Tree.hpp"

int main() {
    int N, Q; cin >> N >> Q;

    vector<pair<int, int>> edges(N - 1);
    for (int j = 0; j <= N - 2; j++) {
        int u, v;
        scanf("%d%d", &u, &v);
        edges[j] = make_pair(u, v);
    }

    Tree T = Construct_Tree(N, edges, 0);
    for (int q = 0; q < Q; q++) {
        int s, t, i;
        scanf("%d%d%d", &s, &t, &i);
        cout << T.jump(s, t, i) << "\n";
    }
}
