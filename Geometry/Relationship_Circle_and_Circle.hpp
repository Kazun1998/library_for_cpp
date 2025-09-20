#pragma once

#include"Circle.hpp"

namespace geometry {
    template<typename R>
    int Relationship(Circle<R> &C, Circle<R> &D) {
        unless (C.radius < D.radius) { swap(C, D); }

        auto d = norm(C.center - D.center);
        auto r = C.radius, s = D.radius;

        int p = compare(r + s, d);
        if (p == 1) { return 4; }
        else if (p == 0) { return 3; }

        int q = compare(s - r, d);
        if (q == 1) { return 2; }
        else if (q == 0) { return 1; }

        return 0;
    }
}
