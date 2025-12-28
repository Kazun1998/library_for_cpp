#pragma once

#include"../template/template.hpp"

template<integral T>
class Xor_Vector_Space {
    vector<T> basis;

    public:
    Xor_Vector_Space(): Xor_Vector_Space(vector<T>{}) {}

    Xor_Vector_Space(const vector<T> &vectors) {
        for (T x: vectors) {
            add_vector(x);
        }
    }

    bool add_vector(T x) {
        T y = projection(x);
        if (y == 0) return false;

        basis.emplace_back(y);

        return true;
    }

    T projection(T x) const {
        for (T v: basis) {
            x = min<T>(x, x ^ v);
        }

        return x;
    }

    constexpr inline bool contains(const T x) const { return projection(x) == 0; }

    constexpr inline size_t dimension() const { return basis.size(); }

    constexpr bool operator<=(const Xor_Vector_Space &W) const {
        for (T x: basis) {
            if (!W.contains(x)) return false;
        }

        return true;
    }

    constexpr bool operator>=(const Xor_Vector_Space &W) const { return W <= *this; }
    constexpr bool operator<(const Xor_Vector_Space &W) const { return (*this <= W) && (this->dimension() < W.dimension()); }
    constexpr bool operator>(const Xor_Vector_Space &W) const { return W < *this; }
    constexpr bool operator==(const Xor_Vector_Space &W) const {  return (*this <= W) && (this->dimension() == W.dimension()); }
    constexpr bool operator!=(const Xor_Vector_Space &W) const { return !(*this == W); }
};
