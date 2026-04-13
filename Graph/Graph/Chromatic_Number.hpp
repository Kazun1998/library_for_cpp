#pragma once

#include "Graph.hpp"
#include "../../Convolution/Bitwise_Or_Convolution.hpp"

namespace graph {
    int Chromatic_Number(const Graph &G) {
        int n = G.order();
        if (n == 0) return 0;

        using namespace convolution;
        using Conv = Bitwise_Or_Convolution<long long>;
        const vector<vector<int>> adj = G.adjacency_matrix();

        // Section I: dp[1][S] を求める. (S が独立集合なら 1, そうでなければ 0)
        Conv indep(vector<long long>(1 << n, 0));
        indep[0] = 1;

        for (int S = 1; S < (1 << n); ++S) {
            int x = lowest_bit(S); // ビットのインデックスを取得
            int Sx = S ^ (1 << x);

            if (indep[Sx] == 0) continue;

            bool is_indep = true;
            for (int y = 0; y < n; y++) {
                if (((Sx >> y) & 1) && adj[x][y]) {
                    is_indep = false;
                    break;
                }
            }
            if (is_indep) indep[S] = 1;
        }

        // 空グラフの彩色数は 1
        if (indep[(1 << n) - 1] == 1) return 1;

        auto clamp = [&](Conv &c) {
            for (int S = 0; S < (1 << n); ++S) {
                c[S] = c[S] > 0 ? 1 : 0;
            }
        };

        // Section II: k = 2, 4, 8, ... に対して, dp
        vector<Conv> dp(2 * n, Conv());
        dp[1] = indep;
        int k = 1;
        for (; 2 * k <= n; k *= 2) {
            dp[2 * k] = dp[k] * dp[k];
            clamp(dp[2 * k]);
            if (dp[2 * k][(1 << n) - 1]) break;
        }

        // Section III: 二分探索によって彩色数を求める
        Conv prev = dp[k];
        int step = k >> 1;

        for (; step > 0; step >>= 1) {
            if (k + step > n) continue;

            // prev (dp[k_current]) と dp[step] を畳み込むことで dp[k_current + step] を得る
            Conv res = prev * dp[step];
            
            clamp(res);

            dp[k + step] = res;

            unless(res[(1 << n) - 1]) {
                k += step;
                prev = res;
            }
        }

        return k + 1;
    }
}
