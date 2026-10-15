#pragma once

// https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/tangent/Tangent_Point_from_Point_to_Circle.hpp

#include"../object/Point.hpp"
#include"../object/Circle.hpp"
#include"../intersection/Intersection_Circle_and_Circle.hpp"

namespace geometry {
    template<typename R>
    vector<Point<Real>> Tangent_Points(const Point<R> &P, const Circle<R> &C) {
        Real d = norm(P - C.center), r = C.radius, s = sqrt(d * d - r * r);
        return Intersection(C, Circle<Real>(P, s));
    }
}