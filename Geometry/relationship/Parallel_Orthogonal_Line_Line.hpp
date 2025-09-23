#pragma once

#include"../object/Line.hpp"

namespace geometry {
    template<typename R>
    Direction_Relation Parallel_Orthogonal (const Line<R> &l, const Line<R> &m) {
        auto u = l.vectorize(), v = m.vectorize();
        if (sign(dot(u, v)) == 0) { return Direction_Relation::ORTHOGONAL; }
        if (sign(cross(u, v)) == 0) { return Direction_Relation::PARALLEL; }
        return Direction_Relation::CROSS;
    }
};
