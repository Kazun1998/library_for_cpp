#define PROBLEM "https://judge.yosupo.jp/problem/static_range_count_distinct"

#include"../../../template/template.hpp"
#include"../../../Queries/Mo.hpp"

void compress(vector<int> &a) {
    unordered_map<int, int> map;
    for (int i = 0; i < a.size(); ++i) {
        if (map.contains(a[i])) a[i] = map[a[i]];
        else {
            a[i] = map[a[i]] = map.size();
        }
    }
}

vector<int> verify() {
    int N, Q; cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) scanf("%d", &a[i]);

    Mo M(N + 1);
    for (int q = 0; q < Q; ++q) {
        int l, r; scanf("%d%d", &l, &r);
        M.add_query(l, r - 1);
    }

    compress(a);

    vector<int> count(N, 0);
    int cand = 0;
    vector<int> ans(Q);

    auto add = [&](const int i) -> void {
        if (count[a[i]] == 0) cand++;

        count[a[i]]++;
    };

    auto del = [&](const int i) -> void {
        count[a[i]]--;

        if (count[a[i]] == 0) cand--;
    };

    auto rem = [&](const int q) -> void {
        ans[q] = cand;
    };

    M.run(add, del, rem);
    return ans;
}

int main() {
    for (auto val: verify()) {
        cout << val << "\n";
    }
}
