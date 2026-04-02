#pragma once

#include "Graph.hpp"

namespace graph {
    struct Path {
        vector<int> vertices;
        vector<Edge> edges;

        Path(const int first, const vector<Edge> &path): edges(path) {
            vertices.emplace_back(first);
            for (const auto &edge: path) {
                vertices.emplace_back(edge.target);
            }
        }
    };
}
