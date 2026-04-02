#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include"../../../template/template.hpp"
#include"../../../Algebra/modint.hpp"
#include"../../../Data_Structure/Sliding_Window_Aggregation.hpp"

using mint = modint<998244353>;
using M = pair<mint, mint>;

M op(const M f, const M g) {
    return { f.first * g.first, f.second * g.first + g.second};
}

constexpr M id = make_pair<mint, mint>(mint(1), mint(0));

vector<mint> verify() {
    int Q; cin >> Q;
    Sliding_Window_Aggregation<M, op, id> S;

    vector<mint> ans;
    for (int q = 1; q <= Q; ++q) {
        int mode; scanf("%d", &mode);
        if (mode == 0) {
            int _a, _b; scanf("%d%d", &_a, &_b);
            mint a(_a), b(_b);
            S.push_back({a, b});
        } else if (mode == 1) {
            S.pop_front();
        } else if (mode == 2) {
            int _x; scanf("%d", &_x);
            mint x(_x);
            auto &&[a, b] = S.product();
            ans.emplace_back(a * x + b);
        }
    }

    return ans;
}

int main() {
    for (const auto &ans: verify()) {
        cout << ans << "\n";
    }
}
