#pragma once

#include"../template/template.hpp"

template<typename mint>
class Combination_Calculator {
    private:
    vector<mint> _fact, _fact_inv, _inv;

    void resize(const int m) {
        if (m < _fact.size()) { return; }

        for (int size = _fact.size(); m >= size; size = _fact.size()) {
            _fact.resize(2 * size);
            _fact_inv.resize(2 * size);
            _inv.resize(2 * size);

            for (int k = size; k < 2 * size; k++) {
                _fact[k] = k * _fact[k - 1];
            }

            _fact_inv.back() = _fact.back().inverse();

            for (int k = 2 * size - 2; k >= size; --k) {
                _fact_inv[k] = (k + 1) * _fact_inv[k + 1];
            }

            for (int k = size; k < 2 * size; ++k) {
                int q, r;
                tie (q, r) = divmod(mint::mod(), k);
                _inv[k] = -q * _inv[r];
            }
        }
    }

    public:
    Combination_Calculator(const int n) {
        _fact.emplace_back(1);
        _fact_inv.emplace_back(1);
        _inv.emplace_back(0);

        resize(n);
    }

    Combination_Calculator(): Combination_Calculator(0) {}

    mint fact(const int k) {
        resize(k);
        return _fact[k];
    }

    mint fact_inv(const int k) {
        resize(k);
        return _fact_inv[k];
    }

    mint inv(const int k) {
        resize(k);
        return _inv[k];
    }

    mint nCr(const int n, const int r) {
        if (!(0 <= r && r <= n)) { return 0; }
        resize(n);
        return fact(n) * fact_inv(r) * fact_inv(n - r);
    }

    mint nPr(const int n, const int r) {
        if (!(0 <= r && r <= n)) { return 0; }
        resize(n);
        return fact(n) * fact_inv(n - r);
    }

    mint nHr(const int n, const int r) {
        if (n == 0 && r == 0) { return 1; }

        return nCr(n + r - 1, r);
    }
};
