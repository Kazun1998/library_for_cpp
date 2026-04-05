#pragma once

#include "Longest_Common_Prefix.hpp"

template<totally_ordered T>
tuple<int, int, int, int> Longest_Common_Continuous_Subsequence(const vector<T> &A, const vector<T> &B) {
    int n = A.size(), m = B.size();

    // Step I: A と B の要素を合わせて座標圧縮を行う
    vector<T> coords;
    coords.reserve(n + m);
    for (const T &a : A) coords.push_back(a);
    for (const T &b : B) coords.push_back(b);
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    // Step II: 座標圧縮後の整数列を生成
    vector<int> C;
    C.reserve(n + m + 1);

    for (const T &a : A) {
        C.push_back(lower_bound(coords.begin(), coords.end(), a) - coords.begin());
    }

    int sentinel = coords.size(); // 番兵
    C.push_back(sentinel); // A と B を区切る番兵

    for (const auto &b : B) {
        C.push_back(lower_bound(coords.begin(), coords.end(), b) - coords.begin());
    }

    // Step III: LCP を計算
    vector<int> suffix_array = Suffix_Array(C);
    vector<int> lcp = Longest_Common_Prefix(C, suffix_array);

    // Step IV: SA における由来が異なる部分における LCP が LCS になる.

    // x 番目の SA が A 由来ならば true, B 由来ならば false
    auto belong = [&](const int x) -> bool { return suffix_array[x] < n; };

    int a = 0, b = -1, c = 0, d = -1, length = 0;
    for (int i = 0; i < n + m; ++i) {
        if (suffix_array[i] == n) continue;
        if (belong(i) == belong(i + 1)) continue;
        unless(chmax(length, lcp[i])) continue;

        int ia = belong(i) ? i : i + 1;
        int ic = belong(i) ? i + 1 : i;

        a = suffix_array[ia];
        b = a + length - 1;
        c = suffix_array[ic] - (n + 1);
        d = c + length - 1;
    }

    return {a, b, c, d};
}

tuple<int, int, int, int> Longest_Common_Substring(const string &S, const string &T) {
    return Longest_Common_Continuous_Subsequence<char>(vector<char>(S.begin(), S.end()), vector<char>(T.begin(), T.end()));
}
