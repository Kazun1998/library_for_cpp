#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include<bits/stdc++.h>

using namespace std;

#include"../../../Union_Find/Union_Find.hpp"

int main() {
    int N, Q; cin >> N >> Q;
    Union_Find U(N);

    for (int q = 1; q <= Q; q++){
        int t, u, v; scanf("%d%d%d", &t, &u, &v);
        if (t == 0) { U.unite(u, v); }
        else if (t == 1) { cout << U.same(u, v) << "\n"; }
    }
}
