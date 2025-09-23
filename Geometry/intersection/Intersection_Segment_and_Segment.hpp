#pragma once

#include"../utility/Counter_Clockwise.hpp"
#include"../object/Segment.hpp"

namespace geometry {
    template<typename R>
    bool has_Intersection(const Segment<R> &s, const Segment<R> &t) {
        auto a = s.A, b = s.B, c = t.A, d = t.B;
        return (Counter_Clockwise(a, b, c) * Counter_Clockwise(a, b, d) <= 0) && (Counter_Clockwise(c, d, a) * Counter_Clockwise(c, d, b) <= 0);
    }

    template<typename R>
    Point<R> Intersection(const Segment<R> &s, const Segment<R> &t) {
        auto a = s.A, b = s.B, c = t.A, d = t.B;
        R k = cross(d - a, d - c) / cross(b - a, d - c);
        return a + k * (b - a); 
    }
}
