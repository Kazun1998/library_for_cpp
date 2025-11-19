#pragma once

#include"../template/template.hpp"

template<typename T>
vector<int> Z_Algorithm(const vector<T> &data) {
    int n = data.size();
    vector<int> Z(n, 0);
    Z[0] = n;

    for (int i = 1, j = 0, k = 0; i < n; ) {
        while (i + j < n && data[j] == data[i + j]) {
            j++;
        }

        if (j == 0) {
            i++;
            continue;
        }

        Z[i] = j;
        k = 1;
        while ((k < n - i) && (k < j - Z[k])) {
            Z[i + k] = Z[k];
            k++;
        }

        i += k;
        j -= k;
    }

    return Z;
};

vector<int> Z_Algorithm(const string &str) {
    return Z_Algorithm(vector<char>(str.begin(), str.end()));
}
