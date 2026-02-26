#pragma once

#include"Modulo.hpp"

namespace modulo {
    /// @brief Legendre 記号 (A/p) を求める.
    /// @param A
    /// @return A = 0 ならば 0, A が平方剰余ならば 1, A が平方非剰余ならば -1.
    int Legendre(const Modulo &A) {
        if (A.is_zero()) return 0;

        return pow(A, (A.n - 1) / 2).is_member(1) ? 1 : -1;
    }

    /// @brief X * X = A を満たす Y を 1 つ求める. 存在しない場合は NotExist 例外を raise.
    /// @param A
    /// @return X * X = A を満たす Y のどれか 1 つ
    optional<Modulo> Sqrt(const Modulo &A) {
        if (Legendre(A) == -1) return nullopt;

        ll p = A.n;
        if (A.is_zero()) return A;
        else if (p == 2) return A;
        else if (p % 4 == 3) return pow(A, (p + 1) / 4);
        else if (p % 8 == 5) {
            if (pow(A, (p - 1) / 4).is_member(1)) return pow(A, (p + 3) / 8);
            else return pow(Modulo(2, p), (p - 1) / 4) * pow(A, (p + 3) / 8);
        }

        ll q = p - 1, s = 0;
        while (safe_mod(q, 2) == 0) { q >>= 1; s++; }

        random_device device;
        Modulo z;
        while (true) {
            z = Modulo(device(), p);
            if (Legendre(z) == -1) break;
        }

        int m = s;
        Modulo c = pow(z, q), t = pow(A, q), x = pow(A, (q + 1) / 2);
        while (m > 1) {
            unless (pow(t, intpow(2, m - 2)).is_member(1)) {
                tie (t, x) = make_pair(c * c * t, c * x);
            }

            c *= c;
            m --;
        }

        return x;
    }
}
