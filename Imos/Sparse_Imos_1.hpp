#pragma once

#include "../template/template.hpp"

template <typename T, typename I = long long>
class Sparse_Imos_1 {
    private:
    std::map<I, T> diff;

    public:
    Sparse_Imos_1() {}

    /// @brief 閉区間 [l, r] に x を加算する
    /// @param l 左端
    /// @param r 右端
    /// @param x 加算する値
    void add(const I l, const I r, const T x = 1) {
        if (l > r) return;

        diff[l] += x;
        diff[r + 1] -= x;
    }

    /// @brief since から until までの累積和を求める
    /// @param since 始点
    /// @param until 終点
    /// @return (y, l, r) という形のリスト. l <= x <= r の範囲においては累積和が y であることを意味する.
    std::vector<std::tuple<T, I, I>> cumulative(const I since, const I until) {
        std::vector<std::tuple<T, I, I>> res;

        T cum = 0;
        I t_old = since;

        for (const auto &[t, d] : diff) {
            if (t > until) break;
            if (d == 0) continue;

            if (t_old <= t - 1) res.emplace_back(cum, t_old, t - 1);

            cum += d;
            t_old = t;
        }

        if (t_old <= until) res.emplace_back(cum, t_old, until);

        return res;
    }

    /// @brief 内部状態をクリアして、再度 add できる状態にする
    void clear() {
        diff.clear();
    }
};
