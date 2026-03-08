#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A"

#include"../../../template/template.hpp"
#include"../../../Graph/Graph/Lowlink.hpp"

int main() {
    using namespace graph;

    int N, M; cin >> N >> M;
    Graph G(N);

    rep(M) {
        int s, t; cin >> s >> t;
        G.add_edge(s, t);
    }

    Lowlink lowlink(G);

    vector<int> articulations;
    for (int x = 0; x < N; x++) {
        if (lowlink.articulation[x]) { cout << x << endl; }
    }
}
