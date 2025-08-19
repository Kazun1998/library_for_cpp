#pragma once

#include"Modulo.hpp"

namespace Modulo {
    class IncompatibleModuloComposite : public exception {
      public: // publicに指定
      const char* what() const noexcept override { return "合成が存在しません"; }
    };

    Modulo Composite(Modulo A, Modulo B) {
        ll a = A.a, n = A.n;
        ll b = B.a, m = B.n;
        ll d = b - a;
        ll g = gcd(n, m);

        if (d % g) { throw IncompatibleModuloComposite(); }

        n /= g; m /= g; d /= g;

        ll s = Modulo(n, m).inverse().a;

        auto alpha = Modulo(a, n * m * g);
        auto beta = Modulo(n * g, n * m * g);
        auto gamma = Modulo(d * s, n * m * g);

        return alpha + beta * gamma;
    }

    Modulo Composite() { return Modulo(0, 1); }

    template <typename T, typename... Args>
    Modulo Composite(const T& first, const Args&... rest) {
        return Composite(first, Composite(rest...));
    }

    Modulo Composite(vector<Modulo> As) {
        auto res = Modulo(0, 1);
        for (auto A: As) { res = Composite(res, A); }

        return res;
    }
}
