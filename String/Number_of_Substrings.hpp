#pragma once

#include "Longest_Common_Prefix.hpp"

/**
 * @brief 配列 A の連続部分列の種類数を求める.
 * 
 * 接尾辞配列（Suffix Array）と LCP 配列を用いて O(N log N) で計算する.
 * 
 * @tparam T 配列の要素の型
 * @param A 検索対象の配列
 * @return ll 連続部分列の種類数
 */
template<totally_ordered T>
ll Number_of_Continuous_Subsequence(const vector<T> &A) {
    ll n = A.size();
    auto lcp = Longest_Common_Prefix(A);
    ll lcp_sum = accumulate(lcp.begin(), lcp.end(), 0LL);
    return n * (n + 1) / 2 - lcp_sum;
}

/**
 * @brief 文字列 S の部分文字列の種類数を求める.
 * 
 * @param S 検索対象の文字列
 * @return ll 部分文字列の種類数
 */
ll Number_of_Substrings(const string &S) {
    return Number_of_Continuous_Subsequence<char>(vector<char>(S.begin(), S.end()));
}
