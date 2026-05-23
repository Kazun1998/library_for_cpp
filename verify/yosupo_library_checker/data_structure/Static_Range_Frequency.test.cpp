#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "../../../template/template.hpp"
#include "../../../Segment_Tree/Persistent_Segment_Tree.hpp"

vector<int> get_uniques(vector<int> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

int get_index(const vector<int>& uniques, int x) {
    auto it = lower_bound(uniques.begin(), uniques.end(), x);
    if (it == uniques.end() || *it != x) return -1;
    return distance(uniques.begin(), it);
}

vector<int> verify() {
    int N, Q; cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) scanf("%d", &a[i]);

    auto uniques = get_uniques(a);

    Persistent_Segment_Tree<int> S(vector<int>(uniques.size(), 0), add<int>, 0);
    for (int i = 0; i < N; ++i) {
        int val_idx = get_index(uniques, a[i]);
        S.increment();
        S.update(val_idx, S.get(i, val_idx) + 1);
    }

    vector<int> ans(Q);
    for (int q = 0; q < Q; ++q) {
        int l, r, x; scanf("%d%d%d", &l, &r, &x);
        int val_idx = get_index(uniques, x);
        if (val_idx == -1) continue;

        ans[q] = S.get(r, val_idx) - S.get(l, val_idx);
    }

    return ans;
}

int main() {
    for (int a: verify()) {
        cout << a << endl;
    }
}