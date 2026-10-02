#pragma once

#include "../template/template.hpp"

namespace convolution {
    template<typename T>
    class Min_Plus_Convolution_Convex {
    public:
        /// @brief f は下に凸 (階差列 Df が広義単調増加) か?
        /// @param f T 上の列
        static bool is_convex(const vector<T> &f) {
            if (f.size() < 2) return true;

            for (int i = 1; i < f.size() - 1; ++i) {
                // f[i] - f[i - 1] <= f[i + 1] - f[i] を式変形
                unless(2 * f[i] <= f[i - 1] + f[i + 1]) return false;
            }

            return true;
        }

        /// @brief 下に凸な f, g に対して, min-plus 畳み込み h[k] := min_{i + j = k} (f[i] + g[j]) を求める.
        /// @param f, g 下に凸な T 上の列
        static vector<T> convolve(const vector<T> &f, const vector<T> &g) {
            int n = f.size(), m = g.size();

            // 空列の畳み込みは空列
            if ((n == 0) || (m == 0)) return {};

            vector<T> h(n + m - 1);
            int i = 0, j = 0;
            for (int k = 0; k < n + m - 1; ++k) {
                h[k] = f[i] + g[j];

                // i を増やすべき?
                if ((j == m - 1) || (i + 1 < n && f[i + 1] + g[j] <= f[i] + g[j + 1])) {
                    ++i;
                } else {
                    ++j;
                }
            }

            return h;
        }
    };
}
