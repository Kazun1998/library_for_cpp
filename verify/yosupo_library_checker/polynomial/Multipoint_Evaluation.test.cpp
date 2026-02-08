#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include"../../../template/template.hpp"
#include"../../../Modulo_Polynomial/Multipoint_Evaluation.hpp"

const ll Mod = 998244353;
using mint = modint<Mod>;

int main(){
    int N, M; cin >> N >> M;
    vector<mint> c(N); for (int i = 0; i < N; ++i) { scanf("%d", &c[i]); }
    vector<mint> p(M); for (int j = 0; j < M; ++j) { scanf("%d", &p[j]); }

    cout << Multipoint_Evaluation<mint>(Fast_Power_Series<mint>(c), p) << endl;
}
