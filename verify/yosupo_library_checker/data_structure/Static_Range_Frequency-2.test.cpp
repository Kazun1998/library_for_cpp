#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "../../../template/template.hpp"
#include "../../../Interval_Query/Interval_Query.hpp"
#include "../../../Interval_Query/Binary_Decomposer.hpp"

using State = unordered_map<int, int>;

vector<int> verify() {
    int N, Q; cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) scanf("%d", &a[i]);

    Interval_Query<int, State> iq(
        a,
        make_unique<Binary_Decomposer>(N),
        [](const vector<int> &sub) {
            State s;
            for (int v: sub) { s[v]++; }
            return s;
        },
        [](vector<State> &children) {
            // small-to-large: 一番大きい map に残りを merge する
            int biggest = 0;
            for (int i = 1; i < (int)children.size(); i++) {
                if (children[i].size() > children[biggest].size()) { biggest = i; }
            }
            State s = move(children[biggest]);
            for (int i = 0; i < (int)children.size(); i++) {
                if (i == biggest) { continue; }
                for (auto &[v, c]: children[i]) { s[v] += c; }
            }
            return s;
        },
        [](State &s, int, const int &before, const int &after) {
            if (--s[before] == 0) { s.erase(before); }
            s[after]++;
        }
    );

    vector<int> ans(Q);
    for (int q = 0; q < Q; ++q) {
        int l, r, x; scanf("%d%d%d", &l, &r , &x);
        ans[q] = iq.query<int>(l, r,
            [x](const State &s) {
                auto it = s.find(x);
                return it == s.end() ? 0 : it->second;
            },
            [](int p, int qq) { return p + qq; },
            0
        );
    }

    return ans;
}

int main() {
    for (int val: verify()) {
        printf("%d\n", val);
    }
}
