// https://github.com/Kazun1998/library_for_cpp/blob/main/Imos/Sparse_Cyclic_Imos_1.hpp
#pragma once

#include "../template/template.hpp"

template <typename T, typename I = long long>
class Sparse_Cyclic_Imos_1 {
    private:
    std::map<I, T> diff;
    I n;

    inline I norm(I t) const { return ((t % n) + n) % n; }

    public:
    Sparse_Cyclic_Imos_1(const I n) : n(n) {}

    /// @brief 周長 n の円環上で, l から r まで (l から時計回りに r まで) の各要素に x を加算する
    /// @details l <= r (mod で正規化した上で) のときは通常の閉区間 [l, r] への加算, l > r のときは [l, n - 1] と [0, r] への加算を意味する.
    /// @param l 始点
    /// @param r 終点
    /// @param x 加算値
    void add(I l, I r, const T x = 1) {
        if (n == 0) return;

        l = norm(l);
        r = norm(r);

        // l <= r : [l, r] が (n-1, 0) をまたがない区間であることを意味する
        if (l <= r) {
            diff[l] += x;
            if (r + 1 < n) diff[r + 1] -= x;
        } else {
            diff[0] += x;
            diff[r + 1] -= x;
            diff[l] += x;
        }
    }

    /// @brief 周長 n の円環上で, 要素 t に x を加算する
    /// @param t 加算する位置
    /// @param x 加算値
    void add_point(const I t, const T x) { add(t, t, x); }

    /// @brief 周長 n の円環上で, l, l + 1, ..., l + (k - 1) の各要素に x を加算する
    /// @param l 始点
    /// @param k 加算する要素数
    /// @param x 加算値
    void add_forward(const I l, const I k, const T x) {
        if (n == 0 || k <= 0) return;

        // q : 円環を何周分加算するか, m : 端数として加算する要素数
        const I q = k / n, m = k % n;
        if (q > 0) add(0, n - 1, x * q);
        if (m > 0) add(l, l + m - 1, x);
    }

    /// @brief 周長 n の円環上で, r, r - 1, ..., r - (k - 1) の各要素に x を加算する
    /// @param r 始点
    /// @param k 加算する要素数
    /// @param x 加算値
    void add_back(const I r, const I k, const T x) {
        if (n == 0 || k <= 0) return;

        // q : 円環を何周分加算するか, m : 端数として加算する要素数
        const I q = k / n, m = k % n;
        if (q > 0) add(0, n - 1, x * q);
        if (m > 0) add(r - m + 1, r, x);
    }

    /// @brief これまでの加算クエリを円環全体 [0, n - 1] について累積する
    /// @return (y, l, r) という形のリスト. l <= x <= r の範囲においては累積和が y であることを意味する.
    std::vector<std::tuple<T, I, I>> cumulative() {
        std::vector<std::tuple<T, I, I>> res;
        if (n == 0) return res;

        T cum = 0;
        I t_old = 0;

        for (const auto &[t, d] : diff) {
            if (t > n - 1) break;
            if (d == 0) continue;

            if (t_old <= t - 1) res.emplace_back(cum, t_old, t - 1);

            cum += d;
            t_old = t;
        }

        if (t_old <= n - 1) res.emplace_back(cum, t_old, n - 1);

        return res;
    }

    /// @brief 内部状態をクリアして、再度 add できる状態にする
    void clear() {
        diff.clear();
    }
};
