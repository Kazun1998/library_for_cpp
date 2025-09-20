#pragma once

#include"../template/template.hpp"

namespace geometry {
    using Real = double long;
    const Real epsilon = 1e-9;
    const Real pi = acos(static_cast<Real>(-1));

    enum { out = -1, on = 0, in = 1 };
    enum class Direction_Relation { PARALLEL = 1, ORTHOGONAL = -1, CROSS = 0}; 

    inline int sign(const Real &r) { return r <= -epsilon ? -1 : r >= epsilon ? 1: 0; }
    inline int equal(const Real &a, const Real &b) { return sign(a - b) == 0; }

    inline int sign(const ll &r) { return r < 0 ? -1 : r > 0 ? 1 : 0; }
    inline int equal(const ll &a, const ll &b) { return sign(a - b) == 0; }

    inline int sign(const int &r) { return r < 0 ? -1 : r > 0 ? 1 : 0; }
    inline int equal(const int &a, const ll &b) { return sign(a - b) == 0; }
};
