#pragma once

#include "../template/template.hpp"

template <typename T>
class Imos_1 {
    private:
    std::vector<T> lazy;
    int n;

    bool push(const int t, const int x) {
        if (!(0 <= t && t < n)) return false;

        lazy[t] += x;
        return true;
    }

    public:
    Imos_1(const int n) : n(n), lazy(n, 0) {}

    /// @brief 閉区間 [l, r] の各要素に x を加算
    /// @param l 左端
    /// @param r 右端
    /// @param x 加算値
    void add(int l, int r, const T x) {
        if (l > r) return;
        
        // 範囲内への丸め込み
        if (l < 0) l = 0;
        if (r >= n) r = n - 1;
        
        // 丸め込んだ結果、逆転 or 範囲外なら何もしない
        if (l > r || l >= n || r < 0) return;
    
        push(l, x);
        push(r + 1, -x);
    }

    /// @brief 閉区間 [l, r] の各要素に 1 を加算
    /// @param l 左端
    /// @param r 右端
    void add(const int l, const int r) { add(l, r, 1); }

    /// @brief 累積和を計算する
    std::vector<T> cumulate() {
        if (n == 0) return std::vector<T>();

        std::vector<T> res(lazy.begin(), lazy.end());
        for (int i = 1; i < n; ++i) res[i] += res[i - 1];

        return res;
    }

    /// @brief 内部状態をクリアして、再度 add できる状態にする
    void clear() {
        std::fill(lazy.begin(), lazy.end(), T(0));
    }
};
