#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Numeric_Theory_Translation.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;

int main() {
    int N, M; cin >> N >> M;
    vector<mint> a(N), b(M);
    for (int i = 0; i < N; i++) {
        int x; scanf("%d", &x);
        a[i] = mint(x);
    }

    for (int j = 0; j < M; j++) {
        int y; scanf("%d", &y);
        b[j] = mint(y);
    }

    vector<mint> c = Numeric_Theory_Translation<mint>().convolution(a, b);

    cout << c << endl;
}