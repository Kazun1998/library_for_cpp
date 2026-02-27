#pragma once

#include "../template/template.hpp"

namespace summation {
    template<typename T>
    T linear(T a, T b, T l, T r) {
        if (l > r) return 0;

        T num_terms = r - l + 1;
        T sum_k = num_terms * (l + r) / 2;
        T sum_b = num_terms * b;
        return a * sum_k + sum_b;
    }

    template<typename T>
    T relu_linear(T a, T b, T l, T r) {
        if (a == 0) { return (r - l + 1) * max<T>(0, b); }
        if (a < 0) { return relu_linear(-a, a * (r + l) + b, l, r); }

        // ここに到達した段階で a > 0 が保証される

        if (a * r + b <= 0) return 0;

        T t = max<T>(l, div_ceil(-b, a));

        return linear(a, b, t, r);
    }

    template<typename T>
    T max_linear(T a, T b, T c, T d, T l, T r) {
        return relu_linear(a - c, b - d, l, r) + linear(c, d, l, r);
    }

    template<typename T>
    T min_linear(T a, T b, T c, T d, T l, T r) {
        return -relu_linear(-(a - c), -(b - d), l, r) + linear(c, d, l, r);
    }
}
