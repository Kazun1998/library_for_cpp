#pragma once

#include"Circle.hpp"
#include"Incenter.hpp"

namespace geometry {
    template<typename R>
    Circle<R> Incircle(const Triangle<R> &T) {
        Point<R> center = Incenter(T);
        auto [a, b, c] = T.edges();
        double radius = (2 * Area(T)) / (a + b + c);
        return Circle<R>(center, radius);
    }
}
