#pragma once

#include"../template/template.hpp"

template<int M>
class modint {
    public:
    static constexpr int _mod = M; 
    uint64_t x;

    public:
    static int mod() { return _mod; }

    static modint raw(int v) {
        modint a;
        a.x = v;
        return a;
    }

    // 初期化
    constexpr modint(): x(0) {}
    constexpr modint(int64_t a) {
        int64_t w = (int64_t)(a) % mod();
        if (w < 0) { w += mod(); }
        x = w;
    }

    // マイナス元
    modint operator-() const { return modint(-x); }

    // 加法
    modint& operator+=(const modint &b){
        if ((x += b.x) >= mod()) x -= mod();
        return *this;
    }

    friend modint operator+(const modint &x, const modint &y) { return modint(x) += y; }

    // 減法
    modint& operator-=(const modint &b){
        if ((x += mod() - b.x) >= mod()) x -= mod();
        return *this;
    }

    friend modint operator-(const modint &x, const modint &y) { return modint(x) -= y; }

    // 乗法
    modint& operator*=(const modint &b){
        (x *= b.x) %= mod();
        return *this;
    }

    friend modint operator*(const modint &x, const modint &y) { return modint(x) *= y; }
    friend modint operator*(const int &x, const modint &y) { return modint(x) *= y; }
    friend modint operator*(const ll &x, const modint &y) { return modint(x) *= y; }

    // 除法
    modint& operator/=(const modint &b){ return (*this) *= b.inverse(); }

    friend modint operator/(const modint &x, const modint &y) { return modint(x) /= y; }

    modint inverse() const {
        int64_t s = 1, t = 0;
        int64_t a = x, b = mod();

        while (b > 0) {
            int64_t q = a / b;

            a -= q * b; swap(a, b);
            s -= q * t; swap(s, t);
        }

        assert (a == 1);

        return modint(s);
    }

    // 比較
    friend bool operator==(const modint &a, const modint &b) { return (a.x == b.x); }
    friend bool operator==(const modint &a, const int &b) { return a.x == safe_mod(b, mod()); }
    friend bool operator!=(const modint &a, const modint &b) { return (a.x != b.x); }

    // 入力
    friend istream &operator>>(istream &is, modint &a) {
        is >> a.x;
        a.x = (a.x % mod() + mod()) % mod();
        return is;
    }

    // 出力
    friend ostream &operator<<(ostream &os, const modint &a) { return os << a.x; }

    bool is_zero() const { return x == 0; }
    bool is_member(ll a) const { return x == (a % mod() + mod()) % mod(); }
};

template<int mod>
modint<mod> pow(modint<mod> x, long long n) {
    if (n < 0) { return pow(x, -n).inverse(); }

    auto res = modint<mod>(1);
    for (; n; n >>= 1) {
        if (n & 1) { res *= x; }
        x *= x;
    }

    return res;
}
