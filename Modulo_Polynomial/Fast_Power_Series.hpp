#pragma once

// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Modulo_Polynomial/Fast_Power_Series.hpp

#include"Modulo_Polynomial.hpp"
#include"Numeric_Theory_Translation.hpp"

template<typename mint>
class Fast_Power_Series : public Modulo_Polynomial<mint, Fast_Power_Series<mint>> {
    using Base = Modulo_Polynomial<mint, Fast_Power_Series<mint>>;
    protected:
    static Numeric_Theory_Translation<mint> calculator;

    public:
    // 共有の数論変換器. ntt を直接使う処理 (Bostan-Mori 法など) から参照する.
    static Numeric_Theory_Translation<mint>& translator() { return calculator; }

    // 係数列 A, B の畳み込み (多項式としての積の係数列) を求める.
    static vector<mint> convolution(const vector<mint> &A, const vector<mint> &B) { return calculator.convolution(A, B); }

    Fast_Power_Series(vector<mint> _poly, int _precision) : Base(_poly, _precision) {}

    Fast_Power_Series() = default;
    Fast_Power_Series(vector<mint> _poly) : Fast_Power_Series(_poly, _poly.size()) {}
    Fast_Power_Series(int _precision) : Fast_Power_Series({}, _precision) {}

    // 線形演算 (加減算, スカラー倍・除算) は基底クラスのものを使う.
    using Base::operator+=;
    using Base::operator-=;
    using Base::operator*=;
    using Base::operator/=;

    friend Fast_Power_Series operator*(const ll &a, const Fast_Power_Series &P) { return mint(a) * P; }

    // 積
    Fast_Power_Series& operator*=(const Fast_Power_Series &P) {
        auto tmp = calculator.convolution(this->poly, P.poly);

        this->poly = tmp;
        this->precision = min(this->precision, P.precision);

        this->weak_resize();
        this->reduce();
        return *this;
    }

    friend Fast_Power_Series operator*(const Fast_Power_Series &lhs, const Fast_Power_Series &rhs) { return Fast_Power_Series(lhs) *= rhs; }

    // 多項式としての積. 精度は結果の次数に合わせて自動拡張される.
    Fast_Power_Series mul_poly(const Fast_Power_Series &P) const {
        auto tmp = calculator.convolution(this->poly, P.poly);
        return Fast_Power_Series(tmp, tmp.size());
    }

    // 係数列 P (P[0] != 0) の (mod X^d) における逆元の係数列を Newton 法で求める.
    static vector<mint> inverse_vector(const vector<mint> &P, int d) {
        int n = P.size();
        assert(!P.empty() && !P[0].is_zero());

        vector<mint> G{P[0].inverse()};
        while ((int) G.size() < d) {
            int m = G.size();
            vector<mint> A(P.begin(), P.begin() + min(n, 2 * m));
            A.resize(2 * m);
            vector<mint> B(G);
            B.resize(2 * m);

            calculator.ntt(A); calculator.ntt(B);
            for (int i = 0; i < 2 * m; i++) { A[i] *= B[i]; }

            calculator.inverse_ntt(A);
            A.erase(A.begin(), A.begin() + m);
            A.resize(2 * m);

            calculator.ntt(A);
            for (int i = 0; i < 2 * m; i++) { A[i] *= -B[i]; }

            calculator.inverse_ntt(A);

            G.insert(G.end(), A.begin(), A.begin() + m);
        }

        G.resize(d);
        return G;
    }

    // (mod X^d) における逆元を求める
    // d = -1 のときは, d = precision になる.
    Fast_Power_Series inverse(int d = -1) const {
        vector<mint> p = inverse_vector(this->poly, (d == -1) ? this->precision : min(d, this->precision));
        return {p, this->precision};
    }

    // 多項式列 A[0], A[1], ... の総積の係数列を求める.
    static vector<mint> multiple_convolution(vector<vector<mint>> A) {
        if (A.empty()) { return {1}; }

        deque<int> queue(A.size());
        iota(queue.begin(), queue.end(), 0);

        while (queue.size() > 1) {
            int i = queue.front(); queue.pop_front();
            int j = queue.front(); queue.pop_front();

            A[i] = calculator.convolution(A[i], A[j]);
            queue.emplace_back(i);
        }

        return A[queue.back()];
    }

    // 除算
    Fast_Power_Series& operator/=(const Fast_Power_Series &P) {
        vector<mint> inv = inverse_vector(P.poly, P.precision);
        this->poly = calculator.convolution(this->poly, inv);
        this->precision = min(this->precision, P.precision);
        this->weak_resize();
        this->reduce();
        return *this;
    }

    friend Fast_Power_Series operator/(const Fast_Power_Series &lhs, const Fast_Power_Series &rhs) { return Fast_Power_Series(lhs) /= rhs; }

    // 多項式としての除算
    Fast_Power_Series div(const Fast_Power_Series &B) {
        this->reduce(); // B.reduce(); const なので変更しない

        int n = this->poly.size(), m = B.poly.size();

        if (n < m) { return Fast_Power_Series({0}); }

        vector<mint> a_rev(this->poly), b_rev(B.poly);
        reverse(a_rev.begin(), a_rev.end());
        reverse(b_rev.begin(), b_rev.end());

        int k = n - m + 1;
        if (a_rev.size() > k) { a_rev.resize(k); }
        if (b_rev.size() > k) { b_rev.resize(k); }
        vector<mint> c = calculator.convolution(a_rev, inverse_vector(b_rev, k));
        c.resize(k);
        reverse(c.begin(), c.end());
        return Fast_Power_Series(c, n);
    }

    Fast_Power_Series& operator%=(const Fast_Power_Series &B) {
        Fast_Power_Series Q = this->div(B);
        vector<mint> product = calculator.convolution(B.poly, Q.poly);
        if (this->poly.size() < product.size()) { this->poly.resize(product.size()); }
        for (int i = 0; i < product.size(); i++) { this->poly[i] -= product[i]; }
        this->reduce();
        return *this;
    }

    friend Fast_Power_Series operator%(const Fast_Power_Series &lhs, const Fast_Power_Series &rhs) { return Fast_Power_Series(lhs) %= rhs; }

    pair<Fast_Power_Series, Fast_Power_Series> divmod(const Fast_Power_Series &B) {
        Fast_Power_Series Q = this->div(B);
        vector<mint> product = calculator.convolution(B.poly, Q.poly);

        Fast_Power_Series R(*this);
        if (R.poly.size() < product.size()) { R.poly.resize(product.size()); }
        for (int i = 0; i < product.size(); i++) { R.poly[i] -= product[i]; }
        R.reduce();
        return {Q, R};
    }
};

template<typename mint>
Numeric_Theory_Translation<mint> Fast_Power_Series<mint>::calculator = Numeric_Theory_Translation<mint>();

template<typename mint>
pair<Fast_Power_Series<mint>, Fast_Power_Series<mint>> divmod(Fast_Power_Series<mint> &A, const Fast_Power_Series<mint> &B) {
    return A.divmod(B);
}
