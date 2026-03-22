#pragma once

#include "../template/template.hpp"

namespace summation {
    /**
     * @brief 等差数列の和を求めます.
     * 
     * sum_{k=l}^{r} (a * k + b)
     * 
     * @tparam T 整数型
     * @param a 係数 a
     * @param b 定数 b
     * @param l 下限
     * @param r 上限
     * @return T 総和
     */
    template<typename T>
    T linear(T a, T b, T l, T r) {
        if (l > r) return 0;

        T num_terms = r - l + 1;
        T sum_k = num_terms * (l + r) / 2;
        T sum_b = num_terms * b;
        return a * sum_k + sum_b;
    }

    /**
     * @brief ReLU(一次関数) の和を求めます.
     * 
     * sum_{k=l}^{r} max(0, a * k + b)
     * 
     * @tparam T 整数型
     * @param a 係数 a
     * @param b 定数 b
     * @param l 下限
     * @param r 上限
     * @return T 総和
     */
    template<typename T>
    T relu_linear(T a, T b, T l, T r) {
        if (a == 0) { return (r - l + 1) * max<T>(0, b); }
        if (a < 0) { return relu_linear(-a, a * (r + l) + b, l, r); }

        // ここに到達した段階で a > 0 が保証される

        if (a * r + b <= 0) return 0;

        T t = max<T>(l, div_ceil(-b, a));

        return linear(a, b, t, r);
    }

    /**
     * @brief 2つの一次関数の最大値の和を求めます.
     * 
     * sum_{k=l}^{r} max(a * k + b, c * k + d)
     * 
     * @tparam T 整数型
     * @param a 第1の一次関数の係数 a
     * @param b 第1の一次関数の定数 b
     * @param c 第2の一次関数の係数 c
     * @param d 第2の一次関数の定数 d
     * @param l 下限
     * @param r 上限
     * @return T 総和
     */
    template<typename T>
    T max_linear(T a, T b, T c, T d, T l, T r) {
        return relu_linear(a - c, b - d, l, r) + linear(c, d, l, r);
    }

    /**
     * @brief 一次関数と定数の最大値の和を求めます.
     * 
     * sum_{k=l}^{r} max(a * k + b, d)
     * 
     * @tparam T 整数型
     * @param a 係数 a
     * @param b 定数 b
     * @param d 定数 d
     * @param l 下限
     * @param r 上限
     * @return T 総和
     */
    template<typename T>
    T max_linear(T a, T b, T d, T l, T r) { return max_linear(a, b, 0, d, l, r); }

    /**
     * @brief 2つの一次関数の最小値の和を求めます.
     * 
     * sum_{k=l}^{r} min(a * k + b, c * k + d)
     * 
     * @tparam T 整数型
     * @param a 第1の一次関数の係数 a
     * @param b 第1の一次関数の定数 b
     * @param c 第2の一次関数の係数 c
     * @param d 第2の一次関数の定数 d
     * @param l 下限
     * @param r 上限
     * @return T 総和
     */
    template<typename T>
    T min_linear(T a, T b, T c, T d, T l, T r) {
        return -relu_linear(-(a - c), -(b - d), l, r) + linear(c, d, l, r);
    }

    /**
     * @brief 一次関数と定数の最小値の和を求めます.
     * 
     * sum_{k=l}^{r} min(a * k + b, d)
     * 
     * @tparam T 整数型
     * @param a 係数 a
     * @param b 定数 b
     * @param d 定数 d
     * @param l 下限
     * @param r 上限
     * @return T 総和
     */
    template<typename T>
    T min_linear(T a, T b, T u, T l, T r) { return min_linear(a, b, 0, u, l, r); }

