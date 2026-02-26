#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include"../../../template/template.hpp"
#include"../../../Algebra/modint.hpp"
#include"../../../Union_Find/Potentilized_Union_Find.hpp"

using mint = modint<998244353>;

int main() {
    int N, Q; cin >> N >> Q;
    Potentilized_Union_Find<mint> U(N, add<mint>, mint(0), neg<mint>);

    for (int q = 0; q < Q; q++) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int u, v, _x; scanf("%d%d%d", &u, &v, &_x);
            mint x = mint::raw(_x);

            if (U.is_possible(u, v, x)) { 
                U.unite(u, v, x);
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (t == 1) {
            int u, v; scanf("%d%d", &u, &v);
            if (U.is_well_defined(u, v)) {
                cout << U.potential(u, v) << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
}
