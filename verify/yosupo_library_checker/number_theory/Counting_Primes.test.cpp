#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include"../../../template/template.hpp"
#include"../../../Integer/Prime_Pi.hpp"

int main() {
    ll N; cin >> N;
    cout << prime::Prime_Pi(N) << endl;
}
