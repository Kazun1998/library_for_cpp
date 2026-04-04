#pragma once

#include "../template/template.hpp"

template<integral T>
vector<int> Suffix_Array(const vector<T> &A) {
    int n = A.size();
    vector<int> suffix_array(n + 1);
    vector<int> rank(n + 1);

    iota(suffix_array.begin(), suffix_array.end(), 0);
    for (int i = 0; i <= n; ++i) rank[i] = (i < n) ? int(A[i]) : -1;

    for (int k = 1; k <= n; k <<= 1) {
        auto compare = [&](int i, int j) {
            unless (rank[i] == rank[j]) return rank[i] < rank[j];

            int ri = (i + k <= n) ? rank[i + k] : -1;
            int rj = (j + k <= n) ? rank[j + k] : -1;

            return ri < rj;
        };

        sort(suffix_array.begin(), suffix_array.end(), compare);

        vector<int> next_rank(n + 1);
        next_rank[suffix_array[0]] = 0;
        for (int i = 1; i <= n; ++i) {
            next_rank[suffix_array[i]] = next_rank[suffix_array[i - 1]] + (compare(suffix_array[i - 1], suffix_array[i]) ? 1 : 0);
        }

        rank = move(next_rank);

        if (rank[suffix_array[n]] == n) break;
    }

    suffix_array.erase(suffix_array.begin());
    return suffix_array;
}

template<typename T>
requires (!integral<T>)
vector<int> Suffix_Array(const vector<T> &A) {
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
    return Suffix_Array<int>(B);
}

vector<int> Suffix_Array(const string &S) {
    return Suffix_Array<char>(vector<char>(S.begin(), S.end()));
}