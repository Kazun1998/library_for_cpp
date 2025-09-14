#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Log.hpp"

int main(){
    const int Mod = 998244353;
    int N; cin >> N;
    Fast_Polynominal_Series<Mod> A(N); cin >> A;

    auto B = Log(A);
    B.resize(N);

    cout << B << endl;
}
