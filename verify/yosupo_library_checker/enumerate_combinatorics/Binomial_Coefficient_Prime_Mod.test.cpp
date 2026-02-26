#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include"../../../template/template.hpp"
#include"../../../Algebra/dynamic_modint.hpp"
#include"../../../Counting/Combination_Calculator.hpp"

using mint = dynamic_modint<0>;

int main() {
    int T, m; cin >> T >> m;
    mint::set_mod(m);

    Combination_Calculator<mint> calc(min(m, 10000000));

    for (int t = 0; t < T; t++) {
        int n, k; scanf("%d%d", &n, &k);
        cout << calc.nCr(n, k) << "\n";
    }
}
