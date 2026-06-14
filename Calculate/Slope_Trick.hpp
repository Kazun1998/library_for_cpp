
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
};
