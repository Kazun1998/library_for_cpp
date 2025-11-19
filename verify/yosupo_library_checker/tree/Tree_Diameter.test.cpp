#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include"../../../template/template.hpp"
#include"../../../Tree/Generator.hpp"
#include"../../../Tree/Tree_DP.hpp"

int main() {
    int N; cin >> N;

    vector<pair<int, int>> edges(N - 1);
    map<pair<int, int>, ll> edge_weight;
    for (int j = 0; j < N - 1; j++) {
        int a, b; ll c; scanf("%d%d%lld", &a, &b, &c);
        edges[j] = {a, b};
        edge_weight[{a, b}] = c;
        edge_weight[{b, a}] = c;
    }

    function<ll(ll, int, int)> f = [&edge_weight](const ll w, const int x, const int y) -> ll {
        return w + edge_weight[{x, y}];
    };

    Tree T1 = Generate_Tree(N, edges, 0);
    vector<ll> dist_1 = Tree_DP_from_Root(T1, f, 0LL);

    int s = 0;
    for (int v = 0; v < N; v++) {
        if (dist_1[s] < dist_1[v]) { s = v; }
    }

    Tree T2 = Generate_Tree(N, edges, s);
    vector<ll> dist_2 = Tree_DP_from_Root(T2, f, 0LL);

    int t = 0;
    for (int v = 0; v < N; v++) {
        if (dist_2[t] < dist_2[v]) { t = v; }
    }

    vector<int> path = T1.path(s, t);
    ll X = dist_2[t];
    int Y = path.size();

    cout << X << " " << Y << endl;
    for (int i = 0; i < path.size(); i++) {
        cout << (i ? " " : "") << path[i];
    }
}
