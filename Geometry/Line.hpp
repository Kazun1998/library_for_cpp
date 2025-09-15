#pragma once

#include"Point.hpp"

namespace geometry {
    template<typename R>
    struct Line {
        Point<R> A, B;

        Line() = default;
        Line(const Point<R> &A, const Point<R> &B): A(A), B(B) {}

        inline Point<R> vectorize() const { return B - A; }
        inline Point<R> counter_vectorize() const { return A - B; }
    };
}