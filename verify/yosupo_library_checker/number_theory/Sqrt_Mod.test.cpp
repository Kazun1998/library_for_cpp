#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include"../../../template/template.hpp"
#include"../../../Modulo/Sqrt.hpp"

int verify() {
    using namespace modulo;
    Modulo Y;
    scanf("%lld%lld", &Y.a, &Y.n);

    auto X = Sqrt(Y);
    return X == nullopt ? -1 : X.value().a;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cout << verify() << "\n";
    }
}
