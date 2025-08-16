#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include<bits/stdc++.h>

using namespace std;

#include"../../../Binary_Indexed_Tree/Binary_Indexed_Tree.hpp"

int main() {
    int N, Q; cin >> N >> Q;
    vector<long long> a(N);
    for (int i = 0; i < N; i ++) { scanf("%lld", &a[i]); }

    Binary_Indexed_Tree<long long> B = Group_Binary_Indexed_Tree(a, 0LL);
    for (; Q > 0; Q--) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int p, x; scanf("%d%d", &p, &x);
            B.add(p, x);
        } else {
            int l, r; scanf("%d%d", &l, &r);
            cout << B.sum(l, r - 1) << "\n";
        }
    }
}
