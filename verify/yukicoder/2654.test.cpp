#define PROBLEM "https://yukicoder.me/problems/no/2654"

#include "../../template/template.hpp"
#include "../../Calculate/Slope_Trick.hpp"
#include "../../Data_Structure/Ordered_Multiset.hpp"

const ll inf = intpow(10, 18);

vector<ll> solve() {
    int N; cin >> N;
    auto A = input_vector<ll>(N + 1);

    vector<vector<int>> T(N + 1);
    for (int j = 1; j <= N; ++j) {
        int u, v; cin >> u >> v;
        T[u].emplace_back(v);
        T[v].emplace_back(u);
    }

    Slope_Trick<ll> F;
    Ordered_Multiset<ll> S;
    vector<ll> ans(N + 1, 0);

    auto dfs = [&](auto self, const int v, const int depth, const int par) -> void {
        F.add_abs(A[v]);
        S.insert(A[v]);

        if (depth > 1) {
            // 外れ値として残す 1 個は, C の最小値 l か最大値 r のどちらかにするのが最適
            ll l = S.min(), r = S.max();

            if (l == r) {
                // 全要素が同じ値なので, 外れ値を 1 だけ動かす操作が最低限必要.
                ans[v] = 1;
            } else {
                // l を外れ値として除いたときの, 残り (C \ {l}) を 1 点に揃える最小コスト.
                // ただし最適な揃え先が l 自身と一致してしまう場合は, それでは「異なる値」にならないので, 外れ値を 1 だけ動かす追加コスト +1 が必要になる.
                F.sub_abs(l);
                auto [Ll, Rl] = F.argmin(-inf, inf);
                ll cost_l = F.get_min() + ((Ll == Rl && Ll == l) ? 1 : 0);
                F.add_abs(l);

                // r を外れ値として除いた場合も同様に計算する.
                F.sub_abs(r);
                auto [Lr, Rr] = F.argmin(-inf, inf);
                ll cost_r = F.get_min() + ((Lr == Rr && Lr == r) ? 1 : 0);
                F.add_abs(r);

                ans[v] = min(cost_l, cost_r);
            }
        } else {
            // パスの長さが短すぎて「どれが異なる値か」を一意に決められないので -1.
            ans[v] = -1;
        }

        for (const int w: T[v]) {
            if (w == par) continue;

            self(self, w, depth + 1, v);
        }

        F.sub_abs(A[v]);
        S.erase(A[v]);
    };

    dfs(dfs, 0, 0, -1);
    ans.erase(ans.begin());
    return ans;
}

int main() {
    for (ll val: solve()) {
        cout << val << "\n";
    }
}
