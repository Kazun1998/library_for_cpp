#pragma once

#include"Counter_Clockwise.hpp"
#include"../object/Polygon.hpp"

namespace geometry {
    template<typename R>
    Polygon<R> Convex_Hull(vector<Point<R>> points, bool strict = true) {
        // 前処理
        sort(points.begin(), points.end(), compare_x<R>);
        points.erase(unique(points.begin(), points.end()), points.end());

        int n = points.size();

        if (n <= 2) { return Polygon(points); }

        int k = 0;
        vector<Point<R>> vertices(2 * n);
        auto is_valid = [&](const int i) -> bool { 
            int d = Counter_Clockwise(vertices[k - 2], vertices[k - 1], points[i]);
            return (d == COUNTER_CLOCKWISE || (!strict && d == ONLINE_FRONT));
        };

        for (int i = 0; i < n; vertices[k++] = points[i++]) {
            if (!vertices.empty() && vertices.back() == points[i]) { vertices.pop_back(); }

            while(k >= 2 && !is_valid(i)) {
                k--;
            }
        }

        for (int i = n - 2, t = k + 1; i >= 0; vertices[k++] = points[i--]) {
            if (!vertices.empty() && vertices.back() == points[i]) { vertices.pop_back(); }

            while (k >= t && !is_valid(i)) {
                k--;
            }
        }

        vertices.resize(k - 1);
        return Polygon(vertices);
    }
}
