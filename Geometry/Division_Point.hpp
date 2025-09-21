#pragma once

#include"Point.hpp"

namespace geometry {
    // 線分 AB を p:q に内分する点を求める.
    template<typename R>
    Point<R> Internal_Division(const Point<R> &A, const Point<R> &B, const R &p, const R &q) {
        return (q * A + p * B) / (p + q);
    }

    // 線分 AB の中点
    template<typename R>
    Point<R> MidPoint(const Point<R> &A, const Point<R> &B) { return (A + B) / 2; }

    // 線分 AB を p:q に外分する点を求める.
    template<typename R>
    Point<R> External_Division(const Point<R> &A, const Point<R> &B, const R &p, const R &q) {
        return (-q * A + p * B) / (p - q);
    }
}