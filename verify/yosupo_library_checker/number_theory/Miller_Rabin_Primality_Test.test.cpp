#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include"../../../template/template.hpp"
#include"../../../Integer/Miller_Rabin_Primality_Test.hpp"

int main(){
    int Q; cin >> Q;
    for (int q = 1; q <= Q; q++) {
        ll N; scanf("%lld", &N);
        cout << (Miller_Rabin_Primality_Test(N, 10) ? "Yes" : "No") << "\n";
    }
}
