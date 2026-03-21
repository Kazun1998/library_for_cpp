#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include"../../../template/template.hpp"
#include"../../../Algebra/modint.hpp"
#include"../../../Segment_Tree/preset/Range_Composite_Range_Sum.hpp"

using mint = modint<998244353>;

int main(){
    int N, Q; cin >> N >> Q;

    vector<mint> a(N);
    for (int i = 0; i < N; i++){
        int x; scanf("%d", &x);
        a[i] = x;
    }

    Range_Composite_Range_Min_Lazy_Segment_Tree<mint> S(a);

    for (int q = 0; q < Q; q++){
        int t, l, r;
        scanf("%d", &t);

        if (t == 0){
            int b, c;
            scanf("%d%d%d%d", &l, &r, &b, &c);
            S.composite(l, r - 1, c, b);
        } elif (t == 1) {
            scanf("%d%d", &l, &r);
            cout << S.sum(l, r - 1) << "\n";
        }
    }
}
