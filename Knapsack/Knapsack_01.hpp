#pragma once

#include"Base.hpp"
#include <concepts>

namespace knapsack_problem {
    template<copyable I, integral V, integral W, integral Q>
    class Knapsack_01 {
        using ItemList = vector<Item<I, V, W>>;

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

        /// @brief 半分全列挙を用いて 0-1 Knapsack 問題を解く.
        /// @param items 詰め込むアイテムのリスト
        /// @param capacity ナップサックの容量
        static Solution<I, V, W, Q> solve_meet_in_the_middle(const vector<Item<I, V, W>> &items, const W capacity) {
            int n = (int)items.size();
            int a = n / 2, b = n - a;

            struct Partial { V v; W w; ll mask; };

            auto get_partials = [&](int offset, int cnt) {
                vector<Partial> res;
                res.reserve(1LL << cnt);
                for (ll S = 0; S < (1LL << cnt); ++S) {
                    V sv = 0; W sw = 0;
                    for (int k = 0; k < cnt; ++k) {
                        unless(get_bit(S, k)) continue;

                        sv += items[offset + k].value;
                        sw += items[offset + k].weight;
                    }

                    if (sw <= capacity) res.push_back({sv, sw, S});
                }

                sort(res.begin(), res.end(), [](const Partial &X, const Partial &Y) { return X.w < Y.w; });
                vector<Partial> filtered;
                for (const auto &p : res) {
                    if (filtered.empty() || p.v > filtered.back().v) filtered.push_back(p);
                }

                return filtered;
            };

            auto A = get_partials(0, a);
            auto B = get_partials(a, b);

            V max_v = 0;
            ll best_a = 0, best_b = 0;
            int b_idx = (int)B.size() - 1;
            for (const auto &pa : A) {
                while (b_idx >= 0 && pa.w + B[b_idx].w > capacity) b_idx--;
                unless (b_idx >= 0) break;
                unless (chmax(max_v, pa.v + B[b_idx].v)) continue;

                best_a = pa.mask;
                best_b = B[b_idx].mask;
            }

            vector<Q> knapsack(n, 0);
            for (int i = 0; i < a; ++i) if (get_bit(best_a, i)) knapsack[i] = 1;
            for (int i = 0; i < b; ++i) if (get_bit(best_b, i)) knapsack[a + i] = 1;

            return Solution<I, V, W, Q>(items, knapsack);
        }
    };
}
