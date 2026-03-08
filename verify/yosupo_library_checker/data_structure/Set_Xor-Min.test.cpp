#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include"../../../template/template.hpp"
#include"../../../Data_Structure/Binary_Trie.hpp"

int main() {
    int Q; cin >> Q;
    Binary_Trie<int> B(30);

    for (int q = 0; q < Q; q++) {
        int t; scanf("%d", &t);
        if (t == 0) {
            int x; scanf("%d", &x);
            B.insert(x);
        } else if (t == 1) {
            int x; scanf("%d", &x);
            B.discard(x);
        } else if (t == 2) {
            int x; scanf("%d", &x);
            B.act_xor(x);
            cout << B.get_min() << "\n";
            B.act_xor(x);
        }
    }
}
