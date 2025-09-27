#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Fast_Power_Series.hpp"

const int Mod = 998244353;
using mint = modint<Mod>;
using FPS = Fast_Polynominal_Series<Mod>;

int main() {
    int N, M; cin >> N >> M;
    vector<mint> f(N), g(M); cin >> f >> g;
    FPS F(f, N + M), G(g, N + M);
    FPS Q, R;

    tie (Q, R) = divmod(F, G);
    int u = Q.is_zero() ? 0 : Q.degree() + 1;
    int v = R.is_zero() ? 0 : R.degree() + 1;

    cout << u << " " << v << endl;
    cout << Q << endl;
    cout << R << endl;
}
