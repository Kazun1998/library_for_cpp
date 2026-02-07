#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Multipoint_Evaluation.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;

int main(){
    int N, M; cin >> N >> M;
    vector<mint> c(N); cin >> c;
    vector<mint> p(M); cin >> p;

    cout << Multipoint_Evaluation<mint>(Fast_Power_Series<mint>(c), p) << endl;
}
