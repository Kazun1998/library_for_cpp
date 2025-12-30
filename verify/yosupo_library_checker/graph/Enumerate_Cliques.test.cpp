#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_cliques"

#include"../../../template/template.hpp"
#include"../../../Algebra/modint.hpp"
#include"../../../Graph/Graph/Cliques.hpp"

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

    auto product = [&x](const vector<int> &C) -> mint {
        mint res = 1;
        for (int v: C) {
            res *= x[v];
        }

        return res;
    };

    cout << Cliques<mint>(G, product, add<mint>, 0)<< endl;
}
