#pragma once

#include"Modulo.hpp"
#include"Solve.hpp"

namespace modulo {
    vector<ll> Garner_Base(vector<Modulo> X) {
        int n = X.size();
        vector<ll> s(n);

        for (int i = 0; i < n; i++) {
            ll m = X[i].n;

            ll a = 1;
            for (int j = 0; j < i; j++) { a = mod(a * X[j].n, m); }

            ll b = 0, h = 1;
            for (int j = 0; j < i; j++) {
                b = mod(b + s[j] * h, m);
                h = mod(h * X[j].n, m);
            }

            s[i] = Solve_Congruence_Equation(a, X[i].a - b, m).a;
        }

        return s;
    }

    ll Minimize_Garner(vector<Modulo> X, const ll M) {
        vector<ll> s = Garner_Base(X);
        ll y = 0, h = 1;
        for (int i = 0; i < X.size(); i++) {
            y = mod(y + s[i] * h, M);
            h = mod(h * X[i].n, M);
        }

        return y;
    }
}
