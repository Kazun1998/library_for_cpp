#pragma once

#include "Semilattice_Convolution_Base.hpp"

namespace convolution {
    template<typename R>
    class Min_Convolution: public Semilattice_Convolution_Base<R> {
        using Base = Convolution_Base<R>;
        using ImplBase = Semilattice_Convolution_Base<R>;
        using ImplBase::ImplBase;

        // 加法 (+)
        friend Min_Convolution operator+(const Min_Convolution &lhs, const Min_Convolution &rhs) {
            Min_Convolution temp(lhs);
            temp += rhs;
            return temp;
        }

        // 減法 (-)
        friend Min_Convolution operator-(const Min_Convolution &lhs, const Min_Convolution &rhs) {
            Min_Convolution temp(lhs);
            temp -= rhs;
            return temp;
        }

        // 乗法 (*)
        friend Min_Convolution operator*(const Min_Convolution &lhs, const Min_Convolution &rhs) { 
            Min_Convolution temp(lhs);
            temp *= rhs;
            return temp;
        }

        // スカラー倍 (a * rhs)
        friend Min_Convolution operator*(const R &a, const Min_Convolution &rhs) {
            Min_Convolution temp(rhs);
            temp *= a;
            return temp;
        }

        // スカラー倍 (lhs * a)
        friend Min_Convolution operator*(const Min_Convolution &lhs, const R &a) {
            Min_Convolution temp(lhs);
            temp *= a;
            return temp;
        }

        void zeta_transform(std::vector<R> &f) const override {
            if (f.empty()) return;
            // 後ろからの累積和: F[i] = sum_{j >= i} f[j]
            for (size_t i = f.size() - 1; i > 0; i--) {
                f[i - 1] += f[i];
            }
        }

        void mobius_transform(std::vector<R> &g) const override {
            if (g.empty()) return;
            // 後ろからの差分: g[i] = G[i] - G[i+1]
            for (size_t i = 0; i + 1 < g.size(); i++) {
                g[i] -= g[i + 1];
            }
        }
    };
}