// https://github.com/Kazun1998/library_for_cpp/blob/main/Imos/Cyclic_Imos_1.hpp

#pragma once

#include "../template/template.hpp"

template <typename T>
class Cyclic_Imos_1 {
    private:
    std::vector<T> lazy;
    int n;

    inline int norm(int t) const { return ((t % n) + n) % n; }

    public:
    Cyclic_Imos_1(const int n) : n(n), lazy(n, 0) {}

    /// @brief 周長 n の円環上で, l から r まで (l から時計回りに r まで) の各要素に x を加算する
    /// @details l <= r (mod で正規化した上で) のときは通常の閉区間 [l, r] への加算, l > r のときは [l, n - 1] と [0, r] への加算を意味する.
    /// @param l 始点
    /// @param r 終点
    /// @param x 加算値
    void add(int l, int r, const T x) {
        if (n == 0) return;

        l = norm(l);
        r = norm(r);

        // l <= r : [l, r] が (n-1, 0) をまたがない区間であることを意味する
        if (l <= r) {
            lazy[l] += x;
            if (r + 1 < n) lazy[r + 1] -= x;
        } else {
            lazy[0] += x;
            lazy[r + 1] -= x;
            lazy[l] += x;
        }
    }

    /// @brief 周長 n の円環上で, l から r まで (l から時計回りに r まで) の各要素に 1 を加算する
    /// @param l 始点
    /// @param r 終点
    void add(const int l, const int r) { add(l, r, 1); }

    /// @brief 周長 n の円環上で, 要素 t に x を加算する
    /// @param t 加算する位置
    /// @param x 加算値
    void add_point(const int t, const T x) { add(t, t, x); }

    /// @brief 周長 n の円環上で, l, l + 1, ..., l + (k - 1) の各要素に x を加算する
    /// @param l 始点
    /// @param k 加算する要素数
    /// @param x 加算値
    void add_forward(const int l, const int k, const T x) {
        if (n == 0 || k <= 0) return;

        // q : 円環を何周分加算するか, m : 端数として加算する要素数
        const int q = k / n, m = k % n;
        if (q > 0) add(0, n - 1, x * q);
        if (m > 0) add(l, l + m - 1, x);
    }

    /// @brief 周長 n の円環上で, r, r - 1, ..., r - (k - 1) の各要素に x を加算する
    /// @param r 始点
    /// @param k 加算する要素数
    /// @param x 加算値
    void add_back(const int r, const int k, const T x) {
        if (n == 0 || k <= 0) return;

        // q : 円環を何周分加算するか, m : 端数として加算する要素数
        const int q = k / n, m = k % n;
        if (q > 0) add(0, n - 1, x * q);
        if (m > 0) add(r - m + 1, r, x);
    }

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
