#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include"../../../template/template.hpp"
#include"../../../Algebra/modint.hpp"
#include"../../../Graph/Graph/Triangle.hpp"

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

    auto product = [&x](const int u, const int v, const int w) -> mint {
        return x[u] * x[v] * x[w];
    };

    cout << Triangle<mint>(G, product, add<mint>, 0)<< endl;
}
