#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../../template/template.hpp"
#include "../../../Segment_Tree/Segment_Tree.hpp"
#include "../../../Segment_Tree/preset/Range_Min.hpp"

int main(){
    int N, Q; cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) { cin >> a[i]; }

    Range_Min_Segment_Tree<int> S(a, numeric_limits<int>::max());

    for (; Q; Q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        cout << S.min(l, r - 1) << "\n";
    }
}
