#pragma once

#include"../projection/Projection_Point_Line.hpp"
#include"../object/Line.hpp"
#include"../object/Circle.hpp"
#include"../distance/Distance_Line_and_Point.hpp"

namespace geometry {
    template<typename R>
    vector<Point<Real>> Intersection(const Circle<R> &C, const Line<R> &l) {
        R h = Distance(l, C.center), r = C.radius;
        Point<R> H = Projection(C.center, l);
        Point<Real> e = l.vectorize().normalize();
        Real x = sqrt(r * r - h * h);
        return { H + x * e, H - x * e };
    }
}
