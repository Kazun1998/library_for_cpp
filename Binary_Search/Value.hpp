#include"../template/template.hpp"

// ソート済みの vector<T> A に対して, x 未満で最大の要素を求める.
// A において, x 未満の要素が存在しない場合は, default_value を返り値とする.
// equal = true にすると, 「未満」が「以下」に置きかわる.
template<typename T>
T Binary_Search_Low_Value(const vector<T> &A, T x, T default_value, bool equal = false) {
    auto it = equal ? upper_bound(A.begin(), A.end(), x) : lower_bound(A.begin(), A.end(), x);
    return (it == A.begin()) ? default_value : *(--it);
}

// ソート済みの vector<T> A に対して, x より大きい最小の要素を求める.
// A において, x より大きい要素が存在しない場合は, default_value を返り値とする.
// equal = true にすると, 「より大きい」が「以上」に置きかわる.
template<typename T>
T Binary_Search_High_Value(const vector<T> &A, T x, T default_value, bool equal = false) {
    auto it = equal ? lower_bound(A.begin(), A.end(), x) : upper_bound(A.begin(), A.end(), x);
    return (it == A.end()) ? default_value : *it;
}
