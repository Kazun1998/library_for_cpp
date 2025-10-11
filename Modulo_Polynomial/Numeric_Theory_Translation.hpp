#pragma once

#include"../template/template.hpp"
#include"Modulo_Polynomial.hpp"

template<typename F>
class Numeric_Theory_Translation {
    public:
    F primitive;
    vector<F> root, iroot, rate2, irate2, rate3, irate3;

    public:
    Numeric_Theory_Translation() {
        primitive = primitive_root();
        build_up();
    }

    private:
    F primitive_root(){
        if (F::Mod == 2) { return F(1); }
        if (F::Mod == 998244353) { return F(3); }

        vector<int> fac;
        int v = F::Mod - 1;

        for (int q = 2; q * q <= v; q++){
            int e = 0;
            while (v % q == 0){
                e++; v /= q;
            }

            if (e > 0) { fac.emplace_back(q); }
        }

        if (v > 1) { fac.emplace_back(v); }

        F g(2);
        while (true) {
            bool flag = true;
            for (int q: fac) {
                if (pow(g, (F::Mod - 1) / q) == 1){
                    flag = false;
                    break;
                }
            }
            if (flag) { break; }
            g += 1;
        }
        return g;
    }

    void build_up() {
        int x = ~(F::Mod - 1) & (F::Mod - 2);
        int rank2 = bit_length(x);

        root.resize(rank2 + 1); iroot.resize(rank2 + 1);
        rate2.resize(max(0, rank2 - 1)); irate2.resize(max(0, rank2 - 1));
        rate3.resize(max(0, rank2 - 2)); irate3.resize(max(0, rank2 - 2));

        root.back() = pow(primitive, (F::Mod - 1) >> rank2);
        iroot.back() = root.back().inverse();

        for (int i = rank2 - 1; i >= 0; i--){
            root[i] = root[i + 1] * root[i + 1];
            iroot[i] = iroot[i + 1] * iroot[i + 1];
        }

        F prod(1), iprod(1);
        for (int i = 0; i < rank2 - 1; i++){
            rate2[i] = root[i + 2] * prod;
            irate2[i] = iroot[i + 2] * prod;

            prod *= iroot[i + 2]; iprod *= root[i + 2];
        }

        prod = 1; iprod = 1;
        for (int i = 0; i < rank2 - 2; i++){
            rate3[i] = root[i + 3] * prod;
            irate3[i] = iroot[i + 3] * iprod;

            prod *= iroot[i + 3]; iprod *= root[i + 3];
        }
    }

    public:
    void ntt(vector<F> &A){
        int N = A.size();
        int h = ceil_log2(N);

        F I = root[2];
        for (int l = 0; l < h;){
            if (h - l == 1){
                int p = 1 << (h - l - 1);
                F rot(1);
                for (int s = 0; s < (1 << l); s++){
                    int offset = s << (h - l);
                    for(int i = 0; i < p; i++){
                        F x = A[i + offset], y = A[i + offset + p] * rot;
                        A[i + offset] = x + y;
                        A[i + offset + p] = x - y;
                    }

                    unless (s + 1 == (1 << l)){ rot *= rate2[bit_length(~s & -(~s)) - 1]; }
                }
                l++;
            } else {
                int p = 1 << (h - l - 2);
                F rot(1);
                for (int s = 0; s < (1 << l); s++){
                    F rot2 = rot * rot, rot3 = rot2 * rot;
                    int offset = s << (h - l);
                    for (int i = 0; i < p; i++){
                        F a0 = A[i + offset];
                        F a1 = A[i + offset + p] * rot;
                        F a2 = A[i + offset + 2 * p] * rot2;
                        F a3 = A[i + offset + 3 * p] * rot3;

                        F alpha = (a1 - a3) * I;

                        A[i + offset]         = a0 + a2 + a1 + a3;
                        A[i + offset + p]     = a0 + a2 - a1 - a3;
                        A[i + offset + 2 * p] = a0 - a2 + alpha;
                        A[i + offset + 3 * p] = a0 - a2 - alpha;
                    }

                    unless(s + 1 == 1 << l) { rot *= rate3[bit_length(~s & -(~s)) - 1]; }
                }
                l += 2;
            }
        }
    }

