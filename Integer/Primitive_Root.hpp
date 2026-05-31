#pragma once

#include "Pollard_Rho.hpp"
#include "Odd_Montgomery_Multiplication.hpp"

/// @brief n が原始根を持つかどうかを判定する
/// @param n 
/// @return n が原始根を持つなら true, そうでないなら false
bool has_Primitive_Root(const uint64_t n) {
    // n が原始根を持つための必要十分条件は
    // n = (1,) 2, 4, p^k, 2p^k (p: 奇素数, k: 正の整数)
    // で表せることである.

    if (n <= 1) return n == 1;
    if (n == 2 || n == 4) return true;
    if (n % 4 == 0) return false;

    uint64_t m = (n % 2 == 0) ? n / 2 : n;
    auto factors = Prime_Factorization_by_Pollard_Rho(m);
    // m = p^k (p は奇素数) であるか判定
    return factors.size() == 1 && factors[0].first != 2;
}

/// @brief n における原始根のうちの 1 つを求める
/// @param n は 2, 4, p^k, 2p^k のうちのいずれかでなくてはならない (p: 素数)
/// @return 原始根の 1 つ
/// @note 存在しない場合の返り値は 0 (n = 1 のときも返り値 0 なので注意).
uint64_t Find_Primitive_Root(const uint64_t n) {
    // 偶数とよく使われる素数は Early Return
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 4) return 3;
    if (n == 998244353) return 3;
    if (n == 1000000007) return 5;

    unless (has_Primitive_Root(n)) return 0;

    uint64_t m = (n % 2 == 0) ? n / 2 : n;
    auto factors = Prime_Factorization_by_Pollard_Rho(m);

    // has_Primitive_Root(n) が true かつ n > 4 なので m は必ず奇素数の冪 p^k となる
    // n = p^k のとき, phi(n) = n (p-1) / p = p^(k-1)(p-1)
    // n = 2p^k のとき, phi(n) = n * (1/2) * (p-1)/p = p^(k-1)(p-1)
    uint64_t p = factors[0].first;
    uint64_t phi = (m / p) * (p - 1);
    auto phi_factors = Prime_Factorization_by_Pollard_Rho(phi);
    auto calc = Odd_Montgomery_Multiplication(m);

    auto judge = [&](const uint64_t g) {
        for (auto [q, ignore]: phi_factors) {
            if (calc.modpow(g % m, phi / q) == 1) return false;
        }

        return true;
    };

    for (uint64_t g = 2; g < n; ++g) {
        unless (gcd(g, n) == 1) continue;
        if (judge(g)) return g;
    }

    return 0;
}
