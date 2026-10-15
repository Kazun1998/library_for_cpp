#pragma once

// https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/triangle_center/Circumcircle.hpp

#include"../object/Circle.hpp"
#include"Circumcenter.hpp"

namespace geometry {
    template<typename R>
    Circle<R> Circumcircle(const Triangle<R> &T) {
        Point<R> center = Circumcenter(T);
        double radius = norm(center - T.A);
        return Circle<R>(center, radius);
    }
}
