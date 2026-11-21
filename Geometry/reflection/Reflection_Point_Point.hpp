#pragma once

// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/reflection/Reflection_Point_Point.hpp

#include "../object/Point.hpp"

namespace geometry {
    // 点 X に関して点 P と対称な点を求める.
    template<typename R>
    Point<R> Reflection(const Point<R> &P, const Point<R> &X) {
        return 2 * X - P;
    }
}
