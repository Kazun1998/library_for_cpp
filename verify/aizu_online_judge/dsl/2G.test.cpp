#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include"../../../template/template.hpp"
#include"../../../Binary_Indexed_Tree/Range_Binary_Indexed_Tree.hpp"

int main() {
    int n, q; cin >> n >> q;

    Range_Binary_Indexed_Tree<ll> B(n + 1, add<ll>, 0LL, neg<ll>, mul<ll>);
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