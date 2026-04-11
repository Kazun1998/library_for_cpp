#pragma once

#include "Convolution_Base.hpp"

namespace convolution {
    template<typename R>
    class Subset_Convolution : public Convolution_Base<R> {
        using Base = Convolution_Base<R>;

        public:
        using Base::Base;

        Subset_Convolution(size_t n) : Base(1ULL << n) {}

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

        /**
         * @brief ランク付きゼータ変換 (Ranked Zeta Transform)
         * 
         * @param f ランク付き形式のデータ (フラット化された 1 次元配列)
         * @param N 全体集合の要素数
         */
        void zeta_transform(std::vector<R>& f, int N) const {
            int size = 1 << N;
            for (int i = 0; i < N; i++) {
                for (int S = 0; S < size; S++) {
                    unless (get_bit(S, i)) continue;

                    int curr_offset = S * (N + 1);
                    int prev_offset = (S ^ (1 << i)) * (N + 1);
                    for (int j = 0; j <= N; j++) {
                        f[curr_offset + j] += f[prev_offset + j];
                    }
                }
            }
        }

        /**
         * @brief ランク付きメビウス変換 (Ranked Mobius Transform)
         * 
         * @param g ランク付き形式のデータ (フラット化された 1 次元配列)
         * @param N 全体集合の要素数
         */
        void mobius_transform(std::vector<R>& g, int N) const {
            int size = 1 << N;
            for (int i = 0; i < N; i++) {
                for (int S = 0; S < size; S++) {
                    unless (get_bit(S, i)) continue;

                    int curr_offset = S * (N + 1);
                    int prev_offset = (S ^ (1 << i)) * (N + 1);
                    for (int j = 0; j <= N; j++) {
                        g[curr_offset + j] -= g[prev_offset + j];
                    }
                }
            }
        }

        /**
         * @brief ランク付き表現の各集合 S に対して多項式乗算を行う
         * 
         * @param fa ランク付き形式のデータ A
         * @param fb ランク付き形式のデータ B
         * @param N 全体集合の要素数
         */
        void multiply_ranked_representation(std::vector<R>& fa, const std::vector<R>& fb, int N) const {
            int size = 1 << N;
            std::vector<R> buf(N + 1);
            for (int S = 0; S < size; S++) {
                int offset = S * (N + 1);
                std::fill(buf.begin(), buf.end(), R(0));
                for (int i = 0; i <= N; i++) {
                    if (is_zero(fa[offset + i])) continue;

                    for (int j = 0; i + j <= N; j++) {
                        buf[i + j] += fa[offset + i] * fb[offset + j];
                    }
                }
                for (int i = 0; i <= N; i++) fa[offset + i] = buf[i];
            }
        }

        Subset_Convolution& operator*=(const Base& B) override {
            const std::vector<R>& b_data = B.to_vector();
            unless (this->data.size() == b_data.size()) {
                throw std::length_error("Convolution operands must have the same size.");
            }

            int n = this->data.size();
            unless (n > 0) return *this;

            int N = ceil_log2(n);
            int size = 1 << N;

            // ランク付きゼータ変換のためのテーブル (mask, rank)
            std::vector<R> fa(size * (N + 1), 0), fb(size * (N + 1), 0);
            for (int i = 0; i < n; i++) {
                fa[i * (N + 1) + popcount(i)] = this->data[i];
                fb[i * (N + 1) + popcount(i)] = b_data[i];
            }

            // ゼータ変換 (各ランクに対して bitwise OR convolution の変換を行う)
            zeta_transform(fa, N);
            zeta_transform(fb, N);

            // 各 S ごとに多項式の乗算を行う
            multiply_ranked_representation(fa, fb, N);

            // 不要になった fb のメモリを早期解放
            { std::vector<R> empty; fb.swap(empty); }

            // メビウス変換 (各ランクに対して逆変換を行う)
            mobius_transform(fa, N);

            this->data.assign(n, 0);
            for (int i = 0; i < n; i++) {
                this->data[i] = fa[i * (N + 1) + popcount(i)];
            }

            return *this;
        }
    };

    template<typename R>
    using Sub = Subset_Convolution<R>;
}
