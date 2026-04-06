#pragma once

#include "../template/template.hpp"

template<totally_ordered T>
pair<vector<int>, int> Concat_with_Compression(const vector<vector<T>> &sequences) {
    vector<T> coords;
    size_t total_length = 0;
    for (const vector<T> &sequence: sequences) {
        total_length += sequence.size();

        for (const auto &x: sequence) coords.emplace_back(x);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    vector<int> converted;
    converted.reserve(total_length + sequences.size());
    int sentinel = coords.size();

    for (const vector<T> &sequence: sequences) {
        for (const auto &x: sequence) {
            int y = lower_bound(coords.begin(), coords.end(), x) - coords.begin();
            converted.emplace_back(y);
        }

        converted.push_back(sentinel++);
    }

    return { converted, coords.size() };

}