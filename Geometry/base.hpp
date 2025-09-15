#pragma once

#include"../template/template.hpp"

namespace geometry {
    using Real = double long;
    const Real epsilon = 1e-9;
    const Real pi = acos(static_cast<Real>(-1));

    enum { out = -1, on = 0, in = 1 };

    inline int sign(const Real &r) { return r <= -epsilon ? -1 : r >= epsilon ? 1: 0; }
    inline int equal(const Real &a, const Real &b) { return sign(a - b) == 0; }
};
