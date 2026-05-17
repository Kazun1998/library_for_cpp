#pragma once

#include "Graph.hpp"
#include "../../Convolution/Bitwise_Or_Convolution.hpp"

namespace graph {
    int Chromatic_Number(const Graph &G) {
        int n = G.order();
        if (n == 0) return 0;

        using namespace convolution;
        using Conv = Bitwise_Or_Convolution<long long>;

        vector<int> adj_mask(n, 0);
        for (int i = 0; i < n; ++i) {
            for (auto edge : G.incidence(i)) {
                adj_mask[i] |= (1 << edge->target);
            }
        }

        // Section I: 独立集合の判定 (S が独立集合なら 1, そうでなければ 0)
        vector<long long> indep_vec(1 << n, 0);
        indep_vec[0] = 1;
        for (int S = 1; S < (1 << n); ++S) {
            int x = lowest_bit(S);
            int prev = S ^ (1 << x);
            if (indep_vec[prev] && !(adj_mask[x] & prev)) indep_vec[S] = 1;
        }

        if (indep_vec[(1 << n) - 1]) return 1;
        Conv indep(indep_vec);

        auto clamp = [&](Conv &c) {
            for (int S = 0; S < (1 << n); ++S) c[S] = (c[S] > 0);
        };

        // Section II: k = 2, 4, 8, ... に対してダブリング
        vector<Conv> dp_pow2;
        dp_pow2.push_back(indep);
        int k = 0;
        while ((1 << (k + 1)) <= n) {
            Conv next = dp_pow2.back() * dp_pow2.back();
            clamp(next);
            if (next[(1 << n) - 1]) break;
            dp_pow2.push_back(next);
            k++;
        }

        // Section III: 二分探索によって彩色数を求める
        int current_k = (1 << k);
        Conv current_dp = dp_pow2.back();
        for (int i = k - 1; i >= 0; --i) {
            if (current_k + (1 << i) > n) continue;
            Conv res = current_dp * dp_pow2[i];
            clamp(res);
            unless (res[(1 << n) - 1]) {
                current_k += (1 << i);
                current_dp = res;
            }
        }

        return current_k + 1;
    }
}
