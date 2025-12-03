#pragma once

#include"Combination_Calculator.hpp"
#include"../template/template.hpp"

template<typename mint>
class Q_Analog_Calculator {
    private:
    Combination_Calculator<mint> calc;

    mint q;
    int order;
    vector<mint> _power;    // q^k
    vector<mint> _bracket;  // q-数 [n]_q
    vector<mint> _fact;     // q-階乗 [n]_q !
    vector<mint> _fact_inv; // q-階乗の逆数 ([n]_q !)^(-1)

    void resize(const int m) {
        if (order != -1) { return; }

        int current_size = _fact.size();
        if (m < current_size) { return; }

        int next_size = min(max(2 * current_size, m), mint::mod());

        _power.resize(next_size);
        for (int k = current_size; k < next_size; k++) {
            _power[k] = q * _power[k - 1];

            if(_power[k] == 1) {
                order = k;
                next_size = k;
                _power.resize(k);
                break;
            }
        }

        _bracket.resize(next_size);
        _fact.resize(next_size);
        for (int k = current_size; k < next_size; k++) {
            _bracket[k] = _bracket[k - 1] + _power[k - 1];
            _fact[k] = _bracket[k] * _fact[k - 1];
        }

        _fact_inv.resize(next_size);
        _fact_inv.back() = _fact.back().inverse();
        for (int k = next_size - 2; k >= current_size; --k) {
            _fact_inv[k] = _bracket[k + 1] * _fact_inv[k + 1];
        }
    }

    mint query(const int n, const int r) const {
        return _fact[n] * _fact_inv[r] * _fact_inv[n - r];
    }

    public:
    /// @brief 
    /// @param  
    /// @return 
    Q_Analog_Calculator(const mint q, const int n): q(q), order(-1), calc() {
        _power.emplace_back(1);
        _bracket.emplace_back(0); 
        _fact.emplace_back(1);
        _fact_inv.emplace_back(1);

        resize(n);
    }

    Q_Analog_Calculator(const mint q): Q_Analog_Calculator(q, 0) {}

    /// @brief q^k を求める.
    mint q_power(const int k) {
        resize(k);
        return _power[k];
    }

    /// @brief [n]_q = 1 + q + ... + q^(n-1) を求める.
    mint q_bracket(const int n) {
        resize(n);
        return _bracket[n];
    }

    /// @brief [n]_q ! = [1]_q * [2]_q * ... * [n]_q を求める.
    mint q_fact(const int n) {
        resize(n);
        return _fact[n];
    }

    /// @brief ([n]_q !)^(-1) を求める.
    mint q_fact_inv(const int n) {
        resize(n);
        return _fact_inv[n];
    }

    /// @brief ([n]_q)^(-1) を求める.
    mint q_inv(const int n) {
        resize(n);
        return _fact_inv[n] * _fact[n];
    }

    /// @brief q-組み合わせ nCk を計算する
    mint q_nCr(const int n, const int r) {
        if (!(0 <= r && r <= n)) { return 0; }
        resize(n);

        if (order == -1) { return query(n, r); }
        if (n < order && r < order) { return query(n, r); }

        return calc.nCr(n / order, r / order) * q_nCr(n % order, r % order);
    }

    /// @brief q-順列 nPk を計算する
    mint q_nPr(const int n, const int r) {
        if (!(0 <= r && r <= n)) { return 0; }
        resize(n);
        return _fact[n] * _fact_inv[n - r];
    }

    /// @brief q-重複組合せ nHk を計算する
    mint q_nHr(const int n, const int r) {
        if (n == 0 && r == 0) { return 1; }

        return q_nCr(n + r - 1, r);
    }


    /// @brief q-多項係数 (k_sum)! / (k1! * k2! * ...) を計算する
    mint q_multinomial_coefficient(const vector<int> &ks) {
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
};
