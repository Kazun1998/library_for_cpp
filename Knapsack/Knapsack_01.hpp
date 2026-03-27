#pragma once

#include"Base.hpp"
#include <concepts>

namespace knapsack_problem {
    template<copyable I, integral V, integral W, integral Q>
    class Knapsack_01 {
        public:
        /// @brief 各アイテムの重さが軽い場合の 0-1 Knapsack 問題を解く.
        /// @param items 詰め込むアイテムのリスト
        /// @param capacity ナップサックの容量
        static Solution<I, V, W, Q> solve_by_weight(const vector<Item<I, V, W>> &items, const W capacity) {
            int n = items.size();
            vector<vector<V>> dp(n + 1, vector<V>(capacity + 1, 0));

            for (int i = 1; i <= n; i++) {
                const auto &item = items[i - 1];

                for (W w = 0; w <= capacity; ++w) {
                    dp[i][w] = dp[i - 1][w];
                    if (w >= item.weight) {
                        dp[i][w] = max(dp[i][w], dp[i - 1][w - item.weight] + item.value);
                    }
                }
            }

            W current_weight = static_cast<W>(argmax(dp[n]));
            vector<Q> knapsack(n, 0);

            for (int i = n; i >= 1; --i) {
                const auto &item = items[i - 1];

                if (item.weight <= current_weight && dp[i][current_weight] == dp[i - 1][current_weight - item.weight] + item.value) {
                    current_weight -= item.weight;
                    knapsack[i - 1]++;
                }
            }

            return Solution<I, V, W, Q>(items, knapsack);
        }

        static Solution<I, V, W, Q> solve_by_value(const vector<Item<I, V, W>> &items, const W capacity) {
            int n = items.size();
            V value_sum = 0;
            for (const auto &item: items) value_sum += item.value;

            vector<vector<W>> dp(n + 1, vector<W>(value_sum + 1, capacity + 1));
            dp[0][0] = 0;

            for (int i = 1; i <= n; ++i) {
                const Item<I, V, W> &item = items[i - 1];

                for (int v = 0; v < item.value; ++v) {
                    dp[i][v] = dp[i - 1][v];
                }

                for (int v = item.value; v <= value_sum; ++v) {
                    dp[i][v] = min(dp[i - 1][v], dp[i - 1][v - item.value] + item.weight);
                }
            }

            V current_value = 0;
            for (int v = value_sum; v >= 0; --v) {
                if (dp[n][v] <= capacity) {
                    current_value = v;
                    break;
                }
            }

            vector<Q> knapsack(n, 0);
            for (int i = n; i >= 1; --i) {
                const auto &item = items[i - 1];

                if (current_value >= item.value && dp[i][current_value] == dp[i - 1][current_value - item.value] + item.weight) {
                    current_value -= item.value;
                    knapsack[i - 1]++;
                }
            }

            return Solution<I, V, W, Q>(items, knapsack);
        }
    };
}
