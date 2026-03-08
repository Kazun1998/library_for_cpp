#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include"../../../Algebra/modint.hpp"
#include"../../../Segment_Tree/Dual_Segment_Tree.hpp"

using mint = modint<998244353>;
using F = pair<mint, mint>;

int main() {
    int N, Q; cin >> N >> Q;
    vector<mint> a(N);

    for (int i = 0; i < N; i++) {
        int _a; scanf("%d", &_a);
        a[i] = _a;
    }

    auto comp = [](const F &f, const F &g) -> F {
        return { f.first * g.first, f.second + f.first * g.second };
    };

    Dual_Segment_Tree<F> D(N, comp, {1, 0});
    for (int q = 0; q < Q; ++q) {
        int t; scanf("%d", &t);

        if (t == 0) {
            int l, r, _b, _c; scanf("%d%d%d%d", &l, &r, &_b, &_c);
            mint b(_b), c(_c);
            D.action(l, r - 1, {b, c});
        } else if (t == 1) {
            int i; scanf("%d", &i);
            auto &[b, c] = D[i];
            cout << b * a[i] + c << "\n";
        }
    }
}
