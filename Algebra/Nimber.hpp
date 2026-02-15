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
        if ((x | b.x) < 256) {
            if (!table_initialized) init_table();
            x = small_table[x][b.x];
            return *this;
        }
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

    inline static uint8_t small_table[256][256];
    inline static bool table_initialized = false;

    static void init_table() {
        if (table_initialized) return;
        small_table[0][0] = 0; small_table[0][1] = 0;
        small_table[1][0] = 0; small_table[1][1] = 1;
        for (int level = 1; level <= 3; ++level) {
            int half = 1 << (1 << (level - 1));
            int full = 1 << (1 << level);
            for (int i = 0; i < full; ++i) {
                for (int j = 0; j < full; ++j) {
                    if (i < half && j < half) continue;
                    int x0 = i & (half - 1);
                    int x1 = i >> (1 << (level - 1));
                    int y0 = j & (half - 1);
                    int y1 = j >> (1 << (level - 1));
                    int p = small_table[x0][y0];
                    int m = small_table[x0 ^ x1][y0 ^ y1];
                    int b = small_table[small_table[x1][y1]][half >> 1];
                    small_table[i][j] = p ^ b ^ ((p ^ m) << (1 << (level - 1)));
                }
            }
        }
        table_initialized = true;
    }

    static uint64_t calculate_mul(const uint64_t x, const uint64_t y, int level) {
        if (level <= 3) { 
            if (!table_initialized) init_table();
            return small_table[x][y];
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
