#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include"../../../template/template.hpp"
#include"../../../Algebra/modint.hpp"
#include"../../../Convolution/Subset_Convolution.hpp"

using mint = modint<998244353>;

int main() {
    int N; cin >> N;
    convolution::Sub<mint> A(N), B(N);
    for (int i = 0; i < (1 << N); i++) scanf("%uld", &A[i].x);
    for (int j = 0; j < (1 << N); j++) scanf("%uld", &B[j].x);

    vector<mint> c = (A * B).to_vector();
    cout << c << endl;
}
