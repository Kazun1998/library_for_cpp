#pragma once

#include "../../template/template.hpp"
#include "../../Linear_Algebra/Field_Matrix.hpp"
#include "Graph.hpp"

namespace graph {
    template<typename F>
    F Count_Spanning_Trees(const Graph &G) {
        vector<vector<int>> L_pre = G.laplacian_matrix();

        const int n = G.order();
        Field_Matrix<F> L(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                L[i, j] = F(L_pre[i][j]);
            }
        }

        return Determinant(L);
    }
};
