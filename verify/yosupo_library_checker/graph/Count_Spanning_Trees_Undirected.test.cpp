#define PROBLEM "https://judge.yosupo.jp/problem/counting_spanning_tree_undirected"

#include "../../../template/template.hpp"
#include "../../../Graph/Graph/Count_Spanning_Trees.hpp"
#include "../../../Algebra/modint.hpp"

using namespace graph;
using mint = modint<998244353>;

mint verify() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int j = 0; j < M; ++j) {
        int u, v; cin >> u >> v;
        G.add_edge(u, v);
    }
    return Count_Spanning_Trees<mint>(G);
}

int main() {
    cout << verify() << endl;
}
