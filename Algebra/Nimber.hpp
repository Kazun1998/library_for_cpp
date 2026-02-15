#pragma once

#include "../template/template.hpp"

class Nimber {
    public:
    Nimber(): x(0) {}
    Nimber(uint64_t x): x(x) {}

    Nimber operator-() const { return Nimber(x); }

    Nimber& operator+=(const Nimber &b) {
        x ^= b.x;
        return *this;
    }

    friend Nimber operator+(const Nimber &x, const Nimber &y) { return Nimber(x) += y; }

    Nimber& operator-=(const Nimber &b){
        *this += b;
        return *this;
    }

    friend Nimber operator-(const Nimber &x, const Nimber &y) { return Nimber(x) -= y; }

    // 乗法
    Nimber& operator*=(const Nimber &b){
        int level = max(calculate_level(x), calculate_level(b.x));
        x = calculate_mul(x, b.x, level);
        return *this;
    }

    friend Nimber operator*(const Nimber &x, const Nimber &y) { return Nimber(x) *= y; }


    // 入力
    friend istream &operator>>(istream &is, Nimber &a) {
        is >> a.x;
        return is;
    }

    // 出力
    friend ostream &operator<<(ostream &os, const Nimber &a) { return os << a.x; }

    private:
    uint64_t x;

    static uint64_t calculate_mul(const uint64_t x, const uint64_t y, int level) {
        if (level == 0) { 
            return (x == 1 && y == 1) ? 1 : 0;
        }

        const auto &[x1, x0] = separate(x, level);
        const auto &[y1, y0] = separate(y, level);

        uint64_t p = calculate_mul(x0, y0, level - 1);
        uint64_t e = 1ULL << (1 << (level - 1));

        uint64_t m = calculate_mul(x0 ^ x1, y0 ^ y1, level - 1);
        uint64_t a = p ^ m * e;
        uint64_t b = calculate_mul(calculate_mul(x1, y1, level - 1), e >> 1, level - 1);

        uint64_t res = (p * e) ^ a ^ b;

        return res;
    }

    static int calculate_level(const uint64_t &x) {
        if (x == 0 || x == 1) { return 0; }

        return floor_log2(floor_log2(x)) + 1;
    }

    static pair<uint64_t, uint64_t> separate(const uint64_t &x, int level) {
        uint64_t upper = x >> (1 << (level - 1));
        uint64_t lower = x ^ (upper << (1 << level - 1));

        return { upper, lower };
    }
};
