#pragma once

#include "../../template/template.hpp"
#include "../../Linear_Algebra/Field_Matrix.hpp"
#include "Graph.hpp"

namespace graph {
    /**
     * @brief グラフ G の全域木の個数を求める.
     * @details 行列木定理 (Matrix Tree Theorem) を用い、ラプラシアン行列の任意の余因子（ここでは第 (n, n) 余因子）の行列式を計算することで、無向グラフの全域木の個数を求める。計算量は行列式の計算に依存し、通常 O(V^3) となる。
     * @tparam F 計算に使用する体の型 (例: modint など)
     * @param G 対象となる無向グラフ
     * @return F 全域木の個数
     */
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
