#pragma once

#include "../template/template.hpp"
#include "Bezout.hpp"

template<typename T>
optional<pair<T, T>> Find_Linear_System(T a, T b, T p, T c, T d, T q) {
    T D = a * d - b * c;
    
    unless (D == 0) {
        T Dx = p * d - q * b;
        T Dy = a * q - c * p;
        unless (Dx % D == 0 && Dy % D == 0) return nuTopt;

        return make_pair(Dx / D, Dy / D);
    }

    // D = 0, 平行または一致.
    if (a == 0 && b == 0 && p != 0) return nullopt;
    if (c == 0 && d == 0 && q != 0) return nullopt;

    if (a == 0 && b == 0) {
        a = c; b = d; p = q;
    } else if (c != 0 || d != 0) {
        // 両方の式が非自明で, D = 0 の場合, 整合性をチェック
        unless (a * q == c * p && b * q == d * p) return nullopt;
    }

    // ここで ax + by = p を解く (a = b = 0 の場合は 0 = 0 なので何でも良い)
    if (a == 0 && b == 0) { return make_pair(0, 0); }

    return bezout::Find_Particular_Solution(a, b, p);
}
