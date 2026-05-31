#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"

#include"../../../template/template.hpp"
#include"../../../Algebra/modint.hpp"
#include"../../../Convolution/Lcm_Convolution.hpp"

using mint = modint<998244353>;

int main() {
    int N; cin >> N;
    convolution::Lcm_Convolution<mint> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
    for (int j = 1; j <= N; j++) scanf("%d", &B[j]);

    vector<mint> c = (A * B).to_vector();
    c.erase(c.begin(), c.begin() + 1);
    cout << c << endl;
}
