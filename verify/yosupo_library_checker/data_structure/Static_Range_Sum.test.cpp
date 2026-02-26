#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include"../../../template/template.hpp"
#include"../../../Data_Structure/Disjoint_Sparse_Table.hpp"

int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> a(N); cin >> a;

    Disjoint_Sparse_Table<ll> S(a, add<ll>, 0);

    for (int q = 1; q <= Q; q++) {
        int l, r; scanf("%d%d", &l, &r);
        cout << S.product(l, r - 1) << "\n";
    }
}
