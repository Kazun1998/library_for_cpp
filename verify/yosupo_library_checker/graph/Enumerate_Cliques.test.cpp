#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_cliques"

#include"../../../template/template.hpp"
#include"../../../Algebra/modint.hpp"
#include"../../../Graph/Graph/Enumerate_Cliques.hpp"

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

    mint res(0);
    for (auto clique: Enumerate_Cliques(G)) {
        mint prod = 1;
        for (int v: clique) prod *= x[v];
        res += prod;
    }

    cout << res << endl;
}
