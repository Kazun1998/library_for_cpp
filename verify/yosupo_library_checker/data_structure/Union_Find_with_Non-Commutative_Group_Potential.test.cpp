#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group"

#include"../../../template/template.hpp"
#include"../../../Algebra/modint.hpp"
#include"../../../Union_Find/Potentilized_Union_Find.hpp"

using mint = modint<998244353>;

struct Mat2 {
    mint p, q, r, s;

    Mat2() = default;
    Mat2(const mint p, const mint q, const mint r, const mint s): p(p), q(q), r(r), s(s) {}

    friend Mat2 operator*(const Mat2 &x, const Mat2 &y) {
        Mat2 z;

        z.p = x.p * y.p + x.q * y.r;
        z.q = x.p * y.q + x.q * y.s;
        z.r = x.r * y.p + x.s * y.r;
        z.s = x.r * y.q + x.s * y.s;

        return z;
    }

    friend bool operator==(const Mat2 &x, const Mat2 &y) {
        return (x.p == y.p) && (x.q == y.q) && (x.r == y.r) && (x.s == y.s);
    }

    Mat2 inverse() const { return Mat2(s, -q, -r, p); }
};

int main() {
    int N, Q; cin >> N >> Q;
    Potentilized_Union_Find<Mat2> U(N, mul<Mat2>, Mat2(1, 0, 0, 1), [](const Mat2 &a) -> Mat2 { return a.inverse(); } );

    for (int q0 = 0; q0 < Q; q0++) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int u, v, _p, _q, _r, _s;
            scanf("%d%d%d%d%d%d", &u, &v, &_p, &_q, &_r, &_s);
            mint p = mint::raw(_p);
            mint q = mint::raw(_q);
            mint r = mint::raw(_r);
            mint s = mint::raw(_s);
            Mat2 x(p, q, r, s);
            Mat2 x_inv = x.inverse();

            if (U.is_possible(u, v, x_inv)) { 
                U.unite(u, v, x_inv);
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (t == 1) {
            int u, v; scanf("%d%d", &u, &v);
            if (U.is_well_defined(u, v)) {
                Mat2 y_inv = U.potential(u, v); 
                Mat2 y = y_inv.inverse();
                print(y.p, y.q, y.r, y.s);
            } else {
                cout << -1 << "\n";
            }
        }
    }
}
