#pragma once

#include "../template/template.hpp"
#include "../template/enumerable.hpp"
#include "../Counting/Combination_Calculator.hpp"

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

template<typename F>
F Lagrange_Interpolation_Point(const vector<pair<F, F>> &points, F X) {
    auto x = enumerable::collect(points, [](const auto &p) { return p.first; });
    auto y = enumerable::collect(points, [](const auto &p) { return p.second; });
    return Lagrange_Interpolation_Point(x, y, X);
}

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

template<typename F>
vector<F> Lagrange_Interpolation_Polynomial(const vector<pair<F, F>> &points) {
    auto x = enumerable::collect(points, [](const auto &p) { return p.first; });
    auto y = enumerable::collect(points, [](const auto &p) { return p.second; });
    return Lagrange_Interpolation_Polynomial(x, y);
}

template<typename F>
F Lagrange_Interpolation_Point_Arithmetic(const F a, const F b, const vector<F> &y, const F s) {
    int n = (int)y.size();
    if (n == 0) return F(0);
    if (n == 1) return y[0];
    int d = n - 1;

    Combination_Calculator<F> calc(d + 1);

    // Precompute s - (a*i + b)
    vector<F> diffs(n);
    F cur_x = b;
    for (int i = 0; i < n; ++i) {
        diffs[i] = s - cur_x;
        cur_x += a;
    }

    vector<F> prefix(n), suffix(n);
    prefix[0] = diffs[0];
    for (int i = 1; i < n; ++i) prefix[i] = prefix[i - 1] * diffs[i];
    suffix[d] = diffs[d];
    for (int i = d - 1; i >= 0; --i) suffix[i] = suffix[i + 1] * diffs[i];

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

template<typename F>
F Lagrange_Interpolation_Point_Arithmetic(const vector<F> &y, const F s) {
    return Lagrange_Interpolation_Point_Arithmetic<F>(1, 0, y, s);
}
