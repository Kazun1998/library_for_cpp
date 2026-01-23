#pragma once

#include"../template/template.hpp"
#include"../template/exception.hpp"

namespace bezout {
    /// @brief 1次不定方程式 a x + b y = c の解 (x, y) を 1 組見つける.
    /// @param hint (p, q) は a p + b q = gcd(a, b) を満たす.
    /// @return 解 (x, y). 解が存在しない場合は std::nullopt.
    template<integral T>
    optional<pair<T, T>> Find_Particular_Solution(const T a, const T b, const T c, const pair<T, T> &hint) {
        T p, q;
        tie (p, q) = hint;

        const T g = a * p + b * q;

        if (g == 0) {
            if (c == 0) { return pair<T, T>(0, 0); }
            return nullopt;
        }

        if (safe_mod(c, g) != 0) { return nullopt; }

        const T k = c / g;
        return pair<T, T>(p * k, q * k);
    }

    /// @brief 1次不定方程式 a x + b y = c の解 (x, y) を 1 組見つける.
    /// @return 解 (x, y). 解が存在しない場合は std::nullopt.
    template<integral T>
    optional<pair<T, T>> Find_Particular_Solution(const T a, const T b, const T c) {
        auto [p, q, g] = Extended_Euclid<T>(a, b);
        return Find_Particular_Solution<T>(a, b, c, {p, q});
    }

    template<integral T>
    optional<tuple<T, T, T, T, T, T>> Solve(T a, T b, T c, const T lx, const T rx, const T ly, const T ry, const pair<T, T> &hint) {
        T p, q;
        tie (p, q) = hint;
        const T g = a * p + b * q;

        if (safe_mod(c, g) != 0) { return nullopt; }

        a /= g; b /= g; c /= g;

        int tmp_l, tmp_r;
        if (b > 0) {
            tmp_l = lx - c * p;
            tmp_r = rx - c * p;
        } else {
            tmp_l = -(rx - c * p);
            tmp_r = -(lx - c * p);
        }

        T klx = div_ceil(tmp_l, abs<T>(b));
        T krx = div_floor(tmp_r, abs<T>(b));

        if (a > 0) {
            tmp_l = -ry + c * q;
            tmp_r = -ly + c * q;
        } else {
            tmp_l = -(-ly + c * q);
            tmp_r = -(-ry + c * q);
        }

        T kly = div_ceil(tmp_l, abs<T>(a));
        T kry = div_floor(tmp_r, abs<T>(a));

        T kl = max<T>(klx, kly), kr = min<T>(krx, kry);

        if (kl > kr) return nullopt;

        return make_tuple(c * p, b, c * q, -a, kl, kr);
    };

    template<integral T>
    optional<tuple<T, T, T, T, T, T>> Solve(T a, T b, T c, const T lx, const T rx, const T ly, const T ry) {
        auto [p, q, g] = Extended_Euclid<T>(a, b);
        return Solve<T>(a, b, c, lx, rx, ly, ry, make_pair(p, q));
    };
}
