#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include"../../../template/template.hpp"
#include"../../../Algebra/modint.hpp"
#include"../../../Convolution/Bitwise_And_Convolution.hpp"

using mint = modint<998244353>;

int main() {
    int N; cin >> N;
    vector<mint> a(1 << N), b(1 << N);
    for (int i = 0; i < (1 << N); i++) {
        int x; scanf("%d", &x);
        a[i] = mint(x);
    }

    for (int j = 0; j < (1 << N); j++) {
        int y; scanf("%d", &y);
        b[j] = mint(y);
    }

    convolution::Bitwize_And_Convolution<mint> A(a), B(b);
    cout <<  (A * B).to_vector() << endl;
}
