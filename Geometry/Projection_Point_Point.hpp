#pragma once

#include"Line.hpp"

namespace geometry {
    // 点 P が点 X に関して対称移動した後の点を求める.
    template<typename R>
    Point<R> Projection(const Point<R> &P, const Point<R> &A) {
        return 2 * A - P;
    }
}
