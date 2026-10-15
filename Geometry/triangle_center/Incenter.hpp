#pragma once

// https://github.com/Kazun1998/library_for_cpp/blob/main/Geometry/triangle_center/Incenter.hpp

#include"../object/Triangle.hpp"

namespace geometry {
    template<typename R>
    Point<R> Incenter(const Triangle<R> &T) { 
        auto [a, b, c] = T.edges();
        return T.balance(a, b, c);
    }
}
