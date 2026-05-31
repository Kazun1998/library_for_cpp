#pragma once

#include "../template/template.hpp"

#include <vector>
#include <algorithm>

template <typename T>
class Imos_2 {
    private:
    // 差分配列 (h+1 x w+1 にすることで境界外参照を回避)
    std::vector<std::vector<T>> lazy;
    int h, w;

    bool push(const int i, const int j, const T x) {
        if (!(0 <= i && i <= h)) return false;
        if (!(0 <= j && j <= w)) return false;

        lazy[i][j] += x;
        return true;
    }

    public:
    Imos_2(const int h, const int w): lazy(h + 1, std::vector<T>(w + 1, T())), h(h), w(w) {}

    // 閉区間 [u, d] x [l, r] への値 x の加算 (4点更新)
    void add(int u, int d, int l, int r, const T x) {
        // 範囲の正規化
        u = std::max(0, u); l = std::max(0, l);
        d = std::min(h - 1, d); r = std::min(w - 1, r);
        if (u > d || l > r) return;

        push(u, l, x);
        push(u, r + 1, -x);
        push(d + 1, l, -x);
        push(d + 1, r + 1, x);
    }

    // デフォルト値 1 での加算
    void add(const int u, const int d, const int l, const int r) { 
        add(u, d, l, r, T(1)); 
    }

    /// @brief 累積和を計算して結果を返す (累積和作用素 S の適用)
    std::vector<std::vector<T>> cumulate() {
        std::vector<std::vector<T>> res = lazy;
        
        // 列方向 (y) の累積和
        for (int i = 0; i < h; ++i) {
            for (int j = 1; j < w; ++j) {
                res[i][j] += res[i][j - 1];
            }
        }
        // 行方向 (x) の累積和
        for (int i = 1; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                res[i][j] += res[i - 1][j];
            }
        }
        
        // 結果は h x w のサイズに切り詰めて返す
        res.resize(h);
        for(auto& row : res) row.resize(w);
        return res;
    }

    /// @brief 内部状態をクリアして、再度 add できる状態にする
    void clear() {
        for (int i = 0; i <= h; ++i) {
            std::fill(lazy[i].begin(), lazy[i].end(), T(0));
        }
    }
};
