#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include"../../../Math/Floor_Linear_Sum.hpp"

int main(){
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    ll N, M, A, B; scanf("%lld%lld%lld%lld", &N, &M, &A, &B);
    cout << Floor_Linear_Sum(A, B, M, N) << "\n";
  }
}
