#pragma once

#include"Line.hpp"

namespace geometry {
    template<typename R>
    R Distance(const Line<R> &l, const Point<R> P) {
        R S = abs<R>(cross(l.vectorize(), P - l.A));
        return S / norm(l.vectorize());
    }
}
