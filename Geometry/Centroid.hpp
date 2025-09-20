#pragma once

#include"Triangle.hpp"

namespace geometry {
    template<typename R>
    Point<R> Centroid(const Triangle<R> &T) { return (T.A + T.B + T.C) / 3; }
}
