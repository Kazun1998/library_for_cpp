#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"

#include"../../../template/template.hpp"
#include"../../../Algebra/modint.hpp"
#include"../../../Convolution/Gcd_Convolution.hpp"

using mint = modint<998244353>;

int main() {
    int N; cin >> N;
    vector<mint> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; i++) {
        int x; scanf("%d", &x);
        a[i] = mint(x);
    }

    for (int j = 1; j <= N; j++) {
        int y; scanf("%d", &y);
        b[j] = mint(y);
    }

    convolution::Gcd_Convolution<mint> A(a), B(b);
    vector<mint> c = (A * B).to_vector();
    c.erase(c.begin(), c.begin() + 1);
    cout << c << endl;
}
