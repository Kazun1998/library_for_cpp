#pragma once

#include"Circle.hpp"
#include"Line.hpp"
#include"Relationship_Circle_and_Circle.hpp"
#include"Tangent_Point_from_Point_to_Circle.hpp"

namespace geometry {
    // 共通接線の円 C における接点
    template<typename R>
    vector<Point<R>> Common_Tangent_Points(const Circle<R> &C, const Circle<R> &D){
        int k = Relationship(C, D);
        vector<Point<R>> tangents;

        R r = C.radius, s = D.radius;
        Point<R> v = D.center - C.center;
        Real d = v.norm(), theta = arg(v);
        Point<Real> op = Point(cos(theta), sin(theta));

        if (k >= 1){
            Real a = r * (r - s) / d, b = sqrt(r * r - a * a);
            tangents.emplace_back(C.center + op * Point(a, b));
            if (k > 1) { tangents.emplace_back(C.center + op * Point(a, -b)); }
        }

        if (k >= 3){
            Real a = r * (r + s) / d, b = sqrt(r * r - a * a);
            tangents.emplace_back(C.center + op * Point(a, b));
            if (k > 3) { tangents.emplace_back(C.center + op * Point(a,-b)); }
        }

        return tangents;
    }
}
