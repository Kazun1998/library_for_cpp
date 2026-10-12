#pragma once

#include "../template/template.hpp"

/// @brief 三分探索によって, 整数を定義域とする関数 f の [L,R] における最小値とその引数を求める.
/// @param L 左端
/// @param R 右端 (L <= R を満たすこと)
/// @param f 下に凸な関数
/// @return pair<最小値, 最小値を与える x の例>
template<typename T>
auto Ternary_Search_Minimize_Integer(T L, T R, const auto &f) {
    while (R - L > 3) {
        T d = (R - L) / 3;
        T a = L + d;
        T b = R - d;

        if (f(a) <= f(b)) R = b;
        else L = a;
    }

    auto y = f(L);
    T argx = L;
    for (T x = L + 1; x <= R; ++x) {
        auto p = f(x);
        if (y > p) { y = p; argx = x; }
    }
    return make_pair(y, argx);
}

/// @brief 三分探索によって, 整数を定義域とする関数 f の [L,R] における最大値とその引数を求める.
/// @param L 左端
/// @param R 右端 (L <= R を満たすこと)
/// @param f 上に凸な関数
/// @return pair<最大値, 最大値を与える x の例>
template<typename T>
auto Ternary_Search_Maximize_Integer(T L, T R, const auto &f) {
    while (R - L > 3) {
        T d = (R - L) / 3;
        T a = L + d;
        T b = R - d;

        if (f(a) >= f(b)) R = b;
        else L = a;
    }

    auto y = f(L);
    T argx = L;
    for (T x = L + 1; x <= R; ++x) {
        auto p = f(x);
        if (y < p) { y = p; argx = x; }
    }
    return make_pair(y, argx);
}
