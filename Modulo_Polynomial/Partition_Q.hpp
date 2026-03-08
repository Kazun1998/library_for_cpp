#pragma once

#include"../Algebra/modint.hpp"
#include"Subset_Sum.hpp"

/// @brief n = 0, 1, ..., N に対して, n を異なる整数で分割する方法 (順序違いは同一視) の数を求める
/// @tparam mint 
/// @param N 
/// @return 長さ (N + 1) の vector 型. 第 i 要素は i を異なる整数で分割する方法 (順序違いは同一視) の数
template<typename mint>
vector<mint> Partition_Q(int N) {
    vector<int> A(N);
    iota(A.begin(), A.end(), 1);
    return Subset_Sum<mint>(A, N);
}
