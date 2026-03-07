#pragma once
#include "../template/template.hpp"

struct Odd_Montgomery_Multiplication {
    using u64 = uint64_t;
    using u128 = __uint128_t;

    /// @brief 剰余
    u64 mod;

    /// @brief N = mod としたとき, NN' ≡ -1 (mod R) を満たす N'
    u64 neg_inv;

    /// @brief (2^64)^2 mod N
    u64 r2;

    Odd_Montgomery_Multiplication(u64 mod) : mod(mod) {
        u64 inv = mod;
        for (int i = 0; i < 5; ++i) inv *= 2 - mod * inv;
        neg_inv = -inv;
        u128 r = -mod % mod;
        r2 = (r * r) % mod;
    }

    /// @brief モンゴメリリダクション. T * R^{-1} mod N を計算する.
    /// @param T 0 <= T < N * R
    /// @return T * R^{-1} mod N
    u64 reduce(u128 T) const {
        u64 m = u64(T) * neg_inv;
        u64 t = (T + (u128)m * mod) >> 64;
        if (t >= mod) { t -= mod; }
        return t;
    }

    /// @brief 通常の整数 a をモンゴメリ表現 aR mod N に変換する.
    /// @param a 0 <= a < N
    /// @return aR mod N
    u64 form(u64 a) const { return reduce((u128)a * r2); }

    /// @brief モンゴメリ表現された数 a, b の積を計算する.
    /// @param a モンゴメリ表現された数
    /// @param b モンゴメリ表現された数
    /// @return a * b のモンゴメリ表現
    u64 multiply(u64 a, u64 b) const { return reduce((u128)a * b); }

    /// @brief 通常の整数 a, b の積 a * b mod N を計算する.
    /// @param a 0 <= a < N
    /// @param b 0 <= b < N
    /// @return a * b mod N
    u64 mod_mul(u64 a, u64 b) const { return reduce(multiply(form(a), form(b))); }
};
