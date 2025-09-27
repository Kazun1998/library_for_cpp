#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Exp.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;
using FPS = Fast_Polynominal_Series<Mod>;

int main() {
    int N; cin >> N;
    vector<mint> a(N); cin >> a;
    FPS A(a);

    auto B = Exp(A);
    B.resize(N);

    cout << B << endl;
}
