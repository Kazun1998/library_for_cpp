#pragma once

#include "../template/template.hpp"

template <typename T>
class Linear_Imos_1 {
    private:
    std::vector<T> slope;
    std::vector<T> intercept;
    int n;

    void push(int t, T a, T b) {
        if (!(0 <= t && t <= n)) return;
        intercept[t] += a;
        slope[t] += b;
    }

    public:
    Linear_Imos_1(const int n) : n(n), slope(n + 1, 0), intercept(n + 1, 0) {}

    /// @brief 閉区間 [l, r] の各要素 i に対し、一次式 a * (i - l) + b を加算する
    /// @details 閉区間 [l, r] に次のように加算する.
    /// I[l] += b, I[l + 1] += a + b, I[l + 2] += 2a + b, ..., I[r] += (r - l)a + b
    /// @param l 左端
    /// @param r 右端
    /// @param a 傾き (公差)
    /// @param b 定数項 (初項)
    void add(int l, int r, const T a, const T b) {
        if (l > r) return;

        // 範囲の丸め込み
        if (l < 0) l = 0;
        if (r >= n) r = n - 1;
        if (l > r || l >= n || r < 0) return;

        // a(i - l) + b = a*i + (b - a*l)
        push(l, b - a * l, a);
        push(r + 1, -(b - a * l), -a);
    }

    /// @brief 閉区間 [l, r] の各要素に定数 x を加算する
    /// @details 閉区間 [l, r] に次のように加算する.
    /// I[l] += x, I[l + 1] += x, ..., I[r] += x
    /// @param l 左端
    /// @param r 右端
    /// @param x 加算値
    void add(int l, int r, const T x) { add(l, r, 0, x); }

    /// @brief 閉区間 [l, r] の各要素 i に対し、(i - l) + 1 を加算する (1, 2, 3, ... の等差数列)
    /// @details 閉区間 [l, r] に次のように加算する.
    /// I[l] += 1, I[l + 1] += 2, ..., I[r] += (r - l) + 1
    /// @param l 左端
    /// @param r 右端
    void add(int l, int r) { add(l, r, T(1), T(1)); }

    /// @brief 閉区間 [l, l + 2m] にテント型（山型）の等差数列を加算する
    /// @details 閉区間 [l, l + 2m] に次のように山型に加算する.
    /// I[l] += a, I[l + 1] += a + b, I[l + 2] += a + 2b, ..., I[l + m] += a + mb
    /// I[l + m + 1] += a + (m - 1)b, I[l + m + 2] += a + (m - 2)b, ..., I[l + 2m - 1] += a + b, I[l + 2m] += a
    /// @param l 左端
    /// @param m 頂点までの距離 (山の裾野の長さ)
    /// @param a 裾野の開始値
    /// @param b 傾き (公差)
    void add_tent(int l, int m, const T a, const T b) {
        if (m < 0) return;
        add(l, l + m, b, a);
        add(l + m + 1, l + 2 * m, -b, a + (m - 1) * b);
    }

    /// @brief 閉区間 [t, t + m - 1] への一様な a の加算を、t = l, l + 1, ..., l + k - 1 について行う
    /// @param l 操作の始点
    /// @param k 操作の回数
    /// @param m 1 回の操作で加算する項の数
    /// @param a 加算する値
    void add_slide_multiple(int l, int k, int m, const T a) {
        if (k <= 0 || m <= 0) return;
        int s = std::min(k, m), lb = std::max(k, m);
        add(l, l + s - 1, a, a);
        add(l + s, l + lb - 1, (T)s * a);
        add(l + lb, l + k + m - 2, -a, (T)(s - 1) * a);
    }

    inline int size() const { return n; }

    /// @brief 累積和を計算する
    std::vector<T> cumulate() {
        if (n == 0) return std::vector<T>();

        std::vector<T> res(n);
        T s = 0, ic = 0;
        for (int i = 0; i < n; ++i) {
            s += slope[i];
            ic += intercept[i];
            res[i] = s * i + ic;
        }

        return res;
    }

    /// @brief 内部状態をクリアして、再度 add できる状態にする
    void clear() {
        std::fill(slope.begin(), slope.end(), T(0));
        std::fill(intercept.begin(), intercept.end(), T(0));
    }
};
