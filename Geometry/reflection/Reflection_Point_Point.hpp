#pragma once

// https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/reflection/Reflection_Point_Point.hpp

#include"../object/Line.hpp"

namespace geometry {
    // 点 P が点 X に関して対称移動した後の点を求める.
    template<typename R>
    Point<R> Reflection(const Point<R> &P, const Point<R> &X) {
        return 2 * X - P;
    }
}
