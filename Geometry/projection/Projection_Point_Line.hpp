#pragma once

// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/projection/Projection_Point_Line.hpp

#include"../object/Line.hpp"

namespace geometry {
    template<typename R>
    Point<R> Projection(const Point<R> &P, const Line<R> &l) {
        auto d = l.vectorize();
        auto t = dot(P - l.A, d) / norm_2(d); 
        return l.A + t * d;
    }
}
