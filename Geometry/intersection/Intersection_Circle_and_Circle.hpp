#pragma once

// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/intersection/Intersection_Circle_and_Circle.hpp

#include"../object/Circle.hpp"

namespace geometry {
    template<typename R>
    vector<Point<Real>> Intersection(const Circle<R> &C, const Circle<R> &D) {
        Point<R> v = D.center - C.center;
        Point<R> e = v.normalize();
        Point<R> f = e.normal();

        R d= v.norm(), r = C.radius, s = D.radius;
        R x = (d * d + r * r - s * s) / (2 * d), y = sqrt(r * r - x * x);
        return { C.center + x * e + y * f, C.center + x * e - y * f };
    }
}
