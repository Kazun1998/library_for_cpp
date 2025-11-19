#pragma once

#include"../template/template.hpp"

template<int id>
class dynamic_modint {
    public:
    uint64_t x;
    static int _mod;

    static void set_mod(const int m) { _mod = m; } 
    static int mod() { return _mod; }

    public:
    static dynamic_modint raw(int v) {
        dynamic_modint a;
        a.x = v;
        return a;
    }

    // 初期化
    constexpr dynamic_modint(): x(0) {}
    constexpr dynamic_modint(int64_t a) {
        int64_t w = (int64_t)(a) % mod();
        if (w < 0) { w += mod(); }
        x = w;
    }

    // マイナス元
    dynamic_modint operator-() const { return dynamic_modint(-x); }

    // 加法
    dynamic_modint& operator+=(const dynamic_modint &b){
        if ((x += b.x) >= mod()) x -= mod();
        return *this;
    }

    friend dynamic_modint operator+(const dynamic_modint &x, const dynamic_modint &y) { return dynamic_modint(x) += y; }

    // 減法
    dynamic_modint& operator-=(const dynamic_modint &b){
        if ((x += mod() - b.x) >= mod()) x -= mod();
        return *this;
    }

    friend dynamic_modint operator-(const dynamic_modint &x, const dynamic_modint &y) { return dynamic_modint(x) -= y; }

    // 乗法
    dynamic_modint& operator*=(const dynamic_modint &b){
        (x *= b.x) %= mod();
        return *this;
    }

    friend dynamic_modint operator*(const dynamic_modint &x, const dynamic_modint &y) { return dynamic_modint(x) *= y; }
    friend dynamic_modint operator*(const int &x, const dynamic_modint &y) { return dynamic_modint(x) *= y; }
    friend dynamic_modint operator*(const ll &x, const dynamic_modint &y) { return dynamic_modint(x) *= y; }

    // 除法
    dynamic_modint& operator/=(const dynamic_modint &b){ return (*this) *= b.inverse(); }

    friend dynamic_modint operator/(const dynamic_modint &x, const dynamic_modint &y) { return dynamic_modint(x) /= y; }

    dynamic_modint inverse() const {
        int64_t s = 1, t = 0;
        int64_t a = x, b = mod();

        while (b > 0) {
            int64_t q = a / b;

            a -= q * b; swap(a, b);
            s -= q * t; swap(s, t);
        }

        assert (a == 1);

        return dynamic_modint(s);
    }

    // 比較
    friend bool operator==(const dynamic_modint &a, const dynamic_modint &b) { return (a.x == b.x); }
    friend bool operator==(const dynamic_modint &a, const int &b) { return a.x == safe_mod(b, mod()); }
    friend bool operator!=(const dynamic_modint &a, const dynamic_modint &b) { return (a.x != b.x); }

    // 入力
    friend istream &operator>>(istream &is, dynamic_modint &a) {
        is >> a.x;
        a.x = (a.x % mod() + mod()) % mod();
        return is;
    }

    // 出力
    friend ostream &operator<<(ostream &os, const dynamic_modint &a) { return os << a.x; }

    bool is_zero() const { return x == 0; }
    bool is_member(ll a) const { return x == (a % mod() + mod()) % mod(); }
};

template<int id>
int dynamic_modint<id>::_mod = 0;

template<int id>
dynamic_modint<id> pow(dynamic_modint<id> x, long long n) {
    if (n < 0) { return pow(x, -n).inverse(); }

    auto res = dynamic_modint<id>(1);
    for (; n; n >>= 1) {
        if (n & 1) { res *= x; }
        x *= x;
    }

    return res;
}

