#pragma once

#include "../template/template.hpp"
#include "../template/concepts.hpp"

template <typename M, auto op, auto identity>
requires Monoid_Concept<M, op, identity>
class Monoid_Functional_Graph {
    private:
    int N;
    long long K;
    vector<vector<int>> to;
    vector<vector<M>> weight;

    public:
    /// @brief 有向辺にモノイドの重みを乗せた Functional Graph を生成する.
    /// @param N 頂点数
    /// @param K 計算に必要な最大の移動回数
    Monoid_Functional_Graph(int N, long long K) : N(N), K(K) {
        to.assign(1, vector<int>(N));
        for (int i = 0; i < N; ++i) { to[0][i] = i; }
        weight.assign(1, vector<M>(N, identity));
    }

    /// @brief 重み x で有向辺 source -> target を設定する.
    /// @param source 始点
    /// @param target 終点
    /// @param x 重み
    void set_arc(int source, int target, M x) {
        to[0][source] = target;
        weight[0][source] = x;
    }

    /// @brief Functional Graph を確定させる.
    void build() {
        long long k = K >> 1;
        while (k > 0) {
            int h = to.size() - 1;
            vector<int> next_to(N);
            vector<M> next_weight(N);

            for (int i = 0; i < N; ++i) {
                int p = to[h][i];
                next_to[i] = to[h][p];
                next_weight[i] = op(weight[h][p], weight[h][i]);
            }

            to.emplace_back(next_to);
            weight.emplace_back(next_weight);
            k >>= 1;
        }
    }

    /// @brief 頂点 v から k 回移動したときの累積重みを求める.
    /// @param v 始点
    /// @param k 移動回数
    /// @return 累積重み
    M calculate(int v, long long k) {
        M x = identity;
        for (int h = 0; k > 0 && h < (int)to.size(); ++h) {
            if (k & 1) {
                x = op(weight[h][v], x);
                v = to[h][v];
            }
            k >>= 1;
        }
        return x;
    }
};
