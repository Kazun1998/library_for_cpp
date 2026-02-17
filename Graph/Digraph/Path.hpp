#pragma once

#include "Digraph.hpp"

namespace digraph {
    struct Path {
        vector<int> vertices;
        vector<Arc> arcs;

        Path(const int first, const vector<Arc> &path): arcs(path) {
            vertices.emplace_back(first);
            for (const auto &arc: path) {
                vertices.emplace_back(arc.target);
            }
        }
    };
}
