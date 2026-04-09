#pragma once

#include "Semilattice_Convolution_Base.hpp"

namespace convolution {
    template<typename R>
    class Lcm_Convolution: public Semilattice_Convolution_Base<R> {
        using Base = Convolution_Base<R>;
        using ImplBase = Semilattice_Convolution_Base<R>;
        using ImplBase::ImplBase;

        // 加法 (+)
        friend Lcm_Convolution operator+(const Lcm_Convolution &lhs, const Lcm_Convolution &rhs) {
            Lcm_Convolution temp(lhs);
            temp += rhs;
            return temp;
        }

        // 減法 (-)
        friend Lcm_Convolution operator-(const Lcm_Convolution &lhs, const Lcm_Convolution &rhs) {
            Lcm_Convolution temp(lhs);
            temp -= rhs;
            return temp;
        }

        // 乗法 (*)
        friend Lcm_Convolution operator*(const Lcm_Convolution &lhs, const Lcm_Convolution &rhs) { 
            Lcm_Convolution temp(lhs);
            temp *= rhs;
            return temp;
        }

        // スカラー倍 (a * rhs)
        friend Lcm_Convolution operator*(const R &a, const Lcm_Convolution &rhs) {
            Lcm_Convolution temp(rhs);
            temp *= a;
            return temp;
        }

        // スカラー倍 (lhs * a)
        friend Lcm_Convolution operator*(const Lcm_Convolution &lhs, const R &a) {
            Lcm_Convolution temp(lhs);
            temp *= a;
            return temp;
        }

        void zeta_transform(std::vector<R> &f) const override {
            if (f.empty()) return;

            size_t n = f.size() - 1;
            vector<bool> is_prime(n + 1, true);

            for (int p = 2; p <= n; p++) {
                if (!is_prime[p]) { continue; }

                // 約数変換: f[k*p] に f[k] を足していく (forward)
                for (size_t k = 1; k <= n / p; k++) {
                    is_prime[k * p] = false;
                    f[k * p] += f[k];
                }
            }
        }

        void mobius_transform(std::vector<R> &g) const override {
            if (g.empty()) return;

            size_t n = g.size() - 1;
            vector<bool> is_prime(n + 1, true);

            for (int p = 2; p <= n; p++) {
                if (!is_prime[p]) { continue; }

                // メビウス逆変換: g[k*p] から g[k] を引いていく (backward)
                for (size_t k = n / p; k > 0; k--) {
                    is_prime[k * p] = false;
                    g[k * p] -= g[k];
                }
            }
        }
    };
}
