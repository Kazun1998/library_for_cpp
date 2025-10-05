#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Stirling_2nd.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;

int main() {
    int N; cin >> N;
    cout << Stirling_2nd<mint>(N) << endl;
}
