#define PROBLEM "https://yukicoder.me/problems/no/187"

#include "../../template/template.hpp"
#include "../../Modulo/Garner.hpp"

using namespace modulo;
ll solve() {
    int n; cin >> n;
    vector<Modulo> modulos(n);
    for (int i = 0; i < n; ++i) {
        ll x, y; cin >> x >> y;
        modulos[i] = Modulo(x, y);
    }

    return First_Garner(modulos, intpow(10, 9) + 7, true).value_or(-1);
}

int main() {
    cout << solve() << endl;
}
