#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include"../../../template/template.hpp"
#include"../../../Segment_Tree/preset/Range_Add_Range_Sum.hpp"

int main() {
    int n, q; cin >> n >> q;

    Range_Add_Range_Sum_Lazy_Segment_Tree<ll> S(n + 1);
    for (int r = 1; r <= q; r++) {
        int p; scanf("%d", &p);
        if (p == 0) {
            int s, t; ll x; scanf("%d%d%lld", &s, &t, &x);
            S.add(s, t, x);
        } else if (p == 1) {
            int s, t; scanf("%d%d", &s, &t);
            cout << S.sum(s, t) << "\n";
        }
    }
}
