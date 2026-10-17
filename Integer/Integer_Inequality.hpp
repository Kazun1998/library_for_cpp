#pragma once

// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Integer/Integer_Inequality.hpp

#include "../template/template.hpp"

/// @brief [l, +infty) 上の非定数多項式 P (係数は符号なし整数) に対して, P(x) <= y (equal = false の場合は P(x) < y) を満たす最大の整数 x を求める (符号なし整数版).
/// @param P 多項式 (P[i] は x^i の係数). 最高次の係数が 0 の場合は取り除かれる.
/// @param y 目標値
/// @param l 捜索範囲の下限.
/// @param equal true の場合は P(x) <= y, false の場合は P(x) < y.
/// @return 条件を満たす最大の整数 x. 存在しない場合 (l でも満たさない場合) は nullopt.
/// @tparam T 符号なし整数型 (unsigned, unsigned long long など).
/// @note 係数・l・y が全て 0 以上なので, P は自動的に [l, +infty) 上で狭義単調増加になる.
/// @note 評価は y を超えた時点で打ち切るためオーバーフローしないが, y + 1 と l + 2 * (解の大きさ) が T の範囲内であること.
template<unsigned_integral T>
optional<T> Integer_Inequality(vector<T> P, const T y, const T l = 0, const bool equal = true) {
    // P の正規化
    until(P.empty() || P.back() != 0) {
        P.pop_back();
    }

    assert(P.size() > 1);

    // P(x) を返す. ただし P(x) > y の場合は y + 1 を返す (割り算で超過を判定するのでオーバーフローしない).
    auto calc = [&](T x) -> T {
        if (x == 0) { return P[0]; }

        T v = 0;
        for (int i = (int)P.size() - 1; i >= 0; i--) {
            if (P[i] > y) { return y + 1; }
            if (v > (y - P[i]) / x) { return y + 1; }
            v = v * x + P[i];
        }
        return v;
    };

    // 条件を満たすか?
    auto ok = [&](T x) -> bool {
        T v = calc(x);
        return v < y || (equal && v == y);
    };

    if (!ok(l)) {
        return nullopt;
    }

    // 上界 hi (ok(hi) = false) を求める.
    T d = 1;
    while (ok(l + d)) {
        d *= 2;
    }

    // ok(lo) = true, ok(hi) = false
    T lo = l, hi = l + d;
    while (hi - lo > 1) {
        T c = lo + (hi - lo) / 2;
        (ok(c) ? lo : hi) = c;
    }

    return lo;
}

/// @brief [l, +infty) 上 (狭義) 単調増加な整数係数の非定数多項式 P に対して, P(x) <= y (equal = false の場合は P(x) < y) を満たす最大の整数 x を求める.
/// @param P 多項式 (P[i] は x^i の係数). 最高次の係数が 0 の場合は取り除かれる.
/// @param y 目標値
/// @param l 捜索範囲の下限.
/// @param equal true の場合は P(x) <= y, false の場合は P(x) < y.
/// @return 条件を満たす最大の整数 x. 存在しない場合 (l でも満たさない場合) は nullopt.
/// @tparam T 符号付き整数型 (int, long long など).
/// @note 係数・l・y は負でもよい. 評価は途中で打ち切るためオーバーフローしないが, 2 * max(|P[i]|, |y|) + |l| が T の範囲内であること.
template<signed_integral T>
optional<T> Integer_Inequality(vector<T> P, const T y, const T l = 0, const bool equal = true) {
    // P の正規化
    until(P.empty() || P.back() != 0) {
        P.pop_back();
    }

    assert(P.size() > 1);

    // C = max |P[i]|, B = max(C, |y|)
    T C = 0;
    for (const T &p: P) { C = max(C, p < 0 ? -p : p); }
    const T B = max(C, y < 0 ? -y : y);
    const T MAX = numeric_limits<T>::max();

    // sgn(P(x) - y) に相当する値を返す. |x| >= 2 のとき, Horner 法の途中値 v が |v| > B になると
    // 以降は |v| が真に増え続け, 最終的に |P(x)| > B >= |y| かつ符号も確定するので, その時点で打ち切る.
    // 打ち切った場合は P(x) > y なら y + 1, P(x) < y なら y - 1 を返す.
    auto calc = [&](T x) -> T {
        const T ax = x < 0 ? -x : x;
        T v = 0;
        for (int i = (int)P.size() - 1; i >= 0; i--) {
            if (ax >= 2) {
                const T av = v < 0 ? -v : v;
                if (av > B || av > (MAX - C) / ax) {
                    // 残りの乗算回数は i + 1 回
                    bool negative = (v < 0) != (x < 0 && (i + 1) % 2 == 1);
                    return negative ? y - 1 : y + 1;
                }
            }
            v = v * x + P[i];
        }
        return v;
    };

    // 条件を満たすか?
    auto ok = [&](T x) -> bool {
        T v = calc(x);
        return v < y || (equal && v == y);
    };

    if (!ok(l)) {
        return nullopt;
    }

    // 上界 hi (ok(hi) = false) を求める.
    T d = 1;
    while (ok(l + d)) {
        d *= 2;
    }

    // ok(lo) = true, ok(hi) = false
    T lo = l, hi = l + d;
    while (hi - lo > 1) {
        T c = lo + (hi - lo) / 2;
        (ok(c) ? lo : hi) = c;
    }

    return lo;
}
