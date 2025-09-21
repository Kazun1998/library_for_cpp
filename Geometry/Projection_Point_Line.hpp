#pragma once

#include"Line.hpp"

namespace geometry {
    template<typename R>
    Point<R> Projection(const Point<R> &P, const Line<R> &l) {
        auto d = l.vectorize();
        auto t = dot(P - l.A, d) / norm_2(d); 
        return l.A + t * d;
    }
}
