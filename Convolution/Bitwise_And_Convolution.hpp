#pragma once

#include"Commutative_Idempotent_Monoid_Convolution_Base.hpp"

namespace convolution {
    template<typename R>
    class Bitwize_And_Convolution: public Commutative_Idempotent_Monoid_Convolution_Base<R> {
        using Base = Convolution_Base<R>;
        using ImplBase = Commutative_Idempotent_Monoid_Convolution_Base<R>;
        using ImplBase::ImplBase;

        // 加法 (+)
        friend Bitwize_And_Convolution operator+(const Bitwize_And_Convolution &lhs, const Bitwize_And_Convolution &rhs) {
            Bitwize_And_Convolution temp(lhs);
            temp += rhs;
            return temp;
        }

        // 減法 (-)
        friend Bitwize_And_Convolution operator-(const Bitwize_And_Convolution &lhs, const Bitwize_And_Convolution &rhs) {
            Bitwize_And_Convolution temp(lhs);
            temp -= rhs;
            return temp;
        }

        // 乗法 (*)
        friend Bitwize_And_Convolution operator*(const Bitwize_And_Convolution &lhs, const Bitwize_And_Convolution &rhs) { 
            Bitwize_And_Convolution temp(lhs);
            temp *= rhs;
            return temp;
        }

        // スカラー倍 (a * rhs)
        friend Bitwize_And_Convolution operator*(const R &a, const Bitwize_And_Convolution &rhs) {
            Bitwize_And_Convolution temp(rhs);
            temp *= a;
            return temp;
        }

        // スカラー倍 (lhs * a)
        friend Bitwize_And_Convolution operator*(const Bitwize_And_Convolution &lhs, const R &a) {
            Bitwize_And_Convolution temp(lhs);
            temp *= a;
            return temp;
        }

        void zeta_transform(std::vector<R> &f) const override {
            int m = floor_log2(f.size());

            for (size_t i = 0; i < m; i++) {
                for (int S = 0; S < (1 << m); S++) {
                    if (get_bit(S, i)) { continue; }

                    f[S] += f[S | (1 << i)];
                }
            }
        }

        void mobius_transform(std::vector<R> &g) const override {
            int m = floor_log2(g.size());

            for (size_t i = 0; i < m; i++) {
                for (int S = 0; S < (1 << m); S++) {
                    if (get_bit(S, i)) { continue; }

                    g[S] -= g[S | (1 << i)];
                }
            }
        }
    };
}
