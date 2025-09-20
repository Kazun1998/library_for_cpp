#pragma once

#include"Perpendicular_Bisector.hpp"
#include"Intersection_Line_and_Line.hpp"
#include"Triangle.hpp"

namespace geometry {
    template<typename R>
    Point<R> Circumcenter(const Triangle<R> &T) { 
        Line<R> l = Perpendicular_Bisector(T.A, T.B), m = Perpendicular_Bisector(T.A, T.C);
        return Intersection(l, m);
    }
}
