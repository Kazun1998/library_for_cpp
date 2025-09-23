#pragma once

#include"../Line.hpp"

namespace geometry {
    // 点 P が点 X に関して対称移動した後の点を求める.
    template<typename R>
    Point<R> Reflection(const Point<R> &P, const Point<R> &X) {
        return 2 * X - P;
    }
}
