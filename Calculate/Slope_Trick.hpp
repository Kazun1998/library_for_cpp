
#pragma once

#include "../Data_Structure/Additive_Treap.hpp"

/// @brief 区分線形凸関数 f(x) を管理するデータ構造 (Slope Trick).
/// @tparam T 座標・値の型 (加算・比較・max が定義された数値型を想定)
template<typename T>
class Slope_Trick {
    Additive_Treap<T> negative, positive;
    T f_min;

    public:
    Slope_Trick(): negative(), positive(), f_min(0) {}

    /// @brief 定数 a を加算する.
    /// @param a
    void add_const(const T &a) { return f_min += a; }

    /// @brief この関数の最小値を得る.
    /// @return
    T get_min() const { return f_min; }

    /// @brief f(x) を f(x) + max(0, x - a) に更新する.
    /// @param a
    void add_x_minus_a(const T &a) {
        unless (negative.empty()) {
            f_min += max(T(0), negative.max() - a);
        }

        negative.insert(a);
        positive.insert(negative.pop_max());
    }

    /// @brief f(x) を f(x) + max(0, a - x) に更新する.
    /// @param a
    void add_a_minus_x(const T &a) {
        unless (positive.empty()) {
            f_min += max(T(0), a - positive.min());
        }

        positive.insert(a);
        negative.insert(positive.pop_min());
    }

    /// @brief f(x) を f(x) + |x - a| に更新する.
    /// @param a
    void add_abs(const T &a) {
        add_x_minus_a(a);
        add_a_minus_x(a);
    }

    /// @brief add_x_minus_a(a) の逆操作. 対応する add_x_minus_a(a) 済みの状態でのみ正しく動作する.
    /// @param a
    void sub_x_minus_a(const T &a) {
        if (positive.contains(a)) {
            positive.erase(a);
        } else {
            negative.insert(positive.pop_min());
            negative.erase(a);
        }

        unless (negative.empty()) {
            f_min -= max(T(0), negative.max() - a);
        }
    }

    /// @brief add_a_minus_x(a) の逆操作. 対応する add_a_minus_x(a) 済みの状態でのみ正しく動作する.
    /// @param a
    void sub_a_minus_x(const T &a) {
        if (negative.contains(a)) {
            negative.erase(a);
        } else {
            positive.insert(negative.pop_max());
            positive.erase(a);
        }

        unless (positive.empty()) {
            f_min -= max(T(0), a - positive.min());
        }
    }

    /// @brief add_abs(a) の逆操作. 対応する add_abs(a) 済みの状態でのみ正しく動作する.
    /// @param a
    void sub_abs(const T &a) {
        sub_x_minus_a(a);
        sub_a_minus_x(a);
    }

    /// @brief f(x) の値を計算する.
    /// @param x
    /// @return f(x)
    T calculate_at(const T &x) const {
        T res = f_min;

        unless (negative.empty()) {
            T sum_l = negative.more_sum(x, false);
            int count_l = negative.count_more(x, false);
            res += sum_l - count_l * x;
        }

        unless (positive.empty()) {
            T sum_r = positive.less_sum(x, false);
            int count_r = positive.count_less(x, false);
            res += count_r * x - sum_r;
        }

        return res;
    }

    /// @brief calculate_at(x) と同じ.
    /// @param x
    /// @return f(x)
    T operator()(const T &x) const { return calculate_at(x); }

    /// @brief 区間 [l, r] における f(x) の最小値 min_{l <= x <= r} f(x) を求める.
    /// @param l
    /// @param r
    /// @return min_{l <= x <= r} f(x)
    T calculate_min(const T &l, const T &r) const {
        if (!negative.empty() && r < negative.max()) {
            return calculate_at(r);
        }

        if (!positive.empty() && l > positive.min()) {
            return calculate_at(l);
        }

        return f_min;
    }

    /// @brief l <= x <= r において f(x) が最小値をとる区間 [a, b] を求める.
    /// @param l
    /// @param r
    /// @return f(x) が最小値をとる区間 [a, b]
    std::pair<T, T> argmin(const T &l, const T &r) const {
        assert(l <= r);
        T L_opt = negative.empty() ? l : negative.max();
        T R_opt = positive.empty() ? r : positive.min();

        if (r < L_opt) {
            return {r, r};
        }
        if (l > R_opt) {
            return {l, l};
        }
        return {std::max(l, L_opt), std::min(r, R_opt)};
    }
};
