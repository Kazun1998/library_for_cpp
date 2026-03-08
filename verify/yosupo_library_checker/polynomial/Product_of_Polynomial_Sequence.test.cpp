#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Numeric_Theory_Translation.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;

int main() {
    int N; cin >> N;
    vector<vector<mint>> a(N, vector<mint>{});
    for (int i = 0; i < N; i++) {
        int d; scanf("%d", &d);
        a[i].resize(d + 1);
        for (int j = 0; j <= d; j++) { cin >> a[i][j]; }
    }

    auto B = Numeric_Theory_Translation<mint>().multiple_convolution(a);

    cout << B << endl;
}
