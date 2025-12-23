#pragma once

#include"../template/template.hpp"

namespace interval_product {
    template <typename F, typename G>
    concept Binary_Operator = requires(F f, G g) {
        { f(g, g) } -> std::convertible_to<G>;
    };

    template <typename F, typename G>
    concept Unary_Operator = requires(F f, G g) {
        { f(g) } -> std::convertible_to<G>;
    };

    template<class G, auto op, auto inv, auto identity>
    requires Binary_Operator<decltype(op), G> &&  Unary_Operator<decltype(inv), G> && convertible_to<decltype(identity), G>
    class Interval_Product {
        vector<G> prefix_prod;

        public:
        Interval_Product(const vector<G> &data) {
            prefix_prod.reserve(data.size() + 1);

            // 累積和は exclusive でとる. つまり, prefix_prod[i] = data[0] * data[1] * ... * data[i - 1] になる.
            prefix_prod.push_back(identity);
            for (const G &x : data) {
                prefix_prod.push_back(op(prefix_prod.back(), x));
            }
        }

        /// @brief 閉区間 [0, r] における累積
        /// @param r 区間の右端
        /// @return 
        inline G query(const int r) const { return prefix_prod[r + 1]; }

        /// @brief 閉区間 [l, r] における累積
        /// @param l 区間の左端
        /// @param r 区間の右端
        inline G query(int l, int r) const {
            if (l == 0) return query(r);
            return op(inv(query(l - 1)), query(r));
        }
    };
}
