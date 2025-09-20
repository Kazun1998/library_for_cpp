#pragma once

#include"Point.hpp"

namespace geometry {
    constexpr int COUNTER_CLOCKWISE = +1;
    constexpr int CLOCKWISE = -1;
    constexpr int ONLINE_BACK = -2;   // c-a-b
    constexpr int ONLINE_FRONT = +2;  // a-b-c
    constexpr int ON_SEGMENT = 0;     // a-c-b

    // A -> B -> C と進んだ時の進行方向を調べる (B 視点)
    // Input
    // A: 始点
    // B: 中継地点
    // C: 終点
    template<typename R>
    int Counter_Clockwise(const Point<R> &A, Point<R> B, Point<R> C) {
        B = B - A; C = C - A;
        if (sign(cross(B, C)) == +1) { return COUNTER_CLOCKWISE; }
        if (sign(cross(B, C)) == -1) { return CLOCKWISE; }
        if (sign(dot(B, C)) == -1) { return ONLINE_BACK; }
        if (norm_2(B) < norm_2(C)) { return ONLINE_FRONT; }
        return ON_SEGMENT;
    }
}
