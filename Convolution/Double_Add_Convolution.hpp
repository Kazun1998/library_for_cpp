#pragma once

#include"../template/template.hpp"

namespace convolution {
    // 浮動小数点数 (double) の畳み込みを FFT で計算する.
    // 誤差を含むため, 厳密な整数畳み込みには Numeric_Theory_Translation 等を使うこと.
    class Double_Add_Convolution {
        using Complex = complex<double>;

        static void fft(vector<Complex> &A, bool inverse) {
            int N = A.size();

            for (int i = 1, j = 0; i < N; i++) {
                int bit = N >> 1;
                for (; j & bit; bit >>= 1) { j ^= bit; }
                j ^= bit;
                if (i < j) { swap(A[i], A[j]); }
            }

            for (int len = 2; len <= N; len <<= 1) {
                double ang = 2 * M_PI / len * (inverse ? -1 : 1);
                Complex wlen(cos(ang), sin(ang));

                for (int i = 0; i < N; i += len) {
                    Complex w(1);
                    for (int j = 0; j < len / 2; j++) {
                        Complex u = A[i + j], v = A[i + j + len / 2] * w;
                        A[i + j] = u + v;
                        A[i + j + len / 2] = u - v;
                        w *= wlen;
                    }
                }
            }

            if (inverse) {
                for (Complex &x: A) { x /= N; }
            }
        }

        public:
        Double_Add_Convolution() = default;

        // 内部で double を用いて計算する (誤差により厳密性は保証されない).
        static vector<ll> convolution(const vector<ll> &A, const vector<ll> &B) {
            if (A.empty() || B.empty()) { return {}; }

            int L = A.size() + B.size() - 1;

            int N = 1;
            while (N < L) { N <<= 1; }

            vector<Complex> FA(N), FB(N);
            for (size_t i = 0; i < A.size(); i++) { FA[i] = A[i]; }
            for (size_t i = 0; i < B.size(); i++) { FB[i] = B[i]; }

            fft(FA, false);
            fft(FB, false);
            for (int i = 0; i < N; i++) { FA[i] *= FB[i]; }
            fft(FA, true);

            vector<ll> C(L);
            for (int i = 0; i < L; i++) { C[i] = llround(FA[i].real()); }
            return C;
        }
    };
}
