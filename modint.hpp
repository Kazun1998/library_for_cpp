#pragma once

#include"template/template.hpp"

template<int Mod>
class modint {
    public:
    int64_t x;

    public:
    // 初期化
    constexpr modint(): x(0) {}
    constexpr modint(int64_t a): x((a % Mod + Mod) % Mod) {}

    // マイナス元
    modint operator-() const { return modint(-x); }

    // 加法
    modint& operator+=(const modint &b){
        if ((x += b.x) >= Mod) x -= Mod;
        return *this;
    }

    friend modint operator+(const modint &x, const modint &y) { return modint(x) += y; }

    // 減法
    modint& operator-=(const modint &b){
        if ((x += Mod - b.x) >= Mod) x -= Mod;
        return *this;
    }

    friend modint operator-(const modint &x, const modint &y) { return modint(x) -= y; }

    // 乗法
    modint& operator*=(const modint &b){
        (x *= b.x) %= Mod;
        return *this;
    }

    friend modint operator*(const modint &x, const modint &y) { return modint(x) *= y; }

    // 除法
    modint& operator/=(const modint &b){ return (*this) *= b.inverse(); }

    friend modint operator/(const modint &x, const modint &y) { return modint(x) /= y; }

    modint inverse() const {
        int64_t s = 1, t = 0;
        int64_t a = x, b = Mod;

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
    friend bool operator!=(const modint &a, const modint &b) { return (a.x != b.x); }

    // 入力
    friend istream &operator>>(istream &is, modint &a) {
        is >> a.x;
        a.x = (a.x % Mod + Mod) % Mod;
        return is;
    }

    // 出力
    friend ostream &operator<<(ostream &os, const modint &a) { return os << a.x; }

    bool is_zero() const { return x == 0; }
    bool is_member(ll a) const { return x == (a % Mod + Mod) % Mod; }
};

template<int mod>
modint<mod> pow(modint<mod> x, int64_t n){
    if (n<0) return pow(x,-n).inverse();

    modint<mod> y(1);
    while (n){
        if (n&1) y*=x;
        x*=x; n>>=1;
    }

    return y;
}
