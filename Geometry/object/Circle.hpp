#pragma once

#include"Point.hpp"

namespace geometry {
    template<typename R>
    class Circle {
        public:
        Point<R> center;
        R radius;

        public:
        Circle() = default;
        Circle(const Point<R> &_center, const R &_radius): center(_center), radius(_radius) {}
    };

    template<typename R>
    R Area(const Circle<R> &C) { return pi * C.radius * C.radius; }
}
