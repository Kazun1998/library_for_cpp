#pragma once

#include"../template/template.hpp"

template<integral T>
class Xor_Vector_Space {
    vector<T> basis;

    public:
    Xor_Vector_Space(): Xor_Vector_Space(vector<T>{}) {}

    /// @brief vectors から生成される部分空間を生成する.
    /// @param vectors 生成元の集合
    Xor_Vector_Space(const vector<T> &vectors) {
        for (T x: vectors) {
            add_vector(x);
        }
    }

    /// @brief x を追加する.
    /// @param x 
    /// @return 次元が増えたら True. そうでなければ False.
    bool add_vector(T x) {
        T y = projection(x);
        if (y == 0) return false;

        basis.emplace_back(y);

        return true;
    }

    /// @brief x をこの空間へ射影した時の残りを求める.
    /// @param x 
    /// @return x = a + b (b in X) となる a.
    T projection(T x) const {
        for (T v: basis) {
            x = min<T>(x, x ^ v);
        }

        return x;
    }

    /// @brief x はこの空間に含まれるか?
    /// @param x 
    constexpr inline bool contains(const T x) const { return projection(x) == 0; }

    /// @brief この空間の次元を求める.
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
