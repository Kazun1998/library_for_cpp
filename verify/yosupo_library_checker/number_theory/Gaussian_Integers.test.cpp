#define PROBLEM "https://judge.yosupo.jp/problem/gcd_of_gaussian_integers"

#include"../../../template/template.hpp"
#include"../../../Algebra/Gaussian_Integer.hpp"

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++){
        ll a1, b1, a2, b2;
        scanf("%lld%lld%lld%lld", &a1, &b1, &a2, &b2);
        Gaussian_Integer<ll> x1(a1, b1), x2(a2, b2);
        auto g = gcd(x1, x2);
        cout << g.re << " " << g.im << "\n";
    }
}
