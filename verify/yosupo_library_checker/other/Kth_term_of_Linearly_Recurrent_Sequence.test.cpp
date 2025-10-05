#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Fast_Power_Series.hpp"
#include"../../../Modulo_Polynomial/Nth_Term_of_Linearly_Recurrent_Sequence.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;
using FPS = Fast_Power_Series<mint>;

int main() {
    int d; ll k; cin >> d >> k;
    vector<mint> a(d), c(d); cin >> a >> c;
    cout << Nth_Term_of_Linearly_Recurrent_Sequence<mint>(a, c, k) << endl;
}
