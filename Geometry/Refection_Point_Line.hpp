#pragma once

#include"Projection_Point_Line.hpp"

namespace geometry {
    // 直線 L に関して, 点 P と対称な点
    template<typename R>
    Point<R> Reflection(const Point<R> &P, const Line<R> &l) {
        return 2 * Projection(P, l) - P;
    }
}