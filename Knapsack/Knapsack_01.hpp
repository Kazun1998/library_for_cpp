#pragma once

#include"Base.hpp"

namespace knapsack_problem {
    template<typename I, typename V, typename W>
    class Knapsack_01 {
        using Item_List = vector<Item<I, V, W>>;

        public:
        static Solution<I, V, W> solve_by_weight(const Item_List &items, const W capacity) {
            int n = items.size();
            vector<vector<V>> dp(n + 1, vector<V>(capacity + 1, 0));

            for (int i = 1; i <= n; i++) {
                const auto &item = items[i - 1];

                for (int w = 0; w < item.weight; ++w) {
                    dp[i][w] = dp[i - 1][w];
                }
                for (int w = item.weight; w <= capacity; ++w) {
                    dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - item.weight] + item.value);
                }
            }

            W current_weight = static_cast<W>(argmax(dp[n]));
            const V packed_value = dp[n][current_weight];
            Item_List packed_items;

            for (int i = n; i >= 1; --i) {
                const auto &item = items[i - 1];

                if (item.weight <= current_weight && dp[i][current_weight] == dp[i - 1][current_weight - item.weight] + item.value) {
                    current_weight -= item.weight;
                    packed_items.emplace_back(item);
                }
            }

            reverse(packed_items.begin(), packed_items.end());

            return Solution<I, V, W>(packed_items, packed_value);
        }
    };
}
