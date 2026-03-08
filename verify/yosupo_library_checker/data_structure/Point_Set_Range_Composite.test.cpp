#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include"../../../template/template.hpp"
#include"../../../Algebra/modint.hpp"
#include"../../../Segment_Tree/Segment_Tree.hpp"

using mint = modint<998244353>;
using M = pair<mint, mint>;

int main() {
    int N, Q; cin >> N >> Q;
    vector<M> f(N);
    for (int i = 0; i < N; i++) {
        int a, b; scanf("%d%d", &a, &b);
        f[i] = {a, b};
    }

    auto op = [](M f, M g) -> M {
        mint a = f.first * g.first;
        mint b = g.first * f.second + g.second;
        return { a, b };
    };

    M unit = {1, 0};

    Segment_Tree<M> S(f, op, unit);

    for (int q = 0; q < Q; q++) {
        int t;  scanf("%d", &t);
        if (t == 0) {
            int p, c, d; scanf("%d%d%d", &p, &c, &d);
            S.update(p, {c, d});
        } else if (t == 1) {
            int l, r, x; scanf("%d%d%d", &l, &r, &x);
            M h = S.product(l, r - 1);
            cout << h.first * x + h.second << "\n";
        }
    }
}
