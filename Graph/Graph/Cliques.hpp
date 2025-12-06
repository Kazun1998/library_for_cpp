#pragma once

#include"Graph.hpp"

namespace graph {
    template<typename X>
    X Cliques(
            const Graph &G,
            const function<X(const vector<int>)> &calc,
            const function<X(X, X)> &merge,
            const X unit,
            bool empty = false) {

        int N = G.order(), M = G.size();
        int M_sqrt = ceil_sqrt(M);

        vector<int> deg(N, 0);
        for (int v = 0; v < N; v++) { deg[v] = G.degree(v); }

        vector<bool> alive(N, true);
        vector<vector<bool>> E(N, vector<bool>(N, false));
        for (int u = 0; u < N; u++) {
            for (auto edge: G.incidence(u)) {
                int v = edge->target;
                E[u][v] = true;
                E[v][u] = true;
            }
        }

        auto generate_bits_table = [&](const vector<int> &A) -> vector<ll> {
            int K = A.size();
            vector<ll> bits(K, 0);

            for (int i = 0; i < K; i++) {
                for (int j = 0; j < i; j++) {
                    unless(E[A[i]][A[j]]) {
                        bits[i] |= 1 << j;
                        bits[j] |= 1 << i;
                    }
                }
            }

            return bits;
        };

        auto is_clique = [&](const vector<int> &A, const vector<ll> &bits, int S) -> bool {
            for (int i = 0; i < A.size(); i++) {
                if (get_bit(S, i) && (S & bits[i])) { return false; }
            }

            return true;
        };

        auto subcalc = [&](const vector<int> &A, const int leader = -1) -> X {
            X res = unit;
            bool empty_accept = (leader != -1) || empty;

            int K = A.size();
            auto bits = generate_bits_table(A);

            for (int S = 0; S < (1 << K); S++) {
                unless(is_clique(A, bits, S)) { continue; }

                vector<int> C;
                if (leader != -1) { C.emplace_back(leader); }

                for (int i = 0; i < K; i++) {
                    if (get_bit(S, i)) {
                        C.emplace_back(A[i]);
                    }
                }

                if(S > 0 || empty_accept) {
                    res = merge(res, calc(C));
                }
            }

            return res;
        };

        X res(unit);

        // 次数が M_sqrt 未満の頂点を含むクリークを計算する
        loop {
            vector<int> A;

            int leader = -1;
            for (int u = 0; u < N; u++) {
                unless (alive[u] && deg[u] < M_sqrt) { continue; }

                for (int v = 0; v < N; v++) {
                    if (u != v && alive[v] && E[u][v]) {
                        A.emplace_back(v);
                    }
                }

                leader = u;
                break;
            }

            if (leader == -1) { break; }

            int K = A.size();
            res = merge(res, subcalc(A, leader));

            alive[leader] = false;
            deg[leader] = 0;

            for (int v = 0; v < N; v++) {
                if (leader != v && alive[v] && E[leader][v]) {
                    deg[v]--;
                }
            }
        }

        // 残った頂点 M_sqrt 個以下である → 全探索
        vector<int> A;
        for (int u = 0; u < N; u++) {
            if(alive[u]) { A.emplace_back(u); }
        }

        res = merge(res, subcalc(A, -1));

        return res;
    };
}