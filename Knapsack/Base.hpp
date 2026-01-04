#pragma once

#include"../template/template.hpp"

namespace knapsack_problem {
    template<typename I, typename V, typename W>
    struct Item {
        I id;
        V value;
        W weight;

        Item() = default;
        Item(const V value, const W weight): value(value), weight(weight) {}
        Item(const I id, const V value, const W weight): id(id), value(value), weight(weight) {}
    };

    template<typename I, typename V, typename W>
    struct Solution {
        private:
        static V calculate_total_value(const vector<Item<I, V, W>> &items) {
            V total_value = 0;
            for (const auto &item : items) total_value += item.value;
            return total_value;
        }

        public:
        const vector<Item<I, V, W>> knapsack;
        const V total_value;

        Solution(const vector<Item<I, V, W>> &items, const V total_value): knapsack(items), total_value(total_value) {}
        Solution(const vector<Item<I, V, W>> &items): knapsack(items), total_value(calculate_total_value(items)) {}
    };
}
