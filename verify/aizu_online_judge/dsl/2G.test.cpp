#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include"../../../template/template.hpp"
#include"../../../Binary_Indexed_Tree/Range_Binary_Indexed_Tree.hpp"

int main() {
    int n, q; cin >> n >> q;

    auto add = [](ll x, ll y) -> ll { return x + y; };
    auto neg = [](ll x) -> ll { return -x; };
    auto mul = [](ll k, ll x) -> ll { return k * x; };

    Range_Binary_Indexed_Tree<ll> B(n + 1, add, 0LL, neg, mul);
    for (int r = 1; r <= q; r++) {
        int p; scanf("%d", &p);
        if (p == 0) {
            int s, t; ll x; scanf("%d%d%lld", &s, &t, &x);
            B.add(s, t, x);
        } else if (p == 1) {
            int s, t; scanf("%d%d", &s, &t);
            cout << B.sum(s, t) << "\n";
        }
    }
}