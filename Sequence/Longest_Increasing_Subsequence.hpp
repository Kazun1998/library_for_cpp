#pragma once

#include"../template/template.hpp"

template<typename O>
struct Longest_Increasing_Subsequence {
    int length = 0;
    vector<O> lis;
    vector<int> index;
    
    Longest_Increasing_Subsequence(const vector<O> &data, bool equal = false) {
        int N = data.size();
        vector<O> X;
        vector<int> I(N);

        for (int i = 0; i < N; i++) {
            auto it = equal ? upper_bound(X.begin(), X.end(), data[i]) : lower_bound(X.begin(), X.end(), data[i]);
            int k = distance(X.begin(), it);
            if (k == X.size()) { X.emplace_back(data[i]); }
            else { X[k] = data[i]; }

            I[i] = k;
        }

        length = X.size();
        lis.resize(length); index.resize(length);

        for (int i = N - 1, j = length - 1; i >= 0; i--) {
            unless(I[i] == j) { continue; }

            lis[j] = data[i];
            index[j] = i;
            j--;
        }
    }
};
