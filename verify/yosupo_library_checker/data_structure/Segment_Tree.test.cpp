#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include<bits/stdc++.h>

using namespace std;

#include"../../../Segment_Tree/Segment_Tree.hpp"

int main(){
    int N, Q; cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) { cin >> a[i]; }

    auto op = [](int x, int y) -> int { return min(x, y); };
    int unit = numeric_limits<int>::max();

    Segment_Tree<int> S(a, op, unit);

    for (; Q; Q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        cout << S.product(l, r - 1) << "\n";
    }
}
