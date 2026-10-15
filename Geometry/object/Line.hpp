#pragma once

// https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/object/Line.hpp

#include"../object/Point.hpp"
#include"../utility/Counter_Clockwise.hpp"

namespace geometry {
    template<typename R>
    struct Line {
        Point<R> A, B;

        Line() = default;
        Line(const Point<R> &A, const Point<R> &B): A(A), B(B) {}

        inline Point<R> vectorize() const { return B - A; }
        inline Point<R> counter_vectorize() const { return A - B; }

        Inclusion include(const Point<R> &P) {
            int m = Counter_Clockwise(A, B, P);
            return (m == ON_SEGMENT || m == ONLINE_BACK || m == ONLINE_FRONT) ? Inclusion::ON : Inclusion::OUT;
        }
    };
}
