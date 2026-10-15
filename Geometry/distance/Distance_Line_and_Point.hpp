#pragma once

// https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/distance/Distance_Line_and_Point.hpp

#include"../object/Line.hpp"

namespace geometry {
    template<typename R>
    R Distance(const Line<R> &l, const Point<R> P) {
        R S = abs<R>(cross(l.vectorize(), P - l.A));
        return S / norm(l.vectorize());
    }
}
