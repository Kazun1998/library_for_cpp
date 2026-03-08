#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"

#include"../../../template/template.hpp"
#include"../../../Data_Structure/AVL_Tree.hpp"

int main() {
    int N, Q; cin >> N >> Q;
    Adelson_Velsky_and_Landis_Tree<int, int> S;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        S.insert(a);
    }

    for (int q = 0; q < Q; q++) {
        int t, x; scanf("%d%d", &t, &x);
        if (t == 0) {
            S.insert(x);
        } else if (t == 1) {
            S.discard(x);
        } else if (t == 2) {
            int res = (x <= S.size()) ? S.kth_key(x - 1) : -1;
            cout << res << "\n";
        } else if (t == 3) {
            cout << S.less_count(x, true) << "\n";
        } else if (t == 4) {
            cout << S.previous(x, -1, true) << "\n";
        } else if (t == 5) {
            cout << S.next(x, -1, true) << "\n";
        }
    }
}
