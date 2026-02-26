#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include"../../../template/template.hpp"
#include"../../../Algebra/modint.hpp"
#include"../../../Graph/Graph/Enumerate_Triangles.hpp"

using namespace graph;
using mint = modint<998244353>;

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);

    vector<mint> x(N); cin >> x;

    for (int j = 0; j < M; j++) {
        int u, v; cin >> u >> v;
        G.add_edge(u, v);
    }

    mint ans = 0;
    for (auto &[u, v, w]: Enumerate_Triangles(G)) {
        ans += x[u] * x[v] * x[w];
    }

    cout << ans << endl;
}
