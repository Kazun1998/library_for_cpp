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
};
