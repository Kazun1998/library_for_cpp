#pragma once

#include"Point.hpp"

namespace geometry {
    template<typename R>
    void Argument_Sort(vector<Point<R>> &points) {
        function<int(Point<R>)> section = [](const Point<R> &P) {
            int sx = sign(P.x), sy = sign(P.y);
            if (sy != 0) { return sy; }
            return -sx;
        };

        function<bool(Point<R>, Point<R>)> cmp = [&](const Point<R> &P, const Point<R> &Q) {
            int sp = section(P), sq = section(Q);
            if (sp != sq) { return sp < sq; }
            return sign(cross(P, Q)) > 0;
        };

        sort(points.begin(), points.end(), cmp);
    }
}
