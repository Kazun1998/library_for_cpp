#pragma once

#include "../template/template.hpp"
#include "Modulo.hpp"
#include "../Integer/Euler_Totient.hpp"

namespace modulo {
    Modulo Power_Tower(vector<ll> tower, ll m) {
        auto helper_mod = [](const ll a, const ll m) -> ll { return a < 2 * m ? a : safe_mod(a, m) + m; };
        auto helper_mul = [&helper_mod](const ll a, const ll b, const ll m) -> ll { return helper_mod(a * b, m); };
        auto helper_power = [&helper_mul](ll a, ll k, const ll m) -> ll {
            ll res = 1;
            while (k) {
                if (k & 1) { res = helper_mul(res, a, m); }

                a = helper_mul(a, a, m);
                k >>= 1;
            }

            return res;
        };

        // 再帰ラムダ (C++23 の型推論を利用)
        auto solve = [&](auto self, size_t idx, ll current_m) -> ll {
            // 基底条件1: 法が1になれば、拡張オイラーの性質上、以降の値は常に「mod 1 + 1 = 1」扱い
            if (current_m == 1) return 1;
            
            // 基底条件2: タワーの最上段に到達
            if (idx == tower.size() - 1) return helper_mod(tower[idx], current_m);

            // 再帰ステップ:
            // 一つ上の階層（指数部分）を、phi(current_m) を法として計算
            ll phi = Euler_Totient(current_m);
            ll exponent = self(self, idx + 1, phi);
            
            // 現在の底を計算した指数で累乗する
            return helper_power(tower[idx], exponent, current_m);
        };

        if (tower.empty()) return Modulo(0, m); // ガード句
        
        // 最終的な結果は通常の mod m で返す
        return Modulo(solve(solve, 0, m), m);
    }
}
