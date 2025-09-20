#pragma once

#include"Line.hpp"
#include"Division_Point.hpp"

namespace geometry {
    // 2 点 A, B に関する垂直二等分線を求める.
    template<typename R>
    Line<R> Perpendicular_Bisector(const Point<R> &A, const Point<R> &B) {
        auto M = MidPoint(A, B);
        auto d = B - A;
        Point<R> n(-d.y, d.x);

        return Line<R>(M, M + n);
    }
}
