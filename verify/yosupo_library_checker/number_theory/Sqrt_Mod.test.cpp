#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include"../../../template/template.hpp"
#include"../../../Modulo/Sqrt.hpp"

int main() {
    using namespace modulo;
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        Modulo Y; scanf("%lld%lld", &Y.a, &Y.n);

        try {
            cout << Sqrt(Y).a << "\n";
        } catch (const NotExist &e) {
            cout << -1 << "\n";
        }
    }
}
