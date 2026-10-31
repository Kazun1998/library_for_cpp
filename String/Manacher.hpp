#pragma once

// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/String/Manacher.hpp

#include"../template/template.hpp"

// 長さ n の列 data に対して, 長さ (2n - 1) の列 R を返す.
// R[2i]     : 第 i 要素を中心とする最長の奇数長回文の長さ
// R[2i - 1] : 第 (i-1) 要素と第 i 要素の間を中心とする最長の偶数長回文の長さ
template<typename T>
vector<int> Manacher(const vector<T> &data) {
    int n = data.size();
    if (n == 0) {
        return {};
    }

    // odd[i]: 第 i 要素を中心とする奇数長回文の半径 (中心を含む)
    vector<int> odd(n, 1);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(odd[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n && data[i - k] == data[i + k]) {
            k++;
        }

        odd[i] = k;
        if (i + k - 1 > r) {
            l = i - k + 1;
            r = i + k - 1;
        }
    }

    // even[i]: 第 (i-1) 要素と第 i 要素の間を中心とする偶数長回文の半径
    vector<int> even(n, 0);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(even[l + r - i + 1], r - i + 1);
        while (i - k - 1 >= 0 && i + k < n && data[i - k - 1] == data[i + k]) {
            k++;
        }

        even[i] = k;
        if (i + k - 1 > r) {
            l = i - k;
            r = i + k - 1;
        }
    }

    vector<int> R(2 * n - 1);
    for (int i = 0; i < n; i++) {
        R[2 * i] = 2 * odd[i] - 1;
        if (i > 0) {
            R[2 * i - 1] = 2 * even[i];
        }
    }

    return R;
}

vector<int> Manacher(const string &str) {
    return Manacher(vector<char>(str.begin(), str.end()));
}
