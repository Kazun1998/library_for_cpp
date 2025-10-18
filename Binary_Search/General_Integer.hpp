#include"../template/template.hpp"

// [L, R] 上で広義単調増加な条件 cond に対して, cond(x) が True になる最小の整数 x を二分探索で求める.
// Args
// T L: 下限
// T R: 上限
// function<bool(T)> cond: [L, R] 上広義単調増加な条件
// T default_value: cond(R) が False の時の返り値
template<typename T>
T General_Binary_Increase_Search_Integer(T L, T R, const function<bool(T)> cond, T default_value) {
    // 例外ケースの処理
    // R でも False → 異常値
    unless(cond(R)) { return default_value; }
    // L にて True → L
    if(cond(L)) { return L; }

    // 探索パート
    while (R - L > 1) {
        T C = L + (R - L) / 2;
        cond(C) ? R = C : L = C;
    }

    return R;
}

// [L, R] 上で広義単調減少な条件 cond に対して, cond(x) が True になる最大の整数 x を二分探索で求める.
// Args
// T L: 下限
// T R: 上限
// function<bool(T)> cond: [L, R] 上広義単調減少な条件
// T default_value: cond(L) が False の時の返り値
template<typename T>
T General_Binary_Decrease_Search_Integer(T L, T R, const function<bool(T)> cond, T default_value) {
    // 例外ケースの処理
    // L でも False → 異常値
    unless(cond(L)) { return default_value; }
    // R にて True → R
    if(cond(R)) { return R; }

    // 探索パート
    while (R - L > 1) {
        T C = L + (R - L) / 2;
        cond(C) ? L = C : R = C;
    }

    return L;
}
