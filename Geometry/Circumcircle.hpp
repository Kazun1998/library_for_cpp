#pragma once

#include"Circle.hpp"
#include"Circumcenter.hpp"

namespace geometry {
    template<typename R>
    Circle<R> Circumcircle(const Triangle<R> &T) {
        Point<R> center = Circumcenter(T);
        double radius = norm(center - T.A);
        return Circle<R>(center, radius);
    }
}
