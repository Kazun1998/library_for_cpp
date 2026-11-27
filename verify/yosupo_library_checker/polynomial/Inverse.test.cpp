#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Fast_Power_Series.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;

int main(){
    int N; cin >> N;
    Fast_Power_Series<mint> A(N); cin >> A;
    cout << A.inverse() << endl;
}
