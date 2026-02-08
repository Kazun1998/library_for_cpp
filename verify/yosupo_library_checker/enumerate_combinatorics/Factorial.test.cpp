#define PROBLEM "https://judge.yosupo.jp/problem/factorial"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Huge_Factorial.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;

mint verify() {
    int N; cin >> N;
    return Huge_Factorial<mint>(N);
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) cout << verify() << endl;
}
