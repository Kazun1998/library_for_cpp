#pragma once

#include"../template/bitop.hpp"

template<typename M>
class Disjoint_Sparse_Table {
    private:
    int n, height;
    std::vector<std::vector<M>> table;
    const std::function<M(M, M)> op;
    const M unit;

    public:
    Disjoint_Sparse_Table(const std::vector<M> &data, const std::function<M(M, M)> op, const M unit): n(data.size()), op(op), unit(unit), height(n > 0 ? ceil_log2(n) : 0) {
        table = std::vector<std::vector<M>>(height, std::vector<M>(n, unit));

        if (n == 0) { return; }

        // 初段の初期化 → data 配列をそのままコピー

        table[0] = data;

        for (int h = 1; h < height; h++) {
            // h 段目は, 2^h 個のブロックからなる.
            int shift = 1 << h;

            std::vector<M> &row = table[h];

            for (int j = 0; j < n; j += 2 * shift) {
                // 左に伸びる累積積を求める.
                int t = min(j + shift, n);
                if (t - 1 >= j) {
                    row[t - 1] = data[t - 1];
                    for (int k = t - 2; k >= j; k--) { row[k] = op(data[k], row[k + 1]); }
                }

                if (n <= t) { break; }

                // 右に伸びる累積積を求める.
                row[t] = data[t];
                int r = min(t + shift, n);
                for (int k = t + 1; k < r; k++) { row[k] = op(row[k - 1], data[k]); }
            }
        }
    }

    public:
    M product(int l, int r, bool left_close = true, bool right_close = true) const {
        if (!left_close) { l++; }
        if (!right_close) { r--; }

        if (l == r) { return table[0][l]; }
        if (l > r) { return unit; }

        int h = bit_length(l ^ r) - 1;
        return op(table[h][l], table[h][r]);
    }
};
