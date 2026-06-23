
#pragma once

#include "../Data_Structure/Additive_Treap.hpp"

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

    void add_x_minus_a(const T &a) {
        unless (negative.empty()) {
            f_min += max(T(0), negative.max() - a);
        }

        negative.insert(a);
        positive.insert(negative.pop_max());
    }

    void add_a_minus_x(const T &a) {
        unless (positive.empty()) {
            f_min += max(T(0), a - positive.min());
        }

        positive.insert(a);
        negative.insert(positive.pop_min());
    }

    void add_abs(const T &a) {
        add_x_minus_a(a);
        add_a_minus_x(a);
    }

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

    void sub_abs(const T &a) {
        sub_x_minus_a(a);
        sub_a_minus_x(a);
    }

    // calculate f(x)
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

    T operator()(const T &x) const { return calculate_at(x); }

    // calculate min_{l <= x <= r} f(x)
    T calculate_min(const T &l, const T &r) const {
        if (!negative.empty() && r < negative.max()) {
            return calculate_at(r);
        }

        if (!positive.empty() && l > positive.min()) {
            return calculate_at(l);
        }

        return f_min;
    }
};
