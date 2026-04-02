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
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                L.mat[i - 1][j - 1] = F(L_pre[i][j]);
            }
        }

        return Determinant(L);
    }
};
