#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Numeric_Theory_Translation.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;

int main(){
    const int Mod = 998244353;
    Numeric_Theory_Translation<mint> calculator;

    int N; cin >> N;
    vector<mint> A(N); cin >> A;
    cout << calculator.inverse(A) << endl;
}
