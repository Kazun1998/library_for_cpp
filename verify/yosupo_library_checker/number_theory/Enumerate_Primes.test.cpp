#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"

#include<bits/stdc++.h>

using namespace std;

#include"../../../Integer/Prime.hpp"

int main(){
  int N, A, B; cin >> N >> A >> B;
  auto primes = prime::prime_list(N);

  int X = (primes.size() - B - 1) / A + 1;
  cout << primes.size() << " " << X << endl;
  for (int i = 0; i < X; i++) { cout << primes[A * i + B] << (i < X - 1 ? " ": "") ; }
  cout << "\n";
}
