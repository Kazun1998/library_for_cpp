#include"../template/template.hpp"


/// @brief [L, R] 上で広義単調増加な条件 cond に対して, cond(x) が true になる最小の整数 x を二分探索で求める.
/// @tparam T 整数型
/// @param L: 下端
/// @param R: 上端
/// @param cond: [L, R] 上広義単調増加な条件. T を受け取り bool を返す呼び出し可能な値.
/// @param default_value: cond(R) が false の時の返り値
/// @return cond(x) が true になる最小の整数 x. ただし, cond(R) が false の場合は default_value を返す.
template<typename T>
T General_Binary_Increase_Search_Integer(T L, T R, const auto& cond, T default_value) {
    // 例外ケースの処理
    // R でも false → 異常値
    unless(cond(R)) { return default_value; }
    // L にて true → L
    if(cond(L)) { return L; }

    // 探索パート
    while (R - L > 1) {
        T C = L + (R - L) / 2;
        cond(C) ? R = C : L = C;
    }

    return R;
}

/// @brief [L, R] 上で広義単調減少な条件 cond に対して, cond(x) が true になる最大の整数 x を二分探索で求める.
/// @tparam T 整数型
/// @param L: 下端
/// @param R: 上端
/// @param cond: [L, R] 上広義単調減少な条件. T を受け取り bool を返す呼び出し可能な値.
/// @param default_value: cond(L) が false の時の返り値
/// @return cond(x) が true になる最大の整数 x. ただし, cond(L) が false の場合は default_value を返す.
template<typename T>
T General_Binary_Decrease_Search_Integer(T L, T R, const auto& cond, T default_value) {
    // 例外ケースの処理
    // L でも false → 異常値
    unless(cond(L)) { return default_value; }
    // R にて true → R
    if(cond(R)) { return R; }

    // 探索パート
    while (R - L > 1) {
        T C = L + (R - L) / 2;
        cond(C) ? L = C : R = C;
    }

    return L;
}
