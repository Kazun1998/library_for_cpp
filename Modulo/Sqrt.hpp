#pragma once

#include"Modulo.hpp"

namespace modulo {
    // X のルシャンドル記号の結果を求める.
    // X = 0 ならば 0
    // X が平方剰余ならば 1
    // X が平方非剰余ならば -1
    int Legendre(const Modulo &X) {
        if (X.is_zero()) { return 0; }

        return pow(X, (X.n - 1) / 2).is_member(1) ? 1 : -1;
    }

    // Y * Y = X を満たす Y を求める.
    Modulo Sqrt(const Modulo &X) {
        if (Legendre(X) == -1) { throw NotExist(); }

        ll p = X.n;
        if (X.is_zero()) { return X; }
        else if (p == 2) { return X; }
        else if (p % 4 == 3) { return pow(X, (p + 1) / 4); }
        else if (p % 8 == 5) {
            return pow(X, (p - 1) / 4).is_member(1) ? pow(X, (p + 3) / 8) : pow(Modulo(2, p), (p - 1) / 4) * pow(X, (p + 3) / 8);
        }

        ll q = p - 1, s = 0;
        while (mod(q, 2) == 0) { q >>= 1; s++; }

        random_device device;
        Modulo z;
        while (true) {
            z = Modulo(device(), p);
            if (Legendre(z) == -1) { break; }
        }

        int m = s;
        Modulo c = pow(z, q), t = pow(X, q), y = pow(X, (q + 1) / 2);
        while (m > 1) {
            unless (pow(t, intpow(2, m - 2)).is_member(1)) {
                tie (t, y) = make_pair(c * c * t, c * y);
            }

            c *= c;
            m -= 1;
        }


        return y;
    }
}
