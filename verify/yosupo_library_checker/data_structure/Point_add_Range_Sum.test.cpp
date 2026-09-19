#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../../template/template.hpp"
#include "../../../Segment_Tree/Segment_Tree.hpp"
#include "../../../Segment_Tree/preset/Range_Sum.hpp"

vector<ll> verify() {
    int N, Q; cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) { cin >> a[i]; }

    Range_Sum_Segment_Tree<ll> S(a);

    vector<ll> ans;
    for (; Q; Q--) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int p; ll x; scanf("%d%lld", &p, &x);
            S.update(p, S.get(p) + x);
        } else {
            int l, r; scanf("%d%d", &l, &r);
            ans.emplace_back(S.sum(l, r - 1));
        }
    }

    return ans;
}

int main(){
    for (ll val: verify()) {
        cout << val << "\n";
    }
}
