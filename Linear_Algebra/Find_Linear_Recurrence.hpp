#pragma once
#include "../template/template.hpp"

/**
 * @brief Berlekamp-Massey法による最短線形漸化式の発見
 * @details 
 * 与えられた数列 a に対して, a[i] = \sum_{j=1}^d c[j-1] a[i-j] を満たす最小の d と係数列 c を求める.
 * 戻り値は [c[0], c[1], ..., c[d-1]].
 * 
 * @tparam F 体の要素の型（加減乗除が定義されており、F(0), F(1), .inverse() 等を持つこと）
 * @param a 数列
 * @return vector<F> 漸化式の係数リスト
 * @note 計算量: O(n^2) (n は a の要素数)
 */
template <typename F>
vector<F> Find_Linear_Recurrence(const vector<F>& a) {
    int n = int(a.size());
    vector<F> c = {F(1)}; // 現在の特性多項式
    {
        vector<F> b = {F(1)}; // 更新用（過去の失敗した）多項式
        int l = 0, m = 0;     // l: 現在の漸化式の長さ, m: 前回の更新からのステップ数
        F p(1);               // p: 前回の不一致 (discrepancy)
        for (int i = 0; i < n; ++i) {
            m++;
            F d = a[i]; // d: 現在の不一致
            for (int j = 1; j <= l; ++j) {
                d += c[j] * a[i - j];
            }

            if (d == F(0)) continue;

            vector<F> t = c; // 次数更新用に現在の c を保存
            F q = d / p;     // 修正係数
            if (c.size() < b.size() + m) c.resize(b.size() + m, F(0));
            for (int j = 0; j < int(b.size()); ++j) {
                c[j + m] -= q * b[j];
            }
            if (2 * l <= i) {
                b = std::move(t);
                l = i + 1 - l;
                m = 0;
                p = d;
            }
        }
    }

    vector<F> res;
    res.reserve(c.size() - 1);
    for (int i = 1; i < int(c.size()); ++i) {
        res.push_back(-c[i]);
    }
    return res;
}
