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

    template<typename I, typename V, typename W, typename T>
    struct Solution {
        private:
        static V calculate_total_value(const vector<Item<I, V, W>> &items, const vector<T> &knapsack) {
            V total_value = 0;
            for (int i = 0; i < items.size(); ++i) {
                total_value += items[i].value * knapsack[i];
            }
            return total_value;
        }

        public:
        const vector<Item<I, V, W>> items;
        const vector<T> knapsack;
        const V total_value;

        Solution(const vector<Item<I, V, W>> &items, const vector<T> &knapsack): items(items), knapsack(knapsack), total_value(calculate_total_value(items, knapsack)){}
    };
}
