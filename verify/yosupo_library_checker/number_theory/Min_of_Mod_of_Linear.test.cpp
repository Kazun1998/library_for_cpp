#define PROBLEM "https://judge.yosupo.jp/problem/min_of_mod_of_linear"

#include"../../../Math/Floor_Linear_Sum.hpp"

int main(){
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    ll N, M, A, B; scanf("%lld%lld%lld%lld", &N, &M, &A, &B);
    cout << Min_of_Mod_of_Linear(A, B, M, N) << "\n";
  }
}
