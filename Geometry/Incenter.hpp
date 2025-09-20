#pragma once

#include"Triangle.hpp"

namespace geometry {
    template<typename R>
    Point<R> Incenter(const Triangle<R> &T) { 
        auto [a, b, c] = T.edges();
        return T.balance(a, b, c);
    }
}
