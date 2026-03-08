#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"

#include"../../../template/template.hpp"
#include"../../../Graph/Weighted_Graph/Prim.hpp"

using namespace weighted_graph;

int main() {
    int N, M; cin >> N >> M;
    Weighted_Graph<ll> G(N);

    for (int j = 0; j < M; j++) {
        int a, b; ll c;
        scanf("%d%d%lld", &a, &b, &c);
        G.add_edge(a, b, c);
    }

    Minimum_Spanning_Tree T = Prim(G);

    cout << T.weight << endl;
    for (int k = 0; k < T.edges.size(); k++) {
        cout << (k ? " " : "") << T.edges[k]->id;
    }

    cout << "\n";
}
