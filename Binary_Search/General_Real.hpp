#include"../template/template.hpp"


/**
 * @brief [l, r] 上で広義単調増加な条件 cond に対して, cond(x) が true になる最小の実数 x を二分探索で求める.
 * 
 * @tparam T 実数型 (float, double, long double など)
 * @param l 探索範囲の下限
 * @param r 探索範囲の上限
 * @param cond [l, r] 上で広義単調増加な条件 (cond(x) が true ならば、任意の y >= x について cond(y) も true)
 * @param trial 二分探索の反復回数
 * @param default_value cond(r) が false の時の返り値
 * @return T cond(x) が true となる最小の実数 x (反復回数 trial に基づく近似値). cond(r) が false の場合は default_value.
 */
template<typename T>
T General_Binary_Increase_Search_Real(const T l, const T r, const auto cond, int trial, T default_value) {
    if(!cond(r)) { return default_value; }

    if (cond(l)) return l;

    T out = l, in = r;
    for (int t = 0; t < trial; ++t) {
        T c = out + (in - out) / 2;
        cond(c) ? in = c : out = c;
    }

    return in;
}

/**
 * @brief [l, r] 上で広義単調減少な条件 cond に対して, cond(x) が true になる最大の実数 x を二分探索で求める.
 * 
 * @tparam T 実数型 (float, double, long double など)
 * @param l 探索範囲の下限
 * @param r 探索範囲の上限
 * @param cond [l, r] 上で広義単調減少な条件 (cond(x) が true ならば、任意の y <= x について cond(y) も true)
 * @param trial 二分探索の反復回数
 * @param default_value cond(l) が false の時の返り値
 * @return T cond(x) が true となる最大の実数 x (反復回数 trial に基づく近似値). cond(l) が false の場合は default_value.
 */
template<typename T>
T General_Binary_Decrease_Search_Real(const T l, const T r, const auto& cond, int trial, T default_value) {
    if (!cond(l)) { return default_value; }

    if (cond(r)) return r;

    T in = l, out = r;
    for (int t = 0; t < trial; ++t) {
        T c = in + (out - in) / 2;
        cond(c) ? in = c : out = c;
    }
    return in; 
}
