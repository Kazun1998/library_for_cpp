
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
};
