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

    Nimber& operator-=(const Nimber &b) {
        *this += b;
        return *this;
    }

    friend Nimber operator-(const Nimber &x, const Nimber &y) { return Nimber(x) -= y; }

    // 乗法
    Nimber& operator*=(const Nimber &b) {
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

    friend bool operator==(const Nimber &a, const Nimber &b) { return a.x == b.x; }
    friend bool operator!=(const Nimber &a, const Nimber &b) { return a.x != b.x; }
    friend bool operator<(const Nimber &a, const Nimber &b) { return a.x < b.x; }

    Nimber square() const {
        if (x < 256) {
            if (!table_initialized) init_table();
            return small_table[x][x];
        }
        int level = calculate_level(x);
        return Nimber(calculate_square(x, level));
    }

    // 入力
    friend istream &operator>>(istream &is, Nimber &a) {
        is >> a.x;
        return is;
    }

    // 出力
    friend ostream &operator<<(ostream &os, const Nimber &a) { return os << a.x; }

    Nimber inverse() const;

    Nimber sqrt() {
        if (x < 256) {
            if (!table_initialized) init_table();
            return Nimber(small_sqrt_table[x]);
        }

        int level = calculate_level(x);
        return Nimber(calculate_sqrt(x, level));
    }

    bool is_zero() const { return x == 0; }

    private:
    uint64_t x;

    inline static uint8_t small_table[256][256];
    inline static bool table_initialized = false;
    inline static uint8_t small_sqrt_table[256];

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

        for (int i = 0; i < 256; ++i) {
            small_sqrt_table[small_table[i][i]] = i;
        }

        table_initialized = true;
    }

    static uint64_t build_up(const uint64_t upper, const uint64_t lower, int level) {
        return upper << (1 << (level - 1)) ^ lower;
    }

    /// @brief x * y を求めるためのヘルパー関数
    /// @param x 
    /// @param y 
    /// @param level 
    /// @return 
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

    /// @brief x の自乗を求めるヘルパー関数
    /// @param x 
    /// @param level 
    /// @return 
    static uint64_t calculate_square(const uint64_t x, int level) {
        if (level <= 3) {
            if (!table_initialized) init_table();
            return small_table[x][x];
        }

        const auto &[x1, x0] = separate(x, level);

        uint64_t p = calculate_square(x0, level - 1);
        uint64_t b = calculate_square(x1, level - 1);
        
        uint64_t e = 1ULL << (1 << (level - 1));
        uint64_t mul_part = calculate_mul(b, e >> 1, level - 1);

        return p ^ (b << (1 << (level - 1))) ^ mul_part;
    }

    static uint64_t calculate_sqrt(const uint64_t x, int level) {
        if (level <= 3) {
            if (!table_initialized) init_table();
            return small_sqrt_table[x];
        }

        const auto &[x1, x0] = separate(x, level);

        uint64_t y1 = calculate_sqrt(x1, level - 1);

        uint64_t e = 1ULL << (1 << (level - 1));
        uint64_t prod = calculate_mul(x1, e >> 1, level - 1);
        uint64_t y0 = calculate_sqrt(prod ^ x0, level - 1);

        return (y1 << (1 << (level - 1))) ^ y0;
    }

    /// @brief x < 2^(2^k) を満たす最小の非負整数 k を求める.
    /// @param x 
    /// @note x > 1 のときは, k = floor_log2(floor_log2(x)) + 1 が成り立つ.
    static int calculate_level(const uint64_t &x) {
        if (x == 0 || x == 1) { return 0; }

        return floor_log2(floor_log2(x)) + 1;
    }

    /// @brief 非負整数 x を x = x1 e_{level} + x0, 0 <= x_0 < e_{level}, 0 <= x_1 < e_{level} となるように分割する. ただし, e_k := 2^(2^k).
    /// @param x 非負整数
    /// @param level e_k における k の値
    /// @return {x1, x0} (順番注意)
    static pair<uint64_t, uint64_t> separate(const uint64_t &x, int level) {
        uint64_t upper = x >> (1 << (level - 1));
        uint64_t lower = x ^ (upper << (1 << level - 1));

        return { upper, lower };
    }
};

template<typename T>
Nimber pow(Nimber x, T n) {
    if constexpr (std::is_signed_v<T>) {
        if (n < 0) return pow(x.inverse(), -n);
    }

    Nimber res(1);
    while (n > 0) {
        if (n & 1) res *= x;
        x = x.square();
        n >>= 1;
    }
    return res;
}

inline Nimber Nimber::inverse() const {
    int l = calculate_level(x);
    return pow(*this, l >= 6 ? -2ULL : (1ULL << (1 << l)) - 2);
}
