#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include"../../../template/template.hpp"
#include"../../../Tree/Subtree_Isomorphism_Hash.hpp"

int main() {
    int N; cin >> N;
    Tree T(N);
    T.set_root(0);
    for (int i = 1; i < N; ++i) {
        int p; scanf("%d", &p);
        T.set_parent(i, p);
    }

    T.seal();
    auto h = Subtree_Isomorphism_Hash(T);

    cout << max(h) + 1 << endl;
    cout << h << endl;
}
