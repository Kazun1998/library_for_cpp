#pragma once

#include"../template/template.hpp"

template<typename mint>
class Combination_Calculator {
    private:
    vector<mint> _fact, _fact_inv;

    void resize(const int m) {
        if (m < _fact.size()) { return; }

        int current_size = _fact.size();
        int next_size = min(max(2 * current_size, m), mint::mod());

        _fact.resize(next_size);
        _fact_inv.resize(next_size);

        for (int k = current_size; k < next_size; k++) {
            _fact[k] = k * _fact[k - 1];
        }

        _fact_inv.back() = _fact.back().inverse();

        for (int k = next_size - 2; k >= current_size; --k) {
            _fact_inv[k] = (k + 1) * _fact_inv[k + 1];
        }
    }

    public:
    /**
     * @brief コンストラクタ: 初期サイズnまで階乗・逆階乗を計算する
     * @param n 初期計算の上限
     */
    Combination_Calculator(const int n) {
        _fact.emplace_back(1); _fact.emplace_back(1);
        _fact_inv.emplace_back(1); _fact_inv.emplace_back(1);

        resize(n);
    }

    Combination_Calculator(): Combination_Calculator(0) {}

    /**
     * @brief k! を取得
     */
    mint fact(const int k) {
        resize(k);
        return _fact[k];
    }

    /**
     * @brief (k!)^(-1) を取得
     */
    mint fact_inv(const int k) {
        resize(k);
        return _fact_inv[k];
    }

    /**
     * @brief k の逆元 k^(-1) を求める
     * @param k 逆元を求めたい数
     */
    mint inv(const int k) {
        if (k <= 0) { return 0; }

        resize(k);
        return _fact_inv[k] * _fact[k - 1];
    }

    /**
     * @brief 組み合わせ nCk を計算する
     */
    mint nCr(const int n, const int r) {
        if (!(0 <= r && r <= n)) { return 0; }
        resize(n);
        return _fact[n] * _fact_inv[r] * _fact_inv[n - r];
    }

    /**
     * @brief 順列 nPk を計算する
     */
    mint nPr(const int n, const int r) {
        if (!(0 <= r && r <= n)) { return 0; }
        resize(n);
        return _fact[n] * _fact_inv[n - r];
    }

    /**
     * @brief 重複組合せ nHk を計算する
     */
    mint nHr(const int n, const int r) {
        if (n == 0 && r == 0) { return 1; }

        return nCr(n + r - 1, r);
    }

    /**
     * @brief 多項係数 (k_sum)! / (k1! * k2! * ...) を計算する
     */
    mint multinomial_coefficient(const vector<int> &ks) {
        int k_sum = 0;
        mint lower = 1;
        for (int k: ks) {
            k_sum += k;
            lower *= _fact_inv[k];
        }

        resize(k_sum);

        mint upper = _fact[k_sum];

        return upper * lower;
    }

    mint catalan(const int n) {
        if (n < 0) { return 0; }
        resize(2 * n);
        return _fact[2 * n] * _fact_inv[n + 1] * _fact_inv[n];
    }
};
