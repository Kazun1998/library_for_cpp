#pragma once

#include "../template/template.hpp"
#include "../template/enumerable.hpp"
#include "../Counting/Combination_Calculator.hpp"

/**
 * @brief ラグランジュ補間を用いた評価点の値の計算 (O(N^2))
 * @details 与えられた n 個の点 (x[i], y[i]) を通る n-1 次以下の多項式 P に対し、P(X) を求める。
 * @tparam F 体を表す型 (ModInt 等)
 * @param x 点の x 座標のリスト (すべて異なる必要がある)
 * @param y 点の y 座標のリスト
 * @param X 評価点
 * @return F P(X) の値
 */
template<typename F>
F Lagrange_Interpolation_Point(const vector<F> &x, const vector<F> &y, F X) {
    assert(x.size() == y.size());
    int n = (int)x.size();

    // 分子の累積積を前計算 O(N)
    vector<F> pre(n + 1, F(1)), suf(n + 1, F(1));
    for (int i = 0; i < n; ++i) pre[i + 1] = pre[i] * (X - x[i]);
    for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] * (X - x[i]);

    F Y = F(0);
    for (int i = 0; i < n; ++i) {
        // 分母の積を計算
        F den = F(1);
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            den *= (x[i] - x[j]);
        }

        Y += y[i] * pre[i] * suf[i + 1] / den;
    }

    return Y;
}

/**
 * @brief ラグランジュ補間を用いた評価点の値の計算 (O(N^2))
 * @details points[i] = (x_i, y_i) を通る n-1 次以下の多項式 P に対し、P(X) を求める。
 * @tparam F 体を表す型
 * @param points 点 (x, y) のリスト
 * @param X 評価点
 * @return F P(X) の値
 */
template<typename F>
F Lagrange_Interpolation_Point(const vector<pair<F, F>> &points, F X) {
    auto x = enumerable::collect(points, [](const auto &p) { return p.first; });
    auto y = enumerable::collect(points, [](const auto &p) { return p.second; });
    return Lagrange_Interpolation_Point(x, y, X);
}

/**
 * @brief ラグランジュ補間を用いた多項式の係数の決定 (O(N^2))
 * @details 与えられた n 個の点 (x[i], y[i]) を通る n-1 次以下の多項式 P(x) = \sum res[i] * x^i を求める。
 * @tparam F 体を表す型
 * @param x 点の x 座標のリスト (すべて異なる必要がある)
 * @param y 点の y 座標のリスト
 * @return vector<F> 多項式の係数リスト res (res[i] は x^i の係数)
 */
template<typename F>
vector<F> Lagrange_Interpolation_Polynomial(const vector<F> &x, const vector<F> &y) {
    assert(x.size() == y.size());
    int n = (int)x.size();
    if (n == 0) return {};

    // Section I: m(x) = \prod (x - xs[i]) を計算
    vector<F> m(n + 1, 0);
    m[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j >= 0; --j) {
            m[j + 1] += m[j];
            m[j] *= -x[i];
        }
    }

    // Section II: m の導関数 m' を求める.
    vector<F> m_diff(n);
    for (int i = 1; i <= n; ++i) {
        m_diff[i - 1] = F(i) * m[i];
    }

    // Section III: f を求める.
    vector<F> res(n, 0);
    for (int i = 0; i < n; ++i) {
        // Evaluate m'(x[i]) using Horner's method
        F val_diff = 0;
        for (int j = n - 1; j >= 0; --j) {
            val_diff = val_diff * x[i] + m_diff[j];
        }

        F weight = y[i] / val_diff;

        // Compute Q_i(x) = m(x) / (x - x[i]) and add weight * Q_i(x) to res
        F q = m[n];
        for (int j = n - 1; j >= 0; --j) {
            res[j] += weight * q;
            q = m[j] + x[i] * q;
        }
    }
    return res;
}

/**
 * @brief ラグランジュ補間を用いた多項式の係数の決定 (O(N^2))
 * @details points[i] = (x_i, y_i) を通る n-1 次以下の多項式 P(x) = \sum res[i] * x^i を求める。
 * @tparam F 体を表す型
 * @param points 点 (x, y) のリスト
 * @return vector<F> 多項式の係数リスト res (res[i] は x^i の係数)
 */
template<typename F>
vector<F> Lagrange_Interpolation_Polynomial(const vector<pair<F, F>> &points) {
    auto x = enumerable::collect(points, [](const auto &p) { return p.first; });
    auto y = enumerable::collect(points, [](const auto &p) { return p.second; });
    return Lagrange_Interpolation_Polynomial(x, y);
}

/**
 * @brief 等差数列上の点におけるラグランジュ補間 (O(N))
 * @details 多項式 P(a*i + b) = y[i] (0 <= i < |y|) を満たす P(s) を求める。
 * @tparam F 体を表す型 (ModInt 等)
 * @param a 等差数列の公差
 * @param b 等差数列の初項
 * @param y 各点における多項式の値のリスト
 * @param s 評価点
 * @return F P(s) の値
 */
template<typename F>
F Lagrange_Interpolation_Point_Arithmetic(const F a, const F b, const vector<F> &y, const F s) {
    int n = (int)y.size();
    if (n == 0) return F(0);
    if (n == 1) return y[0];
    int d = n - 1;

    Combination_Calculator<F> calc(d + 1);

    vector<F> prefix(n), suffix(n);

    // prefix[i] = \prod_{j=0}^i (s - (a*j + b))
    {
        F cur_x = b;
        for (int i = 0; i < n; ++i) {
            prefix[i] = (i == 0 ? s - cur_x : prefix[i - 1] * (s - cur_x));
            cur_x += a;
        }
    }

    // suffix[i] = \prod_{j=i}^d (s - (a*j + b))
    {
        F cur_x = b + a * d;
        for (int i = d; i >= 0; --i) {
            suffix[i] = (i == d ? s - cur_x : suffix[i + 1] * (s - cur_x));
            cur_x -= a;
        }
    }

    // coef = (-a)^{-d}
    F coef = (a == F(1)) ? ((d & 1) ? F(-1) : F(1)) : pow(-a, -d);

    F t = 0;
    for (int i = 0; i < n; ++i) {
        F pre = (i == 0) ? 1 : prefix[i - 1];
        F suf = (i == d) ? 1 : suffix[i + 1];

        F alpha = pre * suf * calc.fact_inv(i) * calc.fact_inv(d - i);
        if (is_odd(i)) alpha = -alpha;

        t += y[i] * alpha;
    }

    return coef * t;
}

/**
 * @brief 連続する整数点におけるラグランジュ補間 (O(N))
 * @details 多項式 P(i) = y[i] (0 <= i < |y|) を満たす P(s) を求める。
 * @tparam F 体を表す型 (ModInt 等)
 * @param y 各点における多項式の値のリスト (x = 0, 1, ..., |y|-1)
 * @param s 評価点
 * @return F P(s) の値
 */
template<typename F>
F Lagrange_Interpolation_Point_Arithmetic(const vector<F> &y, const F s) {
    return Lagrange_Interpolation_Point_Arithmetic<F>(1, 0, y, s);
}
