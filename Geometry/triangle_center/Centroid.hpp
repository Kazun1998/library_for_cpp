#pragma once

#include"../object/Triangle.hpp"

namespace geometry {
    template<typename R>
    Point<R> Centroid(const Triangle<R> &T) { return T.balance(1, 1, 1); }
}
