#pragma once

#include "Convolution_Base.hpp"

namespace convolution {
    template<typename R>
    class Subset_Convolution : public Convolution_Base<R> {
        using Base = Convolution_Base<R>;
        using Base::Base;

        public:
        // 加法 (+)
        friend Subset_Convolution operator+(const Subset_Convolution& lhs, const Subset_Convolution& rhs) {
            Subset_Convolution temp(lhs);
            temp += rhs;
            return temp;
        }

        // 減法 (-)
        friend Subset_Convolution operator-(const Subset_Convolution& lhs, const Subset_Convolution& rhs) {
            Subset_Convolution temp(lhs);
            temp -= rhs;
            return temp;
        }

        // 乗法 (*)
        friend Subset_Convolution operator*(const Subset_Convolution& lhs, const Subset_Convolution& rhs) {
            Subset_Convolution temp(lhs);
            temp *= rhs;
            return temp;
        }

        // スカラー倍 (a * rhs)
        friend Subset_Convolution operator*(const R& a, const Subset_Convolution& rhs) {
            Subset_Convolution temp(rhs);
            temp *= a;
            return temp;
        }

        // スカラー倍 (lhs * a)
        friend Subset_Convolution operator*(const Subset_Convolution& lhs, const R& a) {
            Subset_Convolution temp(lhs);
            temp *= a;
            return temp;
        }

        Subset_Convolution& operator*=(const Base& B) override {
            const std::vector<R>& b_data = B.to_vector();
            if (this->data.size() != b_data.size()) {
                throw std::length_error("Convolution operands must have the same size.");
            }

            int n = this->data.size();
            if (n == 0) return *this;

            int m = 0;
            while ((1 << m) < n) m++;
            int N = 1 << m;

            // ランク付きゼータ変換のためのテーブル (rank, mask)
            // メモリレイアウトを考慮し、[rank * N + mask] の形式で管理
            std::vector<R> fa(N * (m + 1), 0), fb(N * (m + 1), 0);
            for (int i = 0; i < n; i++) {
                int pc = __builtin_popcount(i);
                fa[pc * N + i] = this->data[i];
                fb[pc * N + i] = b_data[i];
            }

            // ゼータ変換 (各ランクに対して bitwise OR convolution の変換を行う)
            for (int i = 0; i < m; i++) {
                for (int j = 0; j <= m; j++) {
                    int offset = j * N;
                    for (int mask = 0; mask < N; mask++) {
                        if ((mask >> i) & 1) {
                            fa[offset + mask] += fa[offset + (mask ^ (1 << i))];
                            fb[offset + mask] += fb[offset + (mask ^ (1 << i))];
                        }
                    }
                }
            }

            // 各 mask ごとに多項式の乗算を行う
            std::vector<R> fc(N * (m + 1), 0);
            for (int mask = 0; mask < N; mask++) {
                for (int i = 0; i <= m; i++) {
                    if (fa[i * N + mask] == 0) continue;
                    for (int j = 0; i + j <= m; j++) {
                        fc[(i + j) * N + mask] += fa[i * N + mask] * fb[j * N + mask];
                    }
                }
            }

            // メビウス変換 (各ランクに対して逆変換を行う)
            for (int i = 0; i < m; i++) {
                for (int j = 0; j <= m; j++) {
                    int offset = j * N;
                    for (int mask = 0; mask < N; mask++) {
                        if ((mask >> i) & 1) {
                            fc[offset + mask] -= fc[offset + (mask ^ (1 << i))];
                        }
                    }
                }
            }

            this->data.assign(n, 0);
            for (int i = 0; i < n; i++) {
                this->data[i] = fc[__builtin_popcount(i) * N + i];
            }

            return *this;
        }
    };

    template<typename R>
    using Sub = Subset_Convolution<R>;
}
