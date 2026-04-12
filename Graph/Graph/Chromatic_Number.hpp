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

        // Section I: dp[1][S] を求める. (iff S は独立集合?)
        Conv indep(vector<long long>(1 << n, 1));

        for (int S = 1; S < (1 << n); ++S) {
            int x = lowest_bit(S); // ビットのインデックスを取得
            int Sx = S ^ (1 << x);

            if (indep[Sx] == 0) {
                indep[S] = 0;
                continue;
            }

            for (int y = 0; y < n; y++) {
                if (((Sx >> y) & 1) && adj[x][y]) {
                    indep[S] = 0;
                    break;
                }
            }
        }

        if (indep[(1 << n) - 1]) return 1;

        // k 色で彩色可能か包除原理で判定 ( I^k(V) > 0 かを確認 )
        vector<Conv> dp{Conv(), indep};
        for (int k = 2; k <= n; ++k) {
            dp.emplace_back(Conv());
            dp[k] = dp[1] * dp[k - 1];

            unless (dp[k][(1 << n) - 1] == 0) return k;

            for (int S = 0; S < (1 << n); ++S) dp[k][S] = dp[k][S] ? 1 : 0;
        }
        return n;
    }
}
