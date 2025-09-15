#pragma once

#include"Line.hpp"

namespace geometry {
    template<typename R>
    Point<R> Projection(const Point<R> &P, const Line<R> &L) {
        auto d = L.vectorize();
        auto t = dot(P - L.A, d) / norm_2(d); 
        return L.A + t * d;
    }
}