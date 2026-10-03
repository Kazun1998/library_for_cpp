#pragma once

#include "../template/template.hpp"

namespace convolution {
    template<typename G>
    class Max_Plus_Convolution_Concave {
    public:
        /// @brief f は上に凸 (階差列 Df が広義単調減少) か?
        /// @param f G 上の列
        static bool is_concave(const vector<G> &f) {
            int n = f.size();
            if (n < 2) return true;

            for (int i = 1; i + 1 < n; ++i) {
                // f[i] - f[i - 1] >= f[i + 1] - f[i] を式変形
                unless(2 * f[i] >= f[i - 1] + f[i + 1]) return false;
            }

            return true;
        }

        /// @brief 上に凸な f, g に対して, max-plus 畳み込み h[k] := max_{i + j = k} (f[i] + g[j]) を求める.
        /// @param f, g 上に凸な G 上の列
        static vector<G> convolve(const vector<G> &f, const vector<G> &g) {
            int n = f.size(), m = g.size();

            // 空列の畳み込みは空列
            if ((n == 0) || (m == 0)) return {};

            vector<G> h(n + m - 1);
            int i = 0, j = 0;
            for (int k = 0; k < n + m - 1; ++k) {
                h[k] = f[i] + g[j];

                // i を増やすべき?
                if ((j == m - 1) || (i + 1 < n && f[i + 1] + g[j] >= f[i] + g[j + 1])) {
                    ++i;
                } else {
                    ++j;
                }
            }

            return h;
        }
    };
}
