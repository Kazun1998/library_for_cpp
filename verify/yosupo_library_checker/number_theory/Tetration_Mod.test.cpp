#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"

#include"../../../template/template.hpp"
#include"../../../Modulo/Tower.hpp"

using namespace modulo;

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; ++t) {
        ll a, b, m; cin >> a >> b >> m;
        cout << Tetoration(a, b, m).a << endl;
    }
}