    public:
    void inverse_ntt(vector<F> &A){
        int N = A.size();
        int h = ceil_log2(N);

        F J = iroot[2];
        for (int l = h; l > 0;){
            if (l == 1){
                int p = 1 << (h - l);
                F irot(1);
                for (int s = 0; s < (1 << (l - 1)); s++){
                    int offset = s << (h - l + 1);
                    for(int i = 0; i < p; i++){
                        F x = A[i + offset], y = A[i + offset + p];
                        A[i + offset]   = x + y;
                        A[i + offset + p] = (x - y) * irot;
                    }

                    unless (s+1 == 1 << (l - 1) ) { irot *= irate2[bit_length(~s & -(~s)) -1]; }
                }
                l--;
            } else {
                int p = 1 << (h - l);
                F irot(1);
                for (int s=0; s<(1<<(l-2)); s++){
                    F irot2 = irot * irot, irot3 = irot2  *irot;
                    int offset=s<<(h-l+2);
                    for (int i = 0; i < p; i++){
                        F a0 = A[i + offset];
                        F a1 = A[i + offset + p];
                        F a2 = A[i + offset + 2 * p];
                        F a3 = A[i + offset + 3 * p];

                        F beta = (a2 - a3) * J;

                        A[i + offset]         = a0 + a2 + a1 + a3;
                        A[i + offset + p]     = (a0 - a1 + beta) * irot;
                        A[i + offset + 2 * p] = (a0 + a1 - a2 - a3) * irot2;
                        A[i + offset + 3 * p] = (a0 - a1 - beta) * irot3;
                    }

                    unless (s + 1 == 1 << (l - 2)) { irot *= irate3[bit_length(~s & -(~s)) - 1]; }
                }
                l-=2;
            }
        }

        F N_inv=F(N).inverse();
        for (int i=0; i<N; i++) A[i]*=N_inv;
    }

    vector<F> convolution(vector<F> A, vector<F> B){
        if (A.empty() || B.empty()) return vector<F>{};

        int M=A.size(), N=B.size(), L=M+N-1;
        if (min(M,N)<64){
            vector<F> C(L);
            for(int i=0; i<M; i++){
                for (int j=0; j<N; j++){
                    C[i+j]+=A[i]*B[j];
                }
            }
            return C;
        }

        int h=bit_length(L);
        int K=1<<h;

        vector<F> X(K), Y(K);
        copy(A.begin(), A.end(), X.begin());
        copy(B.begin(), B.end(), Y.begin());

        ntt(X); ntt(Y);
        for (int i=0; i<K; i++) X[i]*=Y[i];

        inverse_ntt(X); X.resize(L);
        return X;
    }

    vector<F> inverse(vector<F> P, int d) {
        int n = P.size();
        assert(!P.empty() && !P[0].is_zero());

        vector<F> G{P[0].inverse()};
        while (G.size() < d) {
            int m = G.size();
            vector<F> A(P.begin(), P.begin() + min(n, 2 * m));
            A.resize(2 * m);
            vector<F> B(G);
            B.resize(2 * m);

            ntt(A); ntt(B);
            for (int i = 0; i < 2 * m; i++) { A[i] *= B[i]; }

            inverse_ntt(A);
            A.erase(A.begin(), A.begin() + m);
            A.resize(2 * m);

            ntt(A);
            for (int i = 0; i < 2 * m; i++) { A[i] *= -B[i]; }

            inverse_ntt(A);

            G.insert(G.end(), A.begin(), A.begin() + m);
        }

        G.resize(d);
        return G;
    }

    vector<F> inverse(vector<F> P) { return inverse(P, P.size()); }

    vector<F> multiple_convolution(vector<vector<F>> A) {
        if (A.empty()) { return {1}; }

        deque<int> queue(A.size());
        iota(queue.begin(), queue.end(), 0);

        while (queue.size() > 1) {
            int i = queue.front(); queue.pop_front();
            int j = queue.front(); queue.pop_front();

            A[i] = convolution(A[i], A[j]);
            queue.emplace_back(i);
        }

        return A[queue.back()];
    }
};
