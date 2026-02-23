#pragma once

#include "../template/template.hpp"

template<typename T>
vector<int> Slide_Maximum_Index(const vector<T>& data, const int k) {
    const int n = data.size();
    std::vector<int> index(n);
    std::deque<T> Q;

    for (int i = 0; i < n; ++i) {
        if (!Q.empty() && Q.front() <= i - k) Q.pop_front();

        while (!Q.empty() && data[Q.back()] < data[i]) Q.pop_back();

        Q.push_back(i);
        index[i] = Q.front();
    }

    return vector<int>(index.begin() + k - 1, index.end());
}

template<typename T>
vector<T> Slide_Maximum_Value(const vector<T> &data, const int k) {
    int m = data.size() - k + 1;
    vector<int> index = Slide_Maximum_Index(data, k);

    vector<T> res(m);
    for (int i = 0; i < m; i++) res[i] = data[index[i]];

    return res;
}
