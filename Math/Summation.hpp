#pragma once

namespace summation {
    template<typename T>
    T linear(T a, T b, T l, T r) {
        if (l > r) return 0;

        T num_terms = r - l + 1;
        T sum_k = num_terms * (l + r) / 2;
        T sum_b = num_terms * b;
        return a * sum_k + sum_b;
    }
}
