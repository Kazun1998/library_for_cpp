#pragma once

#include"../template/template.hpp"

template<typename T>
ll Binary_Search_Small_Count(const vector<T> &A, const T &x, const bool equal = false) {
    auto it = equal ? upper_bound(A.begin(), A.end(), x) : lower_bound(A.begin(), A.end(), x);
    return distance(A.begin(), it);
}

template<typename T>
ll Binary_Search_Large_Count(const vector<T> &A, const T &x, const bool equal = false) {
    auto it = equal ? lower_bound(A.begin(), A.end(), x) : upper_bound(A.begin(), A.end(), x);
    return distance(it, A.end());
}

template<typename T>
ll Binary_Search_Range_Count(const vector<T> &A, const T &x, const T &y, const bool left_equal = true, const bool right_equal = false) {
    auto l_it = left_equal ? lower_bound(A.begin(), A.end(), x) : upper_bound(A.begin(), A.end(), x);
    auto r_it = right_equal ? upper_bound(A.begin(), A.end(), y) : lower_bound(A.begin(), A.end(), y);
    return max(ll(0), ll(distance(l_it, r_it)));
}
