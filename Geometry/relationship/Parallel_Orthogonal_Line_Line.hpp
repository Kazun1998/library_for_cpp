#pragma once

#include"../object/Line.hpp"

namespace geometry {
    template<typename R>
    bool is_Parallel(const Line<R> &l, const Line<R> &m) {
        return sign(dot(l.vectorize(), m.vectorize())) == 0;
    }

    template<typename R>
    bool is_Orthogonal(const Line<R> &l, const Line<R> &m) {
        return sign(cross(l.vectorize(), m.vectorize())) == 0;
    }

    template<typename R>
    Direction_Relation Parallel_Orthogonal (const Line<R> &l, const Line<R> &m) {
        if (is_Parallel(l, m)) { return Direction_Relation::ORTHOGONAL; }
        if (is_Orthogonal(l, m)) { return Direction_Relation::PARALLEL; }
        return Direction_Relation::CROSS;
    }
};
