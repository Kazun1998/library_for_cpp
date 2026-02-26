#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include"../../../template/template.hpp"
#include"../../../Sequence/Cartesian_Tree.hpp"

int main() {
    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    Cartesian_Tree<int> T(a);
    for (int i = 0; i < N; i++) {
        int p = T.is_root(i) ? i : T.parent[i];
        cout << (i ? " " : "") << p;
    }

    cout << endl;
}
