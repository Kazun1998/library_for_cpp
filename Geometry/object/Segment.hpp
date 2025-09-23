#pragma once

#include"Point.hpp"

namespace geometry {
    template<typename R>
    struct Segment {
        Point<R> A, B;

        Segment() = default;
        Segment(const Point<R> &A, const Point<R> &B): A(A), B(B) {}

        inline Point<R> vectorize() const { return B - A; }
        inline Point<R> counter_vectorize() const { return A - B; }
        inline double length() const { return norm(vectorize()); }
    };
}
