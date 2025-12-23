#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include"../../../template/template.hpp"
#include"../../../Math/Interval_Product.hpp"

int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) scanf("%lld", &a[i]);

    interval_product::Interval_Product<ll, add<ll>, neg<ll>, 0LL> I(a);

    for (int q = 1; q <= Q; q++) {
        int l, r; scanf("%d%d", &l, &r);
        cout << I.query(l, r - 1) << "\n";
    }
}
