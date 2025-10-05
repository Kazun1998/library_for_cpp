#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Fast_Power_Series.hpp"
#include"../../../Modulo_Polynomial/Taylor_Shift.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;

int main() {
    int N; mint c; cin >> N >> c;
    vector<mint> a(N); cin >> a;
    Fast_Power_Series<mint> P(a, N);

    cout << Taylor_Shift(P, c).poly << endl;
}
