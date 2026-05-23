#pragma once

#include "Longest_Common_Prefix.hpp"
#include "Concat_with_Compression.hpp"

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

template<totally_ordered T>
ll Number_of_Continuous_Subsequence(const vector<vector<T>> &As) {
    ll k = As.size();

    // Step I: 各文字列の長さから, 候補となる部分文字列の数を求める.
    ll n_sum = 0, candidates = 0;
    for (const vector<T> A: As) {
        ll n = A.size();
        candidates += n * (n + 1) / 2;
        n_sum += n;
    }

    // Step II: A に出てくる全ての要素に対する座標圧縮を行う. また, 全てを連結させた 1 つの列を作成する.
    auto [B, ignore] = Concat_with_Compression(As);

    const vector<int> lcp = Longest_Common_Prefix(B);

    return candidates - accumulate(lcp.begin(), lcp.end(), 0LL);
}

ll Number_of_Substrings(const vector<string> &Ss) {
    vector<vector<char>> As(Ss.size());
    for (int i = 0; i < Ss.size(); ++i) {
        As[i] = vector<char>(Ss[i].begin(), Ss[i].end());
    }

    return Number_of_Continuous_Subsequence<char>(As);
}
