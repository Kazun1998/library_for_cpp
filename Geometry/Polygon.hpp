#pragma once

#include"Point.hpp"

namespace geometry {
    template<typename R>
    struct Polygon {
        vector<Point<R>> vertices;
        int n;

        Polygon() = default;
        Polygon(const vector<Point<R>> &_vertices): vertices(_vertices), n(_vertices.size()) {}
    };

    template<typename R>
    R Area(const Polygon<R> &X) {
        R area = cross(X.vertices[X.n - 1], X.vertices[0]);
        for (int i = 0; i < X.n - 1; i++) {
            area += cross(X.vertices[i], X.vertices[i + 1]);
        }

        return abs(area) / 2;
    }
}