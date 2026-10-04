#pragma once

#include "Graph.hpp"

namespace graph {
    struct Path {
        vector<int> vertices;
        vector<Oriented_Edge> edges;

        Path(const int first, const vector<Oriented_Edge> &path): edges(path) {
            vertices.emplace_back(first);
            for (const auto &edge: path) {
                vertices.emplace_back(edge.target);
            }
        }
    };
}
