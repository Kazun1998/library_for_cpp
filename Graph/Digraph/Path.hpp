#pragma once

#include "Digraph.hpp"

namespace digraph {
    template<typename W = Empty>
    struct Path {
        vector<int> vertices;
        vector<Arc<W>> arcs;

        Path(const int first, const vector<Arc<W>> &path): arcs(path) {
            vertices.emplace_back(first);
            for (const auto &arc: path) {
                vertices.emplace_back(arc.target);
            }
        }
    };
}