    /**
     * @brief 一次関数の絶対値の和を求めます.
     * 
     * sum_{k=l}^{r} |a * k + b|
     * 
     * @tparam T 整数型
     * @param a 係数 a
     * @param b 定数 b
     * @param l 下限
     * @param r 上限
     * @return T 総和
     */
    template<typename T>
    T abs_linear(T a, T b, T l, T r) {
        return max_linear(a, b, -a, -b, l, r);
    }

    /**
     * @brief 一次関数を範囲 [d, u] に収めた値の和を求めます.
     * 
     * sum_{k=l}^{r} clamp(a * k + b, d, u)
     * clamp(x, d, u) = min(max(x, d), u)
     * 
     * @tparam T 整数型
     * @param a 係数 a
     * @param b 定数 b
     * @param d 下限値 d
     * @param u 上限値 u
     * @param l 総和の下限
     * @param r 総和の上限
     * @return T 総和
     */
    template<typename T>
    T clamp_linear(T a, T b, T d, T u, T l, T r) {
        return linear(a, b, l, r) - relu_linear(a, b - u, l, r) + relu_linear(-a, d - b, l, r);
    }

    /**
     * @brief 0 から n までの二乗和を求めます.
     * 
     * sum_{k=0}^{n} k^2
     * 
     * @tparam T 整数型
     * @param n 上限
     * @return T 総和
     */
    template<typename T>
    T sum_sq(T n) {
        if (n < 0) return 0;
        return n * (n + 1) * (2 * n + 1) / 6;
    }

    /**
     * @brief 一次関数の二乗の和を求めます.
     * 
     * sum_{k=l}^{r} (a * k + b)^2
     * 
     * @tparam T 整数型
     * @param a 係数 a
     * @param b 定数 b
     * @param l 下限
     * @param r 上限
     * @return T 総和
     */
    template<typename T>
    T square_linear(T a, T b, T l, T r) {
        if (l > r) return 0;
        T sum_1 = (r - l + 1) * (l + r) / 2;
        T sum_2 = sum_sq(r) - sum_sq(l - 1);
        return a * a * sum_2 + 2 * a * b * sum_1 + b * b * (r - l + 1);
    }

    /**
     * @brief 2つの一次関数の積の和を求めます.
     * 
     * sum_{k=l}^{r} (a * k + b) * (c * k + d)
     * 
     * @tparam T 整数型
     * @param a 第1の一次関数の係数 a
     * @param b 第1の一次関数の定数 b
     * @param c 第2の一次関数の係数 c
     * @param d 第2の一次関数の定数 d
     * @param l 下限
     * @param r 上限
     * @return T 総和
     */
    template<typename T>
    T sum_product_linear(T a, T b, T c, T d, T l, T r) {
        if (l > r) return 0;
        T n = r - l + 1;
        T sum_k = n * (l + r) / 2;
        T sum_k2 = sum_sq(r) - sum_sq(l - 1);
        return a * c * sum_k2 + (a * d + b * c) * sum_k + b * d * n;
    }

    /**
     * @brief 2つの ReLU(一次関数) の積の和を求めます.
     * 
     * sum_{k=l}^{r} relu(a * k + b) * relu(c * i + d)
     * 
     * @tparam T 整数型
     * @param a 第1の一次関数の係数 a
     * @param b 第1の一次関数の定数 b
     * @param c 第2の一次関数の係数 c
     * @param d 第2の一次関数の定数 d
     * @param l 下限
     * @param r 上限
     * @return T 総和
     */
    template<typename T>
    T product_relu_linear(T a, T b, T c, T d, T l, T r) {
        T L = l, R = r;

        if (a > 0) L = max<T>(L, div_ceil(-b, a));
        else if (a < 0) R = min<T>(R, div_floor(-b, a));
        else if (b < 0) return 0;

        if (c > 0) L = max<T>(L, div_ceil(-d, c));
        else if (c < 0) R = min<T>(R, div_floor(-d, c));
        else if (d < 0) return 0;

        if (L > R) return 0;

        return sum_product_linear(a, b, c, d, L, R);
    }
}
