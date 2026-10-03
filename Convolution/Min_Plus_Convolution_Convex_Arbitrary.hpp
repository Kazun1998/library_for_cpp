#pragma once

#include "../template/template.hpp"

namespace convolution {
    // (min, +) 畳み込み (凸 × 任意)
    template<typename G>
    class Min_Plus_Convolution_Convex_Arbitrary {
    public:
        /// @brief 下に凸な f と任意の g に対して, min-plus 畳み込み h[k] := min_{i + j = k} (f[i] + g[j]) を求める.
        /// @param f 下に凸な G 上の列
        /// @param g (任意の) G 上の列
        static vector<G> convolve(const vector<G> &f, const vector<G> &g) {
            int n = f.size(), m = g.size();

            // 空列の畳み込みは空列
            if ((n == 0) || (m == 0)) return {};

            vector<G> h(n + m - 1);

            // k in [kl, kr) について, h[k] を与える j は [jl, jr) に存在する.
            auto run = [&](auto self, const int kl, const int kr, const int jl, const int jr) -> void {
                if (kl >= kr) return;

                int k = (kl + kr) / 2;

                // j は 0 <= j < m かつ 0 <= k - j < n を満たす必要がある.
                int best_j = max(jl, k - n + 1);
                h[k] = f[k - best_j] + g[best_j];
                for (int j = best_j + 1; j < min({jr, k + 1, m}); ++j) {
                    if (chmin(h[k], f[k - j] + g[j])) {
                        best_j = j;
                    }
                }

                self(self, kl, k, jl, best_j + 1);
                self(self, k + 1, kr, best_j, jr);
            };

            run(run, 0, n + m - 1, 0, m);
            return h;
        }
    };
}
