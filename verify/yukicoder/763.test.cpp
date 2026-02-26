#define PROBLEM "https://yukicoder.me/problems/no/763"

#include"../../template/template.hpp"
#include"../../Tree/Generator.hpp"
#include"../../Tree/Tree_DP.hpp"

int main() {
    int N; cin >> N;

    vector<pair<int, int>> edges(N - 1);
    for (int j = 0; j < N - 1; j++) {
        int u, v; scanf("%d%d", &u, &v);
        edges[j] = {u, v};
    }

    int root = 1;
    Tree T = Generate_Tree(N, edges, root, 1);

    using M = pair<int, int>;
    using X = pair<int, int>;

    function<M(X, int, int)> f = [](const M a, const int v, const int w) -> M {
        return { max(a.first, a.second), max(a.first, a.second - 1) };
    };

    function<X(M, int)> g = [](const M a, const int v) -> X { return { a.first, a.second + 1}; };

    function<M(M, M)> merge = [](const M a, const M b) -> M {
        return { a.first + b.first, a.second + b.second };
    };

    vector<X> data = Tree_DP_from_Leaf(T, f, g, merge, {0, 0});
    cout << max(data[root].first, data[root].second) << endl;
}
