#pragma once

// https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/triangle_center/Centroid.hpp

#include"../object/Triangle.hpp"

namespace geometry {
    template<typename R>
    Point<R> Centroid(const Triangle<R> &T) { return T.balance(1, 1, 1); }
}
