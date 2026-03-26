#pragma once

#include"../template/template.hpp"
#include <concepts>

namespace knapsack_problem {
    template<std::copyable I, std::integral V, std::integral W>
    struct Item {
        I id;
        V value;
        W weight;

        Item() = default;
        Item(const V value, const W weight): value(value), weight(weight) {}
        Item(const I id, const V value, const W weight): id(id), value(value), weight(weight) {}
    };

    template<std::copyable I, std::integral V, std::integral W, std::integral Q>
    struct Solution {
        private:
        static V calculate_total_value(const vector<Item<I, V, W>> &items, const vector<Q> &knapsack) {
            V total_value = 0;
            for (int i = 0; i < items.size(); ++i) {
                total_value += items[i].value * knapsack[i];
            }
            return total_value;
        }

        public:
        const vector<Item<I, V, W>> items;
        const vector<Q> knapsack;
        const V total_value;

        Solution(const vector<Item<I, V, W>> &items, const vector<Q> &knapsack): items(items), knapsack(knapsack), total_value(calculate_total_value(items, knapsack)){}
    };
}
