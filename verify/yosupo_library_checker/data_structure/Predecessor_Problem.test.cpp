#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include"../../../template/template.hpp"
#include"../../../Data_Structure/Ordered_Set.hpp"

void verify() {
    int N, Q; cin >> N >> Q;
    
    Ordered_Set<int> S;
    {
        string T; cin >> T;
        for (int i = 0; i < N; i++) {
            if (T[i] == '1') S.insert(i);
        }
    }

    for (int q = 0; q < Q; q++) {
        int c, k; scanf("%d%d", &c, &k);
        if (c == 0) {
            S.insert(k);
        } else if (c == 1) {
            S.erase(k);
        } else if (c == 2) {
            cout << S.contains(k) << "\n";
        } else if (c == 3) {
            cout << S.next(k, true).value_or(-1) << "\n";
        } else if (c == 4) {
            cout << S.previous(k, true).value_or(-1) << "\n";
        }
    }
}

int main() {
    verify();
}
