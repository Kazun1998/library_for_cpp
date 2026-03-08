#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include"../../../template/template.hpp"
#include"../../../Max_Flow/Max_Flow.hpp"

int main() {
    int N, M; cin >> N >> M;
    max_flow::Max_Flow<int> F(N);

    for (int j = 0; j < M; j++) {
        int u, v, c; cin >> u >> v >> c;
        F.add_arc(u, v, c);
    }

    cout << F.max_flow(0, N - 1) << endl;
}
