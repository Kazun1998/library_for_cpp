#pragma once

#include "Semilattice_Convolution_Base.hpp"

namespace convolution {
    template<typename R>
    class Bitwise_Or_Convolution: public Semilattice_Convolution_Base<R> {
        using Base = Convolution_Base<R>;
        using ImplBase = Semilattice_Convolution_Base<R>;
        using ImplBase::ImplBase;

        // 加法 (+)
        friend Bitwise_Or_Convolution operator+(const Bitwise_Or_Convolution &lhs, const Bitwise_Or_Convolution &rhs) {
            Bitwise_Or_Convolution temp(lhs);
            temp += rhs;
            return temp;
        }

        // 減法 (-)
        friend Bitwise_Or_Convolution operator-(const Bitwise_Or_Convolution &lhs, const Bitwise_Or_Convolution &rhs) {
            Bitwise_Or_Convolution temp(lhs);
            temp -= rhs;
            return temp;
        }

        // 乗法 (*)
        friend Bitwise_Or_Convolution operator*(const Bitwise_Or_Convolution &lhs, const Bitwise_Or_Convolution &rhs) { 
            Bitwise_Or_Convolution temp(lhs);
            temp *= rhs;
            return temp;
        }

        // スカラー倍 (a * rhs)
        friend Bitwise_Or_Convolution operator*(const R &a, const Bitwise_Or_Convolution &rhs) {
            Bitwise_Or_Convolution temp(rhs);
            temp *= a;
            return temp;
        }

        // スカラー倍 (lhs * a)
        friend Bitwise_Or_Convolution operator*(const Bitwise_Or_Convolution &lhs, const R &a) {
            Bitwise_Or_Convolution temp(lhs);
            temp *= a;
            return temp;
        }

        void zeta_transform(std::vector<R> &f) const override {
            int m = floor_log2(f.size());

            for (size_t i = 0; i < m; i++) {
                for (int S = 0; S < (1 << m); S++) {
                    if (!get_bit(S, i)) { continue; }

                    f[S] += f[S ^ (1 << i)];
                }
            }
        }

        void mobius_transform(std::vector<R> &g) const override {
            int m = floor_log2(g.size());

            for (size_t i = 0; i < m; i++) {
                for (int S = 0; S < (1 << m); S++) {
                    if (!get_bit(S, i)) { continue; }

                    g[S] -= g[S ^ (1 << i)];
                }
            }
        }
    };
}