#pragma once

#include "../template/template.hpp"
#include "Prime.hpp"
#include "Odd_Montgomery_Multiplication.hpp"

/// @brief ミラー・ラビン素数判定法により、与えられた整数が素数かどうかを判定する。
/// @param n 判定対象の整数 (n <= 2^64 - 1)
/// @return n が素数であれば true、そうでなければ false を返す。
/// @note 2^64 未満の整数に対しては決定的な判定を行う。
/// @see https://miller-rabin.appspot.com/
bool Miller_Rabin_Primality_Test(uint64_t n) {
    if (n <= 1) return false;
    if (n % 2 == 0) return n == 2; 

    int s; uint64_t d;
    tie (s, d) = prime::exponents(n - 1, 2);

    Odd_Montgomery_Multiplication calculator(n);
    auto challenge = [&n, &s, &d, &calculator](uint64_t a) -> bool {
        a %= n;
        if (a == 0) return true;

        auto y = calculator.modpow(a, d);
        if (y == 1 || y == n - 1) return true;

        rep(s) {
            y = calculator.mod_mul(y, y);
            if (y == n - 1) return true;
        }

        return false;
    };

    // n の値に応じて、決定的素数判定に使用する witness (証人) のリストを選択する。
    // これらのリストは、特定の範囲内の数に対してミラー・ラビン法が確率的でなく決定的になることを保証する。
    if (n < 4759123141) {
        // 32ビット整数 (符号なし) の範囲より少し大きい値までをカバー
        for (const uint64_t a : {2, 7, 61}) {
            if (n == a) return true; // n が witness 自身の場合は素数
            unless(challenge(a)) return false;
        }
    } else {
        // 64ビット整数 (符号なし) の範囲をカバー
        for (const uint64_t a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
            // この場合、n > a が保証されるため、n == a のチェックは不要
            unless(challenge(a)) return false;
        }
    }

    return true;
}