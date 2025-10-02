#define PROBLEM "https://judge.yosupo.jp/problem/bell_number"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Bell_Number.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;

int main() {
    int N; cin >> N;
    cout << Bell_Number<Mod>(N) << endl;
}
