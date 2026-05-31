#pragma once

#include"Base.hpp"

namespace knapsack_problem {
    template<copyable I, integral V, integral W, integral Q>
    class Knapsack_Infinity {
        using ItemList = vector<Item<I, V, W>>;

        public:
        /**
         * @brief 個数制限なしナップサック問題を動的計画法で解く
         * 
         * @param items 詰め込むアイテムのリスト（同一アイテムを何度でも使用可能）
         * @param capacity ナップサックの容量
         * @return Solution<I, V, W, Q> 最適解の情報
         */
        static Solution<I, V, W, Q> solve_by_weight(const vector<Item<I, V, W>> &items, const W capacity) {
            int n = items.size();
            vector<vector<V>> dp(n + 1, vector<V>(capacity + 1, 0));

            for (int i = 1; i <= n; i++) {
                const Item<I, V, W> &item = items[i - 1];

                for (W w = 0; w <= capacity; ++w) {
                    dp[i][w] = dp[i - 1][w];
                    if (item.weight <= w) chmax(dp[i][w], dp[i][w - item.weight] + item.value);
                }
            }

            W current_weight = static_cast<W>(argmax(dp[n]));
            vector<Q> knapsack(n, 0);

            for (int i = n; i >= 1; --i) {
                const Item<I, V, W> &item = items[i - 1];

                while(item.weight <= current_weight && dp[i][current_weight] == dp[i][current_weight - item.weight] + item.value) {
                    current_weight -= item.weight;
                    knapsack[i - 1]++;
                }
            }

            return Solution<I, V, W, Q>(items, knapsack);
        }
    };
}
