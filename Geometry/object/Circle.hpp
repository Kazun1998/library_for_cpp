#pragma once

// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/object/Circle.hpp

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
