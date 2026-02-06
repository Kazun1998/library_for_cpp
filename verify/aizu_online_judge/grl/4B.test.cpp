#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"

#include"../../../template/template.hpp"
#include"../../../Others/Topological_Sort.hpp"

int main() {
    int n, m; cin >> n >> m;
    Topological_Sort T(n);

    for (int j = 0; j < m; j++) {
        int s, t; cin >> s >> t;
        T.add_arc(s, t);
    }

    auto order = T.sort().value();
    for (auto v: order) cout << v << "\n";
}
