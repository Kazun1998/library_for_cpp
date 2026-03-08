#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Stirling_1st.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;

int main() {
    int N; cin >> N;
    cout << Stirling_1st<mint>(N, true) << endl;
}
