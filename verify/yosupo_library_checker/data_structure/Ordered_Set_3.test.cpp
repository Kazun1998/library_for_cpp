#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"

#include"../../../template/template.hpp"
#include"../../../Data_Structure/Treap.hpp"

int main() {
    int N, Q; cin >> N >> Q;
    Treap<int> T;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        T.insert(a);
    }

    for (int q = 0; q < Q; q++) {
        int t, x; scanf("%d%d", &t, &x);
        if (t == 0) {
            T.insert(x);
        } else if (t == 1) {
            T.erase(x);
        } else if (t == 2) {
            int res = (x <= T.size()) ? T[x - 1] : -1;
            cout << res << "\n";
        } else if (t == 3) {
            cout << T.count_less(x, true) << "\n";
        } else if (t == 4) {
            cout << T.previous(x, true).value_or(-1) << "\n";
        } else if (t == 5) {
            cout << T.next(x, true).value_or(-1) << "\n";
        }
    }
}
