#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include"../../../template/template.hpp"
#include"../../../Modulo/Discrete_Log.hpp"

using namespace modulo;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int X, Y, M; cin >> X >> Y >> M;
    auto A = Modulo(X, M), B = Modulo(Y, M);

    cout << Discrete_Log(A, B) << endl;
  }
}
