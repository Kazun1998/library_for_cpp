#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"

#include"../../../Modulo_Polynomial/Bernoulli_Number.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;

int main() {
    int N; cin >> N;
    vector<modint<Mod>> B = Bernoulli_Number<Mod>(N);
    cout << B << endl;
}
