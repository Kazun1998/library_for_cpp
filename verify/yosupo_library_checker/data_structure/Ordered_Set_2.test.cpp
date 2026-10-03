#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"

#include"../../../template/template.hpp"
#include"../../../Data_Structure/Ordered_Set.hpp"

int main() {
    int N, Q; cin >> N >> Q;
    Ordered_Set<int> S;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        S.insert(a);
    }

    for (int q = 0; q < Q; q++) {
        int t, x; scanf("%d%d", &t, &x);
        if (t == 0) {
            S.insert(x);
        } else if (t == 1) {
            S.erase(x);
        } else if (t == 2) {
            int res = (x <= S.size()) ? S[x - 1] : -1;
            cout << res << "\n";
        } else if (t == 3) {
            cout << S.count_less(x, true) << "\n";
        } else if (t == 4) {
            cout << S.previous(x, true).value_or(-1) << "\n";
        } else if (t == 5) {
            cout << S.next(x, true).value_or(-1) << "\n";
        }
    }
}
