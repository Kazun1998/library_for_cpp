#pragma

#include"../template/template.hpp"

template<typename T>
T Floor_Linear_Sum(T a, T b, T m, T n) {
    T total = 0;
    T x, y;
    while (true) {
        total += (n - 1) * n / 2 *  div_floor(a, m);
        a = mod(a, m);

        total += n * div_floor(b, m);
        b = mod(b, m);

        y = div_floor(a * n + b, m);
        x = b - y * m;

        if (y == 0) { return total; }

        total += (n + div_floor(x, a)) * y;
        tie(a, b, m, n) = make_tuple(m, mod(x, a), a, y);
    }
}
