#pragma once

#include "Find_Linear_Recurrence.hpp"
#include "../Modulo_Polynomial/Nth_Term_of_Linearly_Recurrent_Sequence.hpp"

/**
 * @brief 数列の接頭辞から第 k 項を予測する
 * @details 
 * 与えられた数列 a から最短線形漸化式を推定し、第 k 項 (0-indexed) を計算する.
 * 
 * @tparam F 体の要素の型
 * @param a 数列の最初の数項
 * @param k 求めたい項のインデックス
 * @return F 予測される第 k 項の値
 * @note 計算量: O(|a|^2 + d log d log k) (d は推定された漸化式の次数)
 */
template <typename F>
F Predict_Nth_Term(const vector<F>& a, long long k) {
    if (k < (int)a.size()) return a[k];
    
    vector<F> c = Find_Linear_Recurrence(a);
    if (c.empty()) return F(0);

    int d = int(c.size());
    vector<F> initial_terms(a.begin(), a.begin() + min<int>(int(a.size()), d));
    return Nth_Term_of_Linearly_Recurrent_Sequence<F>(initial_terms, c, k);
}
