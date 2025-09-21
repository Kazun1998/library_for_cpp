#pragma once

#include"Point.hpp"
#include"Circle.hpp"
#include"Intersection_Circle_and_Circle.hpp"

namespace geometry {
    template<typename R>
    vector<Point<Real>> Tangent_Points(const Point<R> &P, const Circle<R> &C) {
        Real d = norm(P - C.center), r = C.radius, s = sqrt(d * d - r * r);
        return Intersection(C, Circle<Real>(P, s));
    }
}