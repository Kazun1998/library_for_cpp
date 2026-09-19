#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../../template/template.hpp"
#include "../../../Interval_Query/Interval_Query.hpp"
#include "../../../Interval_Query/Sqrt_Decomposer.hpp"

using State = ll;

vector<ll> verify() {
    int N, Q; cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    Interval_Query<ll, State> iq(
        a,
        make_unique<Sqrt_Decomposer>(N),
        [](const vector<ll> &sub) {
            State s = 0;
            for (ll v: sub) { s += v; }
            return s;
        },
        [](State &s, int, const ll &before, const ll &after) {
            s += after - before;
        }
    );

    vector<ll> ans;
    for (int q = 0; q < Q; ++q) {
        int t; cin >> t;
        if (t == 0) {
            int p; ll x; cin >> p >> x;
            iq.update(p, iq.get(p) + x);
        } else {
            int l, r; cin >> l >> r;
            ans.push_back(iq.query<ll>(l, r,
                [](const State &s) { return s; },
                [](ll p, ll q) { return p + q; },
                0LL
            ));
        }
    }

    return ans;
}

int main() {
    for (ll val: verify()) {
        cout << val << endl;
    }
}
