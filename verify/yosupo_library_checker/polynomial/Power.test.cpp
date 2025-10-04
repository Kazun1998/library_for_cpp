#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Fast_Power_Series.hpp"
#include"../../../Modulo_Polynomial/Power.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;
using FPS = Fast_Power_Series<mint>;

int main() {
    int N; ll M ; cin >> N >> M;
    vector<mint> a(N); cin >> a;
    FPS A(a);

    FPS B = pow(A, M);
    B.resize();

    cout << B << endl;
}
