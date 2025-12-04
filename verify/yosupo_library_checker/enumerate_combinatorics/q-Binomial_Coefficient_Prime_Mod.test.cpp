#define PROBLEM "https://judge.yosupo.jp/problem/q_binomial_coefficient_prime_mod"

#include"../../../template/template.hpp"
#include"../../../Algebra/dynamic_modint.hpp"
#include"../../../Counting/Q_Analog_Combination_Calculator.hpp"

using mint = dynamic_modint<0>;

int main() {
    int T, m; cin >> T >> m;
    mint::set_mod(m);
    mint q; cin >> q;

    Q_Analog_Calculator<mint> calc(q, min(m, 10000000));

    for (int t = 0; t < T; t++) {
        int n, k; scanf("%d%d", &n, &k);
        cout << calc.q_nCr(n, k) << "\n";
    }
}
