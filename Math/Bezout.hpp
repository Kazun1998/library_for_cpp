#pragma once

#include"../template/template.hpp"
#include"../template/exception.hpp"

namespace bezout {
    /// @brief 1次不定方程式 a x + b y = c の解 (x, y) を 1 組見つける.
    /// @param hint (p, q) は a p + b q = gcd(a, b) を満たす.
    /// @return 解 (x, y)
    template<integral T>
    pair<T, T> Find_Particular_Solution(const T a, const T b, const T c, const pair<T, T> &hint) {
        T p, q;
        tie (p, q) = hint;

        const T g = a * p + b * q;

        if (g == 0) {
            if (c == 0) { return {0, 0}; }
            throw NotExist();
        }

        if (safe_mod(c, g) != 0) { throw NotExist(); }

        const T k = c / g;
        return {p * k, q * k};
    }

    /// @brief 1次不定方程式 a x + b y = c の解 (x, y) を 1 組見つける.
    /// @return 解 (x, y)
    template<integral T>
    pair<T, T> Find_Particular_Solution(const T a, const T b, const T c) {
        auto [p, q, g] = Extended_Euclid<T>(a, b);
        return Find_Particular_Solution<T>(a, b, c, {p, q});
    }
}
