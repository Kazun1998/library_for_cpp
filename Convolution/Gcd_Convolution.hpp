#include"Commutative_Idempotent_Monoid_Convolution_Base.hpp"

namespace convolution {
    template<typename R>
    class Gcd_Convolution: public Commutative_Idempotent_Monoid_Convolution_Base<R> {
        using Base = Convolution_Base<R>;
        using ImplBase = Commutative_Idempotent_Monoid_Convolution_Base<R>;
        using ImplBase::ImplBase;

        // 加法 (+)
        friend Gcd_Convolution operator+(const Gcd_Convolution &lhs, const Gcd_Convolution &rhs) {
            Gcd_Convolution temp(lhs);
            temp += rhs;
            return temp;
        }

        // 減法 (-)
        friend Gcd_Convolution operator-(const Gcd_Convolution &lhs, const Gcd_Convolution &rhs) {
            Gcd_Convolution temp(lhs);
            temp -= rhs;
            return temp;
        }

        // 乗法 (*)
        friend Gcd_Convolution operator*(const Gcd_Convolution &lhs, const Gcd_Convolution &rhs) { 
            Gcd_Convolution temp(lhs);
            temp *= rhs;
            return temp;
        }

        // スカラー倍 (a * rhs)
        friend Gcd_Convolution operator*(const R &a, const Gcd_Convolution &rhs) {
            Gcd_Convolution temp(rhs);
            temp *= a;
            return temp;
        }

        // スカラー倍 (lhs * a)
        friend Gcd_Convolution operator*(const Gcd_Convolution &lhs, const R &a) {
            Gcd_Convolution temp(lhs);
            temp *= a;
            return temp;
        }

        void zeta_transform(std::vector<R> &f) const override {
            size_t n = f.size() - 1;
            vector<bool> is_prime(n + 1, true);

            for (int p = 2; p <= n; p++) {
                if (!is_prime[p]) { continue; }

                for (size_t k = n / p; k > 0; k--) {
                    is_prime[k * p] = false;
                    f[k] += f[k * p];
                }
            }
        }

        void mobius_transform(std::vector<R> &g) const override {
            size_t n = g.size() - 1;
            vector<bool> is_prime(n + 1, true);

            for (int p = 2; p <= n; p++) {
                if (!is_prime[p]) { continue; }

                for (size_t k = 1; k <= n / p; k++) {
                    is_prime[k * p] = false;
                    g[k] -= g[k * p];
                }
            }
        }
    };
}
