#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include"../../../Tree/Centroid_Decomposition.hpp"

vector<ll> verify() {
    int N; cin >> N;

    vector<pair<int, int>> edges(N - 1);
    for (auto &[u, v]: edges) {
        cin >> u >> v;
    }

    vector<vector<int>> adj(N);
    for (auto &[u, v]: edges) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    Centroid_Decomposition CD(N, edges);
    vector<bool> removed(N, false);

    vector<ll> answer(N, 0);

    // c を根とする (removed でない) 連結成分について,
    // c からの距離のリストを depths に追加する.
    auto collect_depths = [&](int c) {
        vector<int> depths;
        auto dfs = [&](auto self, int x, int p, int d) -> void {
            depths.emplace_back(d);
            for (int y: adj[x]) {
                if (y == p || removed[y]) { continue; }
                self(self, y, x, d + 1);
            }
        };
        dfs(dfs, c, -1, 0);
        return depths;
    };

    // depths (先頭が距離 0 の c 自身) から
    // 「c を経由する 2 頂点間の距離の個数」を answer に加算する.
    // sign = +1 なら加算, -1 なら減算 (包除原理: 全体 - 各子部分木内のみで完結する分).
    auto add_pair_counts = [&](const vector<int> &depths, int sign) {
        vector<ll> cnt(depths.empty() ? 0 : *max_element(depths.begin(), depths.end()) + 1, 0);
        for (int d: depths) { cnt[d]++; }

        // 距離の和 (i + j) ごとにペア数を畳み込む (O(K^2) で十分小さい).
        for (int i = 0; i < (int)cnt.size(); i++) {
            if (cnt[i] == 0) { continue; }
            for (int j = i; j < (int)cnt.size(); j++) {
                if (cnt[j] == 0) { continue; }
                ll pairs;
                if (i == j) {
                    pairs = cnt[i] * (cnt[i] - 1) / 2;
                } else {
                    pairs = cnt[i] * cnt[j];
                }
                int dist = i + j;
                if (dist < (int)answer.size()) {
                    answer[dist] += sign * pairs;
                }
            }
        }
    };

    for (int c: CD.order()) {
        // c を含む連結成分全体でのペア (c を通るもの) を数える.
        auto depths_all = collect_depths(c);
        add_pair_counts(depths_all, +1);

        // 子ごとの部分木内で完結するペアを除く (2 重に数えないようにする).
        removed[c] = true;
        for (int y: adj[c]) {
            if (removed[y]) { continue; }
            auto depths_child = collect_depths(y);
            for (int &d: depths_child) { d += 1; }
            add_pair_counts(depths_child, -1);
        }
    }

    return answer;
}

int main () {
    vector<ll> answer = verify();
    for (int v = 1; v < (int)answer.size(); v++) {
        cout << answer[v] << (v + 1 < (int)answer.size() ? " " : "\n");
    }
}
