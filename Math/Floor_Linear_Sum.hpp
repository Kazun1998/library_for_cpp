#pragma once

#include"../template/template.hpp"

template<typename T>
T Floor_Linear_Sum(T a, T b, T m, T n) {
    T total = 0;
    T x, y;
    while (true) {
        total += (n - 1) * n / 2 *  div_floor(a, m);
        a = safe_mod(a, m);

        total += n * div_floor(b, m);
        b = safe_mod(b, m);

        y = div_floor(a * n + b, m);
        x = b - y * m;

        if (y == 0) { return total; }

        total += (n + div_floor(x, a)) * y;
        tie(a, b, m, n) = make_tuple(m, safe_mod(x, a), a, y);
    }
}

template<typename T>
T Floor_Linear_Sum(T a, T b, T m, T l, T r) {
    return Floor_Linear_Sum(a, a * l + b, m, r - l + 1);
}

template<typename T>
T Min_of_Mod_of_Linear(T a, T b, T m, T n) {
    T l = 0, r = m;
    T target = Floor_Linear_Sum(a, b, m, n);
    while (r - l > 1) {
        T x = l + (r - l) / 2;
        if (target == Floor_Linear_Sum(a, b - x, m, n)) {
            l = x;
        } else {
            r = x;
        }
    }

    return l;
}