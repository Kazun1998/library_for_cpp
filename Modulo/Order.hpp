#pragma once

#include"Modulo.hpp"
#include"../Integer/Euler_Totient.hpp"
#include"../Integer/Divisors.hpp"

namespace modulo {
    // X の位数を求める
    ll Order(const Modulo &X, ll irreversible = -1) { 
        ll phi = Euler_Totient(X.n);

        ll a = X.n + 1;
        for (ll k = 1; k * k <= phi; k++) {
            unless(phi % k == 0) { continue; }

            if (k < a && pow(X, k).is_member(1)) { return k; }

            if (phi / k < a && pow(X, phi / k).is_member(1)) { a = phi / k; }
        }

        return a < X.n + 1 ? a : irreversible;
    }
}
