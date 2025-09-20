#pragma once

#include"Point.hpp"

namespace geometry {
    template<typename R>
    class Triangle {
        public:
        Point<R> A, B, C;

        public:
        Triangle() = default;
        Triangle(const Point<R> a, const Point<R> b, const Point<R> c): A(a), B(b), C(c) {}

        // 辺 BC, 辺 CA, 辺 AB の長さを出力する.
        tuple<double, double, double> edges() const {
            return make_tuple(norm(C - B), norm(A - C), norm(B - A));
        }
    };

    template<typename R>
    R Area(const Triangle<R> &T) {
        return cross(T.B - T.A, T.C - T.A) / 2;
    }
}