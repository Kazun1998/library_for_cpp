#pragma once

template<int mod>
class modint{
    public:
    int64_t x;

    public:
    // 初期化
    constexpr modint(): x(0) {}
    constexpr modint(int64_t a): x((a % mod + mod) % mod) {}

    // マイナス元
    modint operator-() const { return modint(-x); }

    // 加法
    modint& operator+=(const modint &b){
        if ((x += b.x) >= mod) x -= mod;
        return *this;
    }

    friend modint operator+(const modint &x, const modint &y) { return modint(x) += y; }

    // 減法
    modint& operator-=(const modint &b){
        if ((x += mod - b.x) >= mod) x -= mod;
        return *this;
    }

    friend modint operator-(const modint &x, const modint &y) { return modint(x) -= y; }

    // 乗法
    modint& operator*=(const modint &b){
        (x *= b.x) %= mod;
        return *this;
    }

    friend modint operator*(const modint &x, const modint &y) { return modint(x) *= y; }

    // 除法
    modint& operator/=(const modint &b){ return (*this) *= b.inverse(); }

    friend modint operator/(const modint &x, const modint &y) { return modint(x) /= y; }

    modint inverse() const {
        int64_t s = 1, t = 0;
        int64_t a = x, b = mod;

        while (b > 0) {
            int64_t q = a / b;

            a -= q * b; swap(a, b);
            s -= q * t; swap(s, t);
        }

        assert (a == 1);

        return modint(s);
    }

    // 入力
    friend istream &operator>>(istream &is, modint &a) {
        is >> a.x;
        a.x = (a.x % mod + mod) % mod;
        return is;
    }

    // 出力
    friend ostream &operator<<(ostream &os, const modint &a) { return os << a.x; }
};
