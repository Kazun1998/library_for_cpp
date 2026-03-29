#pragma once

#include "Base.hpp"
#include "Knapsack_01.hpp"

namespace knapsack_problem {
    template<copyable I, integral V, integral W, integral Q>
    class Knapsack_Limitation {
        using ItemList = vector<Item<I, V, W>>;

        public:
        /**
         * @brief 個数制限付きナップサック問題を、0-1ナップサック問題に変換して解く
         * 
         * @param items 詰め込むアイテムのリスト
         * @param limit 各アイテムの使用可能上限数
         * @param capacity ナップサックの容量
         * @return Solution<I, V, W, Q> 最適解の情報
         */
        static Solution<I, V, W, Q> solve_by_weight(const vector<Item<I, V, W>> &items, const vector<Q> &limit, const W capacity) {
            const int n = items.size();

            vector<Item<pair<I, Q>, V, W>> reduced_items;
            for (int i = 0; i < n; ++i) {
                const Item<I, V, W> item = items[i];

                int m = limit[i];
                for (Q k = 1; m > 0; m -= k, k = min(2 * k, m)) {
                    reduced_items.emplace_back(Item<pair<I, Q>, V, W>(make_pair(i, k), item.value * k, item.weight * k));
                }
            }

            Solution<pair<I, Q>, V, W, Q> reduced_result = Knapsack_01<pair<I, Q>, V, W, Q>::solve_by_weight(reduced_items, capacity);

            vector<Q> knapsack(n, 0);
            for (int j = 0; j < reduced_items.size(); ++j) {
                if (reduced_result.knapsack[j] == 0) continue;

                auto &[i, q] = reduced_items[j].id;
                knapsack[i] += q;
            }

            return Solution<I, V, W, Q>(items, knapsack);
        }
    };
}
