#pragma once

#include "Semilattice_Convolution_Base.hpp"

namespace convolution {
    template<typename R>
    class Max_Convolution: public Semilattice_Convolution_Base<R> {
        using Base = Convolution_Base<R>;
        using ImplBase = Semilattice_Convolution_Base<R>;
        using ImplBase::ImplBase;

        // 加法 (+)
        friend Max_Convolution operator+(const Max_Convolution &lhs, const Max_Convolution &rhs) {
            Max_Convolution temp(lhs);
            temp += rhs;
            return temp;
        }

        // 減法 (-)
        friend Max_Convolution operator-(const Max_Convolution &lhs, const Max_Convolution &rhs) {
            Max_Convolution temp(lhs);
            temp -= rhs;
            return temp;
        }

        // 乗法 (*)
        friend Max_Convolution operator*(const Max_Convolution &lhs, const Max_Convolution &rhs) { 
            Max_Convolution temp(lhs);
            temp *= rhs;
            return temp;
        }

        // スカラー倍 (a * rhs)
        friend Max_Convolution operator*(const R &a, const Max_Convolution &rhs) {
            Max_Convolution temp(rhs);
            temp *= a;
            return temp;
        }

        // スカラー倍 (lhs * a)
        friend Max_Convolution operator*(const Max_Convolution &lhs, const R &a) {
            Max_Convolution temp(lhs);
            temp *= a;
            return temp;
        }

        void zeta_transform(std::vector<R> &f) const override {
            for (size_t i = 1; i < f.size(); i++) {
                f[i] += f[i - 1];
            }
        }

        void mobius_transform(std::vector<R> &g) const override {
            if (g.empty()) return;
            for (size_t i = g.size() - 1; i > 0; i--) {
                g[i] -= g[i - 1];
            }
        }
    };
}
