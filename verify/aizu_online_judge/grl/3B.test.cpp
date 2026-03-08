#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B"

#include"../../../template/template.hpp"
#include"../../../Graph/Graph/Lowlink.hpp"

int main() {
    using namespace graph;

    int N, M; cin >> N >> M;
    Graph G(N);

    vector<pair<int, int>> edges(M);
    for (int j = 0; j < M; j++) {
        int s, t; cin >> s >> t;
        if (s > t) { swap(s, t); }
        edges[j] = {s, t};
        G.add_edge(s, t);
    }

    Lowlink lowlink(G);
    vector<pair<int, int>> bridges;
    for (int j = 0; j < M; j++) {
        if (lowlink.bridge[j]) { bridges.emplace_back(edges[j]); }
    }

    sort(bridges.begin(), bridges.end());

    for (auto edge: bridges) {
        cout << edge << endl;
    }
}
