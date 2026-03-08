#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include"../../../template/template.hpp"
#include"../../../Graph/Graph/Two_Edge_Connected_Components.hpp"

int main() {
    using namespace graph;

    int N, M; cin >> N >> M;
    Graph G(N);

    for (int j = 0; j < M; j++) {
        int a, b; cin >> a >> b;
        G.add_edge(a, b);
    }

    auto components = Two_Edge_Connected_Components(G);

    cout << components.components.size() << endl;
    for (auto component: components.components) {
        cout << component.size() << " " << component << "\n";
    }
}