#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include"../../../Graph/Graph/Chromatic_Number.hpp"

using namespace graph;

int verify() {
    int N, M; cin >> N >> M;
    Graph G(N);
    for (int j = 0; j < M; ++j) {
        int u, v; cin >> u >> v;
        G.add_edge(u, v);
    }

    return Chromatic_Number(G);
}

int main(){
    cout << verify() << endl;
}
