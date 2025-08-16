#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include<bits/stdc++.h>

using namespace std;

#include"../../../Modulo/Discrete_Log.hpp"

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int X, Y, M; cin >> X >> Y >> M;
    auto A = Modulo::Modulo(X, M), B = Modulo::Modulo(Y, M);

    cout << Modulo::Discrete_Log(A, B) << endl;
  }
}
