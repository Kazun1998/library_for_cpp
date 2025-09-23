#pragma once

#include"../object/Line.hpp"
#include"../relationship/Parallel_Orthogonal_Line_Line.hpp"

namespace geometry {
    template<typename R>
    bool has_Intersection(const Line<R> &l, const Line<R> &m) {
        if (Parallel_Orthogonal(l, m) == Direction_Relation::CROSS) { return true; }
        return l.include(m.A);
    }

    template<typename R>
    Point<R> Intersection(const Line<R> &l, const Line<R> &m) {
        auto a = l.A, b = l.B, c = m.A, d = m.B;
        R S1 = cross(d - a, d - c), S2 = cross(b - a, d - c);
        R k = S1 / S2;
        return a + k * (b - a);
    }
}
