#pragma once

#include "../template/template.hpp"
#include "../Union_Find/Union_Find.hpp"

struct Todd_Coxeter {
    public:
    /// @brief 語. 文字 (0 以上 K 未満の整数) の列. 空列は単位元を表す.
    using Word = vector<int>;

    /// @brief 関係式 (lhs, rhs). lhs = rhs を表す.
    using Relation = pair<Word, Word>;

    private:
    int K;
    vector<vector<int>> T;

    // 以下は構成中のみ使う.
    Union_Find UF;
    vector<bool> done; // done[alpha]: alpha から全関係式を調べ, 全文字の行き先を定義済みか?

    /// @brief 元を 1 つ追加する.
    /// @return 追加した元の番号.
    int add_vertex() {
        int alpha = T.size();
        T.emplace_back(K, -1);
        UF.add_vertex();
        done.emplace_back(false);

        return alpha;
    }

    /// @brief 元 alpha に文字 x を右から掛けた元を求める. 未定義ならば新しい元を作る.
    /// @return 行き先の代表元.
    int step(int alpha, int x) {
        alpha = UF.find(alpha);
        if (T[alpha][x] == -1) {
            int beta = add_vertex();
            T[alpha][x] = beta;
        }

        return UF.find(T[alpha][x]);
    }

    /// @brief 元 alpha に語 w を右から掛けた元を求める. 途中が未定義ならば新しい元を作る.
    /// @return 行き先の代表元.
    int walk(int alpha, const Word &w) {
        for (int x: w) {
            alpha = step(alpha, x);
        }

        return UF.find(alpha);
    }

    /// @brief 元 alpha0 と元 beta0 を同一視する. 同一視から導かれる併合も連鎖的に行う.
    void merge(int alpha0, int beta0) {
        vector<pair<int, int>> Q({{alpha0, beta0}});

        until(Q.empty()) {
            auto [alpha, beta] = Q.back();
            Q.pop_back();

            alpha = UF.find(alpha);
            beta = UF.find(beta);

            unless (UF.unite(alpha, beta)) continue;

            int gamma = UF.find(alpha);

            done[gamma] = done[alpha] || done[beta];

            for (int x = 0; x < K; ++x) {
                int delta = T[alpha][x];
                int epsilon = T[beta][x];

                T[gamma][x] = (delta == -1) ? epsilon : delta;
                if ((delta != -1) && (epsilon != -1)) {
                    Q.emplace_back(delta, epsilon);
                }
            }
        }
    }

    /// @brief 全ての元から全関係式を調べ, 全文字の行き先を定義する.
    void enumerate(const vector<Relation> &R) {
        add_vertex();
        for (int alpha = 0; alpha < (int)T.size(); ++alpha) {
            if (done[UF.find(alpha)]) { continue; }

            for (const auto &[lhs, rhs]: R) {
                merge(walk(alpha, lhs), walk(alpha, rhs));
            }

            for (int x = 0; x < K; ++x) {
                step(alpha, x);
            }

            done[UF.find(alpha)] = true;
        }
    }

    /// @brief 代表元だけに番号を振り直し, T を最終的な表にする. 単位元の属する族が 0 になる.
    void compress() {
        int N = T.size();
        vector<int> id(N, -1);
        int m = 0;
        id[UF.find(0)] = m++;
        for (int alpha = 0; alpha < N; ++alpha) {
            if (UF.find(alpha) == alpha && id[alpha] == -1) { id[alpha] = m++; }
        }

        vector<vector<int>> S(m, vector<int>(K));
        for (int alpha = 0; alpha < N; ++alpha) {
            unless (UF.find(alpha) == alpha) { continue; }

            for (int x = 0; x < K; ++x) {
                S[id[alpha]][x] = id[UF.find(T[alpha][x])];
            }
        }

        T = move(S);
    }

    public:
    /// @brief 文字が K 個の自由モノイドを, 関係式 R の各 lhs = rhs で割った商モノイド M を構成する.
    /// @param K 文字の個数. 文字は 0, ..., K-1.
    /// @param R 関係式の列. 各 (lhs, rhs) は lhs = rhs を表す.
    /// @note 構成後, T[alpha][x] は元 alpha に文字 x を右から掛けた元で, 単位元は 0.
    /// @warning M は有限でなければならない. 無限ならば終了しない (例: R が空, ab = ba のみ).
    Todd_Coxeter(int K, const vector<Relation> &R): K(K), UF(0) {
        enumerate(R);
        compress();

        // 構成中のみ使う変数を解放する.
        UF = Union_Find(0);
        done = vector<bool>();
    }

    /// @brief 右からの作用表を返す.
    /// @return T[alpha][x]: 元 alpha に文字 x を右から掛けた元の番号 (読み取り専用).
    const vector<vector<int>> &table() const { return T; }

    /// @brief M の位数 (元の個数) を求める.
    int order() const { return T.size(); }

    /// @brief 元 alpha に文字 x を右から掛けた元の番号を求める.
    /// @param alpha 元の番号 (0 以上 order() 未満).
    /// @param x 文字 (0 以上 K 未満).
    int act(int alpha, int x) const { return T[alpha][x]; }

    /// @brief 語 w が表す元の番号を求める.
    /// @param w 文字の列. 各文字は 0 以上 K 未満. 空列は単位元を表す.
    /// @return 元の番号 (単位元は 0).
    int eval(const Word &w) const {
        int alpha = 0;
        for (int x: w) {
            alpha = T[alpha][x];
        }

        return alpha;
    }
};
