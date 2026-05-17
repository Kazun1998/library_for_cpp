#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include<bits/stdc++.h>

using namespace std;

#include"../../../Integer/Linear_Sieve.hpp"

int main(){
  int N, A, B; cin >> N >> A >> B;
  auto lpf = Linear_Sieve(N);

  vector<int> primes;
  for (int i = 2; i <= N; ++i) {
    if (lpf[i] == i) primes.emplace_back(i);
  }

  int X = (primes.size() - B - 1) / A + 1;
  cout << primes.size() << " " << X << endl;
  for (int i = 0; i < X; i++) { cout << primes[A * i + B] << (i < X - 1 ? " ": "") ; }
  cout << "\n";
}
