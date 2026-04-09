#pragma once

#include "Suffix_Array.hpp"

template<integral T>
vector<int> Longest_Common_Prefix(const vector<T> &A, const vector<int> &sa) {
    int n = A.size();
    if (n <= 1) return {};
    vector<int> rank(n);
    for (int i = 0; i < n; ++i) rank[sa[i]] = i;

    vector<int> lcp(n - 1);
    int h = 0;
    for (int i = 0; i < n; ++i) {
        if (rank[i] == n - 1) continue;

        int j = sa[rank[i] + 1];
        while (i + h < n && j + h < n && A[i + h] == A[j + h]) h++;

        lcp[rank[i]] = h;

        if (h > 0) h--;
    }

    return lcp;
}

template<integral T>
vector<int> Longest_Common_Prefix(const vector<T> &A) {
    return Longest_Common_Prefix(A, Suffix_Array(A));
}

template<typename T>
requires (!integral<T> && totally_ordered<T>)
vector<int> Longest_Common_Prefix(const vector<T> &A) {
    int n = A.size();
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return A[i] < A[j]; });

    vector<int> B(n);
    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && A[idx[i - 1]] < A[idx[i]]) r++;
        B[idx[i]] = r;
    }
    return Longest_Common_Prefix<int>(B);
}

vector<int> Longest_Common_Prefix(const string &S) {
    return Longest_Common_Prefix<char>(vector<char>(S.begin(), S.end()));
}
