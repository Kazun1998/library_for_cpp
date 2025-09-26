#pragma once

#include"../template/template.hpp"

namespace modulo {
    class DifferentModulus : public exception {
      public: // publicに指定
      const char* what() const noexcept override { return "異なる法同士の四則演算です"; }
    };

    struct Modulo {
        long long a, n;

        public:
        // 初期化
        Modulo(): a(0), n(1) {}
        Modulo(long long a, long long n): a((a % n + n) % n), n(n) {}

        // マイナス元
        Modulo operator-() const { return Modulo(-a, n); }

        // 加法
        Modulo& operator+=(const Modulo &y) {
            if (n != y.n) { throw DifferentModulus(); }
    
            if ((a += y.a) >= n) a -= n;
            return *this;
        }

        Modulo& operator+=(const long long &y) { return (*this) += Modulo(y, n); }

        friend Modulo operator+(const Modulo &x, const Modulo &y) { return Modulo(x) += y ; }
        friend Modulo operator+(const Modulo &x, const long long &a) { return x + Modulo(a, x.n); }
        friend Modulo operator+(const long long &a, const Modulo &x) { return Modulo(a, x.n) + x; }

        // 減法
        Modulo& operator-=(const Modulo &y) {
            if (n != y.n) { throw DifferentModulus(); }
            if ((a += (n - y.a)) >= n) a -= n;
            return *this;
        }

        Modulo& operator-=(const long long &y) { return (*this) -= Modulo(y, n); }

        friend Modulo operator-(const Modulo &x, const Modulo &y) { return Modulo(x) -= y; }
        friend Modulo operator-(const Modulo &x, const long long &a) { return x - Modulo(a, x.n); }
        friend Modulo operator-(const long long &a, const Modulo &x) { return Modulo(a, x.n) - x; }

        // 乗法
        Modulo& operator*=(const Modulo &y) {
            if (n != y.n) { throw DifferentModulus(); }
            (a *= y.a) %= n;
            return *this;
        }

        Modulo& operator*=(const long long &y){return (*this) *= Modulo(y, n); }

        friend Modulo operator*(const Modulo &x, const Modulo &y) { return Modulo(x) *= y; }
        friend Modulo operator*(const Modulo &x, const long long &a) { return x * Modulo(a,x.n); }
        friend Modulo operator*(const long long &a, const Modulo &x) { return Modulo(a, x.n) * x; }

        // 除法
        Modulo& operator/=(const Modulo &y){
            if (n != y.n) { throw DifferentModulus(); }
            return (*this) *= y.inverse();
        }

        Modulo& operator/=(const long long &y) {return (*this ) /= Modulo(y, n); }

        friend Modulo operator/(const Modulo &x, const Modulo &y) { return Modulo(x) /= y; }
        friend Modulo operator/(const Modulo &x, const long long &a) { return x / Modulo(a, x.n); }
        friend Modulo operator/(const long long &a, const Modulo &x) { return Modulo(a, x.n) / x; }

        // 退化
        Modulo& degenerate(const int m){
            a %= m; n = m;
            return *this;
        }

        // モジュラー逆元
        bool invertible() const {
            long long x = a, y = n;
            while (y) { swap(x = x % y, y); }
            return x == 1;
        }

        Modulo inverse() const{
            long long s = 1, t = 0;
            long long x = a, y = n;
            while (y){
                auto q = x / y;
                swap(x -= q * y, y);
                swap(s -= q * t, t);
            }

            return Modulo(s, n);
        }

        // include?
        bool is_member(ll x) const { return mod(x - a, n) == 0; }

        bool is_zero() const { return is_member(0); }

        // 比較
        friend bool operator==(const Modulo &x, const Modulo &y) { return x.a==y.a; }
        friend bool operator==(const Modulo &x, const long long &a) { return (x.a - a) % x.n == 0; }
        friend bool operator==(const long long &a, const Modulo &x) { return (a - x.a) % x.n == 0; }

        friend bool operator!=(const Modulo &x, const Modulo &y) { return x.a != y.a; }
        friend bool operator!=(const Modulo &x, const long long &a) { return (x.a - a)% x.n != 0; }
        friend bool operator!=(const long long &a, const Modulo &x) { return (a - x.a)% x.n != 0; }

        // 入力
        friend istream &operator>>(istream &is, Modulo &x) {
            long long b, m;
            is >> b >> m;
            x = Modulo(b, m);
            return (is);
        }

        // 出力
        friend ostream &operator<<(ostream &os, const Modulo &x) { return os << x.a << " (mod " << x.n << ")"; }
    };

    Modulo pow(Modulo x, long long n) {
        if (n < 0) { return pow(x, -n).inverse(); }

        auto res = Modulo(1, x.n);
        for (; n; n >>= 1) {
            if (n & 1) { res *= x; }
            x *= x;
        }

        return res;
    }
}
